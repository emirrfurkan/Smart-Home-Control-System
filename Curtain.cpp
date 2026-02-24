/**
 * @file Curtain.cpp
 * @brief Curtain class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#include "Curtain.h"

Curtain::Curtain(int id, string n) : CommonDevice(id, n), openPercentage(0) {}

void Curtain::openCurtain(int percent) {
    if (percent >= 0 && percent <= 100) {
        openPercentage = percent;
        if (openPercentage > 0) turnOn(); // If curtain is open it is "ON"
        else turnOff();
        cout << getName() << " %" << openPercentage << " open." << endl;
    }
}

void Curtain::closeCurtain() {
    openPercentage = 0;
    turnOff();
    cout << getName() << "close completly." << endl;
}

string Curtain::getStatus() {
    return getName() + " [openness: %" + to_string(openPercentage) + "]";
}

void Curtain::controlDevice() {
    cout << "\n--- " << getName() << " CONTROL ---" << endl;
    cout << "1. Open curtain /Set" << endl;
    cout << "2. Close curtain" << endl;

    int secim; cin >> secim;
    if (secim == 1) {
        int p; cout << "What percentage should be opened (0-100)?: "; cin >> p;
        openCurtain(p);
    } else if (secim == 2) {
        closeCurtain();
    }
}
