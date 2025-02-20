void setup() {
  Serial.begin(115200);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
}

void loop() {
  int logicA = digitalRead(4);
  int logicB = digitalRead(5);
  
  Serial.print(logicA);
  Serial.print(" ");
  Serial.println(logicB);

  delay(500);
}
