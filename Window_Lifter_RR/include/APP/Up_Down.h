/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: filename.x $
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
 * $Log: filename.h  $

  ============================================================================*/
#ifndef FILENAME_H
#define FILENAME_H

/* Includes */
#include "HAL/Win_Mov.h"
/*============================================================================*/
/*
#define BlueLed 0
#define RedLed 15
#define GreenLed 16
//Push Button Define
#define UpButton 12
#define DownButton 13
//Led Bar Define
#define LedBar_1 7
#define LedBar_2 17
#define LedBar_3 14
#define LedBar_4 15
#define LedBar_5 16
#define LedBar_6 14
#define LedBar_7 3
#define LedBar_8 16
#define LedBar_9 15
#define LedBar_10 14*/

/* Constants and types */
/*============================================================================*/


/* Exported Variables */
/*============================================================================*/
  //int switch_flag;
  //int lpit0_ch0_flag_counter;


/* Exported functions prototypes */
void Manual_up();
void Manual_Down();
int Push_UpButton();
int Push_DownButton();
int Push_Antipinch();
int validation_10ms();
int validation_500ms();
void timer();
void clear_GPIO();
void clear_Leds(int led);

/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
