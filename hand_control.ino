const int LED1 = 3; // קבע פיזור לד
const int LED2 = 4;
const int LED3 = 5;
const int LED4 = 6;
const int LED5 = 7;

void setup() {
  Serial.begin(9600); // התחלת Serial במהירות 9600
  pinMode(LED1, OUTPUT); // הגדרה של פיזור לד כפלט
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

void loop() {
  if (Serial.available() > 1) { // בדיקה אם קיימים נתונים ב-Serial
    char receivedChar = Serial.read(); // קריאת תו שהתקבל מ-Serial
    
    switch (receivedChar) {
      case '0':
        digitalWrite(LED1, LOW); // כיבויLED
        digitalWrite(LED2, LOW);  // כיבויLED
        digitalWrite(LED3, LOW);  // כיבויLED
        digitalWrite(LED4, LOW); // כיבויLED
        digitalWrite(LED5, LOW); // כיבויLED
        break;
      case '1':
        digitalWrite(LED1, HIGH); // הדלקת LED1
        digitalWrite(LED2, LOW);  // כיבויLED
        digitalWrite(LED3, LOW); // כיבויLED
        digitalWrite(LED4, LOW); // כיבויLED
        digitalWrite(LED5, LOW);  // כיבויLED
        break;
      case '2':
        digitalWrite(LED1, HIGH); // הדלקת LED1
        digitalWrite(LED2, HIGH); // הדלקת LED2
        digitalWrite(LED3, LOW);  // כיבויLED
        digitalWrite(LED4, LOW);  // כיבויLED
        digitalWrite(LED5, LOW);  // כיבויLED
        break;
      case '3':
        digitalWrite(LED1, HIGH); // הדלקת LED1
        digitalWrite(LED2, HIGH); // הדלקת LED2
        digitalWrite(LED3, HIGH); // הדלקת LED3
        digitalWrite(LED4, LOW);  // כיבויLED
        digitalWrite(LED5, LOW);  // כיבויLED
        break;
      case '4':
        digitalWrite(LED1, HIGH); // הדלקת LED1
        digitalWrite(LED2, HIGH); // הדלקת LED2
        digitalWrite(LED3, HIGH); // הדלקת LED3
        digitalWrite(LED4, HIGH); // הדלקת LED4
        digitalWrite(LED5, LOW);  // כיבויLED
        break;
      case '5':
        digitalWrite(LED1, HIGH); // הדלקת LED1
        digitalWrite(LED2, HIGH); // הדלקת LED2
        digitalWrite(LED3, HIGH); // הדלקת LED3
        digitalWrite(LED4, HIGH); // הדלקת LED4
        digitalWrite(LED5, HIGH); // הדלקת LED5
        break;
      default:
        digitalWrite(LED1, LOW);  // כיבויLED
        digitalWrite(LED2, LOW);  // כיבויLED
        digitalWrite(LED3, LOW);  // כיבויLED
        digitalWrite(LED4, LOW);  // כיבויLED
        digitalWrite(LED5, LOW); // כיבויLED
        break;
    }
  }
}
