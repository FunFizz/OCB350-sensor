// 📡 Sensor State Detection with Pull-Up Resistors and Analog Reading
void setup() {
    Serial.begin(115200);
    
    // Enable pull-up resistors for stable digital readings
    pinMode(4, INPUT_PULLUP);  // Logic A (Sensor output)
    pinMode(5, INPUT_PULLUP);  // Logic B (Sensor output)
    pinMode(A0, INPUT);        // Analog sensor input
  }
  
  void loop() {
    int logicA = digitalRead(4);   // Read digital pin 4 (Logic A)
    int logicB = digitalRead(5);   // Read digital pin 5 (Logic B)
    int analogValue = analogRead(A0); // Read analog sensor data from A0
  
    // Determine sensor state and print to Serial Monitor
    Serial.print("A: "); Serial.print(logicA);
    Serial.print(" | B: "); Serial.print(logicB);
    Serial.print(" | Analog A0: "); Serial.print(analogValue);
    Serial.print(" | State: ");
  
    if (logicA == 1 && logicB == 0) {
      Serial.println("Completely Unblocked (No Tube) 🔵");
    } else if (logicA == 0 && logicB == 1) {
      Serial.println("Completely Blocked 🟢");
    } else if (logicA == 1 && logicB == 1) {
      Serial.println("Tube Present (No Water) ⚫");
    } else {
      Serial.println("Unknown State ❓");
    }
    
    delay(500); // Small delay for readability in serial output
  }
  