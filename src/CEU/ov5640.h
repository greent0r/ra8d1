/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#ifndef __OV5640_H
#define __OV5640_H

#include "hal_data.h"
#include "platform.h"
#include "camera_i2c_api.h"
#include "ceu.h"
#include "hal_data.h"



/* ���Ŷ��� */
#define OV5640_RST_GPIO_PORT                GPIOA
#define OV5640_RST_GPIO_PIN                 GPIO_PIN_15
#define OV5640_RST_GPIO_CLK_ENABLE()        do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)


/* OV5640 SCCBͨѶ��ַ */
#define OV5640_SCCB_ADDR                    0x3C

/* OV5640ģ��ISP���봰�����ߴ� */
#define OV5640_ISP_INPUT_WIDTH_MAX          0x0A3F
#define OV5640_ISP_INPUT_HEIGHT_MAX         0x06A9

/* OV5640ģ��ƹ�ģʽö��? */
typedef enum
{
    OV5640_LIGHT_MODE_ADVANCED_AWB = 0x00,  /* Advanced AWB */
    OV5640_LIGHT_MODE_SIMPLE_AWB,           /* Simple AWB */
    OV5640_LIGHT_MODE_MANUAL_DAY,           /* Manual day */
    OV5640_LIGHT_MODE_MANUAL_A,             /* Manual A */
    OV5640_LIGHT_MODE_MANUAL_CWF,           /* Manual cwf */
    OV5640_LIGHT_MODE_MANUAL_CLOUDY         /* Manual cloudy */
} ov5640_light_mode_t;

/* OV5640ģ��ɫ�ʱ��Ͷ�ö�� */
typedef enum
{
    OV5640_COLOR_SATURATION_0 = 0x00,       /* +4 */
    OV5640_COLOR_SATURATION_1,              /* +3 */
    OV5640_COLOR_SATURATION_2,              /* +2 */
    OV5640_COLOR_SATURATION_3,              /* +1 */
    OV5640_COLOR_SATURATION_4,              /* 0 */
    OV5640_COLOR_SATURATION_5,              /* -1 */
    OV5640_COLOR_SATURATION_6,              /* -2 */
    OV5640_COLOR_SATURATION_7,              /* -3 */
    OV5640_COLOR_SATURATION_8,              /* -4 */
} ov5640_color_saturation_t;

/* OV5640ģ������ö�� */
typedef enum
{
    OV5640_BRIGHTNESS_0 = 0x00,             /* +4 */
    OV5640_BRIGHTNESS_1,                    /* +3 */
    OV5640_BRIGHTNESS_2,                    /* +2 */
    OV5640_BRIGHTNESS_3,                    /* +1 */
    OV5640_BRIGHTNESS_4,                    /* 0 */
    OV5640_BRIGHTNESS_5,                    /* -1 */
    OV5640_BRIGHTNESS_6,                    /* -2 */
    OV5640_BRIGHTNESS_7,                    /* -3 */
    OV5640_BRIGHTNESS_8,                    /* -4 */
} ov5640_brightness_t;

/* OV5640ģ��Աȶ�ö��? */
typedef enum
{
    OV5640_CONTRAST_0 = 0x00,               /* +4 */
    OV5640_CONTRAST_1,                      /* +3 */
    OV5640_CONTRAST_2,                      /* +2 */
    OV5640_CONTRAST_3,                      /* +1 */
    OV5640_CONTRAST_4,                      /* 0 */
    OV5640_CONTRAST_5,                      /* -1 */
    OV5640_CONTRAST_6,                      /* -2 */
    OV5640_CONTRAST_7,                      /* -3 */
    OV5640_CONTRAST_8,                      /* -4 */
} ov5640_contrast_t;

/* OV5640ģ��ɫ��ö�� */
typedef enum
{
    OV5640_HUE_0 = 0x00,                    /* -180 degree */
    OV5640_HUE_1,                           /* -150 degree */
    OV5640_HUE_2,                           /* -120 degree */
    OV5640_HUE_3,                           /* -90 degree */
    OV5640_HUE_4,                           /* -60 degree */
    OV5640_HUE_5,                           /* -30 degree */
    OV5640_HUE_6,                           /* 0 degree */
    OV5640_HUE_7,                           /* +30 degree */
    OV5640_HUE_8,                           /* +60 degree */
    OV5640_HUE_9,                           /* +90 degree */
    OV5640_HUE_10,                          /* +120 degree */
    OV5640_HUE_11,                          /* +150 degree */
} ov5640_hue_t;

