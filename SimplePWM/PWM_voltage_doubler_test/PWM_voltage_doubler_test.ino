// Choosing pin 2 for the PWM output
int pwmpin = 3;

// Output voltage should be 3V so 255*3/5 = 153
int aout = 20;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(pwmpin, OUTPUT);
  DDRB = _BV(DDB1);                  //set OC1A/PB1 as output (Arduino pin D9, DIP pin 15)
  TCCR1A = _BV(COM1A0);              //toggle OC1A on compare match
  OCR1A = 7;                         //top value for counter
  TCCR1B = _BV(WGM12) | _BV(CS10);   //CTC mode, prescaler clock/1
}

// the loop routine runs over and over again forever:
void loop() {
  // step up voltage gradually
  for (int aout = 20; aout < 255; aout = aout + 20){
    analogWrite(pwmpin, aout);
    delay(3000);
  }
  aout = 20;
}
