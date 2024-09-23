# Arduino ESC Controller with LCD Display

## Overview

This project uses an Arduino to control an Electronic Speed Controller (ESC) based on the input from a potentiometer. The current speed value is displayed on a Liquid Crystal Display (LCD) using I2C communication. 

## Components Required

- Arduino Board (e.g., Arduino Uno)
- Electronic Speed Controller (ESC)
- Brushless DC Motor
- Potentiometer (10kΩ recommended)
- Liquid Crystal Display (LCD) with I2C interface
- Jumper wires
- Power supply for the ESC and motor

## Wiring Diagram

![Wiring Diagram](https://github.com/Omar-Rihani/Brushless-Motor-Project/blob/main/image.jpg)

### Connections

1. **Potentiometer**:
   - Connect one terminal to +5V
   - Connect the other terminal to GND
   - Connect the middle terminal to the analog pin A0

2. **ESC**:
   - Connect the signal wire to digital pin 9
   - Connect the ground wire to GND
   - Connect the power wire to the battery (ensure compatibility)

3. **LCD**:
   - Connect VCC to +5V
   - Connect GND to GND
   - Connect SDA to A4
   - Connect SCL to A5

## Code Explanation

The code consists of two main parts: the `setup()` function and the `loop()` function.

### Setup Function

- Initializes the LCD and sets up the ESC.
- Turns on the LCD backlight and sets the serial communication for debugging.
- Displays the initial text "Vitesse: " on the LCD.

### Loop Function

- Reads the value from the potentiometer connected to pin A0.
- Maps the potentiometer value (0-1023) to a range suitable for the ESC (0-180 degrees).
- Sends the mapped value to the ESC using the `write()` method.
- Updates the LCD to show the current speed value.
- Prints the current speed value to the serial monitor for debugging.
- Introduces a delay of 100 milliseconds before repeating the process.

## Usage

1. Upload the code to your Arduino board.
2. Connect the components as described above.
3. Power the ESC and motor with the appropriate battery.
4. Adjust the potentiometer to control the speed of the motor. The current speed will be displayed on the LCD.

## Notes

- Ensure that the ESC is compatible with the motor being used.
- Modify the I2C address in the code if your LCD module uses a different address (check with an I2C scanner).
- Make sure to adjust the pulse width values in the `ESC.attach()` method according to your ESC specifications.

## Troubleshooting

- If the LCD does not display any text, check the I2C connections and ensure the address is correct.
- If the motor does not respond, verify the ESC connections and the power supply.
- Monitor the serial output for any debug messages or errors.
