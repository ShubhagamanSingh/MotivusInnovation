//Adding Libraries 

#include <SPI.h>                  /* to handle the communication interface with the modem*/
#include <nRF24L01.h>             /* to handle this particular modem driver*/
#include <RF24.h>                 /* the library which helps us to control the radio modem*/

#define pot_pin A0                /*Variable pin of POT is to be connected to analog pin 0 i.e.A0*/
RF24 radio(7,8);                    /* Creating instance 'radio'  ( CE , CSN )   CE -> D7 | CSN -> D8 */                              
const byte Address[6] = "00001" ;     /* Address to which data to be transmitted*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pot_pin,INPUT);         /* Setting A0 (POT pin) as input*/
  radio.begin ();                 /* Activate the modem*/
  radio.openWritingPipe (Address); /* Sets the address of transmitter to which program will send the data */
}
void loop() {
  // put your main code here, to run repeatedly:
  radio.stopListening ();          /* Setting modem in transmission mode*/
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.print("Transmitting Voltage: ");
  Serial.print(voltage);                           /* Printing POT value on serial monitor*/
  Serial.println(" V");
  radio.write(&voltage, sizeof(voltage));            /* Sending data over NRF 24L01*/
  delay(1000);
}
