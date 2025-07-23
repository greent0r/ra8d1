/*
* bsp_wifi_esp.c
*
*  Created on: 2025年6月6日
*      Author: greentor
*/
#include "bsp_wifi_esp.h"
#include "mymalloc.h"

/*用来接收UART9数据的缓冲区*/
char esp_rx_buff[2048];
struct STRUCT_USART_Fram ESP8266_Fram_Record_Struct = { 0 };  //定义了一个数据帧结构体
TimerHandle_t g_uart_rx_timer = NULL;
SemaphoreHandle_t xUARTBufferMutex = NULL;//互斥锁

void timer9_callback(timer_callback_args_t * p_args)
{
    ESP8266_Fram_Record_Struct.InfBit.FramFinishFlag = 1;
}

void esp_uart_callback(uart_callback_args_t * p_args)
{
    switch(p_args->event)
    {
        case UART_EVENT_RX_CHAR:
        {
            uint8_t rx_byte = (uint8_t)(p_args->data);
            //R_SCI_B_UART_Write(&g_uart3_ctrl, (uint8_t *)&(p_args->data), 1);
            if (ESP8266_Fram_Record_Struct.InfBit.FramLength < (RX_BUF_MAX_LEN - 1)){
                ESP8266_Fram_Record_Struct.Data_RX_BUF[ESP8266_Fram_Record_Struct.InfBit.FramLength++] = rx_byte;
            }
            R_GPT_Stop(&timer9_ctrl);
            R_GPT_Start(&timer9_ctrl);
            break;
        }
        case UART_EVENT_TX_COMPLETE:
            break;
        default:
            break;
    }
}

/* Wifi初始化*/
void esp_init(void)
{
    printf("wifi esp init\n");
    fsp_err_t err = FSP_SUCCESS;
    R_SCI_B_UART_Open(esp_uart.p_ctrl, esp_uart.p_cfg);
    //xUARTBufferMutex = xSemaphoreCreateMutex();//wifi访问的互斥锁
    esp_printf("AT+RST\r\n");
    vTaskDelay(2000);
    R_GPT_Open(&timer9_ctrl, &timer9_cfg);//wifi接收定时器
    R_GPT_Start(&timer9_ctrl);
//    ESP8266_Send_AT_Cmd("AT+UART_DEF=2000000,8,1,0,0", "OK", NULL, 0);
}

int esp_printf(const char *format, ...){
    char buffer[25000];
    va_list args;
    va_start(args, format);

    int len = vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    if (len > 0){
        fsp_err_t err = R_SCI_B_UART_Write(&esp_uart_ctrl, (uint8_t *)buffer, (unsigned int)len);
        if (err != FSP_SUCCESS){
            printf("UART write error: %d\n", err);
        }
    }
    return len;
}

//对ESP8266模块发送AT指令
// cmd 待发送的指令
// ack1,ack2;期待的响应，为NULL表不需响应，两者为或逻辑关系
// time 等待响应时间,毫秒
//返回1发送成功， 0失败
bool ESP8266_Send_AT_Cmd(char *cmd, char *ack1, char *ack2, uint32_t time)
{
        ESP8266_Fram_Record_Struct.InfBit.FramLength = 0;
        esp_printf("%s\r\n", cmd);

        if(ack1 == NULL && ack2 == NULL)
        {
            return true;
        }

        vTaskDelay(time);
        vTaskDelay(1000);

        ESP8266_Fram_Record_Struct.Data_RX_BUF[ESP8266_Fram_Record_Struct.InfBit.FramLength] = '\0';
        printf("%s", ESP8266_Fram_Record_Struct.Data_RX_BUF);

        bool ret = false;
        if(ack1 && ack2)
        {
            ret = (strstr(ESP8266_Fram_Record_Struct.Data_RX_BUF, ack1) != NULL) ||
                  (strstr(ESP8266_Fram_Record_Struct.Data_RX_BUF, ack2) != NULL);
        }
        else if(ack1)
        {
            ret = (strstr(ESP8266_Fram_Record_Struct.Data_RX_BUF, ack1) != NULL);
        }
        else if(ack2)
        {
            ret = (strstr(ESP8266_Fram_Record_Struct.Data_RX_BUF, ack2) != NULL);
        }

        xSemaphoreGive(xUARTBufferMutex);
        return ret;
}

//发送恢复出厂默认设置指令将模块恢复成出厂设置
void ESP8266_AT_Test(void)
{
    char count=0;
    vTaskDelay(1000);
    while(count < 10)
    {
        if(ESP8266_Send_AT_Cmd("AT+RESTORE","OK",NULL,500))
        {
            printf("OK\r\n");
            return;
        }
        ++ count;
    }
}


