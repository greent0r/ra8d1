################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/bsp/mcu/all/bsp_clocks.c \
../ra/fsp/src/bsp/mcu/all/bsp_common.c \
../ra/fsp/src/bsp/mcu/all/bsp_delay.c \
../ra/fsp/src/bsp/mcu/all/bsp_group_irq.c \
../ra/fsp/src/bsp/mcu/all/bsp_guard.c \
../ra/fsp/src/bsp/mcu/all/bsp_io.c \
../ra/fsp/src/bsp/mcu/all/bsp_irq.c \
../ra/fsp/src/bsp/mcu/all/bsp_macl.c \
../ra/fsp/src/bsp/mcu/all/bsp_register_protection.c \
../ra/fsp/src/bsp/mcu/all/bsp_rom_registers.c \
../ra/fsp/src/bsp/mcu/all/bsp_sbrk.c \
../ra/fsp/src/bsp/mcu/all/bsp_security.c 

C_DEPS += \
./ra/fsp/src/bsp/mcu/all/bsp_clocks.d \
./ra/fsp/src/bsp/mcu/all/bsp_common.d \
./ra/fsp/src/bsp/mcu/all/bsp_delay.d \
./ra/fsp/src/bsp/mcu/all/bsp_group_irq.d \
./ra/fsp/src/bsp/mcu/all/bsp_guard.d \
./ra/fsp/src/bsp/mcu/all/bsp_io.d \
./ra/fsp/src/bsp/mcu/all/bsp_irq.d \
./ra/fsp/src/bsp/mcu/all/bsp_macl.d \
./ra/fsp/src/bsp/mcu/all/bsp_register_protection.d \
./ra/fsp/src/bsp/mcu/all/bsp_rom_registers.d \
./ra/fsp/src/bsp/mcu/all/bsp_sbrk.d \
./ra/fsp/src/bsp/mcu/all/bsp_security.d 

CREF += \
newnewnew.cref 

OBJS += \
./ra/fsp/src/bsp/mcu/all/bsp_clocks.o \
./ra/fsp/src/bsp/mcu/all/bsp_common.o \
./ra/fsp/src/bsp/mcu/all/bsp_delay.o \
./ra/fsp/src/bsp/mcu/all/bsp_group_irq.o \
./ra/fsp/src/bsp/mcu/all/bsp_guard.o \
./ra/fsp/src/bsp/mcu/all/bsp_io.o \
./ra/fsp/src/bsp/mcu/all/bsp_irq.o \
./ra/fsp/src/bsp/mcu/all/bsp_macl.o \
./ra/fsp/src/bsp/mcu/all/bsp_register_protection.o \
./ra/fsp/src/bsp/mcu/all/bsp_rom_registers.o \
./ra/fsp/src/bsp/mcu/all/bsp_sbrk.o \
./ra/fsp/src/bsp/mcu/all/bsp_security.o 

MAP += \
newnewnew.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/bsp/mcu/all/%.o: ../ra/fsp/src/bsp/mcu/all/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-m85 -mthumb -mlittle-endian -mfloat-abi=hard -O2 -ffunction-sections -fdata-sections -fno-strict-aliasing -fmessage-length=0 -funsigned-char -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wno-parentheses-equality -Wfloat-equal -g3 -std=c99 -flax-vector-conversions -fshort-enums -fno-unroll-loops -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\CEU" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\DISPLAY" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\FILE" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\GUI" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\GUI\\guider_customer_fonts" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\GUI\\lvgl-9.2.1" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\HX711" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\KEY_BEEP_LED" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\MAX17048" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\MAX6675" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\MQ4_MQ5" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\SDRAM" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\SNR9816" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\WIFI" -I"." -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra\\fsp\\inc" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra\\fsp\\inc\\api" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra\\fsp\\inc\\instances" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra\\fsp\\src\\rm_freertos_port" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra\\aws\\FreeRTOS\\FreeRTOS\\Source\\include" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra\\arm\\CMSIS_5\\CMSIS\\Core\\Include" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra_gen" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra_cfg\\fsp_cfg\\bsp" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra_cfg\\fsp_cfg" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra_cfg\\aws" -D_RENESAS_RA_ -D_RA_CORE=CM85 -D_RA_ORDINAL=1 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -x c "$<" -c -o "$@")
	@clang --target=arm-none-eabi @"$@.in"

