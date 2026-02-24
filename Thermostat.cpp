/**
 * @file Thermostat.cpp
 * @brief Thermostat class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#include "Thermostat.h"

Thermostat::Thermostat(int id, string n) : Device(id, n), targetTemperature(22.0) {
    // Default room temperature is 22 degrees
}

void Thermostat::setTemperature(double temp) {
    targetTemperature = temp;
    cout << getName() << " target temperature set to "
         << targetTemperature << " degrees." << endl;
}

string Thermostat::getStatus() {
    // Append the temperature information to the standard Device status
    string baseStatus = Device::getStatus(); // e.g. "Thermostat is currently ON"
    return baseStatus + " [Target: " + to_string((int)targetTemperature) + "C]";
}

void Thermostat::controlDevice() {
    int choice;
    cout << "\n--- " << getName() << " CONTROL PANEL ---" << endl;
    cout << "1. Turn Device On/Off" << endl;
    cout << "2. Set Temperature" << endl;
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 1) {
        if (getIsOn()) turnOff();
        else turnOn();
    }
    else if (choice == 2) {
        double temp;
        cout << "New Temperature: ";
        cin >> temp;
        setTemperature(temp);
    }
}
