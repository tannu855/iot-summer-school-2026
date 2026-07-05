/*
STATE TRANSITION DIAGRAM

        Insert Coin
IDLE -----------------> COIN_INSERTED
 ^                         |
 | Cancel                  | Select Item
 |                         V
 |------------------- ITEM_SELECTED
                           |
                           | Dispense
                           V
                      DISPENSING
                           |
                           | Finish
                           V
                         IDLE

Cancel button from COIN_INSERTED or ITEM_SELECTED -> IDLE
*/

const int coinBtn = 2;
const int selectBtn = 3;
const int cancelBtn = 4;

const int redLED = 8;
const int yellowLED = 9;
const int greenLED = 10;

enum State {
  IDLE,
  COIN_INSERTED,
  ITEM_SELECTED,
  DISPENSING
};

State currentState = IDLE;

void setup() {
  Serial.begin(9600);

  pinMode(coinBtn, INPUT_PULLUP);
  pinMode(selectBtn, INPUT_PULLUP);
  pinMode(cancelBtn, INPUT_PULLUP);

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  updateLEDs();
  Serial.println("State: IDLE");
}

void loop() {

  switch (currentState) {

    case IDLE:
      if (digitalRead(coinBtn) == LOW) {
        currentState = COIN_INSERTED;
        Serial.println("IDLE -> COIN_INSERTED");
        updateLEDs();
        delay(300);
      }
      break;

    case COIN_INSERTED:
      if (digitalRead(selectBtn) == LOW) {
        currentState = ITEM_SELECTED;
        Serial.println("COIN_INSERTED -> ITEM_SELECTED");
        updateLEDs();
        delay(300);
      }

      if (digitalRead(cancelBtn) == LOW) {
        currentState = IDLE;
        Serial.println("COIN_INSERTED -> IDLE");
        updateLEDs();
        delay(300);
      }
      break;

    case ITEM_SELECTED:
      Serial.println("ITEM_SELECTED -> DISPENSING");
      currentState = DISPENSING;
      updateLEDs();
      delay(2000);
      break;

    case DISPENSING:
      Serial.println("DISPENSING -> IDLE");
      currentState = IDLE;
      updateLEDs();
      delay(1000);
      break;
  }
}

void updateLEDs() {

  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);

  switch (currentState) {

    case IDLE:
      digitalWrite(redLED, HIGH);
      break;

    case COIN_INSERTED:
    case ITEM_SELECTED:
      digitalWrite(yellowLED, HIGH);
      break;

    case DISPENSING:
      digitalWrite(greenLED, HIGH);
      break;
  }
}
