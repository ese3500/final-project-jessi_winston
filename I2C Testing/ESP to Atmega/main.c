#include "uart.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
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
	
	float gyro_x = 0;
	float gyro_y = 0;
	float gyro_z = 0;
	int flex = 0;
	int count = 0;
	
	static char buffer[20]; // Buffer to hold incoming characters
	static char float_buffer[20];
	static uint8_t bufferIndex = 0;

	// Set ESP RX pin (ATmega) as input
	DDRB &= ~(1 << ESP_RX_PIN);

	// Enable global interrupts
	sei();

	while (1) {
				
		// Check if data is available to read from ESP
		if (UART1_available()) {
			
			// Read the incoming byte
			char receivedChar = UART1_read();
			
			// Check if the received character is a digit, a period (for decimal point), or a newline
			if ((receivedChar >= '0' && receivedChar <= '9') || receivedChar == '.' || receivedChar == '-') {
				// Add the character to the buffer
				float_buffer[bufferIndex] = receivedChar;
				buffer[bufferIndex] = receivedChar;
				//bufferIndex+=1; 
				
			} else if (receivedChar == 'X') {
				// Print the string (float number) using UART
				UART0_putstring("Gyro X: ");
				// Print the string (float number) using UART
				UART0_putstring(float_buffer);
				UART0_putstring(" ");
				//bufferIndex+=1; 

				gyro_x = atof(float_buffer);
				
			} else if (receivedChar == 'Y') {
				// Print the string (float number) using UART
				UART0_putstring("Gyro Y: ");
				// Print the string (float number) using UART
				UART0_putstring(float_buffer);
				UART0_putstring(" ");
				//bufferIndex+=1; 
				
				gyro_y = atof(float_buffer);
			
			} else if (receivedChar == 'Z') {
				// Print the string (float number) using UART
				UART0_putstring("Gyro Z: ");
				// Print the string (float number) using UART
				UART0_putstring(float_buffer);
				UART0_putstring("/n");
				//bufferIndex+=1; 

				gyro_z = atof(float_buffer);
				
			} else if (receivedChar == 'F') {
				// Print the string (float number) using UART
				UART0_putstring("Flex: ");
				// Print the string (float number) using UART
				UART0_putstring(float_buffer);
				UART0_putstring(" ");
				
				flex = atoi(float_buffer);
			}
			
			else if (receivedChar == ',') {
				float_buffer[bufferIndex] = '\0';
				buffer[bufferIndex] = receivedChar;
				buffer[bufferIndex+1] = '\0';
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
//#include <string.h> // Include string.h for string manipulation functions
//
//#define F_CPU                16000000UL   // 16MHz clock
//#define USART_BAUD_RATE      9600
//#define USART_BAUD_PRESCALER (((F_CPU / (USART_BAUD_RATE * 16UL))) - 1)
//
//#define ESP_TX_PIN 17 // ATmega TX pin connected to ESP RX pin
//#define ESP_RX_PIN 16 // ATmega RX pin connected to ESP TX pin
//
//
//#include "uart.h"
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util/delay.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h> // Include string.h for string manipulation functions
//
//#define F_CPU                16000000UL   // 16MHz clock
//#define USART_BAUD_RATE      9600
//#define USART_BAUD_PRESCALER (((F_CPU / (USART_BAUD_RATE * 16UL))) - 1)
//
//#define ESP_TX_PIN 17 // ATmega TX pin connected to ESP RX pin
//#define ESP_RX_PIN 16 // ATmega RX pin connected to ESP TX pin
//#define BUFFER_SIZE 20
//
//char buffer[BUFFER_SIZE];
//uint8_t bufferindex = 0;
//char receivedChar;
//float gyro_x = 0;
//float gyro_y = 0;
//float gyro_z = 0;
//int flex = 0;
////
//void process_data(const char* data, char type);
//int main(void) {
	//UART1_init(USART_BAUD_PRESCALER);  // Initialize UART with baud rate of 9600
	//UART0_init(USART_BAUD_PRESCALER);
	//
	//DDRB |= (1 << DDB3);
	//DDRB &= ~(1 << DDB4);
	//
	//
	//memset(buffer, 0, BUFFER_SIZE);  // Clear the buffer
//
	//while (1) {
		////UART0_putstring("start");
		//if (UART1_available()) {
			//receivedChar = UART1_read();
			//UART0_putstring(receivedChar);
			//_delay_ms(100);
			//
			//int bufferIndex = 0;
			//
			//if (receivedChar == ',' || receivedChar == '\n') {
				 ////Process the buffer if a comma or newline is received
				//buffer[bufferIndex] = '\0';  // Null-terminate the string
				//if (bufferIndex > 0) {
					//char type = buffer[bufferIndex - 1];  // Last character is the type
					//buffer[bufferIndex - 1] = '\0';  // Remove the type from the buffer
					//process_data(buffer, type);
					//memset(buffer, 0, BUFFER_SIZE);  // Reset the buffer
					//bufferIndex = 0;  // Reset the index
				//}
				//} else {
				 ////Add the character to the buffer if it's not a delimiter
				//if (bufferIndex < BUFFER_SIZE - 1) {
					//buffer[bufferIndex++] = receivedChar;
				//}
			//}
		//}
		//
	//}
//
	//return 0;
//}
//void process_data(const char* data, char type) {
//switch (type) {
//case 'X':
//gyro_x = atof(data);
//// Implement UART printing or other handling
//UART0_putstring("Gyro X: ");
//UART0_putstring(data);
//UART0_putstring("\n");
//break;
//case 'Y':
//gyro_y = atof(data);
//UART0_putstring("Gyro Y: ");
//UART0_putstring(data);
//UART0_putstring("\n");
//break;
//case 'Z':
//gyro_z = atof(data);
//UART0_putstring("Gyro Z: ");
//UART0_putstring(data);
//UART0_putstring("\n");
//break;
//case 'F':
//flex = atoi(data);
//UART0_putstring("Flex: ");
//UART0_putstring(data);
//UART0_putstring("\n");
//break;
//default:
//// Handle unexpected type
//UART0_putstring("Error: Unknown data type\n");
//break;
//}
//}
//}

//#include "uart.h"
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util/delay.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h> // Include string.h for string manipulation functions
//
//#define F_CPU                16000000UL   // 16MHz clock
//#define USART_BAUD_RATE      9600
//#define USART_BAUD_PRESCALER (((F_CPU / (USART_BAUD_RATE * 16UL))) - 1)
//
//#define ESP_TX_PIN 17 // ATmega TX pin connected to ESP RX pin
//#define ESP_RX_PIN 16 // ATmega RX pin connected to ESP TX pin
//#define BUFFER_SIZE 20
//
//void process_data(const char* data, char type);
	//char buffer[BUFFER_SIZE];
	//uint8_t bufferIndex = 0;
	//char receivedChar;
	//float gyro_x = 0;
	//float gyro_y = 0;
	//float gyro_z = 0;
	//int flex = 0;
	//
	//
//int main(void) {
	//UART1_init(9600);  // Initialize UART with baud rate of 9600
	//UART0_init(9600);
	//
	//DDRB |= (1 << DDB3);
	//DDRB &= ~(1 << DDB4);
	//
	//
	//memset(buffer, 0, BUFFER_SIZE);  // Clear the buffer
//
	//while (1) {
		//UART0_putstring("start");
		//while (UART1_available()) {
			//receivedChar = UART1_read();
			//UART0_putstring(receivedChar);
			///*
			//if (receivedChar == ',' || receivedChar == '\n') {
				//// Process the buffer if a comma or newline is received
				//buffer[bufferIndex] = '\0';  // Null-terminate the string
				//if (bufferIndex > 0) {
					//char type = buffer[bufferIndex - 1];  // Last character is the type
					//buffer[bufferIndex - 1] = '\0';  // Remove the type from the buffer
					//process_data(buffer, type);
					//memset(buffer, 0, BUFFER_SIZE);  // Reset the buffer
					//bufferIndex = 0;  // Reset the index
				//}
				//} else {
				//// Add the character to the buffer if it's not a delimiter
				//if (bufferIndex < BUFFER_SIZE - 1) {
					//buffer[bufferIndex++] = receivedChar;
				//}
			//}*/
		//}
	//}
//
	//return 0;
//}
//
//void process_data(const char* data, char type) {
	//switch (type) {
		//case 'X':
			//gyro_x = atof(data);
			//// Implement UART printing or other handling
			//UART0_putstring("Gyro X: ");
			//UART0_putstring(data);
			//UART0_putstring("\n");
		//break;
		//case 'Y':
		//gyro_y = atof(data);
		//UART0_putstring("Gyro Y: ");
		//UART0_putstring(data);
		//UART0_putstring("\n");
		//break;
		//case 'Z':
		//gyro_z = atof(data);
		//UART0_putstring("Gyro Z: ");
		//UART0_putstring(data);
		//UART0_putstring("\n");
		//break;
		//case 'F':
		//flex = atoi(data);
		//UART0_putstring("Flex: ");
		//UART0_putstring(data);
		//UART0_putstring("\n");
		//break;
		//default:
		//// Handle unexpected type
		//UART0_putstring("Error: Unknown data type\n");
		//break;
	//}
//}

//int main(void) {
    //UART0_init(USART_BAUD_PRESCALER);
    //UART1_init(USART_BAUD_PRESCALER);
    //
    //float gyro_x = 0, gyro_y = 0, gyro_z = 0;
    //int flex = 0;
    //char buffer[20] = {0};
    //uint8_t bufferIndex = 0;
//
    //// Set ESP RX pin (ATmega) as input
    //DDRB &= ~(1 << ESP_RX_PIN);
    //// Enable global interrupts
    //sei();
//
    //while (1) {
        //if (UART1_available()) {
            //char receivedChar = UART1_read();
//
            //if ((receivedChar >= '0' && receivedChar <= '9') || receivedChar == '.' || receivedChar == '-') {
                //if (bufferIndex < sizeof(buffer) - 1) {
                    //buffer[bufferIndex++] = receivedChar;
                    //buffer[bufferIndex] = '\0'; // Ensure null-termination
                //}
            //} else if (receivedChar == ',' || receivedChar == 'X' || receivedChar == 'Y' || receivedChar == 'Z' || receivedChar == 'F') {
                //if (receivedChar != ',') {
                    //switch (receivedChar) {
                        //case 'X':
							////buffer[bufferIndex] = '\0'; // Ensure null-termination
                            //UART0_putstring("Gyro X: ");
                            //gyro_x = atof(buffer);
                            //break;
                        //case 'Y':
							////buffer[bufferIndex] = '\0'; // Ensure null-termination
                            //UART0_putstring("Gyro Y: ");
                            //gyro_y = atof(buffer);
                            //break;
                        //case 'Z':
							////buffer[bufferIndex] = '\0'; // Ensure null-termination
                            //UART0_putstring("Gyro Z: ");
                            //gyro_z = atof(buffer);
                            //break;
                        //case 'F':
							////buffer[bufferIndex] = '\0'; // Ensure null-termination
                            //UART0_putstring("Flex: ");
                            //flex = atoi(buffer);
                            //break;
                    //}
                    //UART0_putstring(buffer);
                    //UART0_putstring("\n");
                //}
                //memset(buffer, 0, sizeof(buffer)); // Clear buffer
                //bufferIndex = 0; // Reset index
            //}
        //}
        //_delay_ms(200);
    //}
    //return 0;
//}

//#include "uart.h"
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util/delay.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h> // Include string.h for string manipulation functions
//
//#define F_CPU                16000000UL   // 16MHz clock
//#define USART_BAUD_RATE      9600
//#define USART_BAUD_PRESCALER (((F_CPU / (USART_BAUD_RATE * 16UL))) - 1)
//
//#define ESP_TX_PIN 17 // ATmega TX pin connected to ESP RX pin
//#define ESP_RX_PIN 16 // ATmega RX pin connected to ESP TX pin
///*
//int main(void) {
	//// Initialize UART for communication
	//UART0_init(USART_BAUD_PRESCALER);
	//UART1_init(USART_BAUD_PRESCALER);
	//
	//float gyro_x = 0;
	//float gyro_y = 0;
	//float gyro_z = 0;
	//int flex = 0;
	//int count = 0;
	//
	//static char buffer[20]; // Buffer to hold incoming characters
	//static char float_buffer[20];
	//static uint8_t bufferIndex = 0;
//
	//// Set ESP RX pin (ATmega) as input
	//DDRB &= ~(1 << ESP_RX_PIN);
//
	//// Enable global interrupts
	//sei();
//
	//while (1) {
				//
		//// Check if data is available to read from ESP
		//if (UART1_available()) {
			//
			//// Read the incoming byte
			//char receivedChar = UART1_read();
			//
			//// Check if the received character is a digit, a period (for decimal point), or a newline
			//if ((receivedChar >= '0' && receivedChar <= '9') || receivedChar == '.' || receivedChar == '-') {
				//// Add the character to the buffer
				//float_buffer[bufferIndex] = receivedChar;
				//buffer[bufferIndex] = receivedChar;
				//bufferIndex+=1; 
				//
			//} else if (receivedChar == 'X') {
				//// Print the string (float number) using UART
				//UART0_putstring("Gyro Y: ");
				//// Print the string (float number) using UART
				//UART0_putstring(float_buffer);
				//UART0_putstring(" ");
				//bufferIndex+=1; 
//
				//gyro_x = atof(float_buffer);
				//
			//} else if (receivedChar == 'Y') {
				//// Print the string (float number) using UART
				//UART0_putstring("Gyro Y: ");
				//// Print the string (float number) using UART
				//UART0_putstring(float_buffer);
				//UART0_putstring(" ");
				//bufferIndex+=1; 
				//
				//gyro_y = atof(float_buffer);
			//
			//} else if (receivedChar == 'Z') {
				//// Print the string (float number) using UART
				//UART0_putstring("Gyro Z: ");
				//// Print the string (float number) using UART
				//UART0_putstring(float_buffer);
				//UART0_putstring(" ");
				//bufferIndex+=1; 
//
				//gyro_z = atof(float_buffer);
				//
			//} else if (receivedChar == 'F') {
				//// Print the string (float number) using UART
				//UART0_putstring("Flex: ");
				//// Print the string (float number) using UART
				//UART0_putstring(float_buffer);
				//UART0_putstring(" ");
				//
				//flex = atoi(float_buffer);
			//}
			//
			//else if (receivedChar == ',') {
				//float_buffer[bufferIndex] = '\0';
				//buffer[bufferIndex] = receivedChar;
				//buffer[bufferIndex+1] = '\0';
				//bufferIndex = 0;
						//
			//}
		//}
	//}
	//_delay_ms(200);
	//return 0;
//}*/
//
//int main(void) {
	//UART0_init(USART_BAUD_PRESCALER);
	//UART1_init(USART_BAUD_PRESCALER);
	//
	//float gyro_x = 0, gyro_y = 0, gyro_z = 0;
	//int flex = 0;
	//char buffer[20] = {0};
	//uint8_t bufferIndex = 0;
//
	//DDRB &= ~(1 << ESP_RX_PIN);
	//sei();
//
	//while (1) {
		//if (UART1_available()) {
			//char receivedChar = UART1_read();
//
			//if ((receivedChar >= '0' && receivedChar <= '9') || receivedChar == '.' || receivedChar == '-') {
				//if (bufferIndex < sizeof(buffer) - 1) {
					//buffer[bufferIndex++] = receivedChar;
					//
				//}
			//} else if (receivedChar == ',' || receivedChar == 'X' || receivedChar == 'Y' || receivedChar == 'Z' || receivedChar == 'F') {
				//if (receivedChar != ',') {
					//// Log the type of data received
					////buffer[bufferIndex+1] = '\0'; // Ensure null-termination
					//UART0_putstring(buffer);
					//UART0_putstring(" / ");
//
					//// Process the data
					//switch (receivedChar) {
						//case 'X': gyro_x = atof(buffer); break;
						//case 'Y': gyro_y = atof(buffer); break;
						//case 'Z': gyro_z = atof(buffer); break;
						//case 'F': flex = atoi(buffer); break;
					//}
				//}
				//memset(buffer, 0, sizeof(buffer)); // Clear buffer
				//bufferIndex = 0; // Reset index
			//}
		//}
		//_delay_ms(200);
	//}
	//return 0;
//}


