/**
 * @file Room.h
 * @brief Room class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>

/**
 * @class Device
 * @brief Represents a Device in the smart home system.
 */
class Device;

/**
 * @class Room
 * @brief Represents a Room in the smart home system.
 */
class Room {
private:
    std::string roomName;
    std::vector<Device*> devices;

public:
/**
 * @brief Performs the Room operation.
 * @param name Parameter.
 * @return Result.
 */
    explicit Room(const std::string& name);
/**
 * @brief Destroys the Room instance and releases resources.
 */
    ~Room();

/**
 * @brief Performs the addDevice operation.
 * @param newDevice Parameter.
 */
    void addDevice(Device* newDevice);
/**
 * @brief Performs the removeDevice operation.
 * @param targetDevice Parameter.
 */
    void removeDevice(Device* targetDevice);
/**
 * @brief Performs the listDevices operation.
 */
    void listDevices();

/**
 * @brief Gets the Device.
 * @param deviceName Parameter.
 * @return Result.
 */
    Device* getDevice(const std::string& deviceName);

/**
 * @brief Gets the Name.
 * @return Result.
 */
    std::string getName() const;


/**
 * @brief Gets the Devices.
 * @return Result.
 */
    std::vector<Device*>& getDevices();
/**
 * @brief Gets the Devices.
 * @return Result.
 */
    const std::vector<Device*>& getDevices() const;
};

#endif
