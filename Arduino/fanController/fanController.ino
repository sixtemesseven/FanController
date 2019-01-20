#include <SoftwareSerial.h>

int fanPwmPin = 0;
int fanMin = 50;
int fanMax = 200;
float scale = 0.3;

float getTemperature(int pin, int average);

#define rxPin 1
#define txPin 0
#define pwmPin 0


// set up a new serial port
//SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);

void setup() {

  pinMode(pwmPin, OUTPUT);
}

void loop() {
  //mySerial.print("Hello Attiny85");
  //delay(100);

  analogWrite(pwmPin,255);
  /*
  float temp1 = getTemperature(A1, 100);
  int fan = int(temp1 * scale);
  if(fan < fanMin)
  {
    fan = fanMin;
  }
  if(fan > fanMax)
  {
    fan = fanMax;
  } 
  analogWrite(fanPwmPin, fan);
  delay(1000);
  */
}


float getTemperature(int pin, int average)
{
  int raw = 0;
  for(int i = 0; i < average; i++)
  {
    raw += analogRead(pin);
    delay(5);
  }
  return(float(raw)/average);
}
