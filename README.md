# Plant Monitoring 
## HATTE Léonie, JUNCK Simon 
> Projet réalisé au cours de notre 4ème Année Automatique et Elecronique dans le cadre du Bureau d'Etudes Programmation Orientée Objet.

> Ce projet est un moniteur d'environnement pour plantes d'intérieur. Il mesure la température, l'humidité et la luminosité de l'environnement proche de la plante. Aussi, à partir d'un certain seuil de température modifiable, l'Arduino commande un servomoteur qui ferme des stores vénitiens pour faire de l'ombre à votre plante bien aimée.  
> Il est aussi agréable pour votre plante d'avoir une exposition au soleil constante et pas trop importante. C'est pour cela que lorsque les stores sont ouvert, notre système adapte l'angle du store afin de garantir une luminosité constante sur votre belle et majestueuse plante. 


## Liste composants 
### Capteurs
* Température
* Humidité 
* Luminosité

### Actionneurs
* Servomoteurs (pour des stores afin de faire de l'ombre)

- - - -

## Comment tester et compiler son code
1. Le dossier **Mes_Classes** contenant les codes sources et header de nos classes persos doit être copié dans l'arborescence **~/(chemin vers arduino)/arduino-1.8.19/libraries**
Il est peu convénient d'ouvrir les fichiers .cpp et .h directement à partir de Arduino IDE. Cependant tout autre IDE est optimal. 

2. Une fois que c'est fait, ouvrir un fichier .ino sous Arduino IDE. Inclure **<classes.h>**, qui est le nom donné au fichier .h associé à l'étape 1. Notre fichier main se prénomme main.ino et est situé dans un répertoire comportant le meme nom.
Il est convenable de déplacer ce répertoire dans le dossier des carnets de croquis Arduino IDE afin d'y accéder plus facilement. **Par défaut le répertoire du carnet de croquis se situe ici : *~/Arduino***

3. Lancer la compilation et le téléversement sous Arduino IDE.

4. Ouvrir le moniteur série d'Arduino IDE.

5. Apprécier les informations optimales pour garantir le bien-être de votre ami(e) plantesque.

- - - -


## Matériel utilisé et exemple de PINs associées  

Une version avec trois types de capteurs, un servo et un affichage propre est dispo dans **main.ino**

Materiel      	       | PIN
---------------------- | -------------
Capteur DHT 	       | D5
Capteur Luminosité     | A0
Servo Moteur	       | D6




<details>
    <summary>Lien Drivers ESP8266</summary>
        <p>http://arduino.esp8266.com/stable/package_esp8266com_index.json</p>
</details>

