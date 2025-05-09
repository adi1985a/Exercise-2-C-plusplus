#include "Clock.h"
#include "SevenSegmentDisplay.h"
#include <iostream>
#include <ctime>

void Clock::update() {

}

void Clock::render() {
    std::string time = getCurrentTime();
    SevenSegmentDisplay::display(time);
}

std::string Clock::getCurrentTime() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    char buffer[6];
    std::strftime(buffer, sizeof(buffer), "%H:%M", localTime);
    return std::string(buffer);
}
