/*
  Stepper Motor Control - one revolution

  This program drives a unipolar or bipolar stepper motor.
  The motor is attached to digital pins 8 - 11 of the Arduino.

  The motor should revolve one revolution in one direction, then
  one revolution in the other direction.

*/

#include <Stepper.h>

int ledPin = 13;  // LED on Pin 13 of Arduino
int pirPin = DD3; // Input for HC-S501 corresponds to pin D3 on Nano
int pirValue; // Place to store read PIR Value

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int rolePerMinute = 5;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm

const bool postDelay = true;

// initialize the stepper library on pins
Stepper motor(stepsPerRevolution, 5, 6, 9, 10);

void setup() {
  motor.setSpeed(rolePerMinute);
  // initialize the serial port:
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
 
  digitalWrite(ledPin, LOW);
}

void loop() {  
  pirValue = digitalRead(pirPin);
  digitalWrite(LED_BUILTIN, pirValue);
  //TODO use a real time clock to 
  if(pirValue && postDelay){
    //TODO determine how far the motor needs to move in each direction
    motor.step(50);
    delay(100);
    //TODO fix motor not going in reverse
    motor.step(-50);
  }
}
