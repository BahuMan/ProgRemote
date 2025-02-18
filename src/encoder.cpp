#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include "pins2024.h"
#include "encoder.hpp"

IRsend irsend(PIN_SAO);

void encoder_setup()
{
    pinMode(PIN_SAO, OUTPUT); //I guess this will be done in irsend.begin() but I want to be sure
    irsend.begin();
}
void sendTVPower()
{
    irsend.sendSony(irsend.encodeSony(TV_BITLENGTH, CMD_POWER, ADDRESS_TV), TV_BITLENGTH, 3U);
    delay(500);
}

void sendSoundbarPower()
{
    irsend.sendSony(irsend.encodeSony(SOUNDBAR_BITLENGTH, CMD_POWER, ADDRESS_SOUNDBAR), SOUNDBAR_BITLENGTH, 3U);
    delay(500);
}

void sendSoundbarVolumeUp()
{
    irsend.sendSony(irsend.encodeSony(SOUNDBAR_BITLENGTH, CMD_VOL_UP, ADDRESS_SOUNDBAR), SOUNDBAR_BITLENGTH, 3U);
    delay(200);
}

void sendSoundbarVolumeDown()
{
    irsend.sendSony(irsend.encodeSony(SOUNDBAR_BITLENGTH, CMD_VOL_DOWN, ADDRESS_SOUNDBAR), SOUNDBAR_BITLENGTH, 3U);
    delay(200);
}