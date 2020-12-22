int triggerPin = 12;
int echoPin = 11;

int redLED = 6;
int greenLED = 7;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:

  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


//  digitalWrite(redLED, HIGH);
//  digitalWrite(greenLED, HIGH);
  
  

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

 digitalWrite(triggerPin, HIGH);
 delayMicroseconds(10);
 
 digitalWrite(triggerPin, LOW);


 duration = pulseIn(echoPin, HIGH);
 distance = duration*0.034/2;

 Serial.print("Distance (cm): ");
 Serial.println(distance);


 if(distance < 40) {
  //TOO CLOSE
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
 } else {
  digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
 }
 
  
}
