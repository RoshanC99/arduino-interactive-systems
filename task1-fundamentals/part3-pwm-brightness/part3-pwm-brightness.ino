/*
  Task 1 - Part 3: LED brightness control with two buttons (PWM)
  ---------------------------------------------------------------
  Two pushbuttons select one of four LED brightness levels using PWM
  (analogWrite). The two buttons give four input combinations, mapped to
  four duty cycles:

      Button 1   Button 2   Brightness   analogWrite value
      released   released   100%         255
      pressed    released    75%         191
      released   pressed     50%         128
      pressed    pressed     25%          64

  Circuit:
  - LED on PWM pin 9 (~), in series with a 330 ohm resistor to GND
  - button 1 on pin 2 from +5V, with a 10K pull-down resistor to GND
  - button 2 on pin 4 from +5V, with a 10K pull-down resistor to GND

  PWM / analogWrite reference:
  https://docs.arduino.cc/learn/microcontrollers/analog-output/
  Fading example used as a starting point for analogWrite:
  https://docs.arduino.cc/built-in-examples/analog/Fading/

  Design note: the most specific combination (both pressed) is tested first
  so that the if / else-if branches never overlap.
*/

const int button_1_Pin = 2;
const int button_2_Pin = 4;
const int ledPin = 9;        // must be a PWM (~) pin for analogWrite

int button_1_State = 0;
int button_2_State = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(button_1_Pin, INPUT);
  pinMode(button_2_Pin, INPUT);
}

void loop() {
  button_1_State = digitalRead(button_1_Pin);
  button_2_State = digitalRead(button_2_Pin);

  if (button_1_State == HIGH && button_2_State == HIGH) {
    analogWrite(ledPin, 64);   // both pressed -> 25% (25% of 255 ~= 64)
  }
  else if (button_1_State == HIGH && button_2_State == LOW) {
    analogWrite(ledPin, 191);  // button 1 only -> 75% (75% of 255 ~= 191)
  }
  else if (button_1_State == LOW && button_2_State == HIGH) {
    analogWrite(ledPin, 128);  // button 2 only -> 50% (50% of 255 ~= 128)
  }
  else {
    analogWrite(ledPin, 255);  // neither pressed -> 100%
  }
}
