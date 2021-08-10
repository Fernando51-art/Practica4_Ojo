/*
 * PWM.h
 *
 *  Created on: 9 jul. 2021
 *      Author: josel
 */

#ifndef PWM_H_
#define PWM_H_

#include<stdio.h>
#include"MKL25Z4.h"
//enum ports{A,B,C,D,E};
enum mux{analog,Alternative1,Alternative2,Alternative3,Alternative4,Alternative5,Alternative6,Alternative7};
enum clks{disable,MCGFLLCLK,OSCERCLK,MCGIRCLK};
enum clk_div{Divide1,Divide2,Divide4,Divide8,Divide16,Divide32,Divide64,Divide128};
typedef unsigned char uint_8;
typedef unsigned int u_int;
#define grados_180(x) x-1091
#define grados_90(x)   x-2596
#define SCGC6_TPM(x)  (u_int)(0x1<<(24+x))
#define SCGC5_PORT(x) (u_int)(0x1<<(9+x))
#define MUX_ALT(x)    (u_int)(x<<8)
#define SOPT2_TPMSRC(x) (u_int)(1<<(24+x))
#define up_down      (u_int)(1<<5)
#define up           (u_int)(0<<5)
#define Center_aligned   0x28
#define clock            48000000
#define clock_div(x)     clock/(1<<(x&0x7))
#define pwm(x,y)       clock_div(y)/(2*x)
extern void PWM_vfnDriverInit (void);
extern uint_8 DPY_bInitialPosition (void);
extern uint_8 PWM_bfnAngleAdjustment (uint_8 bNewAngle);
extern void delayMs(int n);





#endif /* PWM_H_ */
