/**
 * @file Curtain.h
 * @brief Curtain class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef CURTAIN_H
#define CURTAIN_H

#include "CommonDevice.h"

/**
 * @class Curtain
 * @brief Represents a Curtain in the smart home system.
 */
class Curtain : public CommonDevice {
private:
    int openPercentage;

public:
/**
 * @brief Performs the Curtain operation.
 * @param id Parameter.
 * @param n Parameter.
 */
    Curtain(int id, string n);
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
 * @brief Performs the openCurtain operation.
 * @param percent Parameter.
 */
    void openCurtain(int percent);
/**
 * @brief Performs the closeCurtain operation.
 */
    void closeCurtain();
};

#endif
