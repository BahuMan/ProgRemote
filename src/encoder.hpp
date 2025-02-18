#ifndef ENCODER_HPP
#define ENCODER_HPP

#define ADDRESS_TV 0x01
#define TV_BITLENGTH 12
#define ADDRESS_SOUNDBAR 0x30
#define SOUNDBAR_BITLENGTH 15
#define CMD_POWER 0x15
#define CMD_VOL_UP 0x12
#define CMD_VOL_DOWN 0x13

void encoder_setup();
void sendTVPower();
void sendSoundbarPower();
void sendSoundbarVolumeUp();
void sendSoundbarVolumeDown();

#endif