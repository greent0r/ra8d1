/*
 * sd.h
 *
 *  Created on: 2025Äê6ÔÂ19ÈÕ
 *      Author: greentor
 */

#ifndef FILE_SD_H_
#define FILE_SD_H_

#include "hal_data.h"
#include "platform.h"

 extern __IO uint32_t g_transfer_complete;
 extern __IO uint32_t g_card_erase_complete;
 extern __IO bool g_card_inserted;

 extern sdmmc_device_t my_sdmmc_device;

 void SDCard_Init(void);
 void SDCard_Operation(void);


#endif /* FILE_SD_H_ */
