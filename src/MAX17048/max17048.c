/*
 * max17048.c
 *
 *  Created on: 2025年6月18日
 *      Author: Phantasia
 */

#include "max17048.h"
#include "hal_data.h"
#include "stdio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "platform.h"

uint16_t Battery_Soc = 0;        /**< 电池电量百分比*/
uint16_t Battery_Voltage = 0;    /**< 电池电压*/
uint8_t Send_Val_Buf[2];
uint8_t Reg_Val_Buf[2];

#if ENABLE_MAX17048_DEBUG
    void Display_Alarm_Info(uint8_t Alarm_Value);
#endif

void max17048_WriteReg(uint8_t reg, uint16_t data){


    MyI2C_Start();
    MyI2C_SendByte(DEV_ADDR_WRITE);
    if(MyI2C_ReceiveAck()!=0) printf("no ack\n");
    MyI2C_SendByte(reg);
    if(MyI2C_ReceiveAck()!=0) printf("no ack\n");
    MyI2C_SendByte(data>>8);
    if(MyI2C_ReceiveAck()!=0) printf("no ack\n");
    MyI2C_SendByte(data&0xff);
    if(MyI2C_ReceiveAck()!=0) printf("no ack\n");
    MyI2C_Stop();
}

void max17048_ReadReg(uint8_t reg, uint16_t* data){
    MyI2C_Start();
    MyI2C_SendByte(DEV_ADDR_WRITE);
    if(MyI2C_ReceiveAck()!=0) printf("no ack\n");
    MyI2C_SendByte(reg);
    if(MyI2C_ReceiveAck()!=0) printf("no ack\n");
    MyI2C_Start();
    MyI2C_SendByte(DEV_ADDR_READ);
    if(MyI2C_ReceiveAck()!=0) printf("no ack\n");
    *data = MyI2C_ReceiveByte()<<8;
    MyI2C_SendAck(1);
    *data |= MyI2C_ReceiveByte();
    MyI2C_SendAck(0);
    MyI2C_Stop();
}

void max17048_init(){
    uint16_t data=0;
    max17048_ReadReg(REG_STATUS, &data);
    data &= ~((0x01 & 0x3F) << 8);
    max17048_WriteReg(REG_STATUS, data);
    max17048_ReadReg(REG_VERSION, &data);
    printf("version=%x\n",data);
}

void max17048_update(){
    uint16_t data=0;
    //max17048_ReadReg(REG_V_CELL, &data);
    //double vcell = (data*10)>>7;
    max17048_ReadReg(REG_SOC, &data);
    Battery_Soc = data>>8;
    //max17048_ReadReg(REG_STATUS, &data);
    //uint16_t status = (data>>8) & 0x3F;
    //printf("status=%x,vcell=%.0fmV,soc=%d\%\n",status,vcell,soc);
}


#if 0

void I2C_State_Reset(void)
{
    //R_IIC_MASTER_Close(&i2c_master_ctrl);
    vTaskDelay(1);
    //R_IIC_MASTER_Open(&i2c_master_ctrl, &i2c_master_cfg);
}

void Power_On_Reset(void)
{
    /* 复位上电 */
    uint8_t WriteData[3] = {REG_CMD, 0x54, 0x00};
    //fsp_err_t err=R_IIC_MASTER_SlaveAddressSet(&i2c_master_ctrl, DEV_ADDR, I2C_MASTER_ADDR_MODE_7BIT);
    //if(err!=FSP_SUCCESS)printf("err result=%d\n",err);
    //err=R_IIC_MASTER_Write(&i2c_master_ctrl, WriteData, 3, true);
    i2c_write(DEV_ADDR, WriteData, 3);
    //if(err!=FSP_SUCCESS)printf("err result=%d\n",err);
    //while(!iic_tx_done){}
    //iic_tx_done=0;

    /* wait */
    vTaskDelay(100);;

    /* 快速启动 */
    WriteData[0] = REG_MODE;
    WriteData[1] = 0x00;
    WriteData[2] |= REG_BIT6;

    /* 使能休眠模式 */
    //R_IIC_MASTER_SlaveAddressSet(&i2c_master_ctrl, DEV_ADDR, I2C_MASTER_ADDR_MODE_7BIT);
    //err=R_IIC_MASTER_Write(&i2c_master_ctrl, WriteData, 3, false);
    i2c_write(DEV_ADDR, WriteData, 3);
    //if(err!=FSP_SUCCESS)printf("err result=%d\n",err);
    //while(!iic_tx_done){}
    //iic_tx_done=0;
}

