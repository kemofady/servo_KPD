/*
 * main.c
 *
 *  Created on: Sep 16, 2023
 *      Author: Ali Othman
 */

/*****************************************************/
/* 1 - include libraries */
#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "avr/delay.h"

/* 2 - include MCAL */
#include "DIO_driver/Dio_Interface.h"
#include "TIMER_driver/timer_interface.h"
#include "GIE_driver/Gie_interface.h"
#include "LCD_driver/LCD_interface.h"

#include"servo.h"
void main()
{
	KPD_voidInit();
	PWM_voidinit1();
	LCD_voidinit();

	u8 local_u8key=0xff;

	Dio_voidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);

	while(1)
	{
		LCD_voidsendstring("SERVO DIRECTION:");
		do{
			local_u8key = KPD_u8GETPressedKey();

			}while(local_u8key == 0xff);

			if(local_u8key =='8')
			{
				pwm_voidsetdutycycleA(1500);
				LCD_gotoxy(1, 3);
				LCD_voidsendstring(" 90 deg");
			}
			if(local_u8key =='6')
			{
				pwm_voidsetdutycycleA(500);
				LCD_gotoxy(1, 3);
				LCD_voidsendstring(" 0 deg");
			}
			if(local_u8key =='4')
			{
				pwm_voidsetdutycycleA(2500);
				LCD_gotoxy(1, 3);
				LCD_voidsendstring(" 180 deg");
			}
			_delay_ms(500);
			LCD_voidclearscrean();
	}
}
