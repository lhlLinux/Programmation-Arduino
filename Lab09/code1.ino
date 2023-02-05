// Étape 1

int broCURSEUR = A3;  // Broche pour le curseur du potentiomètre 
int broDEL = 6;       // Broche pour la DEL
int potentiometre;    // Variable de lecture de la valeur du potentiomètre

void setup()
{
   pinMode(broDEL, OUTPUT);
   Serial.begin(9600);
}

void loop()
{
   potentiometre = analogRead(broCURSEUR);
   Serial.print("tension: ");
   Serial.println(potentiometre/1023.0*5.0);
   
   digitalWrite(broDEL, HIGH);
   delay(potentiometre);
   digitalWrite(broDEL, LOW);
   delay(potentiometre);  
   // notre ajout pour assurer une lecture agréable lorsque la valeur
   // de la variable 'potentiometre' est inférieure à 250                
   delay(250);
}