/* OV5640ģ������Ч��ö�� */
typedef enum
{
	OV5640_SPECIAL_EFFECT_NORMAL = 0x00,    /* Normal */
    OV5640_SPECIAL_EFFECT_BW,               /* B&W */
    OV5640_SPECIAL_EFFECT_BLUISH,           /* Bluish */
    OV5640_SPECIAL_EFFECT_SEPIA,            /* Sepia */
    OV5640_SPECIAL_EFFECT_REDDISH,          /* Reddish */
    OV5640_SPECIAL_EFFECT_GREENISH,         /* Greenish */
    OV5640_SPECIAL_EFFECT_NEGATIVE,         /* Negative */
} ov5640_special_effect_t;

/* OV5640ģ���ع��ö��? */
typedef enum
{
    OV5640_EXPOSURE_LEVEL_0 = 0x00,         /* -1.7EV */
    OV5640_EXPOSURE_LEVEL_1,                /* -1.3EV */
    OV5640_EXPOSURE_LEVEL_2,                /* -1.0EV */
    OV5640_EXPOSURE_LEVEL_3,                /* -0.7EV */
    OV5640_EXPOSURE_LEVEL_4,                /* -0.3EV */
    OV5640_EXPOSURE_LEVEL_5,                /* default */
    OV5640_EXPOSURE_LEVEL_6,                /* 0.3EV */
    OV5640_EXPOSURE_LEVEL_7,                /* 0.7EV */
    OV5640_EXPOSURE_LEVEL_8,                /* 1.0EV */
    OV5640_EXPOSURE_LEVEL_9,                /* 1.3EV */
    OV5640_EXPOSURE_LEVEL_10,               /* 1.7EV */
} ov5640_exposure_level_t;

/* OV5640ģ�����ö��? */
typedef enum
{
    OV5640_SHARPNESS_OFF = 0x00,            /* Sharpness OFF */
    OV5640_SHARPNESS_1,                     /* Sharpness 1 */
    OV5640_SHARPNESS_2,                     /* Sharpness 2 */
    OV5640_SHARPNESS_3,                     /* Sharpness 3 */
    OV5640_SHARPNESS_4,                     /* Sharpness 4 */
    OV5640_SHARPNESS_5,                     /* Sharpness 5 */
    OV5640_SHARPNESS_6,                     /* Sharpness 6 */
    OV5640_SHARPNESS_7,                     /* Sharpness 7 */
    OV5640_SHARPNESS_8,                     /* Sharpness 8 */
    OV5640_SHARPNESS_AUTO,                  /* Sharpness Auto */
} ov5640_sharpness_t;

/* OV5640ģ�龵��/��תö�� */
typedef enum
{
    OV5640_MIRROR_FLIP_0 = 0x00,            /* MIRROR */
    OV5640_MIRROR_FLIP_1,                   /* FLIP */
    OV5640_MIRROR_FLIP_2,                   /* MIRROR & FLIP */
    OV5640_MIRROR_FLIP_3,                   /* Normal */
} ov5640_mirror_flip_t;

/* OV5640ģ�����ͼ��ö��? */
typedef enum
{
    OV5640_TEST_PATTERN_OFF = 0x00,         /* OFF */
    OV5640_TEST_PATTERN_COLOR_BAR,          /* Color bar */
    OV5640_TEST_PATTERN_COLOR_SQUARE,       /* Color square */
} ov5640_test_pattern_t;

/* OV5640���ͼ���ʽö�� */
typedef enum
{
    OV5640_OUTPUT_FORMAT_RGB565 = 0x00,     /* RGB565 */
    OV5640_OUTPUT_FORMAT_JPEG,              /* JPEG */
    OV5640_OUTPUT_FORMAT_RGB888 = 0x02     /* RGB888 */
} ov5640_output_format_t;

/* OV5640��ȡ֡���ݷ�ʽö�� */
typedef enum
{
    OV5640_GET_TYPE_DTS_8B_NOINC = 0x00,    /* ͼ���������ֽڷ�ʽд��Ŀ�ĵ�ַ��Ŀ�ĵ�ַ�̶����� */
    OV5640_GET_TYPE_DTS_8B_INC,             /* ͼ���������ֽڷ�ʽд��Ŀ�ĵ�ַ��Ŀ�ĵ�ַ�Զ����� */
    OV5640_GET_TYPE_DTS_16B_NOINC,          /* ͼ�������԰��ַ�ʽд��Ŀ�ĵ�ַ��Ŀ�ĵ�ַ�̶����� */
    OV5640_GET_TYPE_DTS_16B_INC,            /* ͼ�������԰��ַ�ʽд��Ŀ�ĵ�ַ��Ŀ�ĵ�ַ�Զ����� */
    OV5640_GET_TYPE_DTS_32B_NOINC,          /* ͼ���������ַ�ʽд��Ŀ�ĵ�ַ��Ŀ�ĵ�ַ�̶����� */
    OV5640_GET_TYPE_DTS_32B_INC,            /* ͼ���������ַ�ʽд��Ŀ�ĵ�ַ��Ŀ�ĵ�ַ�Զ����� */
} ov5640_get_type_t;


