
/* Lab 3 - Étape 2 - Deux (2) boutons en rappel BAS */

int brocheDEL = 13;    // Variable pour la DEL

int entreeBOUTON1_ON = 2;
int etatBOUTON1_ON = 0;

int entreeBOUTON2_OFF = 4;
int etatBOUTON2_OFF = 0;
  
void setup()
{ 
  pinMode(brocheDEL, OUTPUT);        // Sortie pour la DEL
  pinMode(entreeBOUTON1_ON, INPUT);  // Entrée pour bouton 1. 
  pinMode(entreeBOUTON2_OFF, INPUT); // Entrée pour bouton 2. 
} 
  
void loop()
{ 
  // lecture des états des boutons
  etatBOUTON1_ON  = digitalRead(entreeBOUTON1_ON);
  etatBOUTON2_OFF = digitalRead(entreeBOUTON2_OFF);

  if (etatBOUTON1_ON == HIGH)
    digitalWrite(brocheDEL, HIGH); // Allume la DEL  
  else if (etatBOUTON2_OFF == HIGH)
    digitalWrite(brocheDEL, LOW);  // Éteint la DEL  
 
  delay(33); // on règle la fréquence de la boucle à environ 30Hz
}
