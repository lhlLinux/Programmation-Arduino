// Étape 3

// Variables pour le potentiometre et la tension
int broCURSEUR = A3;
int potentiometre;
float tension = 0;

// Vatiables pour la DEL RGB
int broDEL_R = 12;
int broDEL_V = 8;
int broDEL_B = 7;

void setup()
{
   // Initialisation des broches de la DEL RGB
   pinMode(broDEL_R, OUTPUT);
   pinMode(broDEL_V, OUTPUT);
   pinMode(broDEL_B, OUTPUT);
   Serial.begin(9600);
}

void loop()
{
   potentiometre = analogRead(broCURSEUR);
   tension = potentiometre/1023.0*5.0;

   Serial.print( "La tension est: " );
   Serial.print( tension,3 );

   // Une différente couleur allume en fonction de la tension
   if (tension > 3.0)
   {
      // La DEL Rouge allume
      digitalWrite(broDEL_B, LOW);
      digitalWrite(broDEL_V, LOW);
      digitalWrite(broDEL_R, HIGH);
      Serial.println( " et la couleur est Rouge." );
   }
   else if (tension > 1.0)
   {
      // La DEL Bleue allume
      digitalWrite(broDEL_R, LOW);
      digitalWrite(broDEL_V, LOW);
      digitalWrite(broDEL_B, HIGH);
      Serial.println( " et la couleur est Bleue." );
   }
   else //(tension <= 1.0) 
   {
      // La DEL Verte allume
      digitalWrite(broDEL_R, LOW);
      digitalWrite(broDEL_B, LOW);
      digitalWrite(broDEL_V, HIGH);
      Serial.println( " et la couleur est Verte." );
   }

   // on attends 1 secondes pour bien lire la tension
   // pour avoir le temps de bien vérifier la couleur
   delay(1000);
}
