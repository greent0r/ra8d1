#include <esp_thread.h>
#include "platform.h"
#include "WIFI/bsp_wifi_esp.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "my_wifi.h"
#include "ov5640.h"
#include "cJSON.h"
#define TJE_IMPLEMENTATION
#include "tiny_jpeg.h"
#include "recipe.h"


//git
extern TaskHandle_t esp_thread;

void esp_decode();
void upload();
void parse_ingredients(cJSON *root);
void parse_basic_info(cJSON *root);
void parse_steps(cJSON *root);

void esp_thread_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);

    esp_init();
    esp_printf("AT\r\n");
    //ESP8266_Send_AT_Cmd("AT", "OK", NULL, 0);
    //connect_wifi("HUST_WIRELESS_2.4g","123456789");
    vTaskDelay(1000);
    connect_mqtt();
    static int times=0;

    //while(!lvgl_begin){vTaskDelay (10);}
    while (1){
        if (ESP8266_Fram_Record_Struct.InfBit.FramFinishFlag){
            ESP8266_Fram_Record_Struct.InfBit.FramFinishFlag = 0;
            ESP8266_Fram_Record_Struct.Data_RX_BUF[ESP8266_Fram_Record_Struct.InfBit.FramLength] = '\0';

            if(strlen(ESP8266_Fram_Record_Struct.Data_RX_BUF)>1){
                printf("接收一帧数据：\n%s\n",ESP8266_Fram_Record_Struct.Data_RX_BUF);
                esp_decode();
            }

            ESP8266_Fram_Record_Struct.InfBit.FramLength = 0;
        }
        if(mqtt_con){
            esp_printf("AT+MQTTCLEAN=0\r\n");
            vTaskDelay(1000);
            connect_mqtt();
            mqtt_con=0;
        }
        if(get_wifi){
            get_wifi_list();
            get_wifi=0;
        }
        if(wifi_con){
            wifi_con=0;
            connect_wifi(ESP8266_SSID, ESP8266_PWD);
        }
        upload();
        times=(times+1)%200;
        vTaskDelay(10);
    }
}



