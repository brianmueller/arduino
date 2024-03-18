int solarPin = A0;
int startButtonPin = 2;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(startButtonPin, INPUT_PULLUP);

  Serial.begin(9600);

}

// the loop function runs over and over again forever
void loop() {

//  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
//  delay(2000);                      // wait for a second
//  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
//  delay(2000);                      // wait for a second

  int solarValue = analogRead(solarPin);
  Serial.println(solarValue);

  if(digitalRead(startButtonPin) == LOW){
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

}
