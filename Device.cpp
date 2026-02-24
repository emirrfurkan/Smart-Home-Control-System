/**
 * @file Device.cpp
 * @brief Device class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#include "Device.h"

Device::Device(int id, string n) : deviceID(id), name(n), isOn(false) {

}

// Destructor
Device::~Device() {

}

void Device::turnOn() {
    isOn = true;
    cout << name << " opened." << endl;
}

void Device::turnOff() {
    isOn = false;
    cout << name << " closed." << endl;
}

bool Device::getIsOn() const {
    return isOn;
}

string Device::getName() const {
    return name;
}

int Device::getID() const {
    return deviceID;
}


string Device::getStatus() {
    return name + (isOn ? " ON." : " OFF.");
}
