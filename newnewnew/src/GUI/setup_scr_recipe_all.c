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
#include "recipe.h"
 #include "custom.h"



void setup_scr_recipe_all(lv_ui *ui)
{
    //Write codes recipe_all
    ui->recipe_all = lv_obj_create(NULL);
    lv_obj_set_size(ui->recipe_all, 1024, 600);
    lv_obj_set_scrollbar_mode(ui->recipe_all, LV_SCROLLBAR_MODE_OFF);

    //Write style for recipe_all, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_all, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_all, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_all, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_all_btn_return
    ui->recipe_all_btn_return = lv_button_create(ui->recipe_all);
    lv_obj_set_pos(ui->recipe_all_btn_return, 0, 0);
    lv_obj_set_size(ui->recipe_all_btn_return, 130, 50);
    ui->recipe_all_btn_return_label = lv_label_create(ui->recipe_all_btn_return);
    lv_label_set_text(ui->recipe_all_btn_return_label, "返回");
    lv_label_set_long_mode(ui->recipe_all_btn_return_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->recipe_all_btn_return_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->recipe_all_btn_return, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->recipe_all_btn_return_label, LV_PCT(100));

    //Write style for recipe_all_btn_return, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_all_btn_return, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_all_btn_return, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_all_btn_return, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_all_btn_return, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_all_btn_return, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_all_btn_return, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_all_btn_return, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_all_btn_return, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_all_btn_return, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_all_btn_return, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_all_label_2
    ui->recipe_all_label_2 = lv_label_create(ui->recipe_all);
    lv_obj_set_pos(ui->recipe_all_label_2, 396, 0);
    lv_obj_set_size(ui->recipe_all_label_2, 232, 50);
    lv_label_set_text(ui->recipe_all_label_2, "菜谱列表\n");
    lv_label_set_long_mode(ui->recipe_all_label_2, LV_LABEL_LONG_WRAP);

    //Write style for recipe_all_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_all_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_all_label_2, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_all_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_all_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_all_recipe_list
    ui->recipe_all_recipe_list = lv_list_create(ui->recipe_all);
    lv_obj_set_pos(ui->recipe_all_recipe_list, 0, 50);
    lv_obj_set_size(ui->recipe_all_recipe_list, 1024, 550);
    lv_obj_set_scrollbar_mode(ui->recipe_all_recipe_list, LV_SCROLLBAR_MODE_OFF);
    /******************************************************************/
    /* 在这里读取SD卡中所有的菜谱，根据菜谱数目决定生成的条目数目 */
    /******************************************************************/
    int count = list_recipe_files(recipe_list,13,0);
    for (int i = 0; i < RECIPE_ITEM_COUNT; ++i) {
        const char *label = (i < count) ? recipe_list[i] : "";  // 有则显示菜谱名，无则空
        *recipe_items[i] = lv_list_add_button(ui->recipe_all_recipe_list, NULL, label);
    }

    //Write style state: LV_STATE_DEFAULT for &style_recipe_all_recipe_list_main_main_default
    static lv_style_t style_recipe_all_recipe_list_main_main_default;
    ui_init_style(&style_recipe_all_recipe_list_main_main_default);

    lv_style_set_pad_top(&style_recipe_all_recipe_list_main_main_default, 5);
    lv_style_set_pad_left(&style_recipe_all_recipe_list_main_main_default, 5);
    lv_style_set_pad_right(&style_recipe_all_recipe_list_main_main_default, 5);
    lv_style_set_pad_bottom(&style_recipe_all_recipe_list_main_main_default, 5);
    lv_style_set_bg_opa(&style_recipe_all_recipe_list_main_main_default, 185);
    lv_style_set_bg_color(&style_recipe_all_recipe_list_main_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_recipe_all_recipe_list_main_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_recipe_all_recipe_list_main_main_default, 3);
    lv_style_set_border_opa(&style_recipe_all_recipe_list_main_main_default, 255);
    lv_style_set_border_color(&style_recipe_all_recipe_list_main_main_default, lv_color_hex(0xffffff));
    lv_style_set_border_side(&style_recipe_all_recipe_list_main_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_recipe_all_recipe_list_main_main_default, 6);
    lv_style_set_shadow_width(&style_recipe_all_recipe_list_main_main_default, 0);
    lv_obj_add_style(ui->recipe_all_recipe_list, &style_recipe_all_recipe_list_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_recipe_all_recipe_list_main_scrollbar_default
    static lv_style_t style_recipe_all_recipe_list_main_scrollbar_default;
    ui_init_style(&style_recipe_all_recipe_list_main_scrollbar_default);

    lv_style_set_radius(&style_recipe_all_recipe_list_main_scrollbar_default, 0);
    lv_style_set_bg_opa(&style_recipe_all_recipe_list_main_scrollbar_default, 255);
    lv_style_set_bg_color(&style_recipe_all_recipe_list_main_scrollbar_default, lv_color_hex(0xff6500));
    lv_style_set_bg_grad_dir(&style_recipe_all_recipe_list_main_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->recipe_all_recipe_list, &style_recipe_all_recipe_list_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_recipe_all_recipe_list_extra_btns_main_default
    static lv_style_t style_recipe_all_recipe_list_extra_btns_main_default;
    ui_init_style(&style_recipe_all_recipe_list_extra_btns_main_default);

    lv_style_set_pad_top(&style_recipe_all_recipe_list_extra_btns_main_default, 5);
    lv_style_set_pad_left(&style_recipe_all_recipe_list_extra_btns_main_default, 5);
    lv_style_set_pad_right(&style_recipe_all_recipe_list_extra_btns_main_default, 5);
    lv_style_set_pad_bottom(&style_recipe_all_recipe_list_extra_btns_main_default, 5);
    lv_style_set_border_width(&style_recipe_all_recipe_list_extra_btns_main_default, 1);
    lv_style_set_border_opa(&style_recipe_all_recipe_list_extra_btns_main_default, 255);
    lv_style_set_border_color(&style_recipe_all_recipe_list_extra_btns_main_default, lv_color_hex(0x000000));
    lv_style_set_border_side(&style_recipe_all_recipe_list_extra_btns_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_text_color(&style_recipe_all_recipe_list_extra_btns_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_recipe_all_recipe_list_extra_btns_main_default, &lv_customer_font_simsun_24);
    lv_style_set_text_opa(&style_recipe_all_recipe_list_extra_btns_main_default, 255);
    lv_style_set_radius(&style_recipe_all_recipe_list_extra_btns_main_default, 6);
    lv_style_set_bg_opa(&style_recipe_all_recipe_list_extra_btns_main_default, 0);
     /******************************************************************/
     /* 在这里读取SD卡中所有的菜谱，根据菜谱数目决定生成的条目数目 */
     /******************************************************************/
    lv_obj_add_style(ui->recipe_all_recipe_list_item12, &style_recipe_all_recipe_list_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->recipe_all_recipe_list_item11, &style_recipe_all_recipe_list_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->recipe_all_recipe_list_item10, &style_recipe_all_recipe_list_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->recipe_all_recipe_list_item9, &style_recipe_all_recipe_list_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->recipe_all_recipe_list_item8, &style_recipe_all_recipe_list_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->recipe_all_recipe_list_item7, &style_recipe_all_recipe_list_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->recipe_all_recipe_list_item6, &style_recipe_all_recipe_list_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->recipe_all_recipe_list_item5, &style_recipe_all_recipe_list_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->recipe_all_recipe_list_item4, &style_recipe_all_recipe_list_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->recipe_all_recipe_list_item3, &style_recipe_all_recipe_list_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->recipe_all_recipe_list_item2, &style_recipe_all_recipe_list_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->recipe_all_recipe_list_item1, &style_recipe_all_recipe_list_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->recipe_all_recipe_list_item0, &style_recipe_all_recipe_list_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_recipe_all_recipe_list_extra_texts_main_default
    static lv_style_t style_recipe_all_recipe_list_extra_texts_main_default;
    ui_init_style(&style_recipe_all_recipe_list_extra_texts_main_default);

    lv_style_set_pad_top(&style_recipe_all_recipe_list_extra_texts_main_default, 5);
    lv_style_set_pad_left(&style_recipe_all_recipe_list_extra_texts_main_default, 5);
    lv_style_set_pad_right(&style_recipe_all_recipe_list_extra_texts_main_default, 5);
    lv_style_set_pad_bottom(&style_recipe_all_recipe_list_extra_texts_main_default, 5);
    lv_style_set_border_width(&style_recipe_all_recipe_list_extra_texts_main_default, 0);
    lv_style_set_text_color(&style_recipe_all_recipe_list_extra_texts_main_default, lv_color_hex(0x000000));
    lv_style_set_text_font(&style_recipe_all_recipe_list_extra_texts_main_default, &lv_customer_font_simsun_24);
    lv_style_set_text_opa(&style_recipe_all_recipe_list_extra_texts_main_default, 255);
    lv_style_set_radius(&style_recipe_all_recipe_list_extra_texts_main_default, 3);
    lv_style_set_transform_width(&style_recipe_all_recipe_list_extra_texts_main_default, 0);
    lv_style_set_bg_opa(&style_recipe_all_recipe_list_extra_texts_main_default, 255);
    lv_style_set_bg_color(&style_recipe_all_recipe_list_extra_texts_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_recipe_all_recipe_list_extra_texts_main_default, LV_GRAD_DIR_NONE);

    //Write codes all_recipe_btn_2
    ui->recipe_all_btn_2 = lv_button_create(ui->recipe_all);
    lv_obj_set_pos(ui->recipe_all_btn_2, 250, 550);
    lv_obj_set_size(ui->recipe_all_btn_2, 150, 50);
    ui->recipe_all_btn_2_label = lv_label_create(ui->recipe_all_btn_2);
    lv_label_set_text(ui->recipe_all_btn_2_label, "上一页");
    lv_label_set_long_mode(ui->recipe_all_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->recipe_all_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->recipe_all_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->recipe_all_btn_2_label, LV_PCT(100));

    //Write style for recipe_all_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_all_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_all_btn_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_all_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_all_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_all_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_all_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_all_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_all_btn_2, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_all_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_all_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_all_btn_3
    ui->recipe_all_btn_3 = lv_button_create(ui->recipe_all);
    lv_obj_set_pos(ui->recipe_all_btn_3, 639, 550);
    lv_obj_set_size(ui->recipe_all_btn_3, 150, 50);
    ui->recipe_all_btn_3_label = lv_label_create(ui->recipe_all_btn_3);
    lv_label_set_text(ui->recipe_all_btn_3_label, "下一页");
    lv_label_set_long_mode(ui->recipe_all_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->recipe_all_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->recipe_all_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->recipe_all_btn_3_label, LV_PCT(100));

    //Write style for recipe_all_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_all_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_all_btn_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_all_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_all_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_all_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_all_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_all_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_all_btn_3, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_all_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_all_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_all_label_2
    ui->recipe_all_label_2 = lv_label_create(ui->recipe_all);
    lv_obj_set_pos(ui->recipe_all_label_2, 462, 550);
    lv_obj_set_size(ui->recipe_all_label_2, 100, 50);
    lv_label_set_text_fmt(ui->recipe_all_label_2, "%d", recipe_page+1);
    lv_label_set_long_mode(ui->recipe_all_label_2, LV_LABEL_LONG_WRAP);

    //Write style for recipe_all_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_all_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_all_label_2, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_all_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_all_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_all_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of recipe_all.


    //Update current screen layout.
    lv_obj_update_layout(ui->recipe_all);

    //Init events for screen.
    events_init_recipe_all(ui);
}
