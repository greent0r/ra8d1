#include "BLK.h"


void lcd_backlight_init(void)
{
    R_GPT_Open(&timer6_ctrl, &timer6_cfg);//背光pwm定时器
    R_GPT_Start(&timer6_ctrl);
    lcd_set_brightness(50);
}

void lcd_set_brightness(uint8_t duty){
    timer_info_t info;
    uint32_t current_period_counts;
    uint32_t duty_cycle_counts;
    if (duty > 100) duty = 100; //限制占空比范围：0~100
    R_GPT_InfoGet(&timer6_ctrl, &info);
    current_period_counts = info.period_counts;
    duty_cycle_counts = (uint32_t)(((uint64_t) current_period_counts * duty) / 100);
    R_GPT_DutyCycleSet(&timer6_ctrl, duty_cycle_counts, GPT_IO_PIN_GTIOCB);
}

