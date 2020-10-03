#include <pitches.h>

#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); // RX | TX

int buzzerPin = 9;
int inputPin = 2; 
int pirPin =2 ;

// choose the input pin (for PIR sensor)
        // we start, assuming no motion detected
                 // variable for reading the pin status
       //Set up a speaker on a PWM pin (digital 9, 10, or 11)
void setup() {
 
   pinMode(inputPin, INPUT);     // declare sensor as input
   //pinMode(pirPin, INPUT);
   //pinMode(buzzerPin,OUTPUT);   
 // digitalWrite(buzzerPin,LOW); 
  
  Serial.begin(9600);
  BTSerial.begin(9600);
 }

void loop() {


int valPIR=digitalRead(inputPin);
BTSerial.write(200);
BTSerial.write(valPIR);


if(BTSerial.available())
{
  //  tone(buzzerPin, 10000, 1000);
  noTone(buzzerPin);
  digitalWrite(buzzerPin,LOW); 
  int moving = digitalRead(inputPin);
 
 Serial.println("重新感應");
  if (moving ==1) 
  {            // check if the input is HIGH


      Serial.println("偵測到物體接近!");
      //  digitalWrite(buzzerPin, HIGH);
        tone(buzzerPin, 800, 5000);
        delay(800);
       
    
    //    noTone(buzzerPin);
     
       Serial.println("閉嘴");
   
    
   // digitalWrite(buzzerPin, LOW);
  // noTone(buzzerPin);

   
    }

    
   else if (moving==0 )
  {
     //  pinMode(buzzerPin, OUTPUT);
      Serial.println("目前無偵測!");
     //  noTone(buzzerPin);
     tone(buzzerPin, 20000, 10000);
    //  tone(buzzerPin, 1000);
     //noTone(buzzerPin);
         
      

    }
    else {
      Serial.println("錯誤");
      
      }


}
Serial.flush(); 
Serial.println("ㄏ");
delay(1000);
}


  



  



 

