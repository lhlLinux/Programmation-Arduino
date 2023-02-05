/*  Jean Rouleau / S. Bourassa
  Date :  Décembre 2014 / Janvier 2019
  Titre: Laboratoire 8a - Température affiché au moniteur.
  Nom du programme : L08a_TMP36.ino
  But :   Afficher la température au moniteur
*/

int BROCHE1 = 1; // Broche analogique analog 1 pour le capteur TMP36.
                               // Sa sensibilité est 10 mV / degré Celsius.
                               // (500 mV offset) à 0 C pour une température négative.
               
void setup() 
{
  Serial.begin(9600);  // Démarre la connexion série avec l'ordinateur
                                      // le résultat est affiché par l'option outil/moniteur série 
}
 
void loop()
{ 
 float tension = (analogRead(BROCHE1) * (5.0 / 1023));      // Obtiens la tension correspondante 
             // à la température.  
  Serial.println(tension);
 float temperature = (tension - .5) * 100;       // Conversion de la tension pour la température 

 Serial.println(temperature);                             //Affiche le résultat moniteur série

 delay(1000);                                                       //délai d’une seconde

} // Fin Void Loop 



   
  
