/**
 * @file main.cpp
 * @brief Application entry point.
 *
 * This file is part of the SmartHomeProject application.
 */

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
