################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_GPIO_DRIVER/STM32_GPIO_DRIVER.c 

OBJS += \
./STM32_GPIO_DRIVER/STM32_GPIO_DRIVER.o 

C_DEPS += \
./STM32_GPIO_DRIVER/STM32_GPIO_DRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_GPIO_DRIVER/STM32_GPIO_DRIVER.o: ../STM32_GPIO_DRIVER/STM32_GPIO_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/stm32/Gpio_Driver/STM32_GPIO_DRIVER" -I"E:/stm32/Gpio_Driver/STM32_GPIO_DRIVER/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_GPIO_DRIVER/STM32_GPIO_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

