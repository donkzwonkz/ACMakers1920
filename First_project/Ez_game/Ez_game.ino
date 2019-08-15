#include <SparkFun_ADXL345.h>
ADXL345 adxl = ADXL345();             // USE FOR I2C COMMUNICATION

void setup() {
  //adjust tol for tolerance values
  #define tol 25
  
  //set the sound pins
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  
  //Setup the accelerometer
  Serial.begin(9600);                 // Start the serial terminal
  Serial.println("Dice Initialised");
  Serial.println();

  for(int i=0;i<=9;i++){digitalWrite(i,LOW);}

}

//dice rolling function with sound playing
void rollDice(){
for(int i=0;i<=9;i++){digitalWrite(i,LOW);}

int k = random(2, 8); //adjust based on the numbers of the pins required
digitalWrite(k,HIGH);
Serial.println(k);
delay(1000);
}
    
void loop() {
  //variables to store acceleration
  int x,y,z;
  int accel;

    
  //handle accel data
  adxl.readAccel(&x, &y, &z);

  //determine whether to roll the dice and do it
  accel = sqrt(x^2+y^2+z^2); //gets the magnitude of acceleration
  if (accel>tol){
    rollDice();
  }
}
