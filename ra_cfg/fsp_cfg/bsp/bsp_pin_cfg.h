/* generated configuration header file - do not edit */
#ifndef BSP_PIN_CFG_H_
#define BSP_PIN_CFG_H_
#include "r_ioport.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#define USER_SW (BSP_IO_PORT_00_PIN_08)
#define USER_LED (BSP_IO_PORT_10_PIN_01)
extern const ioport_cfg_t g_bsp_pin_cfg; /* RA8D1_CPKCOR.pincfg_1 */

void BSP_PinConfigSecurityInit();

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER
#endif /* BSP_PIN_CFG_H_ */
