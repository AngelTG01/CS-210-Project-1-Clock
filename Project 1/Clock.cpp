#include "Clock.h"

int hours = 0;
int minutes = 0;
int seconds = 0;

// Sets the time with the specified values
// @parameter value h - hours
// @parameter value m - minutes
// @parameter value s - seconds
void setTime(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;
}

// Adds one hour to the time
void addHour() {
    if (hours < 23) {
        hours = (hours + 1) % 24;
    }
    else {
        hours = 0;
    }
}

// Adds one minute to the time
void addMinute() {
    minutes = (minutes + 1) % 60;
    if (minutes == 0) {
        addHour();
    }
}

// Adds one second to the time
void addSecond() {
    seconds = (seconds + 1) % 60;
    if (seconds == 0) {
        addMinute();
    }
}

// Pads a number with leading zeros
// @parameter number - the number to pad
// @returns - the padded number as a string
std::string pad(int number) {
    if (number < 10) {
        return "0" + std::to_string(number);
    }
    else {
        return std::to_string(number);
    }
}

// Returns the time suffix (AM or PM)
std::string getSuffix() {
    if (hours >= 12) {
        return "PM";
    }
    else {
        return "AM";
    }
}

// Returns the formatted 12-hour time string
std::string get12HourFormat() {
    int displayHours = (hours % 12 == 0) ? 12 : hours % 12;
    std::string suffix = (hours >= 12) ? "PM" : "AM";
    return std::to_string(displayHours) + ":" + pad(minutes) + ":" + pad(seconds) + " " + suffix;
}

// Returns the formatted 24-hour time string
std::string get24HourFormat() {
    return pad(hours) + ":" + pad(minutes) + ":" + pad(seconds);
}