/**
 * @file DishWasher.h
 * @brief DishWasher class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef DISHWASHER_H
#define DISHWASHER_H

#include "CleaningAppliance.h"

/**
 * @class Dishwasher
 * @brief Represents a Dishwasher in the smart home system.
 */
class Dishwasher : public CleaningAppliance {
private:
    bool saltWarning;

public:
/**
 * @brief Performs the Dishwasher operation.
 * @param id Parameter.
 * @param n Parameter.
 */
    Dishwasher(int id, string n);
/**
 * @brief Runs the interactive control routine for this device.
 */
    void controlDevice() override;

/**
 * @brief Performs the startWashCycle operation.
 */
    void startWashCycle();
/**
 * @brief Performs the checkSalt operation.
 */
    void checkSalt();
};

#endif
