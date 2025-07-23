/*
 * malloc.h
 *
 *  Created on: 2025年7月5日
 *      Author: greentor
 */

#ifndef MYMALLOC_H_
#define MYMALLOC_H_


#ifndef _MALLOC_H
#define _MALLOC_H
#include "hal_data.h"
//////////////////////////////////////////////////////////////////////////////////
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F7开发板
//内存管理 驱动代码
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2015/12/12
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////
#define MEM_BLOCK_SIZE         64                              //内存块大小为64字节
#define MEM_MAX_SIZE           4096 * 1024                     //最大管理内存
#define MEM_ALLOC_TABLE_SIZE   MEM_MAX_SIZE/MEM_BLOCK_SIZE   //内存表大小

//内存管理控制器
struct _m_mallco_dev
{
    void (*init)();                   //初始化
    uint16_t (*perused)();                 //内存使用率
    uint8_t  *membase;             //内存池 管理SRAMBANK个区域的内存
    uint32_t *memmap;              //内存管理状态表
    uint8_t   memrdy;               //内存管理是否就绪
};

extern struct _m_mallco_dev mallco_dev;  //在mallco.c里面定义

void mymemset(void *s,uint8_t c,uint32_t count);  //设置内存
void mymemcpy(void *des,void *src,uint32_t n);//复制内存
void my_mem_init();              //内存管理初始化函数(外/内部调用)
uint32_t my_mem_malloc(uint32_t size);    //内存分配(内部调用)
uint8_t my_mem_free(uint32_t offset);     //内存释放(内部调用)
uint16_t my_mem_perused();           //获得内存使用率(外/内部调用)
////////////////////////////////////////////////////////////////////////////////
//用户调用函数
void myfree(void *ptr);             //内存释放(外部调用)
void *mymalloc(uint32_t size);           //内存分配(外部调用)
void *myrealloc(void *ptr,uint32_t size);//重新分配内存(外部调用)
#endif



#endif /* MYMALLOC_H_ */
