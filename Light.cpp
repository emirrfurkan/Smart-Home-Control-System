/**
 * @file Light.cpp
 * @brief Light class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#include "Light.h"

Light::Light(int id, string n) : CommonDevice(id, n), brightness(100) {
    // Default brightness 100
}

void Light::setBrightness(int level) {
    if (level >= 0 && level <= 100) {
        brightness = level;
        cout << getName() << " brightness is set to " << brightness << "%." << endl;
    } else {
        cout << "Invalid brightness value! (Must be between 0 and 100)" << endl;
    }
}

// Polymorphism:
void Light::controlDevice() {
    int choice;
    cout << "\n--- " << getName() << " CONTROL PANEL ---" << endl;
    cout << "1. Turn Light On/Off (Current: " << (getIsOn() ? "ON" : "OFF") << ")" << endl;
    cout << "2. Change Brightness (Current: " << brightness << "%)" << endl;
    cout << "0. Exit" << endl;
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 1) {
        if (getIsOn())
            turnOff();
        else
            turnOn();
    }
    else if (choice == 2) {
        int level;
        cout << "New Brightness (0-100): ";
        cin >> level;
        setBrightness(level);
    }
}
