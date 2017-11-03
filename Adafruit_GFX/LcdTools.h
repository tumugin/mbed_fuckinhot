#pragma once
#include "Adafruit_SSD1306.h"

class LcdTools {
public:
    LcdTools();
    virtual ~LcdTools();
    static void print_bitmap(const char *bitmap, Adafruit_SSD1306_I2c* oled,
            int imgx, int imgy, int posx = 0, int posy = 0, bool flip = true);
};
