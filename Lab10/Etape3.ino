
// Étape 3

// Broches du transistor
int baseTRANSISTOR =  2;
int brocheVbe = A5;
int brocheVce = A3;

// Broches pour le bouton es la DEL
int brocheDEL = A1;
int brocheBOUTON = 4;

// Variables de lecture
float valeurDEL = 0;
float valeurVbe = 0;
float valeurVce = 0;

float tension = 0;
bool relaiACTIVE = false;

void setup()
{
  // On initialise certaines broches
  pinMode(baseTRANSISTOR, OUTPUT);
  pinMode(brocheBOUTON, INPUT);
  pinMode(brocheDEL, INPUT); 
  
  Serial.begin(9600); // on active la console
}

void loop()
{
  // le bouton est monté en rappel haut, donc l'état 'appuyé'
  // corresponds à un 'LOW'
  if (digitalRead(brocheBOUTON) == LOW)
  {
      // si le relai est actif, appuyer le bouton est interpété
      // comme une demande pour couper le courant au relai
      if (relaiACTIVE == true)
      {
        // On désactive le relai
        digitalWrite(baseTRANSISTOR, LOW);
        relaiACTIVE = false;
        Serial.println("Relai non-alimenté");

        // on lit la valeur analogique à la DEL
        // pour calculer les valuers requises à afficher
        valeurDEL = analogRead(brocheDEL);
        tension = valeurDEL / 1023.0 * 5.0;
        Serial.print( "La valeur décimale est de: " );
        Serial.println( valeurDEL );
        
        Serial.print( "La tension à la DEL jaune est de: " );
        Serial.print( tension );
        Serial.println( "V" );
        
        Serial.print( "Le courant à la DEL jaune est de: " );
        Serial.print( tension / 560.0 * 1000, 3 );
        Serial.println( "mA" );
      }
      else // relai n'est pas actif, donc appuyer le bouton l'active
      {
        // on active le relai
        digitalWrite(baseTRANSISTOR, HIGH);
        relaiACTIVE = true;
        Serial.println("Relai alimenté");

        // on lit la valeur analogique à la DEL
        // pour calculer les valuers requises à afficher
        valeurDEL = analogRead(brocheDEL);
        tension = valeurDEL / 1023.0 * 5.0;
        Serial.print( "La valeur décimale est de: " );
        Serial.println( valeurDEL );
        
        Serial.print( "La tension à la DEL jaune est de: " );
        Serial.print( tension );
        Serial.println( "V" );
        
        Serial.print( "Le courant à la DEL jaune est de: " );
        Serial.print( tension / 560.0 * 1000, 3 );
        Serial.println( "mA" );
      }
  }
  
  valeurVbe = analogRead( brocheVbe );
  valeurVce = analogRead( brocheVce );

  Serial.print( "Les tensions Vbe et Vce: " );
  Serial.print( valeurVbe / 1023.0 * 5.0 );
  Serial.print( "V / " );
  Serial.print( valeurVce / 1023.0 * 5.0 );
  Serial.println( "V" );

  delay(1000);
}
