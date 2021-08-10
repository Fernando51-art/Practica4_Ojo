#ifndef ARDUINO_H_
#define ARDUINO_H_
#include"MKL25Z4.h"
typedef int entero;

#define  TRUE ((entero)1u)
#define  FALSE ((entero)0u)

#define  Output ((entero)1u)
#define  Intput ((entero)0u)
#define  p(x)  GPIOA_BASE +x*0x40
#define  GPIO(x)  ((GPIO_Type *)p(x))

//__________|Puertos|__________//
enum ports{A,B,C,D,E};

extern void Pin_Mode(int portA,int pin,int confi);
extern void puertoA(int pin,int estate);
extern void puertoB(int pin,int estate);
extern void puertoC(int pin,int estate);
extern void puertoD(int pin,int estate);
extern void puertoE(int pin,int estate);
extern void Digital_Write(int portA,int pin,int on);
extern int Read_Input(int port, int pin);
extern void delay(void);
#define COUNT 1000000U//delay


#endif /* ARDUINO_H_ */
