/*
 * gt911.c
 *
 *  Created on: 2025年6月23日
 *      Author: Admin
 */

#include "gt911.h"

#if 1
/* 定义触摸控制结构体 */
TouchStructure TouchInfo = {
    0,
    0,
    0,
    0,
    0,
};

/* 定义触摸点地址 */
const uint16_t TPX[] = {0x8150, 0x8158, 0x8160, 0x8168, 0x8170};
/* 定义触摸点的颜色 */
//const uint16_t POINT_COLOR_TBL[TOUCH_MAX] = {RED, GREEN, BLUE, GRAY, WHITE};

void GT_INT_IRQHandler(external_irq_callback_args_t *p_args)
{
    //GT_INTScan();
}

/**
 * @brief 向 GT911 的指定寄存器写入一个字节数据
 * @param addr: 要写入的寄存器地址（16位）
 * @param data: 要写入的数据（8位）
 * @return uint8_t: 成功返回1，失败返回0
 */
uint8_t gt9xx_WR_DATA(uint16_t addr, uint8_t data)
{
//    fsp_err_t err;
//    uint8_t tx_buffer[3];  // 地址高位、地址低位、数据字节
//
//    // 设置从设备地址（GT911 写地址）
//    err = R_IIC_MASTER_SlaveAddressSet(&i2c_master_ctrl, GT_DEV_ADDR, I2C_MASTER_ADDR_MODE_7BIT);
//    if (FSP_SUCCESS != err)
//    {
//        return 0;  // 地址设置失败
//    }
//
//    // 构造发送缓冲区：[addr_high][addr_low][data]
//    tx_buffer[0] = (uint8_t)(addr >> 8);  // 高位地址
//    tx_buffer[1] = (uint8_t)addr;         // 低位地址
//    tx_buffer[2] = data;                  // 要写入的数据
//
//    // 发送数据（包含寄存器地址 + 数据）
//    err = R_IIC_MASTER_Write(&i2c_master_ctrl, tx_buffer, 3, false);  // true 表示发送 STOP
//    if (FSP_SUCCESS != err)
//    {
//        return 0;  // 写操作失败
//    }
    MyI2C_Start();
    MyI2C_SendByte(GT_Write_Addr);
    MyI2C_ReceiveAck();
    MyI2C_SendByte((uint8_t)(addr >> 8));
    MyI2C_ReceiveAck();
    MyI2C_SendByte((uint8_t)addr);
    MyI2C_ReceiveAck();
    MyI2C_SendByte(data);
    MyI2C_ReceiveAck();
    MyI2C_Stop();

    return 1;  // 成功
}

/**
 * @brief  使用 BSP 库 I2C 向 GT911 指定地址读取数据
 * @param  addr   : 要读取的寄存器地址（16位）
 * @param  value  : 存放读取结果的缓冲区
 * @param  len    : 要读取的字节数
 * @return uint8_t: 成功返回0，失败返回非0
 */
uint8_t gt9xx_RD_DATA(uint16_t addr, uint8_t len, uint8_t *value)
{
//    fsp_err_t err;
//    uint8_t tx_buffer[2];
//
//    R_IIC_MASTER_SlaveAddressSet(&i2c_master_ctrl, GT_DEV_ADDR, I2C_MASTER_ADDR_MODE_7BIT);
//    // 步骤一：发送寄存器地址（2字节）
//    tx_buffer[0] = (addr >> 8) & 0xFF;  // 高位地址
//    tx_buffer[1] = addr & 0xFF;         // 低位地址
//
//    // 发送寄存器地址
//    err = R_IIC_MASTER_Write(&i2c_master_ctrl, tx_buffer, 2, false);
//    if (FSP_SUCCESS != err)
//    {
//        return 1;  // 写失败
//    }
//
//    // 步骤二：读取数据
//    err = R_IIC_MASTER_Read(&i2c_master_ctrl, value, len, false);  // 最后一个参数是否发送 STOP
//    if (FSP_SUCCESS != err)
//    {
//        return 1;  // 读失败
//    }
//
//    return 0;  // 成功
    uint8_t i;
    MyI2C_Start();
    MyI2C_SendByte(GT_Write_Addr); // 发送写指令
    MyI2C_ReceiveAck();
    MyI2C_SendByte((uint8_t)(addr >> 8));
    MyI2C_ReceiveAck();
    MyI2C_SendByte((uint8_t)addr);
    MyI2C_ReceiveAck();
    MyI2C_Start();
    MyI2C_SendByte(GT_Read_Addr);
    MyI2C_ReceiveAck();
    for (i = 0; i < len; i++){
        if (i == (len - 1)){
            value[i] = MyI2C_ReceiveByte();
            MyI2C_SendAck(0);
        }
        else{
            value[i] = MyI2C_ReceiveByte();
            MyI2C_SendAck(1);
        }
    }
    MyI2C_Stop();
    return 0;
}

