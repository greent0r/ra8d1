/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"




typedef struct
{
  
	lv_obj_t *main;
	bool main_del;
	lv_obj_t *main_btn_1;
	lv_obj_t *main_btn_1_label;
	lv_obj_t *main_btn_2;
	lv_obj_t *main_btn_2_label;
	lv_obj_t *main_btn_3;
	lv_obj_t *main_btn_3_label;
	lv_obj_t *main_btn_4;
	lv_obj_t *main_btn_4_label;
	lv_obj_t *main_label_3;
	lv_obj_t *main_label_4;
	lv_obj_t *main_label_5;
	lv_obj_t *main_label_6;
	lv_obj_t *main_datetext_1;
	lv_obj_t *main_digital_clock_1;
	lv_obj_t *tool;
	bool tool_del;
	lv_obj_t *tool_btn_1;
	lv_obj_t *tool_btn_1_label;
	lv_obj_t *tool_label_1;
	lv_obj_t *tool_roller_1;//温度提醒
	lv_obj_t *tool_btn_2;
	lv_obj_t *tool_btn_2_label;
	lv_obj_t *tool_label_2;
	lv_obj_t *tool_label_4;
	lv_obj_t *tool_label_3;
	lv_obj_t *tool_label_5;
	lv_obj_t *tool_label_6;
    lv_obj_t *tool_roller_2;//闹钟
    lv_obj_t *tool_label_7;
    lv_obj_t *tool_roller_3;//闹钟
    lv_obj_t *tool_roller_4;//闹钟
    lv_obj_t *tool_label_8;
    lv_obj_t *tool_btn_3;
    lv_obj_t *tool_btn_3_label;
    lv_obj_t *tool_label_9;
    lv_obj_t *tool_label_10;
    lv_obj_t *tool_label_11;
    lv_obj_t *tool_label_12;
    lv_obj_t *tool_label_13;
    lv_obj_t *tool_btn_4;
    lv_obj_t *tool_btn_4_label;
	lv_obj_t *recognize;
	bool recognize_del;
	lv_obj_t *recognize_btn_1;
	lv_obj_t *recognize_btn_1_label;
	lv_obj_t *recognize_btn_2;
	lv_obj_t *recognize_btn_2_label;
	lv_obj_t *recognize_label_1;
	lv_obj_t *recognize_label_2;
	lv_obj_t *recognize_label_3;
	lv_obj_t *recognize_label_4;
    lv_obj_t *recognize_label_5;
    lv_obj_t *recognize_label_6;
    lv_obj_t *recognize_label_0;
	lv_obj_t *camera;
	bool camera_del;
	lv_obj_t *camera_btn_1;
	lv_obj_t *camera_btn_1_label;
	lv_obj_t *camera_btn_2;
	lv_obj_t *camera_btn_2_label;
	lv_obj_t *canvas_cam;
	lv_obj_t *setting;
	bool setting_del;
	lv_obj_t *setting_btn_1;
	lv_obj_t *setting_btn_1_label;
	lv_obj_t *setting_slider_1;
	lv_obj_t *setting_slider_2;
	lv_obj_t *setting_label_1;
	lv_obj_t *setting_label_2;
	lv_obj_t *setting_label_3;
	lv_obj_t *setting_ddlist_1;
	lv_obj_t *setting_btn_2;
	lv_obj_t *setting_btn_2_label;
	lv_obj_t *setting_ta_6;
	lv_obj_t *setting_ta_5;
	lv_obj_t *setting_ta_4;
	lv_obj_t *setting_label_9;
	lv_obj_t *setting_label_8;
	lv_obj_t *setting_label_7;
	lv_obj_t *setting_btn_4;
	lv_obj_t *setting_btn_4_label;
    lv_obj_t *setting_btn_3;
    lv_obj_t *setting_btn_3_label;
    lv_obj_t *setting_label_10;
    lv_obj_t *setting_ta_7;
    lv_obj_t *setting_btn_5;
    lv_obj_t *setting_btn_5_label;
	lv_obj_t *recipe_main;
	bool recipe_main_del;
	lv_obj_t *recipe_main_btn_1;
	lv_obj_t *recipe_main_btn_1_label;
	lv_obj_t *recipe_main_btn_3;
	lv_obj_t *recipe_main_btn_3_label;
	lv_obj_t *recipe_main_btn_4;
	lv_obj_t *recipe_main_btn_4_label;
    lv_obj_t *recipe_main_btn_5;
    lv_obj_t *recipe_main_btn_5_label;
    lv_obj_t *recipe_main_btn_6;
    lv_obj_t *recipe_main_btn_6_label;
	lv_obj_t *recipe_main_ta_1;
	lv_obj_t *recipe_main_btn_2;
	lv_obj_t *recipe_main_btn_2_label;
	lv_obj_t *recipe_all;
	bool recipe_all_del;
	lv_obj_t *recipe_all_btn_return;
	lv_obj_t *recipe_all_btn_return_label;
	lv_obj_t *recipe_all_label_1;
	lv_obj_t *recipe_all_recipe_list;
	lv_obj_t *recipe_all_recipe_list_item0;
	lv_obj_t *recipe_all_recipe_list_item1;
	lv_obj_t *recipe_all_recipe_list_item2;
	lv_obj_t *recipe_all_recipe_list_item3;
	lv_obj_t *recipe_all_recipe_list_item4;
	lv_obj_t *recipe_all_recipe_list_item5;
	lv_obj_t *recipe_all_recipe_list_item6;
	lv_obj_t *recipe_all_recipe_list_item7;
	lv_obj_t *recipe_all_recipe_list_item8;
	lv_obj_t *recipe_all_recipe_list_item9;
    lv_obj_t *recipe_all_recipe_list_item10;
    lv_obj_t *recipe_all_recipe_list_item11;
    lv_obj_t *recipe_all_recipe_list_item12;
    lv_obj_t *recipe_all_btn_2;
    lv_obj_t *recipe_all_btn_2_label;
    lv_obj_t *recipe_all_btn_3;
    lv_obj_t *recipe_all_btn_3_label;
    lv_obj_t *recipe_all_label_2;
	lv_obj_t *recipe_one;
    bool recipe_one_del;
    lv_obj_t *recipe_one_recipe_description;
    lv_obj_t *recipe_one_recipe_difficulty;
    lv_obj_t *recipe_one_recipe_time;
    lv_obj_t *recipe_one_btn_1;
    lv_obj_t *recipe_one_btn_1_label;
    lv_obj_t *recipe_one_label_6;
    lv_obj_t *recipe_one_step_list;
    lv_obj_t *recipe_one_label_7;
    lv_obj_t *recipe_one_ingredient_list;
    lv_obj_t *recipe_one_btn_2;
    lv_obj_t *recipe_one_btn_2_label;
    lv_obj_t *recipe_one_recipe_name;
    lv_obj_t *recipe_one_label_8;
    lv_obj_t *recipe_one_label_9;
    lv_obj_t *recipe_one_btn_3;
    lv_obj_t *recipe_one_btn_3_label;
    lv_obj_t *recipe_cook;
	bool recipe_cook_del;
	lv_obj_t *recipe_cook_img_1;
	lv_obj_t *recipe_cook_btn_1;
	lv_obj_t *recipe_cook_btn_1_label;
	lv_obj_t *recipe_cook_recipe_name;
	lv_obj_t *recipe_cook_prev_step;
	lv_obj_t *recipe_cook_prev_step_label;
	lv_obj_t *recipe_cook_next_step;
	lv_obj_t *recipe_cook_next_step_label;
	lv_obj_t *recipe_cook_label_1;
	lv_obj_t *recipe_cook_label_2;
    lv_obj_t *recipe_plan;
    lv_obj_t *recipe_plan_btn_1;
    lv_obj_t *recipe_plan_btn_1_label;
    lv_obj_t *recipe_plan_table_1;
    lv_obj_t *recipe_plan_sw_1;
    lv_obj_t *recipe_plan_label_1;
    bool recipe_plan_del;
	lv_obj_t *g_kb_top_layer;
}lv_ui;

extern lv_ui gui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_screen_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, uint32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                  uint32_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                  lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_completed_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_bottom_layer(void);

void setup_ui(lv_ui *ui);

void video_play(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_main(lv_ui *ui);
void setup_scr_tool(lv_ui *ui);
void setup_scr_recognize(lv_ui *ui);
void setup_scr_camera(lv_ui *ui);
void setup_scr_setting(lv_ui *ui);
void setup_scr_recipe_main(lv_ui *ui);
void setup_scr_recipe_all(lv_ui *ui);
void setup_scr_recipe_one(lv_ui *ui);
void setup_scr_recipe_cook(lv_ui *ui);
void setup_scr_recipe_plan(lv_ui *ui);

LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_18)
LV_FONT_DECLARE(lv_customer_font_simsun_24)
LV_FONT_DECLARE(lv_customer_font_simsun_48)


#ifdef __cplusplus
}
#endif
#endif
