
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();

void setup() {
  Serial.begin(9600);
  
  alpha4.begin(0x70);  // pass in the address
  
  alpha4.clear();
  alpha4.writeDisplay();

}


char displaybuffer[4] = {' ', ' ', ' ', ' '};

void loop() {
  char* str = "0123456789";


  int INPUT_0 = 0;
  int INPUT_1 = 0;
  int INPUT_2 = 3;
  int INPUT_3 = 0;

  int i = INPUT_0;
  int j = INPUT_1;
  int k = INPUT_2;
  int m = INPUT_3;

  for(;i >= 0;i--) {
    for(;j >= 0;j--) {
      for(;k >= 0;k--) {
        for(;m >= 0;m--) {
          alpha4.writeDigitAscii(0, str[i]);
          alpha4.writeDigitAscii(1, str[j]);
          alpha4.writeDigitAscii(2, str[k]);
          alpha4.writeDigitAscii(3, str[m]);
          alpha4.writeDisplay();
          delay(1000);
          alpha4.clear();
        }
        if(k != 0) m = 9;
      }
      if(j != 0) k = 6;
    }
    if(i != 0) j = 9;
  }

  alpha4.writeDigitAscii(1, 'E');
  alpha4.writeDigitAscii(2, 'n');
  alpha4.writeDigitAscii(3, 'd');
  alpha4.writeDisplay();
  delay(5000);
}
