/*
 * 
 * Laboratoire 4 - Étape 6
 * 
 */

int brocheMOTEUR = 9;

 // bouton 1 en rappel haut (met le moteur en marche)
int entreeBOUTON1_MARCHE = 2;
int etatBOUTON1_MARCHE = 0;

 // bouton 2 en rappel bas (arrête le moteur)
int entreeBOUTON2_ARRETE = 4;
int etatBOUTON2_ARRETE = 0;

void setup() 
{
   pinMode(brocheMOTEUR, OUTPUT); // Moteur branché à cette broche, via la base du transistor.
   pinMode(entreeBOUTON1_MARCHE, INPUT); // Entrée pour bouton 1. 
   pinMode(entreeBOUTON2_ARRETE, INPUT); // Entrée pour bouton 2. 
}

void loop() 
{
  // lecture des états des boutons
  etatBOUTON1_MARCHE = digitalRead(entreeBOUTON1_MARCHE);
  etatBOUTON2_ARRETE = digitalRead(entreeBOUTON2_ARRETE);

  // ATTENTION: BOUTON1 est en rappel HAUT et BOUTON2 est en rappel BAS
  if (etatBOUTON1_MARCHE == LOW) // Bouton est appuyé (rappel HAUT)
    digitalWrite(brocheMOTEUR, HIGH); // Démarre le moteur
  else if (etatBOUTON2_ARRETE == HIGH) // bouton est appuyé (rappel BAS)
    digitalWrite(brocheMOTEUR, LOW);  // Arrête le moteur

  delay(33); // on règle la fréquence de la boucle à environ 30Hz 
}
