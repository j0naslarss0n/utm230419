#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "UART.h"
#include "stm32f4xx.h"                  // Device header

#define	LED_PORT 		GPIOB			// Def/Sätter LED_PORT till GPIOB

#define	LED_PORT_CLOCK  (1U<<1)			// Def/Sätter LED_PORT_CLOCK flyttar en bit till vänster, 0000 blir 0001 / 1U Unsigned integer
//Definerar LED-pins genom att flytta bit vänster resp. steg. (s 163)
#define LED_RED_PIN			(1U<<14)	// MODER7 [0:1]
#define LED_GREEN_PIN		(1U<<12)	// MODER6 [0:1]
#define	LED_BLUE_PIN		(1U<<15)	// MODER7 [1:0]
#define LED_YELLOW_PIN	 	(1U<<13)	// MODER6 [1:0]
// Definerar tillstånd genom att flytta vänster bit resp. steg.
#define LED_RED_MODE_BIT  (1U<<28)		// MODER14 [0:1]
#define LED_GREEN_MODE_BIT (1U<<24)		// MODER12 [0:1]
#define LED_YELLOW_MODE_BIT (1U<<26)	// MODER13 [0:1]
#define LED_BLUE_MODE_BIT (1U<<30)		// MODER15 [0:1]



typedef  enum {		//Enumerate/Definierar värden för färgerna 0-3
  
	RED		= 0,
	GREEN,
	YELLOW,
	BLUE

}LedColor_Type;


typedef enum{		//Enumerate/Def värden AV 0 och PÅ 1
 OFF =0,
 ON = 1
}LedState_Type;


/*Led's attributes*/

typedef struct{ 	// Struct som get Led_Type ett värde
	
 LedColor_Type color; 
 LedState_Type state;  
	
}Led_Type;


void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state);
void Led_setState(Led_Type * const me,LedState_Type _state);
LedState_Type Led_getState(Led_Type * const me);
#endif
