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
/*  DATABASE           |        VERSION      | DESCRIPTION                    */
/*----------------------------------------------------------------------------*/
/*   Rodrigo Mortera   |         1             |    Creation of led sequence to up & down the window*/
/*----------------------------------------------------------------------------*/
/*   Rafael Sanchez    |         2            |   Modification to manual up & down function and added of validation functions*/
/*----------------------------------------------------------------------------*/
/* Rodrigo Mortera      |         3         | Update Naming Conventions       */
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
T_S32 s32_switch_flag = -1;
T_U32 u32_lpit0_ch0_flag_counter = 0;
T_U32 u32_lpit0_ch1_flag_counter = 0;
/*============================================================================*/
/* Private functions prototypes */
void appUpDown_void_timer0();
/*============================================================================*/
/* Inline functions */
/*============================================================================*/
/* Private functions */
void appUpDown_void_timer0(){
	while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {}
	(u32_lpit0_ch0_flag_counter)++;
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
T_U32 appUpDown_u32_validation10ms() {
	if (u32_lpit0_ch1_flag_counter >= 10) {
		return 1;
	}
	else {
		return 0;
	}
}

T_U32 appUpDown_u32_validation500ms() {
	if (u32_lpit0_ch1_flag_counter >= 500) {
		return 1;
	}
	else {
		return 0;
	}
}

void appUpDown_void_timer1() {
	while (0 == (LPIT0->MSR & LPIT_MSR_TIF1_MASK)) {}
	(u32_lpit0_ch1_flag_counter)++;
	LPIT0->MSR |= LPIT_MSR_TIF1_MASK;
}

void appUpDown_void_clearGPIO() {
	halWinMov_void_ToggleBlueLed(0); /*  turning off BLUE LED */
	halWinMov_void_ToggleRedLed(0);
	halWinMov_void_ToggleGreenLed(0);
	halWinMov_void_ToggleLedBar1(0);
	halWinMov_void_ToggleLedBar2(0);
	halWinMov_void_ToggleLedBar3(0);
	halWinMov_void_ToggleLedBar4(0);
	halWinMov_void_ToggleLedBar5(0);
	halWinMov_void_ToggleLedBar6(0);
	halWinMov_void_ToggleLedBar7(0);
	halWinMov_void_ToggleLedBar8(0);
	halWinMov_void_ToggleLedBar9(0);
	halWinMov_void_ToggleLedBar10(0);
}

void appUpDown_void_ManualUp() {
	halWinMov_void_ToggleBlueLed(1);
	halWinMov_void_ToggleGreenLed(0);
	if (s32_switch_flag<9) {
		s32_switch_flag++;
		}
	else{

	}
	appUpDown_void_timer0();
	switch (s32_switch_flag) {
				case 0:
					halWinMov_void_ToggleLedBar1(1);
					break;

				case 1:
					halWinMov_void_ToggleLedBar2(1); /* Toggle output on port D0 (blue LED) */
					break;

				case 2:
					halWinMov_void_ToggleLedBar3(1); /* Toggle output on port D0 (blue LED) */
					break;

				case 3:
					halWinMov_void_ToggleLedBar4(1); /* Toggle output on port D0 (blue LED) */
					break;

				case 4:
					halWinMov_void_ToggleLedBar5(1); /* Toggle output on port D0 (blue LED) */
					break;

				case 5:
					halWinMov_void_ToggleLedBar6(1); /* Toggle output on port D0 (blue LED) */
					break;

				case 6:
					halWinMov_void_ToggleLedBar7(1); /* Toggle output on port D0 (blue LED) */
					break;

				case 7:
					halWinMov_void_ToggleLedBar8(1); /* Toggle output on port D0 (blue LED) */
					break;

				case 8:
					halWinMov_void_ToggleLedBar9(1); /* Toggle output on port D0 (blue LED) */
					break;

				case 9:
					halWinMov_void_ToggleBlueLed(0); /* Toggle output on port D0 (blue LED) */
					halWinMov_void_ToggleLedBar10(1); /* Toggle output on port D0 (blue LED) */
				break;
			}
}

void appUpDown_void_ManualDown() {
	halWinMov_void_ToggleBlueLed(0);//Blue led off
	halWinMov_void_ToggleGreenLed(1); /*Green Led On*/
	appUpDown_void_timer0();
	switch (s32_switch_flag) {
		case 9:
			halWinMov_void_ToggleLedBar10(0); /* Toggle output on port D0 (blue LED) */
			break;

		case 8:
			halWinMov_void_ToggleLedBar9(0);/* Toggle output on port D0 (blue LED) */
			break;

		case 7:
			halWinMov_void_ToggleLedBar8(0); /* Toggle output on port D0 (blue LED) */
			break;

		case 6:
			halWinMov_void_ToggleLedBar7(0); /* Toggle output on port D0 (blue LED) */
			break;

		case 5:
			halWinMov_void_ToggleLedBar6(0); /* Toggle output on port D0 (blue LED) */
			break;

		case 4:
			halWinMov_void_ToggleLedBar5(0); /* Toggle output on port D0 (blue LED) */
			break;

		case 3:
			halWinMov_void_ToggleLedBar4(0); /* Toggle output on port D0 (blue LED) */
			break;

		case 2:
			halWinMov_void_ToggleLedBar3(0); /* Toggle output on port D0 (blue LED) */
			break;

		case 1:
			halWinMov_void_ToggleLedBar2(0); /* Toggle output on port D0 (blue LED) */
			break;

		case 0:
			halWinMov_void_ToggleLedBar1(0); /* Toggle output on port D16 (green LED) */
			s32_switch_flag=-1;
			break;

		default:
			break;
	}
	if (s32_switch_flag>0){
		s32_switch_flag--;
	}
}

T_U32 appUpDown_u32_PushUpButton(){
	if(halWinMov_u32_ValidateUpButton()){
		return 1;
	}
	else{
		return 0;
	}
}

T_U32 appUpDown_u32_PushDownButton(){
	if(halWinMov_u32_ValidateDownButton()){
		return 1;
	}
	else{
		return 0;
	}
}

T_U32 appUpDown_u32_PushAntipinch(){
	if(halWinMov_u32_ValidateAntipinch()){
			return 1;
		}
		else{
			return 0;
		}
}

void appUpDown_void_default_Leds(T_U32 u32_led) {
	switch(u32_led){
		case 0:
			halWinMov_void_ToggleBlueLed(0);
			halWinMov_void_ToggleGreenLed(0);
			halWinMov_void_ToggleRedLed(0);
			break;

		case 1:
			halWinMov_void_ToggleBlueLed(0);
			break;

		case 2:
			halWinMov_void_ToggleGreenLed(0);
			break;

		case 3:
			halWinMov_void_ToggleRedLed(1);
			break;

		default:
			halWinMov_void_ToggleBlueLed(1);
			halWinMov_void_ToggleGreenLed(1);
			halWinMov_void_ToggleRedLed(1);
			break;
	}
}
 /* Notice: the file ends with a blank new line to avoid compiler warnings */
