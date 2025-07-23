/*
 * snr9816.h
 *
 *  Created on: 2025年6月24日
 *      Author: Admin
 */

#ifndef SNR9816_SNR9816_H_
#define SNR9816_SNR9816_H_

#include "hal_data.h"

void snr_init(void);
int snr_printf(const char *format, ...);
void snr_say_sentence(char *sentence, uint8_t len);
void soft_uart_write(const uint8_t *data, size_t len);
void snr_man_women(bool man);
void snr_stop(void);
void snr_voice(uint8_t voice);

#endif /* SNR9816_SNR9816_H_ */