//选择ESP8266的工作模式
// enumMode 模式类型
//成功返回true，失败返回false
bool ESP8266_Net_Mode_Choose(ENUM_Net_ModeTypeDef enumMode)
{
    switch ( enumMode )
    {
        case STA:
            return ESP8266_Send_AT_Cmd ( "AT+CWMODE=1", "OK", "no change", 2500 );

        case AP:
            return ESP8266_Send_AT_Cmd ( "AT+CWMODE=2", "OK", "no change", 2500 );

        case STA_AP:
            return ESP8266_Send_AT_Cmd ( "AT+CWMODE=3", "OK", "no change", 2500 );

        default:
          return false;
    }
}


//ESP8266连接外部的WIFI
//pSSID WiFi帐号
//pPassWord WiFi密码
//设置成功返回true 反之false
bool ESP8266_JoinAP( char * pSSID, char * pPassWord)
{
    char cCmd [120];

    sprintf ( cCmd, "AT+CWJAP=\"%s\",\"%s\"", pSSID, pPassWord );
    return ESP8266_Send_AT_Cmd( cCmd, "OK", NULL, 0 );
}

//ESP8266 透传使能
//enumEnUnvarnishTx  是否多连接，bool类型
//设置成功返回true，反之false
bool ESP8266_Enable_MultipleId (bool enumEnUnvarnishTx )
{
    char cStr [20];

    sprintf ( cStr, "AT+CIPMUX=%d", ( enumEnUnvarnishTx ? 1 : 0 ) );

    return ESP8266_Send_AT_Cmd ( cStr, "OK", 0, 500 );

}


//ESP8266 连接服务器
//enumE  网络类型
//ip ，服务器IP
//ComNum  服务器端口
//id，连接号，确保通信不受外界干扰
//设置成功返回true，反之fasle
bool ESP8266_Link_Server(ENUM_NetPro_TypeDef enumE, char * ip, char * ComNum, ENUM_ID_NO_TypeDef id)
{
    char cStr [100] = { 0 }, cCmd [120];

    switch (  enumE )
    {
        case enumTCP:
          sprintf ( cStr, "\"%s\",\"%s\",%s", "TCP", ip, ComNum );
          break;

        case enumUDP:
          sprintf ( cStr, "\"%s\",\"%s\",%s", "UDP", ip, ComNum );
          break;

        default:
            break;
    }

    if ( id < 5 )
        sprintf ( cCmd, "AT+CIPSTART=%d,%s", id, cStr);

    else
        sprintf ( cCmd, "AT+CIPSTART=%s", cStr );

    return ESP8266_Send_AT_Cmd ( cCmd, "OK", "ALREAY CONNECT", 4000 );

}


//透传使能
//设置成功返回true， 反之false
bool ESP8266_UnvarnishSend ( void )
{
    if (!ESP8266_Send_AT_Cmd ( "AT+CIPMODE=1", "OK", 0, 500 ))
        return false;

    return
        ESP8266_Send_AT_Cmd( "AT+CIPSEND", "OK", ">", 500 );

}


//ESP8266发送字符串
//enumEnUnvarnishTx是否使能透传模式
//pStr字符串
//ulStrLength字符串长度
//ucId 连接号
//设置成功返回true， 反之false
bool ESP8266_SendString(bool enumEnUnvarnishTx, char * pStr, uint32_t ulStrLength, ENUM_ID_NO_TypeDef ucId )
{
    char cStr [20];
    bool bRet = false;


    if ( enumEnUnvarnishTx )
    {
        esp_printf ( "%s", pStr );

        bRet = true;

    }

    else
    {
        if ( ucId < 5 )
            sprintf ( cStr, "AT+CIPSEND=%d,%d", ucId, ulStrLength + 2 );

        else
            sprintf ( cStr, "AT+CIPSEND=%d", ulStrLength + 2 );

        ESP8266_Send_AT_Cmd ( cStr, "> ", 0, 1000 );

        bRet = ESP8266_Send_AT_Cmd ( pStr, "SEND OK", 0, 1000 );
  }

    return bRet;

}


//ESP8266退出透传模式
void ESP8266_ExitUnvarnishSend ( void )
{
    vTaskDelay(1000);
    esp_printf( "+++" );
    vTaskDelay( 500 );
}


//ESP8266 检测连接状态
//返回0：获取状态失败
//返回2：获得ip
//返回3：建立连接
//返回4：失去连接
uint8_t ESP8266_Get_LinkStatus ( void )
{
    if (ESP8266_Send_AT_Cmd( "AT+CIPSTATUS", "OK", 0, 500 ) )
    {
        if ( strstr ( ESP8266_Fram_Record_Struct .Data_RX_BUF, "STATUS:2\r\n" ) )
            return 2;

        else if ( strstr ( ESP8266_Fram_Record_Struct .Data_RX_BUF, "STATUS:3\r\n" ) )
            return 3;

        else if ( strstr ( ESP8266_Fram_Record_Struct .Data_RX_BUF, "STATUS:4\r\n" ) )
            return 4;

    }

    return 0;
}

