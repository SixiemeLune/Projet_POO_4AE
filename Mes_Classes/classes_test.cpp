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

// Je commente le reste pour dékà essayer de faire marcher les 
// capteurs
/*


class Actuator {
    protected:
    bool state;

    public:

    bool isOn(){
        return(this->state);
    }

    void set(){
        this->state=true;
    }

    void reset(){
        this->state=false;
    }
};

class Ventilateur : public Actuator {
    protected:
    short mode; // On peut imaginer qu'un ventilateur peut avoir plusieurs modes de ventilation
    public:
    //Constructeur
    Ventilateur():Actuator(){
        this->mode = 0; 
    }

    void changeMode(short a){
        this->mode = a; // Faire bien attention a gerer les exceptions ici 
    }
};

class Moteur : Actuator{

};
*/
