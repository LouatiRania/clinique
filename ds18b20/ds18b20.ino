
//Include libraries
#include <OneWire.h>
#include <DallasTemperature.h>

char data ;

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 9
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
//const int buzzer = 8;
void setup()
{
  Serial.begin(9600); //Begin serial communication
//  Serial.println("Arduino Digital Temperature // Serial Monitor Version"); //Print a message
  sensors.begin();
    pinMode(7, OUTPUT);
}


void loop(void)
{ 
    // Send the command to get temperatures
 /* sensors.requestTemperatures();  
  //Serial.print("Temperature is: ");
  Serial.println(sensors.getTempCByIndex(0)); // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
  data=sensors.getTempCByIndex(0) ;
  Serial.write(data);
  //Update value every 1 sec.

 /* tone(buzzer,1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec*/
 /* digitalWrite(8, LOW);
  delay(100);*/
  sensors.requestTemperatures();
  double temp = sensors.getTempCByIndex(0);
  if (Serial.available()) { data = Serial.read();} 
  if(data=='x')
  {
    digitalWrite(7, HIGH);
  }
  else if(data=='y')
  {
    digitalWrite(7, LOW);
  }
  Serial.print(temp);
  Serial.print(",");
  Serial.flush();
  delay(500);
}
