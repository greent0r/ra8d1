/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "ov5640.h"
#include "platform.h"
#include "FreeRTOS.h"
#include "task.h"
#include "HX711/HX711.h"
#include "FILE/cJSON.h"
#include "SNR9816/snr9816.h"
#include "KEY_BEEP_LED/ws2812.h"
#include "KEY_BEEP_LED/beep.h"
#include "KEY_BEEP_LED/key.h"
#include "MAX17048/max17048.h"
#include "MAX6675/max6675.h"
#include "MQ4_MQ5/MQ4_MQ5.h"
#include "my_wifi.h"
#include "FILE/ff.h"
#include "BLK.h"
#include "custom.h"
#include "recipe.h"
#include "Gb2utf8.h"

extern int main_digital_clock_1_hour_value;
extern int main_digital_clock_1_min_value;
extern int main_digital_clock_1_sec_value;

static void main_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        ui_load_scr_animation(&gui, &gui.recipe_main, gui.recipe_main_del, &gui.main_del, setup_scr_recipe_main, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, false);
        break;
    }
    default:
        break;
    }
}

static void main_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        ui_load_scr_animation(&gui, &gui.tool, gui.tool_del, &gui.main_del, setup_scr_tool, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, false);
        break;
    }
    default:
        break;
    }
}

static void main_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        ui_load_scr_animation(&gui, &gui.recognize, gui.recognize_del, &gui.main_del, setup_scr_recognize, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, false);
        ceu_flag=1;
        break;
    }
    default:
        break;
    }
}

static void main_btn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        ui_load_scr_animation(&gui, &gui.setting, gui.setting_del, &gui.main_del, setup_scr_setting, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, false);
        break;
    }
    default:
        break;
    }
}

void events_init_main (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->main_btn_1, main_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->main_btn_2, main_btn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->main_btn_3, main_btn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->main_btn_4, main_btn_4_event_handler, LV_EVENT_ALL, ui);
}

static void tool_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        tool_setup_done=0;
        ui_load_scr_animation(&gui, &gui.main, gui.main_del, &gui.tool_del, setup_scr_main, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);
        break;
    }
    default:
        break;
    }
}

static void tool_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        Get_Tare_flag=1;
        break;
    }
    default:
        break;
    }
}

static void tool_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        int hour=lv_roller_get_selected(gui.tool_roller_2);
        int minute=lv_roller_get_selected(gui.tool_roller_3);
        int second=lv_roller_get_selected(gui.tool_roller_4);
        start_countdown(hour, minute, second);
        break;
    }
    default:
        break;
    }
}

static void tool_btn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        temp_set=lv_roller_get_selected(gui.tool_roller_1)+20;
        break;
    }
    default:
        break;
    }
}

void events_init_tool (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->tool_btn_1, tool_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->tool_btn_3, tool_btn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->tool_btn_2, tool_btn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->tool_btn_4, tool_btn_4_event_handler, LV_EVENT_ALL, ui);
}

static void recognize_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        ceu_flag=0;
        lv_obj_delete(gui.canvas_cam);
        ui_load_scr_animation(&gui, &gui.main, gui.main_del, &gui.recognize_del, setup_scr_main, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);
        break;
    }
    default:
        break;
    }
}

static void recognize_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        ceu_upload=1;
        ceu_flag=0;
        //ui_load_scr_animation(&gui, &gui.camera, gui.camera_del, &gui.recognize_del, setup_scr_camera, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);

        break;
    }
    default:
        break;
    }
}

void events_init_recognize (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->recognize_btn_1, recognize_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recognize_btn_2, recognize_btn_2_event_handler, LV_EVENT_ALL, ui);
}

static void camera_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        ui_load_scr_animation(&gui, &gui.recognize, gui.recognize_del, &gui.camera_del, setup_scr_recognize, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);
//        lv_obj_delete(gui.canvas_cam);
//        ceu_flag=0;
        break;
    }
    default:
        break;
    }
}

