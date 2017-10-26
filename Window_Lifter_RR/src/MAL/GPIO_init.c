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
/*  Author                          |       Version     | Description         */
/*----------------------------------------------------------------------------*/
/* Rodrigo		                    | 61f508b        |   1.-Added GPIO_init library */
/*									|				 |   2.-Added  for ports, disable */
/*									|			   	 |   and for enabling the timer functions   */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "MAL/GPIO_init.h"



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
//uint8 algreqg_olp_CheckOLPAllow(uint8 ReqestedAction_u8,       /**< the requested action to be performed (e.g. unlock) */
//                                uint16 RequestedComponent_u16  /**< the mask of the doors which motors to be activated (e.g. front doors) */
//                                )
//{
//	return 0;
//}


/* Exported functions */
/*============================================================================*/
void PORT_init (void) {/*Initializing the PORTS*/
	PCC-> PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
	PCC-> PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
	PCC-> PCCn[PCC_PORTB_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
	PCC-> PCCn[PCC_PORTE_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */

	PTD->PDDR |= 1<<BlueLed; /* Port D0: Data Direction= output */
	PTD->PDDR |= 1<<RedLed; /* Port D15: Data Direction= output */
	PTD->PDDR |= 1<<GreenLed; /* Port D16: Data Direction= output */
	PTC->PDDR |= 1<<LedBar_1;/*Port C7: Data Direction= output*/
	PTB->PDDR |= 1<<LedBar_2;
	PTB->PDDR |= 1<<LedBar_3;
	PTB->PDDR |= 1<<LedBar_4;
	PTB->PDDR |= 1<<LedBar_5;
	PTC->PDDR |= 1<<LedBar_6;
	PTC->PDDR |= 1<<LedBar_7;
	PTE->PDDR |= 1<<LedBar_8;
	PTE->PDDR |= 1<<LedBar_9;
	PTE->PDDR |= 1<<LedBar_10;
	PTC->PDDR &= ~(1<<UpButton);/*PORT C12: Data Direction= input*/
	PTC->PDDR &= ~(1<<DownButton);/*PORT C13: Data Direction= input*/
	PTE->PDDR &= ~(1<<Antipinch);

	PORTD->PCR[BlueLed]  = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to blue LED on EVB) */
	PORTD->PCR[RedLed] = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to red LED on EVB) */
	PORTD->PCR[GreenLed] = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to green LED on EVB) */
	PORTC->PCR[LedBar_1] = 0x00000100;
	PORTB->PCR[LedBar_2] = 0x00000100;
	PORTB->PCR[LedBar_3] = 0x00000100;
	PORTB->PCR[LedBar_4] = 0x00000100;
	PORTB->PCR[LedBar_5] = 0x00000100;
	PORTC->PCR[LedBar_6] = 0x00000100;
	PORTC->PCR[LedBar_7] = 0x00000100;
	PORTE->PCR[LedBar_8] = 0x00000100;
	PORTE->PCR[LedBar_9] = 0x00000100;
	PORTE->PCR[LedBar_10] = 0x00000100;
	PORTC->PCR[UpButton] = 0x00000110;
	PORTC->PCR[DownButton] = 0x00000110;
	PORTE->PCR[Antipinch] = 0x00000110;
}

void LPIT0_init (void) {
	PCC->PCCn[PCC_LPIT_INDEX] = PCC_PCCn_PCS(6); /* Clock Src = 6 (SPLL2_DIV2_CLK)*/
	PCC->PCCn[PCC_LPIT_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clk to LPIT0 regs */
	LPIT0->MCR = 0x00000001; /* M_CEN=1: enable module clk (allows writing other LPIT0 regs)*/
	LPIT0->TMR[0].TVAL = 16000000; /*16000000=400 ms*/
	LPIT0->TMR[1].TVAL = 40000;//40000= 1 ms
	LPIT0->TMR[0].TCTRL = 0x00000001; // Timer 0 is enabled
	LPIT0->TMR[1].TCTRL = 0x00000101;//Timer 1 is enabled

}

void WDOG_disable (void) {
	WDOG->CNT=0xD928C520; /*Unlock watchdog*/
	WDOG->TOVAL=0x0000FFFF; /*Maximum timeout value*/
	WDOG->CS = 0x00002100; /*Disable watchdog*/
}
 /* Notice: the file ends with a blank new line to avoid compiler warnings */