void esp_decode()
{
    char* start = ESP8266_Fram_Record_Struct.Data_RX_BUF;
    if (strstr(start, "+MQTTSUBRECV") != NULL) {
        if(strstr(start,"{\"year\":")!=NULL){
            start=strstr(start,"{\"year\":");
            int year, month, day, hour, minute, second;
            sscanf(start,"{\"year\":%d,\"month\":\"%d\",\"day\":\"%d\",\"hours\":\"%d\",\"minutes\":\"%d\",\"seconds\":\"%d\"",
                       &year, &month, &day, &hour, &minute, &second);
                now_time.tm_year = year; now_time.tm_mon  = month;  now_time.tm_mday = day;
                now_time.tm_hour = hour; now_time.tm_min  = minute; now_time.tm_sec  = second;
                update_time = 1;  // 标记时间已更新
        }
        else if(strstr(start,"result")!=NULL){
            for(uint i=0;i<6;i++){
                memset(result[i].name,0,64);
                result[i].score=0.0;
            }
            const char *json_start = strchr(start, '{');
            printf("收到识别结果\n");
            // 解析JSON
            cJSON *root = cJSON_Parse(json_start);
            if(root == NULL){
                printf("JSON解析失败\n");
                recognize_receive = 0;
                return;
            }
            cJSON *ingredient = cJSON_GetObjectItem(root, "ingredient");
            if(ingredient){
                cJSON *ingredient_result = cJSON_GetObjectItem(ingredient, "result");
                if(ingredient_result && cJSON_IsArray(ingredient_result)){
                    int ingredient_count = cJSON_GetArraySize(ingredient_result);
                    for(int i=0; i<3 && i<ingredient_count; i++){  // 最多取3个
                        cJSON *item = cJSON_GetArrayItem(ingredient_result, i);
                        if(item){
                            cJSON *name = cJSON_GetObjectItem(item, "name");
                            cJSON *score = cJSON_GetObjectItem(item, "score");
                            if(name && score){
                                strncpy(result[i].name, name->valuestring, 63);
                                result[i].score = (float)score->valuedouble;
                            }
                        }
                    }
                }
            }
            cJSON *dishs = cJSON_GetObjectItem(root, "dishs");
            if(dishs){
                cJSON *dish_result = cJSON_GetObjectItem(dishs, "result");
                if(dish_result && cJSON_IsArray(dish_result)){
                    int dish_count = cJSON_GetArraySize(dish_result);
                    for(int i=0; i<3 && i<dish_count; i++){  // 最多取3个
                        cJSON *item = cJSON_GetArrayItem(dish_result, i);
                        if(item){
                            cJSON *name = cJSON_GetObjectItem(item, "name");
                            cJSON *probability = cJSON_GetObjectItem(item, "probability");
                            if(name && probability){
                                strncpy(result[3+i].name, name->valuestring, 63);
                                result[3+i].score = (float)atof(probability->valuestring);
                            }
                        }
                    }
                }
            }
            cJSON_Delete(root);
            recognize_receive=1;
        }
        else if(strstr(start,"OVER")!=NULL){
            printf("Recipe download completed!\n");
            recipe_receive=1;
        }
        else{
            start=strstr(start,"+MQTTSUBRECV");
            const char *json_start = strchr(start, '{');
            if (json_start == NULL) return;
            cJSON *root = cJSON_Parse(json_start);
            cJSON *name = cJSON_GetObjectItem(root, "name");
            cJSON *ingredients = cJSON_GetObjectItem(root, "ingredients");
            cJSON *steps = cJSON_GetObjectItem(root, "steps");
            if (name){
                memset(&recipe_rx, 0, sizeof(recipe_rx));
                parse_basic_info(root);
            }
            else if (ingredients)
                parse_ingredients(ingredients);
            else
                parse_steps(steps);
            cJSON_Delete(root);
        }
    }
    else if(strstr(start,"+CWLAP:")!=NULL){
        while ((start = strstr(start, "+CWLAP:")) != NULL) {
            if (ap_count >= 10) {
                break;
            }
            wifi_ap_info_t* ap = &ap_list[ap_count];
            sscanf(start,"+CWLAP:(%hhu,\"%31[^\"]\",%hhd",&ap->ecn, ap->ssid, &ap->rssi);
            ap_count++;
            start += 7;  // 跳过 "+CWLAP:" 的长度
        }
    }
    else if(strstr(start,"WIFI GOT IP")!=NULL){
        wifi=1;
    }
    else if(strstr(start,"AT+MQTTSUB=0")!=NULL){
        if(strstr(start,"ERROR")==NULL)
            mqtt=1;
    }
    else if(strstr(start,"+MQTTDISCONNECTED")!=NULL){
        mqtt=0;
    }
    else if(strstr(start,"WIFI DISCONNECT")!=NULL && strstr(start,"WIFI CONNECTED")==NULL){
        wifi=0;
    }
    else{

    }
}

// 十六进制字符查找表
static const char hex_chars[] = "0123456789ABCDEF";

