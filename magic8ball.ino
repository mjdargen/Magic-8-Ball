/*
  
  Magic 8-Ball
  Michael D'Argenio
  mjdargenio@gmail.com
  https://dargenio.dev
  https://github.com/mjdargen
  September 19, 2019

  *Ask the Magic 8-Ball any question.
  *https://en.wikipedia.org/wiki/Magic_8-Ball
  *An Arduino-version of the fortune-telling toy.
  *Uses 16x2 LCD Screen and switch of your choice.

  The LCD circuit (16x2):
  * LCD RS pin to digital pin 7
  * LCD Enable pin to digital pin 8
  * LCD D4 pin to digital pin 9
  * LCD D5 pin to digital pin 10
  * LCD D6 pin to digital pin 11
  * LCD D7 pin to digital pin 12
  * LCD R/W pin to ground
  * 10K potentiometer:
  * ends to +5V and ground
  * wiper to LCD VO pin (pin 3)

  Switch:
  A tilt ball switch works nicely to mimic an
  actual magic 8-ball, but any switch will do.
  * Digital input 2
  * Configured as external interrupt
  * Connected with 10k resistor to GND
  * Other end of switch connected to 5V

*/

#include "magic8ball.h"

#define SWITCH_PIN  2

// name the states of state machine
// initialize global state variable
typedef enum {INITIAL, WAIT, RESPONSE} states;
states nextState = INITIAL;

/* set up function */
void setup() {
  // set up pin and interrupt for switch
  pinMode(SWITCH_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(SWITCH_PIN), trigger, RISING);

  // seed random() function so that we get a different order
  randomSeed(analogRead(1));
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // print welcome message to the LCD.
  lcd.print("Welcome!");
  delay(2000);
}

/* main while loop function */
void loop() {

  // switch statement state machine
  switch (nextState) {
  
  // intial state, print magic 8-ball
  case INITIAL:
    lcd.clear();
    lcd.print("Magic 8-Ball");
    nextState = WAIT;
    break;
  
  // do nothing state, wait for interrupt
  case WAIT:
    break;

  // reponse state, determine/print response
  case RESPONSE:
    magic8ball();
    nextState = INITIAL;
    break;
  }
}

/* randomly selects from responses and prints it */
void magic8ball() {
  // generate random number between 0 and 19 to select and print random response
  oneLineScroll(0,responses[random(RESPONSES)]);
}

/* interrupt service routine triggered by button press */
void trigger() {
  nextState = RESPONSE;
}

/*
If string is too large to print, scrolls text on single line.
0 = first line; 1 = second line
Reuse for other projects! 
*/
void oneLineScroll (int line, String text) {
  // set cursor on intended line and print first 16 chars
  lcd.clear();
  lcd.setCursor(0, line);
  // print first 16 characters
  lcd.print(text.substring(0,15));
  delay(750);
  // for every additional letter, shift in from right
  if (text.length()>16) {
    for (int i = 0; i <= (text.length()-16); i++) {
      lcd.setCursor(0, line);
      lcd.print(text.substring(i,i+16));
      delay(400);
    }
  }
  delay(1500);
}
