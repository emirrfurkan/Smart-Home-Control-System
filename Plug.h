/**
 * @file Plug.h
 * @brief Plug class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef PLUG_H
#define PLUG_H

#include "CommonDevice.h"

/**
 * @class Plug
 * @brief Represents a Plug in the smart home system.
 */
class Plug : public CommonDevice {
private:
    double energyUsage;

public:
/**
 * @brief Performs the Plug operation.
 * @param id Parameter.
 * @param n Parameter.
 */
    Plug(int id, string n);
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
 * @brief Gets the EnergyReport.
 */
    void getEnergyReport();
/**
 * @brief Sets the Timer.
 * @param minutes Parameter.
 */
    void setTimer(int minutes);
};

#endif
