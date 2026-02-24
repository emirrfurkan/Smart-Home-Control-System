/**
 * @file TV.cpp
 * @brief TV class implementation/declaration.
 *
 * This file is part of the SmartHomeProject application.
 */

#include "TV.h"

TV::TV(int id, string n) : Device(id, n), volume(15), currentChannel(1) {
    // Start on channel 1 with volume set to 15 by default.
}

void TV::setVolume(int vol) {
    if (vol >= 0 && vol <= 100) {
        volume = vol;
        cout << getName() << " volume level: " << volume << endl;
    } else {
        cout << "Error: Volume must be between 0 and 100." << endl;
    }
}

void TV::setChannel(int channel) {
    if (channel > 0 && channel < 1000) {
        currentChannel = channel;
        cout << getName() << " channel changed to: " << currentChannel << endl;
    } else {
        cout << "Error: Invalid channel number." << endl;
    }
}

void TV::channelUp() {
    setChannel(currentChannel + 1);
}

void TV::channelDown() {
    if (currentChannel > 1) {
        setChannel(currentChannel - 1);
    }
}

string TV::getStatus() {
    string base = Device::getStatus();
    if (getIsOn()) {
        return base + " [Channel: " + to_string(currentChannel) +
               ", Volume: " + to_string(volume) + "]";
    } else {
        return base;
    }
}

void TV::controlDevice() {
    int choice;
    cout << "\n--- " << getName() << " REMOTE CONTROL ---" << endl;

    if (!getIsOn()) {
        // If the TV is off, only show the power-on option
        cout << "1. Turn On TV" << endl;
        cout << "0. Exit" << endl;
    } else {
        // If the TV is on, show all options
        cout << "1. Turn Off TV" << endl;
        cout << "2. Set Volume (Current: " << volume << ")" << endl;
        cout << "3. Change Channel (Current: " << currentChannel << ")" << endl;
        cout << "4. Next Channel (+)" << endl;
        cout << "5. Previous Channel (-)" << endl;
        cout << "0. Exit" << endl;
    }

    cout << "Your choice: ";
    cin >> choice;

    if (!getIsOn()) {
        if (choice == 1) turnOn();
    } else {
        switch (choice) {
        case 1:
            turnOff();
            break;
        case 2: {
            int v;
            cout << "Volume Level (0-100): ";
            cin >> v;
            setVolume(v);
            break;
        }
        case 3: {
            int c;
            cout << "Channel Number: ";
            cin >> c;
            setChannel(c);
            break;
        }
        case 4:
            channelUp();
            break;
        case 5:
            channelDown();
            break;
        default:
            break;
        }
    }
}
