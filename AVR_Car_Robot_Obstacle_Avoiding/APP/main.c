/****************************************************************************************************************************/
/***************** Author : IMT team **********************************************************************************/
/***************** File : Robot *********************************************************************************************/
/***************** Date : 1/5/2023  ***************************************************************************************/
/***************** Version : 1.0  *******************************************************************************************/
/***************** Description :   APP         ******************************************************************************/
/****************************************************************************************************************************/
/* LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "stdio.h"
#define  F_CPU 8000000UL
#include <util/delay.h>
/* MCAL */
#include "DIO_interface.h"
#include "UART_interface.h"
#include "TIMER_interface.h"
/* HAL */
#include "SERVO_interface.h"
#include "ULTRASONIC_interface.h"
#include "BUZZER_interface.h"
/*********************************************************** Configuration *****************************************************************/
/* Configuration L298 Port and pits */
#define Robot_u8_MOTOR_DRIVER_L298_PORT            DIO_u8_PORTA
#define Robot_u8_MOTOR_DRIVER_L298_IN1             DIO_u8_PIN0
#define Robot_u8_MOTOR_DRIVER_L298_IN2             DIO_u8_PIN1
#define Robot_u8_MOTOR_DRIVER_L298_IN3             DIO_u8_PIN2
#define Robot_u8_MOTOR_DRIVER_L298_IN4             DIO_u8_PIN3
/* Init modes Speeds*/
#define Robot_u8_INIT_SPEED                        60 	/* 60 % */
#define Robot_u8_ObstacleAvoidingMode_SPEED        60  	/* 60 % */
/****************************************************************** Speed ******************************************************************/
void Robot_voidSpeed(u8 Copy_u8SpeedIntinsty)
{
	/* Speed control by Timer0 and Timer2 */
	TIMER_voidTimer0GeneratePWM(Copy_u8SpeedIntinsty);
	TIMER_voidTimer2GeneratePWM(Copy_u8SpeedIntinsty);
}
/************************************************************* Directions ******************************************************************/
void Robot_voidStop(void)
{
	/* Stop motors */
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN1,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN2,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN3,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN4,DIO_u8_LOW);
}
void Robot_voidForward(void)
{
	/* all motors forward */
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN1,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN2,DIO_u8_HIGH);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN3,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN4,DIO_u8_HIGH);
}
void Robot_voidBackward(void)
{
	/* all motors Backward */
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN1,DIO_u8_HIGH);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN2,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN3,DIO_u8_HIGH);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN4,DIO_u8_LOW);
}
void Robot_voidLeft(void)
{
	/* Left motors forward and Right motors Backward */
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN1,DIO_u8_HIGH);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN2,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN3,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN4,DIO_u8_HIGH);
}
void Robot_voidRight(void)
{
	/* Left motors Backward and Right motors forward */
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN1,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN2,DIO_u8_HIGH);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN3,DIO_u8_HIGH);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN4,DIO_u8_LOW);
}
void Robot_voidStep(void)
{
	/* After Stop take Step */
	Robot_voidSpeed(60);
	Robot_voidForward();
	_delay_ms(170);
}
void Robot_voidRight90(void)
{
	/* turn 90 degree Right */
	Robot_voidSpeed(60);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN1,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN2,DIO_u8_HIGH);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN3,DIO_u8_HIGH);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN4,DIO_u8_LOW);
	/* value of delay will change by change (voltage and arena) */
    BUZZER_voidBuzzer_Work(BUZZER_ON);
    _delay_ms(200);
    BUZZER_voidBuzzer_Work(BUZZER_OFF);
    _delay_ms(200);
	_delay_ms(100);
	Robot_voidStop();
	Robot_voidSpeed(Robot_u8_INIT_SPEED);

}
void Robot_voidLeft90(void)
{
	/* turn 90 degree Left */
	Robot_voidSpeed(60);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN1,DIO_u8_HIGH);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN2,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN3,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN4,DIO_u8_HIGH);
	/* value of delay will change by change (voltage and arena) */
    BUZZER_voidBuzzer_Work(BUZZER_ON);
    _delay_ms(200);
    BUZZER_voidBuzzer_Work(BUZZER_OFF);
    _delay_ms(200);
	_delay_ms(100);
	Robot_voidStop();
	Robot_voidSpeed(Robot_u8_INIT_SPEED);
}
void Robot_voidRevers(void)
{
	/* turn 180 degree  */
	Robot_voidSpeed(60);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN1,DIO_u8_HIGH);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN2,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN3,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN4,DIO_u8_HIGH);
	/* value of delay will change by change (voltage and arena) */
    BUZZER_voidBuzzer_Work(BUZZER_ON);
    _delay_ms(200);
    BUZZER_voidBuzzer_Work(BUZZER_OFF);
    _delay_ms(200);
	_delay_ms(300);
	Robot_voidStop();
	Robot_voidSpeed(Robot_u8_INIT_SPEED);
}
/****************************************************************************************************************************************
 *                                                            Robot Modes                                                               *
 ****************************************************************************************************************************************/
