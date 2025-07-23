#include "MQ4_MQ5.h"


//ADC转换完成标志位
volatile bool scan_complete_flag = false;



void adc_init(void)
{
   fsp_err_t err;
   err = R_ADC_Open(&g_adc0_ctrl, &g_adc0_cfg);
   err = R_ADC_ScanCfg(&g_adc0_ctrl, &g_adc0_channel_cfg);
   assert(FSP_SUCCESS == err);
}

void adc_callback(adc_callback_args_t * p_args)
{
   FSP_PARAMETER_NOT_USED(p_args);
   scan_complete_flag = true;
}

/* 进行ADC采集，读取ADC数据并转换结果 */
double Read_ADC_Voltage_Value(adc_channel_t ch)
{
   uint16_t adc_data;
   double a;

   (void)R_ADC_ScanStart(&g_adc0_ctrl);
   while (!scan_complete_flag){} //等待转换完成标志
   scan_complete_flag = false; //重新清除标志位

   R_ADC_Read(&g_adc0_ctrl, ch, &adc_data);
   a = (double)(adc_data*3.3/4095);

   return a;
}
