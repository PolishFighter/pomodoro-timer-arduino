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
    uint8_t _clockAnim;
    uint16_t _breakTime = 60 * 5;
    uint16_t _focusTime = 60 * 25;
    uint8_t clockChar[8][8] = {{
        0b00000,
        0b01110,
        0b10101,
        0b10101,
        0b10001,
        0b01110,
        0b00000,
        0b00000},
        
        {
        0b00000,
        0b01110,
        0b10011,
        0b10101,
        0b10001,
        0b01110,
        0b00000,
        0b00000},

        {
        0b00000,
        0b01110,
        0b10001,
        0b10111,
        0b10001,
        0b01110,
        0b00000,
        0b00000},

        {
        0b00000,
        0b01110,
        0b10001,
        0b10101,
        0b10011,
        0b01110,
        0b00000,
        0b00000},

        {
        0b00000,
        0b01110,
        0b10001,
        0b10101,
        0b10101,
        0b01110,
        0b00000,
        0b00000},

        {
        0b00000,
        0b01110,
        0b10001,
        0b10101,
        0b11001,
        0b01110,
        0b00000,
        0b00000},
        
        {
        0b00000,
        0b01110,
        0b10001,
        0b11101,
        0b10001,
        0b01110,
        0b00000,
        0b00000},

        {
        0b00000,
        0b01110,
        0b11001,
        0b10101,
        0b10001,
        0b01110,
        0b00000,
        0b00000}  
        };

    void updateLcd();
};