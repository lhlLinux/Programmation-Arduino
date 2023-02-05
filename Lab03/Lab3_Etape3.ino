
/* Lab 3 - Étape 3 */

const int broche_DEL_Rouge = 10;
const int broche_DEL_Verte = 9;

void setup()
{
  pinMode( broche_DEL_Rouge, OUTPUT );
  pinMode( broche_DEL_Verte, OUTPUT );
}

// Simulation de la couleur par alternance du rouge et du vert à haute fréquence
void loop()
{
  digitalWrite( broche_DEL_Rouge, HIGH );
  delay(5); //delay(1000);
  digitalWrite( broche_DEL_Rouge, LOW );

  digitalWrite( broche_DEL_Verte, HIGH );
  delay(5); //delay(500);
  digitalWrite( broche_DEL_Verte, LOW );
}
