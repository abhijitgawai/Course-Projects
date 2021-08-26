int LevelSensorVal = 0;
int LM35 = A1;
int echoPin = 0;
int forcePin =A2;
int Forcevalue =0;


int triggerPin = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(5, OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(forcePin, INPUT);
}

void loop()
{
  echoPin = 3;
  triggerPin = 2;
int value = analogRead(LM35);
Forcevalue=analogRead(forcePin);

float Temperature = value;
  LevelSensorVal = 0.01723 * readUltrasonicDistance(2, 3);
  Serial.println("Level Control System");
  Serial.println(LevelSensorVal);
  if (LevelSensorVal <= 40 && Temperature > 45) {
    Serial.println("Tank is FULL");
Serial.println("Temperature greater than 45");
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    tone(5, 19, 1000); // play tone 3 (D#0 = 19 Hz)
digitalWrite(12,LOW);
digitalWrite(13,HIGH);
if(Forcevalue<4){
Serial.println("Pressure should be greater than 3");
Serial.println("Current pressure reading is ");
Serial.println(Forcevalue);
}
if(Forcevalue>3){
Serial.println("Optimal pressure");
Serial.println("Current pressure reading is ");
Serial.println(Forcevalue);
}
  }

if (LevelSensorVal > 150 && Temperature > 45 && LevelSensorVal<250) {
    Serial.println("Tank is Less than Half Filled");
Serial.println("Temperature Greater than 45");
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    tone(5, 19, 1000); // play tone 3 (D#0 = 19 Hz)
digitalWrite(12,LOW);
digitalWrite(13,HIGH);
if(Forcevalue<4){
Serial.println("Optimal pressure");
Serial.println("Current pressure reading is ");
Serial.println(Forcevalue);
}
if(Forcevalue>3){
Serial.println("Pressure should be less than 4");
Serial.println("Current pressure reading is ");
Serial.println(Forcevalue);
}
  }
if (LevelSensorVal <= 40 && Temperature < 45) {
    Serial.println("Tank is FULL");
Serial.println("Temperature LESSER than 45");
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    tone(5, 19, 1000); // play tone 3 (D#0 = 19 Hz)
digitalWrite(12,HIGH);
digitalWrite(13,HIGH);
Serial.println("Pressure value is 0");
  }
  if (LevelSensorVal >= 300 && Temperature>45) {
    Serial.println("TEMPERATURE IS GREATER THAN 45 BUT THE Tank is EMPTY");
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
digitalWrite(12,HIGH);
digitalWrite(13,HIGH);
Serial.println("Pressure value is 0");
  }
if (LevelSensorVal >= 300 && Temperature<45) {
    Serial.println("TEMPERATURE IS LESSER THAN 45 AND THE Tank is EMPTY");
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
digitalWrite(12,HIGH);
digitalWrite(13,HIGH);
Serial.println("Pressure value is 0");
  }

  delay(10); // Delay a little bit to improve simulation performance
}