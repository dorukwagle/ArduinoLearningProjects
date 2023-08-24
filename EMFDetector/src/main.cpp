#include <Arduino.h>
#include "dht_nonblocking.h"
#include "LiquidCrystal.h"

#define PROBE 2
#define THERMISTER 0
#define DHT_SENSOR 2
#define LCD_CONTRAST 5
#define LCD_BRIGHTNESS 6

#define DHT_SENSOR_TYPE DHT_TYPE_11

DHT_nonblocking dht_sensor(DHT_SENSOR, DHT_SENSOR_TYPE);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int emf = 0;


float readThermister() {
  int tempReading = analogRead(THERMISTER);
  // This is OK
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK)) * tempK); //  Temp Kelvin
  return tempK - 273.15; // temperature in celcius
}

static bool measure_environment(float *temperature, float *humidity)
{
  static unsigned long measurement_timestamp = millis();

  /* Measure once every four seconds. */
  if (millis() - measurement_timestamp > 3000ul)
  {
    if (dht_sensor.measure(temperature, humidity) == true)
    {
      measurement_timestamp = millis();
      return (true);
    }
  }

  return (false);
}

void setup()
{
  lcd.begin(16, 2);
  analogWrite(LCD_CONTRAST, 0);
  analogWrite(LCD_BRIGHTNESS, 50);
}

void loop()
{
  float temprTemp;
  float humidityTemp;
  int temperature;
  int humidity;
  int tempr;

  lcd.clear();
  
  if (measure_environment(&temprTemp, &humidityTemp) == true)
  {
    temperature = (int) temprTemp;
    humidity = (int) humidityTemp;
  }

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print(" C, H:");
  lcd.print(humidity);
  lcd.print("%");

  lcd.setCursor(0, 1);
  tempr = readThermister();
  emf = analogRead(PROBE);
  lcd.print("Tmp:");
  lcd.print(tempr);

  emf = constrain(emf, 1, 100);    
  lcd.print(" EMF:");
  lcd.print(emf);
  
  delay(1000);
}