/**
 * @file Fridge.h
 * @brief Fridge class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef FRIDGE_H
#define FRIDGE_H

#include "KitchenAppliance.h"

/**
 * @class Fridge
 * @brief Represents a Fridge in the smart home system.
 */
class Fridge : public KitchenAppliance {
private:
    int temperature;
    bool superCoolMode;

public:
/**
 * @brief Performs the Fridge operation.
 * @param id Parameter.
 * @param n Parameter.
 */
    Fridge(int id, string n);

/**
 * @brief Runs the interactive control routine for this device.
 */
    void controlDevice() override;


/**
 * @brief Gets the Status.
 * @return Result.
 */
    string getStatus() override;


/**
 * @brief Sets the Temperature.
 * @param temp Parameter.
 */
    void setTemperature(int temp);
/**
 * @brief Performs the toggleSuperCool operation.
 */
    void toggleSuperCool();
};

#endif
