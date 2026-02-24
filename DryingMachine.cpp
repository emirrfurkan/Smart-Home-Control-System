/**
 * @file DryingMachine.cpp
 * @brief DryingMachine class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#include "DryingMachine.h"

DryingMachine::DryingMachine(int id, string n)
    : CleaningAppliance(id, n), drynessLevel("Cupboard dryness"), filterStatus(true) {}

void DryingMachine::setDrynessLevel(string level) {
    drynessLevel = level;
    cout << getName() << " level: " << drynessLevel << endl;
}

void DryingMachine::cleanFilterReset() {
    filterStatus = true;
    cout << "filter is cleaned." << endl;
}

void DryingMachine::controlDevice() {
    cout << "\n--- " << getName() << " Control ---" << endl;
    cout << "1. Start" << endl;
    cout << "2. Choose" << endl;
    cout << "3. Clean Filter" << endl;

    int secim; cin >> secim;
    if (secim == 1) {
        if(filterStatus) {
            turnOn();
            cout << "Started drying" << endl;
        } else {
            cout << "Error: Filter is not empty!" << endl;
        }
    } else if (secim == 2) {
        cout << "1.cupboard 2.Iron: ";
        int l; cin >> l;
        setDrynessLevel(l == 1 ? "cupboard dryness" : "iron dryness");
    } else if (secim == 3) cleanFilterReset();
}
