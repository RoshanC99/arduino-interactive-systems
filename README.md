# Arduino Interactive Systems
GA Tech MS CS Course - CS 7470: Mobile & Ubiquitous Computing

A set of Arduino prototypes built on an ELEGOO UNO R3 (Arduino-compatible),
progressing from basic digital I/O to a complete sensor-driven interactive
system. Each task reads inputs, processes them in Arduino, and drives the
outputs

Written in C/C++ (Arduino framework) and tested on hardware.

---

## What this project demonstrates

- Digital input/output and reading pushbuttons reliably (pull-down and internal pull-up resistors)
- Pulse-width modulation (PWM) for analog-style output (LED dimming, RGB color mixing)
- Reading analog sensors with `analogRead` and rescaling ranges with `map`
- Combining multiple sensors and actuators into a single event loop with no pin conflicts
- Breadboard prototyping, voltage dividers, and hardware debugging
- Reading datasheets/tutorials and adapting reference code with proper attribution

---

## Hardware

- ELEGOO UNO R3 controller board (Arduino Uno compatible)
- Breadboard, jumper wires, and female-to-male DuPont wires
- LEDs + current-limiting resistors (220–330 Ω)
- Pushbuttons + 10 kΩ pull-down resistors
- Joystick module (2-axis analog + button)
- Tilt ball switch
- RGB LED (common cathode)
- Passive buzzer

---

## Repository structure

```
arduino-interactive-systems/
├── task1-fundamentals/
│   ├── part1-blink/            # Blink an LED on a timer
│   ├── part2-button/           # Button turns an LED on/off (digital I/O)
│   └── part3-pwm-brightness/   # Two buttons select 4 LED brightness levels (PWM)
└── task2-interactive-system/   # Joystick -> RGB LED, tilt switch -> buzzer
```

Each folder contains a self-contained `.ino` sketch with a header comment
describing the circuit, pin assignments, and references.

---

## Task 1 — Fundamentals

Three warm-up circuits that build up the input → process → output pattern.

### Part 1 · Blink
A single LED on pin 7 blinks on a one-second timer — the minimal
output-only circuit. Pin 7 (a plain digital pin) is used instead of pin 13 so
the blink clearly comes from the breadboard LED rather than the board's
built-in LED.

### Part 2 · Button
Adds the first **input**. A pushbutton on pin 2 (with a 10 kΩ pull-down
resistor to keep the pin from floating) turns an LED on while pressed. This is
the first circuit that both reads an input and writes an output.

### Part 3 · PWM brightness control
Two pushbuttons select one of four LED brightness levels using PWM. The two
buttons give four input combinations, each mapped to a duty cycle:

| Button 1 | Button 2 | Brightness | `analogWrite` |
|----------|----------|-----------|---------------|
| released | released | 100%      | 255 |
| pressed  | released |  75%      | 191 |
| released | pressed  |  50%      | 128 |
| pressed  | pressed  |  25%      |  64 |

The most specific combination (both pressed) is tested first so the
`if / else-if` branches never overlap.

---

## Task 2 — Interactive system

An original system with **two different sensors** driving **two different
actuators**, all processed by the Arduino (no sensor is wired directly to an
actuator).

| Sensor | → | Actuator | Behavior |
|--------|---|----------|----------|
| Joystick (X-axis, A0) | → | RGB LED (pins 11, 10, 9) | Stick position sweeps the LED through the color spectrum |
| Tilt ball switch (pin 2) | → | Passive buzzer (pin 6) | Tilting toggles an 880 Hz tone on/off |

**How it works.** Each loop, the Arduino reads the joystick's X-axis with
`analogRead` (0–1023), rescales it with `map` onto a six-step color wheel, and
writes red/green/blue values to the RGB LED via PWM. In the same loop it reads
the tilt switch with `digitalRead` (using the internal pull-up resistor) and
plays or silences the buzzer with `tone` / `noTone`. The two halves share no
pins and run independently.

**Engineering notes / debugging.** A few real problems were worked through
during the build, which is half the point of prototyping:
- Swapped a hard-to-seat potentiometer and a flaky analog sensor path for a
  joystick module, which reads the same 0–1023 range with far simpler wiring.
- Traced a buzzer that played regardless of input to a floating digital pin;
  fixed it by switching from an external pull-down resistor to the Arduino's
  internal `INPUT_PULLUP`.
- Found an intermittent tilt switch was shorting across a single breadboard
  row; wiring it directly with DuPont leads resolved it.

---

## Running a sketch

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Open any `.ino` file from this repo.
3. Select **Tools → Board → Arduino Uno** and the correct **Port**.
4. Wire the circuit as described in the sketch's header comment.
5. Click **Upload**.

---

## References

- Adafruit — Blinking the LED: https://learn.adafruit.com/adafruit-arduino-lesson-2-leds/blinking-the-led
- Arduino — Button built-in example: https://docs.arduino.cc/built-in-examples/digital/Button/
- Arduino — Analog output (PWM): https://docs.arduino.cc/learn/microcontrollers/analog-output/
- The Robotics Back-End — Control an RGB LED with a potentiometer: https://roboticsbackend.com/arduino-control-rgb-led-with-potentiometer/

Reference code is cited in each sketch and adapted rather than copied verbatim
where the assignment required original work.