void gt9xx_Init(void)
{
    uint8_t gt9xx_Info[11];
    uint8_t gt9xx_Version = 0;
    R_IOPORT_PinCfg(&g_ioport_ctrl, GT_INT_GPIO_PIN, IOPORT_CFG_PORT_DIRECTION_OUTPUT | IOPORT_CFG_PORT_OUTPUT_HIGH);
    R_IOPORT_PinCfg(&g_ioport_ctrl, GT_RST_GPIO_PIN, IOPORT_CFG_PORT_DIRECTION_OUTPUT | IOPORT_CFG_PORT_OUTPUT_HIGH);
    GT_RST_Clr();
    GT_INT_Clr();
    vTaskDelay(15);
    GT_INT_Clr();
    vTaskDelay(1);
    GT_RST_Set();
    vTaskDelay(15);
    R_IOPORT_PinCfg(&g_ioport_ctrl, GT_INT_GPIO_PIN, IOPORT_CFG_PORT_DIRECTION_INPUT);
    //R_IOPORT_PinCfg(&g_ioport_ctrl, GT_INT_GPIO_PIN, IOPORT_CFG_IRQ_ENABLE);
    //R_ICU_ExternalIrqCallbackSet(&g_external_irq4_ctrl, GT_INT_IRQHandler, 0, NULL);
    //R_ICU_ExternalIrqOpen(&g_external_irq4_ctrl, &g_external_irq4_cfg);
    //R_ICU_ExternalIrqEnable(&g_external_irq4_ctrl);
    gt9xx_RD_DATA(GT_ID_Addr, 11, gt9xx_Info);
    gt9xx_RD_DATA(GT_CFG_Addr, 1, &gt9xx_Version);
    if (gt9xx_Info[0] == '9'){ // 判断第一个字符是否为 9
        printf("Touch ID: GT%.4s \r\n", gt9xx_Info);                                                                   // 打印触摸芯片的ID
        //printf("固件版本： 0X%.4x\r\n", (gt9xx_Info[5] << 8) + gt9xx_Info[4]);                                         // 芯片固件版本
        //printf("触摸分辨率：%d * %d\r\n", (gt9xx_Info[7] << 8) + gt9xx_Info[6], (gt9xx_Info[9] << 8) + gt9xx_Info[8]); // 当前触摸分辨率
        //printf("触摸参数配置版本： 0X%.2x \r\n", gt9xx_Version);                                                       // 触摸配置版本
    }
    else{
        printf("Touch Error\r\n"); // 错误，未检测到触摸屏
    }
}

void GT_INTScan(void)
{
    uint8_t touchData[2 + 8 * TOUCH_MAX]; // 用于存储触摸数据
    uint8_t i = 0;
    gt9xx_RD_DATA(0x814E, 2 + 8 * TOUCH_MAX, touchData); // 读数据
    gt9xx_WR_DATA(0x814E, 0);                            // 清除触摸芯片的寄存器标志位
    TouchInfo.num = touchData[0] & 0x0f;                 // 取当前的触摸点数

    if ((TouchInfo.num >= 1) && (TouchInfo.num <= 5)) //  当触摸数在 1-5 之间时
    {
        for (i = 0; i < TouchInfo.num; i++) // 取相应的触摸坐标
        {
            if (USE_HORIZONTAL == 0)
            {
                TouchInfo.x[i] = LCD_H - ((touchData[5 + 8 * i] << 8) | touchData[4 + 8 * i]); // 获取X坐标
                TouchInfo.y[i] = ((touchData[3 + 8 * i] << 8) | touchData[2 + 8 * i]);         // 获取Y坐标
            }
            else if (USE_HORIZONTAL == 1)
            {
                TouchInfo.x[i] = (touchData[3 + 8 * i] << 8) | touchData[2 + 8 * i]; // 获取X坐标
                TouchInfo.y[i] = (touchData[5 + 8 * i] << 8) | touchData[4 + 8 * i]; // 获取Y坐标
            }
            else if (USE_HORIZONTAL == 2)
            {
                TouchInfo.x[i] = (touchData[5 + 8 * i] << 8) | touchData[4 + 8 * i];           // 获取X坐标
                TouchInfo.y[i] = LCD_V - ((touchData[3 + 8 * i] << 8) | touchData[2 + 8 * i]); // 获取Y坐标
            }
            else
            {
                TouchInfo.x[i] = LCD_H - ((touchData[3 + 8 * i] << 8) | touchData[2 + 8 * i]); // 获取X坐标
                TouchInfo.y[i] = LCD_V - ((touchData[5 + 8 * i] << 8) | touchData[4 + 8 * i]); // 获取Y坐标
            }
            //printf("x[%d]:%d,y[%d]:%d\r\n", i, TouchInfo.x[i], i, TouchInfo.y[i]);
        }
        TouchInfo.flag = 1; // 触摸标志位置1，代表有触摸动作发生
    }
    else
    {
        TouchInfo.flag = 0; // 触摸标志位置0，无触摸动作
    }
}

