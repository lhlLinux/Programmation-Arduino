
/*
 * Laboratoire 4 - Étapes 1, 2 et 3
 */
void setup() 
{
   pinMode(9, OUTPUT); // Moteur branché à cette broche, via la base du transistor.
}

void loop() 
{   
    // On choisit la fonction qu'on désire exécuter
    //moteurONmoteurOFF();
    //moteurTOURNE200moteurTOURNE50();
    moteurACCELERATION();
}

// Le moteur alterne entre une vitesse maximale et zéro « rpm »
void moteurONmoteurOFF()
{
  digitalWrite(9, HIGH); // Le moteur est à une vitesse maximale
  delay(2500);           // (5 volts sur la broche) pause 2,5 sec
  digitalWrite(9, LOW);  // Le moteur arrête.
  delay(1500);           // (0 volt sur la broche 9) pause 1.5 sec
}


// Alterne la vitesse du moteur entre les vitesse 200 et 50. 
void moteurTOURNE200moteurTOURNE50()
{
   analogWrite(9, 200);    // Le moteur tourne à une vitesse haute.
   delay(2500);            // 3.9 volts sur la broche 9. Pause 2500 ms
   analogWrite(9, 100);    // Le moteur tourne à une vitesse basse
   delay(2000);            // 1.96 volts sur la broche 9. Pause 2 sec.
}

// Alterne la vitesse entre une accélération et une décélération
void moteurACCELERATION()
{   
    // Bloc d'instructions pour accélération du moteur
    for(int i = 0; i < 256; i++)    // La vitesse varie de 0 à un maximum
    {
      analogWrite(9, i);            // La tension sur la broche 9 varie de 0.0 V. à 5.0 V.
      delay(100);                   // Pause entre chaque incrément de tension.
    }
    
    //Bloque d'instructions pour la décélération du moteur
    for(int i = 255; i >= 0; i--)   // 255 est le maximum et 0 est le minimum
    {   
      analogWrite(9, i);            // Initialise la nouvelle vitesse.
      delay(100);                   // Délai entre chaque vitesse
    }
}
