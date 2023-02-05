

int tempsCOURT = 1000;
int tempsLONG  = 2200;

void setup() 
{ 
  // Un bloc instruction qui initialise les broches 
  // en sortie pour alimenter les 4 DEL
  pinMode(4,OUTPUT); // DEL rouge
  pinMode(7,OUTPUT); // DEL jaune
  pinMode(10,OUTPUT); // DEL verte
}

void loop()   // Boucle du programme
{ 
   // Ce bloc allume les DEL
   digitalWrite(4, HIGH);  // La DEL à la broche 3 allume 
   delay(tempsCOURT);               
   digitalWrite(7, HIGH);  // La DEL à la broche 7 allume 
   delay(tempsCOURT);               
   digitalWrite(10, HIGH);  // La DEL à la broche 8 allume 
   delay(tempsCOURT);

   // on change les valeurs des intervalles pour la prochaine étape
   // tempsCOURT = 1500;
   tempsLONG  = 2000;

   // Ce bloc éteint les DEL (les trois s'étaignent en même temps)
   digitalWrite(4, LOW);
   //delay(tempsCOURT);               
   digitalWrite(7, LOW);
   //delay(tempsCOURT);               
   digitalWrite(10, LOW);
   delay(tempsLONG);

   // on remet les valeurs originalespour l'étape 1
   tempsCOURT = 1000;
   tempsLONG  = 3000;
}
