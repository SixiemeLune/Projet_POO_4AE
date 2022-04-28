#ifndef MY_CLASSES_H
#define MY_CLASSES_H

#include <Arduino.h>
#include <math.h>
#include "core_esp8266_waveform.h" //Waveform used in Servo control

//----------CONSTANTES TEMPERATURE ---------------------//
#define R0 100000 //Sert dans le calcul de la température
#define B 4275 // idem

//----------CONSTANTES ACTUATOR ET SERVO --------------------------//
#define DEFAULT_PIN 13 // GPIO13 corresponds to D7
#define DEFAULT_MIN_PULSE_WIDTH      1000 // uncalibrated default, the shortest duty cycle sent to a servo
#define DEFAULT_MAX_PULSE_WIDTH      2000 // uncalibrated default, the longest duty cycle sent to a servo 
#define DEFAULT_NEUTRAL_PULSE_WIDTH  1500 // default duty cycle when servo is attached
#define REFRESH_INTERVAL            20000 // classic default period to refresh servos in microseconds 



class Capteur {
    protected:
        int PIN;

    public:
        virtual float getValue1() = 0 ;
        virtual float getValue2() = 0 ;
        void setPIN(int pin);
        int getPin();
        Capteur(int pin);
    
};



/* _________________________________________________________
   __________________CAPTEUR TEMPERATURE____________________
   _________________________________________________________*/

class Capteur_Temp : public Capteur {
    protected:
        float temp;

    public:
        Capteur_Temp(int pin);
        void mesurerTempe();
        float getValue1();
};



/* _________________________________________________________
   __________________CAPTEUR HUMIDITE ______________________
   _________________cf DHT nonblocking______________________*/

class Capteur_Humid : public Capteur {
    protected : 
        float humidity ;
        float temperature ;
        
    public : 
        Capteur_Humid(int pin);
        void mesurerHumid() ;
        void mesurerTemperature() ;
        float getValue1() ; // récupère la valeur de l'a température
        float getValue2() ; // récupère la valeur de l'humidité
} ;



/* _________________________________________________________
   __________________CAPTEUR LUMIERE________________________
   _________________ ______________________*/
   
class Capteur_Lumin : public Capteur {
    protected : 
        float luminosity ;
        
    public : 
        Capteur_Lumin(int pin);
        void mesurerLumin() ;
        float getValue1() ; // récupère la valeur de la luminosité
} ;  
   
   
   
/* _________________________________________________________
__________________SERVO-MOTEURS_____________
_________________ ______________________*/
  


class My_Servo {
    private:
    void Init();
    protected:
    mutable int PIN;
    bool connected;
    int angle;
    int min_us;
    int max_us;
    int time_on_us;

    public:
    My_Servo();
    My_Servo(int pin);
    int connect(int pin);
    void setAngle(int angle);
    int getAngle();
    void Open_Blinds();
    void Close_Blinds();
};


#endif