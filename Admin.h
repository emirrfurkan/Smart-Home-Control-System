/**
 * @file Admin.h
 * @brief Admin class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <vector>

/**
 * @class Room
 * @brief Represents a Room in the smart home system.
 */
class Room;

/**
 * @class Admin
 * @brief Represents a Admin in the smart home system.
 */
class Admin : public User {
public:

    Admin(string uName, string pass, string realName); //constructor


    void addDevice(Room* targetRoom, Device* newDevice); //add device method

    void removeDevice(Room* targetRoom, Device* targetDevice);//remove device method

    void addUser(vector<User*>& userList, User* newUser); // add user method

    void removeUser(vector<User*>& userList, User* targetUser); // remove user method

};

#endif
