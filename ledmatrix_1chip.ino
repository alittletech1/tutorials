int dataPin = 2;
int clockPin = 3;
int latchPin = 4;
int ledState = {0b0101010101010101}; 

void setup() {
  // set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop()
{
  digitalWrite (latchPin, HIGH);
  shiftOut (dataPin, clockPin, MSBFIRST, highByte (ledState)); // send out upper 8 bits
  shiftOut (dataPin, clockPin, MSBFIRST, lowByte (ledState)); // send out lower 8 bits
  digitalWrite (latchPin, LOW);
  delay(500);
  ledState = ~ledState;
}
