/*  
    Arduino with PIR motion sensor
    For complete project details, visit: http://RandomNerdTutorials.com/pirsensor
    Modified by Rui Santos based on PIR sensor by Limor Fried
*/


 
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)




void setup() {
  pinMode(sensor, INPUT);    // initialize sensor as an input

}

void loop(){
  val = digitalRead(sensor);   // read sensor value
 
  if (val == HIGH) {           // check if the sensor is HIGH

//Put the code for what you want to happen when the sensor is triggered here
    
  }
  
  else {

//Put the code for what should happen when the sensor is not being triggered here

    }

}


//Put the small bits of repeatable instructions (functions) here:
