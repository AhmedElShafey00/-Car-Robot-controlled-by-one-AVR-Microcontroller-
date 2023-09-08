/****************************************************************************************************************************/
/***************** Author : IMT team **********************************************************************************/
/***************** File : program of BUZZER ***********************************************************************************/
/***************** Date : 1/5/2023  ***************************************************************************************/
/***************** Version : 1.0  *******************************************************************************************/
/***************** Description : Drive For BUZZER ****************************************************************************/
/****************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "BUZZER_interface.h"
#include "BUZZER_private.h"
#include "BUZZER_config.h"

void BUZZER_voidBuzzer_Work(u8 copy_u8Sound)
{
	switch(copy_u8Sound)
	{
	case BUZZER_ON : 	DIO_voidSetPinValue(BUZZER_PORT , BUZZER_PIN , DIO_u8_HIGH); break ;
	case BUZZER_OFF : 	DIO_voidSetPinValue(BUZZER_PORT , BUZZER_PIN , DIO_u8_LOW); break ;
	}
}

