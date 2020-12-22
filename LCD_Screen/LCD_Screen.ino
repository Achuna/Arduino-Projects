#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int triggerPin = 10;
int echoPin = 9;

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

  lcd.begin(16, 2);
  
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


//  digitalWrite(redLED, HIGH);
//  digitalWrite(greenLED, HIGH);

  lcd.setCursor(0, 0);
  delay(250);
  

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

 digitalWrite(triggerPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(triggerPin, LOW);


 duration = pulseIn(echoPin, HIGH);
 distance = duration*0.034/2;

 Serial.print("Distance (cm): ");
 Serial.println(distance);

 lcd.clear();
 lcd.print("Distance: ");
 lcd.print(distance);


 if(distance < 80) {
  //TOO CLOSE
   lcd.clear();
 lcd.print("GET AWAY FOOL!");
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
 } else {
  digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
 }
 
  
}
