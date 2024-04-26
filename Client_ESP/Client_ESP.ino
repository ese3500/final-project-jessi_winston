
#include <WiFi.h>
#include <stdlib.h> // Include the library for random number generation

const char* ssid = "Ninja Turtle";
const char* password = "applepie";
const char* serverIP = "192.168.252.51";
const int serverPort = 80;

WiFiClient client;

void setup() {
  Serial.begin(115200);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Connect to server
  if (!client.connected()) {
    Serial.println("Connecting to server..");
    if (client.connect(serverIP, serverPort)) {
      Serial.println("Connected to server");
    } else {
      Serial.println("Connection failed");
      return;
    }
  }

  // Generate a random number between 0 and 999 (adjust range as needed)
  int randomNumber = random(1000);

  // Send the random number to the server
  client.println(randomNumber);
  Serial.print("Sent random number to server: ");
  Serial.println(randomNumber);


    Serial.print("wtf");


  delay(2000); // Adjust delay as needed
}


// #include <WiFi.h>

// const char* ssid = "Ninja Turtle";
// const char* password = "applepie";
// const char* serverIP = "192.168.252.179";
// const int serverPort = 80;
// const int buttonPin = 21; // Example pin for button


// WiFiClient client;

// void setup() {
//   pinMode(buttonPin, INPUT);


//   Serial.begin(115200);
//   // Connect to Wi-Fi
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.println("Connecting to WiFi..");
//   }
//   Serial.println("Connected to WiFi");
  
// }

// void loop() {
//   // Connect to server
//   if (!client.connected()) {
//     Serial.println("Connecting to server..");
//     if (client.connect(serverIP, serverPort)) {
//       Serial.println("Connected to server");
//     } else {
//       Serial.println("Connection failed");
//       return;
//     }
//   }

//   // Example: if a button is pressed, send a message to turn on the LED on the server
//   if (digitalRead(buttonPin) == HIGH) {
//     client.println("ON");
//     Serial.println("Sent ON signal to server");
//   } else {
//     client.println("OFF");
//     Serial.println("Sent OFF signal to server");
//   }

//   delay(1000); // Adjust delay as needed
// }