void Alarm_State_Reset(void)
{
    uint8_t RegData = 0;
    uint8_t RecData[2] = {0};
    uint8_t SendData[3] = {0};

    /* 读取报警状态信息 */
    RegData = REG_STATUS;
    //R_IIC_MASTER_SlaveAddressSet(&i2c_master_ctrl, DEV_ADDR, I2C_MASTER_ADDR_MODE_7BIT);
    //R_IIC_MASTER_Write(&i2c_master_ctrl, &RegData, 1, false);
    //while(!iic_tx_done){}
    //iic_tx_done=0;
    //R_IIC_MASTER_Read(&i2c_master_ctrl, RecData, 2, false);
    //while(!iic_rx_done){}
    //iic_rx_done=0;

#if ENABLE_MAX17048_DEBUG
  	printf("Status REG:%02X:VAL:%02X%02X.\r\n", RegData, RecData[0], RecData[1]);
  	Display_Alarm_Info(RecData[0]);
#endif

    /*清除报警信息*/
    SendData[0] = RegData;
    SendData[1] = (RecData[0]&(~0x7F));
    SendData[2] = RecData[1];
    //R_IIC_MASTER_Write(&i2c_master_ctrl, (uint8_t*)&SendData, 3, false);
    //while(!iic_tx_done){}
    //iic_tx_done=0;

#if ENABLE_MAX17048_DEBUG
    printf("Set Status REG:%02X:VAL:%02X%02X.\r\n", RegData, SendData[1], SendData[2]);
#endif
#if ENABLE_MAX17048_DEBUG
    R_IIC_MASTER_Write(&i2c_master_ctrl, &RegData, 1, false);
    //while(!iic_tx_done){}
    //iic_tx_done=0;
    R_IIC_MASTER_Read(&i2c_master_ctrl, RecData, 2, false);
    //while(!iic_rx_done){}
    //iic_rx_done=0;
    printf("After Status REG:%02X:VAL:%02X%02X.\r\n", RegData, RecData[0], RecData[1]);
#endif

    /* 读取配置信息 */
    RegData = REG_CONFIG;
    //R_IIC_MASTER_Write(&i2c_master_ctrl, &RegData, 1, false);
    //while(!iic_tx_done){}
    //iic_tx_done=0;
    //R_IIC_MASTER_Read(&i2c_master_ctrl, RecData, 2, false);
    //while(!iic_rx_done){}
    //iic_rx_done=0;
#if ENABLE_MAX17048_DEBUG
    printf("Config REG:%02X:VAL:%02X%02X.\r\n", RegData, RecData[0], RecData[1]);
#endif
    /*设置报警阈值 BIT0-4 可设范围1-32% 设置10%则32-10*/
    RecData[1] = ((RecData[1]&0xE0)|(32-10));
    /*清除报警状态位 BIT5*/
    RecData[1] &= (~REG_BIT5);
    SendData[0] = RegData;
    SendData[1] = RecData[0];
    SendData[2] = RecData[1];
    //R_IIC_MASTER_Write(&i2c_master_ctrl, SendData, 3, false);
    //while(!iic_tx_done){}
    //iic_tx_done=0;
#if ENABLE_MAX17048_DEBUG
    printf("Set Config REG:%02X:VAL:%02X%02X.\r\n", RegData, SendData[1], SendData[2]);
#endif
#if ENABLE_MAX17048_DEBUG
    R_IIC_MASTER_Write(&i2c_master_ctrl, &RegData, 1, false);
    //while(!iic_tx_done){}
    //iic_tx_done=0;
    R_IIC_MASTER_Read(&i2c_master_ctrl, RecData, 2, false);
    //while(!iic_rx_done){}
    //iic_rx_done=0;
    printf("After Config REG:%02X:VAL:%02X%02X.\r\n", RegData, RecData[0], RecData[1]);
#endif

    /*读取版本信息*/
#if ENABLE_MAX17048_DEBUG
    RegData = REG_VERSION;
    R_IIC_MASTER_Write(&i2c_master_ctrl, &RegData, 1, false);
    //while(!iic_tx_done){}
    //iic_tx_done=0;
    R_IIC_MASTER_Read(&i2c_master_ctrl, RecData, 2, false);
    //while(!iic_rx_done){}
    //iic_rx_done=0;
    printf("Version REG:%02X:VAL:%02X%02X.\r\n", RegData, RecData[0], RecData[1]);
#endif
}

