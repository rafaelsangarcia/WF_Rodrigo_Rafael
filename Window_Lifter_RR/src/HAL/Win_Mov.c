/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: filename.c $
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
#include "S32K144.h"
#include "clocks.h"
#include "HAL/Win_Mov.h"
#include "MAL/GPIO_init.h"

/*============================================================================*/



/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/

/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/

/** Check if action is allowed by overload protection.
 To avoid overheating of the door locking motors and hardware failure
 the software shall limit the number of activations in a short period.
 This function checks if the limitation algorithm allows or not
 a certain activation of the motors.
 \returns TRUE if the activation is allowed, FALSE if not
*/
// uint8 algreqg_olp_CheckOLPAllow(uint8 ReqestedAction_u8,       /**< the requested action to be performed (e.g. unlock) */
//                                 uint16 RequestedComponent_u16  /**< the mask of the doors which motors to be activated (e.g. front doors) */
//                                 )
// {
// 	return 0;
// }


/* Exported functions */
void timer () {
	while (0 == (LPIT0->MSR & LPIT_MSR_TIF1_MASK)) {}
	(lpit0_ch1_flag_counter)++;
	LPIT0->MSR |= LPIT_MSR_TIF1_MASK;
}

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

void Manual_up(void) {
	PTD->PCOR |= 1<< 0;//Blue led on
	PTD->PSOR |= 1<< 16; /* Green Led off */
	if (switch_flag<9) {
		(switch_flag)++;
		}
	switch (switch_flag) {
		case 0:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTC->PSOR |= 1<<7;
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

		case 1:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTB->PSOR |= 1<<17; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

		case 2:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTB->PSOR |= 1<<14; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

		case 3:

			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTB->PSOR |= 1<<15; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

		case 4:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTB->PSOR |= 1<<16; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

		case 5:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTC->PSOR |= 1<<14; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

		case 6:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTC->PSOR |= 1<<3; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

		case 7:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTE->PSOR |= 1<<16; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

		case 8:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTE->PSOR |= 1<<15; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

		case 9:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTD->PSOR |= 1<<0; /* Toggle output on port D0 (blue LED) */
			PTE->PSOR |= 1<<14; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;
		}
}

void Manual_down(void) {
	PTD->PSOR |= 1<<0;//Blue led off
	PTD->PCOR |= 1<<16; /*Green Led On*/
	switch (switch_flag) {
		case 9:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTE->PCOR |= 1<<14; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

		case 8:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTE->PCOR |= 1<<15; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

		case 7:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTE->PCOR |= 1<<16; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

		case 6:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTC->PCOR |= 1<<3; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

		case 5:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTC->PCOR |= 1<<14; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

		case 4:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTB->PCOR |= 1<<16; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

		case 3:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTB->PCOR |= 1<<15; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

		case 2:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTB->PCOR |= 1<<14; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

		case 1:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTB->PCOR |= 1<<17; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

		case 0:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			//PTD->PSOR |= 1<<16; /* Toggle output on port D16 (green LED) */
			PTC->PCOR |= 1<<7; /* Toggle output on port D16 (green LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			switch_flag=-1;
			break;

		default:
			break;
	}
	if (switch_flag>0){
		switch_flag--;
	}
}





/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */
