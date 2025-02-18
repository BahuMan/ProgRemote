#include <Arduino.h>
#include "pins2024.h"

//this code works with the Fri3d 2024 blaster and Noisy Cricket (mini-blaster) add-on
unsigned long lastTime = 0;

//these #defines limit protocols, hopefully keeping the compiled code small:
#define _IR_ENABLE_DEFAULT_ false
//to make this code work for other vendors, change the #defines in encoder.hpp
//and find the correct #define for your vendor in IRremoteESP8266.h
#define DECODE_SONY


//void decoder_setup();
//bool decoder_check();
#include "encoder.hpp"

void setup() {
  Serial.begin(115200);
  pinMode(PIN_A, INPUT_PULLUP); //power TV
  pinMode(PIN_Y, INPUT_PULLUP); //power soundbar
  pinMode(PIN_X, INPUT_PULLUP); //volume up
  pinMode(PIN_B, INPUT_PULLUP); //volume down

  //decoder_setup();
  encoder_setup();
  Serial.println("Setup completed");
}

void check_buttons()
{
  if (digitalRead(PIN_A) == LOW) sendTVPower();
  if (digitalRead(PIN_Y) == LOW) sendSoundbarPower();
  if (digitalRead(PIN_X) == LOW) sendSoundbarVolumeUp();
  if (digitalRead(PIN_B) == LOW) sendSoundbarVolumeDown();

}

void loop() {
  //decoder_check();
  check_buttons();
  if (millis() - lastTime > 1000) {
    Serial.print('.');
    lastTime = millis();
  }
}
