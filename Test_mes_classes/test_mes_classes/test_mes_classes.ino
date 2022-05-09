#include <classes.h>
#include "dht_nonblocking.h"

DHT_nonblocking capteur1(14,DHT_TYPE_11);
My_Servo servo1;
Capteur_Lumin capteur2(A0);

void setup() { 
  servo1.connect(12);
  Serial.begin(9600);  
}



/*
 * Poll for a measurement, keeping the state machine alive.  Returns
 * true if a measurement is available.
 */
static bool measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  /* Measure once every four seconds. */
  if( millis( ) - measurement_timestamp > 3000ul )
  {
    if( capteur1.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return( true );
    }
  }

  return( false );
}





void loop() {
  float temperature;
  float humidity;
  int luminosity = capteur2.getValue();

 
  

  // Attendre la disponibilité d'une mesure du capteur DHT

  if( measure_environment( &temperature, &humidity ) == true )
  {
     // Affichage DHT

     
    Serial.println("");
    Serial.println("--------------------");
    Serial.println(" -- Température et Humidité -- ");
    Serial.println("");
    Serial.print( "T = " );
    Serial.print( temperature, 1 );
    Serial.print( " deg. C, H = " );
    Serial.print( humidity, 1 );
    Serial.println( "%" );

    // AFFICHAGE LUMINOSITE //
    
    Serial.println("");
    Serial.println(" -- Luminosité -- ");
    Serial.println("");

    Serial.print("Donnée capteur = ");
    Serial.println(luminosity);

    
    if (luminosity<10){
      Serial.println("Noir");
    }
    else if (luminosity < 200){
      Serial.println("Sombre");
    }
    else if (luminosity < 500){
      Serial.println("Eclairé");
    }

    else if (luminosity < 800){
      Serial.println("Lumineux");
    }
    else{
      Serial.println("Très lumineux");
    }




    // INTERPRETATION DONNEES ET CONSEILS UTILISATEUR
    Serial.println("");
    Serial.println(" -- Etat et conseils -- ");
    Serial.println("");
    
    if (temperature > 30){
      servo1.Close_Blinds();
      Serial.println("Les volets sont fermés");
    }
    else {
      servo1.Open_Blinds();
      Serial.println("Les volets sont ouverts");
    }

    if (humidity < 40){
      Serial.println("Air très sec, penser à arroser");
    }
    else if (humidity > 70){
      Serial.println("Air trop humide");
    }
    else {
      Serial.println("Air optimal");
    }


    Serial.println("--------------------");
    Serial.println("");
  }
}
