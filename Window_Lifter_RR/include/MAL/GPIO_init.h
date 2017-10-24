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
//Port Led Define
#define PTD0 0
#define PDT15 15
#define PDT16 16
//Push Button Define
#define PTDC12 12
#define PTDC13 13
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

/* Includes */
#include "S32K144.h"
#include "clocks.h"


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
