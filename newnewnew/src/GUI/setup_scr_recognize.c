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
#include "custom.h"
#include "ov5640.h"


void setup_scr_recognize(lv_ui *ui)
{
    //Write codes recognize
    ui->recognize = lv_obj_create(NULL);
    lv_obj_set_size(ui->recognize, 1024, 600);
    lv_obj_set_scrollbar_mode(ui->recognize, LV_SCROLLBAR_MODE_OFF);

    //Write style for recognize, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recognize, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recognize, lv_color_hex(0xfbc3c3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recognize, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recognize_btn_1
    ui->recognize_btn_1 = lv_button_create(ui->recognize);
    lv_obj_set_pos(ui->recognize_btn_1, 0, 0);
    lv_obj_set_size(ui->recognize_btn_1, 130, 50);
    ui->recognize_btn_1_label = lv_label_create(ui->recognize_btn_1);
    lv_label_set_text(ui->recognize_btn_1_label, "返回");
    lv_label_set_long_mode(ui->recognize_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->recognize_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->recognize_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->recognize_btn_1_label, LV_PCT(100));

    //Write style for recognize_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recognize_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recognize_btn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recognize_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recognize_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recognize_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recognize_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recognize_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recognize_btn_1, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recognize_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recognize_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recognize_btn_2
    ui->recognize_btn_2 = lv_button_create(ui->recognize);
    lv_obj_set_pos(ui->recognize_btn_2, 650, 90);
    lv_obj_set_size(ui->recognize_btn_2, 235, 160);
    ui->recognize_btn_2_label = lv_label_create(ui->recognize_btn_2);
    lv_label_set_text(ui->recognize_btn_2_label, "识别");
    lv_label_set_long_mode(ui->recognize_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->recognize_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->recognize_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->recognize_btn_2_label, LV_PCT(100));

    //Write style for recognize_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recognize_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recognize_btn_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recognize_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recognize_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recognize_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recognize_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recognize_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recognize_btn_2, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recognize_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recognize_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recognize_label_1
    ui->recognize_label_1 = lv_label_create(ui->recognize);
    lv_obj_set_pos(ui->recognize_label_1, 56, 370);
    lv_obj_set_size(ui->recognize_label_1, 934, 30);
    lv_label_set_text(ui->recognize_label_1, "1.香蕉:置信度0.994");
    lv_label_set_long_mode(ui->recognize_label_1, LV_LABEL_LONG_WRAP);

    //Write style for recognize_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recognize_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recognize_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recognize_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recognize_label_1, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recognize_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recognize_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recognize_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recognize_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recognize_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recognize_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recognize_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recognize_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recognize_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recognize_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recognize_label_2
    ui->recognize_label_2 = lv_label_create(ui->recognize);
    lv_obj_set_pos(ui->recognize_label_2, 56, 400);
    lv_obj_set_size(ui->recognize_label_2, 934, 30);
    lv_label_set_text(ui->recognize_label_2, "2.葡萄:置信度0.003");
    lv_label_set_long_mode(ui->recognize_label_2, LV_LABEL_LONG_WRAP);

    //Write style for recognize_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recognize_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recognize_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recognize_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recognize_label_2, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recognize_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recognize_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recognize_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recognize_label_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recognize_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recognize_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recognize_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recognize_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recognize_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recognize_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recognize_label_3
    ui->recognize_label_3 = lv_label_create(ui->recognize);
    lv_obj_set_pos(ui->recognize_label_3, 56, 430);
    lv_obj_set_size(ui->recognize_label_3, 934, 30);
    lv_label_set_text(ui->recognize_label_3, "3.火龙果:置信度0.001");
    lv_label_set_long_mode(ui->recognize_label_3, LV_LABEL_LONG_WRAP);

    //Write style for recognize_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recognize_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recognize_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recognize_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recognize_label_3, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recognize_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recognize_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recognize_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recognize_label_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recognize_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recognize_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recognize_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recognize_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recognize_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recognize_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recognize_label_4
    ui->recognize_label_4 = lv_label_create(ui->recognize);
    lv_obj_set_pos(ui->recognize_label_4, 56, 460);
    lv_obj_set_size(ui->recognize_label_4, 934, 30);
    lv_label_set_text(ui->recognize_label_4, "4.苹果:置信度0.001");
    lv_label_set_long_mode(ui->recognize_label_4, LV_LABEL_LONG_WRAP);

    //Write style for recognize_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recognize_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recognize_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recognize_label_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recognize_label_4, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recognize_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recognize_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recognize_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recognize_label_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recognize_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recognize_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recognize_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recognize_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recognize_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recognize_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recognize_label_5
    ui->recognize_label_5 = lv_label_create(ui->recognize);
    lv_obj_set_pos(ui->recognize_label_5, 56, 490);
    lv_obj_set_size(ui->recognize_label_5, 934, 30);
    lv_label_set_text(ui->recognize_label_5, "5.橘子:置信度0.001");
    lv_label_set_long_mode(ui->recognize_label_5, LV_LABEL_LONG_WRAP);

    //Write style for recognize_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recognize_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recognize_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recognize_label_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recognize_label_5, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recognize_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recognize_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recognize_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recognize_label_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recognize_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recognize_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recognize_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recognize_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recognize_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recognize_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recognize_label_6
    ui->recognize_label_6 = lv_label_create(ui->recognize);
    lv_obj_set_pos(ui->recognize_label_6, 56, 520);
    lv_obj_set_size(ui->recognize_label_6, 934, 30);
    lv_label_set_text(ui->recognize_label_6, "6.红烧狮子头:置信度0.001");
    lv_label_set_long_mode(ui->recognize_label_6, LV_LABEL_LONG_WRAP);

    //Write style for recognize_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recognize_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recognize_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recognize_label_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recognize_label_6, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recognize_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recognize_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recognize_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recognize_label_6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recognize_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recognize_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recognize_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recognize_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recognize_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recognize_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);


    //Write codes recognize_label_0
    ui->recognize_label_0 = lv_label_create(ui->recognize);
    lv_obj_set_pos(ui->recognize_label_0, 40, 315);
    lv_obj_set_size(ui->recognize_label_0, 244, 51);
    lv_label_set_text(ui->recognize_label_0, "识别结果:");
    lv_label_set_long_mode(ui->recognize_label_0, LV_LABEL_LONG_WRAP);

    //Write style for recognize_label_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recognize_label_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recognize_label_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recognize_label_0, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recognize_label_0, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recognize_label_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recognize_label_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recognize_label_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recognize_label_0, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recognize_label_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recognize_label_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recognize_label_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recognize_label_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recognize_label_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recognize_label_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of recognize.
    //The custom code of camera.
    ui->canvas_cam = lv_canvas_create(ui->recognize);
    lv_canvas_set_buffer(ui->canvas_cam, g_image_vga_sram2, 320, 240, LV_COLOR_FORMAT_RGB565);
    lv_canvas_fill_bg(ui->canvas_cam, lv_color_hex(0xffffffff), 255);
    lv_obj_set_pos(ui->canvas_cam, 200, 65);
    lv_obj_set_size(ui->canvas_cam, 320, 240);
    lv_obj_set_scrollbar_mode(ui->canvas_cam, LV_SCROLLBAR_MODE_OFF);

    char buff[100];
    sprintf(buff,"1.%s:置信度%1.4f",result[0].name,result[0].score);
    lv_label_set_text(gui.recognize_label_1, buff);
    sprintf(buff,"2.%s:置信度%1.4f",result[1].name,result[1].score);
    lv_label_set_text(gui.recognize_label_2, buff);
    sprintf(buff,"3.%s:置信度%1.4f",result[2].name,result[2].score);
    lv_label_set_text(gui.recognize_label_3, buff);
    sprintf(buff,"4.%s:置信度%1.4f",result[3].name,result[3].score);
    lv_label_set_text(gui.recognize_label_4, buff);
    sprintf(buff,"5.%s:置信度%1.4f",result[4].name,result[4].score);
    lv_label_set_text(gui.recognize_label_5, buff);
    sprintf(buff,"6.%s:置信度%1.4f",result[5].name,result[5].score);
    lv_label_set_text(gui.recognize_label_6, buff);


    //Update current screen layout.
    lv_obj_update_layout(ui->recognize);

    //Init events for screen.
    events_init_recognize(ui);
}
