
#ifndef GT911_H_
#define GT911_H_

#include "hal_data.h"
#include "FreeRTOS.h"
#include "task.h"
#include "platform.h"

/* 控制液晶显示方向 */
#define USE_HORIZONTAL 1
#if USE_HORIZONTAL == 0 || USE_HORIZONTAL == 2
#define LCD_H 600
#define LCD_V 1024
#else
#define LCD_H 1024
#define LCD_V 600
#endif

/* 端口定义 */
#define GT_RST_GPIO_PIN     (BSP_IO_PORT_05_PIN_14)     // Reset
#define GT_INT_GPIO_PIN     (BSP_IO_PORT_04_PIN_02)     // Interrupt
/* 端口中断定义 */
#if 0
    #define GT_INT_IRQn GPIOD_IRQn
    #define GT_INT_IRQHandler GPIOD_Handler
#endif
/* 端口电平状态 */
#define GT_RST_Set() R_IOPORT_PinWrite(&g_ioport_ctrl, GT_RST_GPIO_PIN, BSP_IO_LEVEL_HIGH)
#define GT_RST_Clr() R_IOPORT_PinWrite(&g_ioport_ctrl, GT_RST_GPIO_PIN, BSP_IO_LEVEL_LOW)

#define GT_INT_Set() R_IOPORT_PinWrite(&g_ioport_ctrl, GT_INT_GPIO_PIN, BSP_IO_LEVEL_HIGH)
#define GT_INT_Clr() R_IOPORT_PinWrite(&g_ioport_ctrl, GT_INT_GPIO_PIN, BSP_IO_LEVEL_LOW)

/* 触摸IC相关寄存器 */
#define GT_DEV_ADDR 0x50
#define GT_DEV_ADDR_WRITE 0xA0
#define GT_DEV_ADDR_READ  0xA1

#define ADDR_SET 0
#if ADDR_SET == 0
#define GT_Write_Addr 0xBA
#define GT_Read_Addr 0xBB
#else
#define GT_Write_Addr 0x28
#define GT_Read_Addr 0x29
#endif

#define GT_ID_Addr 0x8140
#define GT_CFG_Addr 0x8047
#define GT_Point_Addr 0x814E

/* 定义最多触摸点个数 */
#define TOUCH_MAX 5

/* 定义触摸状态 */
#define TP_PRES_DOWN 0x80
#define TP_CATH_PRES 0x40

typedef struct
{
    uint8_t flag;
    uint8_t num;
    uint8_t sta;
    uint16_t x[TOUCH_MAX];
    uint16_t y[TOUCH_MAX];
} TouchStructure;

extern TouchStructure TouchInfo;

/* 函数说明 */
uint8_t gt9xx_WR_DATA(uint16_t addr, uint8_t data);
uint8_t gt9xx_RD_DATA(uint16_t addr, uint8_t len, uint8_t *value);
void gt9xx_Init(void);
void gt9xx_Scan();
void GT_INTScan(void);
void gt9xx_Test(void);


#endif /* GT911_GT911_H_ */
