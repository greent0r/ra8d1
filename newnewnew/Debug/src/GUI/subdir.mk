################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/GUI/custom.c \
../src/GUI/events_init.c \
../src/GUI/gui_guider.c \
../src/GUI/lv_port_disp.c \
../src/GUI/lv_port_indev.c \
../src/GUI/setup_scr_camera.c \
../src/GUI/setup_scr_main.c \
../src/GUI/setup_scr_recipe_all.c \
../src/GUI/setup_scr_recipe_cook.c \
../src/GUI/setup_scr_recipe_main.c \
../src/GUI/setup_scr_recipe_one.c \
../src/GUI/setup_scr_recipe_plan.c \
../src/GUI/setup_scr_recognize.c \
../src/GUI/setup_scr_setting.c \
../src/GUI/setup_scr_tool.c \
../src/GUI/widgets_init.c 

C_DEPS += \
./src/GUI/custom.d \
./src/GUI/events_init.d \
./src/GUI/gui_guider.d \
./src/GUI/lv_port_disp.d \
./src/GUI/lv_port_indev.d \
./src/GUI/setup_scr_camera.d \
./src/GUI/setup_scr_main.d \
./src/GUI/setup_scr_recipe_all.d \
./src/GUI/setup_scr_recipe_cook.d \
./src/GUI/setup_scr_recipe_main.d \
./src/GUI/setup_scr_recipe_one.d \
./src/GUI/setup_scr_recipe_plan.d \
./src/GUI/setup_scr_recognize.d \
./src/GUI/setup_scr_setting.d \
./src/GUI/setup_scr_tool.d \
./src/GUI/widgets_init.d 

CREF += \
newnewnew.cref 

OBJS += \
./src/GUI/custom.o \
./src/GUI/events_init.o \
./src/GUI/gui_guider.o \
./src/GUI/lv_port_disp.o \
./src/GUI/lv_port_indev.o \
./src/GUI/setup_scr_camera.o \
./src/GUI/setup_scr_main.o \
./src/GUI/setup_scr_recipe_all.o \
./src/GUI/setup_scr_recipe_cook.o \
./src/GUI/setup_scr_recipe_main.o \
./src/GUI/setup_scr_recipe_one.o \
./src/GUI/setup_scr_recipe_plan.o \
./src/GUI/setup_scr_recognize.o \
./src/GUI/setup_scr_setting.o \
./src/GUI/setup_scr_tool.o \
./src/GUI/widgets_init.o 

MAP += \
newnewnew.map 


# Each subdirectory must supply rules for building sources it contributes
src/GUI/%.o: ../src/GUI/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-m85 -mthumb -mlittle-endian -mfloat-abi=hard -O2 -ffunction-sections -fdata-sections -fno-strict-aliasing -fmessage-length=0 -funsigned-char -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wno-parentheses-equality -Wfloat-equal -g3 -std=c99 -flax-vector-conversions -fshort-enums -fno-unroll-loops -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\CEU" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\DISPLAY" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\FILE" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\GUI" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\GUI\\guider_customer_fonts" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\GUI\\lvgl-9.2.1" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\HX711" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\KEY_BEEP_LED" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\MAX17048" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\MAX6675" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\MQ4_MQ5" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\SDRAM" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\SNR9816" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\src\\WIFI" -I"." -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra\\fsp\\inc" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra\\fsp\\inc\\api" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra\\fsp\\inc\\instances" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra\\fsp\\src\\rm_freertos_port" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra\\aws\\FreeRTOS\\FreeRTOS\\Source\\include" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra\\arm\\CMSIS_5\\CMSIS\\Core\\Include" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra_gen" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra_cfg\\fsp_cfg\\bsp" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra_cfg\\fsp_cfg" -I"H:\\MyDocument\\project\\ra8d1\\newnewnew\\ra_cfg\\aws" -D_RENESAS_RA_ -D_RA_CORE=CM85 -D_RA_ORDINAL=1 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -x c "$<" -c -o "$@")
	@clang --target=arm-none-eabi @"$@.in"

