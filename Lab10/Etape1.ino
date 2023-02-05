
// Étape 1

int baseTRANSISTOR = 2;

void setup()
{
  pinMode(baseTRANSISTOR, OUTPUT);
}

void loop()
{
  // On envoie du courant pour que la DEL sur le contact NO allume
  // et que la DEL sur le contact NC éteint
  digitalWrite(baseTRANSISTOR, HIGH);
    
  delay(1000);   // un petit délai

  // On envoie du courant pour que la DEL sur le contact NC allume
  // et que la DEL sur le contact NO éteint
  digitalWrite(baseTRANSISTOR, LOW);

  delay(2000);  // un petit délai
}
