/*
Developer: Angel Santiago
Date: 5/17/2023
Purpose: This program allows users to view and control a 12-hour and 24-hour clock.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Clock.h"

void printClocks();
void printMenu();

const int CHOICE_ADD_HOUR = 1;
const int CHOICE_ADD_MINUTE = 2;
const int CHOICE_ADD_SECOND = 3;
const int CHOICE_EXIT = 4;

// Validates and returns a valid user choice
// @returns - The valid user choice (an integer between 1 and 4)
int getValidChoice() {
    int userChoice;
    std::cout << "Enter your choice (1-4): ";
    while (!(std::cin >> userChoice) || userChoice < CHOICE_ADD_HOUR || userChoice > CHOICE_EXIT) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid choice. Please enter a valid choice: ";
    }
    return userChoice;
}

int main() {
    int userChoice;

    // Set the initial time
    setTime(0, 0, 0);

    do {
        // Prints the clocks
        printClocks();

        // Prints the menu
        printMenu();

        // Get the user's choice
        userChoice = getValidChoice();

        // Handle the user's choice
        switch (userChoice) {
        case CHOICE_ADD_HOUR:
            addHour();
            break;
        case CHOICE_ADD_MINUTE:
            addMinute();
            break;
        case CHOICE_ADD_SECOND:
            addSecond();
            break;
        case CHOICE_EXIT:
            std::cout << "Goodbye." << std::endl;
            break;
        }
    } while (userChoice != CHOICE_EXIT);

    return 0;
}

// Prints the 12-hour and 24-hour clocks
void printClocks() {
    std::string clock12 = get12HourFormat();
    std::string clock24 = get24HourFormat();

    std::cout << "**************************    **************************" << std::endl;
    std::cout << "*     12-hour Clock      *    *      24-hour Clock     *" << std::endl;
    std::cout << "*      " << clock12 << "       *    *        " << clock24 << "        *" << std::endl;
    std::cout << "**************************    **************************" << std::endl;
    std::cout << std::endl;
}

// Prints the menu options
void printMenu() {
    std::cout << "        Main menu         " << std::endl;
    std::cout << "**************************" << std::endl;
    std::cout << "*  " << CHOICE_ADD_HOUR << "  - Add one hour     *" << std::endl;
    std::cout << "*  " << CHOICE_ADD_MINUTE << "  - Add one minute   *" << std::endl;
    std::cout << "*  " << CHOICE_ADD_SECOND << "  - Add one second   *" << std::endl;
    std::cout << "*  " << CHOICE_EXIT << "  - Exit program     *" << std::endl;
    std::cout << "**************************" << std::endl;
}