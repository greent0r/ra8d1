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


void setup_scr_recipe_plan(lv_ui *ui)
{
    //Write codes recipe_plan
    ui->recipe_plan = lv_obj_create(NULL);
    lv_obj_set_size(ui->recipe_plan, 1024, 600);
    lv_obj_set_scrollbar_mode(ui->recipe_plan, LV_SCROLLBAR_MODE_OFF);

    //Write style for recipe_plan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_plan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_plan, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_plan, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_plan_btn_1
    ui->recipe_plan_btn_1 = lv_button_create(ui->recipe_plan);
    lv_obj_set_pos(ui->recipe_plan_btn_1, 0, 0);
    lv_obj_set_size(ui->recipe_plan_btn_1, 130, 50);
    ui->recipe_plan_btn_1_label = lv_label_create(ui->recipe_plan_btn_1);
    lv_label_set_text(ui->recipe_plan_btn_1_label, "返回");
    lv_label_set_long_mode(ui->recipe_plan_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->recipe_plan_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->recipe_plan_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->recipe_plan_btn_1_label, LV_PCT(100));

    //Write style for recipe_plan_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_plan_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_plan_btn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_plan_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_plan_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_plan_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_plan_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_plan_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_plan_btn_1, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_plan_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_plan_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_plan_table_1
    ui->recipe_plan_table_1 = lv_table_create(ui->recipe_plan);
    lv_obj_set_pos(ui->recipe_plan_table_1, 0, 100);
    lv_obj_set_size(ui->recipe_plan_table_1, 1024, 360);
    lv_obj_set_scrollbar_mode(ui->recipe_plan_table_1, LV_SCROLLBAR_MODE_OFF);
    lv_table_set_column_count(ui->recipe_plan_table_1,4);
    lv_table_set_row_count(ui->recipe_plan_table_1,8);
    lv_table_set_cell_value(ui->recipe_plan_table_1,0,0,"星期/三餐");
    lv_table_set_cell_value(ui->recipe_plan_table_1,1,0,"一");
    lv_table_set_cell_value(ui->recipe_plan_table_1,2,0,"二");
    lv_table_set_cell_value(ui->recipe_plan_table_1,3,0,"三");
    lv_table_set_cell_value(ui->recipe_plan_table_1,4,0,"四");
    lv_table_set_cell_value(ui->recipe_plan_table_1,5,0,"五");
    lv_table_set_cell_value(ui->recipe_plan_table_1,6,0,"六");
    lv_table_set_cell_value(ui->recipe_plan_table_1,7,0,"日");

    lv_table_set_cell_value(ui->recipe_plan_table_1,0,1,"早");
    lv_table_set_cell_value(ui->recipe_plan_table_1,1,1,recipe_plan[0]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,2,1,recipe_plan[1]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,3,1,recipe_plan[2]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,4,1,recipe_plan[3]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,5,1,recipe_plan[4]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,6,1,recipe_plan[5]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,7,1,recipe_plan[6]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,0,2,"午");
    lv_table_set_cell_value(ui->recipe_plan_table_1,1,2,recipe_plan[7]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,2,2,recipe_plan[8]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,3,2,recipe_plan[9]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,4,2,recipe_plan[10]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,5,2,recipe_plan[11]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,6,2,recipe_plan[12]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,7,2,recipe_plan[13]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,0,3,"晚");
    lv_table_set_cell_value(ui->recipe_plan_table_1,1,3,recipe_plan[14]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,2,3,recipe_plan[15]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,3,3,recipe_plan[16]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,4,3,recipe_plan[17]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,5,3,recipe_plan[18]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,6,3,recipe_plan[19]);
    lv_table_set_cell_value(ui->recipe_plan_table_1,7,3,recipe_plan[20]);

    lv_table_set_column_width(ui->recipe_plan_table_1, 0, 160);
    lv_table_set_column_width(ui->recipe_plan_table_1, 1, 288);
    lv_table_set_column_width(ui->recipe_plan_table_1, 2, 288);
    lv_table_set_column_width(ui->recipe_plan_table_1, 3, 288);

    //Write style for recipe_plan_table_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->recipe_plan_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recipe_plan_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recipe_plan_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recipe_plan_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recipe_plan_table_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_plan_table_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_plan_table_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_plan_table_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->recipe_plan_table_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->recipe_plan_table_1, lv_color_hex(0xd5dee6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->recipe_plan_table_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_plan_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_plan_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for recipe_plan_table_1, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->recipe_plan_table_1, lv_color_hex(0x393c41), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_plan_table_1, &lv_customer_font_simsun_24, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_plan_table_1, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_plan_table_1, LV_TEXT_ALIGN_CENTER, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recipe_plan_table_1, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_plan_table_1, 3, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->recipe_plan_table_1, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->recipe_plan_table_1, lv_color_hex(0xd5dee6), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->recipe_plan_table_1, LV_BORDER_SIDE_FULL, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recipe_plan_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recipe_plan_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recipe_plan_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recipe_plan_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);


    //Write codes recipe_plan_sw_1
    ui->recipe_plan_sw_1 = lv_switch_create(ui->recipe_plan);
    lv_obj_set_pos(ui->recipe_plan_sw_1, 924, 0);
    lv_obj_set_size(ui->recipe_plan_sw_1, 100, 50);

    //Write style for recipe_plan_sw_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_plan_sw_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_plan_sw_1, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_plan_sw_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_plan_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_plan_sw_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_plan_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for recipe_plan_sw_1, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->recipe_plan_sw_1, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->recipe_plan_sw_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->recipe_plan_sw_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->recipe_plan_sw_1, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for recipe_plan_sw_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_plan_sw_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_plan_sw_1, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_plan_sw_1, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_plan_sw_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_plan_sw_1, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes recipe_plan_label_1
    ui->recipe_plan_label_1 = lv_label_create(ui->recipe_plan);
    lv_obj_set_pos(ui->recipe_plan_label_1, 864, 12);
    lv_obj_set_size(ui->recipe_plan_label_1, 48, 24);
    lv_label_set_text(ui->recipe_plan_label_1, "设置");
    lv_label_set_long_mode(ui->recipe_plan_label_1, LV_LABEL_LONG_WRAP);

    //Write style for recipe_plan_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recipe_plan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_plan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_plan_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_plan_label_1, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_plan_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recipe_plan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recipe_plan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_plan_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recipe_plan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recipe_plan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recipe_plan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recipe_plan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recipe_plan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_plan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of recipe_plan.


    //Update current screen layout.
    lv_obj_update_layout(ui->recipe_plan);

    //Init events for screen.
    events_init_recipe_plan(ui);
    lv_obj_set_size(ui->recipe_plan_table_1, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
}

