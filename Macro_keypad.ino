#include <Adafruit_NeoMatrix.h>
#include "Adafruit_Keypad.h"
#include "Keyboard.h"

#define PIN       11 //LED pin
#define NUMPIXELS 15
#define KEY_JUST_RELEASED (0) ///< key has been released
#define KEY_JUST_PRESSED (1)


const byte ROWS = 3; // rows
const byte COLS = 5; // columns

//define the symbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'0','1','2','3','4'},
  {'5','6','7','8','9'},
  {'A','B','C','D','E'},
};

byte colPins[COLS] = {13, 5, 10, 9, 8}; //connect to the column pinouts of the keypad
byte rowPins[ROWS] = {4, 12, 6}; //connect to the row pinouts of the keypad


//initialize an instance of class NewKeypad
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

unsigned char randNumber;


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 30

void setup() {

  pinMode(4, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);


  Serial.begin(115200);

  pixels.begin();
  randomSeed(analogRead(38));
  pixels.setBrightness(10);
  customKeypad.begin();
  Keyboard.begin();
  
}

void loop() {

  ledMatrix();

  customKeypad.tick();

  while(customKeypad.available()){
    keypadEvent e = customKeypad.read();
    Serial.println((char)e.bit.KEY);
    

    if(e.bit.EVENT == KEY_JUST_PRESSED);  
    
    char key = (char)e.bit.KEY;
    if(key=='0'){ 
    Keyboard.press('0');
    Keyboard.releaseAll();
    }
    if(key=='1'){ 
    Keyboard.press('1');   
    Keyboard.releaseAll();
    }
    if(key=='2'){ 
    Keyboard.press('2'); 
    Keyboard.releaseAll();
    }
    if(key=='3'){ 
    Keyboard.print('3'); 
    Keyboard.releaseAll();
    }
    if(key=='4'){ 
    Keyboard.press('4'); 
    Keyboard.releaseAll();
    }
    if(key=='5'){ 
    Keyboard.press('5'); 
    Keyboard.releaseAll();
    }
    if(key=='6'){ 
    Keyboard.press('6'); 
    Keyboard.releaseAll();
    }
    if(key=='7'){ 
    Keyboard.press('7'); 
    Keyboard.releaseAll();
    }
    if(key=='8'){ 
    Keyboard.press('8'); 
    Keyboard.releaseAll();
    }
    if(key=='9'){ 
    Keyboard.press('9'); 
    Keyboard.releaseAll();
    }
    if(key=='A'){ 
    Keyboard.press('A'); 
    Keyboard.releaseAll();
    }
    if(key=='B'){ 
    Keyboard.press('B'); 
    Keyboard.releaseAll();
    }    
    if(key=='C'){ 
    Keyboard.press('C'); 
    Keyboard.releaseAll();
    }
    if(key=='D'){ 
    Keyboard.press('D'); 
    Keyboard.releaseAll();
    } 
    if(key=='E'){ 
    Keyboard.press('E'); 
    Keyboard.releaseAll();
    }    

    delay(50);


    } 
  }

void ledMatrix() {

  for(int i=0; i<NUMPIXELS; i++) {
  for(int i=random(0, 15); i<NUMPIXELS; i++) {

    randNumber = random(0, 255); //To adjust the color span

    pixels.setPixelColor(i, pixels.Color(random(), random(), random())); //Random colors

    pixels.show();
    
    delay(DELAYVAL);

    return;

    }  
  }
}