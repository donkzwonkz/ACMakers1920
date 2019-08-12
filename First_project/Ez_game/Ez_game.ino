#include <SparkFun_ADXL345.h>

void setup() {
  
  //set the sound pins
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);

  //dice rolling function with sound playing
  void rollDice(){
    int k = random(3, 8); //adjust based on the numbers of the pins required
    digitalWrite(k,LOW)
     
    }
}

void loop() {
  //variables to store acceleration
  int x,y,z;
  int accel;
  adxl.readAccel(&x, &y, &z);
  accel = x^2+y^2+z^2;
  if (accel>5){ // nyumber is tentative
    rollDice()
    } 
}
