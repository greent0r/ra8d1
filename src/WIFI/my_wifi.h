/*
 * my_wifi.h
 *
 *  Created on: 2025年7月1日
 *      Author: greentor
 */

#ifndef WIFI_MY_WIFI_H_
#define WIFI_MY_WIFI_H_

#include "platform.h"
#include "hal_data.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"
#include "bsp_wifi_esp.h"



#define User_ESP8266_client_id    "Format_Dev1"   //MQTTclientID 用于标志client身份  最长256字节
#define User_ESP8266_username     "sj4y44Ap42"       //用于登录 MQTT 服务器 的 username, 最长 64 字节
#define User_ESP8266_password     "version=2018-10-31&res=products%2Fsj4y44Ap42%2Fdevices%2FFormat_Dev1&et=1908435196&method=md5&sign=j8oLc7iqevim26FOMdjr2Q%3D%3D"          //用于登录 MQTT 服务器 的 password, 最长 64 字节
#define User_ESP8266_MQTTServer_IP     "mqtts.heclouds.com"     //MQTT本地服务器IP
#define User_ESP8266_MQTTServer_PORT   1883     //服务器端口号
#define User_ESP8266_MQTTServer_Topic "$sys/sj4y44Ap42/Format_Dev1/#"


#define MAX_SSID_LEN    32

extern char* ESP8266_SSID;
extern char* ESP8266_PWD;


typedef struct {
    uint8_t ecn;                    // 加密类型
    char ssid[MAX_SSID_LEN];        // SSID 名称
    int8_t rssi;                    // 信号强度
} wifi_ap_info_t;




extern wifi_ap_info_t ap_list[10];
extern uint8_t ap_count;



extern _Bool connect_wifi(char * pSSID, char * pPassWord);
void get_wifi_list();
_Bool connect_mqtt(void);

#endif /* WIFI_MY_WIFI_H_ */
