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
    This is the main.c file
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
/* Rodrigo		                    | 		1        |   1.-Added GPIO_init library */
/*									|				 |   2.-Added  for ports, disable */
/*									|			   	 |   and for enabling the timer functions*/
/*-----------------------------------------------------------------------------*/
/*Rodrigo                           |       2        |  Update Naming Conventions*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "APP/Up_Down.h"
/* Constants and types  */
/*============================================================================*/
/* Variables */
extern T_S32 s32_switch_flag;
extern T_U32 u32_lpit0_ch0_flag_counter;
extern T_U32 u32_lpit0_ch1_flag_counter;
T_U32 u32_flag = 0;
T_S32 s32_temp = 0;
/*============================================================================*/
/* Private functions prototypes */
void main_void_oneTouchUp();
void main_void_oneTouchDown();
void main_void_behaviorUp();
void main_void_behaviorDown();
void main_void_antiPinch();
void main_void_idleState();
/*============================================================================*/

/* Inline functions */
int main(void) {
	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
  	PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
	/*** End of Processor Expert internal initialization.                    ***/
  	malGPIO_init_void_WDOG_disable();
  	malGPIO_init_void_PORT_init(); /* Configure ports */
	SOSC_init_8MHz(); /* Initialize system oscillator for 8 MHz xtal */
	SPLL_init_160MHz(); /* Initialize sysclk to 160 MHz with 8 MHz SOSC */
	NormalRUNmode_80MHz(); /* Init clocks: 80 MHz sysclk & core, 40 MHz bus, 20 MHz flash */
	malGPIO_init_void_LPIT0_init(); /* Initialize PIT0 for 1 second timeout */
	u32_lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
	appUpDown_void_clearGPIO(); //clear PORTS

	for (;;) {
		if(appUpDown_u32_PushUpButton() == 1){
			appUpDown_void_timer1();
			if(appUpDown_u32_validation10ms() == 1){
        main_void_behaviorUp();
			}
		}
		if (u32_flag == 1){
      main_void_antiPinch();
		}
		if(appUpDown_u32_PushDownButton() == 1){
			appUpDown_void_timer1();
			if(appUpDown_u32_validation10ms() == 1){
        main_void_behaviorDown();
			}
		}
		if (appUpDown_u32_PushDownButton() == 0 && appUpDown_u32_PushUpButton() == 0) {
			main_void_idleState();
		}
  }
}
/*============================================================================*/
/* Private functions */
void main_void_oneTouchUp(){
  s32_temp = s32_switch_flag;
  while(s32_temp < 9){
	  appUpDown_void_ManualUp();
    if(appUpDown_u32_PushAntipinch() == 1){
    	appUpDown_void_default_Leds(3);
      s32_temp = 9;
      u32_flag = 1;
    }
    else {
      s32_temp = s32_switch_flag;
      u32_flag = 0;
    }
  }
}
void main_void_oneTouchDown(){
  while(s32_switch_flag >=0){
	  appUpDown_void_ManualDown();
  }
}
void main_void_behaviorUp(){
  if( appUpDown_u32_PushUpButton() == 0 ){ //up_off
    if(appUpDown_u32_validation500ms() == 0){
      main_void_oneTouchUp();
    }
   }
  else{
    if(appUpDown_u32_validation500ms() == 1){
    	appUpDown_void_ManualUp();
    }
  }
}
void main_void_behaviorDown(){
  if( appUpDown_u32_PushDownButton() == 0 ){ //up_off
    if(appUpDown_u32_validation500ms() == 0){
      main_void_oneTouchDown();
    }
  }
  else {
    if(appUpDown_u32_validation500ms() == 1){
    	appUpDown_void_ManualDown();
    }
  }
}
void main_void_antiPinch(){
  main_void_oneTouchDown();
  appUpDown_void_default_Leds(0);
  u32_flag = 0;
  u32_lpit0_ch1_flag_counter = 0;
  while (u32_lpit0_ch1_flag_counter <= 5000){
	  appUpDown_void_timer1();
  }
  u32_lpit0_ch1_flag_counter = 0;
}
void main_void_idleState(){
	appUpDown_void_default_Leds(0);
  u32_lpit0_ch1_flag_counter = 0;
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
 /* Notice: the file ends with a blank new line to avoid compiler warnings */
