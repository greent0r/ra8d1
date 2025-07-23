/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include <LCD.h>
#include "hal_data.h"
#include <stdio.h>
#include "core_cm85.h"
#include "platform.h"






#define SDA_HIGH()    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_05_PIN_11, BSP_IO_LEVEL_HIGH)
#define SDA_LOW()     R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_05_PIN_11, BSP_IO_LEVEL_LOW)
#define SCL_HIGH()    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_05_PIN_12, BSP_IO_LEVEL_HIGH)
#define SCL_LOW()     R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_05_PIN_12, BSP_IO_LEVEL_LOW)
#define READ_SDA()    R_BSP_PinRead(BSP_IO_PORT_05_PIN_11)


rtc_time_t now_time;
_Bool iic_rx_done=0;
_Bool iic_tx_done=0;
volatile bool g_data_received_flag = false;
volatile bool g_data_transmit_flag = false;

//信号量
_Bool ceu_flag=0;
_Bool ceu_upload=0;
_Bool lvgl_begin=0;
_Bool tool_setup_done=0;
_Bool wifi=0;
_Bool mqtt=0;
_Bool Get_Tare_flag=0;
_Bool suiji=0;
_Bool say=0;
_Bool voice_change=0;
_Bool get_wifi=0;
_Bool wifi_con=0;
_Bool mqtt_con=0;
_Bool update_time=0;
_Bool recipe_receive=0;
_Bool recognize_receive=0;
_Bool ai_recommend=0;

uint8_t voice=5;
uint16_t temp_set=300;

uint8_t buf_in[1024] BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".sdram");
uint8_t buf_out[1024] BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".sdram");

FATFS fs;                         /* FatFs文件系统对象 */

void my_init(){
    FRESULT res_sd;                   /* 文件操作结果 */
    bsp_sdram_init();
    R_IOPORT_Open (&g_ioport_ctrl, g_ioport.p_cfg);
    RTC_Init();
    R_SCI_B_UART_Open(&g_uart3_ctrl, &g_uart3_cfg);//用于debug
    init_DWT();
    res_sd = f_mount(&fs, "1:", 1);
    if(res_sd!=FR_OK)printf("res_sd1=%d\r\n",res_sd);

}

void msleep(int ms){
    vTaskDelay(ms);
}

//#define POOL_SIZE (2048 * 1024) // 1MB SDRAM pool
//
//uint8_t sdram_pool[POOL_SIZE] BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".sdram");
//static size_t offset = 0;
//
//void* my_sdram_alloc(size_t size)
//{
//    void* ptr = sdram_pool + offset;
//    offset += (size + 31) & ~31; // 对齐到 32 字节
//    if (offset > POOL_SIZE) return NULL;
//    return ptr;
//}
//
//void my_sdram_free(void)
//{
//    offset = 0;
//}

void MyI2C_W_SCL(uint8_t BitValue)
{
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_05_PIN_12, BitValue);
}

void MyI2C_W_SDA(uint8_t BitValue)
{
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_05_PIN_11, BitValue);
}

uint8_t MyI2C_R_SDA(void)
{
    return R_BSP_PinRead(BSP_IO_PORT_05_PIN_11);
}

void MyI2C_Start(void)
{
    R_IOPORT_PinCfg(&g_ioport_ctrl,  BSP_IO_PORT_05_PIN_11 , IOPORT_CFG_PORT_DIRECTION_OUTPUT |IOPORT_CFG_PORT_OUTPUT_HIGH);
    MyI2C_W_SDA(1);
    MyI2C_W_SCL(1);
    delay_us(2);
    MyI2C_W_SDA(0);
    delay_us(2);
    MyI2C_W_SCL(0);
}

void MyI2C_Stop(void)
{
    R_IOPORT_PinCfg(&g_ioport_ctrl,  BSP_IO_PORT_05_PIN_11 , IOPORT_CFG_PORT_DIRECTION_OUTPUT |IOPORT_CFG_PORT_OUTPUT_LOW);
    MyI2C_W_SDA(0);
    MyI2C_W_SCL(0);
    delay_us(2);
    MyI2C_W_SCL(1);
    delay_us(2);
    MyI2C_W_SDA(1);
    delay_us(2);
}

void MyI2C_SendByte(uint8_t Byte)
{
    uint8_t i;
    if(Byte&0x80)
        R_IOPORT_PinCfg(&g_ioport_ctrl,  BSP_IO_PORT_05_PIN_11 , IOPORT_CFG_PORT_DIRECTION_OUTPUT |IOPORT_CFG_PORT_OUTPUT_HIGH);
    else
        R_IOPORT_PinCfg(&g_ioport_ctrl,  BSP_IO_PORT_05_PIN_11 , IOPORT_CFG_PORT_DIRECTION_OUTPUT |IOPORT_CFG_PORT_OUTPUT_LOW);
    MyI2C_W_SCL(0);
    for (i = 0; i < 8; i ++){
        MyI2C_W_SDA(Byte & (0x80 >> i));
        delay_us(2);
        MyI2C_W_SCL(1);
        delay_us(2);
        MyI2C_W_SCL(0);
        delay_us(2);
    }
}

uint8_t MyI2C_ReceiveByte(void)
{
    uint8_t i, Byte = 0x00;
    R_IOPORT_PinCfg(&g_ioport_ctrl,  BSP_IO_PORT_05_PIN_11 , IOPORT_CFG_PORT_DIRECTION_INPUT);
    for (i = 0x80; i != 0; i >>= 1)
    {
        MyI2C_W_SCL(0);
        delay_us(2);
        MyI2C_W_SCL(1);
        if (MyI2C_R_SDA())  Byte |= i;
        else                Byte &= ~i;
        delay_us(2);
    }
    return Byte;
}

