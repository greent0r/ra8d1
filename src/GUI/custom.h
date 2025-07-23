/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"


typedef struct {
    int32_t remaining;     // 剩余秒数
    bool running;          // 是否运行
} countdown_t;

// 定义一个按钮指针数组方便循环处理
extern lv_obj_t **recipe_items[13];

extern char recipe_plan[21][64];
extern uint32_t recipe_plan_table_1_row;
extern uint32_t recipe_plan_table_1_col;
extern _Bool plan;

#define RECIPE_ITEM_COUNT (sizeof(recipe_items) / sizeof(recipe_items[0]))

extern int recipe_page;
extern int recipe_step;


void start_countdown(int hour, int minute, int second);
void countdown_timer_cb(lv_timer_t *timer);
void msg_event_cb(lv_event_t * e);


#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
