/**
 * @file WashingMachine.cpp
 * @brief WashingMachine class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#include "WashingMachine.h"

WashingMachine::WashingMachine(int id, string n)
    : CleaningAppliance(id, n), rpm(800), waterTemp(40) {
}

void WashingMachine::setSpinSpeed(int speed) {
    if (speed >= 400 && speed <= 1600) {
        rpm = speed;
        cout << getName() << " spin speed set to " << rpm << "." << endl;
    } else {
        cout << "Error: Invalid spin speed." << endl;
    }
}

void WashingMachine::setWaterTemp(int temp) {
    if (temp >= 20 && temp <= 95) {
        waterTemp = temp;
        cout << getName() << " water temperature set to "
             << waterTemp << " degrees." << endl;
    } else {
        cout << "Error: Invalid water temperature." << endl;
    }
}

void WashingMachine::controlDevice() {
    int choice;
    cout << "\n--- " << getName() << " WASHING PANEL ---" << endl;

    if (!getIsOn()) {
        cout << "1. Start Machine" << endl;
        cout << "0. Exit" << endl;
    } else {
        cout << "1. Stop (Turn Off)" << endl;
        cout << "2. Select Program (Current: " << currentProgram << ")" << endl;
        cout << "3. Set Temperature (Current: " << waterTemp << ")" << endl;
        cout << "4. Set Spin Speed (Current: " << rpm << ")" << endl;
        cout << "0. Exit" << endl;
    }

    cout << "Your choice: ";
    cin >> choice;

    if (!getIsOn()) {
        if (choice == 1) {
            turnOn();
            setTimer(120); // Start default washing duration
        }
    } else {
        if (choice == 1) turnOff();
        else if (choice == 2) {
            cout << "Programs: 1.Cotton 2.Synthetic 3.Quick Wash: ";
            int p;
            cin >> p;
            if (p == 1) setProgram("Cotton");
            else if (p == 2) setProgram("Synthetic");
            else setProgram("Quick Wash");
        }
        else if (choice == 3) {
            int t;
            cout << "Temperature: ";
            cin >> t;
            setWaterTemp(t);
        }
        else if (choice == 4) {
            int r;
            cout << "Spin Speed (RPM): ";
            cin >> r;
            setSpinSpeed(r);
        }
    }
}
