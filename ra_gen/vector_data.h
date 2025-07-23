/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
#ifdef __cplusplus
        extern "C" {
        #endif
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (27)
#endif
/* ISR prototypes */
void sci_b_uart_rxi_isr(void);
void sci_b_uart_txi_isr(void);
void sci_b_uart_tei_isr(void);
void sci_b_uart_eri_isr(void);
void adc_scan_end_isr(void);
void gpt_counter_overflow_isr(void);
void rtc_alarm_periodic_isr(void);
void rtc_carry_isr(void);
void r_icu_isr(void);
void dmac_int_isr(void);
void ceu_isr(void);
void sdhimmc_accs_isr(void);
void sdhimmc_card_isr(void);
void glcdc_line_detect_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_SCI3_RXI ((IRQn_Type) 0) /* SCI3 RXI (Receive data full) */
#define SCI3_RXI_IRQn          ((IRQn_Type) 0) /* SCI3 RXI (Receive data full) */
#define VECTOR_NUMBER_SCI3_TXI ((IRQn_Type) 1) /* SCI3 TXI (Transmit data empty) */
#define SCI3_TXI_IRQn          ((IRQn_Type) 1) /* SCI3 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI3_TEI ((IRQn_Type) 2) /* SCI3 TEI (Transmit end) */
#define SCI3_TEI_IRQn          ((IRQn_Type) 2) /* SCI3 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI3_ERI ((IRQn_Type) 3) /* SCI3 ERI (Receive error) */
#define SCI3_ERI_IRQn          ((IRQn_Type) 3) /* SCI3 ERI (Receive error) */
#define VECTOR_NUMBER_SCI4_RXI ((IRQn_Type) 4) /* SCI4 RXI (Receive data full) */
#define SCI4_RXI_IRQn          ((IRQn_Type) 4) /* SCI4 RXI (Receive data full) */
#define VECTOR_NUMBER_SCI4_TXI ((IRQn_Type) 5) /* SCI4 TXI (Transmit data empty) */
#define SCI4_TXI_IRQn          ((IRQn_Type) 5) /* SCI4 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI4_TEI ((IRQn_Type) 6) /* SCI4 TEI (Transmit end) */
#define SCI4_TEI_IRQn          ((IRQn_Type) 6) /* SCI4 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI4_ERI ((IRQn_Type) 7) /* SCI4 ERI (Receive error) */
#define SCI4_ERI_IRQn          ((IRQn_Type) 7) /* SCI4 ERI (Receive error) */
#define VECTOR_NUMBER_ADC0_SCAN_END ((IRQn_Type) 8) /* ADC0 SCAN END (End of A/D scanning operation) */
#define ADC0_SCAN_END_IRQn          ((IRQn_Type) 8) /* ADC0 SCAN END (End of A/D scanning operation) */
#define VECTOR_NUMBER_GPT13_COUNTER_OVERFLOW ((IRQn_Type) 9) /* GPT13 COUNTER OVERFLOW (Overflow) */
#define GPT13_COUNTER_OVERFLOW_IRQn          ((IRQn_Type) 9) /* GPT13 COUNTER OVERFLOW (Overflow) */
#define VECTOR_NUMBER_GPT12_COUNTER_OVERFLOW ((IRQn_Type) 10) /* GPT12 COUNTER OVERFLOW (Overflow) */
#define GPT12_COUNTER_OVERFLOW_IRQn          ((IRQn_Type) 10) /* GPT12 COUNTER OVERFLOW (Overflow) */
#define VECTOR_NUMBER_GPT10_COUNTER_OVERFLOW ((IRQn_Type) 11) /* GPT10 COUNTER OVERFLOW (Overflow) */
#define GPT10_COUNTER_OVERFLOW_IRQn          ((IRQn_Type) 11) /* GPT10 COUNTER OVERFLOW (Overflow) */
#define VECTOR_NUMBER_RTC_PERIOD ((IRQn_Type) 12) /* RTC PERIOD (Periodic interrupt) */
#define RTC_PERIOD_IRQn          ((IRQn_Type) 12) /* RTC PERIOD (Periodic interrupt) */
#define VECTOR_NUMBER_RTC_CARRY ((IRQn_Type) 13) /* RTC CARRY (Carry interrupt) */
#define RTC_CARRY_IRQn          ((IRQn_Type) 13) /* RTC CARRY (Carry interrupt) */
#define VECTOR_NUMBER_GPT1_COUNTER_OVERFLOW ((IRQn_Type) 14) /* GPT1 COUNTER OVERFLOW (Overflow) */
#define GPT1_COUNTER_OVERFLOW_IRQn          ((IRQn_Type) 14) /* GPT1 COUNTER OVERFLOW (Overflow) */
#define VECTOR_NUMBER_GPT9_COUNTER_OVERFLOW ((IRQn_Type) 15) /* GPT9 COUNTER OVERFLOW (Overflow) */
#define GPT9_COUNTER_OVERFLOW_IRQn          ((IRQn_Type) 15) /* GPT9 COUNTER OVERFLOW (Overflow) */
#define VECTOR_NUMBER_ICU_IRQ4 ((IRQn_Type) 16) /* ICU IRQ4 (External pin interrupt 4) */
#define ICU_IRQ4_IRQn          ((IRQn_Type) 16) /* ICU IRQ4 (External pin interrupt 4) */
#define VECTOR_NUMBER_SCI2_RXI ((IRQn_Type) 17) /* SCI2 RXI (Receive data full) */
#define SCI2_RXI_IRQn          ((IRQn_Type) 17) /* SCI2 RXI (Receive data full) */
#define VECTOR_NUMBER_SCI2_TXI ((IRQn_Type) 18) /* SCI2 TXI (Transmit data empty) */
#define SCI2_TXI_IRQn          ((IRQn_Type) 18) /* SCI2 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI2_TEI ((IRQn_Type) 19) /* SCI2 TEI (Transmit end) */
#define SCI2_TEI_IRQn          ((IRQn_Type) 19) /* SCI2 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI2_ERI ((IRQn_Type) 20) /* SCI2 ERI (Receive error) */
#define SCI2_ERI_IRQn          ((IRQn_Type) 20) /* SCI2 ERI (Receive error) */
#define VECTOR_NUMBER_DMAC1_INT ((IRQn_Type) 21) /* DMAC1 INT (DMAC1 transfer end) */
#define DMAC1_INT_IRQn          ((IRQn_Type) 21) /* DMAC1 INT (DMAC1 transfer end) */
#define VECTOR_NUMBER_CEU_CEUI ((IRQn_Type) 22) /* CEU CEUI (CEU interrupt) */
#define CEU_CEUI_IRQn          ((IRQn_Type) 22) /* CEU CEUI (CEU interrupt) */
#define VECTOR_NUMBER_SDHIMMC1_ACCS ((IRQn_Type) 23) /* SDHIMMC1 ACCS (Card access) */
#define SDHIMMC1_ACCS_IRQn          ((IRQn_Type) 23) /* SDHIMMC1 ACCS (Card access) */
#define VECTOR_NUMBER_SDHIMMC1_CARD ((IRQn_Type) 24) /* SDHIMMC1 CARD (Card detect) */
#define SDHIMMC1_CARD_IRQn          ((IRQn_Type) 24) /* SDHIMMC1 CARD (Card detect) */
#define VECTOR_NUMBER_DMAC0_INT ((IRQn_Type) 25) /* DMAC0 INT (DMAC0 transfer end) */
#define DMAC0_INT_IRQn          ((IRQn_Type) 25) /* DMAC0 INT (DMAC0 transfer end) */
#define VECTOR_NUMBER_GLCDC_LINE_DETECT ((IRQn_Type) 26) /* GLCDC LINE DETECT (Specified line) */
#define GLCDC_LINE_DETECT_IRQn          ((IRQn_Type) 26) /* GLCDC LINE DETECT (Specified line) */
#ifdef __cplusplus
        }
        #endif
#endif /* VECTOR_DATA_H */
