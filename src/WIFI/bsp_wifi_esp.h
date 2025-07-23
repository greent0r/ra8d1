/*
 * bsp_wifi_esp.h
 *
 *  Created on: 2025年6月6日
 *      Author: greentor
 */

#ifndef WIFI_BSP_WIFI_ESP_H_
#define WIFI_BSP_WIFI_ESP_H_

#include "platform.h"
#include "hal_data.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

#define RX_BUF_MAX_LEN 1024       //最大字节数


//ESP8266模式选择
typedef enum
{
    STA,
    AP,
    STA_AP
}ENUM_Net_ModeTypeDef;

//网络传输层协议，枚举类型
typedef enum{
     enumTCP,
     enumUDP,
} ENUM_NetPro_TypeDef;

typedef enum{
    Multiple_ID_0 = 0,
    Multiple_ID_1 = 1,
    Multiple_ID_2 = 2,
    Multiple_ID_3 = 3,
    Multiple_ID_4 = 4,
    Single_ID_0 = 5,
} ENUM_ID_NO_TypeDef;

extern struct STRUCT_USART_Fram   //数据帧结构体
{
    char Data_RX_BUF[RX_BUF_MAX_LEN];
    union
    {
        __IO uint16_t InfAll;
        struct
        {
            __IO uint16_t FramLength       :15;                               // 14:0
            __IO uint16_t FramFinishFlag   :1;                                // 15
        }InfBit;
    };

}ESP8266_Fram_Record_Struct;

extern struct STRUCT_USART_Fram ESP8266_Fram_Record_Struct;
extern SemaphoreHandle_t xUARTBufferMutex;

void esp_init(void);
int esp_printf(const char *format, ...);

//初始化和TCP功能函数
void ESP8266_AT_Test(void);
bool ESP8266_Send_AT_Cmd(char *cmd,char *ack1,char *ack2,uint32_t time);
bool ESP8266_Net_Mode_Choose(ENUM_Net_ModeTypeDef enumMode);
bool ESP8266_JoinAP( char * pSSID, char * pPassWord );
bool ESP8266_Enable_MultipleId ( bool enumEnUnvarnishTx );
bool ESP8266_Link_Server(ENUM_NetPro_TypeDef enumE, char * ip, char * ComNum, ENUM_ID_NO_TypeDef id);
bool ESP8266_SendString(bool enumEnUnvarnishTx, char * pStr, uint32_t ulStrLength, ENUM_ID_NO_TypeDef ucId );
bool ESP8266_UnvarnishSend ( void );
void ESP8266_ExitUnvarnishSend ( void );
uint8_t ESP8266_Get_LinkStatus ( void );

//MQTT功能函数
bool ESP8266_MQTTUSERCFG( char * pClient_Id, char * pUserName,char * PassWord);
bool ESP8266_MQTTCONN( char * Ip, int Num);
bool ESP8266_MQTTSUB(char * Topic);
bool ESP8266_MQTTPUB( char * Topic,char *temp);
bool ESP8266_MQTTCLEAN(void);
bool MQTT_SendString(char * pTopic,char *temp2);






#endif /* WIFI_BSP_WIFI_ESP_H_ */
