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
  pinMode(LEDV1, OUTPUT);
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
  digitalWrite(LEDV1, LOW);
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
             Serial.println(" ");
      Serial.print("LED V2: ");
      Serial.println(ledStateV2);
      Serial.println(" ");
    } else if (command == '2') {
      ledStateV3 = !ledStateV3;
      digitalWrite(LEDV3, ledStateV3);
             Serial.println(" ");
      Serial.print("LED V3: ");
      Serial.println(ledStateV3);
       Serial.println(" ");
    } else if (command == '3') {
      ledStateV4 = !ledStateV4;
      digitalWrite(LEDV4, ledStateV4);
             Serial.println(" ");
      Serial.print("LED V4: ");
      Serial.println(ledStateV4);
       Serial.println(" ");
    } 
    else if (command == 'c') {
      // Ausgabe aller Commands
    Serial.println("LED V2 ansteuern Taste = '1'");
    Serial.println("LED V3 ansteuecrn Taste = '2'");
    Serial.println("LED V4 ansteuern Taste = '3'");
    Serial.println("LEDs invertieren Taste = '8'");
    Serial.println("LEDs ausschalten Taste = '9'");
    Serial.println("LEDs anschalten Taste = '0'");
    Serial.println("LEDs abfrage Taste = 'a'");
      }
      else if (command == '0') {
      // Alle LEDs einschalten
      ledStateV2 = 1;
      ledStateV3 = 1;
      ledStateV4 = 1;
      digitalWrite(LEDV2, ledStateV2);
      digitalWrite(LEDV3, ledStateV3);
      digitalWrite(LEDV4, ledStateV4);
      } else if (command == '9') {
      // Alle LEDs ausschalten
      ledStateV2 = 0;
      ledStateV3 = 0;
      ledStateV4 = 0;
      digitalWrite(LEDV2, ledStateV2);
      digitalWrite(LEDV3, ledStateV3);
      digitalWrite(LEDV4, ledStateV4);
    }
    else if (command == '8') {
      // Alle LEDs umschalten
      ledStateV2 = !ledStateV2;
      ledStateV3 = !ledStateV3;
      ledStateV4 = !ledStateV4;
      digitalWrite(LEDV2, ledStateV2);
      digitalWrite(LEDV3, ledStateV3);
      digitalWrite(LEDV4, ledStateV4);
    } else if (command == 'a') {
      Serial.println(" ");
      // Abfrage der LED-Zustände
      Serial.print("LED V2: ");
      Serial.println(ledStateV2);
      Serial.print("LED V3: ");
      Serial.println(ledStateV3);
      Serial.print("LED V4: ");
      Serial.println(ledStateV4);
    }
  }
}
