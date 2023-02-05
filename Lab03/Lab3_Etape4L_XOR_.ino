
/*
 * Dans cet exemple le bouton1 allume la DEL et le bouton2 éteint la DEL.
 * Note: Montage des boutons en Rappel Bas, donc état naturel == LOW
 */

int brocheDELverte = 9;    // Variable pour la DEL
int brocheDELrouge = 10;    // Variable pour la DEL

int brocheBOUTON_DELverte = 2;
int etatBOUTON_DELverte = 0;

int brocheBOUTON_DELrouge = 4;
int etatBOUTON_DELrouge = 0;


  
void setup()
{ 
  pinMode(brocheDELverte, OUTPUT); // Sortie pour la DEL
  pinMode(brocheBOUTON_DELverte, INPUT); // Entrée pour bouton 1. 
  
  pinMode(brocheDELrouge, OUTPUT); // Sortie pour la DEL
  pinMode(brocheBOUTON_DELrouge, INPUT); // Entrée pour bouton 2.
} 
  
void loop()
{ 
  // lecture des états des boutons
  etatBOUTON_DELverte = digitalRead(brocheBOUTON_DELverte);
  etatBOUTON_DELrouge = digitalRead(brocheBOUTON_DELrouge);

  // Ici on s'assure de l'exclusion mutuelle, comme ceci
  // Si les deux boutons sont appuyés en même temps, rien ne se passe
  // Autrement on inspecte les deux, un après l'autre
  // L'algorithme fonctionne à merveille

  //                           *** ATTENTION *** 
  // pour que le XOR fonctionne, les DEUX boutons doivent être montés en rappel BAS
  // Donc ici, le XOR est une opération sensée
  //                           *** ATTENTION *** 

  if (etatBOUTON_DELverte ^ etatBOUTON_DELrouge)
  {
    // Si on se trouve ici, alors c'est peut être l'un ou l'autre
    // bouton qui est appuyé, mai pas les deux en même temps
    if (etatBOUTON_DELverte == HIGH)
    {
      digitalWrite(brocheDELrouge, LOW);
      digitalWrite(brocheDELverte, HIGH);
    }
    
    if (etatBOUTON_DELrouge == HIGH) // bouton1 appuyé
    {
      digitalWrite(brocheDELverte, LOW);
      digitalWrite(brocheDELrouge, HIGH);
    }
  } // fin du bloc if le plus élevé
 
  delay(33); // on règle la fréquence de la boucle à environ 30Hz
  
}