/************************************************************ Obstacle Avoiding Mode ******************************************************/
/***************************************************************** Comparison *************************************************************/
void Robot_voidComparisonlogic(u16 Copy_u16LeftObject,u16 Copy_u16RightObject)
{
	/* Comparison between to direction and set Orientation*/
      if(Copy_u16LeftObject>Copy_u16RightObject)
      {
    	    BUZZER_voidBuzzer_Work(BUZZER_ON);
    	    _delay_ms(200);
    	    BUZZER_voidBuzzer_Work(BUZZER_OFF);
    	    _delay_ms(200);

    	  Robot_voidLeft90();

		    BUZZER_voidBuzzer_Work(BUZZER_ON);
		    _delay_ms(200);
		    BUZZER_voidBuzzer_Work(BUZZER_OFF);
		    _delay_ms(200);
      }
      else if (Copy_u16LeftObject<=Copy_u16RightObject)
      {
    	    BUZZER_voidBuzzer_Work(BUZZER_ON);
    	    _delay_ms(200);
    	    BUZZER_voidBuzzer_Work(BUZZER_OFF);
    	    _delay_ms(200);

    	  Robot_voidRight90();

    	    BUZZER_voidBuzzer_Work(BUZZER_ON);
    	    _delay_ms(200);
    	    BUZZER_voidBuzzer_Work(BUZZER_OFF);
    	    _delay_ms(200);
      }
      else if (Copy_u16LeftObject < 10 && Copy_u16RightObject < 10)
      {
    	    BUZZER_voidBuzzer_Work(BUZZER_ON);
    	    _delay_ms(200);
    	    BUZZER_voidBuzzer_Work(BUZZER_OFF);
    	    _delay_ms(200);

    	  Robot_voidRevers();

    	    BUZZER_voidBuzzer_Work(BUZZER_ON);
    	    _delay_ms(200);
    	    BUZZER_voidBuzzer_Work(BUZZER_OFF);
    	    _delay_ms(200);
      }
}
void Robot_voidObstacleAvoidingMode(void)
{
    u16 Local_u16LeftObject=0,Local_u16RightObject=0,Local_u16DistanceObject=0;
	Robot_voidSpeed(Robot_u8_ObstacleAvoidingMode_SPEED);

	while(1)
	{
		/* Read distance -->if no object go forward */
	    Local_u16DistanceObject = ULTRASONIC_u16GetDistance();

	    if (Local_u16DistanceObject==0)
	    {
		    Local_u16DistanceObject=250;
	    }
	    /*********************************************************************************************/
	    /* */
        if(Local_u16DistanceObject<=15)
	    {
        	/* if find object stop
        	 * Read left and right
        	 * and Orientation to open road
        	 *   */
        	BUZZER_voidBuzzer_Work(BUZZER_ON);
        	_delay_ms(200);
        	BUZZER_voidBuzzer_Work(BUZZER_OFF);
	        Robot_voidBackward();
	        BUZZER_voidBuzzer_Work(BUZZER_ON);
	        _delay_ms(200);
	        BUZZER_voidBuzzer_Work(BUZZER_OFF);
		    _delay_ms(300);
		    /* Stop motors*/
			Robot_voidStop();
			BUZZER_voidBuzzer_Work(BUZZER_ON);
			_delay_ms(200);
			BUZZER_voidBuzzer_Work(BUZZER_OFF);
			_delay_ms(300);
			/* Servo turn to Left (180) then read distance*/
			BUZZER_voidBuzzer_Work(BUZZER_ON);
			_delay_ms(200);
			BUZZER_voidBuzzer_Work(BUZZER_OFF);
			SERVO_voidTimer1ServoSetAngleOCR1B(180);
			_delay_ms(300);
			BUZZER_voidBuzzer_Work(BUZZER_ON);
			_delay_ms(200);
			BUZZER_voidBuzzer_Work(BUZZER_OFF);
			Local_u16LeftObject = ULTRASONIC_u16GetDistance();
			_delay_ms(300);
			/* Servo turn to Right (0) then read distance*/
			BUZZER_voidBuzzer_Work(BUZZER_ON);
			_delay_ms(200);
			BUZZER_voidBuzzer_Work(BUZZER_OFF);
			SERVO_voidTimer1ServoSetAngleOCR1B(0);
			_delay_ms(300);
			Local_u16RightObject = ULTRASONIC_u16GetDistance();
			BUZZER_voidBuzzer_Work(BUZZER_ON);
			_delay_ms(200);
			BUZZER_voidBuzzer_Work(BUZZER_OFF);
			_delay_ms(300);
			/* Set Servo direction */
			BUZZER_voidBuzzer_Work(BUZZER_ON);
			_delay_ms(200);
			BUZZER_voidBuzzer_Work(BUZZER_OFF);
			SERVO_voidTimer1ServoSetAngleOCR1B(90);
			_delay_ms(300);
			/*Alarm on */
		    BUZZER_voidBuzzer_Work(BUZZER_ON);
		    _delay_ms(200);
		    BUZZER_voidBuzzer_Work(BUZZER_OFF);
		    _delay_ms(200);
			/* Comparison between to direction and set Orientation*/
			Robot_voidComparisonlogic(Local_u16LeftObject,Local_u16RightObject);
	    }
	    else
	    {
	    	/* if no object go forward */
		    Robot_voidForward();
		    BUZZER_voidBuzzer_Work(BUZZER_ON);
		    _delay_ms(1000);
		    BUZZER_voidBuzzer_Work(BUZZER_OFF);
		    _delay_ms(1000);
	    }
	}
}
/*********************************************************** Initialization ****************************************************************/
void Robot_voidInit(void)
{
	/************************** Init UART *************************************/
	UART_voidInit();
	DIO_voidSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_PIN_INPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_PIN_OUTPUT);
	/************************** Init Timer ************************************/
	TIMER_voidTimer0Init();
	DIO_voidSetPinDirection(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_PIN_OUTPUT);
	TIMER_voidTimer2Init();
	DIO_voidSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN7,DIO_u8_PIN_OUTPUT);
	/**************************** Init Servo **********************************/
	SERVO_voidTimer1InitOCR1B();
	SERVO_voidTimer1ServoSetAngleOCR1B(90);
	/**************************** Init ULTRASONIC *****************************/
	ULTRASONIC_voidInit();
	/***************************** INIT SPEAD ****************************/
	Robot_voidSpeed(Robot_u8_INIT_SPEED);
	/************************************** MOTOR DRIVER L298******************************************************/
	DIO_voidSetPinDirection(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN1,DIO_u8_PIN_OUTPUT);
	DIO_voidSetPinDirection(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN2,DIO_u8_PIN_OUTPUT);
	DIO_voidSetPinDirection(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN3,DIO_u8_PIN_OUTPUT);
	DIO_voidSetPinDirection(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN4,DIO_u8_PIN_OUTPUT);
	/***************************** INIT BUZZER ****************************/
	DIO_voidSetPinDirection(DIO_u8_PORTA , DIO_u8_PIN5 , DIO_u8_PIN_OUTPUT);
}
int main(void)
{
	/* Initialization Robot */
	Robot_voidInit();
    while(1)
    {
    	Robot_voidObstacleAvoidingMode();
    }

return 0;
}

