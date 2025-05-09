#include "Timer.h"
#include "SevenSegmentDisplay.h"
#include <iostream>
#include <sstream>
#include <windows.h>
#include <mmsystem.h>

void Timer::setTimer(const std::string& duration) {
    int minutes = 0, seconds = 0;
    std::stringstream ss(duration);
    ss >> minutes;
    ss.ignore(1);
    ss >> seconds;
    remainingTime = minutes * 60 + seconds;
    running = true;
}

void Timer::update() {
    if (remainingTime > 0) {
        remainingTime--;
        render();
        if (remainingTime == 0) {
            running = false;
        }
    } else {
        running = false;
    }
}

void Timer::render() {
    std::string time = formatTime(remainingTime);
    SevenSegmentDisplay::display(time);
}

std::string Timer::formatTime(int seconds) {
    int minutes = seconds / 60;
    seconds %= 60;
    char buffer[6];
    std::sprintf(buffer, "%02d:%02d", minutes, seconds);
    return std::string(buffer);
}

bool Timer::isRunning() const {
    return running;
}
