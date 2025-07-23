/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "ov5640.h"



void setup_scr_camera(lv_ui *ui)
{
    //Write codes camera
    ui->camera = lv_obj_create(NULL);
    lv_obj_set_size(ui->camera, 1024, 600);
    lv_obj_set_scrollbar_mode(ui->camera, LV_SCROLLBAR_MODE_OFF);

    //Write style for camera, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->camera, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->camera, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->camera, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes camera_btn_1
    ui->camera_btn_1 = lv_button_create(ui->camera);
    lv_obj_set_pos(ui->camera_btn_1, 0, 0);
    lv_obj_set_size(ui->camera_btn_1, 130, 50);
    ui->camera_btn_1_label = lv_label_create(ui->camera_btn_1);
    lv_label_set_text(ui->camera_btn_1_label, "返回");
    lv_label_set_long_mode(ui->camera_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->camera_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->camera_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->camera_btn_1_label, LV_PCT(100));

    //Write style for camera_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->camera_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->camera_btn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->camera_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->camera_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->camera_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->camera_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->camera_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->camera_btn_1, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->camera_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->camera_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes camera_btn_2
    ui->camera_btn_2 = lv_button_create(ui->camera);
    lv_obj_set_pos(ui->camera_btn_2, 870, 253);
    lv_obj_set_size(ui->camera_btn_2, 100, 100);
    ui->camera_btn_2_label = lv_label_create(ui->camera_btn_2);
    lv_label_set_text(ui->camera_btn_2_label, "");
    lv_label_set_long_mode(ui->camera_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->camera_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->camera_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->camera_btn_2_label, LV_PCT(100));

    //Write style for camera_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->camera_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->camera_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->camera_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->camera_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->camera_btn_2, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->camera_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->camera_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    //lv_obj_set_style_text_font(ui->camera_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->camera_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->camera_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of camera.
    ui->canvas_cam = lv_canvas_create(ui->camera);
    lv_canvas_set_buffer(ui->canvas_cam, g_image_vga_sram, 320, 240, LV_COLOR_FORMAT_RGB565);
    lv_canvas_fill_bg(ui->canvas_cam, lv_color_hex(0xffffffff), 255);
    lv_obj_set_pos(ui->canvas_cam, 352, 180);
    lv_obj_set_size(ui->canvas_cam, 320, 240);
    lv_obj_set_scrollbar_mode(ui->canvas_cam, LV_SCROLLBAR_MODE_OFF);

    //Update current screen layout.
    lv_obj_update_layout(ui->camera);

    //Init events for screen.
    events_init_camera(ui);
}
