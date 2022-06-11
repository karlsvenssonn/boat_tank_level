
#include "LowPower.h"
#define Liquid_Detection_1 2
#define Liquid_Detection_2 3
#define Led_1 4
#define Led_2 5
volatile int Liquid_State = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Led_1, OUTPUT);
  pinMode(Led_2, OUTPUT);
  pinMode(Liquid_Detection_1, INPUT);
  pinMode(Liquid_Detection_2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), liquid, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), liquid_high, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(2), led_off, FALLING);
}

// the loop function runs over and over again forever
void loop() {
   //Serial.println("Going to sleep");
   //LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
}

void liquid() {
    Serial.begin(9600);
    if(digitalRead(Liquid_Detection_1)) {
      Serial.println("LIQUID!");
      digitalWrite(LED_BUILTIN, HIGH);
      //digitalWrite(Led_1, HIGH);
    }
    else {
      Serial.println("NO LIQUID!");
      digitalWrite(LED_BUILTIN, LOW);
      //digitalWrite(Led_1, LOW);
    }
}

void liquid_high() {
    if(digitalRead(Liquid_Detection_1) == HIGH && digitalRead(Liquid_Detection_2) == HIGH) {
      digitalWrite(Led_2, HIGH);
    }
    if(digitalRead(Liquid_Detection_2) == LOW) {
      digitalWrite(Led_2, LOW);
  }
}
