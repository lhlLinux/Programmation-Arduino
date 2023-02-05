int brocheBOUTON_ON = 4; 
int brocheBOUTON_OFF = 7; 
int etatBOUTON_ON = 0;
int etatBOUTON_OFF = 0;
 
void setup() {
   pinMode(9, OUTPUT); //
   pinMode(brocheBOUTON_ON, INPUT);
   pinMode(brocheBOUTON_OFF, INPUT);
}

void loop()
{
   
  etatBOUTON_ON  = digitalRead(brocheBOUTON_ON);
  etatBOUTON_OFF = digitalRead(brocheBOUTON_OFF);

  // Implémentation d'exclusion mutuelle
  if (etatBOUTON_ON == HIGH) // bouton2 appuyé
  {
    // bouton OFF a très bien pu être appuyé également mais on l'ignore 
    delay(200);
    digitalWrite(9,HIGH);
  }
  else if(etatBOUTON_OFF == HIGH) // bouton2 appuyé
  {
    // bouton ON a très bien pu être appuyé également mais on l'ignore 
    delay(200);
    digitalWrite(9,LOW);
  }

  delay( 33 ); // Les boutons sont lus à une fréquence de 30Hz
}
   
