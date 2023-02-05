
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
void loop() {
  // Positionne le curseur. colonne 0 et ligne 1
  lcd.setCursor(0, 1);
  // Affiche le nombre de secondes après un reset.
  lcd.print(millis()/1000);

  uint8_t buttons = lcd.readButtons();

  if (buttons) {
    lcd.clear();  // Efface la mémoire de l'afficheur.
 
    // Bloc des cinq boutons
    if (buttons & BUTTON_UP) {
      lcd.setCursor(0,0);
      lcd.print("HAUT");    // Affiche la chaîne HAUT   
      lcd.setCursor(5,0);
      lcd.write(byte (0));  // Affiche le bonhomme sourire
   // lcd.write(byte (3));  // Affiche le caractère personnel
      lcd.setCursor(0,1);
      lcd.print ( "                "); // on efface la ligne
      lcd.setBacklight(RED);
     }
     
    if (buttons & BUTTON_DOWN) {
      lcd.setCursor(0,0);
      lcd.print("DOWN ");
      lcd.setBacklight(GREEN);
    }
    
    if (buttons & BUTTON_LEFT) {
      lcd.setCursor(0,0);
      lcd.print("LEFT ");
      lcd.setCursor(8, 1);
      lcd.write(byte (1)); // Affiche le bonhomme triste
      lcd.setCursor(0,0);
      lcd.print ( "                "); // la ligne d'en haut est effacée
      lcd.setBacklight(GREEN);
    }
    
    if (buttons & BUTTON_RIGHT) {
      lcd.setCursor(0,0);
      lcd.print("RIGHT ");
      lcd.setBacklight(GREEN);
   // lcd.write(byte (2)); // Affiche le caractère ohm
    }
    
    if (buttons & BUTTON_SELECT) {
      lcd.setCursor(0,0);
      lcd.print("SELECT ");
      lcd.setBacklight(RED);
    }
  }
}
