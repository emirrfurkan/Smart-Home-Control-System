/**
 * @file KitchenAppliance.h
 * @brief KitchenAppliance class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef KITCHENAPPLIANCE_H
#define KITCHENAPPLIANCE_H

#include "SpecialDevice.h"

/**
 * @class KitchenAppliance
 * @brief Represents a KitchenAppliance in the smart home system.
 */
class KitchenAppliance : public SpecialDevice {
public:
    KitchenAppliance(int id, string n) : SpecialDevice(id, n) {}

};

#endif
