/*
 * 
 * Laboratoire 4 - Étape 5
 * 
 */

void setup()
{                
    pinMode(9, OUTPUT);  // Broche 9 en sortie pour le moteur DC
    Serial.begin (9600); // Initialisation du moniteur série
    Serial.println(); // nécessaire affin d'éviter l'affichage
                      // de caractères bizarres au début de la ligne suivant
    Serial.println( "Question Bonus (5) Du Laboratoire 4" );
    Serial.println( "- par Lihua et Linus" );
    Serial.println( "------------------------------------------------------------" );
    Serial.println(); // on saute une ligne
}

void loop()
{
    // Boucle qui alterne la vitesse du moteur (vitesse basse et vitesse élevée)
    Serial.println( "Début du cycle d'accélération" );
    for(int i = 0; i < 10; i++)
    {
        analogWrite( 9, 200 ); // le moteur roule à une vitesse élevé
        delay( 1000 );
        analogWrite( 9, 600 );  // le moteur roule à une vitesse basse
        delay( 3000 );
    }

    digitalWrite( 9, LOW ); // pour arrêter le moteur
    Serial.println( "Moteur en pause" );

    // on finit par boucle infinie qui ne fait rien (exigeance de la question)
    while (true) {}
 
} // fin de loop()
