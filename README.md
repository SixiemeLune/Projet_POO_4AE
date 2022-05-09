# Verti Agri _ JUNCK Simon, HATTE Léonie



## Liste composants 
### Capteurs
 Température
 Humidité 
 Luminosité

## Actionneurs
Moteur (pour des stores pour faire de l'ombre)
Ventilateur 

## Comment tester et compiler son code
1. Le dossier Mes_Classes contenant les codes sources et header de nos classes persos doit être copié dans l'arborescence ~/(chemin vers arduino)/arduino-1.8.19/libraries
Il est difficile d'ouvrir les fichiers .cpp et .h directement à partir de Arduino IDE. Je l'ai fait sous VSCode à la séance 3.

2. Une fois que c'est fait, ouvrir un fichier .ino sous Arduino IDE. Inclure <classes.h>, qui est le nom donné au fichier .h associé à l'étape 1. Mon fichier s'appelle test_mes_classes.ino

3. Tester dans le .ino

4. Compiler sous Arduino IDE (même quand on est en train de tester la librairie)


## Notes diverses
### Séance 3
J'ai commencé à coder tout sous un seul et même fichier classes.cpp avant de le scinder en .h et .cpp, ce qui explique la présence de 3 fichiers.
Classes.cpp est une ébauche. Les fichiers les plus avancés sont dans Mes_Classes et compilent via test_mes_classes.


### 09/05/2022

Une version avec trois types de capteurs, un servo et un affichage propre est dispo dans Test_mes_classes.

Materiel      	       | PIN
---------------------- | -------------
Capteur DHT 	       | D5
Capteur Luminosité     | A0
Servo Moteur	       | D6


###### Lien Esp :  http://arduino.esp8266.com/stable/package_esp8266com_index.json


