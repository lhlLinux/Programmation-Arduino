// Étape 3

#include <Servo.h>

const int brocheServo = 9;
const int brocheDEL = 3;
int valeur = 0;
int pos = 0;

Servo mservo;

void setup()
{
  Serial.begin(9600);
  Serial.flush();
  pinMode( brocheDEL,OUTPUT );
  mservo.attach( brocheServo );
}

void loop()
{ 
  Serial.println("Entrez une valeur entre 0 et 255.");
  while (!Serial.available()) { delay(33); } // Boucle aussi longtemps qu'on n'a rien entré
  
  valeur = Serial.parseInt();          // Initialise la variable avec une valeur

  if (valeur < 0)
    Serial.println( "La valeur sera fixée au minimum" );
  else if (valeur > 255)
    Serial.println( "La valeur sera fixée au maximum" );
  
  valeur = constrain( valeur, 0, 255 );  // Protection pour être dans la plage 0 à 255  
 
  analogWrite( brocheDEL, valeur );    // Initialise l’intensité de la DEL
  pos = map( valeur, 0, 255, 5, 175 ); // Translation de la position de 5 à 175 degrés.
  // pos = constrain( pos, 5, 175 );   // Cette ligne n'est plus ncessaire car la ligne
                                       // prcédente s'occupe de la même tâche

  mservo.write( pos ); // On fait bouger le moteur

  Serial.print( "Voici la valeur que le programme a capté :  ");
  Serial.println( pos, DEC );
}
