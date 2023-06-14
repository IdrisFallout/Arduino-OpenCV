#include <cvzone.h>
#define LED 13

SerialData serialData(1, 1);
int valsRec[2];

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  serialData.begin();
}

void loop() {
  serialData.Get(valsRec);
  digitalWrite(LED, valsRec[0]);
  // delay(10);
}