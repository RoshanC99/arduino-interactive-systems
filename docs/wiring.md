# Wiring reference

Pin assignments and connections for each sketch. Resistor values are typical;
anything in the stated range works.

## Task 1 — Part 1: Blink

| From | To |
|------|----|
| Pin 7 | 330 Ω resistor → LED anode (long leg) |
| LED cathode (short leg) | GND |

## Task 1 — Part 2: Button

| From | To |
|------|----|
| Pin 13 | 220 Ω resistor → LED anode → cathode → GND |
| 5V | button leg A |
| Button leg B | pin 2, and 10 kΩ resistor → GND (pull-down) |

## Task 1 — Part 3: PWM brightness

| From | To |
|------|----|
| Pin 9 (~PWM) | 330 Ω resistor → LED anode → cathode → GND |
| 5V | button 1 leg A, and button 2 leg A |
| Button 1 leg B | pin 2, and 10 kΩ → GND |
| Button 2 leg B | pin 4, and 10 kΩ → GND |

## Task 2 — Interactive system

**Joystick module**

| Joystick pin | Arduino |
|--------------|---------|
| VRx | A0 |
| +5V / VCC | 5V |
| GND | GND |

**RGB LED (common cathode)**

| LED leg | Arduino |
|---------|---------|
| Red | 220 Ω → pin 11 |
| Blue | 220 Ω → pin 10 |
| Green | 220 Ω → pin 9 |
| Common (longest leg) | GND |

If no colors light, the LED may be common anode — move the common leg to 5V.

**Tilt ball switch**

| Switch leg | Arduino |
|------------|---------|
| Leg A | pin 2 (configured `INPUT_PULLUP`) |
| Leg B | GND |

No external resistor needed; the internal pull-up holds the pin HIGH until the
switch closes to GND.

**Passive buzzer**

| Buzzer leg | Arduino |
|------------|---------|
| Leg A | pin 6 |
| Leg B | GND |
