#include <SoftwareSerial.h>

int adc = A1;

int pulseout1 = 10;
int pulseout2 = 11;

int high_delay = 0;
int low_delay = 0;
int valtime = 0;

int Htime;
  int Ltime;  
    float Ttime;
      float frequency=0.00;  
        int frerec = 8;

   void setup()
{
   Serial.begin(9600);
   Serial.println ("  ");
    pinMode(adc, INPUT);
     pinMode(frerec,INPUT);
      pinMode(pulseout1, OUTPUT);
       pinMode(pulseout2, OUTPUT);

 
  }


void loop()
{
    int in1 = analogRead(adc); // adc value 1023
        valtime = in1 *5 ;  // adc value 1023 *5 = valtime
       
 
           
    int totalpulse  = frequency + valtime ;// frequency + adc value 1023 *5 = valtime
   
        low_delay = totalpulse;
        high_delay = low_delay *5;
       
       Htime=pulseIn(frerec,HIGH);
        Ltime=pulseIn(frerec,LOW);
       
          Ttime = Htime+Ltime+valtime;
            frequency=1000000/Ttime;
 
           
      // Serial.println (valtime);
        // Serial.println (low_delay);
          //  Serial.println (high_delay );
         
        Serial.println (frequency);

     digitalWrite(pulseout1, HIGH);
    delayMicroseconds(high_delay);
    digitalWrite(pulseout1, LOW);
    delayMicroseconds(low_delay);
    digitalWrite(pulseout2, HIGH);
    delayMicroseconds(high_delay);
    digitalWrite(pulseout2, LOW);

    digitalWrite(pulseout2, HIGH);
    delayMicroseconds(high_delay);
    digitalWrite(pulseout2, LOW);
    delayMicroseconds(low_delay);
    digitalWrite(pulseout1, HIGH);
    delayMicroseconds(high_delay);
    digitalWrite(pulseout1, LOW);
           
  }
