/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = sci_b_uart_rxi_isr, /* SCI3 RXI (Receive data full) */
            [1] = sci_b_uart_txi_isr, /* SCI3 TXI (Transmit data empty) */
            [2] = sci_b_uart_tei_isr, /* SCI3 TEI (Transmit end) */
            [3] = sci_b_uart_eri_isr, /* SCI3 ERI (Receive error) */
            [4] = sci_b_uart_rxi_isr, /* SCI4 RXI (Receive data full) */
            [5] = sci_b_uart_txi_isr, /* SCI4 TXI (Transmit data empty) */
            [6] = sci_b_uart_tei_isr, /* SCI4 TEI (Transmit end) */
            [7] = sci_b_uart_eri_isr, /* SCI4 ERI (Receive error) */
            [8] = adc_scan_end_isr, /* ADC0 SCAN END (End of A/D scanning operation) */
            [9] = gpt_counter_overflow_isr, /* GPT13 COUNTER OVERFLOW (Overflow) */
            [10] = gpt_counter_overflow_isr, /* GPT12 COUNTER OVERFLOW (Overflow) */
            [11] = gpt_counter_overflow_isr, /* GPT10 COUNTER OVERFLOW (Overflow) */
            [12] = rtc_alarm_periodic_isr, /* RTC PERIOD (Periodic interrupt) */
            [13] = rtc_carry_isr, /* RTC CARRY (Carry interrupt) */
            [14] = gpt_counter_overflow_isr, /* GPT1 COUNTER OVERFLOW (Overflow) */
            [15] = gpt_counter_overflow_isr, /* GPT9 COUNTER OVERFLOW (Overflow) */
            [16] = r_icu_isr, /* ICU IRQ4 (External pin interrupt 4) */
            [17] = sci_b_uart_rxi_isr, /* SCI2 RXI (Receive data full) */
            [18] = sci_b_uart_txi_isr, /* SCI2 TXI (Transmit data empty) */
            [19] = sci_b_uart_tei_isr, /* SCI2 TEI (Transmit end) */
            [20] = sci_b_uart_eri_isr, /* SCI2 ERI (Receive error) */
            [21] = dmac_int_isr, /* DMAC1 INT (DMAC1 transfer end) */
            [22] = ceu_isr, /* CEU CEUI (CEU interrupt) */
            [23] = sdhimmc_accs_isr, /* SDHIMMC1 ACCS (Card access) */
            [24] = sdhimmc_card_isr, /* SDHIMMC1 CARD (Card detect) */
            [25] = dmac_int_isr, /* DMAC0 INT (DMAC0 transfer end) */
            [26] = glcdc_line_detect_isr, /* GLCDC LINE DETECT (Specified line) */
        };
        #if BSP_FEATURE_ICU_HAS_IELSR
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_VECT_ENUM(EVENT_SCI3_RXI,GROUP0), /* SCI3 RXI (Receive data full) */
            [1] = BSP_PRV_VECT_ENUM(EVENT_SCI3_TXI,GROUP1), /* SCI3 TXI (Transmit data empty) */
            [2] = BSP_PRV_VECT_ENUM(EVENT_SCI3_TEI,GROUP2), /* SCI3 TEI (Transmit end) */
            [3] = BSP_PRV_VECT_ENUM(EVENT_SCI3_ERI,GROUP3), /* SCI3 ERI (Receive error) */
            [4] = BSP_PRV_VECT_ENUM(EVENT_SCI4_RXI,GROUP4), /* SCI4 RXI (Receive data full) */
            [5] = BSP_PRV_VECT_ENUM(EVENT_SCI4_TXI,GROUP5), /* SCI4 TXI (Transmit data empty) */
            [6] = BSP_PRV_VECT_ENUM(EVENT_SCI4_TEI,GROUP6), /* SCI4 TEI (Transmit end) */
            [7] = BSP_PRV_VECT_ENUM(EVENT_SCI4_ERI,GROUP7), /* SCI4 ERI (Receive error) */
            [8] = BSP_PRV_VECT_ENUM(EVENT_ADC0_SCAN_END,GROUP0), /* ADC0 SCAN END (End of A/D scanning operation) */
            [9] = BSP_PRV_VECT_ENUM(EVENT_GPT13_COUNTER_OVERFLOW,GROUP1), /* GPT13 COUNTER OVERFLOW (Overflow) */
            [10] = BSP_PRV_VECT_ENUM(EVENT_GPT12_COUNTER_OVERFLOW,GROUP2), /* GPT12 COUNTER OVERFLOW (Overflow) */
            [11] = BSP_PRV_VECT_ENUM(EVENT_GPT10_COUNTER_OVERFLOW,GROUP3), /* GPT10 COUNTER OVERFLOW (Overflow) */
            [12] = BSP_PRV_VECT_ENUM(EVENT_RTC_PERIOD,GROUP4), /* RTC PERIOD (Periodic interrupt) */
            [13] = BSP_PRV_VECT_ENUM(EVENT_RTC_CARRY,GROUP5), /* RTC CARRY (Carry interrupt) */
            [14] = BSP_PRV_VECT_ENUM(EVENT_GPT1_COUNTER_OVERFLOW,GROUP6), /* GPT1 COUNTER OVERFLOW (Overflow) */
            [15] = BSP_PRV_VECT_ENUM(EVENT_GPT9_COUNTER_OVERFLOW,GROUP7), /* GPT9 COUNTER OVERFLOW (Overflow) */
            [16] = BSP_PRV_VECT_ENUM(EVENT_ICU_IRQ4,GROUP0), /* ICU IRQ4 (External pin interrupt 4) */
            [17] = BSP_PRV_VECT_ENUM(EVENT_SCI2_RXI,GROUP1), /* SCI2 RXI (Receive data full) */
            [18] = BSP_PRV_VECT_ENUM(EVENT_SCI2_TXI,GROUP2), /* SCI2 TXI (Transmit data empty) */
            [19] = BSP_PRV_VECT_ENUM(EVENT_SCI2_TEI,GROUP3), /* SCI2 TEI (Transmit end) */
            [20] = BSP_PRV_VECT_ENUM(EVENT_SCI2_ERI,GROUP4), /* SCI2 ERI (Receive error) */
            [21] = BSP_PRV_VECT_ENUM(EVENT_DMAC1_INT,GROUP5), /* DMAC1 INT (DMAC1 transfer end) */
            [22] = BSP_PRV_VECT_ENUM(EVENT_CEU_CEUI,GROUP6), /* CEU CEUI (CEU interrupt) */
            [23] = BSP_PRV_VECT_ENUM(EVENT_SDHIMMC1_ACCS,GROUP7), /* SDHIMMC1 ACCS (Card access) */
            [24] = BSP_PRV_VECT_ENUM(EVENT_SDHIMMC1_CARD,GROUP0), /* SDHIMMC1 CARD (Card detect) */
            [25] = BSP_PRV_VECT_ENUM(EVENT_DMAC0_INT,GROUP1), /* DMAC0 INT (DMAC0 transfer end) */
            [26] = BSP_PRV_VECT_ENUM(EVENT_GLCDC_LINE_DETECT,GROUP2), /* GLCDC LINE DETECT (Specified line) */
        };
        #endif
        #endif
