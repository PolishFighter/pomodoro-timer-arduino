#include <Pomodoro.h>
#include <Arduino.h>

Pomodoro::Pomodoro(uint16_t breakTime, uint16_t focusTime, uint8_t buzz_pin, uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows )
: _breakTime{breakTime}, _focusTime{focusTime},_buzzPin{buzz_pin}, _lcd{lcd_Addr, lcd_cols, lcd_rows}
{
}

void Pomodoro::init(){
    _lcd.init();
    _lcd.backlight();
    _lcd.setCursor(0, 0);
    pinMode(_buzzPin, OUTPUT); 
    _time = _focusTime;
    _clockAnim = 0;

    for(int i = 0; i < 8; i++)
        _lcd.createChar(i, clockChar[i]);
}

void Pomodoro::update(){
    delay(1000);
    _time--;
    if(_time <= 0){
        _state = _state == State::Break ? State::Focus : State::Break;
        _time = _state == State::Break ? _breakTime : _focusTime;
        buzz();
    }
    updateLcd();
}

void Pomodoro::updateLcd(){
    _lcd.clear();
    _lcd.setCursor(4,1);
    _clockAnim++;
    _clockAnim = _clockAnim % 8;
    _lcd.write(_clockAnim);

    _lcd.setCursor(6,1);

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

    //Printing state on screen

    _lcd.setCursor(3, 0);

    switch (_state){
        case State::Break:
            _lcd.print("Break Time");
            break;
        
        case State::Focus:
            _lcd.print("Focus Time");
            break;
    }
}

void Pomodoro::buzz(){
    tone(_buzzPin, 1000);
    delay(1000);
    noTone(_buzzPin);
}