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
/* Rafael Sanchez       |         1         | Prototype creations to up & down the window*/
/*----------------------------------------------------------------------------*/
/* Rodrigo Mortera      |         2         | Update Naming Conventions       */
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
/* Constants and types */
/*============================================================================*/
typedef unsigned int T_U32;
typedef signed int T_S32;
/* Exported Variables */
/*============================================================================*/
/* Exported functions prototypes */
void appUpDown_void_ManualUp();
void appUpDown_void_ManualDown();
T_U32 appUpDown_u32_PushUpButton();
T_U32 appUpDown_u32_PushDownButton();
T_U32 appUpDown_u32_PushAntipinch();
T_U32 appUpDown_u32_validation10ms();
T_U32 appUpDown_u32_validation500ms();
void appUpDown_void_timer1();
void appUpDown_void_clearGPIO();
void appUpDown_void_default_Leds(T_U32 led);

/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
