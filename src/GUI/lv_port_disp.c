/**
 * @file lv_port_disp_templ.c
 *
 */

/*Copy this file as "lv_port_disp.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_disp.h"
#include "hal_data.h"
#include <stdbool.h>
#include <stdio.h>
#include "LCD.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "common_data.h"

/*********************
 *      DEFINES
 *********************/
#define MY_DISP_HOR_RES    1024
#define MY_DISP_VER_RES    600

#define BYTE_PER_PIXEL (LV_COLOR_FORMAT_GET_SIZE(LV_COLOR_FORMAT_ARGB8888)) /*will be 2 for RGB565 */

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void disp_init(void);
static void disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map);
static void vsync_wait_cb(lv_display_t * display);
/**********************
 *  STATIC VARIABLES
 **********************/
//static lv_color32_t buf_1[MY_DISP_HOR_RES * MY_DISP_VER_RES] BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".sdram");
//static lv_color32_t buf_2[MY_DISP_HOR_RES * MY_DISP_VER_RES] BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".sdram");
/**********************
 *      MACROS
 **********************/
static lv_display_t * disp_drv;
bool flag=1;
/**********************
 *   GLOBAL FUNCTIONS
 **********************/


void lv_port_disp_init(void)
{
    /*-------------------------
     * Initialize your display
     * -----------------------*/
    disp_init();

    /*------------------------------------
     * Create a display and set a flush_cb
     * -----------------------------------*/
    disp_drv = lv_display_create(MY_DISP_HOR_RES, MY_DISP_VER_RES);
    if(disp_drv==NULL)printf("error here\n");
    lv_display_set_flush_cb(disp_drv, disp_flush);
    lv_display_set_flush_wait_cb(disp_drv, vsync_wait_cb);
    lv_display_set_buffers(disp_drv, (uint32_t*)&g_framebuffer[0][0], (uint32_t*)&g_framebuffer[1][0], sizeof(g_framebuffer[0]), LV_DISPLAY_RENDER_MODE_DIRECT);
    //lv_display_set_buffers(disp_drv, NULL, (uint32_t*)&g_framebuffer[1][0], sizeof(g_framebuffer[1]), LV_DISPLAY_RENDER_MODE_PARTIAL);

}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*Initialize your display and the required peripherals.*/
static void disp_init(void)
{
    /*You code here*/
    R_GLCDC_BufferChange(&g_display_ctrl, (uint8_t*)g_framebuffer[0], 0);
}

volatile bool disp_flush_enabled = true;

/* Enable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_enable_update(void)
{
    disp_flush_enabled = true;
}

/* Disable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_disable_update(void)
{
    disp_flush_enabled = false;
}

void __attribute__((optimize("O0"))) glcdc_vsync_callback(display_callback_args_t *p_args)
{
    if (p_args->event == DISPLAY_EVENT_LINE_DETECTION) {
//        BaseType_t context_switch = pdFALSE;
//        xSemaphoreGiveFromISR(_SemaphoreVsync, &context_switch);
//        portYIELD_FROM_ISR(context_switch);
        flag=1;
    }

}


static void vsync_wait_cb(lv_display_t * display)
{
    if(!lv_display_flush_is_last(display)) return;
    while(!flag){vTaskDelay(1);}
    //xSemaphoreTake(_SemaphoreVsync, portMAX_DELAY);
}

/*Flush the content of the internal buffer the specific area on the display.
 *`px_map` contains the rendered image as raw pixel map and it should be copied to `area` on the display.
 *You can use DMA or any hardware acceleration to do this operation in the background but
 *'lv_display_flush_ready()' has to be called when it's finished.*/
static void disp_flush(lv_display_t * disp_drv, const lv_area_t * area, uint8_t * px_map)
{
    FSP_PARAMETER_NOT_USED(area);
    if(!lv_display_flush_is_last(disp_drv)) return;
    flag=0;
    R_GLCDC_BufferChange(&g_display_ctrl, (uint8_t *) px_map, (display_frame_layer_t) 0);
    lv_display_flush_ready(disp_drv);
}

#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
