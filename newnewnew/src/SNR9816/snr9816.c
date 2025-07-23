/*
 * snr9816.c
 *
 *  Created on: 2025年6月24日
 *      Author: Admin
 */

#include "hal_data.h"
#include <stdio.h>
#include <stdarg.h>
#include "FreeRTOS.h"
#include "task.h"
#include "platform.h"

int snr_printf(const char *format, ...);

/*================== 中断回调函数 ==================*/

void timer10_callback(timer_callback_args_t *p_args)
{
    if (p_args->event == TIMER_EVENT_CREST)
    {
    }

}

void snr_uart_callback(uart_callback_args_t *p_args){
    switch (p_args->event){
        case UART_EVENT_TX_COMPLETE:

        break;
        case UART_EVENT_RX_COMPLETE:

        break;
        case UART_EVENT_RX_CHAR:
            //R_SCI_B_UART_Write(&g_uart3_ctrl, (uint8_t *)&(p_args->data), 1);
        break;
        default:
        break;
    }
}

int snr_printf(const char *format, ...)
{
    char buffer[128];
    va_list args;
    va_start(args, format);

    int len = vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    if (len > 0){
        R_SCI_B_UART_Write(&snr_uart_ctrl, (uint8_t *)buffer, (uint32_t)len);
    }

    return len;
}


void snr_init(void)
{
    R_SCI_B_UART_Open(&snr_uart_ctrl, &snr_uart_cfg);
}



void snr_say_sentence(char *sentence, uint8_t len)
{
    uint16_t dat_len = len + 2;
    uint8_t buff[200]={0};
    buff[0]=0xFD;
    buff[1]=dat_len>>8;
    buff[2]=dat_len&0xFF;
    buff[3]=0x01;
    buff[4]=0x01;
    memcpy(buff+5,sentence,len);
    R_SCI_B_UART_Write(&snr_uart_ctrl, buff, 5+len);
}

void snr_stop(void){
    uint8_t buff[4];
    buff[0]=0xFD;
    buff[1]=0x00;
    buff[2]=0x01;
    buff[3]=0x02;
    R_SCI_B_UART_Write(&snr_uart_ctrl, (uint8_t *)buff, 4);
}

void snr_man_women(bool man)
{
    uint8_t buff[9];
    buff[0]=0xFD;
    buff[1]=0x00;
    buff[2]=0x06;
    buff[3]=0x01;
    buff[4]=0x01;
    if(man == 1){
        buff[5]=0x5B;
        buff[6]=0x6D;
        buff[7]=0x30;
        buff[8]=0x5D;
    }
    else{
        buff[5]=0x5B;
        buff[6]=0x6D;
        buff[7]=0x31;
        buff[8]=0x5D;
    }
    R_SCI_B_UART_Write(&snr_uart_ctrl, (uint8_t *)buff, 9);
}

//voice最大为9
void snr_voice(uint8_t voice)
{
    uint8_t buff[9];
    buff[0]=0xFD;
    buff[1]=0x00;
    buff[2]=0x06;
    buff[3]=0x01;
    buff[4]=0x01;
    buff[5]=0x5B;
    buff[6]=0x76;
    buff[7]=0x30 + (voice<10?voice:9);
    buff[8]=0x5D;
    R_SCI_B_UART_Write(&snr_uart_ctrl, (uint8_t *)buff, 9);
}



