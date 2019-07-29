//Testin the motor driver if it is working or not by connecting pin 4 of arduino with IN1~4 pins on the driver

void setup() {
  pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(4, HIGH);
}
