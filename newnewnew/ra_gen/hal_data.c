/* generated HAL source file - do not edit */
#include "hal_data.h"

dmac_instance_ctrl_t g_transfer_sdhi_ctrl;
transfer_info_t g_transfer_sdhi_info =
{ .transfer_settings_word_b.dest_addr_mode = TRANSFER_ADDR_MODE_FIXED,
  .transfer_settings_word_b.repeat_area = TRANSFER_REPEAT_AREA_SOURCE,
  .transfer_settings_word_b.irq = TRANSFER_IRQ_END,
  .transfer_settings_word_b.chain_mode = TRANSFER_CHAIN_MODE_DISABLED,
  .transfer_settings_word_b.src_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED,
  .transfer_settings_word_b.size = TRANSFER_SIZE_4_BYTE,
  .transfer_settings_word_b.mode = TRANSFER_MODE_NORMAL,
  .p_dest = (void*) NULL,
  .p_src = (void const*) NULL,
  .num_blocks = 0,
  .length = 128, };
const dmac_extended_cfg_t g_transfer_sdhi_extend =
{ .offset = 1, .src_buffer_size = 1,
#if defined(VECTOR_NUMBER_DMAC0_INT)
    .irq                 = VECTOR_NUMBER_DMAC0_INT,
#else
  .irq = FSP_INVALID_VECTOR,
#endif
  .ipl = (10),
  .channel = 0, .p_callback = g_sdmmc0_dmac_callback, .p_context = &g_sdmmc0_ctrl, .activation_source =
          ELC_EVENT_SDHIMMC1_DMA_REQ, };
const transfer_cfg_t g_transfer_sdhi_cfg =
{ .p_info = &g_transfer_sdhi_info, .p_extend = &g_transfer_sdhi_extend, };
/* Instance structure to use this module. */
const transfer_instance_t g_transfer_sdhi =
{ .p_ctrl = &g_transfer_sdhi_ctrl, .p_cfg = &g_transfer_sdhi_cfg, .p_api = &g_transfer_on_dmac };
#define RA_NOT_DEFINED (UINT32_MAX)
#if (RA_NOT_DEFINED) != (1)

/* If the transfer module is DMAC, define a DMAC transfer callback. */
#include "r_dmac.h"
extern void r_sdhi_transfer_callback(sdhi_instance_ctrl_t *p_ctrl);

void g_sdmmc0_dmac_callback(dmac_callback_args_t *p_args)
{
    r_sdhi_transfer_callback ((sdhi_instance_ctrl_t*) p_args->p_context);
}
#endif
#undef RA_NOT_DEFINED

sdhi_instance_ctrl_t g_sdmmc0_ctrl;
sdmmc_cfg_t g_sdmmc0_cfg =
{ .bus_width = SDMMC_BUS_WIDTH_4_BITS, .channel = 1, .p_callback = g_sdmmc0_callback, .p_context = NULL, .block_size =
          512,
  .card_detect = SDMMC_CARD_DETECT_CD, .write_protect = SDMMC_WRITE_PROTECT_NONE,

  .p_extend = NULL,
  .p_lower_lvl_transfer = &g_transfer_sdhi,

  .access_ipl = (10),
  .sdio_ipl = BSP_IRQ_DISABLED, .card_ipl = (10), .dma_req_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_SDHIMMC1_ACCS)
    .access_irq             = VECTOR_NUMBER_SDHIMMC1_ACCS,
#else
  .access_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SDHIMMC1_CARD)
    .card_irq               = VECTOR_NUMBER_SDHIMMC1_CARD,
#else
  .card_irq = FSP_INVALID_VECTOR,
#endif
  .sdio_irq = FSP_INVALID_VECTOR,
#if defined(VECTOR_NUMBER_SDHIMMC1_DMA_REQ)
    .dma_req_irq            = VECTOR_NUMBER_SDHIMMC1_DMA_REQ,
#else
  .dma_req_irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const sdmmc_instance_t g_sdmmc0 =
{ .p_ctrl = &g_sdmmc0_ctrl, .p_cfg = &g_sdmmc0_cfg, .p_api = &g_sdmmc_on_sdhi };
ceu_instance_ctrl_t g_ceu_vga_ctrl;
const ceu_extended_cfg_t g_ceu_vga_extended_cfg =
{ .capture_format = CEU_CAPTURE_FORMAT_DATA_SYNCHRONOUS,
  .data_bus_width = CEU_DATA_BUS_SIZE_8_BIT,
  .edge_info.dsel = 0,
  .edge_info.hdsel = 0,
  .edge_info.vdsel = 0,
  .hsync_polarity = CEU_HSYNC_POLARITY_HIGH,
  .vsync_polarity = CEU_VSYNC_POLARITY_HIGH,
  .byte_swapping =
  { .swap_8bit_units = (0x1 | 0x2 | 0x4 | 0x0) >> 0x00 & 0x01, .swap_16bit_units = (0x1 | 0x2 | 0x4 | 0x0) >> 0x01
          & 0x01,
    .swap_32bit_units = (0x1 | 0x2 | 0x4 | 0x0) >> 0x02 & 0x01, },
  .burst_mode = CEU_BURST_TRANSFER_MODE_X8,
  .image_area_size = 320 * 240 * 2,
  .interrupts_enabled = 0 | R_CEU_CEIER_CPEIE_Msk | 0 | R_CEU_CEIER_VDIE_Msk | R_CEU_CEIER_CDTOFIE_Msk | 0 | 0
          | R_CEU_CEIER_VBPIE_Msk | R_CEU_CEIER_NHDIE_Msk | R_CEU_CEIER_NVDIE_Msk,
  .ceu_ipl = (6),
  .ceu_irq = VECTOR_NUMBER_CEU_CEUI, };

const capture_cfg_t g_ceu_vga_cfg =
{ .x_capture_pixels = 320,
  .y_capture_pixels = 240,
  .x_capture_start_pixel = 0,
  .y_capture_start_pixel = 0,
  .bytes_per_pixel = 2,
  .p_callback = g_ceu_vga_callback,
  .p_context = NULL,
  .p_extend = &g_ceu_vga_extended_cfg, };