static void camera_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        ui_load_scr_animation(&gui, &gui.recognize, gui.recognize_del, &gui.camera_del, setup_scr_recognize, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);
//        ceu_upload=1;
//        lv_obj_delete(gui.canvas_cam);
//        ceu_flag=0;
        break;
    }
    default:
        break;
    }
}

void events_init_camera (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->camera_btn_1, camera_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->camera_btn_2, camera_btn_2_event_handler, LV_EVENT_ALL, ui);
}

static void setting_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        ui_load_scr_animation(&gui, &gui.main, gui.main_del, &gui.setting_del, setup_scr_main, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);
        break;
    }
    default:
        break;
    }
}

static void setting_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        main_digital_clock_1_hour_value=atoi(lv_textarea_get_text(gui.setting_ta_4));
        main_digital_clock_1_min_value=atoi(lv_textarea_get_text(gui.setting_ta_5));
        main_digital_clock_1_sec_value=atoi(lv_textarea_get_text(gui.setting_ta_6));
       break;
    }
    default:
        break;
    }
}


static void setting_slider_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        voice=(uint8_t)lv_slider_get_value(gui.setting_slider_1);
        voice_change=1;
        break;
    }
    default:
        break;
    }
}

static void setting_slider_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        lcd_set_brightness((uint8_t)lv_slider_get_value(gui.setting_slider_2));
        break;
    }
    default:
        break;
    }
}

static void setting_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        get_wifi=1;
        vTaskDelay(3000);
        char buf[512];
        sprintf(buf,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",
                ap_list[0].ssid,ap_list[1].ssid,ap_list[2].ssid,ap_list[3].ssid,
                ap_list[4].ssid,ap_list[5].ssid,ap_list[6].ssid,ap_list[7].ssid,
                ap_list[8].ssid,ap_list[0].ssid);
        lv_dropdown_set_options(gui.setting_ddlist_1, buf);
        break;
    }
    default:
        break;
    }
}

static void setting_btn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        ESP8266_PWD = (char*)lv_textarea_get_text(gui.setting_ta_7);
        uint8_t id=lv_dropdown_get_selected(gui.setting_ddlist_1);
        ESP8266_SSID=ap_list[id].ssid;
        wifi_con=1;
        vTaskDelay(2000);
        break;
    }
    default:
        break;
    }
}

static void setting_btn_5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        mqtt_con=1;
        break;
    }
    default:
        break;
    }
}

void events_init_setting (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->setting_btn_1, setting_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->setting_btn_2, setting_btn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->setting_slider_1, setting_slider_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->setting_slider_2, setting_slider_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->setting_btn_3, setting_btn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->setting_btn_4, setting_btn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->setting_btn_5, setting_btn_5_event_handler, LV_EVENT_ALL, ui);
}

static void recipe_main_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        ui_load_scr_animation(&gui, &gui.main, gui.main_del, &gui.recipe_main_del, setup_scr_main, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);
        break;
    }
    default:
        break;
    }
}

static void recipe_main_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        recipe_page=0;
        ui_load_scr_animation(&gui, &gui.recipe_all, gui.recipe_all_del, &gui.recipe_main_del, setup_scr_recipe_all, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);
        break;
    }
    default:
        break;
    }
}

lv_obj_t* recipe_main_msgbox;


static void recipe_main_btn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    static char recipe_name_suiji[70];
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        if(get_random_recipe_name(recipe_name_suiji, sizeof(recipe_name_suiji))==true){
            memset(&myrecipe,0,sizeof(myrecipe));
            strcpy(myrecipe.name, recipe_name_suiji);
            printf("Selected recipe: %s\n", recipe_name_suiji);
            load_recipe(&myrecipe);
            suiji=1;
            ui_load_scr_animation(&gui, &gui.recipe_one, gui.recipe_one_del, &gui.recipe_main_del, setup_scr_recipe_one, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        }
        break;
    }
    default:
        break;
    }
}



