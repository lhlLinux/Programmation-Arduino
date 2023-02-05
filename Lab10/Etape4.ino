// Étape 4

// Broches du transistor et de la photorésistance
int baseTRANSISTOR =  2;
int brocheVbe = A5;
int brocheVce = A3;
int brochePHOTO = A1;

// Variables de lecture
float valeurVbe = 0;
float valeurVce = 0;

void setup()
{
  pinMode(baseTRANSISTOR, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // Notre valeur seuil est la moitié de la valeur maximale de lecture
  if (analogRead(brochePHOTO) > 511)
  {
     // On desactive le relai lorsque la tension est au dessus du seuil
     digitalWrite(baseTRANSISTOR, LOW);
     Serial.println("Relai non-alimenté");     
  }
  else
  {
     // On active le relai lorsque la tension est en dessous du seuil
     digitalWrite(baseTRANSISTOR, HIGH);
     Serial.println("Relai alimenté");
  }
  
  // On a gardé l'impression de certaines valeurs pour s'assurer que tout est en ordre
  Serial.print( "La valeur à l'entrée A1 (photorésistance) est de: " );
  Serial.println( analogRead(brochePHOTO) );
  
  valeurVbe = analogRead( brocheVbe );
  valeurVce = analogRead( brocheVce );

  Serial.print( "Les tensions Vbe et Vce: " );
  Serial.print( valeurVbe / 1023.0 * 5.0 );
  Serial.print( "V / " );
  Serial.print( valeurVce / 1023.0 * 5.0 );
  Serial.println( "V" );

  delay(1000);
}
