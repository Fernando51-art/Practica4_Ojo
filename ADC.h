/*
 * adc.h
 *
 *  Created on: 24 jun. 2021
 *      Author: Personal
 */

#ifndef ADC_H_
#define ADC_H_
enum adiv{divide_ratio1,divide_ratio2,divide_ratio4,divide_ratio8};
enum ADLSMP{Short_sample,Long_sample};
enum ADLPC{Normal_power,Low_power};
//enum Modo{ocho_b,doce_b,diez_b,Dieciséis_b};
#define CFG1_MODE(x) (x<<2)
#define CFG1_ADIV(x) (x<<5)
#define CFG1_ADLSMP(x) (x<<4)
#define CFG1_ADLPC(x)  (x<<7)
typedef unsigned char uint_8;
extern  void ADC_vfnDriverInit (void); 
extern uint_8 ADC_bfnReadADC(uint_8 bChannel, uint_8 *bpADCValue);
#endif /* ADC_H_ */
