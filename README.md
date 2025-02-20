# OCB350-sensor
The OCB350 sensor is designed for liquid detection in tubes with non-contact operation. The sensor uses an optical phototransistor to detect changes in light caused by the presence or absence of liquid

![Sensor State](20250220_001506.jpg)


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

- 🔗 Identifying the JST Wires:

· Red: Vcc (Power supply, 4.75V–5.25V)

· Black: GND (Ground)

· Orange: Logic Out A (Digital)

· Blue: Logic Out B (Digital)

· White: Analog Output

· Green: Calibration Pin

🛠️ Steps to Connect:

1. Connect the Red wire to the Arduino’s 5V pin.

2. Connect the Black wire to the Arduino’s GND pin.

3. Connect the remaining wires (as needed) to the appropriate Arduino pins.

![Sensor State](20250220_001402.jpg)

Calibrating the Sensor 🎯

Calibration ensures the sensor is optimized for the specific environmental and tube conditions.

🔍 How Calibration Works:

· The sensor adjusts the LED drive current until the phototransistor output matches the calibration target.

· This compensates for degradation, ambient light, or contamination in the optical path.

🛠️ Steps for Calibration:

1. Ground the Calibration Pin (Green Wire):

a. Connect the green wire to ground (black wire) for 1-2 seconds.

b. This can be automated by connecting the green wire to a digital output pin (e.g., D7) and using Arduino code.

2. LED Feedback During Calibration:

a. Green LED Blinking: Calibration is in progress.

b. Green LED Steady ON: Calibration successful.

c. Red LED ON: Calibration failed. Check alignment or environmental conditions.

3. Choose Calibration State:

a. Empty Tube: Baseline is no liquid.

b. Clear Liquid: Baseline is clear liquid present.

c. No Tube: Baseline is no tube.

4. Arduino Code for Calibration:

const int CALIBRATE_PIN = 7; // Define calibration pin void setup() { pinMode(CALIBRATE_PIN, OUTPUT); // Start calibration digitalWrite(CALIBRATE_PIN, LOW); delay(2000); // Hold calibration for 2 seconds digitalWrite(CALIBRATE_PIN, HIGH); // End calibration }


Progress: We observed the green light for calibration but need to ground touching the wires next and add delay to the code.


Some References: https://www.circuitstate.com/intocb350l250z

https://www.ttelectronics.com/TTElectronics/media/ProductFiles/Datasheet/opb350.pdf
  
  delay(500); // Small delay for readability in serial output
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


}



