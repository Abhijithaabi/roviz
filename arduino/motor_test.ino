#include <AFMotor.h>

AF_DCMotor motor(2, MOTOR12_64KHZ); 

AF_DCMotor motor1(1, MOTOR12_64KHZ);
// create motor #2, 64KHz pwm


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  
  motor.setSpeed(200);
  // set the speed to 200/255
  motor1.setSpeed(200);
}

void loop() {
  Serial.print("tick");
  
  motor.run(FORWARD); 
  motor1.run(FORWARD);
  // turn it on going forward
  delay(1000);

//  Serial.print("tock");
//  motor.run(BACKWARD);     // the other way
//  delay(1000);
//  
//  Serial.print("tack");
//  motor.run(RELEASE);      // stopped
//  delay(1000);
}
 
