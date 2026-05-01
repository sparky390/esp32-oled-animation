/*
  Project: ESP32 OLED Animation
  Author: Surya.S
  GitHub: https://github.com/sparky390/esp32-oled-animation
  Description: SSD1306 OLED animation (128x64)

  Made with ❤️
*/
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "VideoFrame.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

unsigned long previousMillis = 0;
int currentFrame = 0;

void setup() {
  Serial.begin(115200);

  // ✅ For normal ESP32 (NodeMCU)
  Wire.begin(21, 22);  
  Wire.setClock(800000); // Fast I2C for smooth animation

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 not found");
    while (true);
  }

  display.clearDisplay();
  display.display();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= FRAME_DELAY) {
    previousMillis = currentMillis;

    display.clearDisplay();
    display.drawBitmap(0, 0, video_frames[currentFrame], 128, 64, WHITE);
    display.display();

    currentFrame++;
    if (currentFrame >= TOTAL_FRAMES) {
      currentFrame = 0;
    }
  }
}
// ==========================================
// Thanks for watching!
// Follow @sparky.fpv on Instagram 🔥
// ==========================================