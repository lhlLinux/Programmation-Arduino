/********************************************************************
 * Programme d�velopp� dans le cadre du projet de classe
 * No Projet: 6
 * Classe: 243-289-AH     Enseignant:
 * Groupe:                �quipe: Linus Levi
 * Date: 01-Juin-2022
 ********************************************************************/

// Broches des �l�ments employ�s
const int brocheBouton = 13;
const int brocheAlarme = 7;
const int brocheDEL_V = 8;
const int brocheDEL_R = 5;
const int brocheDEL_J = 2;

// Variables pour traitement du mot de passe
const int LONGUEUR_MAX = 10;         // la limite de la m�moire tempon (buffer) pour la cha�ne
char      lecture = 0;               // caract�re lu par Serial.read()
int       longueurMot = 0;           // compteur de la longueur du mot
char      mot[ LONGUEUR_MAX + 1 ] ;  // plus une entr�e de plus pour le caract�re NULL (fin de cha�ne)

// Variables d'�tat
bool      alarme;
bool      codeEntre;
bool      etatArme;

//---------------------------------------------------------
// Description: efface la m�moire tempon du mot de passe
// Retourne: rien
//---------------------------------------------------------
void InitialiseMot()
{
  for (int i = 0; i < LONGUEUR_MAX + 1; i++)
    mot[i] = 0;
  longueurMot = 0;
}

//-----------------------------------------------------------
// Description: Initialise les variables du syst�me d'alarme
//              � tout moment pour pouvoir recommencer.
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
  
  Serial.println("Syst�me pr�t");
}


//---------------------------------------------------------
// Description: compare la cha�ne re�ue par argument
//              � ce qui se trouve dans la m�moire tempon.
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
//              en son enti�rt�
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

  InitialiseSysteme();   // On initialise le syst�me d'alarme
}


//---------------------------------------------------------
// Description: lit le bouton et �tablit l'�tat d'alarme
// Retourne: rien
//---------------------------------------------------------
void TraiteBouton()
{
  // Le bouton est mont� en rappel haut
  // donc appuyer le bouton �quivaut � LOW
  if (digitalRead( brocheBouton ) == LOW)
  {
    // on se touve ici parce que le bouton a �t� appuy�
    if (!alarme) // // l'alarme est �tablie seulement s'il n'y a pas d'alarme
    {
      alarme = true;
      digitalWrite( brocheAlarme, HIGH );
      digitalWrite( brocheDEL_J, HIGH );
    }
    /* 
     *  ces lignes de code on �t� employ�es pour le d�pannage
     *  comme m�thode pratique et gr�cieuse d'interrompre l'alarme
     *  au cas o� le mot de passe ne fonctionnerai pas
    else
     {
      alarme = false;
      digitalWrite( brocheAlarme, LOW );
      digitalWrite( brocheDEL_J, LOW );
    }
    */
    delay(125); // un bref d�lai apr�s la lecture du bouton
    // n�c�essaire lorsque le code en commentaire ci-dessus
    // �tait actif, mais �a ne fait pas mal de le garder.
  }
}


////////////////////////////////////////////////////////////
// Description: Fonction souche qui constitue la boucle
//              principale du programme.
// Retourne: rien
////////////////////////////////////////////////////////////
void loop()
{
  if (etatArme) // en �tat arm� on fait les �tapes suivantes
  {
     TraiteBouton(); // on lit le bouton

     // s'il y a une alarme et le code a �t� entr� on retourne au mode veille (toujours arm�)
     if (alarme && codeEntre)
     {
        // alors on d�sarme
        digitalWrite( brocheAlarme, LOW );
        digitalWrite( brocheDEL_J, LOW );
        codeEntre = false;
        alarme = false;
     }
  }

  // Ici se trouve le traitement du mot de passe entr� au clavier
  if (Serial.available())
  {
    lecture = Serial.read(); // on lit un caract�re ...

    /*
    ... et on filtre ceux n'�tant pas valides.
    On aurait put filtrer d'avantage, soit manuellement
    ou avec les fonctions isDigit(), isAlphaNumeric(), etc...
    mais on l'a gard� simple.
    
    Ce filtre est n�cessaire lorsqu'on doit traiter une cha�ne
    tel un mot de passe car en faisant des tests, on a remarqu�
    qu'un alin�a ( le caract�re NL, "New Line" de valeur 10) est
    ins�r� apr�s chaque caract�re d'un mot entr� au clavier,
    il faut alors l'exclure.
    */ 
    if (lecture > 32)
    {
      // La cha�ne du mot de passe est b�tie
      // Ici on peut voir que la variable longueurMot est utilis�e
      // pour garder l'�vidence de la cha�ne compos�e que des caract�res valides
      if (longueurMot < LONGUEUR_MAX)
        mot[longueurMot] = lecture;
      longueurMot++;
    }
  }
  else
  {
    /* on est ici parce qu'il n'y a pas de valuer � la console, 
     * possiblement parce qu'on a lu tous les caract�res d'une cha�ne
     * pr�c�demment entr�e; c'est ce cas qui nous interesse
     */
    
    // si une cha�ne a �t� entr�e (longeur du mot > 0)
    if (longueurMot > 0)
    {
      // on finit la cha�ne avec un NULL (on marque explicitement sa fin)
      mot[longueurMot] = 0; 

      if (alarme)
      {
        // s'il y a une alarme alors un des deux mots de passe peuvent la d�sactiver
        if (compareMot( "linus" ) || compareMot( "lihua" ))
        {
          // on confirme � l'�cran, et on �tablit l'�tat correspondant
          Serial.println( "le code est bon" );
          codeEntre = true;
        }
        else
          Serial.println( "Le code ne correspond pas. Essayez � nouveau:");
      }      
      // s'il n'y a pas d'alarme alors on test pour l'autre
      else if (compareMot( "lihua" ))
      {
        // d�pendamment de l'�tat d�j� en vigueur (arm� ou non)
        // l'entr�ee du mot de passe soit d�sarme ou arme le syst�me
        if (etatArme)
        {
          // Le changement de mode est confirm� � l'�cran ainsi que par les DELS
          Serial.println( "Le syst�me est d�sarm�" );
          etatArme = false; // l'�tat refl�te la situation
          digitalWrite( brocheDEL_V, LOW );
          digitalWrite( brocheDEL_R, HIGH );
        }
        else
        {
          // Le changement de mode est confirm� � l'�cran ainsi que par les DELS
          Serial.println( "Le syst�me est arm�" );
          etatArme = true; // l'�tat refl�te la situation
          digitalWrite( brocheDEL_V, HIGH );
          digitalWrite( brocheDEL_R, LOW );
        }
      }
      else
        Serial.println( "Le code ne correspond pas. Essayez � nouveau:");

      /*
      Puisque c'est la fin d'une cha�ne on doit r�initialiser
      la m�moire tempon pour faire place � la cha�ne suivante
      */
      InitialiseMot();
    } // fin de "if"
  }

  delay(33); // On �tablit la fr�quence d'execution de 30Hz ce qui est amplement suffisant

} // fin de "void loop()"

// ---------------------------------- Fin du Programme ------------------------------------