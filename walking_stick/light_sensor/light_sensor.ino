
int LED = 13;
int ldr = A0;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(ldr, INPUT);
  

  

}

void loop() {
  // put your main code here, to run repeatedly:

int ldrStatus = analogRead(ldr);

  Serial.println(ldrStatus);
if(ldrStatus < 35) {
  digitalWrite(LED, HIGH);
  
} else {
    digitalWrite(LED, LOW);
}


}
