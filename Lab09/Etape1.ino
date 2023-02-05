int brocheCURSEUR = A0;    // Broche pour le curseur du potentiomètre 
int brocheDEL = 13;               // Broche pour la DEL
int potentiometre;              // Variable lecture entrée analogique A0 (curseur du potentiomètre)

void setup()
{
   pinMode(brocheDEL, OUTPUT);   // déclare la brocheDEL comme une sortie 
}

// Le clignotement du DEL est proportionnel à la tension au curseur du potentiomètre.
void loop()
{
   potentiometre = analogRead(brocheCURSEUR);   // Lecture de la tension au curseur
   digitalWrite(brocheDEL, HIGH);                           // la DEL allume
   delay(potentiometre);                          // délai variable en fonction de la position du curseur 
   digitalWrite(brocheDEL, LOW);             // La DEL éteint
   delay(potentiometre);                  
}
