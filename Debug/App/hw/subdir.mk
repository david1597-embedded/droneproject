################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/hw/BATTERY.c \
../App/hw/CONTROLLER.c \
../App/hw/ICM20948.c \
../App/hw/MOTOR.c \
../App/hw/PID_control.c \
../App/hw/SD.c \
../App/hw/Ultrasonic.c \
../App/hw/hw.c 

OBJS += \
./App/hw/BATTERY.o \
./App/hw/CONTROLLER.o \
./App/hw/ICM20948.o \
./App/hw/MOTOR.o \
./App/hw/PID_control.o \
./App/hw/SD.o \
./App/hw/Ultrasonic.o \
./App/hw/hw.o 

C_DEPS += \
./App/hw/BATTERY.d \
./App/hw/CONTROLLER.d \
./App/hw/ICM20948.d \
./App/hw/MOTOR.d \
./App/hw/PID_control.d \
./App/hw/SD.d \
./App/hw/Ultrasonic.d \
./App/hw/hw.d 


# Each subdirectory must supply rules for building sources it contributes
App/hw/%.o App/hw/%.su App/hw/%.cyclo: ../App/hw/%.c App/hw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/USER/Downloads/droneproject-main/droneproject-main/App" -I"C:/Users/USER/Downloads/droneproject-main/droneproject-main/App/hw" -I"C:/Users/USER/Downloads/droneproject-main/droneproject-main/App/common" -I"C:/Users/USER/Downloads/droneproject-main/droneproject-main/App/ap" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-hw

clean-App-2f-hw:
	-$(RM) ./App/hw/BATTERY.cyclo ./App/hw/BATTERY.d ./App/hw/BATTERY.o ./App/hw/BATTERY.su ./App/hw/CONTROLLER.cyclo ./App/hw/CONTROLLER.d ./App/hw/CONTROLLER.o ./App/hw/CONTROLLER.su ./App/hw/ICM20948.cyclo ./App/hw/ICM20948.d ./App/hw/ICM20948.o ./App/hw/ICM20948.su ./App/hw/MOTOR.cyclo ./App/hw/MOTOR.d ./App/hw/MOTOR.o ./App/hw/MOTOR.su ./App/hw/PID_control.cyclo ./App/hw/PID_control.d ./App/hw/PID_control.o ./App/hw/PID_control.su ./App/hw/SD.cyclo ./App/hw/SD.d ./App/hw/SD.o ./App/hw/SD.su ./App/hw/Ultrasonic.cyclo ./App/hw/Ultrasonic.d ./App/hw/Ultrasonic.o ./App/hw/Ultrasonic.su ./App/hw/hw.cyclo ./App/hw/hw.d ./App/hw/hw.o ./App/hw/hw.su

.PHONY: clean-App-2f-hw

