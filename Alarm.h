#pragma once
#include <string>

class Alarm {
public:
    void setAlarm(const std::string& time);
    void update();
    void render();
    bool isAlarmRinging() const;

private:
    std::string alarmTime;
    bool alarmRinging = false;
    bool isAlarmTime();
};
