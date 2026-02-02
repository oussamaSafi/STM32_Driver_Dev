#include "stm32f1xx.h"


#define IOPCEN					(1U<<4)
#define PIN13					(1<<13)
#define LED_PIN					PIN13

int main(void){
	RCC->APB2ENR |= IOPCEN;

	// Set PC13 as output max speed 10MHz
	GPIOC->CRH |= (1<<20);
	GPIOC->CRH &= ~(1<<21);

	// Set PC13 as output open drain
	GPIOC->CRH |= (1<<22);
	GPIOC->CRH &= ~(1<<23);

	while(1){
		// Set PC13 High
		GPIOC->BSRR |= LED_PIN;
		for (volatile int i = 0; i < 500000; i++) {

		}
		GPIOC->BSRR |= (1<<29);
		for (volatile int i = 0; i < 500000; i++) {

		}
	}
}