uint16_t Read_Vcell_Update(void)
{
    fsp_err_t err;
    Send_Val_Buf[0] = REG_V_CELL;
    //err=R_IIC_MASTER_SlaveAddressSet(&i2c_master_ctrl, DEV_ADDR, I2C_MASTER_ADDR_MODE_7BIT);\
    //if(err!=FSP_SUCCESS)printf("err result=%d\n",err);
    //err=R_IIC_MASTER_Write(&i2c_master_ctrl, Send_Val_Buf, 1, false);
    //if(err!=FSP_SUCCESS)printf("err result=%d\n",err);
    i2c_write(DEV_ADDR, Send_Val_Buf, 1);
    //while(!iic_tx_done){}
    //iic_tx_done=0;
    //err=R_IIC_MASTER_Read(&i2c_master_ctrl, Reg_Val_Buf, 2, false);
    i2c_read(DEV_ADDR, Reg_Val_Buf, 2);
    //if(err!=FSP_SUCCESS)printf("err result=%d\n",err);
    //while(!iic_rx_done){}
    //iic_rx_done=0;
//    if(FSP_SUCCESS != R_IIC_MASTER_Write(&i2c_master_ctrl, Send_Val_Buf, 1, false))
//    {
//        printf("iic write error\n");
//        return Battery_Voltage;
//    }
//    if(FSP_SUCCESS != R_IIC_MASTER_Read(&i2c_master_ctrl, Reg_Val_Buf, 2, false))
//    {
//        printf("iic read error\n");
//        return Battery_Voltage;
//    }

    printf("Reg_Val_Buf=%d\n",((Reg_Val_Buf[0]<<8)+Reg_Val_Buf[1]));
    Battery_Voltage = (uint16_t)((Reg_Val_Buf[0]<<8)+Reg_Val_Buf[1]);
    Battery_Voltage = (uint16_t)(((double)Battery_Voltage * 78.125)/1000000);

    return Battery_Voltage;
}

uint16_t Read_Soc_Update(void)
{
    Send_Val_Buf[0] = REG_SOC;
    //R_IIC_MASTER_SlaveAddressSet(&i2c_master_ctrl, DEV_ADDR, I2C_MASTER_ADDR_MODE_7BIT);
    //R_IIC_MASTER_Write(&i2c_master_ctrl, Send_Val_Buf, 1, false);
    //while(!iic_tx_done){}
    //iic_tx_done=0;
    //R_IIC_MASTER_Read(&i2c_master_ctrl, Reg_Val_Buf, 2, false);
    //while(!iic_rx_done){}
    //iic_rx_done=0;
    //    if(FSP_SUCCESS != R_IIC_MASTER_Write(&i2c_master_ctrl, Send_Val_Buf, 1, false))
//    {
//        I2C_State_Reset();
//        return Battery_Soc;
//    }
//    if(FSP_SUCCESS != R_IIC_MASTER_Read(&i2c_master_ctrl, Reg_Val_Buf, 2, false))
//    {
//        return Battery_Soc;
//    }
    // 合并高位和低位，并转换为百分比
    uint16_t Battery_Soc_Temp = (uint16_t)((Reg_Val_Buf[0]<<8) + Reg_Val_Buf[1]);
    Battery_Soc_Temp /= 256;
    Battery_Soc = Battery_Soc_Temp > 100?100:Battery_Soc_Temp;

    return Battery_Soc;
}


