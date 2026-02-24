/**
 * @file Home.h
 * @brief Home class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef HOME_H
#define HOME_H

#include <string>
#include <vector>
#include <iostream>


#include "Room.h"
#include "User.h"

using namespace std;

/**
 * @class Home
 * @brief Represents a Home in the smart home system.
 */
class Home {
private:
    string homeName;


    vector<Room*> rooms;
    vector<User*> users;

public:

/**
 * @brief Performs the Home operation.
 * @param name Parameter.
 */
    Home(string name);


/**
 * @brief Destroys the Home instance and releases resources.
 */
    ~Home();


/**
 * @brief Performs the addRoom operation.
 * @param newRoom Parameter.
 */
    void addRoom(Room* newRoom);

/**
 * @brief Gets the Room.
 * @param roomName Parameter.
 * @return Result.
 */
    Room* getRoom(string roomName);


/**
 * @brief Performs the authenticateUser operation.
 * @param username Parameter.
 * @param inputPassword Parameter.
 * @return Result.
 */
    User* authenticateUser(string username, string inputPassword);


/**
 * @brief Gets the Users.
 * @return Result.
 */
    vector<User*>& getUsers();
    vector<Room*>& getRooms(){return rooms;}

/**
 * @brief Performs the printHomeStatus operation.
 */
    void printHomeStatus();
};

#endif
