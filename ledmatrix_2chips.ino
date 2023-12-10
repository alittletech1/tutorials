int dataPin = 2;
int clockPin = 3;
int latchPin = 4;

int dataPin2 = 10;
int clockPin2 = 11;
int latchPin2 = 12;

int CNT =0;

void setup() {
  // set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin2, OUTPUT);
  pinMode(clockPin2, OUTPUT);
  pinMode(dataPin2, OUTPUT);
}

void loop()
{
  CNT = CNT + 1;

  if (CNT % 2 == 0)
  {
    //red
    digitalWrite (latchPin, HIGH);
    shiftOut (dataPin, clockPin, MSBFIRST, highByte (0xFFFF)); // send out upper 8 bits
    shiftOut (dataPin, clockPin, MSBFIRST, lowByte (0xFFFF)); // send out lower 8 bits
    digitalWrite (latchPin, LOW);
    //green
    digitalWrite (latchPin2, HIGH);
    shiftOut (dataPin2, clockPin2, MSBFIRST, highByte(0)); // send out upper 8 bits
    shiftOut (dataPin2, clockPin2, MSBFIRST, lowByte(0)); // send out lower 8 bits
    digitalWrite (latchPin2, LOW);
  }
  else {
    //red
    digitalWrite (latchPin, HIGH);
    shiftOut (dataPin, clockPin, MSBFIRST, highByte(0)); // send out upper 8 bits
    shiftOut (dataPin, clockPin, MSBFIRST, lowByte(0)); // send out lower 8 bits
    digitalWrite (latchPin, LOW);
    //green
    digitalWrite (latchPin2, HIGH);
    shiftOut (dataPin2, clockPin2, MSBFIRST, highByte (0xFFFF)); // send out upper 8 bits
    shiftOut (dataPin2, clockPin2, MSBFIRST, lowByte (0xFFFF)); // send out lower 8 bits
    digitalWrite (latchPin2, LOW);
  }
delay(500);
}
