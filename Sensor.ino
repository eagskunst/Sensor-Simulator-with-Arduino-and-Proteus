const int trigger = 22;
const int echo = 23;

void setup() {
  pinMode(trigger, OUTPUT);
   pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop()
{
  long duration, inches, cm;
 
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger, LOW);


  duration = pulseIn(echo, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(100);
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{

  return microseconds / 29 / 2;
}
