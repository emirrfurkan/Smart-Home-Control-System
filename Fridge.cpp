/**
 * @file Fridge.cpp
 * @brief Fridge class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#include "Fridge.h"

Fridge::Fridge(int id, string n) : KitchenAppliance(id, n), temperature(4), superCoolMode(false) {
    // By default, it starts at +4 degrees and in normal mode.
    // We assume the refrigerator starts working as soon as it is plugged in.

    turnOn();
}

void Fridge::setTemperature(int temp) {
    if (temp >= -24 && temp <= 8) {
        temperature = temp;
        cout << getName() << " temperature is set to " << temperature << " degrees." << endl;
    } else {
        cout << "Error: Invalid temperature range (must be between -24 and 8)." << endl;
    }

}

void Fridge::toggleSuperCool() {
    superCoolMode = !superCoolMode; // If true, be false; if false, be true
    cout << getName() << " Super Cooling Mode: "
         << (superCoolMode ? "ACTIVE" : "INACTIVE") << endl;
}


string Fridge::getStatus() {
    string base = Device::getStatus();
    string mod = superCoolMode ? " [SUPER COOL]" : " [Normal]";
    return base + " (" + to_string(temperature) + "C)" + mod;
}

void Fridge::controlDevice() {
    int choice;
    cout << "\n--- " << getName() << " CONTROL PANEL ---" << endl;
    cout << "1. Change Temperature (Current: " << temperature << " C)" << endl;
    cout << "2. Turn Super Cooling Mode On/Off" << endl;
    cout << "3. Turn Off the Device (Unplug)" << endl; // Rarely used, but included
    cout << "0. Exit" << endl;
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 1) {
        int t;
        cout << "New Temperature: ";
        cin >> t;
        setTemperature(t);
    }
    else if (choice == 2) {
        toggleSuperCool();
    }
    else if (choice == 3) {
        turnOff();
    }
}

