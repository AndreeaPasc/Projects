#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4); // Change to (0x27,20,4) for 20x4 LCD.

// mario frames
// (1 = top left 2 = bottem left 3 = top right 4 = bottem right)
byte mario11[8] = {
B00000,
B00000,
B00000,
B00000,
B00001,
B00001,
B00001,
B00000

};
byte mario12[8] = {
B00001,
B00001,
B00001,
B00001,
B00000,
B00000,
B00000,
B00000
};
byte mario13[8] = {
  B00000,
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,

};
byte mario14[8] = {
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
B11110
};

byte mario15[8] = {
B00000,
B00000,
B11000,
B00000,
B11000,
B11100,
B11000,
B10000,

};

byte mario16[8] = {
B00000,
B10000,
B10000,
B10000,
B00000,
B00000,
B10000,
B00000
};

byte mario21[8] = {
   B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
};

byte mario22[8] = {
B00111,
B00111,
B00111,
B00000,
B00001,
B00011,
B00011,
B00001
};

byte mario23[8] = {
B00000,
B01111,
B11111,
B11111,
B11111,
B11111,
B11111,
B01111,

};

byte mario24[8] = {
B11111,
B11111,
B11111,
B11111,
B11111,
B11001,
B00000,
B10000
};
byte mario25[8] = {
B00000,
B00000,
B11100,
B10000,
B11100,
B11110,
B11100,
B11000,

};

byte mario26[8] = {
B11111,
B11111,
B10110,
B11110,
B11110,
B11110,
B00000,
B00000,
};

byte clean[8] = {
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
};

byte coin[8] = {
B00000,
B00000,
B00000,
B00000,
B01110,
B11111,
B11111,
B01110
};
byte pipeDownUp[8] = {
0b11111,
0b11111,
0b11111,
0b11111,
0b11111,
0b11111,
0b11111,
0b11111
};

// variables
int score = 0;
int posCoin;
bool jumped = false;
bool pipes = false;
bool clearMario = false;
bool play = true;
int row = 2;
int a = 4;
int b = a+1;
int c = a+2;
int distance = 0;

// setup
void setup() {
  // lcd init
  lcd.init();
  lcd.backlight();
  // button interrupts
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), jump, CHANGE);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), jumpEnd, CHANGE);
}
 
void loop() {
  // go until the end of the screen and come back
    for(int pos = 19; pos > 0; pos--){
      
      // if the player hasn't lost
      if(play == true){
      //draw pipe
      drawPipeUp(pos);

      // put score on screen
      lcd.setCursor(17, 0);
      lcd.print(score);

      // jump
      if(jumped == false){
        // if mario is on rows 3 and 2, clear rows 0 and 1
        lcdClearUp();
        drawMario(row);
      }
      else {
        // after jump, clear rows 0 and 1
        if(clearMario == true){
          lcdClearDown();
        }
        row = 0;
        clearMario = false;
        drawMario(row);
        // draw pipe under mario
        lcd.setCursor(pos,3);
        lcd.write(8);
        lcd.setCursor(pos, 2);
        lcd.write(8);
        lcd.setCursor(pos-1,2);
        lcd.write(8);
        lcd.setCursor(pos+1, 2);
        lcd.write(8);
      }
        // collision
        distance = pos - 1 - c;
        if(row == 2 && distance == 0){
          endGame();
          }
        // score = time after game started
        score = millis() / 1000;
      }
    }
}

// game over
void endGame(){
  play = false;
  lcd.clear();
  lcd.setCursor(4, 1);
  lcd.print("Game Over");
  lcd.setCursor(3, 2);
  lcd.print("Your score: ");
  lcd.setCursor(16 ,2);
  lcd.print(score);
  }

// jumps
void jump(){
  jumped = true;
  clearMario = true;
  row = 0;  
  }

void jumpEnd(){
  jumped = false;
  clearMario = false;
  row = 2;
  }

// clear screen after jumps
void lcdClearDown(){
  lcd.setCursor(4, 2);
  lcd.print(" ");
  lcd.setCursor(4, 3);
  lcd.print(" ");
  lcd.setCursor(5, 2);
  lcd.print(" ");
  lcd.setCursor(5, 3);
  lcd.print(" ");
  lcd.setCursor(6, 2);
  lcd.print(" ");
  lcd.setCursor(6, 3);
  lcd.print(" ");
  }

void lcdClearUp(){
  lcd.setCursor(4, 0);
  lcd.print(" ");
  lcd.setCursor(4, 1);
  lcd.print(" ");
  lcd.setCursor(5, 0);
  lcd.print(" ");
  lcd.setCursor(5, 1);
  lcd.print(" ");
  lcd.setCursor(6, 0);
  lcd.print(" ");
  lcd.setCursor(6, 1);
  lcd.print(" ");
  }

// draw pipes
void drawPipeUp(int pos){
    lcd.createChar(8, pipeDownUp);
   
    lcd.setCursor(pos,3);
    lcd.write(8);
    lcd.setCursor(pos, 2);
    lcd.write(8);
    lcd.setCursor(pos-1,2);
    lcd.write(8);
    lcd.setCursor(pos+1, 2);
    lcd.write(8);
    
    lcd.setCursor(pos+1,3);
    lcd.write(7);
    lcd.setCursor(pos+2, 2);
    lcd.write(7);
    
    lcd.setCursor(1, 3);
    lcd.write(7);
    lcd.setCursor(1, 2);
    lcd.write(7);
    lcd.setCursor(2, 2);
    lcd.write(7);
    lcd.setCursor(0, 2);
    lcd.write(7);
}

// draw mario
void drawMario(int row){

  lcd.createChar(1, mario11);
  lcd.createChar(2, mario12);
  lcd.createChar(3, mario13);
  lcd.createChar(4, mario14);
  lcd.createChar(5, mario15);
  lcd.createChar(6, mario16);
  lcd.createChar(7, clean);
  
  lcd.setCursor(a,row);
  lcd.write(7);
  lcd.setCursor(a,row+1);
  lcd.write(7);
  
  lcd.setCursor(a,row);
  lcd.write(1);
  lcd.setCursor(a,row+1);
  lcd.write(2);
  lcd.setCursor(b,row);
  lcd.write(3);
  lcd.setCursor(b,row+1);
  lcd.write(4);
  lcd.setCursor(c,row);
  lcd.write(5);
  lcd.setCursor(c,row+1);
  lcd.write(6);
  
  delay(200);
  
  lcd.createChar(1, mario21);
  lcd.createChar(2, mario22);
  lcd.createChar(3, mario23);
  lcd.createChar(4, mario24);
  lcd.createChar(5, mario25);
  lcd.createChar(6, mario26);
  
  lcd.setCursor(a,row);
  lcd.write(7);
  lcd.setCursor(a,row+1);
  lcd.write(7);
  
  lcd.setCursor(a,row);
  lcd.write(1);
  lcd.setCursor(a,row+1);
  lcd.write(2);
  lcd.setCursor(b,row);
  lcd.write(3);
  lcd.setCursor(b,row+1);
  lcd.write(4);
  lcd.setCursor(c,row);
  lcd.write(5);
  lcd.setCursor(c,row+1);
  lcd.write(6);
  }
