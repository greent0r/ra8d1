################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/GUI/lvgl-9.2.1/src/core/lv_group.c \
../src/GUI/lvgl-9.2.1/src/core/lv_obj.c \
../src/GUI/lvgl-9.2.1/src/core/lv_obj_class.c \
../src/GUI/lvgl-9.2.1/src/core/lv_obj_draw.c \
../src/GUI/lvgl-9.2.1/src/core/lv_obj_event.c \
../src/GUI/lvgl-9.2.1/src/core/lv_obj_id_builtin.c \
../src/GUI/lvgl-9.2.1/src/core/lv_obj_pos.c \
../src/GUI/lvgl-9.2.1/src/core/lv_obj_property.c \
../src/GUI/lvgl-9.2.1/src/core/lv_obj_scroll.c \
../src/GUI/lvgl-9.2.1/src/core/lv_obj_style.c \
../src/GUI/lvgl-9.2.1/src/core/lv_obj_style_gen.c \
../src/GUI/lvgl-9.2.1/src/core/lv_obj_tree.c \
../src/GUI/lvgl-9.2.1/src/core/lv_refr.c 

C_DEPS += \
./src/GUI/lvgl-9.2.1/src/core/lv_group.d \
./src/GUI/lvgl-9.2.1/src/core/lv_obj.d \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_class.d \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_draw.d \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_event.d \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_id_builtin.d \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_pos.d \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_property.d \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_scroll.d \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_style.d \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_style_gen.d \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_tree.d \
./src/GUI/lvgl-9.2.1/src/core/lv_refr.d 

CREF += \
newnewnew.cref 

OBJS += \
./src/GUI/lvgl-9.2.1/src/core/lv_group.o \
./src/GUI/lvgl-9.2.1/src/core/lv_obj.o \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_class.o \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_draw.o \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_event.o \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_id_builtin.o \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_pos.o \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_property.o \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_scroll.o \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_style.o \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_style_gen.o \
./src/GUI/lvgl-9.2.1/src/core/lv_obj_tree.o \
./src/GUI/lvgl-9.2.1/src/core/lv_refr.o 

MAP += \
newnewnew.map 


# Each subdirectory must supply rules for building sources it contributes
src/GUI/lvgl-9.2.1/src/core/%.o: ../src/GUI/lvgl-9.2.1/src/core/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-m85 -mthumb -mlittle-endian -mfloat-abi=hard -O2 -ffunction-sections -fdata-sections -fno-strict-aliasing -fmessage-length=0 -funsigned-char -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wno-parentheses-equality -Wfloat-equal -g3 -std=c99 -flax-vector-conversions -fshort-enums -fno-unroll-loops -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\CEU" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\DISPLAY" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\FILE" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\GUI" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\GUI\\guider_customer_fonts" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\GUI\\lvgl-9.2.1" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\HX711" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\KEY_BEEP_LED" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\MAX17048" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\MAX6675" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\MQ4_MQ5" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\SDRAM" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\SNR9816" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\WIFI" -I"." -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra\\fsp\\inc" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra\\fsp\\inc\\api" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra\\fsp\\inc\\instances" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra\\fsp\\src\\rm_freertos_port" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra\\aws\\FreeRTOS\\FreeRTOS\\Source\\include" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra\\arm\\CMSIS_5\\CMSIS\\Core\\Include" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra_gen" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra_cfg\\fsp_cfg\\bsp" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra_cfg\\fsp_cfg" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra_cfg\\aws" -D_RENESAS_RA_ -D_RA_CORE=CM85 -D_RA_ORDINAL=1 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -x c "$<" -c -o "$@")
	@clang --target=arm-none-eabi @"$@.in"

