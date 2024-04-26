
#include "uart.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include <time.h>

#define F_CPU                16000000UL   // 16MHz clock
#define USART_BAUD_RATE      9600
#define USART_BAUD_PRESCALER (((F_CPU / (USART_BAUD_RATE * 16UL))) - 1)

#define ESP_TX_PIN 17 // ATmega TX pin connected to ESP RX pin
#define ESP_RX_PIN 16 // ATmega RX pin connected to ESP TX pin

void initRandom() {
	// Seed the random number generator with current time
	srand(time(NULL));
}

void initTimer() {
	// Set up Timer1 in CTC mode with prescaler of 1024
	TCCR1B |= (1 << WGM12) | (1 << CS12) | (1 << CS10);
	
	// Set compare value for 3-second period
	OCR1A = 0x3D08; // 15624 for 1Hz at prescaler 1024
	
	// Enable Timer1 output compare A interrupt
	TIMSK1 |= (1 << OCIE1A);
	
	DDRB |= (1<<DDB3);
	DDRB |= (1<<DDB4);
}

ISR(TIMER1_COMPA_vect) {
	// Generate and send a random float number
	float randomNumber = (float)rand() / RAND_MAX; // Generate random float between 0 and 1
	char buffer[20]; // Buffer to hold string representation of the number
	dtostrf(randomNumber, 6, 4, buffer); // Convert float to string with 4 decimal places
	
	UART1_putstring(buffer); // Send string over UART
	UART1_putstring("\r\n"); // New line
	
	// Print the random number to the ATmega's serial monitor
	UART0_putstring("Random number: ");
	UART0_putstring(buffer);
	UART0_putstring("\r\n");
	
	_delay_ms(2000);
}

int main(void) {
	// Set up serial UART printing
	UART0_init(USART_BAUD_PRESCALER);
	UART1_init(USART_BAUD_PRESCALER);


	// Set ESP TX pin (ATmega) as output
	DDRB |= (1 << ESP_TX_PIN);
	// Set ESP RX pin (ATmega) as input
	DDRB &= ~(1 << ESP_RX_PIN);

	initRandom();
	initTimer();

	// Enable global interrupts
	sei();

	while (1) {
		// Main program loop
		
	}

	return 0;
}


//
//
//#include "uart.h"
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util/delay.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define F_CPU                16000000UL   // 16MHz clock
//#define USART_BAUD_RATE      9600
//#define USART_BAUD_PRESCALER (((F_CPU / (USART_BAUD_RATE * 16UL))) - 1)
//
//#define ESP_TX_PIN 17 // ATmega TX pin connected to ESP RX pin
//#define ESP_RX_PIN 16 // ATmega RX pin connected to ESP TX pin
//
//void initRandom() {
    //// Seed the random number generator with current time
    //srand(time(NULL));
//}
//
//void initTimer() {
    //// Set up Timer1 in CTC mode with prescaler of 1024
    //TCCR1B |= (1 << WGM12) | (1 << CS12) | (1 << CS10);
	//
    //// Set compare value for 3-second period
    //OCR1A = 0x3D08; // 15624 for 1Hz at prescaler 1024
	//
    //// Enable Timer1 output compare A interrupt
    //TIMSK1 |= (1 << OCIE1A);
	//
	//DDRB |= (1<<DDB3);
	//DDRB |= (1<<DDB4);
//}
//
//ISR(TIMER1_COMPA_vect) {
    //// Generate and send a random number
    //float randomNumber = rand();
    //char buffer[10]; // Buffer to hold string representation of the number
    //itoa(randomNumber, buffer, 10); // Convert number to string
	//
	//
    //UART1_putstring(buffer); // Send string over UART
    //UART1_putstring("\r\n"); // New line
    //
    //// Print the random number to the ATmega's serial monitor
    //UART0_putstring("Random number: ");
    //UART0_putstring(buffer);
    //UART0_putstring("\r\n");
	//
	//_delay_ms(2000);
//}
//
//int main(void) {
    //// Set up serial UART printing
    //UART0_init(USART_BAUD_PRESCALER);
	//UART1_init(USART_BAUD_PRESCALER);
//
//
    //// Set ESP TX pin (ATmega) as output
    //DDRB |= (1 << ESP_TX_PIN);
    //// Set ESP RX pin (ATmega) as input
    //DDRB &= ~(1 << ESP_RX_PIN);
//
    //initRandom();
    //initTimer();
//
    //// Enable global interrupts
    //sei();
//
    //while (1) {
        //// Main program loop
		//
		    //}
//
    //return 0;
//}




//#include "uart.h"
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util/delay.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define F_CPU                16000000UL   // 16MHz clock
//#define USART_BAUD_RATE      9600
//#define USART_BAUD_PRESCALER (((F_CPU / (USART_BAUD_RATE * 16UL))) - 1)
//
//void initRandom() {
	//// Seed the random number generator with current time
	//srand(time(NULL));
//}
//
//void initTimer() {
	//// Set up Timer1 in CTC mode with prescaler of 1024
	//TCCR1B |= (1 << WGM12) | (1 << CS12) | (1 << CS10);
	//// Set compare value for 3-second period
	//OCR1A = 0x3D08; // 15624 for 1Hz at prescaler 1024
	//// Enable Timer1 output compare A interrupt
	//TIMSK1 |= (1 << OCIE1A);
//}
//
//ISR(TIMER1_COMPA_vect) {
	//// Generate and send a random number
	//int randomNumber = rand();
	//char buffer[10]; // Buffer to hold string representation of the number
	//itoa(randomNumber, buffer, 10); // Convert number to string
	//UART_putstring(buffer); // Send string over UART
	//UART_putstring("\r\n"); // New line
//}
//
//int main(void) {
	//// Set up serial UART printing
	//UART_init(USART_BAUD_PRESCALER);
//
	//initRandom();
	//initTimer();
//
	//// Enable global interrupts
	//sei();
//
	//while (1) {
		//// Main program loop
	//}
//
	//return 0;
//}



//#include "uart.h"
//#include <avr/io.h>
//#include <util/delay.h>
//#include <stdlib.h>
//#include <time.h>
//#include <avr/interrupt.h> 
//
//#define F_CPU                16000000UL   // 16MHz clock
//#define USART_BAUD_RATE      9600
//#define USART_BAUD_PRESCALER (((F_CPU / (USART_BAUD_RATE * 16UL))) - 1)
//
//void initRandom() {
	//// Seed the random number generator with current time
	//srand(time(NULL));
//}
//
//void initTimer() {
	//// Set up Timer1 in CTC mode with prescaler of 1024
	//TCCR1B |= (1 << WGM12) | (1 << CS12) | (1 << CS10);
	//// Set compare value for 3-second period
	//OCR1A = 0x3D08; // 15624 for 1Hz at prescaler 1024
	//// Enable Timer1 output compare A interrupt
	//TIMSK1 |= (1 << OCIE1A);
//}
//
//ISR(TIMER1_COMPA_vect) {
	//// Generate and send a random number
	//int randomNumber = rand();
	//char buffer[10]; // Buffer to hold string representation of the number
	//itoa(randomNumber, buffer, 10); // Convert number to string
	//UART_putstring(buffer); // Send string over UART
	//UART_putstring("\r\n"); // New line
//}
//
//int main(void) {
	//// Set up serial UART printing
	//UART_init(USART_BAUD_PRESCALER);
//
	//initRandom();
	//initTimer();
//
	//// Enable global interrupts
	//sei();
//
	//while (1) {
		//// Main program loop
	//}
//
	//return 0;
//}


