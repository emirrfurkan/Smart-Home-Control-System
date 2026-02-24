/**
 * @file Light.h
 * @brief Light class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef LIGHT_H
#define LIGHT_H

#include "CommonDevice.h"

/**
 * @class Light
 * @brief Represents a Light in the smart home system.
 */
class Light : public CommonDevice {
private:
    int brightness;

public:
/**
 * @brief Performs the Light operation.
 * @param id Parameter.
 * @param n Parameter.
 */
    Light(int id, string n);


/**
 * @brief Runs the interactive control routine for this device.
 */
    void controlDevice() override;


/**
 * @brief Sets the Brightness.
 * @param level Parameter.
 */
    void setBrightness(int level);
};

#endif
