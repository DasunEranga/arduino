// ---------------------------------------------------------------------------
// This example code was used to successfully communicate with 15 ultrasonic sensors. You can adjust
// the number of sensors in your project by changing SONAR_NUM and the number of NewPing objects in the
// "sonar" array. You also need to change the pins for each sensor for the NewPing objects. Each sensor
// is pinged at 33ms intervals. So, one cycle of all sensors takes 495ms (33 * 15 = 495ms). The results
// are sent to the "oneSensorCycle" function which currently just displays the distance data. Your project
// would normally process the sensor results in this function (for example, decide if a robot needs to
// turn and call the turn function). Keep in mind this example is event-driven. Your complete sketch needs
// to be written so there's no "delay" commands and the loop() cycles at faster than a 33ms rate. If other
// processes take longer than 33ms, you'll need to increase PING_INTERVAL so it doesn't get behind.
// ---------------------------------------------------------------------------
#include <NewPing.h>

#define SONAR_NUM     4 // Number of sensors.
#define MAX_DISTANCE 10 // Maximum distance (in cm) to ping.
#define PING_INTERVAL 33 // Milliseconds between sensor pings (29ms is about the min to avoid cross-sensor echo).

unsigned long pingTimer[SONAR_NUM]; // Holds the times when the next ping should happen for each sensor.
unsigned int cm[SONAR_NUM];         // Where the ping distances are stored.
uint8_t currentSensor = 0;          // Keeps track of which sensor is active.
const int ledG1 =6;
const int ledR1 =7;
const int ledG2 =12;
const int ledR2 =13;
//const int ledG3 =9;
//const int ledR3 =10;
//const int ledG4 =11;
//const int ledR4 =12;

NewPing sonar[SONAR_NUM] = {     // Sensor object array.
  NewPing(2, 8, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping.
  NewPing(3, 9, MAX_DISTANCE),
  NewPing(4, 10, MAX_DISTANCE),
  NewPing(5, 11, MAX_DISTANCE)
};

void setup() {
  Serial.begin(115200);
  pingTimer[0] = millis() + 75;           // First ping starts at 75ms, gives time for the Arduino to chill before starting.
  for (uint8_t i = 1; i < SONAR_NUM; i++) // Set the starting time for each sensor.
    pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;
}

void loop() {
  for (uint8_t i = 0; i < SONAR_NUM; i++) { // Loop through all the sensors.
    if (millis() >= pingTimer[i]) {         // Is it this sensor's time to ping?
      pingTimer[i] += PING_INTERVAL * SONAR_NUM;  // Set next time this sensor will be pinged.
      if (i == 0 && currentSensor == SONAR_NUM - 1) oneSensorCycle(); // Sensor ping cycle complete, do something with the results.
      sonar[currentSensor].timer_stop();          // Make sure previous timer is canceled before starting a new ping (insurance).
      currentSensor = i;                          // Sensor being accessed.
      cm[currentSensor] = 0;                      // Make distance zero in case there's no ping echo for this sensor.
      sonar[currentSensor].ping_timer(echoCheck); // Do the ping (processing continues, interrupt will call echoCheck to look for echo).
    }
  }
  // Other code that *DOESN'T* analyze ping results can go here.
}

void echoCheck() { // If ping received, set the sensor distance to array.
  if (sonar[currentSensor].check_timer())
    cm[currentSensor] = sonar[currentSensor].ping_result / US_ROUNDTRIP_CM;
}

void oneSensorCycle() { // Sensor ping cycle complete, do something with the results.
  // The following code would be replaced with your code that does something with the ping results.
  for (uint8_t i = 0; i < SONAR_NUM; i++) {
    Serial.print(i);
    Serial.print("=");
    Serial.print(cm[i]);
    Serial.print("cm ");
    //delay(800);


  }
    Serial.print(3);
    Serial.print("=");
    Serial.print(cm[0]);
    
    Serial.println();

    if(cm[0]<10){
       Serial.println("traffic length = 10 m");
       // Serial.println();
        //Green
        delay(1000);
        digitalWrite(ledG1, HIGH);
        digitalWrite(ledR1, HIGH);
        digitalWrite(ledR2, HIGH);
        digitalWrite(ledR1, HIGH);
        delay(2000);
        digitalWrite(ledG1, LOW);
        digitalWrite(ledR1, HIGH);
        digitalWrite(ledR2, LOW);
        digitalWrite(ledG2, HIGH);
        delay(2000);
        digitalWrite(ledG2, LOW);
        digitalWrite(ledR2, HIGH);
        //digitalWrite(ledR3, LOW);
        //digitalWrite(ledG3, HIGH);
        delay(2000);
        //digitalWrite(ledG3, LOW);
        //digitalWrite(ledR3, HIGH);
        //digitalWrite(ledR4, LOW);
        //digitalWrite(ledG4, HIGH);
        delay(2000);
        
            //  Red
//        delay(2000);
//        digitalWrite(ledR1, HIGH);
//        delay(20000);
//        digitalWrite(ledG1, LOW);
        
          
      }else{
        Serial.println("No traffic length ");
        Serial.println();
        
        }

     if(cm[1]<10){
       Serial.println("traffic length = 40 m");
        Serial.println();
        delay(1000);
        digitalWrite(ledG1, LOW);
        digitalWrite(ledR1, HIGH);
        digitalWrite(ledR2, LOW);
        digitalWrite(ledG2, HIGH);
        delay(2000);
        digitalWrite(ledG2, LOW);
        digitalWrite(ledR2, HIGH);
        //digitalWrite(ledR3, LOW);
        //digitalWrite(ledG3, HIGH);
        delay(2000);
        //digitalWrite(ledG3, LOW);
        //digitalWrite(ledR3, HIGH);
        //digitalWrite(ledR4, LOW);
        //digitalWrite(ledG4, HIGH);
        delay(2000);
        digitalWrite(ledG1, HIGH);
        digitalWrite(ledR1, HIGH);
        digitalWrite(ledR2, HIGH);
        digitalWrite(ledR1, HIGH);
        delay(2000);
   
      }else{
        Serial.println("No traffic length ");
        Serial.println();


        
        }
    
}
