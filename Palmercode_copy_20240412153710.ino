// include the library code:
#include <Wire.h>               //For I2C
#include <LiquidCrystal_I2C.h>  //For I2C LCD
// used example code at this link  http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//pin that the buttons are connected to
int button4 = 2;                    
int button8 = 3; 
int button12 = 4; 
int tea = 7; //tea solenoid relay pin
int lem = 8; //lem solenoid relay pin

LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x3F for a 16 chars and 2 line display


void setup() {
  //set the button pin as an input
  pinMode(button4, INPUT_PULLUP);     
  pinMode(button8, INPUT_PULLUP);  
  pinMode(button12, INPUT_PULLUP);    
  pinMode(tea,OUTPUT); //set up relays
  pinMode(lem,OUTPUT);

  // set up the LCD's number of columns and rows:
  lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight

  /*Your code starts here*/

  //display info to user, max 32 characters, 16x2 display
  //clear display
  lcd.clear();
  // Print a message to the LCD.
  lcd.print("The Palmernator");
  // set the cursor to column 0, line 1 (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the oz options 
  lcd.print("4oz, 8oz, 12oz");
}

void loop() {
 
  //user input 4, 8, or 12 oz via buttons
  //solenoids open for time based on oz. requested
  if (digitalRead(button4) == LOW){             //if 4oz button is pressed
    lcd.clear();
    lcd.print("FORE...");
    digitalWrite(tea, HIGH); //open solenoid 1, tea
    digitalWrite(lem, HIGH); //open solenoid 2, lemonaid
    delay(2000);  
    digitalWrite(lem,LOW); //close 1
    delay(2000);
    digitalWrite(tea,LOW); //close 2
    end(); //go to end function
  }

  else if (digitalRead(button8) == LOW){             //if 8oz button is pressed
    lcd.clear();
    lcd.print("FORE...");
    digitalWrite(tea, HIGH); //open solenoid 1, tea
    digitalWrite(lem, HIGH); //open solenoid 2, lemonaid 
    delay(4000);
    digitalWrite(lem,LOW);//close 1
    delay(4000); 
    digitalWrite(tea,LOW);//close 2
    end(); //go to end function
  }

  else if (digitalRead(button12) == LOW){            //if 8oz button is pressed
    lcd.clear();
    lcd.print("FORE...");
    digitalWrite(tea, HIGH); //open solenoid 1, tea
    digitalWrite(lem, HIGH); //open solenoid 2, lemonaid  
    delay(6000); 
    digitalWrite(lem,LOW);//close 1
    delay(6000); 
    digitalWrite(tea,LOW);//close 2
    end(); //go to end function
  }
}         
  void end() { 
    //Turn on motor
    //waitmotor
    //off motor
   lcd.clear();    //display done
   lcd.setCursor(0,0); 
   lcd.print("Hole In One!");
   delay(10000);//wait 10s

   lcd.clear();
   // Print a message to the LCD.
   lcd.print("The Palmer-nator");
   // set the cursor to column 0, line 1 (note: line 1 is the second row, since counting begins with 0):
   lcd.setCursor(0, 1);
   // print the oz options 
   lcd.print("4oz, 8oz, 12oz");
  }


