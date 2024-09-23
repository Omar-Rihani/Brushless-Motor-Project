#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Servo ESC;     // créer un objet servo pour contrôler l'ESC (Electronic Speed Controller)
int potValue;  // valeur provenant de la broche analogique

// Initialiser l'écran LCD avec l'adresse I2C 0x27 (ajuster en fonction de votre module LCD)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.backlight();  // Allumer le rétroéclairage de l'écran LCD
  Serial.begin(9600);  // Démarrer la communication série pour le débogage
  ESC.attach(9, 1000, 2000); // Attacher l'ESC sur la broche 9 (broche, largeur d'impulsion minimale, largeur d'impulsion maximale en microsecondes) 

  lcd.begin(16, 2);  // Initialiser l'écran LCD avec 16 colonnes et 2 lignes
  lcd.print("Vitesse: ");  // Texte initial à afficher
}

void loop() {
  potValue = analogRead(A0);  // Lire la valeur du potentiomètre
  int mappedValue = map(potValue, 0, 1023, 0, 180);  // Mapper la valeur lue à la plage de 0 à 180 degrés
  ESC.write(mappedValue);  // Envoyer la valeur mappée au servo

  lcd.setCursor(7, 0);  // Déplacer le curseur à la position (7, 0) sur l'écran LCD
  lcd.print("    ");  // Effacer l'ancienne valeur affichée
  lcd.setCursor(7, 0);  // Déplacer à nouveau le curseur à la position (7, 0)
  lcd.print(mappedValue);  // Afficher la nouvelle valeur

  Serial.println(mappedValue);  // Envoyer la valeur à la console série pour le débogage

  delay(100);  // Attendre 100 millisecondes avant de continuer
}
