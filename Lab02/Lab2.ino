
////////////////// Étape 1 /////////////////////////////////////

// NOTE: toutes les étapes partagent le même montage de la fonction setup()

void setup()
{
    // initialisation des dix premières broches, en commençant par la deuxìème
    for (int i = 2; i < 12; i++)
    pinMode(i, OUTPUT);
}


void loop()
{
/*
    int PAUSE = 100;
    digitalWrite(2, HIGH);
    delay(PAUSE);
    digitalWrite(3, HIGH);
    delay(PAUSE);
    digitalWrite(4, HIGH);
    delay(PAUSE);
    digitalWrite(5, HIGH); 
    delay(PAUSE);
    digitalWrite(6, HIGH);
    delay(PAUSE);
    digitalWrite(7, HIGH);
    delay(PAUSE); 
    digitalWrite(8, HIGH);
    delay(PAUSE);
    digitalWrite(9, HIGH);
    delay(PAUSE);
    digitalWrite(10, HIGH);
    delay(PAUSE);
    digitalWrite(11, HIGH);
    delay(PAUSE);
   
    //Ce bloque d'instruction éteint les DEL
    digitalWrite(11, LOW);
    delay(PAUSE);
    digitalWrite(10, LOW);
    delay(PAUSE);
    digitalWrite(9, LOW);
    delay(PAUSE);                    
    digitalWrite(8, LOW);
    delay(PAUSE);                    
    digitalWrite(7, LOW);
    delay(PAUSE);                    
    digitalWrite(6, LOW);
    delay(PAUSE);                    
    digitalWrite(5, LOW);
    delay(PAUSE);                    
    digitalWrite(4, LOW);
    delay(PAUSE);
    digitalWrite(3, LOW);
    delay(PAUSE);                    
    digitalWrite(2, LOW);
    delay(PAUSE);   

    */

    ////////////////// Étape 2 /////////////////////////////////////

    /*
    //  Début du programme SECTION 2.
    int delayTime = 100;   // Délai entre action des DEL
  
    //Ce bloque d'instructions allume les 8 DEL. Effet chenillard.  
    for (int i = 2; i < 12; i++) { // Allume une DEL après l'autre en débutant par la DEL à la broche 2.
        digitalWrite(i, HIGH);    //  allume DEL i
        delay(delayTime);          // Délai entre chaque action pour allumer une DEL
    }                                         // On boucle 8 fois pour 8 DEL.
    
    //Ce bloque d'instruction pour éteindre les 8 DEL. On éteint en premier la DEL de la broche 9.
    for (int i = 11; i > 1; i--){  // Le bloc est exécuté 8 fois. On décrémente de 1 à chaque passage.
        digitalWrite(i, LOW);  
        delay(delayTime);         // Délai entre chaque action
    }
    */

    ////////////////// Étape 3 /////////////////////////////////////

    /*
    //Début programme SECTION 3
    int temps = 100; //Délai entre chaque action des DEL.
    for (int i = 2; i < 12; i++)
    {
      int precedent = i - 1;  // La DEL éteinte est une position de moins que celle pointé par i.
      if(i == 2)
      {         
        precedent = 11;        // Si i=2 on initialise la variable DELoff (valeur du dernier DEL).
      }              
      digitalWrite(i, HIGH);     // Allume la DEL qui est pointé par i
      digitalWrite(precedent, LOW); // Éteint la DEL qui est pointé par DELoff
      delay(temps);                      
    }
    */

    ////////////////// Étape 4 /////////////////////////////////////
    
    int delayTime = 100;   // Délai entre action des DEL
  
    //Ce bloque d'instructions allume les 10 DEL. Effet chenillard.  
    int i = 2;
    while (i < 12) // on répète 10 fois
    {
        // Allume une DEL après l'autre en débutant par la DEL à la broche 2.
        digitalWrite(i, HIGH);     //  allume DEL i
        delay(delayTime);          // Délai entre chaque action pour allumer une DEL
        i++;
    }
    
    //Ce bloque d'instruction pour éteindre les 8 DEL. On éteint en premier la DEL de la broche 9.
    i = 11; // on reinitialise la variable i

    while (i > 1)
    {
      // Le bloc est exécuté 8 fois. On décrémente de 1 à chaque passage.
        digitalWrite(i, LOW);  
        delay(delayTime);         // Délai entre chaque action
        i--;
    }
} // Fin de la fonction loop()
