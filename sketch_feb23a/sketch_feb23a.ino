#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8);  // CE, CSN pins

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(0xF0F0F0F0E1LL);  // Set the address for communication
}

void loop() {
  char textMessage[] = "Hello, Receiver!";  // Message to be sent
  radio.write(&textMessage, sizeof(textMessage));
  Serial.println("Message Sent: " + String(textMessage));
  delay(1000);  // Wait for 1 second before sending the next message
}
