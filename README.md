# Arduino Project: Birthday Greeting

## Description

This project uses an Arduino Uno to display a birthday message on a 16x2 I2C LCD and play the Happy Birthday song using a buzzer. After the song, the LCD shows additional custom messages.


## Components

* Arduino Uno
* 16x2 I2C LCD
* Buzzer
* Jumper wires


## Circuit Diagram

![Circuit Diagram](https://github.com/Putrasemaa/arduino-birthday-celebration/blob/main/schematic.png?raw=true)


## Pin Connections

### LCD I2C

* SDA → A4
* SCL → A5
* VCC → 5V
* GND → GND

### Buzzer

* Positive → Pin 11
* Negative → GND


## How It Works

1. Arduino displays a birthday message on the LCD
2. Buzzer plays the Happy Birthday melody
3. After a few seconds, LCD shows custom messages in sequence
4. Final message shows a closing greeting


## Libraries Used

### Wire.h

Used for I2C communication between Arduino and LCD.

### LiquidCrystal_I2C.h

Used to control the 16x2 I2C LCD display.

### pitches.h

Custom library file that contains musical note definitions (example: NOTE_C5, NOTE_D5) used for generating melodies with the buzzer.


## Customization Guide

### Change Name

Find this line:

```cpp
lcd.print("[NAME]");
```

Replace with your name:

```cpp
lcd.print("Ciya");
```

Also change the final message:

```cpp
lcd.print("from [NAME]");
```

Example:

```cpp
lcd.print("from Putra");
```


### Change Messages

Replace these placeholders:

```cpp
lcd.print("[MESSAGE 1]");
lcd.print("[MESSAGE 2]");
```

Example messages:

* Happy Birthday!
* Wish you all the best
* Stay healthy and happy
* Success in your life
* Enjoy your special day
* Thank you for everything


## Example Output Messages

* Message 1: Happy Birthday!
* Message 2: Wish you a wonderful day
* Message 3: Stay healthy and strong
* Message 4: Success in everything you do
* Message 5: Keep smiling always
* Message 6: Enjoy your special day
* Message 7: Thank you and best wishes


## Final Result

![Project Result](https://github.com/Putrasemaa/arduino-birthday-celebration/blob/main/project.jpeg?raw=true)


## Wokwi Simulation

[https://wokwi.com/projects/415953016426231809](https://wokwi.com/projects/415953016426231809)


## Creator

Septiyan Maulana Putra

