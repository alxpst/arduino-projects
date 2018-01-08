/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 8, en = 9, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Hello, world!");
}

byte key() {
  int val = analogRead(0);
  if (val < 50 )return 1; //Right
  else if (val < 150) return 2; //Up
  else if (val < 320) return 3; //Down
  else if (val < 500) return 4; //Left
  else if (val < 800) return 5; //Select
  else if (val <= 1023) return 0; //none
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("analogRead");
  lcd.print(analogRead(0));
  lcd.setCursor(0, 1);
    switch (key()) {
      case 1:
        lcd.print("RIGHT");
        break;
      case 2:
        lcd.print("UP");
        break;
      case 3:
        lcd.print("DOWN");
        break;
      case 4:
        lcd.print("LEFT");
        break;
      case 5:
        lcd.print("SELECT");
        break;
      case 0:
        lcd.print("NONE");
        break;
    }
  delay(250);
}

