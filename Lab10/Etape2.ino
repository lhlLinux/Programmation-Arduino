
// Étape 2

// Broches du transistor
int baseTRANSISTOR =  2;
int brocheVbe = A5;
int brocheVce = A3;

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
  digitalWrite(baseTRANSISTOR, HIGH); // la DEL sur le contact NO allume
  
  valeurVbe = analogRead( brocheVbe );
  valeurVce = analogRead( brocheVce );

  Serial.print( "Les tensions Vbe et Vce lorsque alimenté: " );
  Serial.print( valeurVbe / 1023.0 * 5.0 );
  Serial.print( "V / " );
  Serial.print( valeurVce / 1023.0 * 5.0 );
  Serial.println( "V" );
  
  // La DEL sur le contact NC éteint
  delay(2000);

  digitalWrite(baseTRANSISTOR, LOW); // la DEL sur le contact NC allume

  valeurVbe = analogRead( brocheVbe );
  valeurVce = analogRead( brocheVce );
  
  Serial.print( "Les tensions Vbe et Vce lorsque non-alimenté: " );
  Serial.print( valeurVbe / 1023.0 * 5.0 );
  Serial.print( "V / " );
  Serial.print( valeurVce / 1023.0 * 5.0 );
  Serial.println( "V" );

  delay(2000);                  // délai pour le clignotement
}
