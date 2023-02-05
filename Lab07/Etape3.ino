
// Étape 3

int brochePHOTO = A0;
int brocheDEL_ROUGE = 6;
int brocheDEL_VERTE = 2;    
int forceLUMIERE;
 
void setup()
{
  // Broches en sortie pour la DEL
  pinMode(brocheDEL_ROUGE, OUTPUT);
  pinMode(brocheDEL_VERTE, OUTPUT);
  Serial.begin(9600);
}

int intensite = 0;
int DEL = 0;
int tension = 0;

void loop()
{
  forceLUMIERE = analogRead(brochePHOTO);
  
  // On produit une valeur pour la DEL
  DEL = map(forceLUMIERE, 64, 911, 0, 255);
  intensite = constrain(DEL, 0, 255);
 
  if ( intensite > 128 ) // on établit le seuil du changement à la moitié
  {
    digitalWrite( brocheDEL_VERTE, LOW  );
    digitalWrite( brocheDEL_ROUGE, HIGH );
  }
  else
  {
    digitalWrite( brocheDEL_ROUGE, LOW  );
    digitalWrite( brocheDEL_VERTE, HIGH );
  }

  tension = forceLUMIERE / 1023.0 * 5.0;

  // On affiche la tention
  Serial.print( "La tension à la photorésistance est de: " );
  Serial.print( tension );
  Serial.println( " volts." );

  // On affiche la tention
  Serial.print( "Le courant à la photorésistance est de: " );
  // ici on réétalonne la valeur de la broche analogique (donc de la photorésistance)
  // sur la plage 10000ohm (au minimum, de la résistance), à 2Mohm
  Serial.print( tension / map( forceLUMIERE, 0, 1023, 10000, 2000000 ) );
  Serial.println( " mA." );

  delay(500);
}
