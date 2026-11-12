/*
  Task 1 - Part 1: Blink an LED
  --------------------------------
  The "Hello World" of Arduino. A single LED on the breadboard blinks on/off
  on a one-second timer, driven from a digital output pin.

  Circuit:
  - LED on pin 7, in series with a 330 ohm current-limiting resistor to GND
    (long leg / anode toward the resistor, short leg / cathode to GND)

  Based on the Adafruit "Blinking the LED" tutorial:
  https://learn.adafruit.com/adafruit-arduino-lesson-2-leds/blinking-the-led

  Note: pin 7 is a plain digital pin (unlike pin 13, which also drives the
  on-board "L" LED). Using pin 7 proves the blink comes from the breadboard
  circuit, not the board's built-in LED.
*/

int led = 7;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);   // LED on
  delay(1000);               // wait 1 second
  digitalWrite(led, LOW);    // LED off
  delay(1000);               // wait 1 second
}
