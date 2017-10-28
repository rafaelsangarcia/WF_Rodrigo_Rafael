/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
* $Source: filename.c $
* $Revision: version $
* $Author: Rafael Sanchez $
* $Author: Rodrigo Mortera $
* $Date: 24/10/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    In this Win_Mov.h file, there are the prototypes function Timer, validation_10ms,
    validation_500ms, Manual_up and Manual_down.
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
/*  Author         	   |        Version     | Descritpion											*/
/*----------------------------------------------------------------------------*/
/*    Rafael Sanchez   |     e22ee1c (v2)   |  Create the Prototypes functions*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/

/*typedef unsigned int u32_t;//hola=Lpit0_ch1, contador, Lpit0_ch0
typedef int s32_t;//counter*/
/* Includes */

#include "MAL/GPIO_init.h"

#ifndef FILENAME_H
#define FILENAME_H
/*#define BlueLed 0
#define RedLed 15
#define GreenLed 16
//Push Button Define
#define UpButton 12
#define DownButton 13
#define Antipinch 13
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
/*============================================================================*/
/* Constants and types */
/*============================================================================*/
/* Exported Variables */
/*============================================================================*/
//int lpit0_ch0_flag_counter;
//int switch_flag;
//int lpit0_ch1_flag_counter;
/*============================================================================*/
/* Exported functions prototypes */
/*============================================================================*/
//void Manual_up();
//void Manual_down();

//void timer();
//void clear_GPIO();
//int validation_10ms();
//int validation_500ms();
void init_primary_function();
void Toggle_BlueLed(int);
void Toggle_GreenLed(int);
void Toggle_LedBar_1(int);
void Toggle_LedBar_2(int);
void Toggle_LedBar_3(int);
void Toggle_LedBar_4(int);
void Toggle_LedBar_5(int);
void Toggle_LedBar_6(int);
void Toggle_LedBar_7(int);
void Toggle_LedBar_8(int);
void Toggle_LedBar_9(int);
void Toggle_LedBar_10(int);
int Validate_UpButton();
int Validate_DownButton();
int Validate_Antipinch();

/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
