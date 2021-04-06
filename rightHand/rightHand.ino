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
  Serial.println("Right hand is ready");
}
 
void loop() {
  int shoulderTopDegree = shoulderTop.read();
  int shoulderBottomDegree = shoulderBottom.read();
  int armTopDegree = armTop.read();
  int armBottomDegree = armBottom.read();
  int forearmDegree = forearm.read();
  int fingersTopDegree = fingersTop.read();
  int fingersMidDegree = fingersMid.read();
  int fingersBottomDegree = fingersBottom.read();
  if(Serial.available() == '0'){
    
    shoulderBottomDegree += 15;
    armBottomDegree += 60;
    shoulderBottom.write(shoulderBottomDegree);
    armBottom.write(armBottomDegree);
    
    delay(2500);
    
    fingersMidDegree += 20;
    fingersBottomDegree += 20;
    fingersMid.write(fingersMidDegree);
    fingersBottom.write(fingersBottomDegree);
    
    delay(1000);
    
    fingersMidDegree -= 20;
    fingersBottomDegree -= 20;
    fingersTopDegree += 30;
    fingersTopDegree -= 30;
    fingersMid.write(fingersMidDegree);
    fingersBottom.write(fingersBottomDegree);
    fingersTop.write(fingersTopDegree);
    fingersTop.write(fingersTopDegree);

    forearmDegree -= 60;
    shoulderBottomDegree -= 15;
    forearm.write(forearmDegree);
    shoulderBottom.write(shoulderBottomDegree);

    Serial.println("Arduino response: Handshake action completed");
    
  } else if (Serial.available() == '1') {

    shoulderBottomDegree += 15;
    armBottomDegree += 60;
    forearmDegree += 90;
    shoulderBottom.write(shoulderBottomDegree);
    armBottom.write(armBottomDegree);
    forearm.write(forearmDegree);
    
    delay(2500);
    
    fingersMidDegree += 90;
    fingersBottomDegree += 90;
    fingersMid.write(fingersMidDegree);
    fingersBottom.write(fingersBottomDegree);
    
    delay(1000);
    
    fingersMidDegree -= 90;
    fingersBottomDegree -= 90;
    fingersTopDegree += 30;
    fingersTopDegree -= 30;
    fingersMid.write(fingersMidDegree);
    fingersBottom.write(fingersBottomDegree);
    fingersTop.write(fingersTopDegree);
    fingersTop.write(fingersTopDegree);

    forearmDegree -= 90;
    armBottomDegree -= 60;
    shoulderBottomDegree -= 15;
    forearm.write(forearmDegree);
    armBottom.write(armBottomDegree);
    shoulderBottom.write(shoulderBottomDegree);
    
    Serial.println("Arduino response: Brofist action completed");
    
  } else if (Serial.available() == '2') {
    
    Serial.println("Arduino response: Pathfinder action completed");
    
  } else if (Serial.available() == '3') {
    
    Serial.println("Arduino response: Bye action completed");
    
  } else if (Serial.available() == '4') {
    
    Serial.println("Arduino response: Unknown action completed");
    
  }
}
