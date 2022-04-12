

class Capteur {
    
    protected:
    char PIN;

    public:
    virtual int getValue() = 0;


    void setPIN(char pin){
        this->PIN = pin; 
    }

    Capteur(char pin){
        this->PIN = pin; 
    }
};


class Capteur_Temp : Capteur {
    protected:
    float temp;
    
    public:

    Capteur_Temp():Capteur(){
        temp =0.0;
    }

    float mesurerTemp(){
        int a = analogRead(this->PIN); // pour faire ça include la librairie arduino
        float R = 1023.0/a-1.0;
        R*=100000;
        this->temp = 
    }
}



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

