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


void setup_scr_recipe_cook(lv_ui *ui)
{
    //Write codes recipe_cook
    ui->recipe_cook = lv_obj_create(NULL);
    lv_obj_set_size(ui->recipe_cook, 1024, 600);
    lv_obj_set_scrollbar_mode(ui->recipe_cook, LV_SCROLLBAR_MODE_OFF);

    //Write style for recipe_cook, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_cook, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_cook, lv_color_hex(0xffaf3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_cook, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_cook_btn_1
    ui->recipe_cook_btn_1 = lv_button_create(ui->recipe_cook);
    lv_obj_set_pos(ui->recipe_cook_btn_1, 0, 0);
    lv_obj_set_size(ui->recipe_cook_btn_1, 130, 50);
    ui->recipe_cook_btn_1_label = lv_label_create(ui->recipe_cook_btn_1);
    lv_label_set_text(ui->recipe_cook_btn_1_label, "返回");
    lv_label_set_long_mode(ui->recipe_cook_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->recipe_cook_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->recipe_cook_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->recipe_cook_btn_1_label, LV_PCT(100));

    //Write style for recipe_cook_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_cook_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_cook_btn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_cook_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_cook_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_cook_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_cook_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_cook_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_cook_btn_1, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_cook_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_cook_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_cook_recipe_name
    ui->recipe_cook_recipe_name = lv_label_create(ui->recipe_cook);
    lv_obj_set_pos(ui->recipe_cook_recipe_name, 323, 41);
    lv_obj_set_size(ui->recipe_cook_recipe_name, 378, 55);
    lv_label_set_text_fmt(ui->recipe_cook_recipe_name, "%s", myrecipe.name);
    lv_label_set_long_mode(ui->recipe_cook_recipe_name, LV_LABEL_LONG_WRAP);

    //Write style for recipe_cook_recipe_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recipe_cook_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_cook_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_cook_recipe_name, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_cook_recipe_name, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_cook_recipe_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recipe_cook_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recipe_cook_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_cook_recipe_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recipe_cook_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recipe_cook_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recipe_cook_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recipe_cook_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recipe_cook_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_cook_recipe_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_cook_prev_step
    ui->recipe_cook_prev_step = lv_button_create(ui->recipe_cook);
    lv_obj_set_pos(ui->recipe_cook_prev_step, 120, 423);
    lv_obj_set_size(ui->recipe_cook_prev_step, 148, 95);
    ui->recipe_cook_prev_step_label = lv_label_create(ui->recipe_cook_prev_step);
    lv_label_set_text(ui->recipe_cook_prev_step_label, "上一步");
    lv_label_set_long_mode(ui->recipe_cook_prev_step_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->recipe_cook_prev_step_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->recipe_cook_prev_step, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->recipe_cook_prev_step_label, LV_PCT(100));

    //Write style for recipe_cook_prev_step, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_cook_prev_step, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_cook_prev_step, lv_color_hex(0x776c57), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_cook_prev_step, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_cook_prev_step, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_cook_prev_step, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_cook_prev_step, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_cook_prev_step, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_cook_prev_step, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_cook_prev_step, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_cook_prev_step, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_cook_next_step
    ui->recipe_cook_next_step = lv_button_create(ui->recipe_cook);
    lv_obj_set_pos(ui->recipe_cook_next_step, 756, 423);
    lv_obj_set_size(ui->recipe_cook_next_step, 148, 95);
    ui->recipe_cook_next_step_label = lv_label_create(ui->recipe_cook_next_step);
    lv_label_set_text(ui->recipe_cook_next_step_label, "下一步");
    lv_label_set_long_mode(ui->recipe_cook_next_step_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->recipe_cook_next_step_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->recipe_cook_next_step, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->recipe_cook_next_step_label, LV_PCT(100));

    //Write style for recipe_cook_next_step, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recipe_cook_next_step, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recipe_cook_next_step, lv_color_hex(0x776c57), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recipe_cook_next_step, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->recipe_cook_next_step, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_cook_next_step, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_cook_next_step, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_cook_next_step, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_cook_next_step, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_cook_next_step, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_cook_next_step, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_cook_label_1
    ui->recipe_cook_label_1 = lv_label_create(ui->recipe_cook);
    lv_obj_set_pos(ui->recipe_cook_label_1, 185, 219);
    lv_obj_set_size(ui->recipe_cook_label_1, 654, 148);
    lv_label_set_text(ui->recipe_cook_label_1, "Label");
    lv_label_set_long_mode(ui->recipe_cook_label_1, LV_LABEL_LONG_WRAP);

    //Write style for recipe_cook_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recipe_cook_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_cook_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_cook_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_cook_label_1, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_cook_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recipe_cook_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recipe_cook_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_cook_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recipe_cook_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recipe_cook_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recipe_cook_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recipe_cook_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recipe_cook_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_cook_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recipe_cook_label_2
    ui->recipe_cook_label_2 = lv_label_create(ui->recipe_cook);
    lv_obj_set_pos(ui->recipe_cook_label_2, 120, 153);
    lv_obj_set_size(ui->recipe_cook_label_2, 125, 39);
    lv_label_set_text(ui->recipe_cook_label_2, "步骤1");
    lv_label_set_long_mode(ui->recipe_cook_label_2, LV_LABEL_LONG_WRAP);

    //Write style for recipe_cook_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recipe_cook_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recipe_cook_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recipe_cook_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recipe_cook_label_2, &lv_customer_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recipe_cook_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recipe_cook_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recipe_cook_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recipe_cook_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recipe_cook_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recipe_cook_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recipe_cook_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recipe_cook_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recipe_cook_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recipe_cook_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of recipe_cook.

    lv_label_set_text_fmt(gui.recipe_cook_label_1, "%s\n备注:%s",
                          myrecipe.steps[recipe_step].instruction,
                          myrecipe.steps[recipe_step].note);

    //Update current screen layout.
    lv_obj_update_layout(ui->recipe_cook);

    //Init events for screen.
    events_init_recipe_cook(ui);
}
