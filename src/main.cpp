#include <Arduino.h>

#define LEDV1 14
#define LEDV2 27
#define LEDV3 32
#define LEDV4 33

#define BTNS2 25
#define BTNS3 13
#define BTNS4 15

// Variablen zur Speicherung der Zustände der LEDs
bool ledStateV2 = LOW;
bool ledStateV3 = LOW;
bool ledStateV4 = LOW;

void setup() {
  // Initialisiere LEDs als Ausgänge
  pinMode(LEDV2, OUTPUT);
  pinMode(LEDV3, OUTPUT);
  pinMode(LEDV4, OUTPUT);

  // Initialisiere Tasten als Eingänge mit Pull-Up-Widerstand
  pinMode(BTNS2, INPUT_PULLUP);
  pinMode(BTNS3, INPUT_PULLUP);
  pinMode(BTNS4, INPUT_PULLUP);

  // Initialisiere die serielle Kommunikation
  Serial.begin(9600);

  // Anfangszustand der LEDs
  digitalWrite(LEDV2, ledStateV2);
  digitalWrite(LEDV3, ledStateV3);
  digitalWrite(LEDV4, ledStateV4);
}

void loop() {
  // Überprüfe, ob Tasten gedrückt sind, und aktualisiere die Zustände der LEDs
  if (digitalRead(BTNS2) == LOW) {
    ledStateV2 = !ledStateV2;
    digitalWrite(LEDV2, ledStateV2);
  }
  if (digitalRead(BTNS3) == LOW) {
    ledStateV3 = !ledStateV3;
    digitalWrite(LEDV3, ledStateV3);
  }
  if (digitalRead(BTNS4) == LOW) {
    ledStateV4 = !ledStateV4;
    digitalWrite(LEDV4, ledStateV4);
  }

  // Überprüfe eingehende serielle Befehle
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {
      ledStateV2 = !ledStateV2;
      digitalWrite(LEDV2, ledStateV2);
    } else if (command == '2') {
      ledStateV3 = !ledStateV3;
      digitalWrite(LEDV3, ledStateV3);
    } else if (command == '3') {
      ledStateV4 = !ledStateV4;
      digitalWrite(LEDV4, ledStateV4);
    } else if (command == '0') {
      // Alle LEDs umschalten
      ledStateV2 = !ledStateV2;
      ledStateV3 = !ledStateV3;
      ledStateV4 = !ledStateV4;
      digitalWrite(LEDV2, ledStateV2);
      digitalWrite(LEDV3, ledStateV3);
      digitalWrite(LEDV4, ledStateV4);
    } else if (command == 'q') {
      Serial.println(" ");
      // Abfrage der LED-Zustände
      Serial.print("LED2: ");
      Serial.println(ledStateV2);
      Serial.print("LED3: ");
      Serial.println(ledStateV3);
      Serial.print("LED4: ");
      Serial.println(ledStateV4);
    }
  }
}
