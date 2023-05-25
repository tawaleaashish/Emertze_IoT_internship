#include "temperature_system.h"
#include "Arduino.h"
#include "main.h"


void init_temperature_system(void)
{
  //to config heater and cooler pins output
  pinMode(HEATER,OUTPUT);
  pinMode(COOLER,OUTPUT);
  //to turn OFF heater and cooler
  digitalWrite(HEATER,LOW);
  digitalWrite(COOLER,LOW);
}

float read_temperature(void)
{
  float temperature;
  //voltage to temperature 
  temperature=(((analogRead(TEMPERATURE_SENSOR)*(float)5/1024))/(float)0.01); 
  return temperature;
}
//function to control the cooler
void cooler_control(bool control)
{
  if(control)
  {
    digitalWrite(COOLER,HIGH);
  }
  else
  {
    digitalWrite(COOLER,LOW);
  }
}
//function to control the heater
void heater_control(bool control)
{
  if(control)
  {
    digitalWrite(HEATER,HIGH);
  }
  else
  {
    digitalWrite(HEATER,LOW);
  }
}
