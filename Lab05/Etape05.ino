// Étape 5

// Librairies utilisés :
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <Utility/Adafruit_MCP23017.h>

byte sourire[8]   = { B00000, B10001, B00000, B00000, B10001, B01110, B00000, };
byte triste[8]    = { B00000, B10001, B00000, B00100, B01010, B10001, B00000, };
byte ohm[8]       = { B01110, B10001, B10001, B10001, B10001, B01010, B11011, };
byte personnel[8] = { B00000, B01010, B00000, B00100, B00000, B01010, B00000, };

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

// Utilisé pour un afficheur RGB.
// Notre afficheur est NB
#define RED 0x1
#define GREEN 0x2

void setup() {  
  Serial.begin(9600);
  // Initialise le nombre de colonne et le nombre de lignes
  lcd.begin(16, 2);  // 16 colonnes et 2 lignes
  lcd.createChar(0, sourire);
  lcd.createChar(1, triste);
  lcd.createChar(2, ohm);
  lcd.createChar(3, personnel);
  lcd.write((uint8_t) 0);

  // Affiche le message pour un chronomètre
  int time = millis();
  lcd.print("Hello, world!");
  time = millis() - time;
  Serial.print("Took "); Serial.print(time); Serial.println(" ms");
  lcd.setBacklight(RED);
  lcd.setCursor(0, 1);

}

uint8_t i=0;
byte row = 1;
byte colO = 5;
byte colP = 5;

void loop()
{
  uint8_t buttons = lcd.readButtons();
  delay( 150 );

  if (buttons)
  {
    //lcd.clear();  // Efface la mémoire de l'afficheur.

    if (buttons & BUTTON_UP)
    {
      lcd.setCursor(6,1);
      lcd.print("                ");
      lcd.setBacklight(RED);
     }
     
    if (buttons & BUTTON_DOWN)
    {
      lcd.print ( "                ");
      lcd.setCursor(11,0);
      lcd.print("LINUS");
      lcd.setBacklight(RED);
    }

    // Ceci est le code pertinent pour l'étape 5
    if (buttons & BUTTON_LEFT)
    {  // le caractère se déplace vers la gauche
       // et apparapit de l'autre bord lorsque
       // on veut passer au délà de la limite.
       // Note: chaque caractère a sa propre variable pour la colonne,
       // autrement un affecte l'autre, ce qui est insensé.
       
       if (colP > 0)
          colP--;
       else
          colP = 15; 
          
       lcd.setCursor(0,1);
       lcd.print("                ");
       lcd.setCursor(colP,1);
       lcd.write(byte (3));
    }

    // Ceci est le code pertinent pour l'étape 5
    if (buttons & BUTTON_RIGHT)
    {  // le caractère se déplace vers la droite
       // et apparapit de l'autre bord lorsque
       // on veut passer au délà de la limite.
       // Note: chaque caractère a sa propre variable pour la colonne,
       // autrement un affecte l'autre, ce qui est insensé.
       
        if (colO < 15)
          colO++;
        else
          colO = 0;

        lcd.setCursor(0,0);
        lcd.print("                "); 
        lcd.setCursor(colO,0);
        lcd.write(byte (2));          
    }
    
    if (buttons & BUTTON_SELECT)
    {    // Modifiez ce bloc au besoin
       lcd.setCursor(0,0);
       lcd.print ( "                ");  // affiche 16 espaces pour effacer la ligne
       lcd.setCursor(15,0);
       lcd.write(byte (2));
       lcd.setBacklight(RED);
    }
  }
  lcd.setBacklight(RED);
}
