/*
    Light.ino

    This example shows how to use the light sensor on the 
    platform EL LAB: SLT Board.

    The light sensor used is a standard LDR (photoresistor).

    Created: October 12th, 2018
    Author: El Lab de Electro: EL LAB
    Modified: -
    Author: -

    URL: https://github.com/EL-LAB/EL-LAB_SLT_Board_Arduino_Examples
*/


unsigned int photocellReading; // The analog reading from LDR

void setup() 
{
  Serial.begin(9600);
    
  Serial.print("LIGHT LEVEL\t");
  Serial.println("VOLTS");
  Serial.println("------------------------------------------");
    
}

void loop() 
{
  photocellReading = analogRead(1); // A1 analog pin
    
  double volts = (photocellReading * 5.0) / 1024;  // Convert to volts
    
// Light level detected
  if (photocellReading < 10) 
  {
    // Prints output message
     Serial.println("Very bright\t");
     Serial.println(volts);
  }
  else if (photocellReading < 200) 
  {
    // Prints output message
    Serial.println("Bright\t");
    Serial.println(volts);
  }
  else if (photocellReading < 500) 
  {
    // Prints output message
    Serial.println("Light\t");
    Serial.println(volts);
  } 
  else if (photocellReading < 800) 
  {
    // Prints output message
    Serial.println("Very Dim\t");
    Serial.println(volts);
  } 
  else 
  {
    // Prints output message
    Serial.println("Dark\t");
    Serial.println(volts);
  }
    
  delay(500);
}
