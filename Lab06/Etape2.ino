// Étape 2

#include <Servo.h>

Servo mservo;
const int brocheServo = 9;
const int brochePot = A0;
int posMoteur = 0;
int pos;

void setup()
{
  mservo.attach( brocheServo);
  pinMode( brochePot, INPUT );
}

void loop()
{
  pos = analogRead( brochePot );        // Lecture de la position à A0.
  pos = map( pos, 0, 1023, 0, 180 );    // Translation de la position de 0 à 180o.
  posMoteur = constrain( pos, 3, 175 ); // Moteur varie entre 3 et 175o.
  mservo.write( posMoteur );            // Positionne le moteur (broche 9). 
}
