#ifndef DL2416T_
#define DL2416T_

#include <Arduino.h>

class DL2416T {
  private:
    uint8_t d0Pin;
    uint8_t d1Pin;
    uint8_t d2Pin;
    uint8_t d3Pin;
    uint8_t d4Pin;
    uint8_t d5Pin;
    uint8_t d6Pin;
    uint8_t a0Pin;
    uint8_t a1Pin;
    uint8_t wrPin;
  public:
    void init(uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t);
    void displayChar(char,uint8_t);
};

#endif
