#include "uart.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h> // Include string.h for string manipulation functions

#define F_CPU                16000000UL   // 16MHz clock
#define USART_BAUD_RATE      9600
#define USART_BAUD_PRESCALER (((F_CPU / (USART_BAUD_RATE * 16UL))) - 1)

#define ESP_TX_PIN 17 // ATmega TX pin connected to ESP RX pin
#define ESP_RX_PIN 16 // ATmega RX pin connected to ESP TX pin

int main(void) {
	// Initialize UART for communication
	UART0_init(USART_BAUD_PRESCALER);
	UART1_init(USART_BAUD_PRESCALER);

	// Set ESP RX pin (ATmega) as input
	DDRB &= ~(1 << ESP_RX_PIN);

	// Enable global interrupts
	sei();

	while (1) {
		// Check if data is available to read from ESP
		if (UART1_available()) {
			UART0_putstring("testtt");
			
			// Read the incoming byte
			char receivedChar = UART1_read();

			static char buffer[20]; // Buffer to hold incoming characters
			static uint8_t bufferIndex = 0;

			// Check if the received character is a digit, a period (for decimal point), or a newline
			if ((receivedChar >= '0' && receivedChar <= '9') || receivedChar == '.') {
				// Add the character to the buffer
				buffer[bufferIndex++] = receivedChar;
				} else if (receivedChar == '\n') {
				// End of float number, process the received float number
				// Null-terminate the buffer to make it a valid string
				buffer[bufferIndex] = '\0';
				// Convert the buffer to a float
				float receivedFloat = atof(buffer);
				// Print the received float number
				UART0_putstring("Received float number: ");
				char floatStr[20]; // Buffer to hold string representation of the float number
				dtostrf(receivedFloat, 7, 4, floatStr); // Convert float to string with 7 digits, 4 decimal places
				UART0_putstring(floatStr); // Print the float number
				UART0_putstring("\r\n"); // New line

				// Reset the buffer index for the next float number
				bufferIndex = 0;
			}
		}
	}

	return 0;
}



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
//int main(void) {
	//// Initialize UART for communication
	//UART0_init(USART_BAUD_PRESCALER);
	//UART1_init(USART_BAUD_PRESCALER);
//
	//// Set ESP RX pin (ATmega) as input
	//DDRB &= ~(1 << ESP_RX_PIN);
//
	//// Enable global interrupts
	//sei();
//
	//while (1) {
		//// Check if data is available to read from ESP
		//if (UART1_available()) {
			//// Read the incoming byte
			//char receivedChar = UART1_read();
			//
			//static int randomNumber = 0;
//
			//// Check if the received character is a digit (part of the random number)
			//if (receivedChar >= '0' && receivedChar <= '9') {
				//// Convert the character to a digit and accumulate the number
				//randomNumber = randomNumber * 10 + (receivedChar - '0');
				//} else if (receivedChar == '\n') {
				//// End of random number, process the received random number
				//// Do something with the received random number, for example, print it
				//UART0_putstring("Received random number: ");
				//char buffer[10]; // Buffer to hold string representation of the number
				//itoa(randomNumber, buffer, 10); // Convert number to string
				//UART0_putstring(buffer); // Print the random number
				//UART0_putstring("\r\n"); // New line
//
				//// Reset the randomNumber variable for the next random number
				//randomNumber = 0;
			//}
			//
//
			//UART0_putstring(UART1_available());
			//
		//}
		//
		//
	//}
//
	//return 0;
//}

