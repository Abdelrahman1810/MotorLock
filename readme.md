# MotorLock

MotorLock is an Arduino-based project that controls a DC motor using a keypad and LCD display. The motor will only work if the user enters the correct password.

## Components

* Arduino Uno board
* LiquidCrystal_I2C LCD display
* Keypad 4x4
* Breadboard
* Relay module
* DC motor

## Installation

1. Download the MotorLock code from this repository.
2. Install the LiquidCrystal_I2C and Keypad libraries in the Arduino IDE. You can do this by navigating to Tools -> Manage Libraries, then  searching for and installing "LiquidCrystal_I2C by Frank de Brabander" and "Keypad by Mark Stanley, Alexander Brevig".
3. Connect the components as shown in the circuit diagram.
4. Upload the MotorLock code to your Arduino board using the Arduino IDE.
5. Power up the circuit using a 12V DC power supply.

## Usage

1. When the circuit is powered up, the LCD display will show the "Enter password:" message.
2. Enter the correct password using the keypad. The default password is "1234", but you can change it in the code.
3. If the password is correct, the LCD display will show the "Access granted, Motor is ON" message and the motor will start running.
4. If the password is incorrect, the LCD display will show the "Access denied" message and the motor will not run.

## Circuit Diagram

[Circuit Diagram](https://github.com/Abdelrahman1810/MotorLock/blob/main/Circuit%20Diagram.png)

## Acknowledgements

This project was inspired by the many Arduino-based projects on the internet. Special thanks to the authors of the following libraries:

* LiquidCrystal_I2C by Frank de Brabander
* Keypad by Mark Stanley, Alexander Brevig
