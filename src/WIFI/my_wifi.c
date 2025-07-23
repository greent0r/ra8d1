#include "my_wifi.h"
#include "ov5640.h"
#include "ceu.h"


#define MAX_AP_NUM 10  // 最多保存 10 个 AP

wifi_ap_info_t ap_list[MAX_AP_NUM];
uint8_t ap_count = 0;  // 当前 AP 数量

char* ESP8266_SSID;
char* ESP8266_PWD;

void get_wifi_list()
{
    for (int i = 0; i < ap_count; i++) {
        wifi_ap_info_t* ap = &ap_list[i];
        printf("索引 %d:\n", i);
        printf("  SSID: %s\n", ap->ssid);
        printf("  RSSI: %d dBm\n", ap->rssi);
        printf("  加密方式: %u\n", ap->ecn);
        printf("-------------------------\n");
    }
    ap_count = 0;
    memset(ap_list, 0, sizeof(ap_list));
    esp_printf("AT+CWLAP\r\n");
}

_Bool connect_wifi(char * pSSID, char * pPassWord)
{
    //ESP8266_Send_AT_Cmd ( "AT+CWMODE=1", "OK", "no change", 0);
    //if(!ESP8266_MQTTUSERCFG(User_ESP8266_client_id,User_ESP8266_username,User_ESP8266_password))return 0;
    esp_printf("AT+RST\r\n");
    vTaskDelay(2000);
    printf("SSID=%s,PWD=%s\n",ESP8266_SSID, ESP8266_PWD);
    esp_printf("AT\r\n");
    vTaskDelay(1000);
    esp_printf("AT+CWMODE=1\r\n");
    vTaskDelay(1000);
    esp_printf("AT+CWJAP=\"%s\",\"%s\"\r\n", pSSID, pPassWord);
    vTaskDelay(1000);
    //ESP8266_JoinAP(pSSID, pPassWord);
    return 1;
}

_Bool connect_mqtt(void)
{
    esp_printf("AT\r\n");
    vTaskDelay(1000);
    esp_printf("AT+MQTTUSERCFG=0,1,\"%s\",\"%s\",\"%s\",0,0,\"\"\r\n",User_ESP8266_client_id,User_ESP8266_username,User_ESP8266_password);
    vTaskDelay(2000);
    esp_printf("AT+MQTTCONN=0,\"%s\",%d,0\r\n",User_ESP8266_MQTTServer_IP, User_ESP8266_MQTTServer_PORT);
    vTaskDelay(1000);
    esp_printf("AT+MQTTSUB=0,\"%s\",1\r\n",User_ESP8266_MQTTServer_Topic);
    vTaskDelay(1000);
    return 1;
}

_Bool img_upload(){

    return 1;
}









