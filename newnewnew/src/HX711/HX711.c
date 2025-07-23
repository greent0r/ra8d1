#include "HX711.h"
#include "FreeRTOS.h"
#include "task.h"


uint32_t   buffer[MEDIAN_LEN];       //中值滤波的数据缓存
int   medleng = 0;              //一组中值滤波数据中,进入滤波缓存的数据个数
uint32_t   xd,xd1;                   //数据对比大小中间变量

uint32_t weight;                     //重量值
uint32_t pi_weight;              //皮重
uint32_t hx711_xishu=31706;      //这是一个修正系数，例如1000g砝码称出来是934g，则HX711_xishu=原数据*1000/934;

void HX711_Data_Out(void)
{
    if(R_IOPORT_PinCfg (&g_ioport_ctrl, BSP_IO_PORT_08_PIN_04, IOPORT_CFG_PORT_DIRECTION_OUTPUT | IOPORT_CFG_PORT_OUTPUT_HIGH)!=FSP_SUCCESS){
        printf("R_IOPORT_PinCfg failed\n");
    }
}

void HX711_Data_In(void)
{
    if(R_IOPORT_PinCfg (&g_ioport_ctrl, BSP_IO_PORT_08_PIN_04, IOPORT_CFG_PORT_DIRECTION_INPUT)!=FSP_SUCCESS){
        printf("R_IOPORT_PinCfg failed\n");
    }
}

uint32_t Read_HX711(void)
{
	uint8_t i;
	uint32_t value = 0;

	//vTaskSuspendAll();

//	HX711_Data_Out();
//	HX711_DATA_H;
//	delay_us(30);
	HX711_SCK_L;
	//vTaskDelay(1);
//	HX711_Data_In();

	while(HX711_DATA_IN != 0){
	    //vTaskDelay(1);
	}
	delay_us(30);
	//vTaskDelay(1);
	
	for(i=0; i<24; i++){
		HX711_SCK_H;
		//vTaskDelay(1);
		delay_us(30);
		HX711_SCK_L;
		if(HX711_DATA_IN == 0){
			value = value << 1;
			value |= 0x00;
		}
		else {
			value = value << 1;
			value |= 0x01;
		}
		delay_us(30);
		//vTaskDelay(1);
	}
	
	HX711_SCK_H;

	delay_us(30);
	//vTaskDelay(1);
	HX711_SCK_L;
	//vTaskDelay(1);
	delay_us(30);

//    if(xTaskResumeAll()){
//        taskYIELD();
//    }
	value = value^0x800000;
	return value; 	
}

void Get_Tare(void)//获取皮重
{
    uint32_t hx711_dat;
    uint8_t i;
    for(i=0;i<MEDIAN_LEN;i++)
    {
        hx711_dat=Read_HX711();             //HX711AD转换数据处理
        if(medleng == 0)                    //缓存的第1个元素,直接放入,不需要排序
        {
            buffer[0] = hx711_dat; medleng = 1;
        }
        else                                //插入排序算法,按从小到大的顺序排列
        {
            for(i = 0; i < medleng; i ++)
            {
                if( buffer[i] > hx711_dat)  // 轮询到的当前元素>AD值,则交换它们的值，xd为中间变量存放位置
                {
                    xd = hx711_dat; hx711_dat = buffer[i]; buffer[i] = xd;
                }
            }
            buffer[medleng] = hx711_dat;    //把轮询出较大的数放入缓存的后面.
            medleng++;
        }
        if(medleng >= MEDIAN_LEN)           //ADC采样的数据个数达到中值滤波要求的数据个数
        {
            hx711_dat = buffer[MEDIAN];     //最终重量取中值滤波数组的中间值
            medleng = 0;
        }
    }
    pi_weight=(unsigned short)(hx711_dat*0.01);
}

void Get_Weight()     //获取被测物体重量
{
    uint32_t hx711_data,a;
    uint32_t get,aa;
    hx711_data=Read_HX711();           //HX711数据采集函数
    get=(uint16_t)(hx711_data*0.01);   //HX711AD转换数据处理，数据缩小100倍
    if(get>pi_weight)
    {

        a=Read_HX711();            //重新采集HX711数据
        aa=(uint16_t)(a*0.01)-pi_weight;              //测得的重量值减去皮重
        weight=(uint16_t)((float)aa*0.00001*hx711_xishu);//重量转换函数，传感器型号不同此函数要适当修改（修改HX711_xishu的大小）
    }
    else{
        weight=0;
    }
}



