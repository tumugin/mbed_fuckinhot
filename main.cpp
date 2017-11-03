#include "main.hpp"
#include "mbed.h"
#include "HDC1000/HDC1000.h"
#include "Adafruit_GFX/Adafruit_SSD1306.h"
#include "Adafruit_GFX/LcdTools.h"
#include "fuckinhot.hpp"
#include <string>
using namespace std;

const char LCD_I2C_ADDR = 0x3C;
const char TMPSENS_I2C_ADDR = 0x40;

int main() {
    I2C i2c(I2C_SDA, I2C_SCL);
    Adafruit_SSD1306_I2c oled(i2c, LCD_I2C_ADDR << 1, 64, 128);
    Serial pc(USBTX, USBRX);
    HDC1000 hdc(&i2c, TMPSENS_I2C_ADDR << 1);
    hdc.init();
    while (true) {
        hdc.update();
#ifdef DEBUG
        pc.printf(
                string(
                        "T:" + to_string(hdc.Temperature) + " H:"
                                + to_string(hdc.Humidity) + "\r\n").c_str());
#endif
        oled.clearDisplay();
        LcdTools::print_bitmap(fuckinhot_face, &oled, 128, 64, 0, 0);
        if (hdc.Temperature < 20) {
            //too cold
            LcdTools::print_bitmap(cap_fuckincold, &oled, 128, 19, 0, 45,
                    false);
        } else if (hdc.Temperature > 20 && hdc.Temperature < 25) {
            //good
            LcdTools::print_bitmap(cap_fuckintekion, &oled, 128, 19, 0, 45,
                    false);
        } else {
            //too hot
            LcdTools::print_bitmap(cap_fuckinhot, &oled, 128, 19, 0, 45, false);
        }
        oled.setTextColor(BLACK);
        oled.setTextSize(2);
        oled.setTextCursor(10, 10);
        //MAKE SURE TO COMPILE WITH -u _printf_float OPTION!!!!
        oled.printf("%.1fC", hdc.Temperature);
        oled.setTextCursor(10, 25);
        oled.printf("%.1f%%", hdc.Humidity);
        oled.display();
        wait(1);
    }
    return 0;
}
