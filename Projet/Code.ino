/********************************************************************
 * Programme développé dans le cadre du projet de classe
 * No Projet: 6
 * Classe: 243-289-AH     Enseignant:
 * Groupe:                Équipe: Linus Levi
 * Date: 01-Juin-2022
 ********************************************************************/

// Broches des éléments employés
const int brocheBouton = 13;
const int brocheAlarme = 7;
const int brocheDEL_V = 8;
const int brocheDEL_R = 5;
const int brocheDEL_J = 2;

// Variables pour traitement du mot de passe
const int LONGUEUR_MAX = 10;         // la limite de la mémoire tempon (buffer) pour la chaîne
char      lecture = 0;               // caractère lu par Serial.read()
int       longueurMot = 0;           // compteur de la longueur du mot
char      mot[ LONGUEUR_MAX + 1 ] ;  // plus une entrée de plus pour le caractère NULL (fin de chaîne)

// Variables d'état
bool      alarme;
bool      codeEntre;
bool      etatArme;

//---------------------------------------------------------
// Description: efface la mémoire tempon du mot de passe
// Retourne: rien
//---------------------------------------------------------
void InitialiseMot()
{
  for (int i = 0; i < LONGUEUR_MAX + 1; i++)
    mot[i] = 0;
  longueurMot = 0;
}

//-----------------------------------------------------------
// Description: Initialise les variables du système d'alarme
//              à tout moment pour pouvoir recommencer.
// Retourne: rien
//-----------------------------------------------------------
void InitialiseSysteme()
{
  alarme = false;
  codeEntre = false;
  etatArme = false;
  
  InitialiseMot();
  
  digitalWrite( brocheAlarme, LOW );
  digitalWrite( brocheDEL_V, LOW );
  digitalWrite( brocheDEL_R, HIGH );
  digitalWrite( brocheDEL_J, LOW );
  
  Serial.println("Système prêt");
}


//---------------------------------------------------------
// Description: compare la chaîne reçue par argument
//              à ce qui se trouve dans la mémoire tempon.
// Retourne: vrai ou faux
//---------------------------------------------------------
bool compareMot( char* chaine )
{
  if (strcmp( mot, chaine ) == 0)
    return true;
  return false;
}


////////////////////////////////////////////////////////////
// Description: Fonction souche qui initialise le programme
//              en son entièrté
// Retourne: rien
////////////////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600); // On ouvre le port de communication
  while (!Serial) {;} // et on attends que la console deviens disponible

  pinMode( brocheBouton, INPUT );
  pinMode( brocheAlarme, OUTPUT );
  
  pinMode( brocheDEL_V, OUTPUT );
  pinMode( brocheDEL_R, OUTPUT );
  pinMode( brocheDEL_J, OUTPUT );

  InitialiseSysteme();   // On initialise le système d'alarme
}


//---------------------------------------------------------
// Description: lit le bouton et établit l'état d'alarme
// Retourne: rien
//---------------------------------------------------------
void TraiteBouton()
{
  // Le bouton est monté en rappel haut
  // donc appuyer le bouton équivaut à LOW
  if (digitalRead( brocheBouton ) == LOW)
  {
    // on se touve ici parce que le bouton a été appuyé
    if (!alarme) // // l'alarme est établie seulement s'il n'y a pas d'alarme
    {
      alarme = true;
      digitalWrite( brocheAlarme, HIGH );
      digitalWrite( brocheDEL_J, HIGH );
    }
    /* 
     *  ces lignes de code on été employées pour le dépannage
     *  comme méthode pratique et grâcieuse d'interrompre l'alarme
     *  au cas où le mot de passe ne fonctionnerai pas
    else
     {
      alarme = false;
      digitalWrite( brocheAlarme, LOW );
      digitalWrite( brocheDEL_J, LOW );
    }
    */
    delay(125); // un bref délai après la lecture du bouton
    // nécéessaire lorsque le code en commentaire ci-dessus
    // était actif, mais ça ne fait pas mal de le garder.
  }
}


