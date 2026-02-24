/**
 * @file Oven.cpp
 * @brief Oven class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#include "Oven.h"

Oven::Oven(int id, string n)
    : KitchenAppliance(id, n), temperature(0), cookingMode("Top-Bottom") {
}

void Oven::setTemperature(int temp) {
    if (temp >= 0 && temp <= 250) {
        temperature = temp;
        cout << getName() << " temperature set to "
             << temperature << "C." << endl;
    } else {
        cout << "Error: The oven temperature cannot exceed 250 degrees." << endl;
    }
}

void Oven::setCookingMode(string mode) {
    cookingMode = mode;
    cout << getName() << " mode changed to: " << cookingMode << endl;
}

void Oven::controlDevice() {
    int choice;
    cout << "\n--- " << getName() << " KITCHEN PANEL ---" << endl;

    // If the oven is off, only the power-on option is shown
    if (!getIsOn()) {
        cout << "1. Turn On Oven" << endl;
        cout << "0. Exit" << endl;
    } else {
        cout << "1. Turn Off Oven" << endl;
        cout << "2. Set Temperature (Current: " << temperature << "C)" << endl;
        cout << "3. Change Mode (Current: " << cookingMode << ")" << endl;
        cout << "0. Exit" << endl;
    }

    cout << "Your choice: ";
    cin >> choice;

    if (!getIsOn()) {
        if (choice == 1) {
            turnOn();
        }
    } else {
        if (choice == 1) {
            turnOff();
        }
        else if (choice == 2) {
            int t;
            cout << "Temperature (0-250): ";
            cin >> t;
            setTemperature(t);
        }
        else if (choice == 3) {
            cout << "Modes: 1.Fan 2.Grill 3.Top-Bottom" << endl;
            int m;
            cin >> m;

            if (m == 1) setCookingMode("Fan");
            else if (m == 2) setCookingMode("Grill");
            else setCookingMode("Top-Bottom");
        }
    }
}
