#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
#include <SimpleTimer.h>
 
WidgetLCD lcd(V2);
String data;
char auth[] = "BdUOdvJd6Ml9XWzLdZJQM8GKa3D9P3MB";
 
char ssid[] = "mohua";
char pass[] = "12345678";
 
SimpleTimer timer;
 
String myString;
char rdata;
 
int firstVal;
int sdata;
int clflag = 0;

void myTimerEvent()
{

  Blynk.virtualWrite(V2, millis() / 1000);
 
}
 
 
void setup()
{
  Serial.begin(9600);
 
  Blynk.begin(auth, ssid, pass);
 
    timer.setInterval(1000L,sensorvalue1);
 
}
 
void loop(){


   if (Serial.available() == 0 )
   {
  Blynk.run();
  timer.run();
   }
   
  if (Serial.available() > 0 )
  {
    rdata = Serial.read();
    myString = myString+ rdata;
   Serial.print(rdata);
    if( rdata == '\n')
    {
String l = getValue(myString, ',', 0);
firstVal = l.toInt();
  myString = "";
    }
  }
 
}
 
void sensorvalue1()
{
sdata = firstVal;
data = data + sdata;

 if ( (sdata < 99)&& (clflag == 0))
 {
    lcd.clear();
    //lcd.print(0,0,"Frequency:");
   // lcd.print(11,0,data);
   // lcd.print(0,1,"ElectroniClinic");
     lcd.clear();
    lcd.print(0,0,"Frequency meter:");
     lcd.print(6,1,"Hz");
     lcd.print(0 ,1,data);
    clflag = 1;
 }
 
  if ( (sdata > 100)&& (clflag == 1))
 {
    lcd.clear();
    lcd.print(0,0,"Frequency meter:");
   
     lcd.print(6,1,"Hz");
     lcd.print(0 ,1,data);
    clflag = 0;
 }
 
 lcd.print(11,0,data);
 data = "";
 
}

String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;
 
    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
