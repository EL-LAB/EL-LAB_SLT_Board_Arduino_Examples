/*
    Sound.ino

    This example shows how to use the sound sensor on the 
    platform EL LAB: SLT Board.

    The sound sensor used is a standard PCB mount microphone.
    
    To adjust when the LED turns on based on audio input:
      Perform several experiments by clapping, snapping, blowing, 
      door slamming, knocking etc and see where the resting noise 
      level is and where the loud noises are. Adjust the if statement 
      according to your findings.
      
      You can also adjust how long you take samples for by updating the "SampleWindow"
      
    This code has been adapted from the Electret Mic Breakout Board Hookup Guide
    example from SparkFun.

    Created: October 12th, 2018
    Author: El Lab de Electro: EL LAB
    Modified: -
    Author: -

    URL: https://github.com/EL-LAB/EL-LAB_SLT_Board_Arduino_Examples
*/


const int sampleWindow = 250; // Sample window width in mS (250 mS = 4Hz)
unsigned int sound;
int ledPin = 13;

void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
    
  Serial.print("SOUND\t");
  Serial.println("VOLTS");
  Serial.println("------------------------------------------");
}

void loop() 
{
 unsigned long start = millis();  // Start of sample window
 unsigned int peakToPeak = 0;     // Peak-to-peak level

 unsigned int signalMax = 0;
 unsigned int signalMin = 1024;

 // Collect data for 250 miliseconds
 while (millis() - start < sampleWindow)
 {
   sound = analogRead(0);
      if (sound < 1024)  //This is the max of the 10-bit ADC so this loop will include all readings
      {
         if (sound > signalMax)
         {
           signalMax = sound;  // Save only the max levels
         }
      else if (sound < signalMin)
         {
           signalMin = sound;   // Save only the min levels
         }
     }
 }
    
 peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
 
 double volts = (peakToPeak * 3.3) / 1024;  // Convert to volts
 
if (volts >= 1.0)
{
  // Turns LED on and prints output message
  digitalWrite(ledPin, HIGH);
  Serial.print("Sound detected\t");
  Serial.println("volts");
}
else
{
  //turn LED off
  digitalWrite(ledPin, LOW);
}             
}
