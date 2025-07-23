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



void setup_scr_recipe_main(lv_ui *ui)
{
    //Write codes recipe_main
    ui->recipe_main = lv_obj_create(NULL);
    lv_obj_set_size(ui->recipe_main, 1024, 600);
    lv_obj_set_scrollbar_mode(ui->recipe_main, LV_SCROLLBAR_MODE_OFF);

    //Write style for recipe_main, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_main, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_main, lv_color_hex(0xffaf3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_main, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_main_btn_1
    ui->recipe_main_btn_1 = lv_button_create(ui->recipe_main);
    lv_obj_set_pos(ui->recipe_main_btn_1, 0, 0);
    lv_obj_set_size(ui->recipe_main_btn_1, 130, 50);
    ui->recipe_main_btn_1_label = lv_label_create(ui->recipe_main_btn_1);
    lv_label_set_text(ui->recipe_main_btn_1_label, "返回");
    lv_label_set_long_mode(ui->recipe_main_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->recipe_main_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->recipe_main_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->recipe_main_btn_1_label, LV_PCT(100));

    //Write style for recipe_main_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_main_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_main_btn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_main_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_main_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_main_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_main_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_main_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_main_btn_1, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_main_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_main_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_main_btn_3
    ui->recipe_main_btn_3 = lv_button_create(ui->recipe_main);
    lv_obj_set_pos(ui->recipe_main_btn_3, 212, 220);
    lv_obj_set_size(ui->recipe_main_btn_3, 235, 130);
    ui->recipe_main_btn_3_label = lv_label_create(ui->recipe_main_btn_3);
    lv_label_set_text(ui->recipe_main_btn_3_label, "所有菜谱");
    lv_label_set_long_mode(ui->recipe_main_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->recipe_main_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->recipe_main_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->recipe_main_btn_3_label, LV_PCT(100));

    //Write style for recipe_main_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_main_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_main_btn_3, lv_color_hex(0xacc3d6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_main_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_main_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_main_btn_3, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_main_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_main_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_main_btn_3, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_main_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_main_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_main_btn_4
    ui->recipe_main_btn_4 = lv_button_create(ui->recipe_main);
    lv_obj_set_pos(ui->recipe_main_btn_4, 545, 220);
    lv_obj_set_size(ui->recipe_main_btn_4, 235, 130);
    ui->recipe_main_btn_4_label = lv_label_create(ui->recipe_main_btn_4);
    lv_label_set_text(ui->recipe_main_btn_4_label, "随机推荐");
    lv_label_set_long_mode(ui->recipe_main_btn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->recipe_main_btn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->recipe_main_btn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->recipe_main_btn_4_label, LV_PCT(100));

    //Write style for recipe_main_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_main_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_main_btn_4, lv_color_hex(0xa6d8ca), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_main_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_main_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_main_btn_4, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_main_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_main_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_main_btn_4, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_main_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_main_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_main_ta_1
    ui->recipe_main_ta_1 = lv_textarea_create(ui->recipe_main);
    lv_obj_set_pos(ui->recipe_main_ta_1, 187, 107);
    lv_obj_set_size(ui->recipe_main_ta_1, 580, 40);
    lv_textarea_set_text(ui->recipe_main_ta_1, "宫保鸡丁");
    lv_textarea_set_placeholder_text(ui->recipe_main_ta_1, "宫保鸡丁");
    lv_textarea_set_password_bullet(ui->recipe_main_ta_1, "*");
    lv_textarea_set_password_mode(ui->recipe_main_ta_1, false);
    lv_textarea_set_one_line(ui->recipe_main_ta_1, true);
    lv_textarea_set_accepted_chars(ui->recipe_main_ta_1, "");
    lv_textarea_set_max_length(ui->recipe_main_ta_1, 40);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->recipe_main_ta_1, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for recipe_main_ta_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->recipe_main_ta_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_main_ta_1, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_main_ta_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recipe_main_ta_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_main_ta_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recipe_main_ta_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_main_ta_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_main_ta_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_main_ta_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->recipe_main_ta_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->recipe_main_ta_1, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->recipe_main_ta_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_main_ta_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recipe_main_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recipe_main_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recipe_main_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_main_ta_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for recipe_main_ta_1, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_main_ta_1, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_main_ta_1, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_main_ta_1, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_main_ta_1, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes recipe_main_btn_2
    ui->recipe_main_btn_2 = lv_button_create(ui->recipe_main);
    lv_obj_set_pos(ui->recipe_main_btn_2, 769, 107);
    lv_obj_set_size(ui->recipe_main_btn_2, 70, 40);
    ui->recipe_main_btn_6_label = lv_label_create(ui->recipe_main_btn_2);
    lv_label_set_text(ui->recipe_main_btn_6_label, "搜索");
    lv_label_set_long_mode(ui->recipe_main_btn_6_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->recipe_main_btn_6_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->recipe_main_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->recipe_main_btn_6_label, LV_PCT(100));

    //Write style for recipe_main_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_main_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_main_btn_2, lv_color_hex(0xafafaf), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_main_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_main_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_main_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_main_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_main_btn_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_main_btn_2, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_main_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_main_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_main_btn_5
    ui->recipe_main_btn_5 = lv_button_create(ui->recipe_main);
    lv_obj_set_pos(ui->recipe_main_btn_5, 212, 400);
    lv_obj_set_size(ui->recipe_main_btn_5, 235, 130);
    ui->recipe_main_btn_5_label = lv_label_create(ui->recipe_main_btn_5);
    lv_label_set_text(ui->recipe_main_btn_5_label, "AI推荐");
    lv_label_set_long_mode(ui->recipe_main_btn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->recipe_main_btn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->recipe_main_btn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->recipe_main_btn_5_label, LV_PCT(100));

    //Write style for recipe_main_btn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_main_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_main_btn_5, lv_color_hex(0xa6d8ca), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_main_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_main_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_main_btn_5, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_main_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_main_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_main_btn_5, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_main_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_main_btn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_main_btn_6
    ui->recipe_main_btn_6 = lv_button_create(ui->recipe_main);
    lv_obj_set_pos(ui->recipe_main_btn_6, 545, 400);
    lv_obj_set_size(ui->recipe_main_btn_6, 235, 130);
    ui->recipe_main_btn_6_label = lv_label_create(ui->recipe_main_btn_6);
    lv_label_set_text(ui->recipe_main_btn_6_label, "饮食计划");
    lv_label_set_long_mode(ui->recipe_main_btn_6_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->recipe_main_btn_6_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->recipe_main_btn_6, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->recipe_main_btn_6_label, LV_PCT(100));

    //Write style for recipe_main_btn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_main_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_main_btn_6, lv_color_hex(0xacc3d6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_main_btn_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_main_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_main_btn_6, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_main_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_main_btn_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_main_btn_6, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_main_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_main_btn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of recipe_main.

    //Update current screen layout.
    lv_obj_update_layout(ui->recipe_main);

    //Init events for screen.
    events_init_recipe_main(ui);
}
