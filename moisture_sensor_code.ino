//Libraries
#include <Wire.h>

void setup()
{
    Serial.begin(9600);
    pinMode(4, OUTPUT);
}

void loop() {
  // defining variable for sensor rerading
  int SensorValue = analogRead(A1); //read the input on analog pin 1
  Serial.println(SensorValue); //prints the value read by sensor on the serial monitor:
  if (SensorValue < 650) {
    digitalWrite(4, LOW);
    Serial.print("pump:OFF");
  } else {
    digitalWrite(4, HIGH);
    Serial.print("pump:ON ");
  }
  delay(1000); //Delay 1 sec.
}