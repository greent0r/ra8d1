#ifndef _MAX6675_H_
#define _MAX6675_H_

#include "platform.h"
#include "hal_data.h"


#define MAX6675_CS_L R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_00_PIN_01, BSP_IO_LEVEL_LOW)
#define MAX6675_CS_H R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_00_PIN_01, BSP_IO_LEVEL_HIGH)

#define MAX6675_SCK_L  R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_00_PIN_02, BSP_IO_LEVEL_LOW)
#define MAX6675_SCK_H R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_00_PIN_02, BSP_IO_LEVEL_HIGH)

#define MAX6675_SO  R_BSP_PinRead(BSP_IO_PORT_00_PIN_00)



extern double temper;



unsigned int MAX6675_ReadReg(void);         //读取全部16位数据
double read_temper(void);                   //读取温度









#endif
