#include <Adafruit_NeoMatrix.h>
#include "Adafruit_Keypad.h"

#define PIN       11 //LED pin
#define NUMPIXELS 15

const byte ROWS = 5; // rows
const byte COLS = 3; // columns

//define the symbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'A','2','B'},
  {'4','5','6'},
  {'7','8','9'},
  {'10','11','12'},
  {'13','14','15'}
};

//byte rowPins[ROWS] = {PD4, PD5, PD7}; //connect to the row pinouts of the keypad
//byte colPins[COLS] = {PC7, PC6, PB6, PB5, PB4}; //connect to the column pinouts of the keypad

byte rowPins[ROWS] = {13, 5, 10, 9, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 12, 6}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

unsigned char randNumber;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 1

void setup() {

  Serial.begin(115200);
/*
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(12, INPUT_PULLUP);
  pinMode(PC7, INPUT);  
*/
  pixels.begin();
  randomSeed(analogRead(38));
  pixels.setBrightness(10);

  customKeypad.begin();

   
}

void loop() {

  ledMatrix();
//  Serial.println("TEST");

  customKeypad.tick();

  while(customKeypad.available()){
    keypadEvent e = customKeypad.read();
    Serial.print((char)e.bit.KEY);
    if(e.bit.EVENT == KEY_JUST_PRESSED) Serial.println(" pressed");
    else if(e.bit.EVENT == KEY_JUST_RELEASED) Serial.println(" released");
    delay(10);
  }

  delay(10);


}


void ledMatrix() {

//  for(int i=0; i<NUMPIXELS; i++) {
  for(int i=random(0, 15); i<NUMPIXELS; i++) {

    
    randNumber = random(0, 255); //To adjust the color span

    pixels.setPixelColor(i, pixels.Color(random(), random(), random())); //Random colors

    pixels.show();

    //Serial.println(randNumber);  //Just for debugging!
    
    delay(DELAYVAL);

    return;

  }  


}
