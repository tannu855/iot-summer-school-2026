const int buzzer = 8;

const int btn1 = 2;
const int btn2 = 3;
const int btn3 = 4;
const int btn4 = 5;

void setup() {
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(btn4, INPUT_PULLUP);
}

void loop() {

  // 👇 INPUT READ (Step 6 added)
  bool b1 = digitalRead(btn1) == LOW;
  bool b2 = digitalRead(btn2) == LOW;
  bool b3 = digitalRead(btn3) == LOW;
  bool b4 = digitalRead(btn4) == LOW;

  // 🎹 CHORD + NOTES LOGIC
  if ((b1 + b2 + b3 + b4) >= 2) {
    tone(buzzer, 392); // Sol (Chord)
  }
  else if (b1) {
    tone(buzzer, 262); // Do
  }
  else if (b2) {
    tone(buzzer, 294); // Re
  }
  else if (b3) {
    tone(buzzer, 330); // Mi
  }
  else if (b4) {
    tone(buzzer, 349); // Fa
  }
  else {
    noTone(buzzer); // stop sound
  }
}