//下面为ESP8266MQTT功能指令

/*
*MQTT配置用户属性
*LinkID 连接ID,目前只支持0
*scheme 连接方式，这里选择MQTT over TCP,这里设置为1
*client_id MQTTclientID 用于标志client身份
*username 用于登录 MQTT 服务器 的 username
*password 用于登录 MQTT 服务器 的 password
*cert_key_ID 证书 ID, 目前支持一套 cert 证书, 参数为 0
*CA_ID 目前支持一套 CA 证书, 参数为 0
*path 资源路径，这里设置为""
*设置成功返回true 反之false
*/
bool ESP8266_MQTTUSERCFG( char * pClient_Id, char * pUserName,char * PassWord)
{
    char cCmd [256];
    sprintf ( cCmd, "AT+MQTTUSERCFG=0,1,\"%s\",\"%s\",\"%s\",0,0,\"\"", pClient_Id,pUserName,PassWord );
    return ESP8266_Send_AT_Cmd( cCmd, "OK", NULL, 500 );
}


/*
*连接指定的MQTT服务器
*LinkID 连接ID,目前只支持0
*IP：MQTT服务器上对应的IP地址
*ComNum MQTT服务器上对应的端口号，一般为1883
*设置成功返回true 反之false
*/
bool ESP8266_MQTTCONN( char * Ip, int  Num)
{
    char cCmd [128];
    sprintf ( cCmd,"AT+MQTTCONN=0,\"%s\",%d,0", Ip,Num);
    return ESP8266_Send_AT_Cmd( cCmd, "OK", NULL, 500 );
}

/*
*订阅指定连接的 MQTT 主题, 可重复多次订阅不同 topic
*LinkID 连接ID,目前只支持0
*Topic 订阅的主题名字，这里设置为Topic
*Qos值：一般为0，这里设置为1
*设置成功返回true 反之false
*/
bool ESP8266_MQTTSUB(char * Topic)
{
    char cCmd [256];
    sprintf ( cCmd, "AT+MQTTSUB=0,\"%s\",1",Topic );
    return ESP8266_Send_AT_Cmd( cCmd, "OK", NULL, 500 );
}


/*
*在LinkID上通过 topic 发布数据 data, 其中 data 为字符串消息
*LinkID 连接ID,目前只支持0
*Topic 订阅的主题名字，这里设置为Topic
*data：字符串信息
*设置成功返回true 反之false
*/
bool ESP8266_MQTTPUB( char * Topic,char *temp)
{
    char cCmd [2048];
    sprintf (cCmd, "AT+MQTTPUB=0,\"%s\",\"%s\",1,0", Topic ,temp);
    return ESP8266_Send_AT_Cmd( cCmd, "OK", NULL, 1000 );
}

/*
*关闭 MQTT Client 为 LinkID 的连接, 并释放内部占用的资源
*LinkID 连接ID,目前只支持0
*Topic 订阅的主题名字，这里设置为Topic
*data：字符串信息
*设置成功返回true 反之false
*/
bool ESP8266_MQTTCLEAN(void)
{
    char cCmd [120];
    sprintf ( cCmd, "AT+MQTTCLEAN=0");
    return ESP8266_Send_AT_Cmd( cCmd, "OK", NULL, 500 );
}

//ESP8266发送字符串
//enumEnUnvarnishTx是否使能透传模式
//pStr字符串
//ulStrLength字符串长度
//ucId 连接号
//设置成功返回true， 反之false
bool MQTT_SendString(char * pTopic,char *temp2)
{

    bool bRet = false;
    ESP8266_MQTTPUB(pTopic,temp2);
      vTaskDelay(1000);
    bRet = true;
    return bRet;

}


#if 0
void ESP8266_STA_MQTTClient_Test(void)
{
      char str[1024];
        printf("正在配置ESP8266参数\r\n");
    ESP8266_AT_Test();//恢复出厂默认模式
    ESP8266_Net_Mode_Choose(STA);
    while(!ESP8266_JoinAP(User_ESP8266_SSID, User_ESP8266_PWD));
      ESP8266_MQTTUSERCFG(User_ESP8266_client_id,User_ESP8266_username,User_ESP8266_password);
      ESP8266_MQTTCONN( User_ESP8266_MQTTServer_IP, User_ESP8266_MQTTServer_PORT);
      ESP8266_MQTTSUB( User_ESP8266_MQTTServer_Topic);
        printf("\r\nMQTT配置完成");
        while(1)
        {
              sprintf(str,"aithinker");//格式化发送字符串到MQTT服务器
              MQTT_SendString (User_ESP8266_MQTTServer_Topic,str);//发送数据到MQTT服务器
        }
}
#endif

