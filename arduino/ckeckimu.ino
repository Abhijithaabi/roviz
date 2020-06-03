
#include <MPU6050.h>

#include <Wire.h>

#include <I2Cdev.h>
MPU6050 accelgyro(0x68);




void setup() {
  Serial.begin(115200);
  Setup_MPU6050();

}
void Setup_MPU6050()
{
  

  Wire.begin();
  Serial.println("initializing i2c devices....");
  accelgyro.initialize();
  Serial.println("testing device connections....");
  Serial.println(accelgyro.testConnection() ? "mpu6050 connection successfull...." : "mpu6050 connection failed");
}

void loop() {
  updatempu6050();
  
  

}
void updatempu6050()
{
  int16_t ax,ay,az;
  int16_t gx,gy,gz;
  accelgyro.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);
  Serial.print("ax=");
  Serial.print(ax);
  Serial.print("\t");
  Serial.print("ay=");
  Serial.print(ay);
  Serial.print("\t");
  Serial.print("az=");
  Serial.print(az);
  Serial.print("\t");
  Serial.print("gx=");
  Serial.print(gx);
  Serial.print("\t");
  Serial.print("gy=");
  Serial.print(gy);
  Serial.print("\t");
  Serial.print("gz=");
  Serial.println(gz);
  Serial.print("\n");
  delay(2000);
  
}
