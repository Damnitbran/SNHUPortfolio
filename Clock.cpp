// Clock.cpp
// CS 210 Project One - Chada Tech Dual Clock
// Brandon Willis
// 5.19.2026

#include "Clock.h"
#include <sstream>
#include <iomanip>

Clock::Clock() : hours(0), minutes(0), seconds(0) {}

Clock::Clock(int hours, int minutes, int seconds)
    : hours(hours), minutes(minutes), seconds(seconds) {}

void Clock::addHour() {
    hours = (hours + 1) % 24;
}

void Clock::addMinute() {
    minutes++;
    if (minutes >= 60) {
        minutes = 0;
        addHour();
    }
}

void Clock::addSecond() {
    seconds++;
    if (seconds >= 60) {
        seconds = 0;
        addMinute();
    }
}

std::string Clock::get12HourTime() const {
    // Spec uses "A M" / "P M" with a space between the letters
    std::string period = (hours < 12) ? "A M" : "P M";

    // Midnight (0) and noon (12) both display as 12 in 12-hour format
    int displayHour = hours % 12;
    if (displayHour == 0) {
        displayHour = 12;
    }

    std::ostringstream output;
    output << std::setw(2) << std::setfill('0') << displayHour << ":"
           << std::setw(2) << std::setfill('0') << minutes     << ":"
           << std::setw(2) << std::setfill('0') << seconds
           << " " << period;
    return output.str();
}

std::string Clock::get24HourTime() const {
    std::ostringstream output;
    output << std::setw(2) << std::setfill('0') << hours   << ":"
           << std::setw(2) << std::setfill('0') << minutes << ":"
           << std::setw(2) << std::setfill('0') << seconds;
    return output.str();
}