/* ??�?代�?? */
#define OV5640_EOK      0   /* 没�????�? */
#define OV5640_ERROR    1   /* ??�? */
#define OV5640_EINVAL   2   /* ??�????? */
#define OV5640_ENOMEM   3   /* ??�?�?�? */
#define OV5640_EEMPTY   4   /* �?�?为空 */
#define OV5640_ETIMEOUT 5   /* ??�?�??? */


#define OV5640_CAM_PWR_ON                   (BSP_IO_PORT_10_PIN_14)
#define OV5640_CAM_RESET                    (BSP_IO_PORT_10_PIN_15)


extern uint32_t g_out_width;
extern uint32_t g_out_height;

extern uint8_t g_image_vga_sram  [ VGA_WIDTH * VGA_HEIGHT * RGB565_BYTE_PER_PIXEL ] BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".sdram");
extern uint8_t g_image_vga_sram2 [ VGA_WIDTH * VGA_HEIGHT * RGB565_BYTE_PER_PIXEL ] BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".sdram");
extern uint8_t rgb888_data [ VGA_WIDTH * VGA_HEIGHT * 3 ] BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".sdram");
extern uint8_t jpg_data [ VGA_WIDTH * VGA_HEIGHT] BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".sdram");
extern int jpg_len;

#define OV5640_I2C_SLAVE_ADDR 0x78>>1

/* ??�??��?? */
uint8_t ov5640_init(uint16_t cmos_h_pixel, uint16_t cmos_v_pixel, \
        uint16_t total_h_pixel, uint16_t total_v_pixel);                                                /* ??�???OV5640模�?? */
uint8_t ov5640_capture();                                                       /* OV5640?????��?? */


uint8_t ov5640_auto_focus_init(void);                                                                   /* ??�???OV5640模�?????��?��?? */
uint8_t ov5640_auto_focus_once(void);                                                                   /* OV5640模�?????��?��??�?�? */
uint8_t ov5640_auto_focus_continuance(void);                                                            /* OV5640模�????�????��?��?? */
void ov5640_led_on(void);                                                                               /* �???OV5640模�???????? */
void ov5640_led_off(void);                                                                              /* ?��??OV5640模�???????? */
uint8_t ov5640_set_light_mode(ov5640_light_mode_t mode);                                            /* 设置OV5640模�??????模�? */
uint8_t ov5640_set_color_saturation(ov5640_color_saturation_t saturation);                          /* 设置OV5640模�???�彩饱�??�? */
uint8_t ov5640_set_brightness(ov5640_brightness_t brightness);                                      /* 设置OV5640模�??�?�? */
uint8_t ov5640_set_contrast(ov5640_contrast_t contrast);                                            /* 设置OV5640模�??对�??�? */
uint8_t ov5640_set_hue(ov5640_hue_t hue);                                                           /* 设置OV5640模�???��?? */
uint8_t ov5640_set_special_effect(ov5640_special_effect_t effect);                                  /* 设置OV5640模�???��?????? */
uint8_t ov5640_set_exposure_level(ov5640_exposure_level_t level);                                   /* 设置OV5640模�??????�? */
uint8_t ov5640_set_sharpness_level(ov5640_sharpness_t sharpness);                                   /* 设置OV5640模�????�? */
uint8_t ov5640_set_mirror_flip(ov5640_mirror_flip_t mirror_flip);                                   /* 设置OV5640模�??????/翻转 */
uint8_t ov5640_set_test_pattern(ov5640_test_pattern_t pattern);                                     /* 设置OV5640模�??�?�??��? */
uint8_t ov5640_set_output_format(ov5640_output_format_t format);                                    /* 设置OV5640模�??�??��?��???��? */
uint8_t ov5640_set_isp_input_window(uint16_t x, uint16_t y, uint16_t width, uint16_t height);           /* 设置OV5640模�??ISP�??��???�尺�? */
uint8_t ov5640_set_pre_scaling_window(uint16_t x_offset, uint16_t y_offset);                            /* 设置OV5640模�??�?缩�?��???��??�? */
uint8_t ov5640_set_output_size(uint16_t width, uint16_t height);                                        /* 设置OV5640模�??�??��?��??尺�?? */
void OV5640_set_night_mode_VGA();
#endif
