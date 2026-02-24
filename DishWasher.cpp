/**
 * @file DishWasher.cpp
 * @brief DishWasher class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#include "Dishwasher.h"

Dishwasher::Dishwasher(int id, string n) : CleaningAppliance(id, n), saltWarning(false) {}

void Dishwasher::startWashCycle() {
    if (!saltWarning) {
        turnOn();
        cout << getName() << " starting washing. Program: " << currentProgram << endl;
    } else {
        cout << "Error : don't start.!" << endl;
    }
}

void Dishwasher::checkSalt() {

    saltWarning = false;
    cout << "Control: " << (saltWarning ? "Lack" : "Enough") << endl;
}

void Dishwasher::controlDevice() {
    cout << "\n--- " << getName() << " Control ---" << endl;
    cout << "1. Start" << endl;
    cout << "2. Choose" << endl;
    cout << "3. Control" << endl;

    int secim; cin >> secim;
    if (secim == 1) startWashCycle();
    else if (secim == 2) {
        cout << "1.Eko 2.Fast: ";
        int p; cin >> p;
        setProgram(p == 1 ? "Eko" : "Fast");
    } else if (secim == 3) checkSalt();
}
