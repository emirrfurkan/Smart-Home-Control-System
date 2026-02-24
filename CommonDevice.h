/**
 * @file CommonDevice.h
 * @brief CommonDevice class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef COMMONDEVICE_H
#define COMMONDEVICE_H

#include "Device.h"

/**
 * @class CommonDevice
 * @brief Represents a CommonDevice in the smart home system.
 */
class CommonDevice : public Device {
public:
    CommonDevice(int id, string n) : Device(id, n) {}
};

#endif
