################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SERVO/SERVO_program.c 

OBJS += \
./HAL/SERVO/SERVO_program.o 

C_DEPS += \
./HAL/SERVO/SERVO_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/SERVO/%.o: ../HAL/SERVO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\AVR_WorkSpace\AVR_Car_Robot_Obstacle_Avoiding\APP" -I"D:\AVR_WorkSpace\AVR_Car_Robot_Obstacle_Avoiding\HAL\SERVO" -I"D:\AVR_WorkSpace\AVR_Car_Robot_Obstacle_Avoiding\HAL\ULTRASONIC" -I"D:\AVR_WorkSpace\AVR_Car_Robot_Obstacle_Avoiding\LIB" -I"D:\AVR_WorkSpace\AVR_Car_Robot_Obstacle_Avoiding\MCAL\DIO" -I"D:\AVR_WorkSpace\AVR_Car_Robot_Obstacle_Avoiding\MCAL\GI" -I"D:\AVR_WorkSpace\AVR_Car_Robot_Obstacle_Avoiding\MCAL\TIMER" -I"D:\AVR_WorkSpace\AVR_Car_Robot_Obstacle_Avoiding\MCAL\UART" -I"D:\AVR_WorkSpace\AVR_Car_Robot_Obstacle_Avoiding\HAL\BUZZER" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


