void setup() {
  Serial.begin(115200);
  pinMode(4, INPUT_PULLUP);  // Logic A
  pinMode(5, INPUT_PULLUP);  // Logic B
  pinMode(A0, INPUT);        // Analog sensor input
}

void loop() {
  int logicA = digitalRead(4);
  int logicB = digitalRead(5);
  int analogValue = analogRead(A0);

  // Determine the state
  String state;
  if (logicA == 1 && logicB == 0) {
    state = "Completely Unblocked (No Tube)";
  } else if (logicA == 0 && logicB == 1) {
    state = "Completely Blocked";
  } else if (logicA == 1 && logicB == 1) {
    state = "Tube Present";
  } else {
    state = "Tube + Water";
  }

  // Send the data to Python via Serial
  Serial.print("State: ");
  Serial.print(state);
  Serial.print(", Analog: ");
  Serial.println(analogValue);

  delay(500);
}
