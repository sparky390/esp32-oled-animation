/*
  Project: ESP32 OLED Animation
  Author: Surya.S
  GitHub: https://github.com/sparky390/esp32-oled-animation
  Description: SSD1106 OLED animation (128x64)

  Made with ❤️
*/
#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include "VideoFrame.h"   // your frame file

// ✅ Use SH1106 driver (best match for SSD1106)
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0);

// Timing
unsigned long previousMillis = 0;
int currentFrame = 0;

void setup() {
  Serial.begin(115200);

  // ✅ ESP32 default I2C pins
  Wire.begin(21, 22);

  // ✅ Stable I2C speed
  Wire.setClock(400000);

  u8g2.begin();

  // Optional: max contrast
  u8g2.setContrast(255);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= FRAME_DELAY) {
    previousMillis = currentMillis;

    u8g2.clearBuffer();

    // 🔥 IMPORTANT: Use drawBitmap (NOT drawXBMP)
    // 128px width → 128/8 = 16 bytes per row
    // height = 64
    // offset X = 2 (fix SSD1106 shift)
    u8g2.drawBitmap(2, 0, 16, 64, video_frames[currentFrame]);

    u8g2.sendBuffer();

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
