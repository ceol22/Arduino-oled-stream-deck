#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Joystick.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


int viewVal = 1;
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  31, 0,                  // Button Count, Hat Switch Count
  false, false, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering



int button1 = 7;
int button2 = 6;
int button3 = 5;
int button4 = 4;
int button5 = 8;
int button6 = 9;

int interVal = 250;

int button1Val = 1;
int button2Val = 1;
int button3Val = 1;
int button4Val = 1;
int button5Val = 1;
int button6Val = 1;


void setup() {
  Serial.begin(9600);
  pinMode(9, INPUT_PULLUP);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  pinMode(button6, INPUT_PULLUP);

  Joystick.begin();


}

void pageCheck(){



  int potVal = analogRead(A1);
  int dispVal = map(potVal,0,1023,1,6);

  switch (dispVal) {
    case 1:
    display.clearDisplay();
    display.setTextSize(2);             // Normal 1:1 pixel scale
    display.setTextColor(WHITE);        // Draw white text
    display.setCursor(0,0);             // Start at top-left corner
    display.println(F("Pagina 1"));
    display.display();
    viewVal = 1;
    break;

    case 2:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 2"));
      display.display();
      viewVal = 2;
    break;

    case 3:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 3"));
      display.display();
      viewVal = 3;
    break;

    case 4:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 4"));
      display.display();
      viewVal = 4;
    break;

    case 5:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 5"));
      display.display();
      viewVal = 5;
    break;

  }
}

