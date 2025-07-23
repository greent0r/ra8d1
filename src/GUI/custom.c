/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"
#include "beep.h"
#include "gui_guider.h"

countdown_t g_countdown = {0, false};

char recipe_plan[21][64];
uint32_t recipe_plan_table_1_row=0;
uint32_t recipe_plan_table_1_col=0;
_Bool plan=0;

lv_obj_t *msgbox;

extern lv_obj_t **recipe_items[13] = {
    &gui.recipe_all_recipe_list_item0,
    &gui.recipe_all_recipe_list_item1,
    &gui.recipe_all_recipe_list_item2,
    &gui.recipe_all_recipe_list_item3,
    &gui.recipe_all_recipe_list_item4,
    &gui.recipe_all_recipe_list_item5,
    &gui.recipe_all_recipe_list_item6,
    &gui.recipe_all_recipe_list_item7,
    &gui.recipe_all_recipe_list_item8,
    &gui.recipe_all_recipe_list_item9,
    &gui.recipe_all_recipe_list_item10,
    &gui.recipe_all_recipe_list_item11,
    &gui.recipe_all_recipe_list_item12,
};

int recipe_page=0;
int recipe_step=0;




void start_countdown(int hour, int minute, int second) {
    g_countdown.remaining = hour * 3600 + minute * 60 + second;
    g_countdown.running = true;

    char buf[32];
    int hh = g_countdown.remaining / 3600;
    int mm = (g_countdown.remaining % 3600) / 60;
    int ss = g_countdown.remaining % 60;
    snprintf(buf, sizeof(buf), "%02d时%02d分%02d秒", hh, mm, ss);
    lv_label_set_text(gui.tool_label_8, buf);
}

void msg_event_cb(lv_event_t * e)
{
    beep_stop();
    lv_obj_t * btn = lv_event_get_target(e);
    lv_obj_delete(btn);
    lv_msgbox_close(msgbox);
}

void countdown_timer_cb(lv_timer_t *timer) {
    (void)timer;

    if (!g_countdown.running || g_countdown.remaining <= 0)
        return;

    g_countdown.remaining--;
    if(gui.tool_label_8!=NULL){
        char buf[32];
        int hh = g_countdown.remaining / 3600;
        int mm = (g_countdown.remaining % 3600) / 60;
        int ss = g_countdown.remaining % 60;
        snprintf(buf, sizeof(buf), "%02d时%02d分%02d秒", hh, mm, ss);
        lv_label_set_text(gui.tool_label_8, buf);
    }

    if (g_countdown.remaining == 0) {
        beep_start();
        msgbox = lv_msgbox_create(lv_scr_act());
        lv_obj_set_style_text_font(msgbox, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_msgbox_add_text(msgbox,"时间到了");
        lv_msgbox_add_title(msgbox,"闹钟");
        lv_obj_center(msgbox);
        lv_obj_t *btn = lv_msgbox_add_footer_button(msgbox, "确定");;
        lv_obj_set_style_text_font(btn, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_add_event_cb(btn, msg_event_cb, LV_EVENT_CLICKED, NULL);
        g_countdown.running = false;  // 停止倒计时
    }
}




void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}

