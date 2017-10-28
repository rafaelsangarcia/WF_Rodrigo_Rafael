/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Up_Down.c $
 * $Revision: version $
 * $Author: author $
 * $Date: date $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    short description in one sentence end with dot.
    detailed
    multiline
    description of the file
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*  DATABASE           |        PROJECT     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/*                     |                    |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $

  ============================================================================*/
/* Includes */
#include "APP/Up_Down.h"
/*============================================================================*/
/* Constants and types  */
/*============================================================================*/
/* Variables */
int switch_flag = -1;
int lpit0_ch0_flag_counter = 0;
int lpit0_ch1_flag_counter = 0;
/*============================================================================*/
/* Private functions prototypes */
void timer_0();
/*============================================================================*/
/* Inline functions */
/*============================================================================*/
/* Private functions */
void timer_0(){
	while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {}
	(lpit0_ch0_flag_counter)++;
	LPIT0->MSR |= LPIT_MSR_TIF0_MASK;
}
/*============================================================================*/
/** Check if action is allowed by overload protection.
 To avoid overheating of the door locking motors and hardware failure
 the software shall limit the number of activations in a short period.
 This function checks if the limitation algorithm allows or not
 a certain activation of the motors.
 \returns TRUE if the activation is allowed, FALSE if not
*/
/* Exported functions */
/*============================================================================*/
int validation_10ms() {
	if (lpit0_ch1_flag_counter >= 10) {
		return 1;
	}
	else {
		return 0;
	}
}
int validation_500ms() {
	if (lpit0_ch1_flag_counter >= 500) {
		return 1;
	}
	else {
		return 0;
	}
}
void timer_1() {
	while (0 == (LPIT0->MSR & LPIT_MSR_TIF1_MASK)) {}
	(lpit0_ch1_flag_counter)++;
	LPIT0->MSR |= LPIT_MSR_TIF1_MASK;
}
void clear_GPIO() {
	Toggle_BlueLed(0); /*  turning off BLUE LED */
	Toggle_RedLed(0);
	Toggle_GreenLed(0);
	Toggle_LedBar_1(0);
	Toggle_LedBar_2(0);
	Toggle_LedBar_3(0);
	Toggle_LedBar_4(0);
	Toggle_LedBar_5(0);
	Toggle_LedBar_6(0);
	Toggle_LedBar_7(0);
	Toggle_LedBar_8(0);
	Toggle_LedBar_9(0);
	Toggle_LedBar_10(0);
}
void Manual_up() {
	Toggle_BlueLed(1);
	Toggle_GreenLed(0);
	if (switch_flag<9) {
		switch_flag++;
		}
	timer_0();
	switch (switch_flag) {
				case 0:
					Toggle_LedBar_1(1);
					break;

				case 1:
					Toggle_LedBar_2(1); /* Toggle output on port D0 (blue LED) */
					break;

				case 2:
					Toggle_LedBar_3(1); /* Toggle output on port D0 (blue LED) */
					break;

				case 3:
					Toggle_LedBar_4(1); /* Toggle output on port D0 (blue LED) */
					break;

				case 4:
					Toggle_LedBar_5(1); /* Toggle output on port D0 (blue LED) */
					break;

				case 5:
					Toggle_LedBar_6(1); /* Toggle output on port D0 (blue LED) */
					break;

				case 6:
					Toggle_LedBar_7(1); /* Toggle output on port D0 (blue LED) */
					break;

				case 7:
					Toggle_LedBar_8(1); /* Toggle output on port D0 (blue LED) */
					break;

				case 8:
					Toggle_LedBar_9(1); /* Toggle output on port D0 (blue LED) */
					break;

				case 9:
				Toggle_BlueLed(0); /* Toggle output on port D0 (blue LED) */
				Toggle_LedBar_10(1); /* Toggle output on port D0 (blue LED) */
				break;
			}
}
void Manual_down() {
	Toggle_BlueLed(0);//Blue led off
	Toggle_GreenLed(1); /*Green Led On*/
	timer_0();
	switch (switch_flag) {
		case 9:
			Toggle_LedBar_10(0); /* Toggle output on port D0 (blue LED) */
			break;

		case 8:
			Toggle_LedBar_9(0);/* Toggle output on port D0 (blue LED) */
			break;

		case 7:
			Toggle_LedBar_8(0); /* Toggle output on port D0 (blue LED) */
			break;

		case 6:
			Toggle_LedBar_7(0); /* Toggle output on port D0 (blue LED) */
			break;

		case 5:
			Toggle_LedBar_6(0); /* Toggle output on port D0 (blue LED) */
			break;

		case 4:
			Toggle_LedBar_5(0); /* Toggle output on port D0 (blue LED) */
			break;

		case 3:
			Toggle_LedBar_4(0); /* Toggle output on port D0 (blue LED) */
			break;

		case 2:
			Toggle_LedBar_3(0); /* Toggle output on port D0 (blue LED) */
			break;

		case 1:
			Toggle_LedBar_2(0); /* Toggle output on port D0 (blue LED) */
			break;

		case 0:
			Toggle_LedBar_1(0); /* Toggle output on port D16 (green LED) */
			switch_flag=-1;
			break;

		default:
			break;
	}
	if (switch_flag>0){
		switch_flag--;
	}
}
int Push_UpButton(){
	if(Validate_UpButton()){
		return 1;
	}
	else{
		return 0;
	}
}
int Push_DownButton(){
	if(Validate_DownButton()){
		return 1;
	}
	else{
		return 0;
	}
}
int Push_Antipinch(){
	if(Validate_Antipinch()){
			return 1;
		}
		else{
			return 0;
		}
}
void default_Leds(int led) {
	switch(led){
		case 0:
			Toggle_BlueLed(0);
			Toggle_GreenLed(0);
			Toggle_RedLed(0);
			break;

		case 1:
			Toggle_BlueLed(0);
			break;

		case 2:
			Toggle_GreenLed(0);
			break;

		case 3:
			Toggle_RedLed(1);
			break;

		default:
			Toggle_BlueLed(1);
			Toggle_GreenLed(1);
			Toggle_RedLed(1	);
			break;

	}

}
 /* Notice: the file ends with a blank new line to avoid compiler warnings */
