#pragma once
#include <string>

class Clock {
public:
    void update();
    void render();

private:
    std::string getCurrentTime();
};
