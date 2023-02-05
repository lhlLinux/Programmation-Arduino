
/* Laboratoire 3 - Étape 5 */

const int broche_DEL_Rouge = 10;
const int broche_DEL_Verte = 9;

void setup()
{
  pinMode( broche_DEL_Rouge, OUTPUT );     // Sortie pour la DEL      
  pinMode( broche_DEL_Verte, OUTPUT );     // Sortie pour la DEL 
}

// Lecture du bouton, pour le test utilisé par l'instruction if. 
// Ajustez la valeur du test if à une condition vrai pour un bouton pressé.
void loop()
{
  digitalWrite( broche_DEL_Rouge, HIGH );
  delay(5); //delay(1000);
  digitalWrite( broche_DEL_Rouge, LOW );

  digitalWrite( broche_DEL_Verte, HIGH );
  delay(5); //delay(500);
  digitalWrite( broche_DEL_Verte, LOW );

}
