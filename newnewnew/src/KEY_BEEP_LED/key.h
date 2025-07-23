/*
 * key.h
 *
 *  Created on: 2025年6月11日
 *      Author: greentor
 */

#ifndef KEY_BEEP_KEY_H_
#define KEY_BEEP_KEY_H_

#include "platform.h"
#include "hal_data.h"

typedef struct{
    _Bool single_flag;
    _Bool double_flag;
    _Bool long_flag;
    uint8_t double_status;
    uint8_t status;
    uint32_t long_cnt;
    uint32_t double_cnt;
}KEY;


extern KEY key[4];



void key_init(void);



#endif /* KEY_BEEP_KEY_H_ */
