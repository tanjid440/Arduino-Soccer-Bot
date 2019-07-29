int blue = 12, red = 13, buzzer = 8;
int led = 0;
void setup() {
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  //pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()>0) {
    led = Serial.read();
    Serial.println((char)led);
    if ((char)led=='B') {
      digitalWrite(blue, HIGH);
    }
  } else if ((char)led=='b') {
    digitalWrite(blue, LOW);
  } else if ((char)led=='R') {
    digitalWrite(red, HIGH);
  } else if ((char)led=='r') {
    digitalWrite(red, LOW);
  }
  
}
