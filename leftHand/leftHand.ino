#include <Servo.h>

int impAction;

Servo shoulderTop;
Servo shoulderBottom;
Servo armTop;
Servo armBottom;
Servo forearm;
Servo fingersTop;
Servo fingersMid;
Servo fingersBottom;

void setup() { 
  Serial.begin(9600);
  shoulderTop.attach(1);
  shoulderBottom.attach(2);
  armTop.attach(3);
  armBottom.attach(4);
  forearm.attach(5);
  fingersTop.attach(6);
  fingersMid.attach(7);
  fingersBottom.attach(8);
  Serial.println("Left hand is ready");
  int shoulderTopDegree = shoulderTop.read();
  int shoulderBottomDegree = shoulderBottom.read();
  int armTopDegree = armTop.read();
  int armBottomDegree = armBottom.read();
  int forearmDegree = forearm.read();
  int fingersTopDegree = fingersTop.read();
  int fingersMidDegree = fingersMid.read();
  int fingersBottomDegree = fingersBottom.read();
}
 
void loop() {
  if(Serial.available() == '0'){
    Serial.println("Arduino response: Handshake action completed");
  } else if (Serial.available() == '1') {
    Serial.println("Arduino response: Brofist action completed");
  } else if (Serial.available() == '2') {
    Serial.println("Arduino response: Pathfinder action completed");
  } else if (Serial.available() == '3') {
    Serial.println("Arduino response: Bye action completed");
  } else if (Serial.available() == '4') {
    Serial.println("Arduino response: Unknown action completed");
  }
}
