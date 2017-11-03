#include "LcdTools.h"

LcdTools::LcdTools() {
    // TODO Auto-generated constructor stub

}

LcdTools::~LcdTools() {
    // TODO Auto-generated destructor stub
}

void LcdTools::print_bitmap(const char *bitmap, Adafruit_SSD1306_I2c* oled,
        int imgx, int imgy, int posx, int posy, bool flip) {
    for (int ih = 1; ih <= imgy; ih++) {
        for (int iw = 1; iw <= imgx; iw++) {
            char pixel = bitmap[imgx * (ih - 1) + iw - 1];
            //invert color
            uint16_t d_color = flip ? BLACK : WHITE;
            uint16_t bg_color = flip ? WHITE : BLACK;
            if (pixel == 1) {
                oled->drawPixel(iw + posx, ih + posy, d_color);
            } else {
                oled->drawPixel(iw + posx, ih + posy, bg_color);
            }
        }
    }
}
