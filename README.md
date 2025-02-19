# OCB350-sensor
The OCB350 sensor is designed for liquid detection in tubes with non-contact operation. The sensor uses an optical phototransistor to detect changes in light caused by the presence or absence of liquid

# 🚀 Sensor State Detection with Arduino

This project demonstrates how to **read and interpret sensor states** using **digital logic outputs (A & B) and an analog signal (A0)**. The **sensor states** are printed to the **Serial Monitor** instead of controlling an LED.

## 📌 Features
✔ Uses **pull-up resistors** for stable digital input readings.  
✔ Reads **digital outputs (Logic A & B) to determine the state**.  
✔ Captures **analog input (A0) for additional sensor data**.  
✔ **Outputs real-time sensor states** to the **Serial Monitor** for debugging.  
✔ Simple and efficient **Arduino implementation**.

---

## 📡 Sensor Logic States

The **sensor outputs two logic signals (A & B)** that define four possible states:

| State                       |  A | B | Description |
|--------                     |---|---|----------------------|
| **Completely Unblocked**    | 1 | 0 | No Tube Present 🔵 |
| **Completely Blocked**      | 0 | 1 | Tube Fully Blocked 🟢 |
| **Tube Present**            | 1 | 1 | Tube Detected (No Water) ⚫ |
| **Unknown State**           | ? | ? | Undefined ❓ |

---

## 🛠️ Hardware Setup

- **Logic A (Sensor Output)** → **Arduino Pin 4** (Pull-up enabled)
- **Logic B (Sensor Output)** → **Arduino Pin 5** (Pull-up enabled)
- **Analog Output (Optional)** → **Arduino A0**
- **Power Supply:** 5V (or 3.3V depending on sensor)
- **Common Ground (GND)**: Connect sensor GND to Arduino GND

---

## 📝 Arduino Code

```cpp
// 📡 Sensor State Detection with Serial Output
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
