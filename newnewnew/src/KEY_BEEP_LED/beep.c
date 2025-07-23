#include <KEY_BEEP_LED/beep.h>

#include "hal_data.h"

// 480MHz主频，输出频率 = 主频 / beep_timer_cfg.period_counts
// 占空比 = beep_timer_cfg.duty_cycle_counts / beep_timer_cfg.period_counts

/* GPT初始化函数 */
void beep_pwm_init(void)
{
    /* 初始化 GPT 模块 */
    R_GPT_Open(&beep_timer_ctrl, &beep_timer_cfg);

    /* 启动 GPT 定时器 */
    R_GPT_Start(&beep_timer_ctrl);
}

// 可以使用 R_GPT_Stop() 来关闭 PWM 输出(大概)

/** 设置PWM占空比
    @param duty 占空比范围：0~100 %
*/
void beep_pwm_setduty(uint8_t duty)
{
    timer_info_t info;
    uint32_t current_period_counts;
    uint32_t duty_cycle_counts;


    if (duty > 100)
        duty = 100; //限制占空比范围：0~100


    /* 获得GPT的信息 */
    R_GPT_InfoGet(&beep_timer_ctrl, &info);

    /* 获得计时器一个周期需要的计数次数 */
    current_period_counts = info.period_counts;

    /* 根据占空比和一个周期的计数次数计算GTCCR寄存器的值 */
    duty_cycle_counts = (uint32_t)(((uint64_t) current_period_counts * duty) / 100);


    /* 最后调用FSP库函数设置占空比 */
    R_GPT_DutyCycleSet(&beep_timer_ctrl, duty_cycle_counts, GPT_IO_PIN_GTIOCB);
}

void beep_start(void)
{
    beep_pwm_init();
    beep_pwm_setduty(50);
}

void beep_stop(void)
{
    R_GPT_Stop(&beep_timer_ctrl);
}


