#include <Pomodoro.h>
#include <Arduino.h>

Pomodoro::Pomodoro(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows )
: _lcd{lcd_Addr, lcd_cols, lcd_rows}
{
}

void Pomodoro::init(){
    _lcd.init();
    _lcd.backlight();
    _lcd.setCursor(0, 0);
    _time = _focusTime;
}

void Pomodoro::update(){
    delay(1000);
    _time--;
    if(_time <= 0){
        _state = _state == State::Break ? State::Focus : State::Break;
        _time = _state == State::Break ? _breakTime : _focusTime;
    }
    updateLcd();
}

void Pomodoro::updateLcd(){
    _lcd.clear();
    _lcd.setCursor(3,0);

    uint16_t minutes = _time/60;
    uint16_t seconds = _time%60;

    if(minutes<10){
        _lcd.print("0");
    }
    _lcd.print(minutes);

    _lcd.print(":");
    
    if(seconds < 10){
        _lcd.print("0");
    }
    _lcd.print(seconds);
}