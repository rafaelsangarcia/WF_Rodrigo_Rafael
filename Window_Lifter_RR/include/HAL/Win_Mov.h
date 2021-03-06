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
/*    Rafael Sanchez   |          1         |  Create the Prototypes functions*/
/*----------------------------------------------------------------------------*/
/* Rodrigo Mortera      |         2         | Update Naming Conventions       */
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
typedef unsigned int T_U32;
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
void halWinMov_void_ToggleBlueLed(T_U32);
void halWinMov_void_ToggleGreenLed(T_U32);
void halWinMov_void_ToggleRedLed(T_U32);
void halWinMov_void_ToggleLedBar1(T_U32);
void halWinMov_void_ToggleLedBar2(T_U32);
void halWinMov_void_ToggleLedBar3(T_U32);
void halWinMov_void_ToggleLedBar4(T_U32);
void halWinMov_void_ToggleLedBar5(T_U32);
void halWinMov_void_ToggleLedBar6(T_U32);
void halWinMov_void_ToggleLedBar7(T_U32);
void halWinMov_void_ToggleLedBar8(T_U32);
void halWinMov_void_ToggleLedBar9(T_U32);
void halWinMov_void_ToggleLedBar10(T_U32);
T_U32 halWinMov_u32_ValidateUpButton();
T_U32 halWinMov_u32_ValidateDownButton();
T_U32 halWinMov_u32_ValidateAntipinch();

/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
