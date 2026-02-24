/**
 * @file Thermostat.h
 * @brief Thermostat class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "CommonDevice.h"

/**
 * @class Thermostat
 * @brief Represents a Thermostat in the smart home system.
 */
class Thermostat : public Device {
private:
    double targetTemperature;

public:
/**
 * @brief Performs the Thermostat operation.
 * @param id Parameter.
 * @param n Parameter.
 */
    Thermostat(int id, string n);


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
    void setTemperature(double temp);
};

#endif
