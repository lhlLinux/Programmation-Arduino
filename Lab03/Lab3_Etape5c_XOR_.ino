
/*
 * Dans cet exemple le bouton1 allume la DEL et le bouton2 éteint la DEL.
 * Note: Montage des boutons en Rappel Haut, donc état naturel == HIGH
 */

int brocheDEL = 13;    // Variable pour la DEL

int entreeBOUTON1_ON = 2;
int etatBOUTON1_ON = 0;

int entreeBOUTON2_OFF = 4;
int etatBOUTON2_OFF = 0;

  
void setup()
{ 
  pinMode(brocheDEL, OUTPUT); // Sortie pour la DEL
  pinMode(entreeBOUTON1_ON, INPUT); // Entrée pour bouton 1. 
  pinMode(entreeBOUTON2_OFF, INPUT); // Entrée pour bouton 2. 
} 
  
void loop()
{ 
  // lecture des états des boutons
  etatBOUTON1_ON  = digitalRead(entreeBOUTON1_ON);
  etatBOUTON2_OFF = digitalRead(entreeBOUTON2_OFF);

  // Ici on s'assure d'exclusion mutuelle, comme ceci
  // Si les deux boutons sonts appuyés en même temps, rien ne se passe
  // Autrement on inspecte les deux, un après l'autre
  // L'algorithme fonctionne à merveille
  
  //                           *** ATTENTION *** 
  // pour que le XOR fonctionne, les DEUX boutons doivent être montés en rappel BAS
  // Donc ici, en rappel HAUT, le XOR ne foncionnera pas
  //                           *** ATTENTION *** 
  
  if (!((etatBOUTON1_ON == LOW) && (etatBOUTON2_OFF == LOW)))
  {
    // Si on se trouve ici, cela veut dire nécessairement que c'est peut être 
    // l'un ou l'autre bouton qui est appuyé, mai pas les deux en même temps
    if (etatBOUTON1_ON == LOW) // bouton1 appuyé
      digitalWrite(brocheDEL, HIGH); // Éteint la DEL  
    
    if (etatBOUTON2_OFF == LOW) // bouton1 appuyé
      digitalWrite(brocheDEL, LOW); // Éteint la DEL  
  } // fin du bloc if le plus élevé
 
  delay(33); // on règle la fréquence de la boucle à environ 30Hz
  
}
