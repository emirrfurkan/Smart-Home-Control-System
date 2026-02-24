/**
 * @file Plug.cpp
 * @brief Plug class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#include "Plug.h"

Plug::Plug(int id, string n) : CommonDevice(id, n), energyUsage(0.0) {}

void Plug::getEnergyReport() {
    // Simulated report
    cout << getName() << " Total Consumption: " << energyUsage << " kWh" << endl;
}

void Plug::setTimer(int minutes) {
    cout << "Timer set for " << minutes << " minutes on " << getName() << "." << endl;
}

string Plug::getStatus() {
    return CommonDevice::getStatus() + (getIsOn() ? " [Power On]" : " [No Power]");
}

void Plug::controlDevice() {
    cout << "\n--- " << getName() << " CONTROL ---" << endl;
    cout << "1. Turn Plug On/Off" << endl;
    cout << "2. Get Energy Report" << endl;
    cout << "3. Set Timer" << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
        if (getIsOn()) turnOff();
        else turnOn();
    } else if (choice == 2) {
        getEnergyReport();
    } else if (choice == 3) {
        int m;
        cout << "Minutes: ";
        cin >> m;
        setTimer(m);
    }
}
