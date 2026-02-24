# SmartHomeProject.pro
# Qt project file for SmartHomeProject.
# This repository also includes Doxygen-compatible comments in the source code.

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Admin.cpp \
    CleaningAppliance.cpp \
    Curtain.cpp \
    Device.cpp \
    DishWasher.cpp \
    DryingMachine.cpp \
    Fridge.cpp \
    Home.cpp \
    Light.cpp \
    Oven.cpp \
    Plug.cpp \
    Room.cpp \
    TV.cpp \
    Thermostat.cpp \
    User.cpp \
    WashingMachine.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Admin.h \
    CleaningAppliance.h \
    CommonDevice.h \
    Curtain.h \
    Device.h \
    DishWasher.h \
    DryingMachine.h \
    Fridge.h \
    Home.h \
    KitchenAppliance.h \
    Light.h \
    Oven.h \
    Plug.h \
    Room.h \
    SpecialDevice.h \
    TV.h \
    Thermostat.h \
    User.h \
    WashingMachine.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