void loop() {
int potVal = analogRead(A1);
int dispVal = map(potVal,0,1023,1,6);

switch (dispVal) {
  case 1:
  display.clearDisplay();
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println(F("Pagina 1"));
  display.display();
  viewVal = 1;
  break;

  case 2:
    display.clearDisplay();
    display.setTextSize(2);             // Normal 1:1 pixel scale
    display.setTextColor(WHITE);        // Draw white text
    display.setCursor(0,0);             // Start at top-left corner
    display.println(F("Pagina 2"));
    display.display();
    viewVal = 2;
  break;

  case 3:
    display.clearDisplay();
    display.setTextSize(2);             // Normal 1:1 pixel scale
    display.setTextColor(WHITE);        // Draw white text
    display.setCursor(0,0);             // Start at top-left corner
    display.println(F("Pagina 3"));
    display.display();
    viewVal = 3;
  break;

  case 4:
    display.clearDisplay();
    display.setTextSize(2);             // Normal 1:1 pixel scale
    display.setTextColor(WHITE);        // Draw white text
    display.setCursor(0,0);             // Start at top-left corner
    display.println(F("Pagina 4"));
    display.display();
    viewVal = 4;
  break;

  case 5:
    display.clearDisplay();
    display.setTextSize(2);             // Normal 1:1 pixel scale
    display.setTextColor(WHITE);        // Draw white text
    display.setCursor(0,0);             // Start at top-left corner
    display.println(F("Pagina 5"));
    display.display();
    viewVal = 5;
  break;

}

while (viewVal == 1) {
  int button1Val = digitalRead(button1);
  int button2Val = digitalRead(button2);
  int button3Val = digitalRead(button3);
  int button4Val = digitalRead(button4);
  int button5Val = digitalRead(button5);
  int button6Val = digitalRead(button6);


  int potVal = analogRead(A1);
  int dispVal = map(potVal,0,1023,1,6);

  switch (dispVal) {
    case 1:
    display.clearDisplay();
    display.setTextSize(2);             // Normal 1:1 pixel scale
    display.setTextColor(WHITE);        // Draw white text
    display.setCursor(0,0);             // Start at top-left corner
    display.println(F("Pagina 1"));
    display.display();
    viewVal = 1;
    break;

    case 2:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 2"));
      display.display();
      viewVal = 2;
    break;

    case 3:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 3"));
      display.display();
      viewVal = 3;
    break;

    case 4:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 4"));
      display.display();
      viewVal = 4;
    break;

    case 5:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 5"));
      display.display();
      viewVal = 5;
    break;

  }



  if(button1Val == LOW){
    Joystick.setButton(1, 1);
    delay(interVal);
    Joystick.setButton(1, 0);
   }




  if(button2Val == LOW){
    Joystick.setButton(2, 1);
    delay(interVal);
    Joystick.setButton(2, 0);
   }




  if(button3Val == LOW){
    Joystick.setButton(3, 1);
    delay(interVal);
    Joystick.setButton(3, 0);
   }




  if(button4Val == LOW){
    Joystick.setButton(4, 1);
    delay(interVal);
    Joystick.setButton(4, 0);
   }




  if(button5Val == LOW){
   Joystick.setButton(5, 1);
   delay(interVal);
   Joystick.setButton(5, 0);
    }



  if(button6Val == LOW){
    Joystick.setButton(6, 1);
    delay(interVal);
    Joystick.setButton(6, 0);
   }



}
// ###########################################################################################################################################



while (viewVal == 2) {
  int button1Val = digitalRead(button1);
  int button2Val = digitalRead(button2);
  int button3Val = digitalRead(button3);
  int button4Val = digitalRead(button4);
  int button5Val = digitalRead(button5);
  int button6Val = digitalRead(button6);



  int potVal = analogRead(A1);
  int dispVal = map(potVal,0,1023,1,6);

  switch (dispVal) {
    case 1:
    display.clearDisplay();
    display.setTextSize(2);             // Normal 1:1 pixel scale
    display.setTextColor(WHITE);        // Draw white text
    display.setCursor(0,0);             // Start at top-left corner
    display.println(F("Pagina 1"));
    display.display();
    viewVal = 1;
    break;

    case 2:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 2"));
      display.display();
      viewVal = 2;
    break;

    case 3:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 3"));
      display.display();
      viewVal = 3;
    break;

    case 4:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 4"));
      display.display();
      viewVal = 4;
    break;

    case 5:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 5"));
      display.display();
      viewVal = 5;
    break;

  }



  if(button1Val == LOW){
    Joystick.setButton(7, 1);
    delay(interVal);
    Joystick.setButton(7, 0);
   }




  if(button2Val == LOW){
    Joystick.setButton(8, 1);
    delay(interVal);
    Joystick.setButton(8, 0);
   }




  if(button3Val == LOW){
    Joystick.setButton(9, 1);
    delay(interVal);
    Joystick.setButton(9, 0);
   }




  if(button4Val == LOW){
    Joystick.setButton(10, 1);
    delay(interVal);
    Joystick.setButton(10, 0);
   }




  if(button5Val == LOW){
   Joystick.setButton(11, 1);
   delay(interVal);
   Joystick.setButton(11, 0);
    }



  if(button6Val == LOW){
    Joystick.setButton(12, 1);
    delay(interVal);
    Joystick.setButton(12, 0);
   }


}

// ###########################################################################################################################################


while (viewVal == 3) {

  int button1Val = digitalRead(button1);
  int button2Val = digitalRead(button2);
  int button3Val = digitalRead(button3);
  int button4Val = digitalRead(button4);
  int button5Val = digitalRead(button5);
  int button6Val = digitalRead(button6);

  pageCheck();

  if(button1Val == LOW){
    Joystick.setButton(13, 1);
    delay(interVal);
    Joystick.setButton(13, 0);
   }




  if(button2Val == LOW){
    Joystick.setButton(14, 1);
    delay(interVal);
    Joystick.setButton(14, 0);
   }




  if(button3Val == LOW){
    Joystick.setButton(15, 1);
    delay(interVal);
    Joystick.setButton(15, 0);
   }




  if(button4Val == LOW){
    Joystick.setButton(16, 1);
    delay(interVal);
    Joystick.setButton(16, 0);
   }




  if(button5Val == LOW){
   Joystick.setButton(17, 1);
   delay(interVal);
   Joystick.setButton(17, 0);
    }



  if(button6Val == LOW){
    Joystick.setButton(18, 1);
    delay(interVal);
    Joystick.setButton(18, 0);
   }






}


//##################################################################################################################################################


while (viewVal == 4) {
  int button1Val = digitalRead(button1);
  int button2Val = digitalRead(button2);
  int button3Val = digitalRead(button3);
  int button4Val = digitalRead(button4);
  int button5Val = digitalRead(button5);
  int button6Val = digitalRead(button6);



  int potVal = analogRead(A1);
  int dispVal = map(potVal,0,1023,1,6);

  switch (dispVal) {
    case 1:
    display.clearDisplay();
    display.setTextSize(2);             // Normal 1:1 pixel scale
    display.setTextColor(WHITE);        // Draw white text
    display.setCursor(0,0);             // Start at top-left corner
    display.println(F("Pagina 1"));
    display.display();
    viewVal = 1;
    break;

    case 2:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 2"));
      display.display();
      viewVal = 2;
    break;

    case 3:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 3"));
      display.display();
      viewVal = 3;
    break;

    case 4:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 4"));
      display.display();
      viewVal = 4;
    break;

    case 5:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 5"));
      display.display();
      viewVal = 5;
    break;

  }



  if(button1Val == LOW){
    Joystick.setButton(19, 1);
    delay(interVal);
    Joystick.setButton(19, 0);
   }




  if(button2Val == LOW){
    Joystick.setButton(20, 1);
    delay(interVal);
    Joystick.setButton(20, 0);
   }




  if(button3Val == LOW){
    Joystick.setButton(21, 1);
    delay(interVal);
    Joystick.setButton(21, 0);
   }




  if(button4Val == LOW){
    Joystick.setButton(22, 1);
    delay(interVal);
    Joystick.setButton(22, 0);
   }




  if(button5Val == LOW){
   Joystick.setButton(23, 1);
   delay(interVal);
   Joystick.setButton(23, 0);
    }



  if(button6Val == LOW){
    Joystick.setButton(24, 1);
    delay(interVal);
    Joystick.setButton(24, 0);
   }


}



//###########################################################################################################################################



while (viewVal == 5) {
  int button1Val = digitalRead(button1);
  int button2Val = digitalRead(button2);
  int button3Val = digitalRead(button3);
  int button4Val = digitalRead(button4);
  int button5Val = digitalRead(button5);
  int button6Val = digitalRead(button6);



  int potVal = analogRead(A1);
  int dispVal = map(potVal,0,1023,1,6);

  switch (dispVal) {
    case 1:
    display.clearDisplay();
    display.setTextSize(2);             // Normal 1:1 pixel scale
    display.setTextColor(WHITE);        // Draw white text
    display.setCursor(0,0);             // Start at top-left corner
    display.println(F("Pagina 1"));
    display.display();
    viewVal = 1;
    break;

    case 2:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 2"));
      display.display();
      viewVal = 2;
    break;

    case 3:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 3"));
      display.display();
      viewVal = 3;
    break;

    case 4:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 4"));
      display.display();
      viewVal = 4;
    break;

    case 5:
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.println(F("Pagina 5"));
      display.display();
      viewVal = 5;
    break;

  }



  if(button1Val == LOW){
    Joystick.setButton(25, 1);
    delay(interVal);
    Joystick.setButton(25, 0);
   }




  if(button2Val == LOW){
    Joystick.setButton(26, 1);
    delay(interVal);
    Joystick.setButton(26, 0);
   }




  if(button3Val == LOW){
    Joystick.setButton(27, 1);
    delay(interVal);
    Joystick.setButton(27, 0);
   }




  if(button4Val == LOW){
    Joystick.setButton(28, 1);
    delay(interVal);
    Joystick.setButton(28, 0);
   }




  if(button5Val == LOW){
   Joystick.setButton(29, 1);
   delay(interVal);
   Joystick.setButton(29, 0);
    }



  if(button6Val == LOW){
    Joystick.setButton(30, 1);
    delay(interVal);
    Joystick.setButton(30, 0);
   }


}

}
