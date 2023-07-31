//in this file we will excecute the main file in this mechaniced indoor garden
//this file will be the main function that will be excecuted in the arduino

//the code consists in the gathering of the data from the sensors and the actuators and watering the plants
//sensors to consider are: temperature, humidity, soil moisture, light
//the plant is watered by a soleinoid valve that is activated by a relay


//macros

#define SOLENOID_PIN 2
#define LIGHT_PIN 8
#define HUMIDITY_PIN A2
#define TEMPERATURE_PIN A1
#define MOISTURE_PIN A0



//libraries
////import <stdio.h>
////import <stdlib.h>



//auxiliar functions

//variables

//setup
void setup() {
  // put your setup code here, to run once:
    //we then initialize the sensors
    pinMode(LIGHT_PIN, INPUT);
    pinMode(HUMIDITY_PIN, INPUT);
    pinMode(TEMPERATURE_PIN, INPUT);
    pinMode(MOISTURE_PIN, INPUT);    

    //we then initialize the actuators
    pinMode(SOLENOID_PIN, OUTPUT);
    digitalWrite(SOLENOID_PIN, LOW);

    //we then initialize the Serial communication
    Serial.begin(9600);
    
}

//loop
void loop() {
  // put your main code here, to run repeatedly:
    //we create the variables that will store the data from the sensors
    int light, humidity, temperature, moisture;
    //we then read the sensors
    light = analogRead(LIGHT_PIN);
    humidity = analogRead(HUMIDITY_PIN);
    temperature = analogRead(TEMPERATURE_PIN);
    moisture = analogRead(MOISTURE_PIN);

    //we normalize the data
    //crate the variables that will store the normalized data
    int Light, Humidity, Temperature, Moisture;
    Light = map(light, 0, 1023, 0, 100);
    Humidity = map(humidity, 0, 1023, 0, 100);
    Temperature = map(temperature, 0, 1023, 0, 100);
    Moisture = map(moisture, 0, 1023, 0, 100);

    //we then print the data
    Serial.print("Light: ");
    Serial.print(Light);
    Serial.println("%");
    Serial.print("Humidity: ");
    Serial.print(Humidity);
    Serial.println("%");
    Serial.print("Temperature: ");
    Serial.print(Temperature);
    Serial.println("%");
    Serial.print("Moisture: ");
    Serial.print(Moisture);
    Serial.println("%");
    Serial.println(" ");
    
    //we print the state in which the soleinoid valve is
    Serial.print("Soleinoid valve: ");
    if(digitalRead(SOLENOID_PIN) == HIGH){
        Serial.println("ON");} else {
        Serial.println("OFF");
    }
    
}