void MyI2C_SendAck(uint8_t AckBit)
{
    if(AckBit){
        MyI2C_W_SCL(0);
        R_IOPORT_PinCfg(&g_ioport_ctrl,  BSP_IO_PORT_05_PIN_11 , IOPORT_CFG_PORT_DIRECTION_OUTPUT |IOPORT_CFG_PORT_OUTPUT_LOW);
        MyI2C_W_SDA(0);
        delay_us(2);
        MyI2C_W_SCL(1);
        delay_us(2);
        MyI2C_W_SCL(0);
    }
    else{
        MyI2C_W_SCL(0);
        R_IOPORT_PinCfg(&g_ioport_ctrl,  BSP_IO_PORT_05_PIN_11 , IOPORT_CFG_PORT_DIRECTION_OUTPUT |IOPORT_CFG_PORT_OUTPUT_HIGH);
        MyI2C_W_SDA(1);
        delay_us(2);
        MyI2C_W_SCL(1);
        delay_us(2);
        MyI2C_W_SCL(0);
    }
}

uint8_t MyI2C_ReceiveAck(void)
{
    uint8_t AckBit;
    R_IOPORT_PinCfg(&g_ioport_ctrl,  BSP_IO_PORT_05_PIN_11 , IOPORT_CFG_PORT_DIRECTION_INPUT);
    delay_us(2);
    MyI2C_W_SCL(1);
    delay_us(2);
    AckBit = MyI2C_R_SDA();
    MyI2C_W_SCL(0);
    return AckBit;
}



void RTC_Init(void)
{
   rtc_time_t set_time =
   { .tm_sec = 0,  //秒
     .tm_min = 0,  //分
     .tm_hour = 0,  //小时
     .tm_mday = 0,  //日（一个月中）
     .tm_wday = 0,   //星期
     .tm_mon = 0,   //月份，0~11代表11~12月
     .tm_year = 0, //年份（如今年是2008，则这里输入2008-1900=108）
   };
   R_RTC_Open (rtc.p_ctrl, rtc.p_cfg);
   R_RTC_CalendarTimeSet (rtc.p_ctrl, &set_time); //设置当前时间
   R_RTC_PeriodicIrqRateSet (rtc.p_ctrl, RTC_PERIODIC_IRQ_SELECT_1_SECOND);
}

void rtc_callback(rtc_callback_args_t *p_args)
{
      switch (p_args->event){
         case RTC_EVENT_PERIODIC_IRQ:
            //R_RTC_CalendarTimeGet (rtc.p_ctrl, &now_time);
            break;
         default:
            break;
      }
}

void init_DWT(void)
{
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    DWT->CYCCNT = 0;
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

void delay_ns(uint32_t ns) {
    uint32_t delay_ticks = ((uint64_t)ns*SystemCoreClock)/1000000000UL;
    uint32_t start = DWT->CYCCNT;

    while ((DWT->CYCCNT - start) < delay_ticks);
}

void delay_us(uint32_t us)
{
    uint32_t ticks_per_us = SystemCoreClock / 1000000UL;
    uint32_t start = DWT->CYCCNT;
    uint32_t delay_ticks = us * ticks_per_us;
    while ((DWT->CYCCNT - start) < delay_ticks);
}

void delay_ms(uint32_t ms)
{
    uint32_t ticks_per_ms = SystemCoreClock / 1000UL;
    uint32_t start = DWT->CYCCNT;
    uint32_t delay_ticks = ms * ticks_per_ms;
    while ((DWT->CYCCNT - start) < delay_ticks);
}




void debug_uart3_callback(uart_callback_args_t *p_args)
{
    switch (p_args->event){
        case UART_EVENT_TX_COMPLETE:
            g_data_transmit_flag = true;
        break;
        case UART_EVENT_RX_COMPLETE:
            g_data_received_flag = true;
        break;
        case UART_EVENT_RX_CHAR:
            R_SCI_B_UART_Write(&g_uart3_ctrl, (uint8_t *)&(p_args->data), 1);
        break;
        default:
        break;
    }
}

int user_read(char *buffer, int file, int count)
{
    FSP_PARAMETER_NOT_USED(file);
    int bytesReceived = 0;

    for (int i = 0; i < count; i++){
        // Start Transmission
        g_data_received_flag = false;
        fsp_err_t err = R_SCI_B_UART_Read(&g_uart3_ctrl, (uint8_t * const)(buffer + i), 1U);
        if (FSP_SUCCESS != err){
             return -1;
        }
        /* Wait for event receive complete */
        while (!g_data_received_flag){}
        bytesReceived++;
        if ((char)(buffer[i]) == '\r'){ //Break out of the loop if ENTER is pressed
            break;
        }
    }
    __NOP();
    return bytesReceived;
}

int user_write(char ptr, FILE* file)
{
  FSP_PARAMETER_NOT_USED(file);
  // Start Transmission
  g_data_transmit_flag = false;
  if(ptr != 0){
      fsp_err_t err = R_SCI_B_UART_Write(&g_uart3_ctrl, (uint8_t * const)(&ptr), 1U);
      if (FSP_SUCCESS != err){
           return -1;
      }
  }
  else
      return 0;
  // Wait for event receive complete
  while (!g_data_transmit_flag);
  return FSP_SUCCESS;
}

/* Redirect sdtio as per https://github.com/picolibc/picolibc/blob/main/doc/os.md */
static FILE __stdio = FDEV_SETUP_STREAM(user_write, NULL, NULL, _FDEV_SETUP_WRITE);
FILE *const stdin = &__stdio;
__strong_reference(stdin, stdout);
__strong_reference(stdin, stderr);



