/* 
 * RU: Мигаем светодиодами без delay()
 * EN: Blink leds without delay()
 * 08.01.2017
 * Александр Пустынный / Pustynnyy Aleksandr
 */

const byte ledPin = 9; // номер выхода, подключаемого к светодиоду
const byte aLedPin = 13 // номер выхода, отвечающего за светодиод arduino

int ledState = LOW;    // храним состояние светодиода
int aLedState = HIGH;  // храним состояние светодиода arduino
long prevMillis = 0;   // храним время последнего переключения

long interval = 1000;  // храним интервал переключения состояния

void setup() {
  // задаем режим выхода для порта подключенного к светодиоду
  pinMode (ledPin, OUTPUT);
}

void loop() {
  // 
  unsigned long currMillis = millis();

  if (currMillis - prevMillis > interval) {
    prevMillis = currMillis;

    if (ledState == LOW) {
      ledState = HIGH;
      aLedState = LOW;
    }
    else {
      ledState = LOW;
      aLedState = HIGH;
    }

    digitalWrite(ledPin, ledState);
    digitalWrite(13, aLedState);
  }
}
