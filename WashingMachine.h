/**
 * @file WashingMachine.h
 * @brief WashingMachine class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef WASHINGMACHINE_H
#define WASHINGMACHINE_H

#include "CleaningAppliance.h"

/**
 * @class WashingMachine
 * @brief Represents a WashingMachine in the smart home system.
 */
class WashingMachine : public CleaningAppliance {
private:
    int rpm;
    int waterTemp;

public:
/**
 * @brief Performs the WashingMachine operation.
 * @param id Parameter.
 * @param n Parameter.
 */
    WashingMachine(int id, string n);


/**
 * @brief Runs the interactive control routine for this device.
 */
    void controlDevice() override;


/**
 * @brief Sets the SpinSpeed.
 * @param speed Parameter.
 */
    void setSpinSpeed(int speed);
/**
 * @brief Sets the WaterTemp.
 * @param temp Parameter.
 */
    void setWaterTemp(int temp);
};

#endif
