

#ifndef PLATFORM_H_
#define PLATFORM_H_

#include <stdint.h>
#include <SDRAM/board_sdram.h>
#include "stdio.h"
#include "hal_data.h"
#include "FreeRTOS.h"
#include "task.h"
#include "MQ4_MQ5.h"
#include "KEY_BEEP_LED/key.h"
#include "LCD.h"
#include "BLK.h"
#include "ff.h"
#include "sd.h"
#include "recipe.h"

#define SDA_HIGH()    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_05_PIN_11, BSP_IO_LEVEL_HIGH)
#define SDA_LOW()     R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_05_PIN_11, BSP_IO_LEVEL_LOW)
#define SCL_HIGH()    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_05_PIN_12, BSP_IO_LEVEL_HIGH)
#define SCL_LOW()     R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_05_PIN_12, BSP_IO_LEVEL_LOW)
#define READ_SDA()    R_BSP_PinRead(BSP_IO_PORT_05_PIN_11)
#define RESET_VALUE 0

extern FATFS fs;

extern _Bool ceu_flag;
extern _Bool ceu_upload;
extern _Bool lvgl_begin;
extern _Bool tool_setup_done;
extern _Bool wifi;
extern _Bool mqtt;
extern _Bool Get_Tare_flag;
extern _Bool suiji;
extern _Bool say;
extern _Bool voice_change;
extern _Bool get_wifi;
extern _Bool wifi_con;
extern _Bool mqtt_con;
extern _Bool update_time;
extern _Bool recipe_receive;
extern _Bool recognize_receive;
extern _Bool ai_recommend;

extern uint8_t voice;
extern uint16_t temp_set;
extern uint8_t buf_in[1024] BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".sdram");
extern uint8_t buf_out[1024] BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".sdram");

extern rtc_time_t now_time;
extern _Bool iic_rx_done;
extern _Bool iic_tx_done;


void MyI2C_Start(void);
void MyI2C_Stop(void);
void MyI2C_SendByte(uint8_t Byte);
uint8_t MyI2C_ReceiveByte(void);
void MyI2C_SendAck(uint8_t AckBit);
uint8_t MyI2C_ReceiveAck(void);


void my_init();
void msleep(int ms);
void RTC_Init(void);
void init_DWT(void);
void delay_ns(uint32_t ns);
void delay_us(uint32_t us);
void delay_ms(uint32_t ms);
int user_read(char *buffer, int file, int count);
int user_write(char ptr, FILE* file);

#endif /* PLATFORM_H_ */
