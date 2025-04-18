# 🔌 Arduino Dual Motor Control with BTS7960 (HW-039)

This project controls two motor drivers (HW-039 / BTS7960) via serial commands using an Arduino. It supports multiple movements like forward, backward, turning, and more using simple one-character commands.

## 🚀 Features

- Dual BTS7960 motor driver support
- Serial command interface
- Smooth PWM-based speed control
- Directional commands: forward, backward, left, right
- Pattern movements: circle, cross, triangle, square
- Start and pause functionality

## 🧠 Command List

| Command | Action                  |
|---------|-------------------------|
| F       | Move Forward            |
| B       | Move Backward           |
| L       | Turn Left               |
| R       | Turn Right              |
| C       | Circle Motion           |
| X       | Cross (custom)          |
| T       | Triangle (custom)       |
| S       | Square (custom)         |
| A       | Start Operation         |
| P       | Pause/Stop All Motors   |

## 🧰 Components Used

| Component                        | Quantity |
|----------------------------------|----------|
| Arduino Uno/Nano                 | 1        |
| HW-039/BTS7960 43A Motor Driver  | 2        |
| DC Motors                        | 4 (2 per driver) |
| External Power Supply (12V/24V)  | 1        |
| Jumper Wires                     | As needed |
| bluetooth module hc 06           | 2        |
| USB Cable                        | 1        |

## 🛠️ Pin Configuration

### 🔹 Johnson Drive (Driver 1)
| Function | Arduino Pin |
|----------|-------------|
| RPWM     | 9           |
| LPWM     | 10          |
| REN (Enable) | 8       |
| LEN (Enable) | 7       |

### 🔹 Drive 2 (Driver 2)
| Function | Arduino Pin |
|----------|-------------|
| RPWM2    | 6           |
| LPWM2    | 5           |
| REN2 (Enable) | 4      |
| LEN2 (Enable) | 3      |

## ⚙️ How It Works

1. Upload the code to your Arduino.
2. Open Serial Monitor (baud rate: 9600).
3. Send any of the defined commands.
4. The robot will respond accordingly.

## ⚠️ Notes

- Make sure you connect the **ENA and ENB** pins on the BTS7960 module to HIGH for enabling the motor.
- Use an **external power source** capable of handling the motor’s current requirements.
- Double-check the GND connection between the Arduino and the BTS7960 boards.


---

🛠️ Built with ❤️ using Arduino & BTS7960 for robust motor control.
