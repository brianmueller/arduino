// states: inactive, ready, go, complete, busted

// b = begin
  // hold: "ready/armed" (yellow)
  // release: "go" (blue)
// e = end
  // "complete" (green)
// l = laser
  // "busted" (red)

int solarPin = A0;
int solarThreshold = 500;
int startButtonPin = 2;
int endButtonPin = 3;
int relayPin = 4;
String state = "inactive";

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(startButtonPin, INPUT_PULLUP);
  pinMode(endButtonPin, INPUT_PULLUP);

  // testing only
  relayPin = LED_BUILTIN;
  
  Serial.begin(9600);

  inactive();
}

// the loop function runs over and over again forever
void loop() {

  int solarValue = analogRead(solarPin);

  // arm
  if(digitalRead(startButtonPin) == LOW){
    armed();
  }

  // go
  if(state == "armed" && digitalRead(startButtonPin) == HIGH){
    go();
  }

  // complete
  if(state == "go" && digitalRead(endButtonPin) == LOW){
    complete();
  }

  // busted
  if(state == "go" && analogRead(solarPin) < solarThreshold){
    busted();
  }
  
  Serial.println(state);
//  Serial.println(solarValue);


}

void inactive() {
  state = "inactive";
  digitalWrite(LED_BUILTIN, LOW);
}

void armed() {
  state = "armed";
//  digitalWrite(LED_BUILTIN, HIGH);

  // TODO: relay turn laser ON
  digitalWrite(relayPin, HIGH);
}

void go() {
  state = "go";
}

void complete() {
  state = "complete";
//  digitalWrite(LED_BUILTIN, LOW);

  // TODO: relay turn laser OFF
  digitalWrite(relayPin, LOW);
}

void busted() {
  state = "busted";
//  digitalWrite(LED_BUILTIN, LOW);

  // TODO: relay turn laser OFF
  digitalWrite(relayPin, LOW);
}
