#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 3; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

int timer[4] = {0,0,0,0};
int index = 0;

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  index = 0;
}
  
void loop(){
  char customKey = customKeypad.getKey();
  int num = 0;
  if (customKey)
  {
    num = ((int)(customKey)) - 48;
    //Serial.println(num);
  }
  timer[index] = num;
  index++;
  if(index == 4){
    break;
  }
}
