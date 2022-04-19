#include "classes.h"
#define COOLDOWN_HUMIDITY_SENSOR 2000

Capteur_Temp c1(PIN_A0);
// Capteur_humid h1(PIN_...)  A DEFINIR

void setup() { 
  Serial.begin(9600);   // pour initialiser le port série
}

void loop() {

  c1.mesurerTempe();
  Serial.print("ça marche sur la pin ");

  Serial.println(c1.getPin());

  Serial.print("Il fait ");

  Serial.print(c1.getValue());
  Serial.println(" °C");
  delay(100);


  // TEST POUR LE CAPTEUR D'HUMIDITE
  
/* 
 *  
 *  h1.mesurerHumid();
 *  Serial.print("ça marche sur la pin ");
 *  Serial.println(h1.getPin());
 *  Serial.print("Température à  ");
 *  Serial.print(h1.getValue1());
 *  Serial.println(" °C");
 *  Serial.print("Humidité à  ");
 *  Serial.print(h1.getValue2());
 *  Serial.println(" %");
 *  delay(COOLDOWN_HUMIDITY_SENSOR); // délai necessaire pour le cooldown du capteur
 *  
 */
  
  
}
