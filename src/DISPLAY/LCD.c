#include <DISPLAY/LCD.h>
#include <DISPLAY/gt911.h>
#include "platform.h"

uint32_t *lcd_current_working_buffer = (uint32_t *) &g_framebuffer[0][0];
uint16_t g_hz_size, g_vr_size;
uint32_t g_buffer_size;
uint8_t * g_p_single_buffer, *g_p_double_buffer;


void lcd_init(void){
    fsp_err_t err = FSP_SUCCESS;
    printf("glcdc init\n");

    //LCD_BLK_Set();
    LCD_RES_Set();
    delay_ms(20);
    LCD_RES_Clr();
    delay_ms(20);
    LCD_RES_Set();
    delay_ms(120);

    g_hz_size = (g_display_cfg.input[0].hsize);
    g_vr_size = (g_display_cfg.input[0].vsize);
    g_buffer_size = (uint32_t) (g_hz_size * g_vr_size * BYTES_PER_PIXEL);
    g_p_single_buffer = (uint8_t *) g_display_cfg.input[0].p_base;
    g_p_double_buffer = g_p_single_buffer + g_buffer_size;

    err = R_GLCDC_Open(&g_display_ctrl, &g_display_cfg);
    if(FSP_SUCCESS != err) {
        printf("\r\nGLCDC driver initialization FAILED:%d\r\n",err);
    }
    err = R_GLCDC_Start(&g_display_ctrl);
    if(FSP_SUCCESS != err) {
        printf("\r\nGLCDC driver initialization FAILED:%d\r\n",err);
    }

    R_GLCDC_BufferChange(&g_display_ctrl, (uint8_t*)g_framebuffer[0], 0);
    //screen_display((uint16_t)X1_CO_ORDINATE, (uint16_t)Y1_CO_ORDINATE, g_hz_size, g_vr_size, GREEN);
}

#if 1

static void lcd_set_working_buffer(uint8_t index){
    if (index >= 1 && index <= 2){
        lcd_current_working_buffer = (uint32_t *)g_framebuffer[index - 1];
    }
}
//index=1 or 2
static void lcd_set_display_buffer(uint8_t index){
    /* 更改图层的帧缓冲区指针 */
    R_GLCDC_BufferChange(&g_display_ctrl, (uint8_t*)g_framebuffer[index - 1], 0);
}

void lcd_clear(uint32_t color){
    for (uint32_t i = 0; i < (HSIZE * VSIZE); i++){
        lcd_current_working_buffer[i] = color;
    }
}

void lcd_swap_buffer(void){
    if (lcd_current_working_buffer == (uint32_t *)g_framebuffer[0]){
        lcd_set_working_buffer(2);
        lcd_set_display_buffer(2);
    }
    else{
        lcd_set_working_buffer(1);
        lcd_set_display_buffer(1);
    }
}

void screen_display(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint32_t color)
{
    /*Declare local variables */
    uint16_t start_x, start_y, display_length, display_height;
    uint32_t start_addr;

    /* Assign co-ordinate values and calculate start address */
    start_x = x1;
    start_y = y1;
    start_addr = (uint32_t)((start_x * BYTES_PER_PIXEL) + (start_y * 1024* BYTES_PER_PIXEL));

    /* Calculate display box length and height */
    display_length = (uint16_t)((x2 - x1) * BYTES_PER_PIXEL);
    display_height = (y2 - y1);

    /* Display required color band */
    for(uint16_t ver_value = Y1_CO_ORDINATE; ver_value < (display_height - 1); ver_value++)
    {
        for(uint32_t hor_value = start_addr; hor_value < (start_addr + display_length); hor_value += BYTES_PER_PIXEL)
        {
            *(uint32_t *) (g_p_single_buffer + hor_value) = color;
            *(uint32_t *) (g_p_double_buffer + hor_value) = color;
        }
        start_addr = (uint32_t)(start_addr + (1024 * BYTES_PER_PIXEL));
    }
}

#endif


