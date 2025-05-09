#include "Alarm.h"
#include "SevenSegmentDisplay.h"
#include <iostream>
#include <ctime>
#include <windows.h>
#include <mmsystem.h>

void Alarm::setAlarm(const std::string& time) {
    alarmTime = time;
    alarmRinging = false;
}

void Alarm::update() {
    if (isAlarmTime()) {
        alarmRinging = true;
    }
}

void Alarm::render() {
    if (alarmRinging) {
        std::string message = "ALARM!";
        SevenSegmentDisplay::display(message);
    }
}

bool Alarm::isAlarmTime() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    char buffer[6];
    std::strftime(buffer, sizeof(buffer), "%H:%M", localTime);
    return std::string(buffer) == alarmTime;
}

bool Alarm::isAlarmRinging() const {
    return alarmRinging;
}
