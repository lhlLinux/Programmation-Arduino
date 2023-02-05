
// Étape 1

int brochePHOTO = A0;  // Entrée analogue pour brancher la photorésistance 
int brocheDEL   = 6;   // La broche de la DEL, qui contrôle la luminosité en PWM       
int forceLUMIERE;      // Variable pour l'intensité de lumière
 
void setup()
{
  pinMode(brocheDEL, OUTPUT);  // Sortie pour la DEL
  Serial.begin(9600);          // Établir la communication.
}

int intensite = 0;
int DEL = 0;

void loop()
{
  forceLUMIERE = analogRead(brochePHOTO);

  //On affiche la valeur à la broche avant modification
  Serial.print( "Force lumière :  ");
  Serial.println( forceLUMIERE, DEC );
  
  //DEL = map(forceLUMIERE, 0, 900, 0, 255);
  // Notre adaptation en fonction de nos valeurs
  DEL = map( forceLUMIERE, 64, 911, 0, 255 );
  intensite = constrain( DEL, 0, 255 );

  // On envoie le courant à la broche
  analogWrite( brocheDEL, intensite );
  
  delay(500); // pour pouvoir lire les valeurs
}
