
// UHD ACM
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <string.h>

// Physical LED's
const uint8_t OUTPUT_LED_1 = 9;
const uint8_t OUTPUT_LED_2 = 10;
const uint8_t OUTPUT_LED_3 = 11;
const uint8_t OUTPUT_LED_4 = 12;
const uint8_t OUTPUT_LED_5 = 13;

const uint8_t Pulldown_Button_PIN = 2;

// global index
uint8_t i = 0;

// global delay wait
uint8_t DELAY = 115;

// Adress to write at I2C Protocool
const uint8_t I2CAdress = 0x27;
const uint8_t Screen_Char_Count = 16;
const uint8_t Screen_Line_Count = 2;

// Initialize Global I2C Handler on the stack
LiquidCrystal_I2C lcd_handler(I2CAdress, Screen_Char_Count, Screen_Line_Count);
uint8_t LEN;
String message = ". . . . . . Interested in Computer Science, Cyber Security, Software Engineering, Information Technology? . . . .  Join ACM ! . . . ";
uint8_t m_index = 0;        // message index


// Function declarations
void write_led_binary(uint8_t);
void write_message(const uint8_t);


// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(OUTPUT_LED_1, OUTPUT);
  pinMode(OUTPUT_LED_2, OUTPUT);
  pinMode(OUTPUT_LED_3, OUTPUT);
  pinMode(OUTPUT_LED_4, OUTPUT);
  pinMode(OUTPUT_LED_5, OUTPUT);

  pinMode(Pulldown_Button_PIN, INPUT);

  lcd_handler.init(); 
  lcd_handler.backlight();
  lcd_handler.noBlink();

  LEN = message.length();
}


void loop()
{
  uint8_t button_state = digitalRead(Pulldown_Button_PIN);

  write_led_binary(i++);

  write_message(button_state);

  delay(DELAY);
}

void write_message(const uint8_t _button_read)
{

  lcd_handler.setCursor(0, 0);  

  if (_button_read == HIGH)
  {
    lcd_handler.print("Binary count:   ");
    lcd_handler.setCursor(13, 1);
    lcd_handler.print(i % 64);
  }
  else
  {

    // calculate circling message index'ies
    if (m_index + Screen_Char_Count > LEN - 1) // do we risk going out of bounds?
    {
      uint8_t index_overflow_characters = (m_index + Screen_Char_Count) - LEN;

      // Concatenate both sub strings
      lcd_handler.print(
        message.substring(m_index, LEN) +
        message.substring(0, index_overflow_characters));

    }
    else  // array bound check is safe, we'll print the entire substring
      lcd_handler.print(
        message.substring(m_index, m_index + Screen_Char_Count));
  
    // update message index
    m_index = ++m_index % LEN;
  }
}

void write_led_binary(uint8_t index)
{
  uint8_t OUTPUT_1 = LOW;
  uint8_t OUTPUT_2 = LOW;
  uint8_t OUTPUT_3 = LOW;
  uint8_t OUTPUT_4 = LOW;
  uint8_t OUTPUT_5 = LOW;

  if (i % 2 == 1) // odd value
    OUTPUT_1 = HIGH; 

  if (i % 4 >= 2) // every other group of 2 integers
    OUTPUT_2 = HIGH;

  if (i % 8 >= 4) // every other group of 4 integers
    OUTPUT_3 = HIGH;

  if (i % 16 >= 8) // every other group of 8 integers
    OUTPUT_4 = HIGH;

  if (i % 32 >= 16) // every other group of 16 integers
    OUTPUT_5 = HIGH;

  digitalWrite(OUTPUT_LED_1, OUTPUT_1);
  digitalWrite(OUTPUT_LED_2, OUTPUT_2);
  digitalWrite(OUTPUT_LED_3, OUTPUT_3);
  digitalWrite(OUTPUT_LED_4, OUTPUT_4);
  digitalWrite(OUTPUT_LED_5, OUTPUT_5);
}