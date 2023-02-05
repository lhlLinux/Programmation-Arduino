// Étape 4

#include <Servo.h>

// Variables du potentiometre et la tension
int broCURSEUR = A3;
int potentiometre;
float tension = 0;

// Variables de la DEL
int broDEL_R = 12;
int broDEL_V = 8;
int broDEL_B = 7;

// Variables du servomoteur
int brocheSERVO = 10;
int pos = 0;
Servo myservo;

// Variables pour le choix
int choix = 0;
int lecture = 0;

void setup()
{
   // on initialise les broches de la DEL
   pinMode(broDEL_R, OUTPUT);
   pinMode(broDEL_V, OUTPUT);
   pinMode(broDEL_B, OUTPUT);
   Serial.begin(9600);
   myservo.attach(brocheSERVO); // on initialise le servomoteur
}


void loop() 
{
   // Lecture de la tension au curseur
   potentiometre = analogRead(broCURSEUR);
   tension = potentiometre/1023.0*5.0;

   Serial.print("tension: ");
   Serial.println(tension,3);

   // la lecture est faite seulement si une valeur est prête à être lue
   if (Serial.available())
   {
      lecture = Serial.parseInt();

      // Il semble que la valeur zéro signifie "aucune valeur" 
      // et est toujours lue. Alors on l'exclue tout simplement
      if (lecture != 0)
           choix = lecture;
   }

   // On détermine quoi faire en fonction du choix
   switch (choix)
   {
      case 1:
          // Pour ce cas, on éteint les DELS,
          // et on recalcule l'étalement de la valeur de lecture pour le moteur
          EtteindreDELS();
          pos = map(potentiometre,0,1023,45,135);
          myservo.write(pos);         
      break;

      case 2:
          // On allume la DEL correspondant à la tension
          // Le moteur est naturellement arrêté lorsqu'il ne reçoit de signaux
          AllumeDELS();
      break;

      default:
          // On éteint la DEL
          // Le moteur est naturellement arrêté lorsqu'il ne reçoit de signaux
          EtteindreDELS();
          // L'usager a fait un choix ivalide. Il est informé de la situation
          // et demeure en attente d'un nouvau choix
          Serial.println( "Votre choix n'est pas valide." );
          Serial.println( "Appuyer sur la touche 1 ou 2 pour faire votre choix." );
          while (Serial.available == 0) {;}
   }

   delay(250);                
}

void EtteindreDELS()
{
   digitalWrite(broDEL_R, LOW);                           // la DEL allume
   digitalWrite(broDEL_V, LOW);                           // la DEL allume
   digitalWrite(broDEL_B, LOW);
}

void AllumeDELS()
{
   // Une différente couleur allume en fonction de la tension
   if (tension > 3.0)
   {
      // La DEL Rouge allume
      digitalWrite(broDEL_B, LOW);
      digitalWrite(broDEL_V, LOW);
      digitalWrite(broDEL_R, HIGH);
      Serial.println( "La couleur est Rouge." );
   }
   else if (tension > 1.0)
   {
      // La DEL Bleue allume
      digitalWrite(broDEL_R, LOW);
      digitalWrite(broDEL_V, LOW);
      digitalWrite(broDEL_B, HIGH);
      Serial.println( "La couleur est Bleue." );
   }
   else //(tension <= 1.0) 
   {
      // La DEL Verte allume
      digitalWrite(broDEL_R, LOW);
      digitalWrite(broDEL_B, LOW);
      digitalWrite(broDEL_V, HIGH);
      Serial.println( "La couleur est Verte." );
   }
}
