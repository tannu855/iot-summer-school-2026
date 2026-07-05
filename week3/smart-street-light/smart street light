const int LDR_PIN = A0;
const int PIR_PIN = 2;
const int LED_PIN = 9;

const int LDR_THRESHOLD = 500;   // Adjust if needed

unsigned long motionTime = 0;
bool motionDetected = false;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int ldrValue = analogRead(LDR_PIN);
  int pirValue = digitalRead(PIR_PIN);

  // DAY MODE
  if (ldrValue > LDR_THRESHOLD) {
    analogWrite(LED_PIN, 0);
    motionDetected = false;

    Serial.print("[");
    Serial.print(millis() / 1000);
    Serial.println("s] EVENT: Day Mode - LED OFF");

    delay(1000);
    return;
  }

  // NIGHT MODE
  if (pirValue == HIGH) {
    analogWrite(LED_PIN, 255);   // Full Brightness
    motionTime = millis();
    motionDetected = true;

    Serial.print("[");
    Serial.print(millis() / 1000);
    Serial.println("s] EVENT: Motion Detected - LED ON");
  }

  // 30 seconds after last motion
  if (motionDetected && millis() - motionTime >= 30000) {
    analogWrite(LED_PIN, 51);    // 20% Brightness

    Serial.print("[");
    Serial.print(millis() / 1000);
    Serial.println("s] EVENT: No Motion - LED DIM");

    motionDetected = false;
  }

  delay(100);
}
