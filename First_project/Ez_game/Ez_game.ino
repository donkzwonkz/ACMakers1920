#include <SparkFun_ADXL345.h>
ADXL345 adxl = ADXL345();             // USE FOR I2C COMMUNICATION
int cheating = 1;

void setup() {
  //adjust tol for tolerance values
#define tol 25

  //set the sound pins
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10,OUTPUT);
  //Setup the accelerometer
  Serial.begin(9600);                 // Start the serial terminal
  Serial.println("Dice Initialised");
  Serial.println();

  for (int i = 0; i <= 7; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(10 ,HIGH);
}

//dice rolling function with sound playing
void rollDice(int cht) {
  for (int i = 0; i <= 7; i++) {
    digitalWrite(i, LOW);
  }
  int k;

  switch (cht) {
    case 1:  k = 4;
      cht = cht++;
      digitalWrite(k, HIGH);
      Serial.println(k);
      delay(1000);
    case 2:  k = 3;
      cht = cht++;
      digitalWrite(k, HIGH);
      Serial.println(k);
      delay(1000);
    case 3:  k = 6; cht = cht++;
      digitalWrite(k, HIGH);
      Serial.println(k);
      delay(1000);
    case 4:  k = 2; cht = cht++;
      digitalWrite(k, HIGH);
      Serial.println(k);
      delay(1000);
    case 5:  k = 7; cht = cht++;
      digitalWrite(k, HIGH);
      Serial.println(k);
      delay(1000);
    case 6:  k = 5; cht = cht++;
      digitalWrite(k, HIGH);
      Serial.println(k);
      delay(1000);
    default: k = random(2, 8); digitalWrite(k, HIGH);
      Serial.println(k);
      delay(1000);//adjust based on the numbers of the pins required
  }
  return cht;

  //k = random(2, 8);
  //digitalWrite(k,HIGH);
  //Serial.println(k);
  //delay(1000);
}

void loop() {
  //variables to store acceleration
  int x, y, z;
  int accel;


  //handle accel data
  adxl.readAccel(&x, &y, &z);

  //determine whether to roll the dice and do it
  accel = sqrt(x ^ 2 + y ^ 2 + z ^ 2); //gets the magnitude of acceleration
  if (accel > tol) {
    rollDice(cheating);
  }
}
