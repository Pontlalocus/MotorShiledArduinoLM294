

/*
    Objective
    =========

    This software is created to test functionality of L293D Motor Shield

    Hardware Requirements
    =====================

    1 x Arduino Uno
    4 x GA12-N20 Motor - 
        Or Similar to DC 6V 30RPM 3mm Shaft Mini Metal Gearwheel Gear Motor GA12-N20 
        Reference:  https://www.amazon.com/gp/product/B00SL1R7E2/ref=oh_aui_detailpage_o04_s00?ie=UTF8&psc=1
    1 x L293D Motor Drive Shield 
        Reference: https://www.amazon.com/gp/product/B00813HBBO/ref=oh_aui_detailpage_o03_s00?ie=UTF8&psc=1

    4 x Red wires for the motors
    4 x Black Wires for the motors
    1 x Power Supply for Arduino Uno
    1 x USB cable for Arduino Uno

    Software Requirements
    =====================
    Install Library in the Arduino GUI
    DC Motor adafruit-Adafruit-Motor-Shield-library
    Filename: adafruit-Adafruit-Motor-Shield-library-1.0.0-3-g99381df
    Link: https://github.com/adafruit/Adafruit-Motor-Shield-library/zipball/master
    Include Nambe: <AFMotor.h>

    Disclaimer
    ============

    Created by:  Pontlalocus 
    Date: 1/5/2017
    Rev:0.01

    License
    ========
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
  
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
  
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
  
*/


#include <SD.h>21

#include <AFMotor.h>  // this is important ot call AFMotor Library refer to description above for reference

// We use the AF_DCMotor function to create 4 motors with 1KHz frequency, this is clock frquncey divided by 64 and it is the slowest Clock source since motors does not need high frequency.
// Other options that can be used are 
// MOTOR12_64KHZ   register clock
// MOTOR12_8KHZ    register clock divide by 8
// MOTOR12_2KHZ    register clock divide by 32
// MOTOR12_1KHZ    register clock divide by 64

AF_DCMotor motor1(1, MOTOR12_1KHZ); // create motor #1, 1KHz pwm
AF_DCMotor motor2(2, MOTOR12_1KHZ); // create motor #2, 1KHz pwm
AF_DCMotor motor3(3, MOTOR12_1KHZ); // create motor #3, 1KHz pwm
AF_DCMotor motor4(4, MOTOR12_1KHZ); // create motor #4, 1KHz pwm

void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps - most common we have tested to use it up to 115200 and down to 1200 Hz.  Important Note: Remember to setup your arduino serial monitor accordingly with the frequency you selected
  Serial.println("Motor test Started!");    // Serial Data message with end of line
  motor1.setSpeed(60); // set the speed of Motor #1 to 60/255.  The max will depend on your power supply -- be careful not to damage your chips with bigger motors or higher voltage power supply
  motor2.setSpeed(60); // set the speed of Motor #2 to 60/255
  motor3.setSpeed(60); // set the speed of Motor #3 to 60/255
  motor4.setSpeed(60); // set the speed of Motor #4 to 60/255
}


void loop() {
  Serial.println("tick");
  motor1.run(FORWARD); // turn Motor #1 on going forward
  motor2.run(FORWARD); // turn Motor #2 on going forward
  motor3.run(FORWARD); // turn Motor #3 on going forward
  motor4.run(FORWARD); // turn Motor #4 on going forward
  delay(500); //  Wait 1 second = 1000ms on Stop mode
  Serial.println("tock"); // Serial Data message with end of line
  motor1.run(BACKWARD); // turn Motor #1 on going backward
  motor2.run(BACKWARD); // turn Motor #2 on going backward
  motor3.run(BACKWARD); // turn Motor #3 on going backward
  motor4.run(BACKWARD); // turn Motor #4 on going backward
  delay(500); //Wait 1 second = 1000ms on Stop mode
  Serial.println("tack"); // Serial Data message with end of line
  motor1.run(RELEASE); // Motor #1 Stopped
  motor2.run(RELEASE); // Motor #2 Stopped
  motor3.run(RELEASE); // Motor #3 Stopped
  motor4.run(RELEASE); // Motor #4 Stopped
  delay(500);  //Wait 1 second = 1000ms on Stop mode
}

/*  EOF */
