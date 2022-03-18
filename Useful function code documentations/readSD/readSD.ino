//Mark Neil Crisostomo
#include <SD.h>
char text[32];
File myFile;

void readingSD() {
  // Open serial communications and wait for port to open:
  //  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.print("Initializing SD card...");
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  // open the file for reading:00
  myFile = SD.open("bayotka.txt");
  if (myFile) {
    Serial.println("bayotka.txt:");
    // read from the file until there's nothing else in it:
    while (myFile.available()) {

      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening bayotka.txt");
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SD.begin(10);


}

void loop() {
  readingSD();
  delay(6000);
}
