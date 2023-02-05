

int tempsCOURT = 1000;
int tempsLONG  = 3000;

void setup() 
{ 
  // Un bloc instruction qui initialise les broches 
  // en sortie pour alimenter les 4 DEL
  pinMode(3,OUTPUT); // DEL rouge
  pinMode(5,OUTPUT); // DEL jaune
  pinMode(7,OUTPUT); // DEL verte
  pinMode(9,OUTPUT); // del rouge
}

void loop()   // Boucle du programme
{ 
   // Ce bloc allume les DEL
   digitalWrite(3, HIGH);  // La DEL à la broche 2 allume 
   delay(tempsCOURT);
   digitalWrite(5, HIGH);  // La DEL à la broche 3 allume 
   delay(tempsCOURT);               
   digitalWrite(7, HIGH);  // La DEL à la broche 7 allume 
   delay(tempsCOURT);               
   digitalWrite(9, HIGH);  // La DEL à la broche 8 allume 
   delay(tempsCOURT);

   // on change les valeurs des intervalles pour la prochaine étape
   tempsCOURT = 1500;
   tempsLONG  = 2000;

   // Ce bloc éteint les DEL
   digitalWrite(3, LOW);
   delay(tempsCOURT);
   digitalWrite(5, LOW);
   delay(tempsCOURT);               
   digitalWrite(7, LOW);
   delay(tempsCOURT);               
   digitalWrite(9, LOW);
   delay(tempsLONG);

   // on remet les valeurs originalespour l'étape 1
   tempsCOURT = 1000;
   tempsLONG  = 3000;
}
