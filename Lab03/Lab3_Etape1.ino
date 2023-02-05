
/* 
 *  Lab 3 - Étape 1 
 *  Bouton monté en rappel bas
 *  Note: la variable "etatBOUTON" figurant dans le programme original
 *  a été enlevée car dans ce programme spécifique, elle est redondante
*/

const int brocheBOUTON = 4;     // Broche en entrée pour la lecture du bouton poussoir.
const int brocheDEL    = 6;     // Broche en sortie pour la DEL

void setup()
{
  pinMode( brocheDEL, OUTPUT );     // Sortie pour la DEL      
  pinMode( brocheBOUTON, INPUT );   // Entrée pour le bouton poussoir.   
}

void loop()
{
  // Montage en rappel bas: dans ce montage l'état naturel du bouton est LOW
  if (digitalRead( brocheBOUTON ) == HIGH) // Bouton appuyé
    digitalWrite( brocheDEL, LOW );        // La DEL éteint.
  else // donc HIGH, correspondant au bouton appuyé
    digitalWrite( brocheDEL, HIGH );       // La DEL allume.

  delay(33); // la boucle est réglée à 30Hz
}
