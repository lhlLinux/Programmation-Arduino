
// Étape 1

#include <Servo.h>

Servo mservo;
int pos;
const int brocheDEL = 6;
const int brocheServo = 9;
int lumDEL = 0;

void setup()
{
  pinMode(brocheDEL, OUTPUT);
  mservo.attach(brocheServo);
}

void loop()
{
  // boucle du balayage initial
  for (pos = 0; pos < 180; pos++)
  {
    mservo.write( pos );
    lumDEL = map( pos, 0, 180, 0, 255 );
    analogWrite( brocheDEL, lumDEL );
    delay( 150 );
  }

  // boucle de retour de l'essuie-glace
  for (pos = 180; pos >= 1; pos-=2)
  {
    mservo.write( pos );
    delay( 75 );
  }
}