void gt9xx_Scan()
{
    uint8_t buf[4];
    uint8_t i = 0;
    uint8_t temp;
    uint8_t tempsta;
    static uint8_t mode;
    static uint8_t t = 0; // 控制查询间隔,从而降低CPU占用率
    t++;
    if ((t % 10) == 0 || t < 10) // 空闲时,每进入10次CTP_Scan函数才检测1次,从而节省CPU使用率
    {
        gt9xx_RD_DATA(GT_Point_Addr, 1, &mode);
        if ((mode & 0X80))// && ((mode & 0XF) < 6))
        {
            temp = 0;
            gt9xx_WR_DATA(GT_Point_Addr, temp);
        }
        if ((mode & 0XF) && ((mode & 0XF) < 6))
        {
            temp = 0XFF << (mode & 0XF); // 将点的个数转换为1的位数,匹配TouchInfo.sta定义
            tempsta = TouchInfo.sta;     // 保存当前的TouchInfo.sta值
            TouchInfo.sta = (~temp) | TP_PRES_DOWN | TP_CATH_PRES;
            TouchInfo.x[4] = TouchInfo.x[0]; // 保存触点0的数据
            TouchInfo.y[4] = TouchInfo.y[0];
            for (i = 0; i < 5; i++)
            {
                if (TouchInfo.sta & (1 << i)) // 触摸有效?
                {
                    gt9xx_RD_DATA(TPX[i], 4, buf); // 读取XY坐标值
                    if (USE_HORIZONTAL == 0)
                    {

                        TouchInfo.x[i] = LCD_H - (((uint16_t)buf[3] << 8) + buf[2]);
                        TouchInfo.y[i] = (((uint16_t)buf[1] << 8) + buf[0]);
                    }
                    else if (USE_HORIZONTAL == 1)
                    {
                        TouchInfo.x[i] = (((uint16_t)buf[1] << 8) + buf[0]);
                        TouchInfo.y[i] = (((uint16_t)buf[3] << 8) + buf[2]);
                    }
                    else if (USE_HORIZONTAL == 2)
                    {
                        TouchInfo.x[i] = (((uint16_t)buf[3] << 8) + buf[2]);
                        TouchInfo.y[i] = LCD_V - (((uint16_t)buf[1] << 8) + buf[0]);
                    }
                    else
                    {
                        TouchInfo.x[i] = LCD_H - (((uint16_t)buf[1] << 8) + buf[0]);
                        TouchInfo.y[i] = LCD_V - (((uint16_t)buf[3] << 8) + buf[2]);
                    }
                    //printf("x[%d]:%d,y[%d]:%d\r\n", i, TouchInfo.x[i], i, TouchInfo.y[i]);
                }
            }
            if (TouchInfo.x[0] > LCD_H || TouchInfo.y[0] > LCD_V) // 非法数据(坐标超出了)
            {
                if ((mode & 0XF) > 1) // 有其他点有数据,则复第二个触点的数据到第一个触点.
                {
                    TouchInfo.x[0] = TouchInfo.x[1];
                    TouchInfo.y[0] = TouchInfo.y[1];
                    t = 0; // 触发一次,则会最少连续监测10次,从而提高命中率
                }
                else // 非法数据,则忽略此次数据(还原原来的)
                {
                    TouchInfo.x[0] = TouchInfo.x[4];
                    TouchInfo.y[0] = TouchInfo.y[4];
                    mode = 0X80;
                    TouchInfo.sta = tempsta; // 恢复TouchInfo.sta
                }
            }
            else
                t = 0; // 触发一次,则会最少连续监测10次,从而提高命中率
        }
    }
    if ((mode & 0X8F) == 0X80) // 无触摸点按下
    {
        if (TouchInfo.sta & TP_PRES_DOWN) // 之前是被按下的
        {
            TouchInfo.sta &= ~(1 << 7); // 标记按键松开
        }
        else // 之前就没有被按下
        {
            TouchInfo.x[0] = 0xffff;
            TouchInfo.y[0] = 0xffff;
            TouchInfo.sta &= 0XE0; // 清除点有效标记
        }
    }
    if (t > 240)
        t = 10; // 重新从10开始计数
}


#endif
