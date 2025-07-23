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
#include "platform.h"


void setup_scr_tool(lv_ui *ui)
{
    //Write codes tool
    ui->tool = lv_obj_create(NULL);
    lv_obj_set_size(ui->tool, 1024, 600);
    lv_obj_set_scrollbar_mode(ui->tool, LV_SCROLLBAR_MODE_OFF);

    //Write style for tool, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->tool, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->tool, lv_color_hex(0x9cc899), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->tool, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tool_btn_1
    ui->tool_btn_1 = lv_button_create(ui->tool);
    lv_obj_set_pos(ui->tool_btn_1, 0, 0);
    lv_obj_set_size(ui->tool_btn_1, 130, 50);
    ui->tool_btn_1_label = lv_label_create(ui->tool_btn_1);
    lv_label_set_text(ui->tool_btn_1_label, "返回");
    lv_label_set_long_mode(ui->tool_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->tool_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->tool_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->tool_btn_1_label, LV_PCT(100));

    //Write style for tool_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->tool_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->tool_btn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->tool_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->tool_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tool_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tool_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->tool_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->tool_btn_1, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->tool_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->tool_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tool_label_1
    ui->tool_label_1 = lv_label_create(ui->tool);
    lv_obj_set_pos(ui->tool_label_1, 192, 70);
    lv_obj_set_size(ui->tool_label_1, 143, 48);
    lv_label_set_text(ui->tool_label_1, "5301");
    lv_label_set_long_mode(ui->tool_label_1, LV_LABEL_LONG_WRAP);

    //Write style for tool_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tool_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tool_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->tool_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->tool_label_1, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->tool_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->tool_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->tool_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->tool_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tool_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tool_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tool_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tool_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tool_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tool_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tool_btn_2
    ui->tool_btn_2 = lv_button_create(ui->tool);
    lv_obj_set_pos(ui->tool_btn_2, 444, 70);
    lv_obj_set_size(ui->tool_btn_2, 161, 48);
    ui->tool_btn_2_label = lv_label_create(ui->tool_btn_2);
    lv_label_set_text(ui->tool_btn_2_label, "归零");
    lv_label_set_long_mode(ui->tool_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->tool_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->tool_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->tool_btn_2_label, LV_PCT(100));

    //Write style for tool_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->tool_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->tool_btn_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->tool_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->tool_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tool_btn_2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tool_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->tool_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->tool_btn_2, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->tool_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->tool_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tool_label_2
    ui->tool_label_2 = lv_label_create(ui->tool);
    lv_obj_set_pos(ui->tool_label_2, 35, 70);
    lv_obj_set_size(ui->tool_label_2, 158, 48);
    lv_label_set_text(ui->tool_label_2, "称重:");
    lv_label_set_long_mode(ui->tool_label_2, LV_LABEL_LONG_WRAP);

    //Write style for tool_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tool_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tool_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->tool_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->tool_label_2, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->tool_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->tool_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->tool_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->tool_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tool_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tool_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tool_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tool_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tool_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tool_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tool_label_4
    ui->tool_label_4 = lv_label_create(ui->tool);
    lv_obj_set_pos(ui->tool_label_4, 203, 140);
    lv_obj_set_size(ui->tool_label_4, 121, 48);
    lv_label_set_text(ui->tool_label_4, "202");
    lv_label_set_long_mode(ui->tool_label_4, LV_LABEL_LONG_WRAP);

    //Write style for tool_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tool_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tool_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->tool_label_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->tool_label_4, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->tool_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->tool_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->tool_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->tool_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tool_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tool_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tool_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tool_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tool_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tool_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tool_label_3
    ui->tool_label_3 = lv_label_create(ui->tool);
    lv_obj_set_pos(ui->tool_label_3, 35, 140);
    lv_obj_set_size(ui->tool_label_3, 158, 48);
    lv_label_set_text(ui->tool_label_3, "测温:");
    lv_label_set_long_mode(ui->tool_label_3, LV_LABEL_LONG_WRAP);

    //Write style for tool_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tool_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tool_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->tool_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->tool_label_3, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->tool_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->tool_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->tool_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->tool_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tool_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tool_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tool_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tool_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tool_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tool_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tool_label_5
    ui->tool_label_5 = lv_label_create(ui->tool);
    lv_obj_set_pos(ui->tool_label_5, 352, 70);
    lv_obj_set_size(ui->tool_label_5, 48, 48);
    lv_label_set_text(ui->tool_label_5, "克");
    lv_label_set_long_mode(ui->tool_label_5, LV_LABEL_LONG_WRAP);

    //Write style for tool_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tool_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tool_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->tool_label_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->tool_label_5, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->tool_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->tool_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->tool_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->tool_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tool_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tool_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tool_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tool_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tool_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tool_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tool_label_6
    ui->tool_label_6 = lv_label_create(ui->tool);
    lv_obj_set_pos(ui->tool_label_6, 352, 140);
    lv_obj_set_size(ui->tool_label_6, 48, 48);
    lv_label_set_text(ui->tool_label_6, "度");
    lv_label_set_long_mode(ui->tool_label_6, LV_LABEL_LONG_WRAP);

    //Write style for tool_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tool_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tool_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->tool_label_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->tool_label_6, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->tool_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->tool_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->tool_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->tool_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tool_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tool_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tool_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tool_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tool_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tool_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tool_label_13
    ui->tool_label_13 = lv_label_create(ui->tool);
    lv_obj_set_pos(ui->tool_label_13, 450, 140);
    lv_obj_set_size(ui->tool_label_13, 48*3, 48);
    lv_label_set_text(ui->tool_label_13, "提醒:");
    lv_label_set_long_mode(ui->tool_label_13, LV_LABEL_LONG_WRAP);

    //Write style for tool_label_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tool_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tool_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->tool_label_13, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->tool_label_13, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->tool_label_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->tool_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->tool_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->tool_label_13, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tool_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tool_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tool_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tool_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tool_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tool_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tool_roller_1
   ui->tool_roller_1 = lv_roller_create(ui->tool);
   lv_obj_set_pos(ui->tool_roller_1, 610, 130);
   lv_obj_set_width(ui->tool_roller_1, 100);
#define MAX_OPTION_COUNT    (300 - 20 + 1)
#define BUF_SIZE            (MAX_OPTION_COUNT * 4)  // 每个数字平均占用4字节（含换行符）
   char opt[BUF_SIZE]={0};
   for (int i = 20; i <= 300; i++) {
       char num_str[10];
       sprintf(num_str, "%d\n", i);
       strcat(opt, num_str);
   }
   lv_roller_set_options(ui->tool_roller_1, opt, LV_ROLLER_MODE_INFINITE);

   //Write style for tool_roller_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
   lv_obj_set_style_radius(ui->tool_roller_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
   lv_obj_set_style_bg_opa(ui->tool_roller_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
   lv_obj_set_style_bg_color(ui->tool_roller_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
   lv_obj_set_style_bg_grad_dir(ui->tool_roller_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
   lv_obj_set_style_text_color(ui->tool_roller_1, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
   lv_obj_set_style_text_font(ui->tool_roller_1, &lv_font_montserrat_14, LV_PART_MAIN|LV_STATE_DEFAULT);
   lv_obj_set_style_text_opa(ui->tool_roller_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
   lv_obj_set_style_text_align(ui->tool_roller_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
   lv_obj_set_style_border_width(ui->tool_roller_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
   lv_obj_set_style_border_opa(ui->tool_roller_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
   lv_obj_set_style_border_color(ui->tool_roller_1, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
   lv_obj_set_style_border_side(ui->tool_roller_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
   lv_obj_set_style_pad_left(ui->tool_roller_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
   lv_obj_set_style_pad_right(ui->tool_roller_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
   lv_obj_set_style_shadow_width(ui->tool_roller_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

   //Write style for tool_roller_1, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
   lv_obj_set_style_bg_opa(ui->tool_roller_1, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
   lv_obj_set_style_bg_color(ui->tool_roller_1, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
   lv_obj_set_style_bg_grad_dir(ui->tool_roller_1, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
   lv_obj_set_style_text_color(ui->tool_roller_1, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
   lv_obj_set_style_text_font(ui->tool_roller_1, &lv_font_montserrat_14, LV_PART_SELECTED|LV_STATE_DEFAULT);
   lv_obj_set_style_text_opa(ui->tool_roller_1, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
   lv_roller_set_visible_row_count(ui->tool_roller_1, 2);

   //Write codes tool_btn_4
  ui->tool_btn_4 = lv_button_create(ui->tool);
  lv_obj_set_pos(ui->tool_btn_4, 730, 140);
  lv_obj_set_size(ui->tool_btn_4, 155, 50);
  ui->tool_btn_4_label = lv_label_create(ui->tool_btn_4);
  lv_label_set_text(ui->tool_btn_4_label, "设置");
  lv_label_set_long_mode(ui->tool_btn_4_label, LV_LABEL_LONG_WRAP);
  lv_obj_align(ui->tool_btn_4_label, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_style_pad_all(ui->tool_btn_4, 0, LV_STATE_DEFAULT);
  lv_obj_set_width(ui->tool_btn_4_label, LV_PCT(100));

  //Write style for tool_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
  lv_obj_set_style_bg_opa(ui->tool_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui->tool_btn_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
  lv_obj_set_style_bg_grad_dir(ui->tool_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui->tool_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
  lv_obj_set_style_radius(ui->tool_btn_4, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_width(ui->tool_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
  lv_obj_set_style_text_color(ui->tool_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui->tool_btn_4, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui->tool_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
  lv_obj_set_style_text_align(ui->tool_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

       //Write codes tool_roller_2
       ui->tool_roller_2 = lv_roller_create(ui->tool);
       lv_obj_set_pos(ui->tool_roller_2, 219, 265);
       lv_obj_set_width(ui->tool_roller_2, 100);
       lv_roller_set_options(ui->tool_roller_2,
               "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24"
               , LV_ROLLER_MODE_INFINITE);

       //Write style for tool_roller_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
       lv_obj_set_style_radius(ui->tool_roller_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_opa(ui->tool_roller_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_color(ui->tool_roller_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_grad_dir(ui->tool_roller_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_color(ui->tool_roller_2, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_font(ui->tool_roller_2, &lv_font_montserrat_14, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_opa(ui->tool_roller_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_align(ui->tool_roller_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_border_width(ui->tool_roller_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_border_opa(ui->tool_roller_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_border_color(ui->tool_roller_2, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_border_side(ui->tool_roller_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_left(ui->tool_roller_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_right(ui->tool_roller_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_shadow_width(ui->tool_roller_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

       //Write style for tool_roller_2, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
       lv_obj_set_style_bg_opa(ui->tool_roller_2, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_color(ui->tool_roller_2, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_grad_dir(ui->tool_roller_2, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
       lv_obj_set_style_text_color(ui->tool_roller_2, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
       lv_obj_set_style_text_font(ui->tool_roller_2, &lv_font_montserrat_14, LV_PART_SELECTED|LV_STATE_DEFAULT);
       lv_obj_set_style_text_opa(ui->tool_roller_2, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

       lv_roller_set_visible_row_count(ui->tool_roller_2, 2);
       //Write codes tool_label_7
       ui->tool_label_7 = lv_label_create(ui->tool);
       lv_obj_set_pos(ui->tool_label_7, 35, 283);
       lv_obj_set_size(ui->tool_label_7, 158, 48);
       lv_label_set_text(ui->tool_label_7, "闹钟:");
       lv_label_set_long_mode(ui->tool_label_7, LV_LABEL_LONG_WRAP);

       //Write style for tool_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
       lv_obj_set_style_border_width(ui->tool_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_radius(ui->tool_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_color(ui->tool_label_7, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_font(ui->tool_label_7, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_opa(ui->tool_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_letter_space(ui->tool_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_line_space(ui->tool_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_align(ui->tool_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_opa(ui->tool_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_top(ui->tool_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_right(ui->tool_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_bottom(ui->tool_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_left(ui->tool_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_shadow_width(ui->tool_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

       //Write codes tool_roller_3
       ui->tool_roller_3 = lv_roller_create(ui->tool);
       lv_obj_set_pos(ui->tool_roller_3, 400, 265);
       lv_obj_set_width(ui->tool_roller_3, 100);
       lv_roller_set_options(ui->tool_roller_3,
               "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59\n60",
               LV_ROLLER_MODE_INFINITE);

       //Write style for tool_roller_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
       lv_obj_set_style_radius(ui->tool_roller_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_opa(ui->tool_roller_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_color(ui->tool_roller_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_grad_dir(ui->tool_roller_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_color(ui->tool_roller_3, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_font(ui->tool_roller_3, &lv_font_montserrat_14, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_opa(ui->tool_roller_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_align(ui->tool_roller_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_border_width(ui->tool_roller_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_border_opa(ui->tool_roller_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_border_color(ui->tool_roller_3, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_border_side(ui->tool_roller_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_left(ui->tool_roller_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_right(ui->tool_roller_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_shadow_width(ui->tool_roller_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

       //Write style for tool_roller_3, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
       lv_obj_set_style_bg_opa(ui->tool_roller_3, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_color(ui->tool_roller_3, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_grad_dir(ui->tool_roller_3, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
       lv_obj_set_style_text_color(ui->tool_roller_3, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
       lv_obj_set_style_text_font(ui->tool_roller_3, &lv_font_montserrat_14, LV_PART_SELECTED|LV_STATE_DEFAULT);
       lv_obj_set_style_text_opa(ui->tool_roller_3, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

       lv_roller_set_visible_row_count(ui->tool_roller_3, 2);
       //Write codes tool_roller_4
       ui->tool_roller_4 = lv_roller_create(ui->tool);
       lv_obj_set_pos(ui->tool_roller_4, 582, 265);
       lv_obj_set_width(ui->tool_roller_4, 100);
       lv_roller_set_options(ui->tool_roller_4,
               "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59\n60"
               , LV_ROLLER_MODE_INFINITE);

       //Write style for tool_roller_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
       lv_obj_set_style_radius(ui->tool_roller_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_opa(ui->tool_roller_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_color(ui->tool_roller_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_grad_dir(ui->tool_roller_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_color(ui->tool_roller_4, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_font(ui->tool_roller_4, &lv_font_montserrat_14, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_opa(ui->tool_roller_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_align(ui->tool_roller_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_border_width(ui->tool_roller_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_border_opa(ui->tool_roller_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_border_color(ui->tool_roller_4, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_border_side(ui->tool_roller_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_left(ui->tool_roller_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_right(ui->tool_roller_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_shadow_width(ui->tool_roller_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

       //Write style for tool_roller_4, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
       lv_obj_set_style_bg_opa(ui->tool_roller_4, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_color(ui->tool_roller_4, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_grad_dir(ui->tool_roller_4, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
       lv_obj_set_style_text_color(ui->tool_roller_4, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
       lv_obj_set_style_text_font(ui->tool_roller_4, &lv_font_montserrat_14, LV_PART_SELECTED|LV_STATE_DEFAULT);
       lv_obj_set_style_text_opa(ui->tool_roller_4, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

       lv_roller_set_visible_row_count(ui->tool_roller_4, 2);
       //Write codes tool_label_8
       ui->tool_label_8 = lv_label_create(ui->tool);
       lv_obj_set_pos(ui->tool_label_8, 205, 350);
       lv_obj_set_size(ui->tool_label_8, 366, 48);
       lv_label_set_text(ui->tool_label_8, "00小时00分00秒");
       lv_label_set_long_mode(ui->tool_label_8, LV_LABEL_LONG_WRAP);

       //Write style for tool_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
       lv_obj_set_style_border_width(ui->tool_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_radius(ui->tool_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_color(ui->tool_label_8, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_font(ui->tool_label_8, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_opa(ui->tool_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_letter_space(ui->tool_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_line_space(ui->tool_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_align(ui->tool_label_8, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_opa(ui->tool_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_top(ui->tool_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_right(ui->tool_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_bottom(ui->tool_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_left(ui->tool_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_shadow_width(ui->tool_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

       //Write codes tool_btn_3
       ui->tool_btn_3 = lv_button_create(ui->tool);
       lv_obj_set_pos(ui->tool_btn_3, 791, 283);
       lv_obj_set_size(ui->tool_btn_3, 155, 50);
       ui->tool_btn_3_label = lv_label_create(ui->tool_btn_3);
       lv_label_set_text(ui->tool_btn_3_label, "设置");
       lv_label_set_long_mode(ui->tool_btn_3_label, LV_LABEL_LONG_WRAP);
       lv_obj_align(ui->tool_btn_3_label, LV_ALIGN_CENTER, 0, 0);
       lv_obj_set_style_pad_all(ui->tool_btn_3, 0, LV_STATE_DEFAULT);
       lv_obj_set_width(ui->tool_btn_3_label, LV_PCT(100));

       //Write style for tool_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
       lv_obj_set_style_bg_opa(ui->tool_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_color(ui->tool_btn_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_grad_dir(ui->tool_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_border_width(ui->tool_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_radius(ui->tool_btn_3, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_shadow_width(ui->tool_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_color(ui->tool_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_font(ui->tool_btn_3, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_opa(ui->tool_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_align(ui->tool_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

       //Write codes tool_label_9
       ui->tool_label_9 = lv_label_create(ui->tool);
       lv_obj_set_pos(ui->tool_label_9, 35, 350);
       lv_obj_set_size(ui->tool_label_9, 158, 48);
       lv_label_set_text(ui->tool_label_9, "剩余:");
       lv_label_set_long_mode(ui->tool_label_9, LV_LABEL_LONG_WRAP);

       //Write style for tool_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
       lv_obj_set_style_border_width(ui->tool_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_radius(ui->tool_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_color(ui->tool_label_9, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_font(ui->tool_label_9, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_opa(ui->tool_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_letter_space(ui->tool_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_line_space(ui->tool_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_align(ui->tool_label_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_opa(ui->tool_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_top(ui->tool_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_right(ui->tool_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_bottom(ui->tool_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_left(ui->tool_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_shadow_width(ui->tool_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

       //Write codes tool_label_10
       ui->tool_label_10 = lv_label_create(ui->tool);
       lv_obj_set_pos(ui->tool_label_10, 514, 283);
       lv_obj_set_size(ui->tool_label_10, 48, 48);
       lv_label_set_text(ui->tool_label_10, "分");
       lv_label_set_long_mode(ui->tool_label_10, LV_LABEL_LONG_WRAP);

       //Write style for tool_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
       lv_obj_set_style_border_width(ui->tool_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_radius(ui->tool_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_color(ui->tool_label_10, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_font(ui->tool_label_10, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_opa(ui->tool_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_letter_space(ui->tool_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_line_space(ui->tool_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_align(ui->tool_label_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_opa(ui->tool_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_top(ui->tool_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_right(ui->tool_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_bottom(ui->tool_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_left(ui->tool_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_shadow_width(ui->tool_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

       //Write codes tool_label_11
       ui->tool_label_11 = lv_label_create(ui->tool);
       lv_obj_set_pos(ui->tool_label_11, 337, 283);
       lv_obj_set_size(ui->tool_label_11, 48, 48);
       lv_label_set_text(ui->tool_label_11, "时");
       lv_label_set_long_mode(ui->tool_label_11, LV_LABEL_LONG_WRAP);

       //Write style for tool_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
       lv_obj_set_style_border_width(ui->tool_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_radius(ui->tool_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_color(ui->tool_label_11, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_font(ui->tool_label_11, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_opa(ui->tool_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_letter_space(ui->tool_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_line_space(ui->tool_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_align(ui->tool_label_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_opa(ui->tool_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_top(ui->tool_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_right(ui->tool_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_bottom(ui->tool_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_left(ui->tool_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_shadow_width(ui->tool_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

       //Write codes tool_label_12
       ui->tool_label_12 = lv_label_create(ui->tool);
       lv_obj_set_pos(ui->tool_label_12, 706, 283);
       lv_obj_set_size(ui->tool_label_12, 48, 48);
       lv_label_set_text(ui->tool_label_12, "秒");
       lv_label_set_long_mode(ui->tool_label_12, LV_LABEL_LONG_WRAP);

       //Write style for tool_label_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
       lv_obj_set_style_border_width(ui->tool_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_radius(ui->tool_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_color(ui->tool_label_12, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_font(ui->tool_label_12, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_opa(ui->tool_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_letter_space(ui->tool_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_line_space(ui->tool_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_text_align(ui->tool_label_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_bg_opa(ui->tool_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_top(ui->tool_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_right(ui->tool_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_bottom(ui->tool_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_pad_left(ui->tool_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
       lv_obj_set_style_shadow_width(ui->tool_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

       //The custom code of tool.



    //Update current screen layout.
    lv_obj_update_layout(ui->tool);

    //Init events for screen.
    events_init_tool(ui);
    tool_setup_done=1;
}
