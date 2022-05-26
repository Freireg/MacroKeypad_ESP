#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <BleKeyboard.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SparkFunVKeyVoltageKeypad.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define FONT_SIZE     0x01

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
BleKeyboard bleKeyboard;
VKey keypad(4, VKey::THREE);
uint32_t keypressed = 0;

void setup() {
  Serial.begin(9600);
  bleKeyboard.begin();
  Wire.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.setTextColor(WHITE);
  display.setTextSize(FONT_SIZE);
}

void loop() {
  VKey::eKeynum k;  // Variable to receive the key indication
  String DisplayPrint;

  if(bleKeyboard.isConnected()) 
  {
    if((keypad.checkKeys(k)) && (k != 0))
    {
      switch (k)
      {
      case 0x01:
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.press(KEY_NUM_1);
        bleKeyboard.releaseAll();
        DisplayPrint = "CTRL+ALT+1";
        break;
      case 0x02:
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.press(KEY_NUM_2);
        bleKeyboard.releaseAll();
        DisplayPrint = "CTRL+ALT+2";
        break;
      case 0x03:
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.press(KEY_NUM_3);
        bleKeyboard.releaseAll();
        DisplayPrint = "CTRL+ALT+3";
        break;
      case 0x04:
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.press(KEY_NUM_4);
        bleKeyboard.releaseAll();
        DisplayPrint = "CTRL+ALT+4";
        break;
      case 0x05:
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.press(KEY_NUM_5);
        bleKeyboard.releaseAll();
        DisplayPrint = "CTRL+ALT+5";
        break;
      case 0x06:
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.press(KEY_NUM_6);
        bleKeyboard.releaseAll();
        DisplayPrint = "CTRL+ALT+6";
        break;
      case 0x07:
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.press(KEY_NUM_7);
        bleKeyboard.releaseAll();
        DisplayPrint = "CTRL+ALT+7";
        break;
      case 0x08:
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.press(KEY_NUM_8);
        bleKeyboard.releaseAll();
        DisplayPrint = "CTRL+ALT+8";
        break;
      case 0x09:
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.press(KEY_NUM_9);
        bleKeyboard.releaseAll();
        DisplayPrint = "CTRL+ALT+9";
        break;
      case 0x0A:
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.print("y");
        bleKeyboard.releaseAll();
        DisplayPrint = "CTRL+ALT+Y";
        break;
      case 0x0B: /* CTRL + ALT + I */
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.print("i");
        bleKeyboard.releaseAll();
        DisplayPrint = "CTRL+ALT+I";
        break;
      case 0x0C: /* CTRL + ALT + T */
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.print("t");
        bleKeyboard.releaseAll();
        DisplayPrint = "CTRL+ALT+T";
        break;
      default:
        break;
      }
      display.clearDisplay();
      display.print(DisplayPrint);
      display.display();
    }
  }
  else
  {
    display.clearDisplay();
    display.print("Waiting for conection.");
    display.display();
    delay(100);
    display.clearDisplay();
    display.print("Waiting for conection..");
    display.display();
    delay(100);
    display.clearDisplay();
    display.print("Waiting for conection...");
    display.display();
    delay(100);
  }
    
  delay(50);
}
