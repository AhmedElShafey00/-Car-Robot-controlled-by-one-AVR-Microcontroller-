################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/BUZZER/BUZZER_program.c 

OBJS += \
./HAL/BUZZER/BUZZER_program.o 

C_DEPS += \
./HAL/BUZZER/BUZZER_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/BUZZER/%.o: ../HAL/BUZZER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\AVR_WorkSpace\AVR_Car_Robot_Obstacle_Avoiding\APP" -I"D:\AVR_WorkSpace\AVR_Car_Robot_Obstacle_Avoiding\HAL\SERVO" -I"D:\AVR_WorkSpace\AVR_Car_Robot_Obstacle_Avoiding\HAL\ULTRASONIC" -I"D:\AVR_WorkSpace\AVR_Car_Robot_Obstacle_Avoiding\LIB" -I"D:\AVR_WorkSpace\AVR_Car_Robot_Obstacle_Avoiding\MCAL\DIO" -I"D:\AVR_WorkSpace\AVR_Car_Robot_Obstacle_Avoiding\MCAL\GI" -I"D:\AVR_WorkSpace\AVR_Car_Robot_Obstacle_Avoiding\MCAL\TIMER" -I"D:\AVR_WorkSpace\AVR_Car_Robot_Obstacle_Avoiding\MCAL\UART" -I"D:\AVR_WorkSpace\AVR_Car_Robot_Obstacle_Avoiding\HAL\BUZZER" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


