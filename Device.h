/**
 * @file Device.h
 * @brief Device class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <iostream>

using namespace std;

/**
 * @class Device
 * @brief Represents a Device in the smart home system.
 */
class Device {
protected:

    int deviceID;
    string name;
    bool isOn;

public:

/**
 * @brief Performs the Device operation.
 * @param id Parameter.
 * @param n Parameter.
 */
    Device(int id, string n);


/**
 * @brief Destroys the Device instance and releases resources.
 */
    virtual ~Device();


/**
 * @brief Turns the device on.
 */
    virtual void turnOn();
/**
 * @brief Turns the device off.
 */
    virtual void turnOff();
/**
 * @brief Gets the IsOn.
 * @return Result.
 */
    bool getIsOn() const;
/**
 * @brief Gets the Name.
 * @return Result.
 */
    string getName() const;
/**
 * @brief Gets the ID.
 * @return Result.
 */
    int getID() const;



/**
 * @brief Gets the Status.
 * @return Result.
 */
    virtual string getStatus();


/**
 * @brief Runs the interactive control routine for this device.
 */
    virtual void controlDevice() = 0;
};

#endif
