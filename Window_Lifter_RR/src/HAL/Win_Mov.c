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
    In this Win_Mov.c file, there are the function Timer, validation_10ms,
		validation_500ms, Manual_up and Manual_down.
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, T_U32erior Division, Body and Security                     */
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
/*  Author         	   |        Version     | Descritpion					  */
/*----------------------------------------------------------------------------*/
/*    Rafael Sanchez   |         1          |   Create the functions          */
/*----------------------------------------------------------------------------*/
/*    Rodrigo Mortera  |         2          |   Update naming conventions      */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
 *
  ============================================================================*/

/* Includes */

#include "HAL/Win_Mov.h"
/*============================================================================*/
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
/* Exported functions */
void halWinMov_void_ToggleBlueLed(T_U32 u32_status){
	if (u32_status == 1) {
		PTD->PCOR |= 1<< BlueLed;
	}
	else {
		PTD->PSOR |= 1<< BlueLed;
	}
}
void halWinMov_void_ToggleGreenLed(T_U32 u32_status){
	if (u32_status == 1) {
		PTD->PCOR |= 1<< GreenLed;
	}
	else {
		PTD->PSOR |= 1<< GreenLed;
	}
}
void halWinMov_void_ToggleRedLed(T_U32 u32_status){
	if (u32_status == 1) {
		PTD->PCOR |= 1<< RedLed;
	}
	else {
		PTD->PSOR |= 1<< RedLed;
	}
}
void halWinMov_void_ToggleLedBar1(T_U32 u32_status){
	if (u32_status == 1){
		PTC->PSOR |= 1<<LedBar_1;
	}
	else {
		PTC->PCOR |= 1<<LedBar_1;
	}
}
void halWinMov_void_ToggleLedBar2(T_U32 u32_status){
	if (u32_status == 1){
		PTB->PSOR |= 1<<LedBar_2;
	}
	else {
		PTB->PCOR |= 1<<LedBar_2;
	}
}
void halWinMov_void_ToggleLedBar3(T_U32 u32_status){
	if (u32_status == 1){
		PTB->PSOR |= 1<<LedBar_3;
	}
	else {
		PTB->PCOR |= 1<<LedBar_3;
	}
}
void halWinMov_void_ToggleLedBar4(T_U32 u32_status){
	if (u32_status == 1){
		PTB->PSOR |= 1<<LedBar_4;
	}
	else {
		PTB->PCOR |= 1<<LedBar_4;
	}
}
void halWinMov_void_ToggleLedBar5(T_U32 u32_status){
	if (u32_status == 1){
		PTB->PSOR |= 1<<LedBar_5;
	}
	else {
		PTB->PCOR |= 1<<LedBar_5;
	}
}
void halWinMov_void_ToggleLedBar6(T_U32 u32_status){
	if (u32_status == 1){
		PTC->PSOR |= 1<<LedBar_6;
	}
	else {
		PTC->PCOR |= 1<<LedBar_6;
	}
}
void halWinMov_void_ToggleLedBar7(T_U32 u32_status){
	if (u32_status == 1){
		PTC->PSOR |= 1<<LedBar_7;
	}
	else {
		PTC->PCOR |= 1<<LedBar_7;
	}
}
void halWinMov_void_ToggleLedBar8(T_U32 u32_status){
	if (u32_status == 1){
		PTE->PSOR |= 1<<LedBar_8;
	}
	else {
		PTE->PCOR |= 1<<LedBar_8;
	}
}
void halWinMov_void_ToggleLedBar9(T_U32 u32_status){
	if (u32_status == 1){
		PTE->PSOR |= 1<<LedBar_9;
	}
	else {
		PTE->PCOR |= 1<<LedBar_9;
	}
}
void halWinMov_void_ToggleLedBar10(T_U32 u32_status){
	if (u32_status == 1){
		PTE->PSOR |= 1<<LedBar_10;
	}
	else {
		PTE->PCOR |= 1<<LedBar_10;
	}
}
T_U32 halWinMov_u32_ValidateUpButton(){
	if(PTC->PDIR & (1<<UpButton)){
			return 1;
		}
		else{
			return 0;
		}
}
T_U32 halWinMov_u32_ValidateDownButton(){
	if(PTC->PDIR & (1<<DownButton)){
			return 1;
		}
		else{
			return 0;
		}
}
T_U32 halWinMov_u32_ValidateAntipinch(){
	if(PTE->PDIR & (1<<Antipinch)){
				return 1;
			}
			else{
				return 0;
			}
}
/*============================================================================*/
 /* Notice: the file ends with a blank new line to avoid compiler warnings */
