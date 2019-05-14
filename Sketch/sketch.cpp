/*
 * M4Default.cpp
 *
 * Created: 5/14/2019 11:00:56 AM
 * Author : User
 */ 


#include "Arduino.h"

#define HEARTBEAT_PIN LED_BUILTIN
#define HEARTBEAT_TIME 1000

void heartbeat(){
  static uint32_t lastBlinkTimer = 0;
  static uint8_t led = LOW;

  if (millis() - lastBlinkTimer > (HEARTBEAT_TIME / 2)){
    led = !led;
    digitalWrite(LED_BUILTIN, led);
    lastBlinkTimer = millis();
    if (led) Serial.println("Heartbeat");
  }
}

void setup(){
  Serial.begin(9600);
  Serial.println("Boot...");
  pinMode(HEARTBEAT_PIN, OUTPUT);
}

void loop(){
  heartbeat();
}
