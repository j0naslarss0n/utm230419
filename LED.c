#include "Led.h"


void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state){
  
	me->color  = _color;			// Definerar färg från struct LedColor_Type
	me->state  = _state; 			// Def tillstånd från scruct LedState_Type

	 	
	 /*Hardware Init*/
	RCC->AHB1ENR |= LED_PORT_CLOCK;  // Clock Control Enable def (1U<<1) från Led.h
	
	switch(_color){					// Switch för olika utfall färg och AV/PÅ
		 
		case RED:						
			LED_PORT->MODER |=LED_RED_MODE_BIT;	// GPIOB -> MODER14[0:1]
		  if(me->state  == ON){					// Om PÅ/1
			   LED_PORT->ODR |= LED_RED_PIN;	// GPIOB -> MODER7[0:1]
				printf("The RED Led is set ON \n\r"); // Printa detta
			}
			else{
			  LED_PORT->ODR &= ~LED_RED_PIN; 	// Annars INTE MODER[0:1] eller är det MODER[0:0]?
        printf("The RED Led is set OFF \n\r"); 	// Print detta

			}
		break;									// Gå ur

		case YELLOW:							// Samma som ovan fast andra MODERx [X:X]
			LED_PORT->MODER |=LED_YELLOW_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_YELLOW_PIN;
				printf("The YELLOW Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_YELLOW_PIN;
        printf("The YELLOW Led is set OFF \n\r");

			}
		break;
		
		case BLUE:
			LED_PORT->MODER |=LED_BLUE_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_BLUE_PIN;
				printf("The BLUE Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_BLUE_PIN;
        printf("The BLUE Led is set OFF \n\r");

			}
		break;
		
		case GREEN:
			LED_PORT->MODER |=LED_GREEN_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_GREEN_PIN;
				printf("The GREEN Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_GREEN_PIN;
        printf("The GREEN Led is set OFF \n\r");

			}
		break;
	
	}
}

// Osäker på vad denna gör? Trodde först som Led_cstor fast utan färg-structen?...
// ... Men det känns som kaka på kaka, varför?
void Led_setState(Led_Type * const me,LedState_Type _state){

	 me->state =  _state;

	 
	
	switch(me->color){
		 
		case RED:
			LED_PORT->MODER |=LED_RED_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_RED_PIN;
				printf("The RED Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_RED_PIN;
        printf("The RED Led is set OFF \n\r");

			}
		break;
		
		case YELLOW:
			LED_PORT->MODER |=LED_YELLOW_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_YELLOW_PIN;
				printf("The YELLOW Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_YELLOW_PIN;
        printf("The YELLOW Led is set OFF \n\r");

			}
		break;
		
		case BLUE:
			LED_PORT->MODER |=LED_BLUE_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_BLUE_PIN;
				printf("The BLUE Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_BLUE_PIN;
        printf("The BLUE Led is set OFF \n\r");

			}
		break;
		
		case GREEN:
			LED_PORT->MODER |=LED_GREEN_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_GREEN_PIN;
				printf("The GREEN Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_GREEN_PIN;
        printf("The GREEN Led is set OFF \n\r");

			}
		break;
	
	}
}

// Funktion som kolla om LED är på eller av. 
LedState_Type Led_getState(Led_Type * const me){

	switch(me->color){
		
		case RED:
			   printf("The RED Led is cureently %d \n\r",me->state);
				 break;
		
	  case GREEN:
			   printf("The GREEN Led is cureently %d \n\r",me->state);
				 break;
		case BLUE:
			   printf("The BLUE Led is cureently %d\n\r",me->state);
				 break;
		case YELLOW:
			   printf("The YELLOW Led is cureently  %d \n\r",me->state);
				 break;
		
		
	 }
  
	return me->state;
}
