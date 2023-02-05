
// Étape 3

int intensite = 0;
const int brocheDEL = 3;

void setup()
{
  Serial.begin(9600);
  pinMode( brocheDEL,OUTPUT );
}

void loop()
{ 
//  Serial.println("Entrez une valeur entre 0 et 255 dans la zone d'ecriture");
//  while (!Serial.available()) { delay(33); }     // Boucle aussi longtemps qu’on n’a pas entré une 

  if (Serial.available())
  {
  //Serial.parseInt();
  intensite = Serial.parseInt();                // Initialise la variable rouge avec une valeur dans la 
  Serial.flush();
  intensite = constrain(intensite, 0, 255);   // Protection pour être dans la plage 0 à 255  
  analogWrite( brocheDEL, intensite );           // Initialise l’intensité de la DEL
  Serial.print( "Voici la valeur que le programme a capté :  ");
  //Serial.flush();
  Serial.println( intensite, DEC );            // La valeur est affichée au moniteur en décimale DEC.  
  }

  delay(33);
  // HEX pour afficher en hexa.
  //Serial.println( "" );
  
}
