// Étape 4

int BROCHE_BOUTON = 7;
int BROCHE_TMP = A1;
float temp[3];
float tension;
int choix = 0; // Initialement on n'affiche pas la température
int lecture;
            
void setup() 
{
    pinMode( BROCHE_BOUTON, INPUT );
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
  
    if (Serial.available())
    {
        lecture = Serial.parseInt();
        if (lecture == 1)
            choix = 1;

        if (lecture == 2)
            choix = 2;
    }

    // la température est affichée en fonction du choix
    if (choix == 2)
    {
        // le bouton n'est PAS appuyé: on affiche la température en Celsius
        Serial.print("La température est de: ");
        Serial.print(temperature, 1);
        Serial.println(" C.");
    }
    else if (choix == 1)
    {
        // le bouton EST appuyé: on affiche la température en Fahrenheit
        Serial.print("La température est de: ");
        Serial.print( (temperature * 1.8) + 32, 1);
        Serial.println(" F.");
    }
    // Tout autre choix est exclu
    
    // délai d’une seconde afin de permettre la lecture des résultats
    delay(1000);

} // Fin void
