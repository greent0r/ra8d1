#include "key.h"


KEY key[4]={0};


/* GPT 初始化函数 */
void key_init(void)
{
    /* 初始化 GPT0 模块 */
    R_GPT_Open(&timer13_ctrl, &timer13_cfg);
    /* 启动 GPT0 定时器 */
    R_GPT_Start(&timer13_ctrl);
}

/* GPT 中断回调函数 */
void timer13_callback(timer_callback_args_t * p_args)
{
    /* 定时器溢出事件 */
    if (TIMER_EVENT_CYCLE_END == p_args->event){
        _Bool key_in[4];
        key_in[0]=R_BSP_PinRead(BSP_IO_PORT_10_PIN_06);
        key_in[1]=R_BSP_PinRead(BSP_IO_PORT_10_PIN_05);
        key_in[2]=R_BSP_PinRead(BSP_IO_PORT_10_PIN_02);
        key_in[3]=R_BSP_PinRead(BSP_IO_PORT_10_PIN_03);
        for(int i=0;i<4;i++){
            switch(key[i].status){
                case 0:
                    if(key_in[i]==0)
                        key[i].status=1;
                    break;
                case 1:
                    if(key_in[i]==0){
                        key[i].status=2;
                        key[i].long_cnt=0;
                    }
                    else{
                        key[i].status=0;
                    }
                    break;
                case 2:
                    if(key_in[i]==0){
                        key[i].long_cnt++;
                    }
                    else if(key_in[i]==1 && key[i].long_cnt>100){
                        key[i].long_flag=1;
                        key[i].status=0;
                    }
                    else if(key_in[i]==1 && key[i].long_cnt<=100){
                        if(key[i].double_status==0){
                            key[i].double_status=1;
                            key[i].double_cnt=0;
                        }
                        else{
                            key[i].double_flag=1;
                            key[i].double_status=0;
                        }
                        key[i].status=0;
                    }
                    break;
            }
            if(key[i].double_status==1){
                key[i].double_cnt++;
                if(key[i].double_cnt>=35){
                    key[i].single_flag=1;
                    key[i].double_status=0;
                }
            }

        }
    }
}






