#include "ws2812.h"


//count=150
#define WS_H           102   // 1 码相对计数值
#define WS_L           48   // 0 码相对计数值
#define LED_NUM         8   // WS2812灯个数
#define DATA_LEN       24   // WS2812数据长度，单个需要24个字节
#define WS2812_RST_NUM 50   // 官方复位时间为50us（40个周期），保险起见使用50个周期

#define WS2812_LOW    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_01_PIN_05, BSP_IO_LEVEL_LOW)
#define WS2812_HIGH   R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_01_PIN_05, BSP_IO_LEVEL_HIGH)

//uint32_t ws2812_buffer[LED_DATA_LEN];  // 存储LED数据
//uint8_t ws2812_flag = 0;        // 修改占空比指示信号
//uint32_t WS2812_RGB_Buff[LED_NUM*DATA_LEN+WS2812_RST_NUM] = {0};

uint8_t rgb_data[24] = {0x00,0xFF,0x00,0xFF,0x00,0x00,0x00,0x00,0xFF,0x7F,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x7F,0xFF};



void WS2812_Set(uint16_t num,uint8_t R,uint8_t G,uint8_t B)
{
  uint32_t index=num*3;
  for (uint8_t i = 0;i < 3;i++)
  {
    //填充数组
      rgb_data[index+i]      = G;
      rgb_data[index+i + 1]  = R;
      rgb_data[index+i + 2]  = B;
  }
  uint8_t x = 0,y = 0,z = 0,n = 0;
  WS2812_LOW;
  delay_us(400);
  for(x = 0;x < 24;x++){        //发送18字节数据；24 = 一个灯3字节数据*8个灯
      n = rgb_data[x];
      for(y = 0;y < 8;y++){
          z = ((n<<y)&0x80);
          if(z){
              WS2812_HIGH;        //灯的控制脚位设置为输出高
              delay_ns(1000);
              WS2812_LOW;
              delay_ns(400);    //灯的控制脚位设置为输出低
          }else{
              WS2812_HIGH;
              delay_ns(400);
              WS2812_LOW;
              delay_ns(1000);
          }
      }
  }
}


void send_code(){    //发送亮度数据

}

/* GPT初始化函数 */
void ws2812_pwm_init(void)
{
//    fsp_err_t err;
//    R_GPT_Open(&led_pwm_ctrl, &led_pwm_cfg);
//    R_GPT_Start(&led_pwm_ctrl);
//    err = R_DMAC_Open(&g_transfer_dmac0_ctrl, &g_transfer_dmac0_cfg);
//    transfer_info_t my_transfer_info_normal =
//    {
//        .transfer_settings_word_b.dest_addr_mode = TRANSFER_ADDR_MODE_FIXED,  //每次传输后，目标地址指针都会增加
//        .transfer_settings_word_b.repeat_area    = TRANSFER_REPEAT_AREA_SOURCE,     //源区域重复 (正常模式下无效)
//        .transfer_settings_word_b.irq            = TRANSFER_IRQ_END,                //传输完成后中断
//        .transfer_settings_word_b.chain_mode     = TRANSFER_CHAIN_MODE_DISABLED,    //不使能（DMAC没有该功能，仅DTC有）
//        .transfer_settings_word_b.src_addr_mode  = TRANSFER_ADDR_MODE_INCREMENTED,  //每次传输后，源地址指针都会增加
//        .transfer_settings_word_b.size           = TRANSFER_SIZE_4_BYTE,            //每次传输4字节
//        .transfer_settings_word_b.mode           = TRANSFER_MODE_NORMAL,            //正常传输模式
//        .p_dest                                  = (void *)(&(led_pwm_ctrl.p_reg->GTCCR[2])),             //目标地址
//        .p_src                                   = (void const *) WS2812_RGB_Buff,       //源地址
//        .num_blocks = 0,            //指定传输的块数（正常模式下无效，仅在重复、块或重复-块模式下有效）
//        .length     = 242,          //指定传输的长度（即正常和重复模式下的传输次数 或 块和重复-块模式下传输的块大小）
//    };
//    R_DMAC_Reconfigure(&g_transfer_dmac0_ctrl, &my_transfer_info_normal);
//    assert(FSP_SUCCESS == err);
//    R_DMAC_Enable(&g_transfer_dmac0_ctrl);
//    R_DMAC_SoftwareStart(&g_transfer_dmac0_ctrl, TRANSFER_START_MODE_SINGLE);
}

