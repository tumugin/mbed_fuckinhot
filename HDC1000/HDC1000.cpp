#include "HDC1000.h"

HDC1000::HDC1000(I2C* i2c,char addr) {
    i2cptr = i2c;
    addrptr = addr;
}

HDC1000::~HDC1000() {

}

void HDC1000::init(){
    wait_ms(15);
    array<char,3> initary = {0x02,0x10,0x00};
    i2cptr->write(addrptr,initary.data(),initary.size(),false);
}

void HDC1000::update(){
    array<char,1> initary = {0x00};
    i2cptr->write(addrptr,initary.data(),initary.size(),false);
    wait_ms(30);
    array<char,4> buffer;
    i2cptr->read(addrptr,buffer.data(),buffer.size());
    int temp = (buffer[0] << 8) | buffer[1];
    int hudi = (buffer[2] << 8) | buffer[3];
    Temperature = (temp / 65536.0) * 165.0 - 40.0;
    Humidity = ((hudi / 65536.0 ) * 100.0);
}