static void recipe_main_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        if(recipe_main_msgbox){
            lv_obj_delete(recipe_main_msgbox);
        }
        const char* recipe_name=lv_textarea_get_text(gui.recipe_main_ta_1);
        if(find_recipe(recipe_name)){
            memset(&myrecipe,0,sizeof(myrecipe));
            strcpy(myrecipe.name, recipe_name);
            printf("Selected recipe: %s\n", recipe_name);
            load_recipe(&myrecipe);
            recipe_main_msgbox = lv_msgbox_create(gui.recipe_main);
            lv_obj_set_size(recipe_main_msgbox, 400, 200);
            lv_obj_center(recipe_main_msgbox);
            lv_obj_set_style_text_font(recipe_main_msgbox, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_clip_corner(recipe_main_msgbox, true, 0);
            lv_msgbox_add_text(recipe_main_msgbox, "找到菜谱");
            lv_obj_invalidate(lv_scr_act());
            vTaskDelay(2000);
            suiji=1;
            ui_load_scr_animation(&gui, &gui.recipe_one, gui.recipe_one_del, &gui.recipe_main_del, setup_scr_recipe_one, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
//            lv_msgbox_add_close_button(recipe_main_msgbox);
//            lv_obj_t * apply_button = lv_msgbox_add_footer_button(recipe_main_msgbox, "进入");
//            lv_obj_set_flex_grow(apply_button, 1);
//            lv_obj_add_event_cb(apply_button, apply_button_event_cb, LV_EVENT_CLICKED, NULL);
        }
        else{
            recipe_main_msgbox = lv_msgbox_create(gui.recipe_main);
            lv_obj_set_size(recipe_main_msgbox, 400, 200);
            lv_obj_center(recipe_main_msgbox);
            lv_obj_set_style_text_font(recipe_main_msgbox, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_clip_corner(recipe_main_msgbox, true, 0);
            lv_msgbox_add_text(recipe_main_msgbox, "未找到菜谱");
            lv_obj_invalidate(lv_scr_act());
            vTaskDelay(2000);
//            lv_obj_delete(recipe_main_msgbox);
            lv_msgbox_add_close_button(recipe_main_msgbox);
        }
        break;
    }
    default:
        break;
    }
}

static void recipe_main_btn_5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        ai_recommend=1;
        break;
    }
    default:
        break;
    }
}

static void recipe_main_btn_6_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        ui_load_scr_animation(&gui, &gui.recipe_plan, gui.recipe_plan_del, &gui.recipe_main_del, setup_scr_recipe_plan, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_recipe_main (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->recipe_main_btn_1, recipe_main_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_main_btn_2, recipe_main_btn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_main_btn_3, recipe_main_btn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_main_btn_4, recipe_main_btn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_main_btn_5, recipe_main_btn_5_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_main_btn_6, recipe_main_btn_6_event_handler, LV_EVENT_ALL, ui);
}

static void recipe_all_btn_return_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        ui_load_scr_animation(&gui, &gui.recipe_main, gui.recipe_main_del, &gui.recipe_all_del, setup_scr_recipe_main, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void recipe_all_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        recipe_page=recipe_page==0?recipe_page:recipe_page-1;
        lv_label_set_text_fmt(gui.recipe_all_label_2, "%d",recipe_page+1);
        int count = list_recipe_files(recipe_list,13,recipe_page*13);
        for (int i = 0; i < 13; ++i) {
            const char *label = (i < count) ? recipe_list[i] : "";  // 有则显示菜谱名，无则空
            lv_list_set_button_text(gui.recipe_all_recipe_list, *recipe_items[i], label);
        }
        break;
    }
    default:
        break;
    }
}

