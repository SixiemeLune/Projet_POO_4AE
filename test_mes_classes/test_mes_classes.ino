#include <classes.h>


Capteur_Temp c1(PIN_A0);

void setup() { 
  Serial.begin(9600);  
}

void loop() {

  c1.mesurerTempe();
  Serial.print("ça marche sur la pin ");

  Serial.println(c1.getPin());

  Serial.print("Il fait ");

  Serial.print(c1.getValue());
  Serial.println(" °C");
  delay(100);
}
