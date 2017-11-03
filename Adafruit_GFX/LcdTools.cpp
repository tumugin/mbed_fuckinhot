#include "LcdTools.h"

LcdTools::LcdTools() {
    // TODO Auto-generated constructor stub

}

LcdTools::~LcdTools() {
    // TODO Auto-generated destructor stub
}

void LcdTools::print_bitmap(const char* bitmap, Adafruit_SSD1306_I2c* oled) {
    for (int ih = 1; ih <= 64; ih++) {
        for (int iw = 1; iw <= 128; iw++) {
            char pixel = bitmap[128 * (ih - 1) + iw - 1];
            //invert color
            if (pixel != 1) oled->drawPixel(iw, ih, WHITE);
        }
    }
}
