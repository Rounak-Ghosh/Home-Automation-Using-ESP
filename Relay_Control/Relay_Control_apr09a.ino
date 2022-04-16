#include "arduino_secrets.h"
/*
  CloudSwitch relay_1;
  CloudSwitch relay_2;
  CloudSwitch relay_3;
  CloudSwitch relay_4;
*/

#include "thingProperties.h"

int connected = 0;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
  pinMode(5, OUTPUT); //D1
  pinMode(4, OUTPUT); //D2
  pinMode(14, OUTPUT); //D5
  pinMode(12, OUTPUT); //D6
  pinMode(2, OUTPUT); // LED inbuilt
  

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  connected = 1;
}

void loop() {
  ArduinoCloud.update();
  if(connected == 0) {
    digitalWrite(2, HIGH);
    delay(500);
    digitalWrite(2, LOW);
    delay(100); 
  }
  else {
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);
    delay(100);
  }
}

void onRelay1Change()  {
  if(relay_1 == 1)
  {
    digitalWrite(5, LOW);
    Serial.println("Relay 1 - ON");
  }
  else
  {
    digitalWrite(5, HIGH);
    Serial.println("Relay 1 - OFF");
  }
}

void onRelay2Change()  {
  if(relay_2 == 1)
  {
    digitalWrite(4, LOW);
    Serial.println("Relay 2 - ON");
  }
  else
  {
    digitalWrite(4, HIGH);
    Serial.println("Relay 2 - OFF");
  }
}

void onRelay3Change()  {
  if(relay_3 == 1)
  {
    digitalWrite(13, LOW);
    Serial.println("Relay 3 - ON");
  }
  else
  {
    digitalWrite(13, HIGH);
    Serial.println("Relay 3 - OFF");
  }}

void onRelay4Change()  {
  if(relay_4 == 1)
  {
    digitalWrite(12, LOW);
    Serial.println("Relay 4 - ON");
  }
  else
  {
    digitalWrite(12, HIGH);
    Serial.println("Relay 4 - OFF");
  }}