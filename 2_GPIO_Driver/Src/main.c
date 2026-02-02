#include "stm32f1xx.h"


#define IOPCEN					(1U<<4)
#define PIN13					(1<<13)
#define LED_PIN					PIN13


#define PIN14					(1<<14)
#define BTN_PIN					PIN14

int main(void){
	RCC->APB2ENR |= IOPCEN;

	// Set PC13 as output max speed 10MHz
	GPIOC->CRH |= (1<<20);
	GPIOC->CRH &= ~(1<<21);

	// Set PC13 as output open drain
	GPIOC->CRH |= (1<<22);
	GPIOC->CRH &= ~(1<<23);

	// Set PC14 as input
	GPIOC->CRH &= ~(1<<24);
	GPIOC->CRH &= ~(1<<25);

	// Set PC14 as input with pull-up / pull-down
	GPIOC->CRH &= ~(1<<26);
	GPIOC->CRH |= (1<<27);

	while(1){
		if(GPIOC->IDR & BTN_PIN){
			// Set PC13 High
			GPIOC->BSRR = LED_PIN;
		}
		else{
			// Set PC13 LOW
			GPIOC->BSRR = (1<<29);
		}
	}
}
