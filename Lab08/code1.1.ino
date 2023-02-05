// Étape 1

int BROCHE_TMP = A1; // Broche analogique analog 1 pour le capteur TMP36.
                     // Calibré à 10 mV / degré Celsius.
                     // (500 mV offset) à 0 C pour une température négative.
               
void setup() 
{
    Serial.begin(9600);
}
 
void loop()
{ 
    // Obtiens la tension correspondante 
    float tension = analogRead( BROCHE_TMP ) / 1023 * 5.0;

    // On affiche la tension
    Serial.print( "La tension est de: " );
    Serial.print( tension, 3 ); // à trois décimales près
    Serial.print( " Volts. " ); 
 
    // Conversion de la tension en température 
    float temperature = (tension - 0.5) * 100;

    // On affiche la température
    Serial.print("La température correspondante est de: ");
    Serial.print(temperature, 1); // à une décimale près
    Serial.println(" C.");

    // délai d’une seconde afin de permettre la lecture des résultats
    delay(1000);
    
} // Fin Void Loop 



   
  
