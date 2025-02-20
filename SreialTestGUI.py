import serial
import tkinter as tk
from tkinter import Label

# Set up Serial connection (Change 'COM12' to your actual port)
try:
    ser = serial.Serial('COM12', 115200, timeout=1)
except serial.SerialException as e:
    print(f"Error: {e}")
    exit()

# Function to update the display
def update_display():
    if ser.in_waiting > 0:
        data = ser.readline().decode('utf-8').strip()
        print(f"Received: {data}")  # Debugging output

        if data == "1 0":   # Completely Unblocked (No Tube)
            state_label.config(text="No Tube Detected", bg="blue", fg="white")
        elif data == "0 1": # Completely Blocked
            state_label.config(text="Tube is Completely Blocked", bg="green", fg="white")
        elif data == "1 1": # Tube Present
            state_label.config(text="Tube Present", bg="gray", fg="black")
        elif data == "1 0": # Tube with Water
            state_label.config(text="Tube with Water", bg="blue", fg="white")

    # Repeat function every 500ms
    root.after(500, update_display)

# Set up GUI window
root = tk.Tk()
root.title("Tube Sensor State")
root.geometry("400x200")

state_label = Label(root, text="Waiting for Data...", font=("Arial", 16), bg="white", width=40, height=5)
state_label.pack(pady=20)

# Start updating display
update_display()

# Run the GUI loop
root.mainloop()
