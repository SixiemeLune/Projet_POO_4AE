#include "classes.h"


void Capteur::setPIN(int pin){
    this->PIN = pin; 
}

Capteur::Capteur(int pin){
    this->PIN = pin; 
}

int Capteur::getPin(){
    return this->PIN;
}



/* _________________________________________________________
   __________________CAPTEUR TEMPERATURE____________________
   _________________________________________________________*/

Capteur_Temp::Capteur_Temp(int pin) : Capteur(pin){
    temp =0.0;
}

void Capteur_Temp::mesurerTempe(){
    int a = analogRead(this->PIN);
    float R = 1023.0/a-1.0;
    R*=R0;
    this->temp = (1.0/(log(R/R0)/B+1/298.15)-273.15);
}

float Capteur_Temp::getValue1(){
    return this->temp;
}



/* _________________________________________________________
   __________________CAPTEUR HUMIDITE ______________________
   _________________cf DHT nonblocking______________________*/

Capteur_Humid::Capteur_Humid(int pin) : Capteur(pin){
    humidity = 0.0 ;
    temperature = 0.0 ;
}

void Capteur_Humid::mesurerHumid(){
    float value = analogRead(this->PIN);
    this->temperature = value/(10.0);
}

void Capteur_Humid::mesurerTemperature(){
    float value = analogRead(this->PIN);
    this->temperature = value/(10.0);
}

float Capteur_Humid::getValue2(){
    return this->humidity ;
}

float Capteur_Humid::getValue1(){
    return this->temperature ;
}


/* _________________________________________________________
   __________________CAPTEUR LUMIERE________________________
   _________________ ______________________*/

Capteur_Lumin::Capteur_Lumin(int pin) : Capteur(pin){
    luminosity = 0.0 ;
}

void Capteur_Lumin::mesurerLumin(){
    float value = analogRead(this->PIN);
    this->luminosity = value ;
}

float Capteur_Lumin::getValue1(){
    return this->luminosity ;
}

/* _________________________________________________________
   __________________SERVO-MOTEURS_____________
   _________________ ______________________*/


void My_Servo::Init(){
    this->connected = false;
    this->min_us = DEFAULT_MIN_PULSE_WIDTH; // Valeur min typique pour une PWM d'un servo en microsecondes
    this->max_us = DEFAULT_MAX_PULSE_WIDTH;
    this -> time_on_us = (DEFAULT_MIN_PULSE_WIDTH+DEFAULT_MAX_PULSE_WIDTH)/2; // Duty cycle 50% le servo ne bouge pas
    this->angle = 0;
    this->connected = false;
}

My_Servo::My_Servo(){
    Init();
}



My_Servo::My_Servo(int pin){
    Init();
    this->PIN = pin;
}

int My_Servo::connect(int pin){
    if (this->connected == false){
        pinMode(pin,OUTPUT);
        digitalWrite(pin,LOW);
        this->PIN =pin;
        this->connected = true;
    }
    return pin;
}


void My_Servo::setAngle(int angle) { // On suppose que l'entrée est entre 0 et 180 degrés
    if (this->connected == true){
        angle = constrain(angle, 0, 180);
        this->angle = angle;
        this->time_on_us = map(angle, 0,180,min_us,max_us);
        time_on_us = constrain(time_on_us, min_us,max_us);
        startWaveform(PIN,time_on_us,REFRESH_INTERVAL-time_on_us,0); // PWM de duty cycle time_on_us
    }
}
    
int My_Servo::getAngle (){
    return this->angle;
}

void My_Servo::Open_Blinds(){
    setAngle(90);
}

void My_Servo::Close_Blinds(){
    setAngle(0);
}


