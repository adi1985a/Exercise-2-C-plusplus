#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>
#include <windows.h>
#include "Clock.h"
#include "Timer.h"
#include "Alarm.h"
#include "SevenSegmentDisplay.h"
#include <locale>

// ANSI color codes for console text
#define RESET   "\033[0m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define WHITE   "\033[37m"

void displayMenu() {
    std::cout << YELLOW << "Clock Application\n" << RESET << "\n"; // Displays the main menu

    std::cout << WHITE << "1. Show current time\n";
    std::cout << "2. Set Alarm\n";
    std::cout << "3. Set Timer\n";
    std::cout << "4. Exit\n";
    std::cout << RED << "\nChoose an option: " << RESET;
}

void clearScreen();

void clearScreen() {
    // Clears the screen on Windows
    system("cls");
    // On UNIX-based systems, use system("clear");
}

void showCurrentTime(Clock& clock) {
    clearScreen();
    clock.update(); // Updates the clock time
    std::cout << "Current time: ";
    std::cout << GREEN; // Set text color to green
    clock.render(); // Displays current time
    std::cout << RESET;
    std::cout << "\nPress any key to return to menu...";
    _getch(); // Wait for key press
    clearScreen();
    displayMenu(); // Return to main menu
}

void handleInvalidChoice() {
    clearScreen();
    std::cout << "Invalid choice, press any key to return to menu...";
    _getch(); // Wait for key press
    clearScreen();
}

void runClockApp() {
    Clock clock;  // Create clock instance
    Timer timer;  // Create timer instance
    Alarm alarm;  // Create alarm instance

    while (true) {
        clearScreen();
        displayMenu();
        std::string choice;
        std::cin >> choice;

        if (choice == "1") {
            showCurrentTime(clock);
        } else if (choice == "2") {
            clearScreen();
            std::cout << WHITE << "Enter alarm time " << YELLOW << "(HH:MM): " << RESET;
            std::string time;
            std::cin >> time;
            std::cout << RED << time << RESET;
            alarm.setAlarm(time); // Set alarm time
            clearScreen();
            std::cout << "Alarm set for " << time << "\n";
            while (true) {
                alarm.update(); // Check if alarm should ring
                if (alarm.isAlarmRinging()) {
                    clearScreen();
                    std::cout << RED << "ALARM!" << RESET << "\n";
                    std::cout << "\nPress any key to return to menu...";
                    PlaySound(TEXT("C:\\Users\\HP\\Downloads\\2.Zaawansowane tech Projekt\\clock_app1\\clock_app\\app1\\assets\\alarm_sound.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
                    while (!_kbhit()) {
                        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Delay between alarm checks
                    }
                    _getch(); // Wait for key press
                    PlaySound(NULL, 0, 0); // Stop sound
                    clearScreen();
                    displayMenu(); // Return to menu
                    break;
                }
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            _getch();
            clearScreen();
            displayMenu();
        } else if (choice == "3") { // Similar to alarm, but for timer
            clearScreen();
            std::cout << WHITE << "Enter timer duration " << YELLOW << "(MM:SS): " << RESET;
            std::string duration;
            std::cin >> duration;
            std::cout << RED << duration << RESET;
            timer.setTimer(duration);
            while (timer.isRunning()) {
                clearScreen();
                timer.update();
                PlaySound(TEXT("C:\\Users\\HP\\Downloads\\2.Zaawansowane tech Projekt\\clock_app1\\clock_app\\app1\\assets\\timer_sound.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            PlaySound(NULL, 0, 0); // Stop timer sound
            clearScreen();
            std::cout << RED << "Countdown finished!" << RESET << "\n";
            std::cout << "Press any key to stop alarm and return to menu...";
            PlaySound(TEXT("C:\\Users\\HP\\Downloads\\2.Zaawansowane tech Projekt\\clock_app1\\clock_app\\app1\\assets\\alarm_sound.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
            _getch();
            PlaySound(NULL, 0, 0); // Stop sound
            clearScreen();
            displayMenu();
        } else if (choice == "4") {
            return; // Exit application
        } else {
            handleInvalidChoice(); // Handle invalid input
        }
    }
}

int main(int argc, char** argv) {
    runClockApp(); // Start the program
    return 0;
}
