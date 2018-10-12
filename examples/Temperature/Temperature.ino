/*
    Temperature.ino

    This example shows how to use the temperature sensor on the 
    platform EL LAB: SLT Board.

    The temperature sensor used is the LM335Z and 
    it's calibrated at 10mV/K.
    
    Calibrated for 2.982V at 25°C.

    Created: October 12th, 2018
    Author: El Lab de Electro: EL LAB
    Modified: -
    Author: -

    URL: https://github.com/EL-LAB/EL-LAB_SLT_Board_Arduino_Examples
*/


unsigned int temperatureReading;    // The analog reading from sensor

void setup()
{
  Serial.begin(9600);   
    
  Serial.print("TEMPERATURE\t");
  Serial.println("VOLTS");
  Serial.println("------------------------------------------");
}
 
void loop()
{
  temperatureReading = analogRead(2); // A2 analog pin
    
  double volts = (temperatureReading * 5.0) / 1024;  // Convert to volts
  double tempKelvin =  volts * 100;                  // Temperature in Kelvin (10mV/K)
  double tempCelsius = tempK - 273.15;               // Temperature in Celsius 
 
  // Prints output message
  Serial.print(tempCelsius);
  Serial.print("\t");
  Serial.println(volts);
 
  delay(1000);
}
