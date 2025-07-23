/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "blinky_thread.h"
#include "platform.h"
#include "FreeRTOS.h"
#include "task.h"
#include "HX711/HX711.h"
#include "FILE/cJSON.h"
#include "SNR9816/snr9816.h"
#include "KEY_BEEP_LED/ws2812.h"
#include "KEY_BEEP_LED/beep.h"
#include "KEY_BEEP_LED/key.h"
#include "MAX17048/max17048.h"
#include "MAX6675/max6675.h"
#include "MQ4_MQ5/MQ4_MQ5.h"
#include "my_wifi.h"
#include "FILE/ff.h"
#include "gui_guider.h"
#include "lvgl.h"
#include "gt911.h"
#include "recipe.h"
#include "mymalloc.h"
#include "Gb2utf8.h"
#include "custom.h"
#include "max17048.h"

#define LED_ON  R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_01, BSP_IO_LEVEL_LOW)
#define LED_OFF R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_01, BSP_IO_LEVEL_HIGH)


extern MKFS_PARM f_opt;
extern FATFS fs;                         /* FatFs��浠剁郴缁�瀵硅薄 */
extern FIL fnew;                         /* ��浠跺�硅薄 */
extern UINT fnum;                        /* ��浠舵����璇诲���伴�� */
extern FRESULT res_sd;                   /* ��浠舵��浣�缁��� */
extern BYTE ReadBuffer[1024];        /* 璇荤��插�� */
extern BYTE WriteBuffer[1024];
extern BYTE work[FF_MAX_SS]; /* Work area (larger is better for processing time) */

void read_and_parse_json_file(void);
void write_json_file(void);

uint8_t bit_reverse_byte(uint8_t b) {
    b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
    b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
    b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
    return b;
}

void bit_reverse_array(uint8_t *arr, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        arr[i] = bit_reverse_byte(arr[i]);
    }
}

uint8_t buff[400]={0};

/* Blinky Thread entry function */
void blinky_thread_entry (void * pvParameters)
{
    FSP_PARAMETER_NOT_USED(pvParameters);
    //HX711_Data_In();
    snr_init();
    beep_pwm_init();
    key_init();
    max17048_init();
    adc_init();
    beep_stop();
    //WS2812_Set(0,0xFF,0x00,0x00);
    LED_ON;
    static int times=0;
    while(!lvgl_begin){vTaskDelay (10);}
    while (1){
        if(say==1){
            say=0;
            memset(buf_in, 0, sizeof(buf_in));
            memset(buf_out, 0, sizeof(buf_out));
            strcpy(buf_in, myrecipe.steps[recipe_step].instruction);
            UTF8ToGB(buf_in, strlen(buf_in), buf_out, sizeof(buf_out));
            uint16_t dat_len = strlen(buf_out);
            memset(buff,0,sizeof(buff));
            buff[0]=0xFD;
            buff[1]=(dat_len+2)>>8;
            buff[2]=(dat_len+2)&0xFF;
            buff[3]=0x01;
            buff[4]=0x01;
            memcpy(buff+5,buf_out,dat_len);
            R_SCI_B_UART_Write(&snr_uart_ctrl, buff, 5+dat_len);
            //snr_say_sentence(buf_out, dat_len);
            vTaskDelay(1000);
        }
        if(voice_change){
            memset(buff,0,sizeof(buff));
            buff[0]=0xFD;
            buff[1]=0x00;
            buff[2]=0x06;
            buff[3]=0x01;
            buff[4]=0x01;
            buff[5]=0x5B;
            buff[6]=0x76;
            buff[7]=0x30 + (voice&0xFF);
            buff[8]=0x5D;
            R_SCI_B_UART_Write(&snr_uart_ctrl, buff, 9);
            voice_change=0;
        }

        if(times==0){
            max17048_update();
            if((Read_ADC_Voltage_Value(0)>2.0)||(Read_ADC_Voltage_Value(4)>2.0)){
                beep_start();
            }else{
                beep_stop();
            }
        }

        if(tool_setup_done && times%2==0){
            if(Get_Tare_flag){
                Get_Tare();
                Get_Tare_flag=0;
            }
            Get_Weight();
        }
        if(tool_setup_done && times%5==0){
            read_temper();
            if(temper > temp_set){
                beep_start();
            }else{
                beep_stop();
            }
        }

        times=(times+1)%20;
        vTaskDelay (100);
    }
}





