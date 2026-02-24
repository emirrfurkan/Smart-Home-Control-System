/**
 * @file Oven.h
 * @brief Oven class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef OVEN_H
#define OVEN_H

#include "KitchenAppliance.h"

/**
 * @class Oven
 * @brief Represents a Oven in the smart home system.
 */
class Oven : public KitchenAppliance {
private:
    int temperature;
    string cookingMode;

public:
/**
 * @brief Performs the Oven operation.
 * @param id Parameter.
 * @param n Parameter.
 */
    Oven(int id, string n);

/**
 * @brief Runs the interactive control routine for this device.
 */
    void controlDevice() override;


/**
 * @brief Sets the Temperature.
 * @param temp Parameter.
 */
    void setTemperature(int temp);
/**
 * @brief Sets the CookingMode.
 * @param mode Parameter.
 */
    void setCookingMode(string mode);
};

#endif
