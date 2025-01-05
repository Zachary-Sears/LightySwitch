int ledPin = 13;  // LED on Pin 13 of Arduino
int pirPin = DD3; // Input for HC-S501 corresponds to pin D3 on Nano

int pirValue; // Place to store read PIR Value


void setup() {
  
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
 
  digitalWrite(ledPin, LOW);
  
  
  
}

void loop() {
  pirValue = digitalRead(pirPin);
  digitalWrite(ledPin, pirValue);

}
