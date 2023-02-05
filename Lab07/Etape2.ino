
// Étape 2

#include <Servo.h>

Servo mservo;
int brochePHOTO = A0; // Entrée analogue pour photorésistance 
int brocheSERVO = 5;  // Broche pour le servomoteur
int forceLUMIERE;     // Variable pour l'intensité de lumière
 
void setup()
{
  // Il n'est pas nécéssaire d'initialiser la broche A0
  mservo.attach( brocheSERVO );
  Serial.begin(9600);
}

int intensite = 0;
int pos = 0;

void loop()
{
  forceLUMIERE = analogRead( brochePHOTO );

  // On affiche les valeurs non transformées
  Serial.print( "Entrée A0:  ");
  Serial.print( forceLUMIERE );

  // On encadre la position entre 5 et 175 degres
  // en fonction du minimum et maximum de la photorésistance
  pos = map( forceLUMIERE, 64, 911, 5, 175 );
  pos = constrain( pos, 5, 175 );

  // On affiche la position envoyée au moteur
  Serial.print( ". Position du moteur:  ");
  Serial.println( pos );

  mservo.write( pos ); // on positionne le moteur
 
  delay(33);
}
