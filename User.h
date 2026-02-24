/**
 * @file User.h
 * @brief User class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include "Device.h"

using namespace std;

/**
 * @class User
 * @brief Represents a User in the smart home system.
 */
class User {
protected:

    string username;
    string password;
    string name;

public:

/**
 * @brief Performs the User operation.
 * @param uName Parameter.
 * @param pass Parameter.
 * @param realName Parameter.
 */
    User(string uName, string pass, string realName);


/**
 * @brief Destroys the User instance and releases resources.
 */
    virtual ~User();

/**
 * @brief Performs the login operation.
 * @param inputPassword Parameter.
 * @return Result.
 */
    bool login(string inputPassword);

/**
 * @brief Performs the viewDeviceStatus operation.
 * @param d Parameter.
 */
    void viewDeviceStatus(Device* d);

/**
 * @brief Runs the interactive control routine for this device.
 * @param d Parameter.
 */
    virtual void controlDevice(Device* d);

/**
 * @brief Gets the Username.
 * @return Result.
 */
    string getUsername() const;
/**
 * @brief Gets the Name.
 * @return Result.
 */
    string getName() const;
};

#endif // USER_H
