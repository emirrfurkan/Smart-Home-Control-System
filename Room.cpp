/**
 * @file Room.cpp
 * @brief Room class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#include "Room.h"
#include "Device.h"
#include <iostream>
#include <algorithm>

Room::Room(const std::string& name) : roomName(name) {}

Room::~Room() {
    for (Device* d : devices) {
        delete d;
    }
    devices.clear();
}

void Room::addDevice(Device* newDevice) {
    if (newDevice != nullptr) {
        devices.push_back(newDevice);
    }
}

void Room::removeDevice(Device* targetDevice) {
    auto it = std::find(devices.begin(), devices.end(), targetDevice);
    if (it != devices.end()) {

        delete *it;
        devices.erase(it);
        std::cout << "Device removed from the room." << std::endl;
    } else {
        std::cout << "Error: Device not found in this room." << std::endl;
    }
}

void Room::listDevices() {
    if (devices.empty()) {
        std::cout << "There are no devices in the " << roomName << " room." << std::endl;
        return;
    }

    std::cout << "--- Devices in the " << roomName << " Room ---" << std::endl;
    for (Device* d : devices) {
        if (d) std::cout << "- " << d->getStatus() << " (ID: " << d->getID() << ")" << std::endl;
    }
}

Device* Room::getDevice(const std::string& deviceName) {
    for (Device* d : devices) {
        if (d && d->getName() == deviceName) return d;
    }
    return nullptr;
}

std::string Room::getName() const {
    return roomName;
}


std::vector<Device*>& Room::getDevices() {
    return devices;
}

const std::vector<Device*>& Room::getDevices() const {
    return devices;
}
