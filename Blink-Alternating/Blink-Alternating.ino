/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/

const int OUTPUT_LED_3 = 8;
const int OUTPUT_LED_2 = 10;
const int OUTPUT_LED_1 = 12;
//const int BAUD_RATE = 9600;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(OUTPUT_LED_1, OUTPUT);
  pinMode(OUTPUT_LED_2, OUTPUT);
  pinMode(OUTPUT_LED_3, OUTPUT);

  //Serial.begin(BAUD_RATE);
}



// the loop function runs over and over again forever
void loop() {

  digitalWrite(OUTPUT_LED_1, HIGH);  // change state of the LED by setting the pin to the HIGH voltage level
  digitalWrite(OUTPUT_LED_2, LOW);
  digitalWrite(OUTPUT_LED_3, LOW);
  //Serial.println("Criss");
  
  delay(300);                      // wait for a second
  
  digitalWrite(OUTPUT_LED_1, LOW);   // change state of the LED by setting the pin to the LOW voltage level
  digitalWrite(OUTPUT_LED_2, HIGH);
  digitalWrite(OUTPUT_LED_3, HIGH);
  //Serial.println("Cross");
  delay(300);                      // wait for a second
}
