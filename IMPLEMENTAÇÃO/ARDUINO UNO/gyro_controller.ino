#include <Wire.h>

const int MPU1=0x68;
int16_t AcX1, AcZ1, AcY1, Tmp1, GyX1,GyY1,GyZ1;

int data;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.beginTransmission(MPU1);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  GetMpuValue1(MPU1);

  sentunity();
}

void GetMpuValue1(const int MPU){
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,14,true);

  AcX1 = Wire.read()<<8| Wire.read();
  AcZ1 = Wire.read()<<8| Wire.read();
  AcY1 = Wire.read()<<8| Wire.read();
  Tmp1 = Wire.read()<<8| Wire.read();
  GyX1 = Wire.read()<<8| Wire.read();
  GyY1 = Wire.read()<<8| Wire.read();
  GyZ1 = Wire.read()<<8| Wire.read();
}

void sentunity(){
  if (Serial.available()){
    data = Serial.read();
    if (data == 'a'){
      Serial.println(AcX1);
    }
    if (data == 'b'){
      Serial.println(AcY1);
    }
    if (data == 'c'){
      Serial.println(AcZ1);
    }
    if (data == 'd'){
      Serial.println(GyX1);
    }
    if (data == 'e'){
      Serial.println(GyY1);
    }
    if (data == 'f'){
      Serial.println(GyZ1);
    }
  }
}
