// Clock.h
// CS 210 Project One - Chada Tech Dual Clock
// Brandon Willis
// 5.19.2026

#ifndef CLOCK_H
#define CLOCK_H

#include <string>

class Clock {
public:
    Clock();
    Clock(int hours, int minutes, int seconds);

    void addHour();
    void addMinute();
    void addSecond();

    std::string get12HourTime() const;
    std::string get24HourTime() const;

private:
    // Time is stored internally in 24-hour format
    int hours;
    int minutes;
    int seconds;
};

#endif
