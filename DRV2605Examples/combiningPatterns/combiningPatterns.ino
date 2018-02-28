#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;

void setup() {
  drv.begin();

  // I2C trigger by sending 'go' command
  drv.setMode(DRV2605_MODE_INTTRIG); // default, internal trigger when sending GO command

  drv.selectLibrary(1);
}

void loop() {

  drv.setWaveform(0, 7);  // soft bump 100%
  drv.setWaveform(1, 0);  // end of sequence

  drv.go();
  delay(3000);
  drv.setWaveform(0, 16); // 1000 ms alert
  drv.setWaveform(1, 0);  // end of sequence

  drv.go();
  delay(3000);
  drv.setWaveform(0, 87);  // transition ramp up short smooth2 - 0 to 100%
  drv.setWaveform(1, 71);  // transition ramp down long smooth 2 - 100 to 0%
  drv.setWaveform(2, 0);   // end of sequence
  drv.go();
  delay(3000);
  drv.setWaveform(0, 70);  // transition ramp down smooth 100% to 0%
  drv.setWaveform(1, 52);  // pulsing strong 1
  drv.setWaveform(2, 34);  // short double tick 1
  drv.setWaveform(3, 0);   // end of sequence
  drv.go();
  delay(3000);

}
