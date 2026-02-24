/**
 * @file CleaningAppliance.cpp
 * @brief CleaningAppliance class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#include "CleaningAppliance.h"

CleaningAppliance::CleaningAppliance(int id, string n)
    : Device(id, n), currentProgram("Automatic"), remainingTime(0) {
}

void CleaningAppliance::setProgram(string prog) {
    currentProgram = prog;
    cout << getName() << " Set program " << currentProgram << endl;
}

void CleaningAppliance::setTimer(int minutes) {
    remainingTime = minutes;
    cout << getName() << " Remaning Time: " << remainingTime << " minutes." << endl;
}

string CleaningAppliance::getStatus() {
    string base = Device::getStatus();
    if (getIsOn()) {
        return base + " [Program: " + currentProgram + ", Time: " + to_string(remainingTime) + "min]";
    }
    return base;
}
