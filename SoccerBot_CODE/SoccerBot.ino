//PIN NUMBER FOR MOTOR DRIVERS
  //left
    int left_IN1 = 8;
    int left_IN2 = 9;
    int left_IN3 = 13;
    int left_IN4 = 12;
  //right  
    int right_IN1 = 3;
    int right_IN2 = 2;
    int right_IN3 = 7;
    int right_IN4 = 4;
  /*pwm control
    int leftFront_pwm = 10;
    int leftBack_pwm = 11;
    int rightFront_pwm = 5;
    int rightBack_pwm = 6; */
//WHEEL DIRECTION REFERENCE
  //left wheel
    int leftFront_Forward = left_IN3;
    int leftFront_Reverse = left_IN4;
    int leftBack_Forward = left_IN1;
    int leftBack_Reverse = left_IN2;
  //right wheel
    int rightFront_Forward = right_IN2;
    int rightFront_Reverse = right_IN1;
    int rightBack_Forward = right_IN3;
    int rightBack_Reverse = right_IN4;

void setup() {
  pinMode(left_IN1,OUTPUT);
  pinMode(left_IN2,OUTPUT);
  pinMode(left_IN3,OUTPUT);
  pinMode(left_IN4,OUTPUT);
  pinMode(right_IN1,OUTPUT);
  pinMode(right_IN2,OUTPUT);
  pinMode(right_IN3,OUTPUT);
  pinMode(right_IN4,OUTPUT);
  /*pinMode(leftFront_pwm,OUTPUT);
  pinMode(leftBack_pwm,OUTPUT);
  pinMode(rightFront_pwm,OUTPUT);
  pinMode(rightBack_pwm,OUTPUT);*/
  Serial.begin(9600);
}


void leftForward () {
  digitalWrite(leftFront_Forward, HIGH);
  digitalWrite(leftBack_Forward, HIGH);
}

void leftReverse () {
  digitalWrite(leftFront_Reverse,HIGH);
  digitalWrite(leftBack_Reverse,HIGH);
}

void rightReverse () {
  digitalWrite(rightFront_Reverse,HIGH);
  digitalWrite(rightBack_Reverse,HIGH);
}

void rightForward () {
  digitalWrite(rightFront_Forward, HIGH);
  digitalWrite(rightBack_Forward, HIGH);
}

void forward () {
  leftForward();
  rightForward();
}

void reverse () {
  leftReverse();
  rightReverse();
}

void leftOff () {
  digitalWrite(left_IN1,LOW);
  digitalWrite(left_IN2,LOW);
  digitalWrite(left_IN3,LOW);
  digitalWrite(left_IN4,LOW);
}

void rightOff () {
  digitalWrite(right_IN1,LOW);
  digitalWrite(right_IN2,LOW);
  digitalWrite(right_IN3,LOW);
  digitalWrite(right_IN4,LOW);
}

void carStop () {
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
}

void loop() {
  char input;
  if (Serial.available()>0) {
    input = Serial.read();
    /*int pwm;
    if (input=='1') {
      pwm = 26;
      analogWrite(leftFront_pwm,pwm);
      analogWrite(leftBack_pwm,pwm);
      analogWrite(rightFront_pwm,pwm);
      analogWrite(rightBack_pwm,pwm);
    } else if (input=='2') {
      pwm = 51;
      analogWrite(leftFront_pwm,pwm);
      analogWrite(leftBack_pwm,pwm);
      analogWrite(rightFront_pwm,pwm);
      analogWrite(rightBack_pwm,pwm);
    } else if (input=='3') {
      pwm = 77;
      analogWrite(leftFront_pwm,pwm);
      analogWrite(leftBack_pwm,pwm);
      analogWrite(rightFront_pwm,pwm);
      analogWrite(rightBack_pwm,pwm);
    } else if (input=='4') {
      pwm = 102;
      analogWrite(leftFront_pwm,pwm);
      analogWrite(leftBack_pwm,pwm);
      analogWrite(rightFront_pwm,pwm);
      analogWrite(rightBack_pwm,pwm);
    } else if (input=='5') {
      pwm = 128;
      analogWrite(leftFront_pwm,pwm);
      analogWrite(leftBack_pwm,pwm);
      analogWrite(rightFront_pwm,pwm);
      analogWrite(rightBack_pwm,pwm);
    } else if (input=='6') {
      pwm = 153;
      analogWrite(leftFront_pwm,pwm);
      analogWrite(leftBack_pwm,pwm);
      analogWrite(rightFront_pwm,pwm);
      analogWrite(rightBack_pwm,pwm);
    } else if (input=='7') {
      pwm = 179;
      analogWrite(leftFront_pwm,pwm);
      analogWrite(leftBack_pwm,pwm);
      analogWrite(rightFront_pwm,pwm);
      analogWrite(rightBack_pwm,pwm);
    } else if (input=='8') {
      pwm = 204;
      analogWrite(leftFront_pwm,pwm);
      analogWrite(leftBack_pwm,pwm);
      analogWrite(rightFront_pwm,pwm);
      analogWrite(rightBack_pwm,pwm);
    } else if (input=='9') {
      pwm = 230;
      analogWrite(leftFront_pwm,pwm);
      analogWrite(leftBack_pwm,pwm);
      analogWrite(rightFront_pwm,pwm);
      analogWrite(rightBack_pwm,pwm);
    } else if (input=='q') {
      pwm = 255;
      analogWrite(leftFront_pwm,pwm);
      analogWrite(leftBack_pwm,pwm);
      analogWrite(rightFront_pwm,pwm);
      analogWrite(rightBack_pwm,pwm);
    } */
    if (input=='S') {
      carStop();
    } else if (input=='F') {
      forward();
    } else if (input=='B') {
      reverse();
    } else if (input=='L') {
      leftReverse();
      rightForward();
    } else if (input=='R') {
      rightReverse();
      leftForward();
    } else if (input=='G') {
      rightForward();
      leftOff();
    } else if (input=='I') {
      leftForward();
      rightOff();
    } else if (input=='H') {
      rightReverse();
      leftOff();
    } else if (input=='J') {
      leftReverse();
      rightOff();
    } else {
      carStop();
    }
    Serial.println(input);
  }
}
