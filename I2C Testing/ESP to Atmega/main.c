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
			// Read the incoming byte
			char receivedChar = UART1_read();
			
			static int randomNumber = 0;

			// Check if the received character is a digit (part of the random number)
			if (receivedChar >= '0' && receivedChar <= '9') {
				// Convert the character to a digit and accumulate the number
				randomNumber = randomNumber * 10 + (receivedChar - '0');
				} else if (receivedChar == '\n') {
				// End of random number, process the received random number
				// Do something with the received random number, for example, print it
				UART0_putstring("Received random number: ");
				char buffer[10]; // Buffer to hold string representation of the number
				itoa(randomNumber, buffer, 10); // Convert number to string
				UART0_putstring(buffer); // Print the random number
				UART0_putstring("\r\n"); // New line

				// Reset the randomNumber variable for the next random number
				randomNumber = 0;
			}
			

			UART0_putstring(UART1_available());
			
		}
		
		
	}

	return 0;
}

