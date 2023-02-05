
/* Laboratoire 3 - étape 4 - Deux (2) boutons en rappel BAS */

int brocheDELverte = 9;     // Variable pour la DEL verte
int brocheDELrouge = 10;    // Variable pour la DEL rouge

int brocheBOUTON_DELverte = 2;
int etatBOUTON_DELverte = 0;

int brocheBOUTON_DELrouge = 4;
int etatBOUTON_DELrouge = 0;
  
void setup()
{ 
  pinMode(brocheDELverte, OUTPUT);        // Sortie pour la DEL
  pinMode(brocheBOUTON_DELverte, INPUT);  // Entrée pour bouton 1. 
  
  pinMode(brocheDELrouge, OUTPUT);        // Sortie pour la DEL
  pinMode(brocheBOUTON_DELrouge, INPUT);  // Entrée pour bouton 2.
} 
  
void loop()
{ 
  // lecture des états des boutons
  etatBOUTON_DELverte = digitalRead(brocheBOUTON_DELverte);
  etatBOUTON_DELrouge = digitalRead(brocheBOUTON_DELrouge);

  if (etatBOUTON_DELverte == HIGH)
  {
      digitalWrite(brocheDELrouge, LOW);
      digitalWrite(brocheDELverte, HIGH);
  }
  else if (etatBOUTON_DELrouge == HIGH)  
  {
      digitalWrite(brocheDELverte, LOW);
      digitalWrite(brocheDELrouge, HIGH);
  }

  delay(33); // on règle la fréquence de la boucle à environ 30Hz
}
