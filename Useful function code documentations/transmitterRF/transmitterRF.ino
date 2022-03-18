


//code for transmitting message into the RF -.-.-.-.-.-.-.-.-.-.-.-.-.-.-
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "ABCDE"; // the address the the module

/**
  03/19/2022
  3:04
  .00005
  0934

*/

//String data[] = {"03/19/2022", "3:04", ".00005", "0934"};

void setup() {
  radio.begin();
  Serial.begin(9600);

  radio.setAutoAck(false);
  SPI.setClockDivider(SPI_CLOCK_DIV4);
  radio.setRetries(15, 15);
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();

}

void To_send() {
  char text[] = "03/19/2022_3:04_.00005_0934";
  radio.write(&text, sizeof(text));
  Serial.println(text);
  delay(500);

}

void loop()
{
  To_send();

}














