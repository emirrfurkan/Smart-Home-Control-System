/**
 * @file User.cpp
 * @brief User class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#include "User.h"

// Constructor: Initializes user data
User::User(string uName, string pass, string realName)
    : username(uName), password(pass), name(realName) {
    // Any additional operations when the object is created can be placed here
}

// Destructor
User::~User() {
    // Memory cleanup (currently empty)
}

// Password Check
bool User::login(string inputPassword) {
    if (this->password == inputPassword) {
        cout << "Login successful. Welcome, " << name << "." << endl;
        return true;
    } else {
        cout << "Incorrect password!" << endl;
        return false;
    }
}

// View Device Status
void User::viewDeviceStatus(Device* d) {
    if (d != nullptr) {
        cout << "Device Information: " << d->getStatus() << endl;
    } else {
        cout << "Error: Device not found!" << endl;
    }
}

// Control Device
void User::controlDevice(Device* d) {
    if (d != nullptr) {
        // Calling the "pure virtual" function defined in the Device class.

        d->controlDevice();
    } else {
        cout << "No device to control!" << endl;
    }
}

string User::getUsername() const {
    return username;
}

string User::getName() const {
    return name;
}