static void recipe_all_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        recipe_page++;
        lv_label_set_text_fmt(gui.recipe_all_label_2, "%d",recipe_page+1);
        int count = list_recipe_files(recipe_list,13,recipe_page*13);
        for (int i = 0; i < 13; ++i) {
            const char *label = (i < count) ? recipe_list[i] : "";  // 有则显示菜谱名，无则空
            lv_list_set_button_text(gui.recipe_all_recipe_list, *recipe_items[i], label);
        }
        break;
    }
    default:
        break;
    }
}

static void recipe_all_recipe_list_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        const char *recipe_name = lv_list_get_button_text(gui.recipe_all_recipe_list,lv_event_get_target(e)); // 获取按钮上的菜谱名称
        if(recipe_plan_table_1_row != 0 && recipe_plan_table_1_col != 0){
            strcpy(&recipe_plan[(recipe_plan_table_1_row-1)+(recipe_plan_table_1_col-1)*7][0],recipe_name);
            recipe_plan_table_1_row = 0;
            recipe_plan_table_1_col = 0;
            ui_load_scr_animation(&gui, &gui.recipe_plan, gui.recipe_plan_del, &gui.recipe_all_del, setup_scr_recipe_plan, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        }
        else if (strlen(recipe_name) > 1) {
            memset(&myrecipe,0,sizeof(myrecipe));
            printf("Selected recipe: %s\n", recipe_name);
            strcpy(myrecipe.name, recipe_name);
            load_recipe(&myrecipe);
            ui_load_scr_animation(&gui, &gui.recipe_one, gui.recipe_one_del, &gui.recipe_all_del, setup_scr_recipe_one, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        }
        break;
    }
    default:
        break;
    }
}

void events_init_recipe_all (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->recipe_all_btn_return, recipe_all_btn_return_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_all_btn_2, recipe_all_btn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_all_btn_3, recipe_all_btn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_all_recipe_list_item0, recipe_all_recipe_list_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_all_recipe_list_item1, recipe_all_recipe_list_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_all_recipe_list_item2, recipe_all_recipe_list_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_all_recipe_list_item3, recipe_all_recipe_list_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_all_recipe_list_item4, recipe_all_recipe_list_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_all_recipe_list_item5, recipe_all_recipe_list_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_all_recipe_list_item6, recipe_all_recipe_list_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_all_recipe_list_item7, recipe_all_recipe_list_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_all_recipe_list_item8, recipe_all_recipe_list_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_all_recipe_list_item9, recipe_all_recipe_list_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_all_recipe_list_item10, recipe_all_recipe_list_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_all_recipe_list_item11, recipe_all_recipe_list_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_all_recipe_list_item12, recipe_all_recipe_list_event_handler, LV_EVENT_ALL, ui);
}

static void recipe_one_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        if(suiji==1){
            suiji=0;
            ui_load_scr_animation(&gui, &gui.recipe_main, gui.recipe_main_del, &gui.recipe_one_del, setup_scr_recipe_main, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        }
        else if(plan==1){
            recipe_plan_table_1_row = 0;
            recipe_plan_table_1_col = 0;
            plan=0;
            ui_load_scr_animation(&gui, &gui.recipe_plan, gui.recipe_plan_del, &gui.recipe_one_del, setup_scr_recipe_plan, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        }
        else{
            ui_load_scr_animation(&gui, &gui.recipe_all, gui.recipe_all_del, &gui.recipe_one_del, setup_scr_recipe_all, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        }

        break;
    }
    default:
        break;
    }
}

static void recipe_one_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        plan=0;
        recipe_plan_table_1_row = 0;
        recipe_plan_table_1_col = 0;
        recipe_step=0;
        say=1;
        ui_load_scr_animation(&gui, &gui.recipe_cook, gui.recipe_cook_del, &gui.recipe_one_del, setup_scr_recipe_cook, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void recipe_one_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        delete_recipe_file(&myrecipe);
        plan=0;
        recipe_plan_table_1_row = 0;
        recipe_plan_table_1_col = 0;
        if(suiji==1){
            suiji=0;
            ui_load_scr_animation(&gui, &gui.recipe_main, gui.recipe_main_del, &gui.recipe_one_del, setup_scr_recipe_main, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        }
        else{
            ui_load_scr_animation(&gui, &gui.recipe_all, gui.recipe_all_del, &gui.recipe_one_del, setup_scr_recipe_all, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        }
        break;
    }
    default:
        break;
    }
}

