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

// Physical LED's
const uint8_t OUTPUT_LED_3 = 8;
const uint8_t OUTPUT_LED_2 = 10;
const uint8_t OUTPUT_LED_1 = 12;

//const uint8_t BAUD_RATE = 9600;

// global index
uint8_t i = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(OUTPUT_LED_1, OUTPUT);
  pinMode(OUTPUT_LED_2, OUTPUT);
  pinMode(OUTPUT_LED_3, OUTPUT);

  //Serial.begin(BAUD_RATE);
}



// the loop function runs over and over again forever
void loop()
{
  write_led_binary(i++);
  
  //Serial.println("Cross");
  delay(500);                      // wait for a second
}

void write_led_binary(int index)
{
  uint8_t OUTPUT_1 = LOW;
  uint8_t OUTPUT_2 = LOW;
  uint8_t OUTPUT_3 = LOW;

  if (i % 2 == 1) // odd value
    OUTPUT_1 = HIGH; 

  if (i % 4 >= 2) // every other group of 2 integers
    OUTPUT_2 = HIGH;

  if (i % 8 >= 4) // odd value
    OUTPUT_3 = HIGH;

  digitalWrite(OUTPUT_LED_1, OUTPUT_1);
  digitalWrite(OUTPUT_LED_2, OUTPUT_2);
  digitalWrite(OUTPUT_LED_3, OUTPUT_3);
}