//void Voltameter_Port_IIC_Callback(i2c_master_callback_args_t *p_args)
//{
//    switch (p_args->event)
//    {
//        case I2C_MASTER_EVENT_RX_COMPLETE:
//        {
////            if (Send_Val_Buf[0] == REG_V_CELL)
////            {
////                uint16_t Battery_Voltage_Temp = (uint16_t)((Reg_Val_Buf[0]<<8)+Reg_Val_Buf[1]);
////                Battery_Voltage_Temp = (uint16_t)(((double)Battery_Voltage_Temp * 78.125)/1000000);
////                Battery_Voltage = Battery_Voltage_Temp;
////            }
////            else if (Send_Val_Buf[0] == REG_SOC)
////            {
////                uint16_t Battery_Soc_Temp = (uint16_t)((Reg_Val_Buf[0]<<8) + Reg_Val_Buf[1]);
////                Battery_Soc_Temp /= 256;
////                Battery_Soc = Battery_Soc_Temp > 100?100:Battery_Soc_Temp;
////            }
//            break;
//        }
//        case I2C_MASTER_EVENT_TX_COMPLETE:
//        {
//            break;
//        }
//        default:break;
//    }
//}

uint16_t Voltameter_Port_Get_Battery_Electric_Quantity(void)
{
    Read_Soc_Update();
    Read_Vcell_Update();
    return Battery_Soc;
}

void Voltameter_Port_OnOff_Sleep(bool Sleep_En)
{
    uint8_t RegData = 0;
    uint8_t RecData[2] = {0};
    uint8_t SendData[3] = {0};

    /*读取配置信息*/
    RegData = REG_CONFIG;
    //R_IIC_MASTER_SlaveAddressSet(&i2c_master_ctrl, DEV_ADDR, I2C_MASTER_ADDR_MODE_7BIT);
    //R_IIC_MASTER_Write(&i2c_master_ctrl, &RegData, 1, false);
    i2c_write(DEV_ADDR, &RegData, 1);
    //while(!iic_tx_done){}
    //iic_tx_done=0;
    //R_IIC_MASTER_Read(&i2c_master_ctrl, RecData, 1, false);
    i2c_read(DEV_ADDR, RecData, 1);
    //while(!iic_rx_done){}
    //iic_rx_done=0;
#if ENABLE_MAX17048_DEBUG
    printf("Config REG:%02X:VAL:%02X%02X.\r\n", RegData, RecData[0], RecData[1]);
#endif

    SendData[1] = RegData;
    SendData[1] = RecData[0];
    SendData[2] = RecData[1];

    if(Sleep_En == true)
    {
        /*进入休眠 config.sleep = 1*/
        SendData[1] |= REG_BIT7;
    }
    else
    {
        /*退出休眠 config.sleep = 0*/
        SendData[1] &= ~REG_BIT7;
    }

    //R_IIC_MASTER_Write(&i2c_master_ctrl, SendData, 3, false);
    i2c_write(DEV_ADDR, SendData, 3);
    //while(!iic_tx_done){}
    //iic_tx_done=0;
}

void Voltameter_Port_Init(void)
{
    /*上电复位MAX17048*/
    Power_On_Reset();

    /*报警复位*/
    //Alarm_State_Reset();
}

#endif
