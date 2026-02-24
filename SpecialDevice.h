/**
 * @file SpecialDevice.h
 * @brief SpecialDevice class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef SPECIALDEVICE_H
#define SPECIALDEVICE_H

#include "Device.h"

/**
 * @class SpecialDevice
 * @brief Represents a SpecialDevice in the smart home system.
 */
class SpecialDevice : public Device {
public:
    SpecialDevice(int id, string n) : Device(id, n) {}
};

#endif
