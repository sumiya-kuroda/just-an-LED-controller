// Pin assignments
const int inputPins[3]  = {4, 5, 6};     // DI4, DI5, DI6
const int outputPins[3] = {10, 11, 12};  // DO10, DO11, DO12

void setup() {
  // Configure input pins as plain inputs (no internal pull-ups)
  for (int i = 0; i < 3; i++) {
    pinMode(inputPins[i], INPUT);
  }

  // Configure output pins
  for (int i = 0; i < 3; i++) {
    pinMode(outputPins[i], OUTPUT);
    digitalWrite(outputPins[i], LOW);
  }

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  bool anyHigh = false;

  for (int i = 0; i < 3; i++) {
    int state = digitalRead(inputPins[i]);   // read the input (LOW or HIGH)
    digitalWrite(outputPins[i], state);      // mirror it to the corresponding output
    if (state == HIGH) anyHigh = true;
  }

  digitalWrite(LED_BUILTIN, anyHigh ? HIGH : LOW);
}