#if 0
void WS2812_Set(uint16_t num,uint8_t R,uint8_t G,uint8_t B)
{
  uint32_t indexx=(num*(3*8));
  for (uint8_t i = 0;i < 8;i++)
  {
    //填充数组
    WS2812_RGB_Buff[indexx+i]      = (G << i) & (0x80)?WS_H:WS_L;
    WS2812_RGB_Buff[indexx+i + 8]  = (R << i) & (0x80)?WS_H:WS_L;
    WS2812_RGB_Buff[indexx+i + 16] = (B << i) & (0x80)?WS_H:WS_L;
  }
}

// DMA 传输完成标志位
volatile bool dmac0_complete_transmission_sign = false;
/* DMAC 中断回调函数 */
void dmac0_callback(dmac_callback_args_t *p_args)
{
    (void)(p_args);
    dmac0_complete_transmission_sign = true;
}

void led_timer_update_event_callback(timer_callback_args_t * p_args)
{
    if (p_args->event == TIMER_EVENT_TROUGH)
    {
        //ws2812_flag = 1;
    }
}
#endif

#if 0

/** 设置PWM占空比
    @param duty 占空比范围：0~100 %
*/
void ws2812_pwm_setduty(uint8_t duty)
{
    timer_info_t info;
    uint32_t current_period_counts;
    uint32_t duty_cycle_counts;


    if (duty > 100)
        duty = 100; //限制占空比范围：0~100


    /* 获得GPT的信息 */
    R_GPT_InfoGet(&led_pwm_ctrl, &info);

    /* 获得计时器一个周期需要的计数次数 */
    current_period_counts = info.period_counts;

    /* 根据占空比和一个周期的计数次数计算GTCCR寄存器的值 */
    duty_cycle_counts = (uint32_t)(((uint64_t) current_period_counts * duty) / 100);


    /* 最后调用FSP库函数设置占空比 */
    R_GPT_DutyCycleSet(&led_pwm_ctrl, duty_cycle_counts, GPT_IO_PIN_GTIOCA);
}

// 编码一个字节的数据
void encode_byte(uint8_t byte, uint16_t *data)
{
    for (int i = 7; i >= 0; i--)
    {
        if ((byte >> i) & 0x01)
        {
            *data++ = T1H;
        }
        else
        {
            *data++ = T0H;
        }
    }
}

// 编码一个灯珠的RGB数据
void encode_led(uint8_t r, uint8_t g, uint8_t b, uint16_t *data)
{
    encode_byte(g, data);
    data += 8;
    encode_byte(r, data);
    data += 8;
    encode_byte(b, data);
}

// 设置某一位灯珠的颜色
void set_one_led(uint32_t index, uint8_t r, uint8_t g, uint8_t b)
{
    // 检查索引是否越界
    if (index >= LED_NUM) return;

    // 定位该LED在DMA缓冲区中的起始位置
    uint16_t *led_data = &ws2812_buffer[index * 24];

    // 按照 GRB 顺序编码
    encode_byte(g, led_data);     // 绿色
    encode_byte(r, led_data + 8); // 红色
    encode_byte(b, led_data + 16); // 蓝色
}

// 设置所有灯珠的颜色
void set_all_leds(uint8_t r, uint8_t g, uint8_t b)
{
    for (int i = 0; i < LED_NUM; i++)   // 0-9，每个标号代表一个灯珠的颜色数据
    {
        encode_led(r, g, b, &ws2812_buffer[i * 24]);
    }
}

void ws2812_start(void)
{
    ws2812_pwm_init();
    ws2812_pwm_setduty(0);
    R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MICROSECONDS);
    for (uint8_t index = 0; index < LED_DATA_LEN; index++)
    {
        if (ws2812_flag == 1)
        {
            ws2812_pwm_setduty((uint8_t)ws2812_buffer[index]);
            ws2812_flag = 0;
            if (index == 23)
            {
                ws2812_pwm_setduty(0);
            }
        }
    }
}

void ws2812_stop(void)
{
    R_GPT_Stop(&led_pwm_ctrl);
}

// 用pwm模拟ws2812时序
void led_timer_update_event_callback(timer_callback_args_t * p_args)
{
    if (p_args->event == TIMER_EVENT_TROUGH)
    {
        ws2812_flag = 1;
    }
}

#endif