const capture_instance_t g_ceu_vga =
{ .p_ctrl = &g_ceu_vga_ctrl, .p_cfg = &g_ceu_vga_cfg, .p_api = &g_ceu_on_capture, };
dmac_instance_ctrl_t g_transfer_dmac0_ctrl;
transfer_info_t g_transfer_dmac0_info =
{ .transfer_settings_word_b.dest_addr_mode = TRANSFER_ADDR_MODE_FIXED,
  .transfer_settings_word_b.repeat_area = TRANSFER_REPEAT_AREA_SOURCE,
  .transfer_settings_word_b.irq = TRANSFER_IRQ_END,
  .transfer_settings_word_b.chain_mode = TRANSFER_CHAIN_MODE_DISABLED,
  .transfer_settings_word_b.src_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED,
  .transfer_settings_word_b.size = TRANSFER_SIZE_4_BYTE,
  .transfer_settings_word_b.mode = TRANSFER_MODE_NORMAL,
  .p_dest = (void*) NULL,
  .p_src = (void const*) NULL,
  .num_blocks = 0,
  .length = 242, };
const dmac_extended_cfg_t g_transfer_dmac0_extend =
{ .offset = 1, .src_buffer_size = 1,
#if defined(VECTOR_NUMBER_DMAC1_INT)
    .irq                 = VECTOR_NUMBER_DMAC1_INT,
#else
  .irq = FSP_INVALID_VECTOR,
#endif
  .ipl = (3),
  .channel = 1, .p_callback = dmac0_callback, .p_context = NULL, .activation_source = ELC_EVENT_NONE, };
const transfer_cfg_t g_transfer_dmac0_cfg =
{ .p_info = &g_transfer_dmac0_info, .p_extend = &g_transfer_dmac0_extend, };
/* Instance structure to use this module. */
const transfer_instance_t g_transfer_dmac0 =
{ .p_ctrl = &g_transfer_dmac0_ctrl, .p_cfg = &g_transfer_dmac0_cfg, .p_api = &g_transfer_on_dmac };
sci_b_uart_instance_ctrl_t snr_uart_ctrl;

sci_b_baud_setting_t snr_uart_baud_setting =
        {
        /* Baud rate calculated with 0.160% error. */.baudrate_bits_b.abcse = 0,
          .baudrate_bits_b.abcs = 0, .baudrate_bits_b.bgdm = 1, .baudrate_bits_b.cks = 0, .baudrate_bits_b.brr = 64, .baudrate_bits_b.mddr =
                  (uint8_t) 256,
          .baudrate_bits_b.brme = false };

/** UART extended configuration for UARTonSCI HAL driver */
const sci_b_uart_extended_cfg_t snr_uart_cfg_extend =
{ .clock = SCI_B_UART_CLOCK_INT, .rx_edge_start = SCI_B_UART_START_BIT_FALLING_EDGE, .noise_cancel =
          SCI_B_UART_NOISE_CANCELLATION_DISABLE,
  .rx_fifo_trigger = SCI_B_UART_RX_FIFO_TRIGGER_MAX, .p_baud_setting = &snr_uart_baud_setting, .flow_control =
          SCI_B_UART_FLOW_CONTROL_RTS,
#if 0xFF != 0xFF
                .flow_control_pin       = BSP_IO_PORT_FF_PIN_0xFF,
                #else
  .flow_control_pin = (bsp_io_port_pin_t) UINT16_MAX,
#endif
  .rs485_setting =
  { .enable = SCI_B_UART_RS485_DISABLE,
    .polarity = SCI_B_UART_RS485_DE_POLARITY_HIGH,
    .assertion_time = 1,
    .negation_time = 1, } };

/** UART interface configuration */
const uart_cfg_t snr_uart_cfg =
{ .channel = 2, .data_bits = UART_DATA_BITS_8, .parity = UART_PARITY_OFF, .stop_bits = UART_STOP_BITS_1, .p_callback =
          snr_uart_callback,
  .p_context = NULL, .p_extend = &snr_uart_cfg_extend,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_tx = NULL,
#else
                .p_transfer_tx       = &RA_NOT_DEFINED,
#endif
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_rx = NULL,
#else
                .p_transfer_rx       = &RA_NOT_DEFINED,
#endif
#undef RA_NOT_DEFINED
  .rxi_ipl = (12),
  .txi_ipl = (12), .tei_ipl = (12), .eri_ipl = (12),
#if defined(VECTOR_NUMBER_SCI2_RXI)
                .rxi_irq             = VECTOR_NUMBER_SCI2_RXI,
#else
  .rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI2_TXI)
                .txi_irq             = VECTOR_NUMBER_SCI2_TXI,
#else
  .txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI2_TEI)
                .tei_irq             = VECTOR_NUMBER_SCI2_TEI,
#else
  .tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI2_ERI)
                .eri_irq             = VECTOR_NUMBER_SCI2_ERI,
#else
  .eri_irq = FSP_INVALID_VECTOR,
#endif
        };

/* Instance structure to use this module. */
const uart_instance_t snr_uart =
{ .p_ctrl = &snr_uart_ctrl, .p_cfg = &snr_uart_cfg, .p_api = &g_uart_on_sci_b };
gpt_instance_ctrl_t timer9_ctrl;
#if 0
const gpt_extended_pwm_cfg_t timer9_pwm_extend =
{
    .trough_ipl          = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT9_COUNTER_UNDERFLOW)
    .trough_irq          = VECTOR_NUMBER_GPT9_COUNTER_UNDERFLOW,
#else
    .trough_irq          = FSP_INVALID_VECTOR,
