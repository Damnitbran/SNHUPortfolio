// main.cpp
// CS 210 Project One - Chada Tech Dual Clock
// Brandon Willis
// 5.19.2026

#include "Clock.h"
#include <iostream>
#include <string>
#include <limits>

// Reads an int from cin, re-prompting on bad input or out-of-range values
int getValidatedInt(const std::string& prompt, int minValue, int maxValue) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "  Invalid input. Please enter a whole number.\n";
            continue;
        }

        if (value < minValue || value > maxValue) {
            std::cout << "  Value must be between " << minValue
                      << " and " << maxValue << ".\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }
}

Clock getInitialTime() {
    std::cout << "\nEnter the initial time using a 24-hour format.\n";
    int hours   = getValidatedInt("  Hours (0-23):   ", 0, 23);
    int minutes = getValidatedInt("  Minutes (0-59): ", 0, 59);
    int seconds = getValidatedInt("  Seconds (0-59): ", 0, 59);
    return Clock(hours, minutes, seconds);
}

void displayClocks(const Clock& clock) {
    std::cout << "\n";
    std::cout << "**************************     **************************\n";
    std::cout << "*     12-Hour Clock      *     *     24-Hour Clock      *\n";
    std::cout << "*       " << clock.get12HourTime() << "      *     *        "
              << clock.get24HourTime() << "        *\n";
    std::cout << "**************************     **************************\n";
}

void displayMenu() {
    std::cout << "\n";
    std::cout << "**************************\n";
    std::cout << "* 1 - Add One Hour       *\n";
    std::cout << "* 2 - Add One Minute     *\n";
    std::cout << "* 3 - Add One Second     *\n";
    std::cout << "* 4 - Exit Program       *\n";
    std::cout << "**************************\n";
}

void runClockMenu(Clock& clock) {
    bool running = true;
    while (running) {
        displayClocks(clock);
        displayMenu();
        int choice = getValidatedInt("Select an option (1-4): ", 1, 4);

        switch (choice) {
            case 1: clock.addHour();   break;
            case 2: clock.addMinute(); break;
            case 3: clock.addSecond(); break;
            case 4: running = false;   break;
        }
    }
}

int main() {
    std::cout << "===========================================\n";
    std::cout << "    Chada Tech - Dual Clock Display\n";
    std::cout << "===========================================\n";

    Clock clock = getInitialTime();
    runClockMenu(clock);

    std::cout << "\nGoodbye!\n";
    return 0;
}
