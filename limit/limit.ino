/*
  Motorized potentiometer preset homing example

   Controls a motorized potentiometer. If the pot is within range
   of a preset, the motor stops. If the pot goes higher or lower than
   the preset, the motor changes direction to bring the pot back
   to the preset value

   created 27 Feb 2017
   by Tom Igoe
*/
const int motorPin1 = 4;  // pins that the motor is attached to
const int motorPin2 = 5;
const int pwmPin = 3;     // pin for the PWM driver pin
int preset = 512;         // preset for where to stop the motor
int previous = 0;

void setup() {
  Serial.begin(9600);           // initialize serial
  pinMode(motorPin1, OUTPUT);   // set motorPins as outputs
  pinMode(motorPin2, OUTPUT);
  Serial.setTimeout(10);        // 10ms timeout on serial input
}

void loop() {
  if (Serial.available()) {         // if there's serial input
    int input = Serial.parseInt();  // see if it's a numerical string
    if (input != 0) preset = input; // if it's not 0, make it the new preset
  }
  // read the potentiometer:
  int potentiometer = analogRead(A0);
 int motorSpeed = abs(preset - potentiometer);
  analogWrite(pwmPin, 255); // slow down as you approach preset

 digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, HIGH);
    
//  if (previous > potentiometer) {   // if you're above preset, go down
//    digitalWrite(motorPin1, HIGH);
//    digitalWrite(motorPin2, HIGH);
//  }
//  else {                         // if you're below preset, go up
//    digitalWrite(motorPin1, HIGH);
//    digitalWrite(motorPin2, LOW);
//  }
//  previous = potentiometer;

  // print the potentiometer value:
  Serial.println(motorSpeed);
}
