/*
  Stepper Motor Control - one revolution

  This program drives a unipolar or bipolar stepper motor.
  The motor is attached to digital pins 8 - 11 of the Arduino.

  The motor should revolve one revolution in one direction, then
  one revolution in the other direction.

*/

#include <Stepper.h>

int ledPin = 13;  // LED on Pin 13 of Arduino
int motionPin = DD3; // Input for HC-S501 corresponds to pin D3 on Nano
int isMotionDetected; // Place to store read PIR Value

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int rolePerMinute = 5;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm

const bool isDelayDone = true;

// initialize the stepper library on pins
Stepper motor(stepsPerRevolution, 5, 6, 9, 10);

void setup() {
  motor.setSpeed(rolePerMinute);
  // initialize the serial port:
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  pinMode(motionPin, INPUT);
 
  digitalWrite(ledPin, LOW);
}

void loop() {  
  isMotionDetected = digitalRead(motionPin);
  digitalWrite(LED_BUILTIN, isMotionDetected);
  if(isMotionDetected && isDelayDone){
    //TODO determine how far the motor needs to move in each direction
    motor.step(100);
    delay(100);
    //TODO fix motor not going couterclockwise
    motor.step(-100);
  }
}
