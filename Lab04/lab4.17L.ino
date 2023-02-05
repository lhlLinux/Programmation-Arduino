

int  brocheBOUTON_ON = 4; 
int  etatBOUTON_ON = 0;
bool employeBOUTON_ON = false;

int  brocheBOUTON_OFF = 7; 
int  etatBOUTON_OFF = 0;
bool employeBOUTON_OFF = true;

void setup()
{
   pinMode(9, OUTPUT);
   pinMode(brocheBOUTON_ON, INPUT);
   pinMode(brocheBOUTON_OFF, INPUT);
}


void loop()
{
   
  etatBOUTON_ON  = digitalRead(brocheBOUTON_ON);
  etatBOUTON_OFF = digitalRead(brocheBOUTON_OFF);

  // Implémentation d'exclusion mutuelle
  if ((etatBOUTON_ON == HIGH) && (employeBOUTON_ON == false)) // bouton_ON appuyé
  {
    // bouton OFF a très bien pu être appuyé également mais on l'ignore 
    delay(200);
    digitalWrite(9,HIGH);
    employeBOUTON_ON = true;
    employeBOUTON_OFF = false;
  }
  else if((etatBOUTON_OFF == HIGH) && (employeBOUTON_OFF == false)) // bouton_OFF appuyé
  {
    // bouton ON a très bien pu être appuyé également mais on l'ignore 
    delay(200);
    digitalWrite(9,LOW);
    employeBOUTON_ON = false;
    employeBOUTON_OFF = true;

  }

  delay( 33 ); // Les boutons sont lus à une fréquence de 30Hz
}
   
