/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: GPIO_init.h $
 * $Revision:  61f508b $
 * $Author: Rodrigo Mortera $
 * $Author: Rafael Sanchez $

 * $Date: Oct/10/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    This file is to init the GPIO ports, watchdog, and timers
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
/*  Author             |        Version     | Descritpion                     */
/*----------------------------------------------------------------------------*/
/*  Rodrigo Mortera     |         61f508b   | 1.-15 Port definitions (Output Leds,and input ports of push button) */
/*						|				    | 2.-Prototype funtions for ports, disable and for enable the timers.   */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/



/* Includes */
#include "S32K144.h"
#include "clocks.h"

#ifndef FILENAME_H
#define FILENAME_H
//Port Led Define
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
#define LedBar_10 14
/*============================================================================*/
/* Constants and types */
/*typedef unsigned int u32_t;//hola=Lpit0_ch1, contador, Lpit0_ch0
typedef signed int 32_t;//counter*/
/*============================================================================*/
/* Exported Variables */
/*============================================================================*/
/* Exported functions prototypes */
void PORT_init (void);
void WDOG_disable (void);
void LPIT0_init (void);
/*============================================================================*/
#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
