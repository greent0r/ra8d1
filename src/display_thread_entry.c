#include "display_thread.h"
#include "lvgl.h"
#include "task.h"
#include "GUI/lv_port_disp.h"
#include "GUI/lv_port_indev.h"
#include "GUI/lvgl-9.2.1/demos/lv_demos.h"
#include "stdio.h"
#include "LCD.h"
#include "DISPLAY/gt911.h"
#include "DISPLAY/BLK.h"
#include "CEU/ov5640.h"
#include "key.h"
#include "ff.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
#include "HX711.h"
#include "max6675.h"
#include "max17048.h"
#include "ceu.h"

extern int main_digital_clock_1_min_value;
extern int main_digital_clock_1_hour_value;
extern int main_digital_clock_1_sec_value;
extern TaskHandle_t display_thread;


void show_recipe_popup(void);

void timer12_callback(timer_callback_args_t * p_args){
    if (TIMER_EVENT_CYCLE_END == p_args->event){
        lv_tick_inc(1);

    }
}


void display_thread_entry(void *pvParameters)
{
    char buff[50];
    FSP_PARAMETER_NOT_USED (pvParameters);
    lcd_backlight_init();
    lcd_init();
    gt9xx_Init();
    R_GPT_Open(&timer12_ctrl, &timer12_cfg);
    R_GPT_Start(&timer12_ctrl);
    ov5640_init(320,240,1800,1000);
    //memset(&g_framebuffer[0][0],0xFF,1024*600*3);
    //memset(&g_framebuffer[1][0],0xFF,1024*600*3);
    //while(1);
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();
    setup_ui(&gui);
    lv_timer_create(countdown_timer_cb, 1000, NULL);

    lvgl_begin=1;
    printf("lvgl begin\n");
//
//    lv_obj_t * scr = lv_scr_act(); // 获取当前屏幕对象
//    lv_obj_clean(scr);             // 清空当前屏幕内容
//    lv_obj_t * bg = lv_obj_create(scr);
//    lv_obj_set_size(bg, LV_HOR_RES, LV_VER_RES); // 设置为屏幕分辨率
//    lv_obj_set_style_bg_color(bg, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
//    lv_obj_set_style_border_width(bg, 0, LV_PART_MAIN); // 去掉边框
//    while(1){
//        lv_obj_set_style_bg_color(bg, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
//    }

    static int times=0;
    while (1){
        lv_timer_handler();
        if(times==0){
            wifi?lv_obj_clear_flag(gui.main_label_5, LV_OBJ_FLAG_HIDDEN):lv_obj_add_flag(gui.main_label_5, LV_OBJ_FLAG_HIDDEN);
            mqtt?lv_obj_clear_flag(gui.main_label_6, LV_OBJ_FLAG_HIDDEN):lv_obj_add_flag(gui.main_label_6, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text_fmt(gui.main_label_3, "电量%d%%", Battery_Soc>100?100:Battery_Soc);
        }
        if(ceu_flag){
            if(ov5640_capture()!=0){
                vTaskDelay(100);
            }
            else
                lv_obj_invalidate(gui.canvas_cam);
        }
        if(recognize_receive){
            recognize_receive=0;
            if(lv_screen_active()==gui.recognize){
                char buff[100];
                sprintf(buff,"1.%s:置信度%1.4f",result[0].name,result[0].score);
                lv_label_set_text(gui.recognize_label_1, buff);
                sprintf(buff,"2.%s:置信度%1.4f",result[1].name,result[1].score);
                lv_label_set_text(gui.recognize_label_2, buff);
                sprintf(buff,"3.%s:置信度%1.4f",result[2].name,result[2].score);
                lv_label_set_text(gui.recognize_label_3, buff);
                sprintf(buff,"4.%s:置信度%1.4f",result[3].name,result[3].score);
                lv_label_set_text(gui.recognize_label_4, buff);
                sprintf(buff,"5.%s:置信度%1.4f",result[4].name,result[4].score);
                lv_label_set_text(gui.recognize_label_5, buff);
                sprintf(buff,"6.%s:置信度%1.4f",result[5].name,result[5].score);
                lv_label_set_text(gui.recognize_label_6, buff);
            }
        }
        if(tool_setup_done && times%100==0){
            sprintf(buff,"%d",weight);
            lv_label_set_text(gui.tool_label_1, buff);
            sprintf(buff,"%3.1f",temper);
            lv_label_set_text(gui.tool_label_4, buff);
        }
        if(key[0].single_flag){
            key[0].single_flag=0;
            if(lv_screen_active()==gui.recipe_cook){
                tool_setup_done=1;
                ui_load_scr_animation(&gui, &gui.tool, gui.tool_del, &gui.recipe_cook_del, setup_scr_tool, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, false);
            }
        }
        if(key[1].single_flag){
            key[1].single_flag=0;
            if(lv_screen_active()==gui.tool){
                tool_setup_done=0;
                ui_load_scr_animation(&gui, &gui.recipe_cook, gui.recipe_cook_del, &gui.tool_del, setup_scr_recipe_cook, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, false);
            }
        }
        if(recipe_receive){
            recipe_receive=0;
            show_recipe_popup();
        }
        if(update_time){
            update_time=0;
            lv_label_set_text_fmt(gui.main_datetext_1, "%d/%02d/%02d",now_time.tm_year,now_time.tm_mon,now_time.tm_mday);
            main_digital_clock_1_hour_value=now_time.tm_hour;
            main_digital_clock_1_min_value=now_time.tm_min;
            main_digital_clock_1_sec_value=now_time.tm_sec;
        }
        times=(times+1)%1000;
        gt9xx_Scan(0);
        vTaskDelay(1);
    }
}



static lv_obj_t *msgbox = NULL;

// 按钮事件回调
static void btn1_event_cb(lv_event_t *e) {
    memset(&recipe_rx, 0, sizeof(recipe_rx));
    lv_msgbox_close(msgbox); // 关闭消息框
    msgbox=NULL;
}

// 按钮事件回调
static void btn2_event_cb(lv_event_t *e) {
    save_recipe(&recipe_rx);
    memset(&recipe_rx, 0, sizeof(recipe_rx));
    printf("菜谱已保存\n");
    lv_msgbox_close(msgbox); // 关闭消息框
    msgbox=NULL;
}

void show_recipe_popup(void) {
    if(msgbox){
        return;
    }
    msgbox = lv_msgbox_create(lv_scr_act());
    lv_obj_set_size(msgbox, 800, 500);
    lv_obj_center(msgbox);
    lv_obj_set_style_text_font(msgbox, &lv_customer_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(msgbox, true, 0);

    // 添加两个简单按钮
    lv_obj_t *btn_ok = lv_msgbox_add_footer_button(msgbox, "取消");
    lv_obj_add_event_cb(btn_ok, btn1_event_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_t *btn_cancel = lv_msgbox_add_footer_button(msgbox, "保存");
    lv_obj_add_event_cb(btn_cancel, btn2_event_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_t * content = lv_msgbox_get_content(msgbox);
    lv_obj_set_flex_flow(content, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(content, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    //lv_obj_set_style_pad_right(content, -1, LV_PART_SCROLLBAR);

    lv_obj_t* msglabel =lv_label_create(content);
    char* buffer=mymalloc(8192);
    sprintf(buffer,
        "菜谱名称: %s\n\n"
        "描述: %s\n"
        "分类: %s\n"
        "难度: %d\n"
        "准备时间: %d分钟\n"
        "烹饪时间: %d分钟\n\n"
        "食材清单:\n",
        recipe_rx.name,
        recipe_rx.description,
        recipe_rx.category,
        recipe_rx.difficulty,
        recipe_rx.prep_time,
        recipe_rx.cook_time
    );

    // 添加食材
    for(int i = 0; i < recipe_rx.ingredient_count; i++) {
        strcat(buffer, "  ");
        strcat(buffer, recipe_rx.ingredients[i].name);
        strcat(buffer, ": ");
        char qty[20];
        sprintf(qty, "%.1f%s\n", recipe_rx.ingredients[i].quantity,
                               recipe_rx.ingredients[i].unit);
        strcat(buffer, qty);
    }

    // 添加步骤
    strcat(buffer, "\n烹饪步骤:\n");
    for(int i = 0; i < recipe_rx.step_count; i++) {
        char step[100];
        sprintf(step, "%d. %s\n", recipe_rx.steps[i].step_number,
                                 recipe_rx.steps[i].instruction);
        strcat(buffer, step);
    }

    lv_label_set_text(msglabel, buffer);

    myfree(buffer);
}


