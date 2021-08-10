/*
 * ADC.c
 *
 *  Created on: 24 jun. 2021
 *      Author: Personal
 */

#include "MKL25Z4.h"
#include <stdio.h>
#include "adc.h"
#include "Arduino.h"
#include "PWM.h"
//**************************************************
//				ADC DRIVERS
//**************************************************

void ADC_vfnDriverInit ( void )
{
	SIM->SCGC6 |=SIM_SCGC6_ADC0_MASK; //0x8000000; //Activar reloj del ADC
	SIM->SCGC5 |=SCGC5_PORT(E); //0x3E00;	//Inicializar reloj del puerto B
	PORTB->PCR[20] |= MUX_ALT(analog) ; // Entrada analogica B0 //Select alternate function as ADC-CH8
	/*8 bit conversion, Prescalar of 8, long sample time*/
	ADC0->CFG1 =(CFG1_MODE(1) | CFG1_ADIV(divide_ratio4)|CFG1_ADLSMP(Long_sample)); //0x70; //1111000      0x70 = 8bits
	ADC0->CFG1 |= (CFG1_ADLPC(Low_power)); //Modo de baja potencia
	//ADC0_CFG2 |= ADC_CFG1_ADLSTS(0X0);
	ADC0->SC1[0] = ADC_SC1_ADCH(31); //Desactivar todos los canales //Disable the module
}


void ADC_vfnDriverInit2 ( void )
{
	SIM->SCGC6 |=SIM_SCGC6_ADC0_MASK; //0x8000000; //Activar reloj del ADC
	SIM->SCGC5 |=SCGC5_PORT(E); //0x3E00;	//Inicializar reloj del puerto B
	PORTB->PCR[22] |= MUX_ALT(analog) ; // Entrada analogica B0 //Select alternate function as ADC-CH8
	/*8 bit conversion, Prescalar of 8, long sample time*/
	ADC0->CFG1 =(CFG1_MODE(1) | CFG1_ADIV(divide_ratio4)|CFG1_ADLSMP(Long_sample)); //0x70; //1111000      0x70 = 8bits
	ADC0->CFG1 |= (CFG1_ADLPC(Low_power)); //Modo de baja potencia
	//ADC0_CFG2 |= ADC_CFG1_ADLSTS(0X0);
	ADC0->SC1[0] = ADC_SC1_ADCH(31); //Desactivar todos los canales //Disable the module
}








uint_8 ADC_bfnReadADC (uint_8 bChannel, uint_8 *bpADCValue)
{
	ADC0->SC1[0] = bChannel & ADC_SC1_ADCH_MASK;//Write to SC1A to start conversion
	while(ADC0->SC2 & ADC_SC2_ADACT_MASK);//Conversion in progress
	while(!(ADC0->SC1[0] & ADC_SC1_COCO_MASK));//wait till conversion is complete
    if(ADC0->SC1[0] & ADC_SC1_COCO_MASK)
	{ *bpADCValue=ADC0->R[0]; 
	   return 1;
	}
	else{return 0;}
}
