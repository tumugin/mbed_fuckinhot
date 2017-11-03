#pragma once
#include <array>
#include "mbed.h"
using namespace std;

class HDC1000 {
public:
    HDC1000(I2C* i2c,char addr);
    void init();
    void update();
    virtual ~HDC1000();
    double Temperature;
    double Humidity;
private:
    I2C* i2cptr;
    char addrptr;
};
