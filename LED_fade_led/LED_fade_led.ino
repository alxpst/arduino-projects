/*
 * Пример управления яркостью светодиода
 * на выходе 9 контроллера Arduino
 * функцией analogWrite().
 */
int brightness = 0; /*начальное значение яркости*/
int fadeAmount = 5; /*шаг увеличения/уменьшения яркости*/

void setup() {
  /*
   * устанавливаем пин D9 в режим выхода
   */
  pinMode(9, OUTPUT);
}

void loop() {
  /* 
   * устанавливаем значение широты импульса на выходе 9
   * задавая яркость светодиода
   */
  analogWrite(9,brightness);
  /*
   * изменяем занчение в переменной для яркости
   */
  brightness = brightness + fadeAmount;
  /*
   * в крайних значениях яркости
   * меняем знак переменной шага яркости
   */
  if (brightness == 0 || brightness == 255) fadeAmount = -fadeAmount;

  delay(30);
}
