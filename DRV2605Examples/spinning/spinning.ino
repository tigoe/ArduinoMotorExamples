#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;

void setup() {
  drv.begin();

  // I2C trigger by sending 'go' command
  drv.setMode(DRV2605_MODE_INTTRIG); // default, internal trigger when sending GO command

  drv.selectLibrary(1);
  drv.setWaveform(0, 83);  // soft bump 100%
  drv.setWaveform(1, 71);  // end of sequence
  drv.setWaveform(2, 0);  // soft bump 100%

}

void loop() {
  drv.go();
  delay(3000);

}
