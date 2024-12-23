# Push-Button Controlled Lights (Tinkercad + Embedded C)

This project demonstrates a simple push-button controlled light system using **Tinkercad** for simulation and **Embedded C** for coding. It serves as a beginner-friendly introduction to embedded systems and microcontroller programming.

## Overview

The system uses a microcontroller to toggle LEDs on and off in response to a push-button input. The logic is implemented in Embedded C, and the circuit is simulated in Tinkercad, a web-based tool for electronic prototyping.

## Features

- **Push-Button Input**: Controls the LEDs by toggling their state when pressed.
- **LED Output**: Visual indication of the system's response to the button press.
- **Debouncing Logic**: Implements software debouncing to ensure stable button input.
- **Simulation**: Easily test the setup without physical hardware using Tinkercad.

## Components

- **Microcontroller**: Arduino Uno (or equivalent in Tinkercad).
- **Push-Button**: Used to toggle the LED states.
- **LEDs**: Visual indicators for the output.
- **Resistors**: Used to limit current for LEDs and pull-down resistors for the button.

## Circuit Diagram

The circuit consists of:
1. A push-button connected to a digital input pin with a pull-down resistor.
2. LEDs connected to digital output pins with current-limiting resistors.

You can replicate the circuit in Tinkercad or refer to the diagram below.

## Code

The logic for the system is implemented in Embedded C. The key components include:

- **Pin Initialization**: Configures the microcontroller pins for input (push-button) and output (LEDs).
- **Button Debouncing**: Ensures reliable detection of button presses.
- **State Management**: Toggles the LED state when the button is pressed.

### Sample Code
```c
#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PD2
#define BUTTON_PIN PD3

void init_pins() {
    DDRD |= (1 << LED_PIN);  // Set LED_PIN as output
    DDRD &= ~(1 << BUTTON_PIN);  // Set BUTTON_PIN as input
    PORTD |= (1 << BUTTON_PIN);  // Enable pull-up resistor on BUTTON_PIN
}

int main() {
    init_pins();
    uint8_t button_pressed = 0;

    while (1) {
        if (!(PIND & (1 << BUTTON_PIN))) {  // Check if button is pressed
            _delay_ms(50);  // Debounce delay
            if (!(PIND & (1 << BUTTON_PIN))) {
                button_pressed = !button_pressed;
                if (button_pressed) {
                    PORTD |= (1 << LED_PIN);  // Turn LED on
                } else {
                    PORTD &= ~(1 << LED_PIN);  // Turn LED off
                }
                while (!(PIND & (1 << BUTTON_PIN)));  // Wait for button release
            }
        }
    }
    return 0;
}
```

## How to Use

1. Open [Tinkercad](https://www.tinkercad.com/).
2. Create a new circuit and set up the components as described in the circuit diagram.
3. Upload the Embedded C code to the simulated Arduino.
4. Start the simulation and press the push-button to observe the LED behavior.

## Applications

- **Learning Tool**: Great for beginners to understand microcontroller basics.
- **Prototyping**: A starting point for more complex embedded systems.
- **IoT Projects**: Can be expanded to include sensors or wireless communication.

## Contributing

Feel free to fork this repository, submit issues, or suggest improvements through pull requests.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
