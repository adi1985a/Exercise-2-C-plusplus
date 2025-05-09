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

// Kody ANSI do kolorowania tekstu w konsoli
#define RESET   "\033[0m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define WHITE   "\033[37m"

void displayMenu() {
    std::cout << YELLOW << "Aplikacja Zegarek\n" << RESET << "\n"; // Wyswietla glowne menu aplikacji zegarka

    std::cout << WHITE << "1. Pokaz aktualny czas\n";
    std::cout << "2. Ustaw Alarm\n";
    std::cout << "3. Ustaw Timer\n";
    std::cout << "4. Wyjscie\n";
    std::cout << RED << "\nWybierz opcje: " << RESET;
}

void clearScreen();


void clearScreen() {
    // Czysci ekran w systemie Windows
    system("cls");
    // W systemach UNIX-based nalezy użyc system("clear");
}

void showCurrentTime(Clock& clock) {
    clearScreen();
    clock.update();// Aktualizuje czas w zegarze
    std::cout << "Aktualny czas: ";
    std::cout << GREEN;// Ustawia kolor tekstu na zielony
    clock.render();// Wyswietla aktualny czas
    std::cout << RESET;
    std::cout << "\nPrzycisnij jakikolwiek klawisz zeby wrocic do menu...";
    _getch(); // Czeka na nacisniecie dowolnego klawisza
    clearScreen();
    displayMenu(); // Powrot do menu glownego
}

void handleInvalidChoice() {
    clearScreen();
    std::cout << "Zly wybor, przycisnij jakikolwiek klawisz zeby wrocic do menu...";
    _getch(); // Czeka na nacisniecie dowolnego klawisza
    clearScreen();
}

void runClockApp() {


    Clock clock;// Tworzy instancje zegara
    Timer timer;// Tworzy instancje timera
    Alarm alarm;// Tworzy instancje alarmu


    while (true) {
        clearScreen();
        displayMenu();
        std::string choice;
        std::cin >> choice;

        if (choice == "1") {
            showCurrentTime(clock);
        } else if (choice == "2") {
            clearScreen();
            std::cout << WHITE << "Wpisz czas alarmu " << YELLOW << "(HH:MM): " << RESET;
            std::string time;
            std::cin >> time;
            std::cout << RED << time << RESET;
            alarm.setAlarm(time);// Ustawia czas alarmu
            clearScreen();
            std::cout << "Alarm ustawiony na " << time << "\n";
            while (true) {
                alarm.update();// Sprawdza, czy alarm powinien dzwonic
                if (alarm.isAlarmRinging()) {
                    clearScreen();

                    std::cout << RED << "ALARM!" << RESET << "\n";
                    std::cout << "\nPrzycisnij jakikolwiek klawisz zeby wrocic do menu...";
                    PlaySound(TEXT("C:\\Users\\HP\\Downloads\\2.Zaawansowane tech Projekt\\clock_app1\\clock_app\\app1\\assets\\alarm_sound.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
                    while (!_kbhit()) {
                        std::this_thread::sleep_for(std::chrono::milliseconds(100));// Opóźnienie pomiedzy kolejnymi sprawdzeniami alarmu
                    }
                    _getch(); // Czeka na nacisniecie dowolnego klawisza
                    PlaySound(NULL, 0, 0); // zatrzymuje dzwiek
                    clearScreen();
                    displayMenu(); // Powrot do menu
                    break;
                }
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            _getch();
            clearScreen();
            displayMenu();
        } else if (choice == "3") { // Podobne dzialanie jak przy ustawianiu alarmu, ale dla timera
            clearScreen();
            std::cout << WHITE << "Wpisz czas trwania " << YELLOW << "(MM:SS): " << RESET;
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
            PlaySound(NULL, 0, 0); // zatrzymuje dzwiek timera
            clearScreen();

            std::cout << RED << "Odliczanie zakonczone!" << RESET << "\n";
            std::cout << "Przycisnij jakikolwiek klawisz zeby zamknac alarm i wrocic do menu...";
            PlaySound(TEXT("C:\\Users\\HP\\Downloads\\2.Zaawansowane tech Projekt\\clock_app1\\clock_app\\app1\\assets\\alarm_sound.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
            _getch();
            PlaySound(NULL, 0, 0); // zatrzymuje dzwiek
            clearScreen();
            displayMenu();
        } else if (choice == "4") {
            return;// Zakonczenie aplikacji
        } else {
            handleInvalidChoice();// Obsluga nieprawidlowego wyboru
        }
    }
}

int main(int argc, char** argv) {

    runClockApp(); //uruchomienie funkcji programu
    return 0;
}
