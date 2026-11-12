/*
  Task 2: Interactive system - two sensors driving two actuators
  ---------------------------------------------------------------
  An original interactive circuit with two different sensors and two different
  actuators. The Arduino reads both sensors, processes the values in code, and
  drives both actuators. No sensor is wired directly to an actuator -- every
  input flows through the Arduino.

  Sensor 1 -> Actuator 1 : Joystick X-axis  -> RGB LED color
  Sensor 2 -> Actuator 2 : Tilt ball switch -> Passive buzzer (tone on/off)

  Circuit:
  - Joystick module: VRx -> A0, +5V -> 5V, GND -> GND
  - RGB LED (common cathode): common leg -> GND; red -> pin 11, blue -> pin 10,
    green -> pin 9, each through a 220 ohm resistor
  - Tilt ball switch: one leg -> pin 2, other leg -> GND
    (read with the internal pull-up resistor, so no external resistor needed)
  - Passive buzzer: one leg -> pin 6, other leg -> GND

  References:
  - RGB rainbow color logic adapted from:
    https://roboticsbackend.com/arduino-control-rgb-led-with-potentiometer/
  - Tilt switch read like a button using INPUT_PULLUP; digitalRead logic reused
    from Task 1.
*/

// Sensor 1 -> Actuator 1
const int JOYSTICK_X    = A0;
const int RGB_RED_PIN   = 11;
const int RGB_BLUE_PIN  = 10;
const int RGB_GREEN_PIN = 9;

// Sensor 2 -> Actuator 2
const int TILT_PIN   = 2;
const int BUZZER_PIN = 6;

int tiltState = 0;

void setup() {
  pinMode(RGB_RED_PIN, OUTPUT);
  pinMode(RGB_BLUE_PIN, OUTPUT);
  pinMode(RGB_GREEN_PIN, OUTPUT);
  pinMode(TILT_PIN, INPUT_PULLUP);   // internal pull-up: pin reads HIGH until switch pulls it to GND
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // --- Sensor 1 -> Actuator 1: joystick position sets the RGB LED color ---
  int xValue = analogRead(JOYSTICK_X);            // 0-1023 from the X-axis
  int rgbValue = map(xValue, 0, 1023, 0, 1535);   // scale onto a 6-step color wheel

  int red, blue, green;
  if (rgbValue < 256) {
    red = 255;             blue = rgbValue;       green = 0;
  } else if (rgbValue < 512) {
    red = 511 - rgbValue;  blue = 255;            green = 0;
  } else if (rgbValue < 768) {
    red = 0;               blue = 255;            green = rgbValue - 512;
  } else if (rgbValue < 1024) {
    red = 0;               blue = 1023 - rgbValue; green = 255;
  } else if (rgbValue < 1280) {
    red = rgbValue - 1024; blue = 0;              green = 255;
  } else {
    red = 255;             blue = 0;              green = 1535 - rgbValue;
  }

  analogWrite(RGB_RED_PIN, red);
  analogWrite(RGB_BLUE_PIN, blue);
  analogWrite(RGB_GREEN_PIN, green);

  // --- Sensor 2 -> Actuator 2: tilt switch toggles the buzzer tone ---
  tiltState = digitalRead(TILT_PIN);
  if (tiltState == LOW) {            // LOW = switch closed (tilted into contact)
    tone(BUZZER_PIN, 880);          // play an 880 Hz tone
  } else {
    noTone(BUZZER_PIN);             // otherwise silent
  }
}