void events_init_recipe_one (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->recipe_one_btn_1, recipe_one_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_one_btn_2, recipe_one_btn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_one_btn_3, recipe_one_btn_3_event_handler, LV_EVENT_ALL, ui);
}

static void recipe_cook_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        ui_load_scr_animation(&gui, &gui.recipe_main, gui.recipe_main_del, &gui.recipe_cook_del, setup_scr_recipe_main, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void recipe_cook_prev_step_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        recipe_step=recipe_step==0?0:recipe_step-1;
        lv_label_set_text_fmt(gui.recipe_cook_label_1, "%s\n备注:%s",
                              myrecipe.steps[recipe_step].instruction,
                              myrecipe.steps[recipe_step].note);
        lv_label_set_text_fmt(gui.recipe_cook_label_2, "步骤%d",recipe_step+1);
        say=1;
        break;
    }
    default:
        break;
    }
}

static void recipe_cook_next_step_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        recipe_step = recipe_step == myrecipe.step_count - 1 ? myrecipe.step_count - 1 : recipe_step + 1;
        lv_label_set_text_fmt(gui.recipe_cook_label_1, "%s\n备注:%s",
                              myrecipe.steps[recipe_step].instruction,
                              myrecipe.steps[recipe_step].note);
        lv_label_set_text_fmt(gui.recipe_cook_label_2, "步骤%d",recipe_step+1);
        say=1;
        break;

    }
    default:
        break;
    }
}

void events_init_recipe_cook (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->recipe_cook_btn_1, recipe_cook_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_cook_prev_step, recipe_cook_prev_step_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_cook_next_step, recipe_cook_next_step_event_handler, LV_EVENT_ALL, ui);
}

static void recipe_plan_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        ui_load_scr_animation(&gui, &gui.recipe_main, gui.recipe_main_del, &gui.recipe_plan_del, setup_scr_recipe_main, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void recipe_plan_table_1_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        lv_table_get_selected_cell(gui.recipe_plan_table_1, &recipe_plan_table_1_row, &recipe_plan_table_1_col);
        if(recipe_plan_table_1_row!=0 && recipe_plan_table_1_col!=0)
            if(lv_obj_has_state(gui.recipe_plan_sw_1, LV_STATE_CHECKED))
                ui_load_scr_animation(&gui, &gui.recipe_all, gui.recipe_all_del, &gui.recipe_main_del, setup_scr_recipe_all, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);
            else
                if(strlen(&recipe_plan[(recipe_plan_table_1_row-1)+(recipe_plan_table_1_col-1)*7][0])>2){
                    memset(&myrecipe,0,sizeof(myrecipe));
                    printf("Selected recipe: %s\n", &recipe_plan[(recipe_plan_table_1_row-1)+(recipe_plan_table_1_col-1)*7][0]);
                    strcpy(myrecipe.name, &recipe_plan[(recipe_plan_table_1_row-1)+(recipe_plan_table_1_col-1)*7][0]);
                    load_recipe(&myrecipe);
                    plan=1;
                    ui_load_scr_animation(&gui, &gui.recipe_one, gui.recipe_one_del, &gui.recipe_all_del, setup_scr_recipe_one, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                }
    }
}


void events_init_recipe_plan (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->recipe_plan_btn_1, recipe_plan_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recipe_plan_table_1, recipe_plan_table_1_event_handler, LV_EVENT_VALUE_CHANGED, ui);
}

void events_init(lv_ui *ui)
{

}
