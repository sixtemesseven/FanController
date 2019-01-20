const int maxTemp = 85;
const int minTemp = 20;
const int minFan = 30;
const int maxFan = 100;
const int firstADC = 1;
const int lastADC = 1;
const int rxPin = 1;
const int txPin = 0;
const int pwmPin = 0;
const int averageFilterSamples = 20;
int getHighTemperature(int firstADC, int lastADC, int filter);
void setFan(int percent);


void setup() 
{
}


void loop() 
{
  analogRead(A0);
  analogWrite(pwmPin,10);
  /*
  int temp = 0;
  temp = getHighTemperature(firstADC, lastADC, averageFilterSamples);
  if(temp < minTemp)
  {
    setFan(0, pwmPin);
  }
  else
  {
    setFan(((maxFan - minFan) / (maxTemp - minTemp) * temp), pwmPin);
  } */
}


void setFan(int percent, int pin)
{
  if(percent < minFan)
  {
    analogWrite(pin, 0);
  }
  else
  {
  analogWrite(pin, ((maxFan * 255 / 100) * percent / 100));
  }
}


int getHighTemperature(int firstADC, int lastADC, int filter)
{ 
  int largest = 0;
  int filterT[4] = {0};
  for(int i = 0; i < filter; i++)
  {
    for(int adc = firstADC; adc <= lastADC; adc++)
    {
      float temp;
      temp = analogRead(adc)*5/1024.0;
      temp = temp - 0.5;
      temp = temp / 0.01;
      filterT[adc] += int(temp);
      delay(10);
    }
  }
  for(int adc = firstADC; adc <= lastADC; adc++)
  {
    filterT[adc] = filterT[adc] / filter;
  }
  for(int adc = firstADC; adc <= lastADC; adc++)
  {
    if(largest < filterT[adc])
    {
      largest = filterT[adc];
    }
  }
  return largest;
}
