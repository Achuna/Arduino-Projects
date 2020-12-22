int triggerPin = 11;
int echoPin = 10;
int buzzer = 12;


long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
pinMode(triggerPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzer, OUTPUT);

Serial.begin(9600);

}

void loop() {


  
      // put your main code here, to run repeatedly:
    digitalWrite(triggerPin, LOW);
     delayMicroseconds(2);
    
     digitalWrite(triggerPin, HIGH);
     delayMicroseconds(10);
     
     digitalWrite(triggerPin, LOW);
     duration = pulseIn(echoPin, HIGH);
     distance = duration*0.034/2;
    
     Serial.print("Distance (cm): ");
     Serial.println(distance);


    //WAY TOO CLOSE!
    if(distance < 20) { 
      digitalWrite(buzzer, HIGH);
    } 

    //APPROCHING IT
    else if(distance < 40) { 
      digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);
      delay(50);
      digitalWrite(buzzer, HIGH);
    } 
    
    else if(distance < 70) {
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(100);
      digitalWrite(buzzer, HIGH);
    }
    
    else {
    digitalWrite(buzzer, LOW);
    }




}
