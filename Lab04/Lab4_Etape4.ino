/*
 * 
 * Laboratoire 4 - Étape 4
 * 
 */

int largeurPWM = 0;    

void setup()
{                
    pinMode(9, OUTPUT);  // Broche 9 en sortie pour le moteur DC
    Serial.begin (9600); // Initialisation du moniteur série
    Serial.println(); // buffer flush: nécessaire affin d'éviter l'affichage
                      // de caractères bizarres au début de la ligne suivant
    Serial.println( "Affichage des tensions appliquées au moteur DC en temps réél" );
    Serial.println( "- par Lihua et Linus" );
    Serial.println( "------------------------------------------------------------" );
    Serial.println(); // on saute une ligne
}

void loop()
{
    // On procède à l'accélération du moteur
    Serial.println( "Début du cycle d'accélération" );
    for(int i = 0; i < 256; i+=10) // on accélère par incréments de 10
    {
      analogWrite( 9, i );
      Serial.print( "La tension est: " );
      Serial.print( largeurPWM / 255.0 * 5.0 ); // on affiche la tension
      Serial.println( " Volts"); // on termine l'affichage et on saute une ligne
      delay( 1000 ); // On accorde du temps pour lire la valeur une fois affichée
    }
    Serial.println( "Cycle d'accélération terminé" );

    delay( 2000 ); // une petite pause avant de procéder à la prochaine phase
    Serial.println(); // on saute une ligne
    
    // Maintenant on décélère
    Serial.println( "Début du cycle de décélération" );
    for(int i = 255; i >= 0; i-=15) // on décélère par incréments de 15
    {
      analogWrite( 9, i );
      Serial.print( "La tension est: " );
      Serial.print( largeurPWM / 255.0 * 5.0 );  // on affiche la tension
      Serial.println( " Volts"); // on termine l'affichage et on saute une ligne
      delay( 1000 ); // On accorde du temps pour lire la valeur une fois affichée
    }
    Serial.println( "Cycle de décélération terminé" );

    delay( 2000 ); // une petite pause avant de recommencer
    Serial.println(); // on saute une ligne
    
} // fin de loop()
