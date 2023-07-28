//in this file we will excecute the main file in this mechaniced indoor garden
//this file will be the main function that will be excecuted in the arduino

//the code consists in the gathering of the data from the sensors and the actuators and watering the plants
//sensors to consider are: temperature, humidity, soil moisture, light
//the plant is watered by a soleinoid valve that is activated by a relay


//macros

//libraries
////import <stdio.h>
////import <stdlib.h>



//auxiliar functions

//variables

//setup
void setup() {
  // put your setup code here, to run once:
    //we first initialize the serial communication 
    Serial.begin(9600);
    //we then initialize the sensors
    //we then initialize the actuators
}

//loop
void loop() {
  // put your main code here, to run repeatedly:
}