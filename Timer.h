#pragma once
#include <string>

class Timer {
public:
    void setTimer(const std::string& duration);
    void update();
    void render();
    bool isRunning() const;

private:
    int remainingTime;
    bool running;
    std::string formatTime(int seconds);
};
