/**
 * @file DryingMachine.h
 * @brief DryingMachine class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef DRYINGMACHINE_H
#define DRYINGMACHINE_H

#include "CleaningAppliance.h"

/**
 * @class DryingMachine
 * @brief Represents a DryingMachine in the smart home system.
 */
class DryingMachine : public CleaningAppliance {
private:
    string drynessLevel;
    bool filterStatus;
public:
/**
 * @brief Performs the DryingMachine operation.
 * @param id Parameter.
 * @param n Parameter.
 */
    DryingMachine(int id, string n);
/**
 * @brief Runs the interactive control routine for this device.
 */
    void controlDevice() override;

/**
 * @brief Sets the DrynessLevel.
 * @param level Parameter.
 */
    void setDrynessLevel(string level);
/**
 * @brief Performs the cleanFilterReset operation.
 */
    void cleanFilterReset();
};

#endif
