
// Librairies utilisés :
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <Utility/Adafruit_MCP23017.h>


byte sourire[8] = {
  B00000, B10001, B00000, B00000, B10001, B01110, B00000,};
byte triste[8] = {
  B00000, B10001, B00000, B00100, B01010, B10001, B00000,};
byte ohm[8] = {
  B01011, B01011, B01011, B01011, B01011, B01011, B01011,};
byte personnel[8] = {
  B01011, B01011, B01011, B01011, B01011, B01011, B01011,};

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

// Utilisé pour un afficheur RGB. Notre afficheur est NB
#define RED 0x1
#define GREEN 0x2

void setup()
{  
  Serial.begin(9600);
  // Initialise le nombre de colonne et le nombre de lignes
  lcd.begin(16, 2);  // 16 colonnes et 2 lignes
  lcd.createChar(0, sourire);   // crée le caractère en mémoire 0
  lcd.createChar(1, triste);    // crée le caractère en mémoire 1
  lcd.createChar(2, ohm);       // crée le caractère en mémoire 2
  lcd.createChar(3, personnel); // crée le caractère en mémoire 3
  lcd.write((uint8_t) 0);

  // Affiche le message pour un chronomètre
  int time = millis();
  lcd.print("Hello, world!");
  time = millis() - time;
  Serial.print("Took "); Serial.print(time); Serial.println(" ms");
  lcd.setBacklight(RED);
}

uint8_t i=0;
void loop()
{
  // Début du programme …
  // Positionne le curseur. colonne 0 et ligne 1
  lcd.setCursor(0, 1);
  // Affiche le nombre de secondes après un reset.
  lcd.print(millis()/1000);

  uint8_t buttons = lcd.readButtons();

  if (buttons)
  {
    lcd.clear();  // Efface la mémoire de l'afficheur.
 
    // Bloc des cinq boutons
    if (buttons & BUTTON_UP)   //DEBUT DU BLOC BOUTON UP
    {
      lcd.setCursor(6,1); // deuxième ligne et au centre
      lcd.print ( "                ");
      lcd.print("LEVI");
      lcd.setBacklight(RED);
     }
     
    if (buttons & BUTTON_DOWN)
    {
      lcd.setCursor(11,0);
      lcd.print ( "                ");
      lcd.print("LINUS");
      lcd.setBacklight(RED);
    }
    
    if (buttons & BUTTON_LEFT) {
      lcd.setCursor(0,0);
      lcd.print ( "                ");
      // première façon d'effacer (en imprimant des espaces)
      lcd.setCursor(0,1);
      lcd.print ( "                ");
      // deuxième façon d'effacer (avec la fonction clear() )
      lcd.clear();
      lcd.setBacklight(RED);
    }
    
    if (buttons & BUTTON_RIGHT) {
       lcd.setCursor(0,0);
       lcd.print("RIGHT ");
       lcd.setBacklight(RED);
    }
    
    if (buttons & BUTTON_SELECT) {
      lcd.setCursor(0,0);
      lcd.print("SELECT ");
      lcd.setBacklight(RED);
    }
  }
}
