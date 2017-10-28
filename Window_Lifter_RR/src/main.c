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
#include "APP/Up_Down.h"
/* Constants and types  */
/*============================================================================*/
/* Variables */
extern int switch_flag;
extern int lpit0_ch0_flag_counter;
extern int lpit0_ch1_flag_counter;

int flag = 0;
int temp = 0;
/*============================================================================*/
/* Private functions prototypes */
void OneTouch_UP();
void OneTouch_Down();
void behavior_UP();
void behavior_Down();
void antiPinch();
void idleState();

/*============================================================================*/
/* Inline functions */
int main(void) {
	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
  	PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
	/*** End of Processor Expert internal initialization.                    ***/


	//init_primary_function();
	WDOG_disable();
	PORT_init(); /* Configure ports */
	SOSC_init_8MHz(); /* Initialize system oscillator for 8 MHz xtal */
	SPLL_init_160MHz(); /* Initialize sysclk to 160 MHz with 8 MHz SOSC */
	NormalRUNmode_80MHz(); /* Init clocks: 80 MHz sysclk & core, 40 MHz bus, 20 MHz flash */
	LPIT0_init(); /* Initialize PIT0 for 1 second timeout */
	lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
	clear_GPIO(); //clear PORTS

	for (;;) {
		if(Push_UpButton() == 1){
			timer();
			if(validation_10ms() == 1){
        behavior_UP();
			}
		}
		if (flag == 1){
      antiPinch();
		}
		if(Push_DownButton() == 1){
		  timer();
			if(validation_10ms() == 1){
        behavior_Down();
			}
		}
		if (Push_DownButton() == 0 && Push_UpButton() == 0) {
			idleState();
		}
  }
}


/*============================================================================*/
/* Private functions */
void OneTouch_UP(){
  temp = switch_flag;
  while(temp < 9){
    Manual_up();
    if(Push_Antipinch() == 1){
      default_Leds(3);
      temp = 9;
      flag = 1;
    }
    else {
      temp = switch_flag;
      flag = 0;
    }
  }
}
void OneTouch_Down(){
  while(switch_flag >=0){
    Manual_down();
  }
}
void behavior_UP(){
  if( Push_UpButton() == 0 ){ //up_off
    if(validation_500ms() == 0){
      OneTouch_UP();
    }
   }
  else{
    if(validation_500ms() == 1){
      Manual_up();
    }
  }
}
void behavior_Down(){
  if( Push_DownButton() == 0 ){ //up_off
    if(validation_500ms() == 0){
      OneTouch_Down();
    }
  }
  else {
    if(validation_500ms() == 1){
        Manual_down();
    }
  }
}
void antiPinch(){
  OneTouch_Down();
  default_Leds(0);
  flag = 0;
  lpit0_ch1_flag_counter = 0;
  while (lpit0_ch1_flag_counter <= 5000){
    timer();
  }
  lpit0_ch1_flag_counter = 0;
}
void idleState(){
  default_Leds(0);
  lpit0_ch1_flag_counter = 0;
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