void upload()
{
    static uint8_t flag=5;
    static uint8_t recommend_id=5;
    uint8_t buffer[512];
    if(ai_recommend){
        ai_recommend=0;
        recommend_id=(recommend_id+1)%10;
        sprintf(buffer,"{\"id\":2,\"dp\":{\"req_id\":[{\"v\":%d}]}}",recommend_id);
        esp_printf("AT+MQTTPUBRAW=0,\"$sys/sj4y44Ap42/Format_Dev1/dp/post/json\",%u,0,0\r\n", 34);
        vTaskDelay(10);
        esp_printf("%s", buffer);
        vTaskDelay(10);
    }
    if(ceu_upload){
        memset(jpg_data,0,sizeof(jpg_data));
        for (size_t i = 0; i < 240*320; i++) {
            uint16_t rgb565 = (*(g_image_vga_sram + 2*i)<<8) + *(g_image_vga_sram + 2*i+1); // 每个像素占 2 字节
            rgb888_data[i * 3 + 0] = (uint8_t)((rgb565 >> 11) * 255 / 31); // R
            rgb888_data[i * 3 + 1] = (uint8_t)((rgb565 >> 5 & 0x3F) * 255 / 63); // G
            rgb888_data[i * 3 + 2] =  (uint8_t)((rgb565 & 0x1F) * 255 / 31); // B
        }

        if(!tje_encode_to_file_at_quality(
              "1:/test.jpeg",
              1,
              320,
              240,
              3,
              rgb888_data)){
            printf("jpeg encode error\n");

        }
        else{
            printf("jpeg_length=%d\n",jpg_len);
            const size_t packet_size = 12000;// 每包最大字节数
            char* hex_buffer=mymalloc(packet_size*2 + 1);
            char* str=mymalloc(24500);
            memset(hex_buffer,0,packet_size*2 + 1);
            memset(str,0,24500);
            // 构建当前包的 hex 字符串
            for (int j = 0; j < jpg_len; j++) {
                hex_buffer[2*j] = hex_chars[(jpg_data[j] >> 4) & 0x0F];
                hex_buffer[2*j+1] = hex_chars[jpg_data[j] & 0x0F];
            }

            sprintf(str,"{\"id\":2,\"dp\":{\"Upload_Pic\":[{\"v\":\"%s\"}],\"Upload_Pic_id\":[{\"v\":%d}]}}", hex_buffer,flag);
            esp_printf("AT+MQTTPUBRAW=0,\"$sys/sj4y44Ap42/Format_Dev1/dp/post/json\",%u,0,0\r\n", 65+2*jpg_len);
            vTaskDelay(10);
            esp_printf("%s", str);
            vTaskDelay(10);
            myfree(str);
            myfree(hex_buffer);
            flag=(flag+1)%10;
        }
        jpg_len=0;
        ceu_upload=0;
        //ceu_flag=1;
        //R_SCI_B_UART_Write(&g_uart3_ctrl, g_image_vga_sram, 320*240*2);
    }
}


void parse_basic_info(cJSON *root) {
    strncpy(recipe_rx.name, cJSON_GetObjectItem(root, "name")->valuestring, sizeof(recipe_rx.name));
    strncpy(recipe_rx.description, cJSON_GetObjectItem(root, "description")->valuestring, sizeof(recipe_rx.description));
    strncpy(recipe_rx.category, cJSON_GetObjectItem(root, "category")->valuestring, sizeof(recipe_rx.category));

    recipe_rx.difficulty = cJSON_GetObjectItem(root, "difficulty")->valueint;
    recipe_rx.prep_time = cJSON_GetObjectItem(root, "prep_time")->valueint;
    recipe_rx.cook_time = cJSON_GetObjectItem(root, "cook_time")->valueint;

    recipe_rx.name[sizeof(recipe_rx.name)-1] = '\0';
    recipe_rx.description[sizeof(recipe_rx.description)-1] = '\0';
    recipe_rx.category[sizeof(recipe_rx.category)-1] = '\0';
}

void parse_ingredients(cJSON *root) {
    if (!cJSON_IsArray(root)) return;

    cJSON *item;
    cJSON_ArrayForEach(item, root) {
        if (recipe_rx.ingredient_count >= MAX_INGREDIENTS) break;

        cJSON *name = cJSON_GetObjectItem(item, "name1");
        cJSON *qty = cJSON_GetObjectItem(item, "quantity");
        cJSON *unit = cJSON_GetObjectItem(item, "unit");

        if (name && qty && unit) {
            ingredient_t *ing = &recipe_rx.ingredients[recipe_rx.ingredient_count];
            strcpy(ing->name, name->valuestring);
            ing->quantity = (float)qty->valuedouble;
            strcpy(ing->unit, unit->valuestring);
            recipe_rx.ingredient_count++;
        }
    }
}

void parse_steps(cJSON *root) {
    if (!cJSON_IsArray(root)) return;

    cJSON *item;
    cJSON_ArrayForEach(item, root) {
        if (recipe_rx.step_count >= MAX_STEPS) break;

        cJSON *num = cJSON_GetObjectItem(item, "step_number");
        cJSON *inst = cJSON_GetObjectItem(item, "instruction");
        cJSON *note = cJSON_GetObjectItem(item, "note");

        if (num && inst) {
            step_t *step = &recipe_rx.steps[recipe_rx.step_count];
            step->step_number = num->valueint;
            strncpy(step->instruction, inst->valuestring, sizeof(step->instruction) - 1);
            if (note) strncpy(step->note, note->valuestring, sizeof(step->note) - 1);
            recipe_rx.step_count++;
        }
    }
}
