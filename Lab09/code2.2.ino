//Étape 2

int broCURSEUR = A3;

int broDEL_R = 6;               // Broche pour la DEL
int broDEL_V = 8;

int potentiometre;              // Variable lecture entrée analogique A0 (curseur du potentiomètre)
float tension = 0;

void setup()
{
   pinMode(broDEL_R, OUTPUT);   // déclare la broDEL_R comme une sortie 
   pinMode(broDEL_V, OUTPUT);   // déclare la broDEL_R comme une sortie 
   Serial.begin(9600);
}

void loop()
{
   // Lecture du curseur et calcul de la tension
   potentiometre = analogRead(broCURSEUR);
   tension = potentiometre/1023.0 * 5.0

   Serial.print("tension: ");
   Serial.println(tension);

   delay(potentiometre);

   // condition qui détérmine quelle DEL allume
   if (tension > 3.2)
   {
      digitalWrite(broDEL_V, LOW);
      digitalWrite(broDEL_R, HIGH);
   }
   else
   {
      digitalWrite(broDEL_R, LOW);
      digitalWrite(broDEL_V, HIGH);
   }
   
   delay(potentiometre);  
   // on assure une lecture agréable
   // lorsque la valeur de 'potentiometre' est très petite
   delay(250);
}
