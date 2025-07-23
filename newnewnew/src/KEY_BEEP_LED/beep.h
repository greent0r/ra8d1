/*
 * beep.h
 *
 *  Created on: 2025年6月11日
 *      Author: greentor
 */

#ifndef KEY_BEEP_BEEP_H_
#define KEY_BEEP_BEEP_H_

#include "platform.h"
#include "hal_data.h"



void beep_pwm_init(void);
void beep_pwm_setduty(uint8_t duty);

void beep_start(void);
void beep_stop(void);


#endif /* KEY_BEEP_BEEP_H_ */
