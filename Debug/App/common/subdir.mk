################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/common/def.c 

OBJS += \
./App/common/def.o 

C_DEPS += \
./App/common/def.d 


# Each subdirectory must supply rules for building sources it contributes
App/common/%.o App/common/%.su App/common/%.cyclo: ../App/common/%.c App/common/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/USER/Downloads/droneproject-main/droneproject-main/App" -I"C:/Users/USER/Downloads/droneproject-main/droneproject-main/App/hw" -I"C:/Users/USER/Downloads/droneproject-main/droneproject-main/App/common" -I"C:/Users/USER/Downloads/droneproject-main/droneproject-main/App/ap" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-common

clean-App-2f-common:
	-$(RM) ./App/common/def.cyclo ./App/common/def.d ./App/common/def.o ./App/common/def.su

.PHONY: clean-App-2f-common

