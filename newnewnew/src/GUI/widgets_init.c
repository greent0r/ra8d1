/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include "gui_guider.h"
#include "widgets_init.h"
#include <stdlib.h>
#include <string.h>


__attribute__((unused)) void kb_event_cb (lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *kb = lv_event_get_target(e);
    if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
}

__attribute__((unused)) void ta_event_cb (lv_event_t *e) {
#if LV_USE_KEYBOARD
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_t * kb = lv_event_get_user_data(e);

    if(code == LV_EVENT_FOCUSED) {
        if(lv_indev_get_type(lv_indev_active()) != LV_INDEV_TYPE_KEYPAD) {
            lv_keyboard_set_textarea(kb, ta);
            lv_obj_remove_flag(kb, LV_OBJ_FLAG_HIDDEN);
        }
    } else if(code == LV_EVENT_READY) {
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_state(ta, LV_STATE_FOCUSED);
        lv_indev_reset(NULL, ta);
    } else if(code == LV_EVENT_DEFOCUSED) {
        lv_keyboard_set_textarea(kb, NULL);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
#endif
}

void clock_count(int *hour, int *min, int *sec)
{
    (*sec)++;
    if(*sec == 60)
    {
        *sec = 0;
        (*min)++;
    }
    if(*min == 60)
    {
        *min = 0;
        if(*hour==24){
            *hour=0;

        }
        else{
            *hour++;
        }
    }
}

static lv_obj_t * main_datetext_1_calendar;

void main_datetext_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_FOCUSED) {
        char * s = lv_label_get_text(btn);
        if(main_datetext_1_calendar == NULL) {
            main_datetext_1_init_calendar(btn, s);
        }
    }
}

void main_datetext_1_init_calendar(lv_obj_t *obj, char * s)
{
    if (main_datetext_1_calendar == NULL) {
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        main_datetext_1_calendar = lv_calendar_create(lv_layer_top());
        lv_obj_t * scr = lv_obj_get_screen(obj);
        int32_t scr_height = lv_obj_get_height(scr);
        int32_t scr_width = lv_obj_get_width(scr);
        lv_obj_set_size(main_datetext_1_calendar, scr_width * 0.8, scr_height * 0.8);
        char * year = strtok(s, "/");
        char * month = strtok(NULL, "/");
        char * day = strtok(NULL, "/");
        lv_calendar_set_showed_date(main_datetext_1_calendar, atoi(year), atoi(month));
        lv_calendar_date_t highlighted_days[1];       /*Only its pointer will be saved so should be static*/
        highlighted_days[0].year = atoi(year);
        highlighted_days[0].month = atoi(month);
        highlighted_days[0].day = atoi(day);
        lv_calendar_set_highlighted_dates(main_datetext_1_calendar, highlighted_days, 1);
        lv_obj_align(main_datetext_1_calendar,LV_ALIGN_CENTER, 0, 0);

        lv_obj_add_event_cb(main_datetext_1_calendar, main_datetext_1_calendar_event_handler, LV_EVENT_ALL,NULL);
        lv_calendar_header_arrow_create(main_datetext_1_calendar);
        lv_obj_update_layout(scr);
    }
}

void main_datetext_1_calendar_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_current_target(e);

    if (code == LV_EVENT_VALUE_CHANGED) {
        lv_calendar_date_t date;
        lv_calendar_get_pressed_date(obj,&date);
        char buf[16];
        lv_snprintf(buf,sizeof(buf),"%d/%02d/%02d", date.year, date.month,date.day);
        lv_label_set_text(gui.main_datetext_1, buf);
        lv_obj_remove_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_style_bg_opa(lv_layer_top(), LV_OPA_TRANSP, 0);
        lv_obj_delete(main_datetext_1_calendar);
        main_datetext_1_calendar = NULL;
    }
}


extern int main_digital_clock_1_hour_value;
extern int main_digital_clock_1_min_value;
extern int main_digital_clock_1_sec_value;

void main_digital_clock_1_timer(lv_timer_t *timer)
{
    clock_count(&main_digital_clock_1_hour_value, &main_digital_clock_1_min_value, &main_digital_clock_1_sec_value);
    if (lv_obj_is_valid(gui.main_digital_clock_1))
    {
        lv_label_set_text_fmt(gui.main_digital_clock_1, "%02d:%02d:%02d", main_digital_clock_1_hour_value, main_digital_clock_1_min_value, main_digital_clock_1_sec_value);
    }
}

