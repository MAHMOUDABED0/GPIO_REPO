################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_GPIO_DRIVER/lcd_diver/lcd.c 

OBJS += \
./STM32_GPIO_DRIVER/lcd_diver/lcd.o 

C_DEPS += \
./STM32_GPIO_DRIVER/lcd_diver/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_GPIO_DRIVER/lcd_diver/lcd.o: ../STM32_GPIO_DRIVER/lcd_diver/lcd.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/stm32/gpio_section3/STM32_GPIO_DRIVER" -I"E:/stm32/gpio_section3/STM32_GPIO_DRIVER/INC" -I"E:/stm32/gpio_section3/STM32_GPIO_DRIVER/keypad_driver" -I"E:/stm32/gpio_section3/STM32_GPIO_DRIVER/lcd_diver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_GPIO_DRIVER/lcd_diver/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

