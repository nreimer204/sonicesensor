/*  
    Arduino with PIR motion sensor
    For complete project details, visit: http://RandomNerdTutorials.com/pirsensor
    Modified by Rui Santos based on PIR sensor by Limor Fried
*/

#include <FastLED.h>
#include <Adafruit_NeoPixel.h>
#include "pitches.h"

#define LED_PIN     6
#define NUM_LEDS    50

CRGB leds[NUM_LEDS];
Adafruit_NeoPixel strip = Adafruit_NeoPixel(50, LED_PIN, NEO_GRB + NEO_KHZ800);
 
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};


void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

  
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
 
  if (val == HIGH) {           // check if the sensor is HIGH
    for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
  
  colorWipe(strip.Color(random(0, 255), random(0, 255), random(0, 255)), 5); // random colour
    delay(5000);                // delay 100 milliseconds 
     
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {

      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH){

  colorWipe(strip.Color(0, 0, 0), 1); // random colour
  
  Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }

}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void colorClear(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void oneLightOn() {

  leds[3] = CRGB(255, 200, 20);
  FastLED.show();
  delay(100);
  
}


void oneLightOff() {
    leds[3] = CRGB::Black;
  FastLED.show();
  delay(100);
}

void lightsOn() {
    
  leds[0] = CRGB(255, 0, 0);
  FastLED.show();
  delay(100); 
        // Set the first led back to black for 1 second
      leds[0] = CRGB::Black;
      FastLED.show();
      delay(500); 
  leds[1] = CRGB(0, 255, 0);
  FastLED.show();
  delay(100);
          // Set the first led back to black for 1 second
      leds[1] = CRGB::Black;
      FastLED.show();
      delay(500); 
  leds[2] = CRGB(0, 0, 255);
  FastLED.show();
  delay(100);
          // Set the first led back to black for 1 second
      leds[2] = CRGB::Black;
      FastLED.show();
      delay(500); 
  leds[5] = CRGB(150, 0, 255);
  FastLED.show();
  delay(100);
          // Set the first led back to black for 1 second
      leds[5] = CRGB::Black;
      FastLED.show();
      delay(100); 
  leds[3] = CRGB(255, 200, 20);
  FastLED.show();
  delay(100);
          // Set the first led back to black for 1 second
      leds[3] = CRGB::Black;
      FastLED.show();
      delay(100); 
  leds[4] = CRGB(85, 60, 180);
  FastLED.show();
  delay(100);
          // Set the first led back to black for 1 second
      leds[4] = CRGB::Black;
      FastLED.show();
      delay(100); 
  leds[8] = CRGB(50, 255, 20);
  FastLED.show();
  delay(100);
          // Set the first led back to black for 1 second
      leds[8] = CRGB::Black;
      FastLED.show();
      delay(100); 

   }
