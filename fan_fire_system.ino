float t;
int tempPin= A0;
int fire_pin = A1; // select the input pin for the LDR
int fireValue = 205; // variable to store the value coming from the sensor
int buzzer = 2; // Output pin for Buzzer
float mq=A2;
float gas_val=0;
void setup()
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(mq,INPUT);
}

void loop()
{
 Serial.println("fire: " + fireValue);
 Serial.println("gas: " + gas_val);
 fireValue = analogRead(fire_pin);
 gas_val = analogRead(mq);

delay(1000);
  if (fireValue < 200 || gas_val> 500){
  Serial.println("Fire Detected");
  digitalWrite(buzzer,HIGH);
  delay(1000);} 
  else{
  digitalWrite(buzzer,LOW);
  }
  
 t=analogRead(tempPin);
 t=t*0.48828125; //converts temperature
   if (t < 20 ){
  analogWrite(3, 0);
  delay(500);
  }
  else if (t >= 20 && t <= 22){
  analogWrite(3, 51);//Fan Speed: 20%
  delay(500);
  }
  else if (t > 22 && t <= 24) //Fan Speed: 40%
{
  analogWrite(3, 102);
  delay(500);
  }
  else if (t >24 && t <= 26) //Fan Speed: 60%
{
  analogWrite(3, 153);
  delay(500);
  }
 else if (t > 26 && t <= 28)//Fan Speed: 80%
{
  analogWrite(3, 204);
  delay(500);
  }
  else if (t > 28) //Fan Speed: 100%
{
  analogWrite(3, 255);
  delay(500);
  }
}