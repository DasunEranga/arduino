//code for testing Ultrasonic Module
#define ECHOPIN 8        // Pin to receive echo pulse 
#define TRIGPIN 4        // Pin to send trigger pulse

#define ECHOPIN2 9        // Pin to receive echo pulse 
#define TRIGPIN2 5        // Pin to send trigger pulse

  
void setup() 
{ 
  Serial.begin(9600); 
  pinMode(ECHOPIN, INPUT); 
  pinMode(TRIGPIN, OUTPUT); 

  pinMode(ECHOPIN2, INPUT); 
  pinMode(TRIGPIN2, OUTPUT); 
}
void loop() 
{ 
  // Start Ranging -Generating a trigger of 10us burst 
  digitalWrite(TRIGPIN, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TRIGPIN, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TRIGPIN, LOW);
  
  digitalWrite(TRIGPIN2, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TRIGPIN2, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TRIGPIN, LOW);
  
  
  // Distance Calculation
  
  float distance1 = pulseIn(ECHOPIN, HIGH); 
  distance1= distance1/58;

  float distance2 = pulseIn(ECHOPIN2, HIGH); 
  distance2= distance2/58; 
/* The speed of sound is 340 m/s or 29 us per cm.The Ultrasonic burst travels out & back.So to find the distance of object we divide by 58  */
  Serial.print(distance1); 
  Serial.println(" cm");
  delay(200);

  Serial.print(distance2); 
  Serial.println(" cm");
  delay(300);
}
