################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/cathy/STM32Cube/Repository/Packs/NimaLTD/I-CUBE-WS28XX/3.0.1/Middlewares/Third_Party/WS28XX/ws28xx.c 

OBJS += \
./Middlewares/I-CUBE-WS28XX/Driver/WS28XX/ws28xx.o 

C_DEPS += \
./Middlewares/I-CUBE-WS28XX/Driver/WS28XX/ws28xx.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/I-CUBE-WS28XX/Driver/WS28XX/ws28xx.o: C:/Users/cathy/STM32Cube/Repository/Packs/NimaLTD/I-CUBE-WS28XX/3.0.1/Middlewares/Third_Party/WS28XX/ws28xx.c Middlewares/I-CUBE-WS28XX/Driver/WS28XX/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -IC:/Users/cathy/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/cathy/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/cathy/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Middlewares/ST/STM32_USB_Device_Library/Core/Inc -IC:/Users/cathy/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -IC:/Users/cathy/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/cathy/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Include -I../I-CUBE-WS28XX -IC:/Users/cathy/STM32Cube/Repository//Packs/NimaLTD/I-CUBE-WS28XX/3.0.1/Middlewares/Third_Party/WS28XX -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-I-2d-CUBE-2d-WS28XX-2f-Driver-2f-WS28XX

clean-Middlewares-2f-I-2d-CUBE-2d-WS28XX-2f-Driver-2f-WS28XX:
	-$(RM) ./Middlewares/I-CUBE-WS28XX/Driver/WS28XX/ws28xx.cyclo ./Middlewares/I-CUBE-WS28XX/Driver/WS28XX/ws28xx.d ./Middlewares/I-CUBE-WS28XX/Driver/WS28XX/ws28xx.o ./Middlewares/I-CUBE-WS28XX/Driver/WS28XX/ws28xx.su

.PHONY: clean-Middlewares-2f-I-2d-CUBE-2d-WS28XX-2f-Driver-2f-WS28XX

