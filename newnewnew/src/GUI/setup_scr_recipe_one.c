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
#include "recipe.h"


void setup_scr_recipe_one(lv_ui *ui)
{
    //Write codes recipe_one
    ui->recipe_one = lv_obj_create(NULL);
    lv_obj_set_size(ui->recipe_one, 1024, 600);
    lv_obj_set_scrollbar_mode(ui->recipe_one, LV_SCROLLBAR_MODE_OFF);

    //Write style for recipe_one, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_one, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_one, lv_color_hex(0xffaf3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_one, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_one_recipe_description
    ui->recipe_one_recipe_description = lv_label_create(ui->recipe_one);
    lv_obj_set_pos(ui->recipe_one_recipe_description, 16, 138);
    lv_obj_set_size(ui->recipe_one_recipe_description, 989, 28);
    lv_label_set_text_fmt(ui->recipe_one_recipe_description, "%s", myrecipe.description);
    lv_label_set_long_mode(ui->recipe_one_recipe_description, LV_LABEL_LONG_WRAP);

    //Write style for recipe_one_recipe_description, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recipe_one_recipe_description, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_one_recipe_description, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_one_recipe_description, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_one_recipe_description, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_one_recipe_description, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recipe_one_recipe_description, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recipe_one_recipe_description, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_one_recipe_description, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recipe_one_recipe_description, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recipe_one_recipe_description, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recipe_one_recipe_description, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recipe_one_recipe_description, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recipe_one_recipe_description, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_one_recipe_description, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_one_recipe_difficulty
    ui->recipe_one_recipe_difficulty = lv_label_create(ui->recipe_one);
    lv_obj_set_pos(ui->recipe_one_recipe_difficulty, 275, 100);
    lv_obj_set_size(ui->recipe_one_recipe_difficulty, 124, 32);
    switch(myrecipe.difficulty){
        case 1:lv_label_set_text(ui->recipe_one_recipe_difficulty, "难度:低");break;
        case 2:lv_label_set_text(ui->recipe_one_recipe_difficulty, "难度:中");break;
        case 3:lv_label_set_text(ui->recipe_one_recipe_difficulty, "难度:高");break;
        default:lv_label_set_text(ui->recipe_one_recipe_difficulty, "难度:中");break;
    }
    lv_label_set_long_mode(ui->recipe_one_recipe_difficulty, LV_LABEL_LONG_WRAP);

    //Write style for recipe_one_recipe_difficulty, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recipe_one_recipe_difficulty, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_one_recipe_difficulty, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_one_recipe_difficulty, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_one_recipe_difficulty, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_one_recipe_difficulty, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recipe_one_recipe_difficulty, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recipe_one_recipe_difficulty, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_one_recipe_difficulty, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recipe_one_recipe_difficulty, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recipe_one_recipe_difficulty, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recipe_one_recipe_difficulty, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recipe_one_recipe_difficulty, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recipe_one_recipe_difficulty, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_one_recipe_difficulty, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_one_recipe_time
    ui->recipe_one_recipe_time = lv_label_create(ui->recipe_one);
    lv_obj_set_pos(ui->recipe_one_recipe_time, 579, 100);
    lv_obj_set_size(ui->recipe_one_recipe_time, 200, 32);
    lv_label_set_text_fmt(ui->recipe_one_recipe_time, "准备时间:%d分钟", myrecipe.prep_time);
    lv_label_set_long_mode(ui->recipe_one_recipe_time, LV_LABEL_LONG_WRAP);

    //Write style for recipe_one_recipe_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recipe_one_recipe_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_one_recipe_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_one_recipe_time, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_one_recipe_time, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_one_recipe_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recipe_one_recipe_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recipe_one_recipe_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_one_recipe_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recipe_one_recipe_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recipe_one_recipe_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recipe_one_recipe_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recipe_one_recipe_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recipe_one_recipe_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_one_recipe_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_one_label_9
    ui->recipe_one_label_9 = lv_label_create(ui->recipe_one);
    lv_obj_set_pos(ui->recipe_one_label_9, 781, 100);
    lv_obj_set_size(ui->recipe_one_label_9, 200, 32);
    lv_label_set_text_fmt(ui->recipe_one_label_9, "制作时间:%d分钟", myrecipe.cook_time);
    lv_label_set_long_mode(ui->recipe_one_label_9, LV_LABEL_LONG_WRAP);

    //Write style for recipe_one_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recipe_one_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_one_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_one_label_9, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_one_label_9, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_one_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recipe_one_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recipe_one_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_one_label_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recipe_one_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recipe_one_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recipe_one_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recipe_one_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recipe_one_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_one_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_one_btn_1
    ui->recipe_one_btn_1 = lv_button_create(ui->recipe_one);
    lv_obj_set_pos(ui->recipe_one_btn_1, 0, 0);
    lv_obj_set_size(ui->recipe_one_btn_1, 130, 50);
    ui->recipe_one_btn_1_label = lv_label_create(ui->recipe_one_btn_1);
    lv_label_set_text(ui->recipe_one_btn_1_label, "返回");
    lv_label_set_long_mode(ui->recipe_one_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->recipe_one_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->recipe_one_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->recipe_one_btn_1_label, LV_PCT(100));

    //Write style for recipe_one_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_one_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_one_btn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_one_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_one_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_one_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_one_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_one_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_one_btn_1, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_one_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_one_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_one_label_6
    ui->recipe_one_label_6 = lv_label_create(ui->recipe_one);
    lv_obj_set_pos(ui->recipe_one_label_6, 551, 180);
    lv_obj_set_size(ui->recipe_one_label_6, 161, 49);
    lv_label_set_text(ui->recipe_one_label_6, "步骤");
    lv_label_set_long_mode(ui->recipe_one_label_6, LV_LABEL_LONG_WRAP);

    //Write style for recipe_one_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recipe_one_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_one_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_one_label_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_one_label_6, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_one_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recipe_one_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recipe_one_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_one_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recipe_one_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recipe_one_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recipe_one_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recipe_one_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recipe_one_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_one_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_one_step_list
    ui->recipe_one_step_list = lv_list_create(ui->recipe_one);
    lv_obj_set_pos(ui->recipe_one_step_list, 242, 237);
    lv_obj_set_size(ui->recipe_one_step_list, 780, 361);
    lv_obj_set_scrollbar_mode(ui->recipe_one_step_list, LV_SCROLLBAR_MODE_OFF);

//    ui->recipe_one_step_list_item0 =lv_list_add_text(ui->recipe_one_step_list, "save");
//    ui->recipe_one_step_list_item1 =lv_list_add_text(ui->recipe_one_step_list, "save_1");
//    ui->recipe_one_step_list_item2 =lv_list_add_text(ui->recipe_one_step_list, "save_2");
//    ui->recipe_one_step_list_item3 =lv_list_add_text(ui->recipe_one_step_list, "save_3");
//    ui->recipe_one_step_list_item4 =lv_list_add_text(ui->recipe_one_step_list, "save_4");
//    ui->recipe_one_step_list_item5 =lv_list_add_text(ui->recipe_one_step_list, "save_5");
//    ui->recipe_one_step_list_item6 =lv_list_add_text(ui->recipe_one_step_list, "save_6");
//    ui->recipe_one_step_list_item7 =lv_list_add_text(ui->recipe_one_step_list, "save_7");
//    ui->recipe_one_step_list_item8 =lv_list_add_text(ui->recipe_one_step_list, "save_8");
//    ui->recipe_one_step_list_item9 =lv_list_add_text(ui->recipe_one_step_list, "save_9");

    //Write style state: LV_STATE_DEFAULT for &style_recipe_one_step_list_main_main_default
    static lv_style_t style_recipe_one_step_list_main_main_default;
    ui_init_style(&style_recipe_one_step_list_main_main_default);

    lv_style_set_pad_top(&style_recipe_one_step_list_main_main_default, 5);
    lv_style_set_pad_left(&style_recipe_one_step_list_main_main_default, 5);
    lv_style_set_pad_right(&style_recipe_one_step_list_main_main_default, 5);
    lv_style_set_pad_bottom(&style_recipe_one_step_list_main_main_default, 5);
    lv_style_set_bg_opa(&style_recipe_one_step_list_main_main_default, 160);
    lv_style_set_bg_color(&style_recipe_one_step_list_main_main_default, lv_color_hex(0xff6500));
    lv_style_set_bg_grad_dir(&style_recipe_one_step_list_main_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_recipe_one_step_list_main_main_default, 1);
    lv_style_set_border_opa(&style_recipe_one_step_list_main_main_default, 255);
    lv_style_set_border_color(&style_recipe_one_step_list_main_main_default, lv_color_hex(0xff6500));
    lv_style_set_border_side(&style_recipe_one_step_list_main_main_default, LV_BORDER_SIDE_NONE);
    lv_style_set_radius(&style_recipe_one_step_list_main_main_default, 3);
    lv_style_set_shadow_width(&style_recipe_one_step_list_main_main_default, 0);
    lv_obj_add_style(ui->recipe_one_step_list, &style_recipe_one_step_list_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_recipe_one_step_list_main_scrollbar_default
    static lv_style_t style_recipe_one_step_list_main_scrollbar_default;
    ui_init_style(&style_recipe_one_step_list_main_scrollbar_default);

    lv_style_set_radius(&style_recipe_one_step_list_main_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_recipe_one_step_list_main_scrollbar_default, 255);
    lv_style_set_bg_color(&style_recipe_one_step_list_main_scrollbar_default, lv_color_hex(0xd6a72a));
    lv_style_set_bg_grad_dir(&style_recipe_one_step_list_main_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->recipe_one_step_list, &style_recipe_one_step_list_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_recipe_one_step_list_extra_btns_main_default
    static lv_style_t style_recipe_one_step_list_extra_btns_main_default;
    ui_init_style(&style_recipe_one_step_list_extra_btns_main_default);

    lv_style_set_pad_top(&style_recipe_one_step_list_extra_btns_main_default, 5);
    lv_style_set_pad_left(&style_recipe_one_step_list_extra_btns_main_default, 5);
    lv_style_set_pad_right(&style_recipe_one_step_list_extra_btns_main_default, 5);
    lv_style_set_pad_bottom(&style_recipe_one_step_list_extra_btns_main_default, 5);
    lv_style_set_border_width(&style_recipe_one_step_list_extra_btns_main_default, 1);
    lv_style_set_border_opa(&style_recipe_one_step_list_extra_btns_main_default, 255);
    lv_style_set_border_color(&style_recipe_one_step_list_extra_btns_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_recipe_one_step_list_extra_btns_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_text_color(&style_recipe_one_step_list_extra_btns_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_recipe_one_step_list_extra_btns_main_default, &lv_customer_font_simsun_24);
    lv_style_set_text_opa(&style_recipe_one_step_list_extra_btns_main_default, 255);
    lv_style_set_radius(&style_recipe_one_step_list_extra_btns_main_default, 0);
    lv_style_set_bg_opa(&style_recipe_one_step_list_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_recipe_one_step_list_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_recipe_one_step_list_extra_btns_main_default, LV_GRAD_DIR_NONE);

    //Write style state: LV_STATE_DEFAULT for &style_recipe_one_step_list_extra_texts_main_default
    static lv_style_t style_recipe_one_step_list_extra_texts_main_default;
    ui_init_style(&style_recipe_one_step_list_extra_texts_main_default);

    lv_style_set_pad_top(&style_recipe_one_step_list_extra_texts_main_default, 5);
    lv_style_set_pad_left(&style_recipe_one_step_list_extra_texts_main_default, 5);
    lv_style_set_pad_right(&style_recipe_one_step_list_extra_texts_main_default, 5);
    lv_style_set_pad_bottom(&style_recipe_one_step_list_extra_texts_main_default, 5);
    lv_style_set_border_width(&style_recipe_one_step_list_extra_texts_main_default, 0);
    lv_style_set_text_color(&style_recipe_one_step_list_extra_texts_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_recipe_one_step_list_extra_texts_main_default, &lv_customer_font_simsun_24);
    lv_style_set_text_opa(&style_recipe_one_step_list_extra_texts_main_default, 255);
    lv_style_set_radius(&style_recipe_one_step_list_extra_texts_main_default, 3);
    lv_style_set_transform_width(&style_recipe_one_step_list_extra_texts_main_default, 0);
    lv_style_set_bg_opa(&style_recipe_one_step_list_extra_texts_main_default, 255);
    lv_style_set_bg_color(&style_recipe_one_step_list_extra_texts_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_recipe_one_step_list_extra_texts_main_default, LV_GRAD_DIR_NONE);


    for (int i = 0; i < myrecipe.step_count; ++i) {
        char step_str[256];
        sprintf(step_str, "%d.%s\n备注:%s",
                myrecipe.steps[i].step_number,
                myrecipe.steps[i].instruction,
                myrecipe.steps[i].note[0] ? myrecipe.steps[i].note : "(无)");
        lv_obj_t *item = lv_list_add_text(ui->recipe_one_step_list, step_str);
        lv_obj_add_style(item, &style_recipe_one_step_list_extra_texts_main_default,LV_PART_MAIN|LV_STATE_DEFAULT);
    }

    //Write codes recipe_one_label_7
    ui->recipe_one_label_7 = lv_label_create(ui->recipe_one);
    lv_obj_set_pos(ui->recipe_one_label_7, 85, 180);
    lv_obj_set_size(ui->recipe_one_label_7, 161, 49);
    lv_label_set_text(ui->recipe_one_label_7, "食材");
    lv_label_set_long_mode(ui->recipe_one_label_7, LV_LABEL_LONG_WRAP);

    //Write style for recipe_one_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recipe_one_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_one_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_one_label_7, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_one_label_7, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_one_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recipe_one_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recipe_one_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_one_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recipe_one_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recipe_one_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recipe_one_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recipe_one_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recipe_one_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_one_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_one_ingredient_list
    ui->recipe_one_ingredient_list = lv_list_create(ui->recipe_one);
    lv_obj_set_pos(ui->recipe_one_ingredient_list, 5, 236);
    lv_obj_set_size(ui->recipe_one_ingredient_list, 233, 361);
    lv_obj_set_scrollbar_mode(ui->recipe_one_ingredient_list, LV_SCROLLBAR_MODE_OFF);


//    ui->recipe_one_ingredient_list_item0 =lv_list_add_text(ui->recipe_one_ingredient_list, "save");
//    ui->recipe_one_ingredient_list_item1 =lv_list_add_text(ui->recipe_one_ingredient_list, "save_1");
//    ui->recipe_one_ingredient_list_item2 =lv_list_add_text(ui->recipe_one_ingredient_list, "save_2");
//    ui->recipe_one_ingredient_list_item3 =lv_list_add_text(ui->recipe_one_ingredient_list, "save_3");
//    ui->recipe_one_ingredient_list_item4 =lv_list_add_text(ui->recipe_one_ingredient_list, "save_4");
//    ui->recipe_one_ingredient_list_item5 =lv_list_add_text(ui->recipe_one_ingredient_list, "save_5");
//    ui->recipe_one_ingredient_list_item6 =lv_list_add_text(ui->recipe_one_ingredient_list, "save_6");
//    ui->recipe_one_ingredient_list_item7 =lv_list_add_text(ui->recipe_one_ingredient_list, "save_7");
//    ui->recipe_one_ingredient_list_item8 =lv_list_add_text(ui->recipe_one_ingredient_list, "save_8");
//    ui->recipe_one_ingredient_list_item9 =lv_list_add_text(ui->recipe_one_ingredient_list, "save_9");

    //Write style state: LV_STATE_DEFAULT for &style_recipe_one_ingredient_list_main_main_default
    static lv_style_t style_recipe_one_ingredient_list_main_main_default;
    ui_init_style(&style_recipe_one_ingredient_list_main_main_default);

    lv_style_set_pad_top(&style_recipe_one_ingredient_list_main_main_default, 5);
    lv_style_set_pad_left(&style_recipe_one_ingredient_list_main_main_default, 5);
    lv_style_set_pad_right(&style_recipe_one_ingredient_list_main_main_default, 5);
    lv_style_set_pad_bottom(&style_recipe_one_ingredient_list_main_main_default, 5);
    lv_style_set_bg_opa(&style_recipe_one_ingredient_list_main_main_default, 160);
    lv_style_set_bg_color(&style_recipe_one_ingredient_list_main_main_default, lv_color_hex(0xff6500));
    lv_style_set_bg_grad_dir(&style_recipe_one_ingredient_list_main_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_recipe_one_ingredient_list_main_main_default, 1);
    lv_style_set_border_opa(&style_recipe_one_ingredient_list_main_main_default, 255);
    lv_style_set_border_color(&style_recipe_one_ingredient_list_main_main_default, lv_color_hex(0xff6500));
    lv_style_set_border_side(&style_recipe_one_ingredient_list_main_main_default, LV_BORDER_SIDE_NONE);
    lv_style_set_radius(&style_recipe_one_ingredient_list_main_main_default, 3);
    lv_style_set_shadow_width(&style_recipe_one_ingredient_list_main_main_default, 0);
    lv_obj_add_style(ui->recipe_one_ingredient_list, &style_recipe_one_ingredient_list_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_recipe_one_ingredient_list_main_scrollbar_default
    static lv_style_t style_recipe_one_ingredient_list_main_scrollbar_default;
    ui_init_style(&style_recipe_one_ingredient_list_main_scrollbar_default);

    lv_style_set_radius(&style_recipe_one_ingredient_list_main_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_recipe_one_ingredient_list_main_scrollbar_default, 255);
    lv_style_set_bg_color(&style_recipe_one_ingredient_list_main_scrollbar_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_recipe_one_ingredient_list_main_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->recipe_one_ingredient_list, &style_recipe_one_ingredient_list_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_recipe_one_ingredient_list_extra_btns_main_default
    static lv_style_t style_recipe_one_ingredient_list_extra_btns_main_default;
    ui_init_style(&style_recipe_one_ingredient_list_extra_btns_main_default);

    lv_style_set_pad_top(&style_recipe_one_ingredient_list_extra_btns_main_default, 5);
    lv_style_set_pad_left(&style_recipe_one_ingredient_list_extra_btns_main_default, 5);
    lv_style_set_pad_right(&style_recipe_one_ingredient_list_extra_btns_main_default, 5);
    lv_style_set_pad_bottom(&style_recipe_one_ingredient_list_extra_btns_main_default, 5);
    lv_style_set_border_width(&style_recipe_one_ingredient_list_extra_btns_main_default, 1);
    lv_style_set_border_opa(&style_recipe_one_ingredient_list_extra_btns_main_default, 255);
    lv_style_set_border_color(&style_recipe_one_ingredient_list_extra_btns_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_recipe_one_ingredient_list_extra_btns_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_text_color(&style_recipe_one_ingredient_list_extra_btns_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_recipe_one_ingredient_list_extra_btns_main_default, &lv_customer_font_simsun_24);
    lv_style_set_text_opa(&style_recipe_one_ingredient_list_extra_btns_main_default, 255);
    lv_style_set_radius(&style_recipe_one_ingredient_list_extra_btns_main_default, 0);
    lv_style_set_bg_opa(&style_recipe_one_ingredient_list_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_recipe_one_ingredient_list_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_recipe_one_ingredient_list_extra_btns_main_default, LV_GRAD_DIR_NONE);

    //Write style state: LV_STATE_DEFAULT for &style_recipe_one_ingredient_list_extra_texts_main_default
    static lv_style_t style_recipe_one_ingredient_list_extra_texts_main_default;
    ui_init_style(&style_recipe_one_ingredient_list_extra_texts_main_default);

    lv_style_set_pad_top(&style_recipe_one_ingredient_list_extra_texts_main_default, 5);
    lv_style_set_pad_left(&style_recipe_one_ingredient_list_extra_texts_main_default, 5);
    lv_style_set_pad_right(&style_recipe_one_ingredient_list_extra_texts_main_default, 5);
    lv_style_set_pad_bottom(&style_recipe_one_ingredient_list_extra_texts_main_default, 5);
    lv_style_set_border_width(&style_recipe_one_ingredient_list_extra_texts_main_default, 0);
    lv_style_set_text_color(&style_recipe_one_ingredient_list_extra_texts_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_recipe_one_ingredient_list_extra_texts_main_default, &lv_customer_font_simsun_24);
    lv_style_set_text_opa(&style_recipe_one_ingredient_list_extra_texts_main_default, 255);
    lv_style_set_radius(&style_recipe_one_ingredient_list_extra_texts_main_default, 3);
    lv_style_set_transform_width(&style_recipe_one_ingredient_list_extra_texts_main_default, 0);
    lv_style_set_bg_opa(&style_recipe_one_ingredient_list_extra_texts_main_default, 255);
    lv_style_set_bg_color(&style_recipe_one_ingredient_list_extra_texts_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_recipe_one_ingredient_list_extra_texts_main_default, LV_GRAD_DIR_NONE);

    for (int i = 0; i < myrecipe.ingredient_count; ++i) {
        char ingredient_str[256];
        sprintf(ingredient_str, "%s:%.0f%s",
                myrecipe.ingredients[i].name,
                myrecipe.ingredients[i].quantity,
                myrecipe.ingredients[i].unit);
        lv_obj_t *item = lv_list_add_text(ui->recipe_one_ingredient_list, ingredient_str);
        lv_obj_add_style(item, &style_recipe_one_ingredient_list_extra_texts_main_default,LV_PART_MAIN|LV_STATE_DEFAULT);
    }

    //Write codes recipe_one_btn_2
    ui->recipe_one_btn_2 = lv_button_create(ui->recipe_one);
    lv_obj_set_pos(ui->recipe_one_btn_2, 450, 50);
    lv_obj_set_size(ui->recipe_one_btn_2, 124, 36);
    ui->recipe_one_btn_2_label = lv_label_create(ui->recipe_one_btn_2);
    lv_label_set_text(ui->recipe_one_btn_2_label, "开始制作");
    lv_label_set_long_mode(ui->recipe_one_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->recipe_one_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->recipe_one_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->recipe_one_btn_2_label, LV_PCT(100));

    //Write style for recipe_one_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_one_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_one_btn_2, lv_color_hex(0x776c57), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_one_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_one_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_one_btn_2, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_one_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_one_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_one_btn_2, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_one_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_one_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_one_recipe_name
    ui->recipe_one_recipe_name = lv_label_create(ui->recipe_one);
    lv_obj_set_pos(ui->recipe_one_recipe_name, 322, 15);
    lv_obj_set_size(ui->recipe_one_recipe_name, 380, 30);
    lv_label_set_text_fmt(ui->recipe_one_recipe_name, "%s", myrecipe.name);
    lv_label_set_long_mode(ui->recipe_one_recipe_name, LV_LABEL_LONG_WRAP);

    //Write style for recipe_one_recipe_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recipe_one_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_one_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_one_recipe_name, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_one_recipe_name, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_one_recipe_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recipe_one_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recipe_one_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_one_recipe_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recipe_one_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recipe_one_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recipe_one_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recipe_one_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recipe_one_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_one_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_one_label_8
    ui->recipe_one_label_8 = lv_label_create(ui->recipe_one);
    lv_obj_set_pos(ui->recipe_one_label_8, 33, 100);
    lv_obj_set_size(ui->recipe_one_label_8, 177, 32);
    lv_label_set_text_fmt(ui->recipe_one_label_8, "品种:%s", myrecipe.category);
    lv_label_set_long_mode(ui->recipe_one_label_8, LV_LABEL_LONG_WRAP);

    //Write style for recipe_one_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recipe_one_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_one_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_one_label_8, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_one_label_8, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_one_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recipe_one_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recipe_one_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_one_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recipe_one_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recipe_one_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recipe_one_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recipe_one_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recipe_one_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_one_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_one_btn_3
    ui->recipe_one_btn_3 = lv_button_create(ui->recipe_one);
    lv_obj_set_pos(ui->recipe_one_btn_3, 894, 0);
    lv_obj_set_size(ui->recipe_one_btn_3, 130, 50);
    ui->recipe_one_btn_3_label = lv_label_create(ui->recipe_one_btn_3);
    lv_label_set_text(ui->recipe_one_btn_3_label, "删除菜谱");
    lv_label_set_long_mode(ui->recipe_one_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->recipe_one_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->recipe_one_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->recipe_one_btn_3_label, LV_PCT(100));

    //Write style for recipe_one_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_one_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_one_btn_3, lv_color_hex(0x39352e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_one_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_one_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_one_btn_3, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_one_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_one_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_one_btn_3, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_one_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_one_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of recipe_one.


    //Update current screen layout.
    lv_obj_update_layout(ui->recipe_one);

    //Init events for screen.
    events_init_recipe_one(ui);
}

