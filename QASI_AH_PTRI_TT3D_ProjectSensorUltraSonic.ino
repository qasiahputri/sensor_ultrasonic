const int pingPin=7;
const int echoPin=6;
const int ledPin=13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  long duration;
  long cm;
  pinMode(pingPin,OUTPUT);
  digitalWrite(pingPin,LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin,LOW);

  pinMode(echoPin,INPUT);
  duration=pulseIn(echoPin,HIGH);
  cm=microsecondsToCentimeters(duration);

  if(cm<=200)
  {
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
}

  long microsecondsToCentimeters(long microseconds)
  {
  return microseconds*0.034/2;
  }


