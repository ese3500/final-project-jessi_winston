#include <WiFi.h>
#include <HardwareSerial.h>

const char* ssid = "Ninja Turtle";
const char* password = "applepie";

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600); // Initialize Serial2 for communication with ATmega
  
  delay(10);

  // Connect to Wi-Fi
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(2000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New client connected");
    while (client.connected()) {
      delay(2000);
      if (client.available()) {
        // Read the incoming data
        String data = client.readStringUntil('\n');
        // Convert the received data to a float
        float randomNumber = data.toFloat();
        // Print the received random number
        Serial.print("Received random number: ");
        Serial.println(randomNumber, 4);
        
        // Send the random number to ATmega over UART
        // Convert float to string before sending
        char buffer[20];
        sprintf(buffer, "%.4f", randomNumber); // Format float with 4 decimal places
        Serial2.println(buffer);
      }
    }
    client.stop();
    Serial.println("Client disconnected");
  }
}


// #include <WiFi.h>
// #include <HardwareSerial.h>

// const char* ssid = "Ninja Turtle";
// const char* password = "applepie";

// WiFiServer server(80);

// void setup() {
//   Serial.begin(9600);
//   Serial2.begin(9600); // Initialize Serial2 for communication with ATmega
  
//   delay(10);

//   // Connect to Wi-Fi
//   Serial.println();
//   Serial.print("Connecting to ");
//   Serial.println(ssid);
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(2000);
//     Serial.print(".");
//   }
//   Serial.println("");
//   Serial.println("WiFi connected");

//   // Start the server
//   server.begin();
//   Serial.println("Server started");
// }

// void loop() {
//   WiFiClient client = server.available();
//   if (client) {
//     Serial.println("New client connected");
//     while (client.connected()) {
//       delay(2000);
//       if (client.available()) {
//         // Read the incoming data
//         String data = client.readStringUntil('\n');
//         // Convert the received data to an integer
//         int randomNumber = data.toInt();
//         // Print the received random number
//         Serial.print("Received random number: ");
//         Serial.println(randomNumber);
        
//         // Send the random number to ATmega over UART
//         Serial2.print(randomNumber);
//         Serial2.print('\n'); // Terminate with newline character
//       }
//     }
//     client.stop();
//     Serial.println("Client disconnected");
//   }

    //Serial.println("will this print");

    // Serial.println("test");

    //delay(2000);

//}





// #include <WiFi.h>

// const char* ssid = "Ninja Turtle";
// const char* password = "applepie";

// WiFiServer server(80);

// void setup() {
//   Serial.begin(115200);
//   delay(10);

//   // Connect to Wi-Fi
//   Serial.println();
//   Serial.print("Connecting to ");
//   Serial.println(ssid);
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(2000);
//     Serial.print(".");
//   }
//   Serial.println("");
//   Serial.println("WiFi connected");

//   // Start the server
//   server.begin();
//   Serial.println("Server started");
// }

// void loop() {
//   WiFiClient client = server.available();
//   if (client) {
//     Serial.println("New client connected");
//     while (client.connected()) {
//       if (client.available()) {
//         // Read the incoming data
//         String data = client.readStringUntil('\n');
//         // Convert the received data to an integer
//         int randomNumber = data.toInt();
//         // Print the received random number
//         Serial.print("Received random number: ");
//         Serial.println(randomNumber);
//       }
//     }
//     client.stop();
//     Serial.println("Client disconnected");
//   }
// }


// #include <WiFi.h>

// const char* ssid = "Ninja Turtle";
// const char* password = "applepie";

// WiFiServer server(80);

// void setup() {
//   Serial.begin(115200);
//   delay(10);

//   // Connect to Wi-Fi
//   Serial.println();
//   Serial.print("Connecting to ");
//   Serial.println(ssid);
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(2000);
//     Serial.print(".");
//   }
//   Serial.println("");
//   Serial.println("WiFi connected");

//   // Start the server
//   server.begin();
//   Serial.println("Server started");
// }

// void loop() {
//   WiFiClient client = server.available();
//   if (client) {
//     Serial.println("New client connected");
//     while (client.connected()) {
//       if (client.available()) {
//         char request = client.read();
//         Serial.println(request);
//         // Assuming you receive a specific character as a signal to turn on the LED
//         if (request == '1') {
//           // Code to turn on the LED
//           Serial.println("LED on");
//         }
//       }
//     }
//     client.stop();
//     Serial.println("Client disconnected");
//   }
// }
