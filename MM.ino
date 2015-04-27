#include <Servo.h> 
 
Servo armservo;  					// Creates servo object to control the arm servo.
							// (a maximum of eight servo objects can be created.)
 
int tdpotpin = 0;  					// Identifies the analog pin used to connect the potentiometer.
int touchdelay;    					// Variable to read the value from the analog pin.
int restpos = 0;    					// Variable to store the servo's resting position.
int touchpos = 120;    					// Variable to store the servo's touching position.
int mintd = 1500;    					// Variable to store the minimum touch delay.
int maxtd = 21600000;    				// Variable to store the maximum touch delay.
 
void setup() 
{ 
  armservo.attach(9);  					// attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() 
{ 
  touchdelay = analogRead(potpin);            		// reads the value of the potentiometer (value between 0 and 1023) 
  touchdelay = map(touchdelay, 0, 1023, mintd, maxtd);     	// http://www.arduino.cc/en/Reference/Map
  armservo.write(touchpos);              		// Tells servo to move the arm and touch the screens.
  delay(1500);                       			// Waits for the servo to reach the position.
  armservo.write(restpos);              		// Tells servo to move the arm back to the resting position.
  delay(touchdelay);                       		// Waits the amount of time set by the potentiometer/user.
}