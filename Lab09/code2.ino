int broCURSEUR = A3;    // Broche pour le curseur du potentiomètre 

int broDEL_R = 6;               // Broche pour la DEL
int broDEL_V = 8;
int potentiometre;              // Variable lecture entrée analogique A0 (curseur du potentiomètre)
float tension = 0;

void setup() {
   pinMode(broDEL_R, OUTPUT);   // déclare la broDEL_R comme une sortie 
   pinMode(broDEL_V, OUTPUT);   // déclare la broDEL_R comme une sortie 
   Serial.begin(9600);
}

// Le clignotement du DEL est proportionnel à la tension au curseur du potentiomètre.
void loop() {
   potentiometre = analogRead(broCURSEUR);   // Lecture de la tension au curseur

   tension = potentiometre/1023.0*5.0;

   Serial.print("tension: ");
   Serial.println(tension,3);

   if (tension > 3.2)
   {
      digitalWrite(broDEL_V, LOW);
      digitalWrite(broDEL_R, HIGH);
      delay(potentiometre);
      digitalWrite(broDEL_R, LOW);
   }
   else
   {
      digitalWrite(broDEL_R, LOW);
      digitalWrite(broDEL_V, HIGH);
      delay(potentiometre);
      digitalWrite(broDEL_V, LOW);
    }

   delay(potentiometre);  
   delay(250);                
}
