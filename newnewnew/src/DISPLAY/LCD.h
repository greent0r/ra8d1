/*
 * LCD.h
 *
 *  Created on: 2025Äê6ÔÂ6ÈÕ
 *      Author: greentor
 */

#ifndef DISPLAY_LCD_H_
#define DISPLAY_LCD_H_


#include "stdio.h"
#include "hal_data.h"
#include "lvgl.h"

#define LCD_RES_Set() R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_01, BSP_IO_LEVEL_HIGH)
#define LCD_RES_Clr() R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_01, BSP_IO_LEVEL_LOW)

//#define LCD_BLK_Set() R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_01, BSP_IO_LEVEL_HIGH)
//#define LCD_BLK_Clr() R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_01, BSP_IO_LEVEL_LOW)

extern uint32_t *lcd_current_working_buffer;



#define HSIZE               1024
#define VSIZE               600

#define X1_CO_ORDINATE      (0U)
#define Y1_CO_ORDINATE      (0U)
#define BYTES_PER_PIXEL     (4)       //32 bit format
#define RED         (0x00FF0000)
#define GREEN       (0x0000FF00)
#define BLUE        (0x000000FF)
#define BLACK       (0x00000000)
#define WHITE       (0xFFFFFFFF)
#define YELLOW      (0xFFFFFF00)
#define MAGENTA     (0x00FF00FF)
#define CYAN        (0x0000FFFF)

void lcd_init(void);
void lcd_clear(uint32_t color);
void lcd_swap_buffer(void);
void screen_display(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint32_t color);

#endif /* DISPLAY_LCD_H_ */
