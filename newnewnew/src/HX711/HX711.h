#ifndef __HX711_H
#define __HX711_H

#include "platform.h"
#include "hal_data.h"

#define  HX711_DATA_IN  R_BSP_PinRead(BSP_IO_PORT_08_PIN_04)
#define  HX711_DATA_H   R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_08_PIN_04, BSP_IO_LEVEL_HIGH)
#define  HX711_DATA_L   R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_08_PIN_04, BSP_IO_LEVEL_LOW)
#define  HX711_SCK_H    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_01_PIN_07, BSP_IO_LEVEL_HIGH)
#define  HX711_SCK_L    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_01_PIN_07, BSP_IO_LEVEL_LOW)



#define MEDIAN_LEN  5           //中值滤波的滤波长度,一般取奇数
#define MEDIAN      3           //中值在滤波数组中的位置


extern uint32_t   buffer[MEDIAN_LEN];       //中值滤波的数据缓存
extern int   medleng;              //一组中值滤波数据中,进入滤波缓存的数据个数
extern uint32_t   xd,xd1;                   //数据对比大小中间变量

extern uint32_t weight;                     //重量值
extern uint32_t pi_weight;              //皮重
extern uint32_t hx711_xishu;      //这是一个修正系数，例如1000g砝码称出来是934g，则HX711_xishu=原数据*1000/934;

void HX711_Data_Out(void);
void HX711_Data_In(void);
uint32_t Read_HX711(void);
void Get_Tare(void);
void Get_Weight();

#endif

