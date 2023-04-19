#include "Led.h"

Led_Type led1;						// Dekl. led1 från struct i  Led.h
Led_Type led2;						// Dekl. led2 från struct i  Led.h

int main(void){

  USART2_Init();					// Initierar start funktionen från UART.c
	Led_ctor(&led1,RED,OFF);		// Kör funk. med pekare led1, Color_Type RED/0 o State_Type OFF/0
	Led_ctor(&led2,BLUE,ON);		// Kör funk. med pekare led2, Color_Type BLUE/3 o State_Type ON/1
	
//	Led_getState(&led1);
//	Led_getState(&led2);
//	
//	Led_setState(&led1,ON);
//	
	
	
	
	while(1){
	
	}
}
