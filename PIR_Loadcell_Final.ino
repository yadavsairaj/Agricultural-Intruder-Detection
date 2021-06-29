#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;
int ledPin = 13;                // LED 
int pirPin = 4;                 // PIR Out pin 
int pirStat = 0;                   // PIR status

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  pinMode(ledPin, OUTPUT);     
 pinMode(pirPin, INPUT);     
 Serial.begin(9600);
}

void loop() {
pirStat = digitalRead(pirPin); 
  if (scale.is_ready()) {
    long reading = scale.read();
    
      if(reading<0)
        { Serial.println("intruder found!!!");
        }
        else if (pirStat== HIGH)
        {Serial.println("intruder found!!!"); 
          }
    
  else {
    Serial.println("not found.");
  }}

  delay(1000);

}
