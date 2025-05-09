# Clock Application

## Overview
This C++ console application simulates a digital clock with time display, alarm, and timer functionalities. It uses `Clock`, `Timer`, `Alarm`, and `SevenSegmentDisplay` classes, with an ANSI-colored menu, sound alerts, and Windows-specific console handling. Users can view the current time, set alarms, or start timers.

## Features
- **Clock Functionality**:
  - Displays current time using the `Clock` class.
  - Updates and renders time in a console with green text.
- **Alarm Functionality**:
  - Set alarms with `HH:MM` input via the `Alarm` class.
  - Plays a sound (`alarm_sound.wav`) when triggered.
  - Stops with any keypress.
- **Timer Functionality**:
  - Set timers with `MM:SS` input via the `Timer` class.
  - Plays a sound (`timer_sound.wav`) during countdown and when finished.
  - Stops with any keypress.
- **Console Interface**:
  - ANSI-colored menu (yellow, red, green, white) for user interaction.
  - Clears screen using `system("cls")` for Windows.
  - Handles invalid inputs with error messages.
- **Sound Integration**:
  - Uses Windows `PlaySound` for alarm and timer audio.
  - Requires `alarm_sound.wav` and `timer_sound.wav` in the specified path.

## Requirements
- C++ compiler (e.g., g++, MSVC) with C++11 or later
- Windows OS (for `windows.h` and `PlaySound`)
- Standard C++ libraries: `<iostream>`, `<thread>`, `<chrono>`, `<conio.h>`
- External libraries: `<windows.h>`
- Local assets:
  - `Clock.h`, `Timer.h`, `Alarm.h`, `SevenSegmentDisplay.h`: Header files for classes
  - `assets/alarm_sound.wav`, `assets/timer_sound.wav`: Audio files
- Sound files path: `C:\Users\HP\Downloads\2.Zaawansowane tech Projekt\clock_app1\clock_app\app1\assets\`

## Setup
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. Ensure header files (`Clock.h`, `Timer.h`, `Alarm.h`, `SevenSegmentDisplay.h`) are in the project directory.
3. Place sound files (`alarm_sound.wav`, `timer_sound.wav`) in:
   ```
   C:\Users\HP\Downloads\2.Zaawansowane tech Projekt\clock_app1\clock_app\app1\assets\
   ```
   Or update the file paths in the source code.
4. Save the provided code as `main.cpp`.
5. Compile the program:
   ```bash
   g++ main.cpp -o clock_app -lwinmm
   ```
   Note: `-lwinmm` links the Windows multimedia library for `PlaySound`.
6. Run the program:
   ```bash
   .\clock_app
   ```

## Usage
1. Compile and run the program using the steps above.
2. **Interface**:
   - Displays a colored menu with options:
     1. Show current time
     2. Set alarm
     3. Set timer
     4. Exit
   - Input a number (1–4) to select an option.
3. **Actions**:
   - **Show Time**: Displays current time; press any key to return to menu.
   - **Set Alarm**: Enter `HH:MM`, wait for alarm to trigger with sound; press any key to stop.
   - **Set Timer**: Enter `MM:SS`, view countdown with sound; press any key when finished.
   - **Exit**: Closes the application.
   - Invalid inputs show an error; press any key to retry.

## File Structure
- `main.cpp`: Main C++ source file with application logic.
- `Clock.h`, `Timer.h`, `Alarm.h`, `SevenSegmentDisplay.h`: Header files for classes (assumed, not provided).
- `assets/alarm_sound.wav`, `assets/timer_sound.wav`: Audio files for alerts.
- `README.md`: This file, providing project documentation.

## Notes
- The program uses Polish text (e.g., "Aplikacja Zegarek", "Aktualny czas") for the interface.
- Windows-specific (`windows.h`, `conio.h`, `PlaySound`); adapt for other OS (e.g., use `system("clear")` for Unix).
- Sound files must exist at the specified path or paths must be updated in `main.cpp`.
- Header files (`Clock.h`, etc.) are assumed to exist; ensure implementations are complete.
- ANSI color codes may not work in some Windows terminals (e.g., older Command Prompt); use modern terminals like Windows Terminal.
- No error handling for invalid time formats (`HH:MM`, `MM:SS`); add validation if needed.
- Extend by adding features like persistent alarm settings or cross-platform support.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make changes and commit (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
For questions or feedback, open an issue on GitHub or contact the repository owner.