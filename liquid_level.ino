
#include "LowPower.h"
#define Liquid_Detection_1 2
volatile int Liquid_State = 0;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  while (!Serial) delay(1);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Liquid_Detection_1, INPUT);
  Serial.write("Started");
  
}

// the loop function runs over and over again forever
void loop() {
   attachInterrupt(digitalPinToInterrupt(2), led_on, RISING);
   attachInterrupt(digitalPinToInterrupt(2), led_off, FALLING);
   Serial.println("Going to sleep");
   LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);

}

void led_on() {
    Serial.println("LIQUID!");
    digitalWrite(LED_BUILTIN, HIGH);
}

void led_off() {
    Serial.println(" NO LIQUID!");
    digitalWrite(LED_BUILTIN, LOW);
}