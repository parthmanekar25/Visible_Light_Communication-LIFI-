#include<string.h>
#include<HardwareSerial.h>
const int bufferSize = 200; // Define the buffer size according to your needs
char receivedData[bufferSize]; // Character array to store received data
#define TRANSMIT_LED 11
#define BUTTON 3
#define SAMPLING_TIME 20

char* text = receivedData;

//Declaration
bool led_state = false;
bool button_state = false;
bool transmit_data = true;
int bytes_counter = 20;
int total_bytes;

void setup() {
  pinMode(TRANSMIT_LED, OUTPUT);
  Serial.begin(9600);
  updateTotalBytes(); // Initial update of total_bytes
}

void loop() {
  if (Serial.available() > 0) { // Check if data is available to read
    int i = 0;
    while (Serial.available() > 0 && i < bufferSize - 1) {
      char c = Serial.read(); // Read one character at a time
      receivedData[i] = c; // Store the character in the buffer
      i++;
    }
    receivedData[i] = '\0'; // Null-terminate the received data
    text = receivedData; // Update text pointer to point to received data
    Serial.println("Received data:");
    Serial.println(text); // Print the received data

    updateTotalBytes(); // Update total_bytes when text changes
  }
updateTotalBytes();
  while (transmit_data) {
    transmit_byte(receivedData[total_bytes - bytes_counter]);
    bytes_counter--;
    if (bytes_counter == 0) {
      transmit_data = false;
    }
    //delay(100);
  }
  transmit_data = true;
  bytes_counter = total_bytes;
  delay(1000);
}

void transmit_byte(char data_byte) {
  digitalWrite(TRANSMIT_LED, LOW);
  delay(SAMPLING_TIME);
  for (int i = 0; i < 8; i++) {
    digitalWrite(TRANSMIT_LED, (data_byte >> i) & 0x01);
    delay(SAMPLING_TIME);
  }
  digitalWrite(TRANSMIT_LED, HIGH); //Return to IDLE state
  delay(SAMPLING_TIME);
}

void updateTotalBytes() {
  total_bytes = strlen(receivedData); // Update total_bytes based on current text length
}
