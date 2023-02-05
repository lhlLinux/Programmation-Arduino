// Étape 2

int BROCHE_TMP = A1; // Broche analogique analog 1 pour le capteur TMP36.
                     // Calibré à 10 mV / degré Celsius.
                     // (500 mV offset) à 0 C pour une température négative.
                     
float temp[3];       // Trois espaces mémoires pour la sauvegarde des 3 températures. 
float tension;       // Initialiser la variable tension en valeur réelle.
             
void setup()
{
    Serial.begin(9600);
}
 
void loop()
{  
    for (int t = 0; t < 3; t++)
    {
        tension = analogRead( BROCHE_TMP ) / 1023 * 5.0;
        delay (100);
        temp[t] = tension;
    }
    // on calcul la valeur moyenne des trois mesures.  
    tension = (temp[0] + temp[1] + temp[2]) / 3;
 
    // Conversion de la tension pour la température 
    float temperature = (tension - 0.5) * 100;    

    // On affiche la tension
    Serial.print("La tension est: ");
    Serial.print(tension, 3);
    Serial.print(" Volts. ");

    // On affiche la température en Celsius
    Serial.print("La température est de: ");
    Serial.print(temperature, 1);
    Serial.print(" C /");

    // On affiche la température en Fahrenheit
    Serial.print( (temperature * 1.8) + 32, 1);
    Serial.println(" F.");
 
    // délai d’une seconde afin de permettre la lecture des résultats
    delay(1000);

} // Fin void
