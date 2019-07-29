//Testin the serial communication

void setup() {
  Serial.begin(9600);
}

void loop() {
  int input;
  input = Serial.read();
  if (Serial.available()>0) {
    Serial.read();
    Serial.println((char)input);
  }
}
