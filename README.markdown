# ⏰🔔 ConsoleTime Pro: C++ Digital Clock, Alarm & Timer 🇵🇱
_A C++ console application simulating a digital clock with current time display, settable alarms, and countdown timers, featuring sound alerts and an ANSI-colored interface (Windows-focused)._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B%2011%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)

## 📋 Table of Contents
1.  [Overview](#-overview)
2.  [Key Features](#-key-features)
3.  [Screenshots (Conceptual)](#-screenshots-conceptual)
4.  [System Requirements & Assets](#-system-requirements--assets)
5.  [Core Class Headers (User-Provided)](#-core-class-headers-user-provided)
6.  [Installation and Setup](#️-installation-and-setup)
7.  [Usage Guide](#️-usage-guide)
8.  [File Structure](#-file-structure)
9.  [Technical Notes](#-technical-notes)
10. [Contributing](#-contributing)
11. [License](#-license)
12. [Contact](#-contact)

## 📄 Overview

**ConsoleTime Pro**, developed by Adrian Lesniak, is a C++ console application that emulates a digital clock with added alarm and timer functionalities. It leverages several classes (`Clock`, `Timer`, `Alarm`, `SevenSegmentDisplay` - definitions assumed in user-provided headers) to manage time display, set and trigger alarms, and run countdown timers. The application features an ANSI-colored menu for user interaction, utilizes Windows-specific functions for sound playback (`PlaySound`) and console handling, and presents its interface with English text. Users can view the current time, set alarms for specific times, or start countdown timers, with audio alerts for alarm and timer completion.

![Demo GIF](screenshots/1.gif)

## ✨ Key Features

*   🕒 **Clock Functionality (`Clock` Class)**:
    *   Displays the current system time, continuously updated.
    *   Renders the time in the console, typically in a HH:MM:SS format, possibly using `SevenSegmentDisplay` for a stylized look (e.g., green text).
*   🔔 **Alarm Functionality (`Alarm` Class)**:
    *   Allows users to set alarms by inputting a specific time in HH:MM format.
    *   Triggers an audio alert (plays `alarm_sound.wav` via `PlaySound`) when the set alarm time is reached.
    *   The alarm sound can be stopped by any keypress.
*   ⏳ **Timer Functionality (`Timer` Class)**:
    *   Enables users to set countdown timers by inputting a duration in MM:SS format.
    *   Displays the countdown in real-time.
    *   Plays an audio alert (e.g., `timer_sound.wav`) during the countdown (continuously or at intervals) and a distinct sound when the timer reaches zero.
    *   The timer (and its sound) can be stopped by any keypress once finished.
*   🖥️ **Interactive Console Interface**:
    *   **ANSI-Colored Menu**: Presents a main menu with options (Show time, Set alarm, Set timer, Exit) using various colors (yellow, red, green, white) for better visual distinction.
    *   **Screen Clearing**: Uses `system("cls")` for clearing the console screen on Windows, providing a clean UI for each section.
    *   Handles invalid menu inputs with error messages and prompts for retry.
*   🔊 **Sound Integration (Windows-specific)**:
    *   Utilizes the Windows `PlaySound` API function (from `mmsystem.h`, linked via `-lwinmm`) for playing `.wav` files for alarm and timer alerts.
    *   Requires `alarm_sound.wav` and `timer_sound.wav` to be present at a specified path.

## 🖼️ Screenshots (Conceptual)


_This section shows screenshots of: the colored main menu, the current time display (possibly with seven-segment style), the alarm setting prompt, the timer countdown, and examples of alert messages._

<p align="center">
  <img src="screenshots\Image1.jpg" width="300"/>
  <img src="screenshots\Image2.jpg" width="300"/>
  <img src="screenshots\Image3.jpg" width="300"/>
  <img src="screenshots\Image4.jpg" width="300"/>
  <img src="screenshots\Image5.jpg" width="300"/>
  <img src="screenshots\Image6.jpg" width="300"/>
  <img src="screenshots\Image7.jpg" width="300"/>
  <img src="screenshots\Image8.jpg" width="300"/>
</p>

## ⚙️ System Requirements & Assets

*   **Operating System**: Windows (due to heavy reliance on `<windows.h>`, `PlaySound` from `mmsystem.h`, and `<conio.h>`).
*   **C++ Compiler**: A C++ compiler supporting C++11 or later (e.g., g++ via MinGW, MSVC).
*   **Standard C++ Libraries**: `<iostream>`, `<string>`, `<vector>` (if used), `<thread>`, `<chrono>`, `<iomanip>`, `<limits>`.
*   **Windows-Specific Libraries**: `<windows.h>`, `<mmsystem.h>` (requires linking with `winmm.lib` or `-lwinmm`).
*   📄 **Custom Header Files (User-Provided)**:
    *   `Clock.h`: Declares the `Clock` class.
    *   `Timer.h`: Declares the `Timer` class.
    *   `Alarm.h`: Declares the `Alarm` class.
    *   `SevenSegmentDisplay.h`: (If used for time display) Declares the `SevenSegmentDisplay` class or related functions.
*   🎵 **Audio Assets**:
    *   `alarm_sound.wav`
    *   `timer_sound.wav`
    *   These files **must** be located at the hardcoded path: `C:\Users\HP\Downloads\2.Zaawansowane tech Projekt\clock_app1\clock_app\app1\assets\` **OR** the paths in `main.cpp` must be updated to their correct location.

## 🧩 Core Class Headers (User-Provided)

This application relies on several user-provided header files defining the core logic classes:

*   **`Clock.h`**: Should declare a class responsible for fetching, formatting, and possibly displaying the current system time.
*   **`Timer.h`**: Should declare a class for managing countdown timer logic, including setting duration, ticking down, and signaling completion.
*   **`Alarm.h`**: Should declare a class for setting alarm times, checking against current time, and signaling when an alarm is triggered.
*   **`SevenSegmentDisplay.h`**: (Optional, based on implementation) If used, this would declare a class or functions to render numbers in a seven-segment display style using ASCII/console characters.

*Implementations for these classes would typically reside in corresponding `.cpp` files (e.g., `Clock.cpp`, `Timer.cpp`, `Alarm.cpp`, `SevenSegmentDisplay.cpp`) which need to be compiled and linked with `main.cpp`.*

## 🛠️ Installation and Setup

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
    (Replace `<repository-url>` and `<repository-directory>` with your specific details)

2.  **Ensure Header Files are Present**:
    Place `Clock.h`, `Timer.h`, `Alarm.h`, and `SevenSegmentDisplay.h` (and their corresponding `.cpp` implementation files if separate) in the project directory or an appropriate include path.

3.  **Place Audio Assets**:
    *   Create the directory structure: `C:\Users\HP\Downloads\2.Zaawansowane tech Projekt\clock_app1\clock_app\app1\assets\`
    *   Place `alarm_sound.wav` and `timer_sound.wav` into this `assets` folder.
    *   **Alternatively, and recommended for portability, modify the hardcoded paths for these sound files within `main.cpp` to be relative to the executable (e.g., `"assets/alarm_sound.wav"`) and place the `assets` folder in the same directory as your compiled `.exe` file.**

4.  **Save Main Code**:
    Ensure your main application logic is saved as `main.cpp` in the project directory.

5.  **Compile the Program (Windows with MinGW g++)**:
    Open a terminal (Command Prompt, PowerShell) in the project directory.
    ```bash
    g++ main.cpp Clock.cpp Timer.cpp Alarm.cpp SevenSegmentDisplay.cpp -o clock_app.exe -std=c++11 -lwinmm -static-libgcc -static-libstdc++
    ```
    *(This is an example. Include all necessary `.cpp` files. The `-lwinmm` flag is crucial for linking the Windows Multimedia library required for `PlaySound`. Adjust if using MSVC, which links `winmm.lib` differently, often automatically or via project settings).*

6.  **Run the Program**:
    ```bash
    .\clock_app.exe
    ```
    (or `clock_app.exe` in CMD)

## 💡 Usage Guide

1.  Compile and run `clock_app.exe` as detailed above.
2.  **Interface**:
    *   The program will display a main menu with options presented in Polish and using ANSI colors (on compatible terminals):
        1. Show current time
        2. Set alarm
        3. Set timer
        4. Exit
           
3.  **Input**:
    *   Enter a number (1–4) corresponding to your choice and press Enter.
4.  **Actions**:
    *   **Show current time (Option 1)**: Displays the current time, updating in the console. Press any key to return to the menu.
    *   **Set alarm (Option 2)**: Prompts you to enter the alarm time in HH:MM format. Once set, the program will wait. When the system time matches the alarm time, `alarm_sound.wav` will play. Press any key to stop the alarm sound and return to the menu.
    *   **Set timer (Option 3)**: Prompts you to enter the timer duration in MM:SS format. A countdown will begin, possibly with sound. When the timer reaches zero, `timer_sound.wav` (or a different completion sound) will play. Press any key to acknowledge and return to the menu.
    *   **Exit (Option 4)**: Closes the application.
    *   Invalid menu inputs will display an error message, and you'll be prompted to press a key to retry.

## 🗂️ File Structure

*   `main.cpp`: The main C++ source file containing the application's primary loop, menu handling, and interaction with the `Clock`, `Timer`, and `Alarm` objects.
*   `Clock.h` / `Clock.cpp`: (User-provided) Declaration and implementation for the `Clock` class.
*   `Timer.h` / `Timer.cpp`: (User-provided) Declaration and implementation for the `Timer` class.
*   `Alarm.h` / `Alarm.cpp`: (User-provided) Declaration and implementation for the `Alarm` class.
*   `SevenSegmentDisplay.h` / `SevenSegmentDisplay.cpp`: (User-provided, if used) Declaration and implementation for a seven-segment display style renderer.
*   `assets/alarm_sound.wav`: Audio file for alarm alerts.
*   `assets/timer_sound.wav`: Audio file for timer alerts.
*   `README.md`: This documentation file.

*(No explicit log files like `program_log.txt` or `results.txt` were mentioned in the features for this specific project, but error handling for sound file loading would be beneficial).*

## 📝 Technical Notes

*   **Windows-Specific**: This application is heavily tied to the Windows environment due to:
    *   `<windows.h>` for console manipulation and `PlaySound`.
    *   `<conio.h>` likely for `_getch()` for non-buffered keypresses.
    *   `PlaySound` API from `mmsystem.h` (linked with `-lwinmm` or `winmm.lib`).
    Adapting for other OSes would require replacing `PlaySound` with a cross-platform audio library (e.g., SDL_mixer, OpenAL, PortAudio) and console functions with POSIX alternatives or libraries like ncurses.
*   **Hardcoded Sound Paths**: The path to sound files is hardcoded. This is not portable. It's highly recommended to make these paths relative to the executable or configurable.
*   **User-Provided Headers**: The functionality heavily relies on the correct implementation of `Clock.h`, `Timer.h`, `Alarm.h`, and `SevenSegmentDisplay.h`.
*   **ANSI Colors**: While `windows.h` might be used for some console aspects, the menu is described as "ANSI-colored." Modern Windows terminals (like Windows Terminal) support ANSI escape codes, but older `cmd.exe` might not render them correctly without specific enabling. If using Windows API for colors, this would be Windows-specific.
*   **Input Validation for Time Formats**: The description notes "No error handling for invalid time formats (HH:MM, MM:SS)." This is a critical area for improvement to prevent crashes or undefined behavior if the user enters, for example, "99:99".

## 🤝 Contributing

Contributions to **ConsoleTime Pro** are welcome! If you have ideas for improving cross-platform compatibility (especially for sound and console UI), enhancing time input validation, adding features like persistent alarm settings, or refining the visual display:

1.  Fork the repository.
2.  Create a new branch for your feature (`git checkout -b feature/ClockEnhancements`).
3.  Make your changes and commit them (`git commit -m 'Feature: Implement ClockEnhancements'`).
4.  Push to the branch (`git push origin feature/ClockEnhancements`).
5.  Open a Pull Request.

Please ensure your code is well-commented and adheres to good C++ practices.

## 📃 License

This project is licensed under the **MIT License**.
(If you have a `LICENSE` file in your repository, refer to it: `See the LICENSE file for details.`)

## 📧 Contact

Created by **Adrian Lesniak**.
For questions, feedback, or issues, please open an issue on the GitHub repository or contact the repository owner.

---
🕰️ _Bringing time management to your console with sound and style!_
