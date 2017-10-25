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
#ifndef FILENAME_H
#define FILENAME_H

/*typedef unsigned int u32_t;//hola=Lpit0_ch1, contador, Lpit0_ch0
typedef int s32_t;//counter*/
/* Includes */
#include "S32K144.h"
#include "clocks.h"
#include "MAL/GPIO_init.h"
/*============================================================================*/
/* Constants and types */
/*============================================================================*/
/* Exported Variables */
/*============================================================================*/
int lpit0_ch0_flag_counter = 0;
int switch_flag = -1;
int lpit0_ch1_flag_counter = 0;
/*============================================================================*/
/* Exported functions prototypes */
/*============================================================================*/
void Manual_up();
void Manual_down();
void timer();
void clear_GPIO();
int validation_10ms();
int validation_500ms();

/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
