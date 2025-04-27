################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/stm32-hal-mcp2515/mcp2515.cpp 

OBJS += \
./Core/Inc/stm32-hal-mcp2515/mcp2515.o 

CPP_DEPS += \
./Core/Inc/stm32-hal-mcp2515/mcp2515.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/stm32-hal-mcp2515/%.o Core/Inc/stm32-hal-mcp2515/%.su Core/Inc/stm32-hal-mcp2515/%.cyclo: ../Core/Inc/stm32-hal-mcp2515/%.cpp Core/Inc/stm32-hal-mcp2515/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -IC:/Users/cathy/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/cathy/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/cathy/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Middlewares/ST/STM32_USB_Device_Library/Core/Inc -IC:/Users/cathy/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -IC:/Users/cathy/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/cathy/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Include -IC:/Users/cathy/STM32Cube/Repository//Packs/NimaLTD/I-CUBE-WS28XX/3.0.1/Middlewares/Third_Party/WS28XX -I../I-CUBE-WS28XX -I"C:/Users/cathy/STM32CubeIDE/workspace_1.17.0/Display_STM32/Core/Src" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-stm32-2d-hal-2d-mcp2515

clean-Core-2f-Inc-2f-stm32-2d-hal-2d-mcp2515:
	-$(RM) ./Core/Inc/stm32-hal-mcp2515/mcp2515.cyclo ./Core/Inc/stm32-hal-mcp2515/mcp2515.d ./Core/Inc/stm32-hal-mcp2515/mcp2515.o ./Core/Inc/stm32-hal-mcp2515/mcp2515.su

.PHONY: clean-Core-2f-Inc-2f-stm32-2d-hal-2d-mcp2515

