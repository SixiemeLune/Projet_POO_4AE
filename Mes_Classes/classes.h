#ifndef MY_CLASSES_H
#define MY_CLASSES_H

#include <Arduino.h>
#include <math.h>

#define R0 100000 //Sert dans le calcul de la température
#define B 4275 // idem

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
   
   
   
   
   

// Je commente le reste pour tester les capteurs d'abord
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

class Ventilateur : Actuator {
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
#endif