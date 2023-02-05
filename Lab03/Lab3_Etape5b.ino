
//Dans cet exemple le bouton1 allume la DEL et le bouton2 éteint la DEL.

int brocheDEL = 13;    // Variable pour la DEL

int  entreeBOUTON1_ON = 2;
bool emploiBOUTON1_ON = false;

int  entreeBOUTON2_OFF = 3;
bool emploiBOUTON1_OFF = false;

  
void setup()
{ 
  pinMode(brocheDEL, OUTPUT); // Sortie pour la DEL
  pinMode(entreeBOUTON1, INPUT); // Entrée pour bouton 1. 
  pinMode(entreeBOUTON2, INPUT); // Entrée pour bouton 2. 
} 
  
void loop()
{ 
  if (digitalRead(entreeBOUTON1) == LOW) // non appuyé
  { // Bouton 1 
    delay(200);
    digitalWrite(brocheDEL, LOW); // Éteint la DEL  
  }
  else
  {
    if (digitalRead(entreeBOUTON2) == LOW) // non appuyé
    { // Bouton 2
      delay(200);
      digitalWrite(brocheDEL, HIGH); // allume la DEL 
    }
    
    digitalWrite(brocheDEL, HIGH); // allume la DEL
  }
 
}
