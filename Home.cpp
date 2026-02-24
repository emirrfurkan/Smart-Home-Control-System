/**
 * @file Home.cpp
 * @brief Home class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#include "Home.h"

// Constructor
Home::Home(string name) : homeName(name) {
    cout << "--- " << homeName << " Smart Home System Started ---" << endl;
}

// Destructor
Home::~Home() {
    cout << "System is shutting down, cleaning memory..." << endl;

    // Delete rooms from memory
    for (Room* r : rooms) {
        delete r;
    }
    rooms.clear();

    // Delete users from memory
    for (User* u : users) {
        delete u;
    }
    users.clear();
}

// Add Room
void Home::addRoom(Room* newRoom) {
    if (newRoom != nullptr) {
        rooms.push_back(newRoom);

    }
}

// Find Room
Room* Home::getRoom(string roomName) {
    for (Room* r : rooms) {
        if (r->getName() == roomName) {
            return r; // Room found, return its address
        }
    }
    return nullptr; // Not found
}

// User Authentication (Login)
User* Home::authenticateUser(string username, string inputPassword) {
    for (User* u : users) {
        // Check username
        if (u->getUsername() == username) {
            // If username matches, check password
            if (u->login(inputPassword)) {
                return u; // Login successful
            } else {
                return nullptr; // Wrong password
            }
        }
    }
    cout << "User not found!" << endl;
    return nullptr;
}

// Get User List (for Admin)
vector<User*>& Home::getUsers() {
    return users;
}

// General Status Report
void Home::printHomeStatus() {
    cout << "\n=== HOME STATUS REPORT ===" << endl;
    cout << "Number of Registered Rooms: " << rooms.size() << endl;
    cout << "Number of Registered Users: " << users.size() << endl;

    // List devices in each room
    for (Room* r : rooms) {
        r->listDevices();
    }
    cout << "==========================\n" << endl;
}
