#include <Servo.h>
#include <Keypad.h>
Servo ServoMotor;
char* password = "953";  // change the password here, pick any 3 numbers
int position = 0;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte rowPins[ROWS] = { 9, 8, 7, 6 };
byte colPins[COLS] = { 5, 4, 3, 2 };
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int led1 = 12;                // the pin that the LED is atteched to

int sensor = 10;            // the pin that the sensor is atteched to
int state = LOW;         // by default, no motion detected
int val = 0;                  // variable to store the sensor status (value)
bool isOpen = false;
void setup()
{
ServoMotor.attach(11);
LockedPosition(true);
Serial.begin(9600);
pinMode(led1, OUTPUT);      // initalize LED as an output
pinMode(sensor, INPUT);    // initialize sensor as an input 
}

void loop()
{
char key = keypad.getKey();
if(key){
  Serial.println(key);
}
  if (key == '*' || key == '#')
{
position = 0;
LockedPosition(true);
}
if (key == password[position])
{
position ++;
}
if (position == 3)
{
LockedPosition(false);
isOpen = true;
}
delay(100);
Serial.println(isOpen);

if(isOpen == true){
val = digitalRead(sensor); 
Serial.println(val);// read sensor value
if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led1, HIGH);   // turn LED ON
    delay(5000);
    val=0;
} 
else if((val == LOW)){
    digitalWrite(led1, LOW); // turn LED OFF
    delay(1000);             // delay 200 milliseconds 
      
  }
}
}

void LockedPosition(int locked)
{
if (locked)
{
ServoMotor.write(11);
}
else
{
ServoMotor.write(90);
}
}