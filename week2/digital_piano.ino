const int buzzer = 8;
const int buttons[] = {2, 3, 4, 5};
const int modeButton = 6;

bool majorMode = true;
bool lastModeState = HIGH;

int majorNotes[] = {262, 294, 330, 349};
int minorNotes[] = {262, 277, 311, 330};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }

  pinMode(modeButton, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
}

void loop() {

  bool modeState = digitalRead(modeButton);

  if (lastModeState == HIGH && modeState == LOW) {
    majorMode = !majorMode;
    delay(200);
  }

  lastModeState = modeState;

  int pressed = 0;
  int note = 0;

  for (int i = 0; i < 4; i++) {
    if (digitalRead(buttons[i]) == LOW) {
      pressed++;
      note = majorMode ? majorNotes[i] : minorNotes[i];
    }
  }

  if (pressed >= 2) {
    tone(buzzer, 392);
  }
  else if (pressed == 1) {
    tone(buzzer, note);
  }
  else {
    noTone(buzzer);
  }
}
