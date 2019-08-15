void setup() {
  // put your setup code here, to run once:
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
  
Serial.begin(9600);                 // Start the serial terminal
  Serial.println("Dice Initialised");
  Serial.println();
  
for(int i=0;i<=9;i++){digitalWrite(i,LOW);}

int k = random(2, 8); //adjust based on the numbers of the pins required
digitalWrite(k,HIGH);
Serial.println(k);
delay(1000);

}
void loop() {
  // put your main code here, to run repeatedly:

}
