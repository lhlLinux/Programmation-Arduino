// Étape 4

#include <Servo.h>

const int brocheServo = 9;
const int brocheDEL = 3;
const int brochePot = A3;
int lum = 0;
int pos = 0;
int valeur = 0;

Servo mservo;

void setup()
{
  Serial.begin(9600);
  Serial.flush();
  pinMode( brocheDEL, OUTPUT );
  pinMode( brocheServo, OUTPUT );
  pinMode( brochePot, INPUT );

  mservo.attach( brocheServo );
}

void loop()
{ 
  valeur = analogRead( brochePot ); // On lit le potentiomètre
  
  // on se prépare pour allumer la DEL
  lum = map( valeur, 0, 1023, 0, 255 );
  analogWrite( brocheDEL, lum );
  
  // on se prépare pour faire bouger le moteur
  // Comme à l'étape 3, la fonction constrain()
  // n'est plus nécessaire car on applique déjà
  // les contraintes avec la fonction ci-dessous
  pos = map( valeur, 0, 1023, 5, 175 );
  mservo.write( pos );
  
  Serial.print( "La tension au potentiomètre est de:  ");
  Serial.println( valeur / 1023.0 * 5, 3 );
  Serial.println( "Volts" );

  delay(33);
}
