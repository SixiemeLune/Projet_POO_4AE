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


Capteur_Temp::Capteur_Temp(int pin) : Capteur(pin){
    temp =0.0;
}

void Capteur_Temp::mesurerTempe(){
    int a = analogRead(this->PIN);
    float R = 1023.0/a-1.0;
    R*=R0;
    this->temp = (1.0/(log(R/R0)/B+1/298.15)-273.15);
}

float Capteur_Temp::getValue(){
    return this->temp;
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
