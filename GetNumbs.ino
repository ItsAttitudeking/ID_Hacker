#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include <Keypad.h>
#include <SoftwareSerial.h>

const int txPin = 12;
const int rxPin = 11;
char str[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

SoftwareSerial BTSerial(rxPin, txPin); // RX, TX

const int numDigits = 4;

int timer[4] = {0, 0, 0, 0};
int index = 0;


Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();

void setup() {
  // put your setup code here, to run once:
  alpha4.begin(0x70);  // pass in the address

  alpha4.clear();
  alpha4.writeDisplay();

  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (BTSerial.available()){
    int num = BTSerial.parseInt();
    
    int i = num / 1000;
    int j = (num / 100) % 10;
    int k = (num / 10) % 10;
    int m = num % 10;
    alpha4.writeDigitAscii(0, str[i]);
    alpha4.writeDigitAscii(1, str[j]);
    alpha4.writeDigitAscii(2, str[k]);
    alpha4.writeDigitAscii(3, str[m]);
    alpha4.writeDisplay();
  }
    

}
