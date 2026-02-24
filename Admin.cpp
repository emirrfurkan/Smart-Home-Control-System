/**
 * @file Admin.cpp
 * @brief Admin class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#include "Admin.h"
#include "Room.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Constructor
Admin::Admin(string uName, string pass, string realName)
    : User(uName, pass, realName) {

}


void Admin::addDevice(Room* targetRoom, Device* newDevice) {
    if (targetRoom != nullptr && newDevice != nullptr) {

        targetRoom->addDevice(newDevice);
        cout << "[ADMIN]: " << newDevice->getName() << " device "
             << targetRoom->getName() << " add room." << endl;
    } else {
        cout << "[Error]: Invalid room or device" << endl;
    }
}


void Admin::removeDevice(Room* targetRoom, Device* targetDevice) {
    if (targetRoom != nullptr && targetDevice != nullptr) {

        targetRoom->removeDevice(targetDevice);
        cout << "[ADMIN]: Removed device." << endl;
    }
}


void Admin::addUser(vector<User*>& userList, User* newUser) {

    userList.push_back(newUser);
    cout << "[ADMIN]: New user (" << newUser->getUsername() << ") add to system." << endl;
}


void Admin::removeUser(vector<User*>& userList, User* targetUser) {

    bool found = false;
    for (auto it = userList.begin(); it != userList.end(); ++it) {
        if (*it == targetUser) {
            userList.erase(it);
            found = true;
            cout << "[ADMIN]:Removed user." << endl;
            break;
        }
    }

    if (!found) {
        cout << "[Error]:Don't found the list" << endl;
    }
}
