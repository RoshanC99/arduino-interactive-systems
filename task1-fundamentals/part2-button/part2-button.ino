/*
  Task 1 - Part 2: Button-controlled LED
  ----------------------------------------
  First circuit that both reads an input (a pushbutton) and writes an output
  (an LED). While the button is held, the LED is on; released, it is off.

  Circuit:
  - LED attached from pin 13 to ground through a 220 ohm resistor
    (pin 13 also drives the on-board "L" LED, so both respond together)
  - pushbutton attached to pin 2 from +5V
  - 10K pull-down resistor attached to pin 2 from ground
    (keeps the input at a clean LOW when the button is not pressed)

  Code is the public-domain Arduino "Button" built-in example:
  https://docs.arduino.cc/built-in-examples/digital/Button/
  created 2005 by DojoDave; modified 30 Aug 2011 by Tom Igoe
*/

const int buttonPin = 2;   // pushbutton pin
const int ledPin = 13;     // LED pin

int buttonState = 0;       // variable for reading the pushbutton status

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);   // button pressed -> LED on
  } else {
    digitalWrite(ledPin, LOW);    // button released -> LED off
  }
}
