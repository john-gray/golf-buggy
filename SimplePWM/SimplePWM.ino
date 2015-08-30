// Choosing pin 3 for the PWM output
int pwmpin = 3;
// Output voltage should be 3V so 255*3/5 = 153
int aout = 153;

// the setup routine runs once when you press reset:
void setup() {
// initialize the digital pin as an output.
pinMode(pwmpin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  analogWrite(pwmpin, aout);
  delay(1000);
}
