import serial

# Open serial connection (Replace 'COMX' with your actual port, e.g., 'COM4' on Windows or '/dev/ttyUSB0' on Linux)
ser = serial.Serial('COM12', 115200, timeout=1)

while True:
    try:
        # Read line from Arduino
        line = ser.readline().decode('utf-8').strip()

        if line:
            print(f"Received: {line}")  # Print the received state

    except KeyboardInterrupt:
        print("Closing connection.")
        ser.close()
        break