////////////////////////////////////////////////////////////
// Description: Fonction souche qui constitue la boucle
//              principale du programme.
// Retourne: rien
////////////////////////////////////////////////////////////
void loop()
{
  if (etatArme) // en état armé on fait les étapes suivantes
  {
     TraiteBouton(); // on lit le bouton

     // s'il y a une alarme et le code a été entré on retourne au mode veille (toujours armé)
     if (alarme && codeEntre)
     {
        // alors on désarme
        digitalWrite( brocheAlarme, LOW );
        digitalWrite( brocheDEL_J, LOW );
        codeEntre = false;
        alarme = false;
     }
  }

  // Ici se trouve le traitement du mot de passe entré au clavier
  if (Serial.available())
  {
    lecture = Serial.read(); // on lit un caractère ...

    /*
    ... et on filtre ceux n'étant pas valides.
    On aurait put filtrer d'avantage, soit manuellement
    ou avec les fonctions isDigit(), isAlphaNumeric(), etc...
    mais on l'a gardé simple.
    
    Ce filtre est nécessaire lorsqu'on doit traiter une chaîne
    tel un mot de passe car en faisant des tests, on a remarqué
    qu'un alinéa ( le caractère NL, "New Line" de valeur 10) est
    inséré après chaque caractère d'un mot entré au clavier,
    il faut alors l'exclure.
    */ 
    if (lecture > 32)
    {
      // La chaîne du mot de passe est bâtie
      // Ici on peut voir que la variable longueurMot est utilisée
      // pour garder l'évidence de la chaîne composée que des caractères valides
      if (longueurMot < LONGUEUR_MAX)
        mot[longueurMot] = lecture;
      longueurMot++;
    }
  }
  else
  {
    /* on est ici parce qu'il n'y a pas de valuer à la console, 
     * possiblement parce qu'on a lu tous les caractères d'une chaîne
     * précédemment entrée; c'est ce cas qui nous interesse
     */
    
    // si une chaîne a été entrée (longeur du mot > 0)
    if (longueurMot > 0)
    {
      // on finit la chaîne avec un NULL (on marque explicitement sa fin)
      mot[longueurMot] = 0; 

      if (alarme)
      {
        // s'il y a une alarme alors un des deux mots de passe peuvent la désactiver
        if (compareMot( "linus" ) || compareMot( "lihua" ))
        {
          // on confirme à l'écran, et on établit l'état correspondant
          Serial.println( "le code est bon" );
          codeEntre = true;
        }
        else
          Serial.println( "Le code ne correspond pas. Essayez à nouveau:");
      }      
      // s'il n'y a pas d'alarme alors on test pour l'autre
      else if (compareMot( "lihua" ))
      {
        // dépendamment de l'état déjà en vigueur (armé ou non)
        // l'entréee du mot de passe soit désarme ou arme le système
        if (etatArme)
        {
          // Le changement de mode est confirmé à l'écran ainsi que par les DELS
          Serial.println( "Le système est désarmé" );
          etatArme = false; // l'état reflète la situation
          digitalWrite( brocheDEL_V, LOW );
          digitalWrite( brocheDEL_R, HIGH );
        }
        else
        {
          // Le changement de mode est confirmé à l'écran ainsi que par les DELS
          Serial.println( "Le système est armé" );
          etatArme = true; // l'état reflète la situation
          digitalWrite( brocheDEL_V, HIGH );
          digitalWrite( brocheDEL_R, LOW );
        }
      }
      else
        Serial.println( "Le code ne correspond pas. Essayez à nouveau:");

      /*
      Puisque c'est la fin d'une chaîne on doit réinitialiser
      la mémoire tempon pour faire place à la chaîne suivante
      */
      InitialiseMot();
    } // fin de "if"
  }

  delay(33); // On établit la fréquence d'execution de 30Hz ce qui est amplement suffisant

} // fin de "void loop()"

// ---------------------------------- Fin du Programme ------------------------------------