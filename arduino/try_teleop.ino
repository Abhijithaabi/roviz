#include <AFMotor.h>
 
#include <string.h>

AF_DCMotor motor1(1, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
AF_DCMotor motor2(2, MOTOR12_64KHZ);

void setup() {
  Serial.begin(115200);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  
  
}
void control_motor1(int speed){
    if(speed > 0){
        motor1.setSpeed(speed);
        motor1.run(FORWARD);
    }
    else if(speed < 0){
        motor1.setSpeed(-speed);
        motor1.run(BACKWARD);}
    else{
        motor1.run(RELEASE);
    
    }
}
void control_motor2(int speed){
    if(speed > 0){
        motor2.setSpeed(speed);
        motor2.run(FORWARD);
    }
    else if(speed < 0){
        motor2.setSpeed(-speed);
        motor2.run(BACKWARD);}
    else{
        motor2.run(RELEASE);
    
    }
}

void loop() {
  static int speed[6];
    static char buff[30];
    int counter = 0;

    // read command from raspberry pi
    while(Serial.available()){
        buff[counter] = Serial.read();
        if (counter > 10 || buff[counter] == '*') {
            buff[counter] = '\0';
            speed[0]=atoi(strtok(buff,","));
           
        }
        else{
            counter++;
        }
    }
    control_motor1(speed[0]);
    
    control_motor2(speed[0]);
    
    Serial.print(speed[0]); Serial.print(",");
    Serial.print(speed[1]); Serial.print(",");
    delay(100);
}
