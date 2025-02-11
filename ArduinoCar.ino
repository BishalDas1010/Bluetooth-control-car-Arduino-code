#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define CIRCLE 'C'
#define CROSS 'X'
#define TRIANGLE 'T'
#define SQUARE 'S'
#define START 'A'
#define PAUSE 'P'

// Johnson drive
#define RPWM 9  // Right PWM pin
#define LPWM 10 // Left PWM pin
#define REN 8   // Right Enable pin
#define LEN 7   // Left Enable pin


// Driv 2
#define RPWM2 6  // Right PWM pin
#define LPWM2 5 // Left PWM pin
#define REN2 4   // Right Enable pin
#define LEN2 3   // Left Enable pin


void setup() {
  Serial.begin(9600);  // Set the baud rate for serial communication

  // Set control pins as outputs drive 1
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);
  pinMode(REN, OUTPUT);
  pinMode(LEN, OUTPUT);

  // Drive 2
  pinMode(RPWM2, OUTPUT);
  pinMode(LPWM2, OUTPUT);
  pinMode(REN2, OUTPUT);
  pinMode(LEN2, OUTPUT);

  // Enable both sides of the H-bridge
  digitalWrite(REN, HIGH);
  digitalWrite(LEN, HIGH);

  // Enable both sides of the H-bridge for drive 2
  digitalWrite(REN2, HIGH);
  digitalWrite(LEN2, HIGH);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    executeCommand(command);
  }
  // Continue with other tasks in your main loop
}

void executeCommand(char command) {
  switch (command) {
    case FORWARD:
      // Perform action for moving forward
      analogWrite(RPWM, 220); // Speed control (0-255)
      analogWrite(LPWM, 0);   // Left PWM LOW
      analogWrite(RPWM2, 220); // Speed control (0-255)
      analogWrite(LPWM2, 0);   // Left PWM LOW
      break;

    case BACKWARD:
      // Perform action for moving backward
      analogWrite(RPWM, 0);   // Speed control (0-255)
      analogWrite(LPWM, 220); // Left PWM HIGH
      analogWrite(RPWM2, 0);   // Speed control (0-255)
      analogWrite(LPWM2, 220); // Left PWM HIGH
      break;

    case LEFT:
      // Perform action for turning left
      analogWrite(RPWM, 200); // Speed control (0-255)
      analogWrite(LPWM, 0);   // Left PWM LOW
      analogWrite(RPWM2, 0); // Stop right motor
      analogWrite(LPWM2, 220);   // Right motor backward
      break;

    case RIGHT:
      // Perform action for turning right
      analogWrite(RPWM, 0); // Stop left motor
      analogWrite(LPWM, 220);   // Left motor backward
      analogWrite(RPWM2, 0); // Speed control (0-255)
      analogWrite(LPWM2, 0);   // Right PWM LOW
      break;

    case CIRCLE:
      // Perform action for circle
      analogWrite(RPWM, 200); // Speed control (0-255)
      analogWrite(LPWM, 0);   // Left PWM LOW
      analogWrite(RPWM2, 100); // Speed control (0-255)
      analogWrite(LPWM2, 0);   // Left PWM LOW
      break;

    case CROSS:
      // Perform action for immediate stop or crossing
      analogWrite(RPWM, 200); // Speed control (0-255)
      analogWrite(LPWM, 0);   // Left PWM LOW
      analogWrite(RPWM2, 100); // Speed control (0-255)
      analogWrite(LPWM2, 0);   // Left PWM LOW
      break;

    case TRIANGLE:
      // Perform action for toggling a state (e.g., LED on/off)
      analogWrite(RPWM, 200); // Speed control (0-255)
      analogWrite(LPWM, 0);   // Left PWM LOW
      analogWrite(RPWM2, 100); // Speed control (0-255)
      analogWrite(LPWM2, 0);   // Left PWM LOW
      break;

    case SQUARE:
      // Perform action for retrieving and sending status information
      analogWrite(RPWM, 200); // Speed control (0-255)
      analogWrite(LPWM, 0);   // Left PWM LOW
      analogWrite(RPWM2, 100); // Speed control (0-255)
      analogWrite(LPWM2, 0);   // Left PWM LOW
      break;

    case START:
      // Perform action for starting a process or operation
      analogWrite(RPWM, 200); // Speed control (0-255)
      analogWrite(LPWM, 0);   // Left PWM LOW
      analogWrite(RPWM2, 100); // Speed control (0-255)
      analogWrite(LPWM2, 0);   // Left PWM LOW
      break;

    case PAUSE:
      // Perform action for pausing a process or operation
      analogWrite(RPWM, 0); // Speed control (0-255)
      analogWrite(LPWM, 0);   // Left PWM LOW
      analogWrite(RPWM2, 0); // Speed control (0-255)
      analogWrite(LPWM2, 0);   // Left PWM LOW
      break;

    default:
      // Invalid command received
      analogWrite(RPWM, 0); // Speed control (0-255)
      analogWrite(LPWM, 0);   // Left PWM LOW
      analogWrite(RPWM2, 0); // Speed control (0-255)
      analogWrite(LPWM2, 0);   // Left PWM LOW
      break;
  }
}
