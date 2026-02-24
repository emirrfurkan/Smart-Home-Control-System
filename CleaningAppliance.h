/**
 * @file CleaningAppliance.h
 * @brief CleaningAppliance class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef CLEANINGAPPLIANCE_H
#define CLEANINGAPPLIANCE_H

#include "Device.h"


/**
 * @class CleaningAppliance
 * @brief Represents a CleaningAppliance in the smart home system.
 */
class CleaningAppliance : public Device {
protected:
    string currentProgram;
    int remainingTime;
public:
/**
 * @brief Performs the CleaningAppliance operation.
 * @param id Parameter.
 * @param n Parameter.
 */
    CleaningAppliance(int id, string n);


/**
 * @brief Sets the Program.
 * @param prog Parameter.
 */
    void setProgram(string prog);
/**
 * @brief Sets the Timer.
 * @param minutes Parameter.
 */
    void setTimer(int minutes);


/**
 * @brief Gets the Status.
 * @return Result.
 */
    string getStatus() override;

};

#endif
