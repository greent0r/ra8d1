#include "max6675.h"
#include "FreeRTOS.h"
#include "task.h"


double temper;

unsigned int MAX6675_ReadReg(void)
{
    unsigned char i=0;
    unsigned int dat=0;

    //vTaskSuspendAll();

    MAX6675_CS_L;      //拉低片选开始传输
    MAX6675_SCK_L;    //拉低时钟准备传输
    delay_us(2);
    for(i=0; i<16; i++)
    {
        MAX6675_SCK_H;    //拉高时钟线
        delay_us(2);
        dat = dat<<1;
        if(MAX6675_SO==1) dat = dat|0x01;
        MAX6675_SCK_L;//拉低时钟结束传输
        delay_us(2);
    }
    MAX6675_CS_H;  //拉高片选，传输结束
    delay_us(4);

//    if(xTaskResumeAll()){
//        taskYIELD();
//    }

    return dat;
}

double read_temper()                 //读取温度
{
    unsigned int d;
    d = MAX6675_ReadReg();          //读取当前温度
    d = d<<1;                //去掉伪符号位
    if(d&0x08)  //MAX6675是否在线
        printf("no temp");
    temper = ((d>>4)&0x0fff)*0.25;
    //printf("temper=%f\r\n",temper);
    return temper;
}

