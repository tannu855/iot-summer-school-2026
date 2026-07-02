int led = 13;
int pot = A0;
int count = 0;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int speed = analogRead(pot);
  speed = map(speed, 0, 1023, 100, 1000);

  digitalWrite(led, HIGH);
  delay(speed);
  digitalWrite(led, LOW);
  delay(speed);

  count++;
  Serial.print("Blink count: ");
  Serial.println(count);
}
