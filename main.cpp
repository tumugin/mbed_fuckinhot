#include "main.hpp"
#include "mbed.h"
#include "HDC1000/HDC1000.h"
#include "Adafruit_GFX/Adafruit_SSD1306.h"
#include "Adafruit_GFX/LcdTools.h"
#include <string>
using namespace std;

const char LCD_I2C_ADDR = 0x3C;
const char TMPSENS_I2C_ADDR = 0x40;

int main(){
    I2C i2c(I2C_SDA, I2C_SCL);
    Adafruit_SSD1306_I2c gOled2(i2c, LCD_I2C_ADDR << 1);
    Serial pc(USBTX, USBRX);
    HDC1000 hdc(&i2c,TMPSENS_I2C_ADDR << 1);
    hdc.init();
    while(true){
        hdc.update();
        pc.printf(string("T:" + to_string(hdc.Temperature) + " H:" + to_string(hdc.Humidity) + "\r\n").c_str());
        wait(1);
    }
    return 0;
}
