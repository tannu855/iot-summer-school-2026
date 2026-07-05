# LED Blink Project

## Project Title
LED Blink using Arduino UNO

## Hardware Required
- Arduino UNO
- 1 LED
- 220Ω Resistor
- Breadboard
- Jumper Wires
- USB Cable

## Circuit Diagram Description
- Connect the LED anode (long leg) to Arduino Digital Pin 13.
- Connect the LED cathode (short leg) to a 220Ω resistor.
- Connect the other end of the resistor to GND.
- Power the Arduino using a USB cable.

## How to Upload Code
1. Open the Arduino IDE.
2. Connect the Arduino UNO to the computer using a USB cable.
3. Open the `led_blink.ino` sketch.
4. Select **Tools > Board > Arduino UNO**.
5. Select the correct COM Port from **Tools > Port**.
6. Click the **Upload** button.
7. Wait until the message **"Done Uploading"** appears.

## Expected Output
- The LED connected to Pin 13 turns ON for 1 second.
- The LED turns OFF for 1 second.
- The blinking continues repeatedly.

## Troubleshooting Tips
1. Check that the LED polarity is correct (long leg to Pin 13, short leg to GND through a resistor).
2. Verify that the correct Arduino board and COM port are selected in the Arduino IDE.
3. Ensure all jumper wire connections are secure.
4. Confirm that the code has been uploaded successfully without errors.
5. Make sure the USB cable is working properly.
