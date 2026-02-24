/**
 * @file TV.h
 * @brief TV class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef TV_H
#define TV_H

#include "SpecialDevice.h"

/**
 * @class TV
 * @brief Represents a TV in the smart home system.
 */
class TV : public Device {
private:
    int volume;
    int currentChannel;

public:
/**
 * @brief Performs the TV operation.
 * @param id Parameter.
 * @param n Parameter.
 */
    TV(int id, string n);


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
 * @brief Sets the Volume.
 * @param vol Parameter.
 */
    void setVolume(int vol);
/**
 * @brief Sets the Channel.
 * @param channel Parameter.
 */
    void setChannel(int channel);
/**
 * @brief Performs the channelUp operation.
 */
    void channelUp();
/**
 * @brief Performs the channelDown operation.
 */
    void channelDown();
};

#endif
