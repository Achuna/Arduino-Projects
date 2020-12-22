#include <IRremote.h>

int RECV_PIN = 11;

int buzzer = 12;//the pin of the active buzzer

IRrecv irrecv(RECV_PIN);

decode_results results;

int redLED = 6;
int greenLED = 7;
int yellowLED = 5;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
   pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);

  pinMode(buzzer,OUTPUT);//initialize the buzzer pin as an output

}

void loop() {
if (irrecv.decode(&results)){
  
    long int decCode = results.value;
    Serial.println(results.value, HEX);
    
    //switch case to use the selected remote control button
    switch (results.value){
      
      case 16724175: //when you press the 1 button
        digitalWrite(greenLED, HIGH);
        digitalWrite(buzzer,HIGH);
          delay(1000);
          digitalWrite(greenLED, LOW);
          digitalWrite(buzzer,LOW);
                  break; 
          
       case 16718055: //when you press the 2 button
        digitalWrite(redLED, HIGH);
        digitalWrite(buzzer,HIGH);
          delay(1000);
          digitalWrite(redLED, LOW);
          digitalWrite(buzzer,LOW);
        break; 

         case 16743045: //when you press the 3 button
        digitalWrite(yellowLED, HIGH);
        digitalWrite(buzzer,HIGH);
          delay(1000);
          digitalWrite(yellowLED, LOW);
          digitalWrite(buzzer,LOW);
        break; 
                  
    }
    irrecv.resume(); // Receives the next value from the button you press
  }
  
}
