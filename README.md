# Magic-8-Ball
*Michael D'Argenio  
mjdargenio@gmail.com  
https://dargenio.dev  
https://github.com/mjdargen  
September 19, 2019*   
\
\
*Ask the Magic 8-Ball any question.  
*https://en.wikipedia.org/wiki/Magic_8-Ball  
*An Arduino-version of the fortune-telling toy.  
*Uses 16x2 LCD Screen and switch of your choice.  
\
\
**The LCD circuit (16x2):**
* LCD RS pin to digital pin 7
* LCD Enable pin to digital pin 8
* LCD D4 pin to digital pin 9
* LCD D5 pin to digital pin 10
* LCD D6 pin to digital pin 11
* LCD D7 pin to digital pin 12
* LCD R/W pin to ground
 10K potentiometer:
* ends to +5V and ground
* wiper to LCD VO pin (pin 3)
[//]: # (Hello)
      \
      \
**Switch**
* A tilt ball switch works nicely to mimic an actual magic 8-ball, but any switch will do.
* Digital input 2
* Configured as external interrupt
* Pulled down with 10k resistor to GND
* Other end of switch connected to 5V
