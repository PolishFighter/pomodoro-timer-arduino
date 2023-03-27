#pragma once

#include <LiquidCrystal_I2C.h>

class Pomodoro 
{
public:
    Pomodoro(uint8_t lcd_Addr = 0x27, uint8_t lcd_cols = 16, uint8_t lcd_rows = 2);
    void init();
    void update();
private:
    enum class State {Focus, Break};
    LiquidCrystal_I2C _lcd;
    State _state;
    uint16_t _time;
    uint16_t _breakTime = 60 * 5;
    uint16_t _focusTime = 60 * 25;

    void updateLcd();
};