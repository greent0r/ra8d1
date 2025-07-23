
#ifndef WS2812_H_
#define WS2812_H_

#include "platform.h"
#include "hal_data.h"


#define LED_NUM 8  // WS2812灯珠数量
#define LED_DATA_LEN (LED_NUM * 24)  // 每个灯珠24位数据

// 编码逻辑0和逻辑1的脉冲宽度
#define T0H 30  // 逻辑0的高电平时间
#define T1H 60  // 逻辑1的高电平时间

extern uint16_t ws2812_buffer[LED_DATA_LEN];

void ws2812_pwm_init(void);
void ws2812_pwm_setduty(uint8_t duty);
void WS2812_Set(uint16_t num,uint8_t R,uint8_t G,uint8_t B);
void encode_byte(uint8_t byte, uint16_t *data);
void encode_led(uint8_t r, uint8_t g, uint8_t b, uint16_t *data);
void set_one_led(uint32_t index, uint8_t r, uint8_t g, uint8_t b);
void set_all_leds(uint8_t r, uint8_t g, uint8_t b);

void ws2812_start(void);
void ws2812_stop(void);
#endif
