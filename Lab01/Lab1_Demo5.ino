

void setup() // Initialisation de la broche 13 en sortie.
{
    pinMode(13, OUTPUT);
}

void loop()
{
  // Clignotement de la DEL à la broche 13
  for (int i = 0; i < 5; i++)
  {
     digitalWrite(13, HIGH);  // La DEL à la broche 3 allume 
     delay(1000);   // Pause de 1 sec.
     digitalWrite(13, LOW);  // La DEL à la broche 3 éteint 
     delay(1000); // Pause de 1 sec.
  } // Fin For loop
  delay(5000);   //Pause de 5 sec. et le cycle recommence.
} // Fin Void Loop
