#include <HardwareSerial.h>

void setup() {
    Serial.begin(9600);
    Serial2.begin(9600);
}

void loop() {
    // Generate a random number
    int randomNumber = random(0, 100); // Generate a random number between 0 and 99
    
    // Send the random number over UART to the ATmega
    Serial2.print(randomNumber);
    Serial2.print('\n'); // Terminate with newline character
    
    delay(3000); // Wait for 3 seconds before generating the next random number
}

