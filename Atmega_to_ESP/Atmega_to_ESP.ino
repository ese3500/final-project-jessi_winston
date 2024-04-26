
#include <WiFi.h>
#include <HardwareSerial.h>

const char* ssid = "Ninja Turtle";
const char* password = "applepie";
const char* serverIP = "192.168.252.51";
const int serverPort = 80;

WiFiClient client;

void setup() {
    Serial.begin(9600); // Initialize serial monitor
    Serial2.begin(9600); // Initialize serial communication with ATmega
  
    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi..");
    }
    Serial.println("Connected to WiFi");
}

void loop() {
    // Check if random number is available from ATmega
    if (Serial2.available()) {
        // Read the incoming random number from ATmega
        int randomNumber = Serial2.parseInt();
        Serial.print("Received random number from ATmega: ");
        Serial.println(randomNumber);

        // Connect to server
        if (!client.connected()) {
            Serial.println("Connecting to server..");
            if (client.connect(serverIP, serverPort)) {
                Serial.println("Connected to server");
                
                // Send the random number to the server
                client.println(randomNumber);
                Serial.print("Sent random number to server: ");
                Serial.println(randomNumber);
            } else {
                Serial.println("Connection failed");
            }
        }
    }

    // Delay before next iteration
    delay(2000); // Adjust delay as needed
}


// #include <HardwareSerial.h>

// void setup() {
//     Serial.begin(9600);
//     Serial2.begin(9600);
// }

// void loop() {

//     if (Serial2.available()) {
//         int randomNumber = Serial2.parseInt(); // Read the incoming random number
//         Serial.print("Received random number: ");
//         Serial.println(randomNumber);
//         // Add your code to send the random number over WiFi to another ESP32
//     }


//     Serial.println(Serial2.available());

// }


