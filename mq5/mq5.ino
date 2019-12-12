int sensor=A0;
int gas_value;
char data;
void setup()
{

pinMode(sensor,INPUT);
Serial.begin(9600);
 pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{

gas_value= analogRead(sensor);
Serial.print(gas_value);
Serial.print(",");
Serial.flush();
delay(500);
if(Serial.available())  {data=Serial.read();
  if(data=='x')
  {    digitalWrite(5,HIGH);                            
       digitalWrite(6, LOW);
    }else if(data=='y')
    {
              digitalWrite(6,HIGH);
              digitalWrite(5, LOW);
    }
    }



}
