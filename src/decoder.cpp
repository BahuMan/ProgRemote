#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include "pins2024.h"

const uint16_t kCaptureBufferSize = 1024;

IRrecv irrecv(PIN_IR_RECEIVER, kCaptureBufferSize, 50, true);
decode_results results;

void decoder_setup()
{
    // NOTE: Set this value very high to effectively turn off UNKNOWN detection.
    irrecv.setUnknownThreshold(12);
    irrecv.setTolerance(kTolerance);  // Override the default tolerance.
    irrecv.enableIRIn();  // Start the receiver
}

bool decoder_check()
{
  bool success = irrecv.decode(&results);
  if (success) {
    Serial.println(resultToHumanReadableBasic(&results));
    Serial.println(resultToSourceCode(&results));
    Serial.println();    // Blank line between entries
  }
  return success;
}