#endif
    .poeg_link           = GPT_POEG_LINK_POEG0,
    .output_disable      = (gpt_output_disable_t) ( GPT_OUTPUT_DISABLE_NONE),
    .adc_trigger         = (gpt_adc_trigger_t) ( GPT_ADC_TRIGGER_NONE),
    .dead_time_count_up  = 0,
    .dead_time_count_down = 0,
    .adc_a_compare_match = 0,
    .adc_b_compare_match = 0,
    .interrupt_skip_source = GPT_INTERRUPT_SKIP_SOURCE_NONE,
    .interrupt_skip_count  = GPT_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_adc    = GPT_INTERRUPT_SKIP_ADC_NONE,
    .gtioca_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
    .gtiocb_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
};
#endif
const gpt_extended_cfg_t timer9_extend =
        { .gtioca =
        { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
          .gtiocb =
          { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
          .start_source = (gpt_source_t) (GPT_SOURCE_NONE), .stop_source = (gpt_source_t) (GPT_SOURCE_NONE), .clear_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .count_up_source = (gpt_source_t) (GPT_SOURCE_NONE), .count_down_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .capture_b_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_ipl = (BSP_IRQ_DISABLED), .capture_b_ipl =
                  (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT9_CAPTURE_COMPARE_A)
    .capture_a_irq       = VECTOR_NUMBER_GPT9_CAPTURE_COMPARE_A,
#else
          .capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT9_CAPTURE_COMPARE_B)
    .capture_b_irq       = VECTOR_NUMBER_GPT9_CAPTURE_COMPARE_B,
#else
          .capture_b_irq = FSP_INVALID_VECTOR,
#endif
          .compare_match_value =
          { /* CMP_A */0x0, /* CMP_B */0x0 },
          .compare_match_status = (0U << 1U) | 0U, .capture_filter_gtioca = GPT_CAPTURE_FILTER_NONE, .capture_filter_gtiocb =
                  GPT_CAPTURE_FILTER_NONE,
#if 0
    .p_pwm_cfg                   = &timer9_pwm_extend,
#else
          .p_pwm_cfg = NULL,
#endif
#if 0
    .gtior_setting.gtior_b.gtioa  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.oadflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.oahld  = 0U,
    .gtior_setting.gtior_b.oae    = (uint32_t) false,
    .gtior_setting.gtior_b.oadf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfaen  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsa  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
    .gtior_setting.gtior_b.gtiob  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.obdflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.obhld  = 0U,
    .gtior_setting.gtior_b.obe    = (uint32_t) false,
    .gtior_setting.gtior_b.obdf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfben  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsb  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
#else
          .gtior_setting.gtior = 0U,
#endif
        };

const timer_cfg_t timer9_cfg =
{ .mode = TIMER_MODE_PERIODIC,
/* Actual period: 0.001 seconds. Actual duty: 50%. */.period_counts = (uint32_t) 0xea60,
  .duty_cycle_counts = 0x7530, .source_div = (timer_source_div_t) 1, .channel = 9, .p_callback = timer9_callback,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = &timer9_extend,
  .cycle_end_ipl = (2),
#if defined(VECTOR_NUMBER_GPT9_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GPT9_COUNTER_OVERFLOW,
#else
  .cycle_end_irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const timer_instance_t timer9 =
{ .p_ctrl = &timer9_ctrl, .p_cfg = &timer9_cfg, .p_api = &g_timer_on_gpt };
gpt_instance_ctrl_t led_pwm_ctrl;
#if 0
const gpt_extended_pwm_cfg_t led_pwm_pwm_extend =
{
    .trough_ipl          = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT1_COUNTER_UNDERFLOW)
    .trough_irq          = VECTOR_NUMBER_GPT1_COUNTER_UNDERFLOW,
#else
    .trough_irq          = FSP_INVALID_VECTOR,
#endif
    .poeg_link           = GPT_POEG_LINK_POEG0,
    .output_disable      = (gpt_output_disable_t) ( GPT_OUTPUT_DISABLE_NONE),
    .adc_trigger         = (gpt_adc_trigger_t) ( GPT_ADC_TRIGGER_NONE),
    .dead_time_count_up  = 0,
    .dead_time_count_down = 0,
    .adc_a_compare_match = 0,
    .adc_b_compare_match = 0,
    .interrupt_skip_source = GPT_INTERRUPT_SKIP_SOURCE_NONE,
    .interrupt_skip_count  = GPT_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_adc    = GPT_INTERRUPT_SKIP_ADC_NONE,
    .gtioca_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
    .gtiocb_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
};
#endif
const gpt_extended_cfg_t led_pwm_extend =
        { .gtioca =
        { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
          .gtiocb =
          { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
          .start_source = (gpt_source_t) (GPT_SOURCE_NONE), .stop_source = (gpt_source_t) (GPT_SOURCE_NONE), .clear_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .count_up_source = (gpt_source_t) (GPT_SOURCE_NONE), .count_down_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .capture_b_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_ipl = (BSP_IRQ_DISABLED), .capture_b_ipl =
                  (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT1_CAPTURE_COMPARE_A)
    .capture_a_irq       = VECTOR_NUMBER_GPT1_CAPTURE_COMPARE_A,
#else
          .capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT1_CAPTURE_COMPARE_B)
    .capture_b_irq       = VECTOR_NUMBER_GPT1_CAPTURE_COMPARE_B,
#else
          .capture_b_irq = FSP_INVALID_VECTOR,
#endif
          .compare_match_value =
          { /* CMP_A */0x0, /* CMP_B */0x0 },
          .compare_match_status = (0U << 1U) | 0U, .capture_filter_gtioca = GPT_CAPTURE_FILTER_NONE, .capture_filter_gtiocb =
                  GPT_CAPTURE_FILTER_NONE,
#if 0
    .p_pwm_cfg                   = &led_pwm_pwm_extend,
#else
          .p_pwm_cfg = NULL,
#endif
#if 0
    .gtior_setting.gtior_b.gtioa  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.oadflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.oahld  = 0U,
    .gtior_setting.gtior_b.oae    = (uint32_t) false,
    .gtior_setting.gtior_b.oadf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfaen  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsa  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
    .gtior_setting.gtior_b.gtiob  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.obdflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.obhld  = 0U,
    .gtior_setting.gtior_b.obe    = (uint32_t) false,
    .gtior_setting.gtior_b.obdf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfben  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsb  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
#else
          .gtior_setting.gtior = 0U,
#endif
        };

const timer_cfg_t led_pwm_cfg =
{ .mode = TIMER_MODE_PWM,
/* Actual period: 0.00000125 seconds. Actual duty: 50%. */.period_counts = (uint32_t) 0x96,
  .duty_cycle_counts = 0x4b, .source_div = (timer_source_div_t) 0, .channel = 1, .p_callback =
          led_timer_update_event_callback,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = &led_pwm_extend,
  .cycle_end_ipl = (2),
#if defined(VECTOR_NUMBER_GPT1_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GPT1_COUNTER_OVERFLOW,
#else
  .cycle_end_irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const timer_instance_t led_pwm =
{ .p_ctrl = &led_pwm_ctrl, .p_cfg = &led_pwm_cfg, .p_api = &g_timer_on_gpt };
gpt_instance_ctrl_t beep_timer_ctrl;
#if 0
const gpt_extended_pwm_cfg_t beep_timer_pwm_extend =
{
    .trough_ipl          = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT2_COUNTER_UNDERFLOW)
    .trough_irq          = VECTOR_NUMBER_GPT2_COUNTER_UNDERFLOW,
#else
    .trough_irq          = FSP_INVALID_VECTOR,
#endif
    .poeg_link           = GPT_POEG_LINK_POEG0,
    .output_disable      = (gpt_output_disable_t) ( GPT_OUTPUT_DISABLE_NONE),
    .adc_trigger         = (gpt_adc_trigger_t) ( GPT_ADC_TRIGGER_NONE),
    .dead_time_count_up  = 0,
    .dead_time_count_down = 0,
    .adc_a_compare_match = 0,
    .adc_b_compare_match = 0,
    .interrupt_skip_source = GPT_INTERRUPT_SKIP_SOURCE_NONE,
    .interrupt_skip_count  = GPT_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_adc    = GPT_INTERRUPT_SKIP_ADC_NONE,
    .gtioca_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
    .gtiocb_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
};
#endif
const gpt_extended_cfg_t beep_timer_extend =
        { .gtioca =
        { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
          .gtiocb =
          { .output_enabled = true, .stop_level = GPT_PIN_LEVEL_LOW },
          .start_source = (gpt_source_t) (GPT_SOURCE_NONE), .stop_source = (gpt_source_t) (GPT_SOURCE_NONE), .clear_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .count_up_source = (gpt_source_t) (GPT_SOURCE_NONE), .count_down_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .capture_b_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_ipl = (BSP_IRQ_DISABLED), .capture_b_ipl =
                  (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT2_CAPTURE_COMPARE_A)
    .capture_a_irq       = VECTOR_NUMBER_GPT2_CAPTURE_COMPARE_A,
#else
          .capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT2_CAPTURE_COMPARE_B)
    .capture_b_irq       = VECTOR_NUMBER_GPT2_CAPTURE_COMPARE_B,
#else
          .capture_b_irq = FSP_INVALID_VECTOR,
#endif
          .compare_match_value =
          { /* CMP_A */0x0, /* CMP_B */0x0 },
          .compare_match_status = (0U << 1U) | 0U, .capture_filter_gtioca = GPT_CAPTURE_FILTER_NONE, .capture_filter_gtiocb =
                  GPT_CAPTURE_FILTER_NONE,
#if 0
    .p_pwm_cfg                   = &beep_timer_pwm_extend,
#else
          .p_pwm_cfg = NULL,
#endif
#if 0
    .gtior_setting.gtior_b.gtioa  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.oadflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.oahld  = 0U,
    .gtior_setting.gtior_b.oae    = (uint32_t) false,
    .gtior_setting.gtior_b.oadf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfaen  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsa  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
    .gtior_setting.gtior_b.gtiob  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.obdflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.obhld  = 0U,
    .gtior_setting.gtior_b.obe    = (uint32_t) true,
    .gtior_setting.gtior_b.obdf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfben  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsb  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
#else
          .gtior_setting.gtior = 0U,
#endif
        };

const timer_cfg_t beep_timer_cfg =
{ .mode = TIMER_MODE_PERIODIC,
/* Actual period: 0.0004166666666666667 seconds. Actual duty: 50%. */.period_counts = (uint32_t) 0xc350,
  .duty_cycle_counts = 0x61a8, .source_div = (timer_source_div_t) 0, .channel = 2, .p_callback = NULL,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = &beep_timer_extend,
  .cycle_end_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT2_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GPT2_COUNTER_OVERFLOW,
#else
  .cycle_end_irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const timer_instance_t beep_timer =
{ .p_ctrl = &beep_timer_ctrl, .p_cfg = &beep_timer_cfg, .p_api = &g_timer_on_gpt };
rtc_instance_ctrl_t rtc_ctrl;
const rtc_error_adjustment_cfg_t rtc_err_cfg =
{ .adjustment_mode = RTC_ERROR_ADJUSTMENT_MODE_AUTOMATIC,
  .adjustment_period = RTC_ERROR_ADJUSTMENT_PERIOD_10_SECOND,
  .adjustment_type = RTC_ERROR_ADJUSTMENT_NONE,
  .adjustment_value = 0, };
const rtc_cfg_t rtc_cfg =
{ .clock_source = RTC_CLOCK_SOURCE_LOCO, .freq_compare_value = 255, .p_err_cfg = &rtc_err_cfg, .p_callback =
          rtc_callback,
  .p_context = NULL, .p_extend = NULL, .alarm_ipl = (BSP_IRQ_DISABLED), .periodic_ipl = (12), .carry_ipl = (12),
#if defined(VECTOR_NUMBER_RTC_ALARM)
    .alarm_irq               = VECTOR_NUMBER_RTC_ALARM,
#else
  .alarm_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_RTC_PERIOD)
    .periodic_irq            = VECTOR_NUMBER_RTC_PERIOD,
#else
  .periodic_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_RTC_CARRY)
    .carry_irq               = VECTOR_NUMBER_RTC_CARRY,
#else
  .carry_irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const rtc_instance_t rtc =
{ .p_ctrl = &rtc_ctrl, .p_cfg = &rtc_cfg, .p_api = &g_rtc_on_rtc };
gpt_instance_ctrl_t timer10_ctrl;
#if 0
const gpt_extended_pwm_cfg_t timer10_pwm_extend =
{
    .trough_ipl          = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT10_COUNTER_UNDERFLOW)
    .trough_irq          = VECTOR_NUMBER_GPT10_COUNTER_UNDERFLOW,
#else
    .trough_irq          = FSP_INVALID_VECTOR,
#endif
    .poeg_link           = GPT_POEG_LINK_POEG0,
    .output_disable      = (gpt_output_disable_t) ( GPT_OUTPUT_DISABLE_NONE),
    .adc_trigger         = (gpt_adc_trigger_t) ( GPT_ADC_TRIGGER_NONE),
    .dead_time_count_up  = 0,
    .dead_time_count_down = 0,
    .adc_a_compare_match = 0,
    .adc_b_compare_match = 0,
    .interrupt_skip_source = GPT_INTERRUPT_SKIP_SOURCE_NONE,
    .interrupt_skip_count  = GPT_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_adc    = GPT_INTERRUPT_SKIP_ADC_NONE,
    .gtioca_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
    .gtiocb_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
};
#endif
const gpt_extended_cfg_t timer10_extend =
        { .gtioca =
        { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
          .gtiocb =
          { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
          .start_source = (gpt_source_t) (GPT_SOURCE_NONE), .stop_source = (gpt_source_t) (GPT_SOURCE_NONE), .clear_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .count_up_source = (gpt_source_t) (GPT_SOURCE_NONE), .count_down_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .capture_b_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_ipl = (BSP_IRQ_DISABLED), .capture_b_ipl =
                  (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT10_CAPTURE_COMPARE_A)
    .capture_a_irq       = VECTOR_NUMBER_GPT10_CAPTURE_COMPARE_A,
#else
          .capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT10_CAPTURE_COMPARE_B)
    .capture_b_irq       = VECTOR_NUMBER_GPT10_CAPTURE_COMPARE_B,
#else
          .capture_b_irq = FSP_INVALID_VECTOR,
#endif
          .compare_match_value =
          { /* CMP_A */0x0, /* CMP_B */0x0 },
          .compare_match_status = (0U << 1U) | 0U, .capture_filter_gtioca = GPT_CAPTURE_FILTER_NONE, .capture_filter_gtiocb =
                  GPT_CAPTURE_FILTER_NONE,
#if 0
    .p_pwm_cfg                   = &timer10_pwm_extend,
#else
          .p_pwm_cfg = NULL,
#endif
#if 0
    .gtior_setting.gtior_b.gtioa  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.oadflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.oahld  = 0U,
    .gtior_setting.gtior_b.oae    = (uint32_t) false,
    .gtior_setting.gtior_b.oadf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfaen  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsa  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
    .gtior_setting.gtior_b.gtiob  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.obdflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.obhld  = 0U,
    .gtior_setting.gtior_b.obe    = (uint32_t) false,
    .gtior_setting.gtior_b.obdf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfben  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsb  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
#else
          .gtior_setting.gtior = 0U,
#endif
        };

const timer_cfg_t timer10_cfg =
{ .mode = TIMER_MODE_ONE_SHOT,
/* Actual period: 0.000007983333333333334 seconds. Actual duty: 50%. */.period_counts = (uint32_t) 0x3be,
  .duty_cycle_counts = 0x1df, .source_div = (timer_source_div_t) 0, .channel = 10, .p_callback = timer10_callback,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = &timer10_extend,
  .cycle_end_ipl = (0),
#if defined(VECTOR_NUMBER_GPT10_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GPT10_COUNTER_OVERFLOW,
#else
  .cycle_end_irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const timer_instance_t timer10 =
{ .p_ctrl = &timer10_ctrl, .p_cfg = &timer10_cfg, .p_api = &g_timer_on_gpt };
gpt_instance_ctrl_t timer12_ctrl;
#if 0
const gpt_extended_pwm_cfg_t timer12_pwm_extend =
{
    .trough_ipl          = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT12_COUNTER_UNDERFLOW)
    .trough_irq          = VECTOR_NUMBER_GPT12_COUNTER_UNDERFLOW,
#else
    .trough_irq          = FSP_INVALID_VECTOR,
#endif
    .poeg_link           = GPT_POEG_LINK_POEG0,
    .output_disable      = (gpt_output_disable_t) ( GPT_OUTPUT_DISABLE_NONE),
    .adc_trigger         = (gpt_adc_trigger_t) ( GPT_ADC_TRIGGER_NONE),
    .dead_time_count_up  = 0,
    .dead_time_count_down = 0,
    .adc_a_compare_match = 0,
    .adc_b_compare_match = 0,
    .interrupt_skip_source = GPT_INTERRUPT_SKIP_SOURCE_NONE,
    .interrupt_skip_count  = GPT_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_adc    = GPT_INTERRUPT_SKIP_ADC_NONE,
    .gtioca_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
    .gtiocb_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
};
#endif
const gpt_extended_cfg_t timer12_extend =
        { .gtioca =
        { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
          .gtiocb =
          { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
          .start_source = (gpt_source_t) (GPT_SOURCE_NONE), .stop_source = (gpt_source_t) (GPT_SOURCE_NONE), .clear_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .count_up_source = (gpt_source_t) (GPT_SOURCE_NONE), .count_down_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .capture_b_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_ipl = (BSP_IRQ_DISABLED), .capture_b_ipl =
                  (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT12_CAPTURE_COMPARE_A)
    .capture_a_irq       = VECTOR_NUMBER_GPT12_CAPTURE_COMPARE_A,
#else
          .capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT12_CAPTURE_COMPARE_B)
    .capture_b_irq       = VECTOR_NUMBER_GPT12_CAPTURE_COMPARE_B,
#else
          .capture_b_irq = FSP_INVALID_VECTOR,
#endif
          .compare_match_value =
          { /* CMP_A */0x0, /* CMP_B */0x0 },
          .compare_match_status = (0U << 1U) | 0U, .capture_filter_gtioca = GPT_CAPTURE_FILTER_NONE, .capture_filter_gtiocb =
                  GPT_CAPTURE_FILTER_NONE,
#if 0
    .p_pwm_cfg                   = &timer12_pwm_extend,
#else
          .p_pwm_cfg = NULL,
#endif
#if 0
    .gtior_setting.gtior_b.gtioa  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.oadflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.oahld  = 0U,
    .gtior_setting.gtior_b.oae    = (uint32_t) false,
    .gtior_setting.gtior_b.oadf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfaen  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsa  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
    .gtior_setting.gtior_b.gtiob  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.obdflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.obhld  = 0U,
    .gtior_setting.gtior_b.obe    = (uint32_t) false,
    .gtior_setting.gtior_b.obdf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfben  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsb  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
#else
          .gtior_setting.gtior = 0U,
#endif
        };

const timer_cfg_t timer12_cfg =
{ .mode = TIMER_MODE_PERIODIC,
/* Actual period: 0.001 seconds. Actual duty: 50%. */.period_counts = (uint32_t) 0xea60,
  .duty_cycle_counts = 0x7530, .source_div = (timer_source_div_t) 1, .channel = 12, .p_callback = timer12_callback,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = &timer12_extend,
  .cycle_end_ipl = (1),
#if defined(VECTOR_NUMBER_GPT12_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GPT12_COUNTER_OVERFLOW,
#else
  .cycle_end_irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const timer_instance_t timer12 =
{ .p_ctrl = &timer12_ctrl, .p_cfg = &timer12_cfg, .p_api = &g_timer_on_gpt };
gpt_instance_ctrl_t timer13_ctrl;
#if 0
const gpt_extended_pwm_cfg_t timer13_pwm_extend =
{
    .trough_ipl          = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT13_COUNTER_UNDERFLOW)
    .trough_irq          = VECTOR_NUMBER_GPT13_COUNTER_UNDERFLOW,
#else
    .trough_irq          = FSP_INVALID_VECTOR,
#endif
    .poeg_link           = GPT_POEG_LINK_POEG0,
    .output_disable      = (gpt_output_disable_t) ( GPT_OUTPUT_DISABLE_NONE),
    .adc_trigger         = (gpt_adc_trigger_t) ( GPT_ADC_TRIGGER_NONE),
    .dead_time_count_up  = 0,
    .dead_time_count_down = 0,
    .adc_a_compare_match = 0,
    .adc_b_compare_match = 0,
    .interrupt_skip_source = GPT_INTERRUPT_SKIP_SOURCE_NONE,
    .interrupt_skip_count  = GPT_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_adc    = GPT_INTERRUPT_SKIP_ADC_NONE,
    .gtioca_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
    .gtiocb_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
};
#endif
const gpt_extended_cfg_t timer13_extend =
        { .gtioca =
        { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
          .gtiocb =
          { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
          .start_source = (gpt_source_t) (GPT_SOURCE_NONE), .stop_source = (gpt_source_t) (GPT_SOURCE_NONE), .clear_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .count_up_source = (gpt_source_t) (GPT_SOURCE_NONE), .count_down_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .capture_b_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_ipl = (BSP_IRQ_DISABLED), .capture_b_ipl =
                  (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT13_CAPTURE_COMPARE_A)
    .capture_a_irq       = VECTOR_NUMBER_GPT13_CAPTURE_COMPARE_A,
#else
          .capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT13_CAPTURE_COMPARE_B)
    .capture_b_irq       = VECTOR_NUMBER_GPT13_CAPTURE_COMPARE_B,
#else
          .capture_b_irq = FSP_INVALID_VECTOR,
#endif
          .compare_match_value =
          { /* CMP_A */0x0, /* CMP_B */0x0 },
          .compare_match_status = (0U << 1U) | 0U, .capture_filter_gtioca = GPT_CAPTURE_FILTER_NONE, .capture_filter_gtiocb =
                  GPT_CAPTURE_FILTER_NONE,
#if 0
    .p_pwm_cfg                   = &timer13_pwm_extend,
#else
          .p_pwm_cfg = NULL,
#endif
#if 0
    .gtior_setting.gtior_b.gtioa  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.oadflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.oahld  = 0U,
    .gtior_setting.gtior_b.oae    = (uint32_t) false,
    .gtior_setting.gtior_b.oadf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfaen  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsa  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
    .gtior_setting.gtior_b.gtiob  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.obdflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.obhld  = 0U,
    .gtior_setting.gtior_b.obe    = (uint32_t) false,
    .gtior_setting.gtior_b.obdf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfben  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsb  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
#else
          .gtior_setting.gtior = 0U,
#endif
        };

const timer_cfg_t timer13_cfg =
{ .mode = TIMER_MODE_PERIODIC,
/* Actual period: 0.01 seconds. Actual duty: 50%. */.period_counts = (uint32_t) 0x927c,
  .duty_cycle_counts = 0x493e, .source_div = (timer_source_div_t) 5, .channel = 13, .p_callback = timer13_callback,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = &timer13_extend,
  .cycle_end_ipl = (2),
#if defined(VECTOR_NUMBER_GPT13_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GPT13_COUNTER_OVERFLOW,
#else
  .cycle_end_irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const timer_instance_t timer13 =
{ .p_ctrl = &timer13_ctrl, .p_cfg = &timer13_cfg, .p_api = &g_timer_on_gpt };
gpt_instance_ctrl_t timer6_ctrl;
#if 0
const gpt_extended_pwm_cfg_t timer6_pwm_extend =
{
    .trough_ipl          = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT6_COUNTER_UNDERFLOW)
    .trough_irq          = VECTOR_NUMBER_GPT6_COUNTER_UNDERFLOW,
#else
    .trough_irq          = FSP_INVALID_VECTOR,
#endif
    .poeg_link           = GPT_POEG_LINK_POEG0,
    .output_disable      = (gpt_output_disable_t) ( GPT_OUTPUT_DISABLE_NONE),
    .adc_trigger         = (gpt_adc_trigger_t) ( GPT_ADC_TRIGGER_NONE),
    .dead_time_count_up  = 0,
    .dead_time_count_down = 0,
    .adc_a_compare_match = 0,
    .adc_b_compare_match = 0,
    .interrupt_skip_source = GPT_INTERRUPT_SKIP_SOURCE_NONE,
    .interrupt_skip_count  = GPT_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_adc    = GPT_INTERRUPT_SKIP_ADC_NONE,
    .gtioca_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
    .gtiocb_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
};
#endif
const gpt_extended_cfg_t timer6_extend =
        { .gtioca =
        { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
          .gtiocb =
          { .output_enabled = true, .stop_level = GPT_PIN_LEVEL_LOW },
          .start_source = (gpt_source_t) (GPT_SOURCE_NONE), .stop_source = (gpt_source_t) (GPT_SOURCE_NONE), .clear_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .count_up_source = (gpt_source_t) (GPT_SOURCE_NONE), .count_down_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .capture_b_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_ipl = (BSP_IRQ_DISABLED), .capture_b_ipl =
                  (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT6_CAPTURE_COMPARE_A)
    .capture_a_irq       = VECTOR_NUMBER_GPT6_CAPTURE_COMPARE_A,
#else
          .capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT6_CAPTURE_COMPARE_B)
    .capture_b_irq       = VECTOR_NUMBER_GPT6_CAPTURE_COMPARE_B,
#else
          .capture_b_irq = FSP_INVALID_VECTOR,
#endif
          .compare_match_value =
          { /* CMP_A */0x0, /* CMP_B */0x0 },
          .compare_match_status = (0U << 1U) | 0U, .capture_filter_gtioca = GPT_CAPTURE_FILTER_NONE, .capture_filter_gtiocb =
                  GPT_CAPTURE_FILTER_NONE,
#if 0
    .p_pwm_cfg                   = &timer6_pwm_extend,
#else
          .p_pwm_cfg = NULL,
#endif
#if 0
    .gtior_setting.gtior_b.gtioa  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.oadflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.oahld  = 0U,
    .gtior_setting.gtior_b.oae    = (uint32_t) false,
    .gtior_setting.gtior_b.oadf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfaen  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsa  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
    .gtior_setting.gtior_b.gtiob  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.obdflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.obhld  = 0U,
    .gtior_setting.gtior_b.obe    = (uint32_t) true,
    .gtior_setting.gtior_b.obdf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfben  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsb  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
#else
          .gtior_setting.gtior = 0U,
#endif
        };

const timer_cfg_t timer6_cfg =
{ .mode = TIMER_MODE_PWM,
/* Actual period: 0.00005 seconds. Actual duty: 50%. */.period_counts = (uint32_t) 0x1770,
  .duty_cycle_counts = 0xbb8, .source_div = (timer_source_div_t) 0, .channel = 6, .p_callback = NULL,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = &timer6_extend,
  .cycle_end_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT6_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GPT6_COUNTER_OVERFLOW,
#else
  .cycle_end_irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const timer_instance_t timer6 =
{ .p_ctrl = &timer6_ctrl, .p_cfg = &timer6_cfg, .p_api = &g_timer_on_gpt };
adc_instance_ctrl_t g_adc0_ctrl;
const adc_extended_cfg_t g_adc0_cfg_extend =
{ .add_average_count = ADC_ADD_OFF,
  .clearing = ADC_CLEAR_AFTER_READ_ON,
  .trigger = ADC_START_SOURCE_DISABLED,
  .trigger_group_b = ADC_START_SOURCE_DISABLED,
  .double_trigger_mode = ADC_DOUBLE_TRIGGER_DISABLED,
  .adc_vref_control = ADC_VREF_CONTROL_VREFH,
  .enable_adbuf = 0,
#if defined(VECTOR_NUMBER_ADC0_WINDOW_A)
    .window_a_irq        = VECTOR_NUMBER_ADC0_WINDOW_A,
#else
  .window_a_irq = FSP_INVALID_VECTOR,
#endif
  .window_a_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_ADC0_WINDOW_B)
    .window_b_irq      = VECTOR_NUMBER_ADC0_WINDOW_B,
#else
  .window_b_irq = FSP_INVALID_VECTOR,
#endif
  .window_b_ipl = (BSP_IRQ_DISABLED), };
const adc_cfg_t g_adc0_cfg =
{ .unit = 0, .mode = ADC_MODE_SINGLE_SCAN, .resolution = ADC_RESOLUTION_12_BIT, .alignment =
          (adc_alignment_t) ADC_ALIGNMENT_RIGHT,
  .trigger = (adc_trigger_t) 0xF, // Not used
  .p_callback = adc_callback,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = &g_adc0_cfg_extend,
#if defined(VECTOR_NUMBER_ADC0_SCAN_END)
    .scan_end_irq        = VECTOR_NUMBER_ADC0_SCAN_END,
#else
  .scan_end_irq = FSP_INVALID_VECTOR,
#endif
  .scan_end_ipl = (2),
#if defined(VECTOR_NUMBER_ADC0_SCAN_END_B)
    .scan_end_b_irq      = VECTOR_NUMBER_ADC0_SCAN_END_B,
#else
  .scan_end_b_irq = FSP_INVALID_VECTOR,
#endif
  .scan_end_b_ipl = (BSP_IRQ_DISABLED), };
#if ((0) | (0))
const adc_window_cfg_t g_adc0_window_cfg =
{
    .compare_mask        =  0,
    .compare_mode_mask   =  0,
    .compare_cfg         = (0) | (0) | (0) | (ADC_COMPARE_CFG_EVENT_OUTPUT_OR),
    .compare_ref_low     = 0,
    .compare_ref_high    = 0,
    .compare_b_channel   = (ADC_WINDOW_B_CHANNEL_0),
    .compare_b_mode      = (ADC_WINDOW_B_MODE_LESS_THAN_OR_OUTSIDE),
    .compare_b_ref_low   = 0,
    .compare_b_ref_high  = 0,
};
#endif
const adc_channel_cfg_t g_adc0_channel_cfg =
{ .scan_mask = ADC_MASK_CHANNEL_0 | ADC_MASK_CHANNEL_4 | 0, .scan_mask_group_b = 0, .priority_group_a =
          ADC_GROUP_A_PRIORITY_OFF,
  .add_mask = 0, .sample_hold_mask = 0, .sample_hold_states = 24,
#if ((0) | (0))
    .p_window_cfg        = (adc_window_cfg_t *) &g_adc0_window_cfg,
#else
  .p_window_cfg = NULL,
#endif
        };
/* Instance structure to use this module. */
const adc_instance_t g_adc0 =
{ .p_ctrl = &g_adc0_ctrl, .p_cfg = &g_adc0_cfg, .p_channel_cfg = &g_adc0_channel_cfg, .p_api = &g_adc_on_adc };
sci_b_uart_instance_ctrl_t esp_uart_ctrl;

sci_b_baud_setting_t esp_uart_baud_setting =
        {
        /* Baud rate calculated with 0.000% error. */.baudrate_bits_b.abcse = 1,
          .baudrate_bits_b.abcs = 0, .baudrate_bits_b.bgdm = 0, .baudrate_bits_b.cks = 0, .baudrate_bits_b.brr = 9, .baudrate_bits_b.mddr =
                  (uint8_t) 256,
          .baudrate_bits_b.brme = false };

/** UART extended configuration for UARTonSCI HAL driver */
const sci_b_uart_extended_cfg_t esp_uart_cfg_extend =
{ .clock = SCI_B_UART_CLOCK_INT, .rx_edge_start = SCI_B_UART_START_BIT_FALLING_EDGE, .noise_cancel =
          SCI_B_UART_NOISE_CANCELLATION_DISABLE,
  .rx_fifo_trigger = SCI_B_UART_RX_FIFO_TRIGGER_MAX, .p_baud_setting = &esp_uart_baud_setting, .flow_control =
          SCI_B_UART_FLOW_CONTROL_RTS,
#if 0xFF != 0xFF
                .flow_control_pin       = BSP_IO_PORT_FF_PIN_0xFF,
                #else
  .flow_control_pin = (bsp_io_port_pin_t) UINT16_MAX,
#endif
  .rs485_setting =
  { .enable = SCI_B_UART_RS485_DISABLE,
    .polarity = SCI_B_UART_RS485_DE_POLARITY_HIGH,
    .assertion_time = 1,
    .negation_time = 1, } };

/** UART interface configuration */
const uart_cfg_t esp_uart_cfg =
{ .channel = 4, .data_bits = UART_DATA_BITS_8, .parity = UART_PARITY_OFF, .stop_bits = UART_STOP_BITS_1, .p_callback =
          esp_uart_callback,
  .p_context = NULL, .p_extend = &esp_uart_cfg_extend,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_tx = NULL,
#else
                .p_transfer_tx       = &RA_NOT_DEFINED,
#endif
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_rx = NULL,
#else
                .p_transfer_rx       = &RA_NOT_DEFINED,
#endif
#undef RA_NOT_DEFINED
  .rxi_ipl = (12),
  .txi_ipl = (12), .tei_ipl = (12), .eri_ipl = (12),
#if defined(VECTOR_NUMBER_SCI4_RXI)
                .rxi_irq             = VECTOR_NUMBER_SCI4_RXI,
#else
  .rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI4_TXI)
                .txi_irq             = VECTOR_NUMBER_SCI4_TXI,
#else
  .txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI4_TEI)
                .tei_irq             = VECTOR_NUMBER_SCI4_TEI,
#else
  .tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI4_ERI)
                .eri_irq             = VECTOR_NUMBER_SCI4_ERI,
#else
  .eri_irq = FSP_INVALID_VECTOR,
#endif
        };

/* Instance structure to use this module. */
const uart_instance_t esp_uart =
{ .p_ctrl = &esp_uart_ctrl, .p_cfg = &esp_uart_cfg, .p_api = &g_uart_on_sci_b };
sci_b_uart_instance_ctrl_t g_uart3_ctrl;

sci_b_baud_setting_t g_uart3_baud_setting =
        {
        /* Baud rate calculated with 0.000% error. */.baudrate_bits_b.abcse = 1,
          .baudrate_bits_b.abcs = 0, .baudrate_bits_b.bgdm = 0, .baudrate_bits_b.cks = 0, .baudrate_bits_b.brr = 9, .baudrate_bits_b.mddr =
                  (uint8_t) 256,
          .baudrate_bits_b.brme = false };

/** UART extended configuration for UARTonSCI HAL driver */
const sci_b_uart_extended_cfg_t g_uart3_cfg_extend =
{ .clock = SCI_B_UART_CLOCK_INT, .rx_edge_start = SCI_B_UART_START_BIT_FALLING_EDGE, .noise_cancel =
          SCI_B_UART_NOISE_CANCELLATION_DISABLE,
  .rx_fifo_trigger = SCI_B_UART_RX_FIFO_TRIGGER_MAX, .p_baud_setting = &g_uart3_baud_setting, .flow_control =
          SCI_B_UART_FLOW_CONTROL_RTS,
#if 0xFF != 0xFF
                .flow_control_pin       = BSP_IO_PORT_FF_PIN_0xFF,
                #else
  .flow_control_pin = (bsp_io_port_pin_t) UINT16_MAX,
#endif
  .rs485_setting =
  { .enable = SCI_B_UART_RS485_DISABLE,
    .polarity = SCI_B_UART_RS485_DE_POLARITY_HIGH,
    .assertion_time = 1,
    .negation_time = 1, } };

/** UART interface configuration */
const uart_cfg_t g_uart3_cfg =
{ .channel = 3, .data_bits = UART_DATA_BITS_8, .parity = UART_PARITY_OFF, .stop_bits = UART_STOP_BITS_1, .p_callback =
          debug_uart3_callback,
  .p_context = NULL, .p_extend = &g_uart3_cfg_extend,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_tx = NULL,
#else
                .p_transfer_tx       = &RA_NOT_DEFINED,
#endif
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_rx = NULL,
#else
                .p_transfer_rx       = &RA_NOT_DEFINED,
#endif
#undef RA_NOT_DEFINED
  .rxi_ipl = (12),
  .txi_ipl = (12), .tei_ipl = (12), .eri_ipl = (12),
#if defined(VECTOR_NUMBER_SCI3_RXI)
                .rxi_irq             = VECTOR_NUMBER_SCI3_RXI,
#else
  .rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI3_TXI)
                .txi_irq             = VECTOR_NUMBER_SCI3_TXI,
#else
  .txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI3_TEI)
                .tei_irq             = VECTOR_NUMBER_SCI3_TEI,
#else
  .tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI3_ERI)
                .eri_irq             = VECTOR_NUMBER_SCI3_ERI,
#else
  .eri_irq = FSP_INVALID_VECTOR,
#endif
        };

/* Instance structure to use this module. */
const uart_instance_t g_uart3 =
{ .p_ctrl = &g_uart3_ctrl, .p_cfg = &g_uart3_cfg, .p_api = &g_uart_on_sci_b };
void g_hal_init(void)
{
    g_common_init ();
}
