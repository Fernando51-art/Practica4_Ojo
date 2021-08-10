
#include <stdio.h>
#include "Arduino.h"
#include "MKL25Z4.h"




void Pin_Mode(int port,int pin,int estate)
{
    void (*p[])(int,int)={puertoA,puertoB,puertoC,puertoD,puertoE};
    (*p[port])(pin,estate);
  
}

void puertoA(int pin,int estate)
{
    SIM->SCGC5 |=SIM_SCGC5_PORTA_MASK;
    PORTA->PCR[pin] =0x100;
    if(estate==1){GPIOA->PDDR|=0x01<<pin;}
    else {GPIOA->PDDR &= ~(1<<pin);}

}

void puertoB(int pin,int estate)
{
    SIM->SCGC5 |=SIM_SCGC5_PORTB_MASK;
    PORTB->PCR[pin] =0x100;
    if(estate==1){GPIOB->PDDR|=0x01<<pin;}
    else {GPIOB->PDDR &= ~(1<<pin);}

}

void puertoC(int pin,int estate)
{
    SIM->SCGC5 |=SIM_SCGC5_PORTC_MASK;
    PORTC->PCR[pin] =0x100;
    if(estate==1){GPIOC->PDDR|=0x01<<pin;}
    else {GPIOC->PDDR &= ~(1<<pin);}

}

void puertoD(int pin,int estate)
{
    SIM->SCGC5 |=SIM_SCGC5_PORTD_MASK;
    PORTD->PCR[pin] =0x100;
    if(estate==1){GPIOD->PDDR|=0x01<<pin;}
    else {GPIOD->PDDR &= ~(1<<pin);}

}

void puertoE(int pin,int estate)
{
    SIM->SCGC5 |=SIM_SCGC5_PORTE_MASK;
    PORTE->PCR[pin] =0x100;
    if(estate==1){GPIOE->PDDR|=0x01<<pin;}
    else {GPIOE->PDDR &= ~(1<<pin);}

}


void Digital_Write(int port,int pin,int on)
{
    if(on==1){GPIO(port)->PDOR|=0x01<<pin;}
    else{GPIO(port)->PCOR|=0x01<<pin;}
}



int Read_Input(int port, int pin)
{
    int reg;
   return reg=GPIO(port)->PDIR& (1<<pin);
}




void delay(void) {
    entero i = 0;
    for (i = 0; i < COUNT; i++)
    {
        __NOP();

    }
}

