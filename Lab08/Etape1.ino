/*  Jean Rouleau / S. Bourassa
  Date :  Décembre 2014 / Janvier 2019
  Titre: Laboratoire 8a - Température affiché au moniteur.
  Nom du programme : L08a_TMP36.ino
  But :   Afficher la température au moniteur
*/

int BROCHETEMP = A5; // Broche analogique analog 1 pour le capteur TMP36.
                               // Sa sensibilité est 10 mV / degré Celsius.
                               // (500 mV offset) à 0 C pour une température négative.
               
void setup() {

  Serial.begin(9600);  // Démarre la connexion série avec l'ordinateur
                                      // le résultat est affiché par l'option outil/moniteur série 
}
 
void loop()
{ 
  // Obtiens la tension correspondante à la température.  
  float tension = (analogRead(BROCHETEMP) / 1023) * 5.0;
  //float tension = (analogRead(BROCHETEMP) / 1023) * 3.3;        
  Serial.print("La tension est: ");
  Serial.print(tension);
  Serial.println(" Volts ");
  
  // Conversion de la tension pour la température 
  float temperature = (tension - 0.5) * 100;
  // float temperature = tension * 0.5 / 100;

  //Affiche le résultat moniteur série
  Serial.print("La température est: ");
  Serial.print(temperature);
  Serial.println(" C");
  delay(1000);

} // Fin Void Loop
