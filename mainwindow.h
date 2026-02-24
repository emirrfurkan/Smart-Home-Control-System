/**
 * @file mainwindow.h
 * @brief Main window UI controller for the Qt application.
 *
 * This file is part of the SmartHomeProject application.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>

#include "Home.h"
#include "User.h"
#include "Room.h" // is neccassary for selectedRoom
#include <QInputDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief Represents a MainWindow in the smart home system.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
/**
 * @brief Performs the MainWindow operation.
 * @param parent Parameter.
 */
    MainWindow(QWidget *parent = nullptr);
/**
 * @brief Destroys the MainWindow instance and releases resources.
 */
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // Variables
    Home* myHome;
    User* currentUser;
    Room* selectedRoom;

    // Helper Method
/**
 * @brief Sets the upDummyData.
 */
    void setupDummyData();
/**
 * @brief Sets the upHomePage.
 */
    void setupHomePage();
/**
 * @brief Sets the upRoomListPage.
 */
    void setupRoomListPage();
/**
 * @brief Sets the upRoomDetailPage.
 */
    void setupRoomDetailPage();
/**
 * @brief Performs the clearLayout operation.
 * @param layout Parameter.
 */
    void clearLayout(QLayout *layout);

private slots:
    // First Page Buttons
/**
 * @brief Performs the on_btnAdmin_clicked operation.
 */
    void on_btnAdmin_clicked();
/**
 * @brief Performs the on_btnUser_clicked operation.
 */
    void on_btnUser_clicked();
/**
 * @brief Performs the on_btnAddRoom_clicked operation.
 */
    void on_btnAddRoom_clicked();
/**
 * @brief Performs the on_btnAddUser_clicked operation.
 */
    void on_btnAddUser_clicked();

    // 2. Page Buttons
/**
 * @brief Performs the on_btnGlobalLightOff_clicked operation.
 */
    void on_btnGlobalLightOff_clicked();
/**
 * @brief Performs the on_btnGlobalCurtains_clicked operation.
 */
    void on_btnGlobalCurtains_clicked();
/**
 * @brief Performs the on_btnGlobalWaterOff_clicked operation.
 */
    void on_btnGlobalWaterOff_clicked();
/**
 * @brief Performs the on_btnGlobalDoorLock_clicked operation.
 */
    void on_btnGlobalDoorLock_clicked();
/**
 * @brief Performs the on_btnGlobalTempUp_clicked operation.
 */
    void on_btnGlobalTempUp_clicked();
/**
 * @brief Performs the on_btnGlobalTempDown_clicked operation.
 */
    void on_btnGlobalTempDown_clicked();

    // 3.Page
/**
 * @brief Performs the on_listWidgetRooms_itemClicked operation.
 * @param item Parameter.
 */
    void on_listWidgetRooms_itemClicked(QListWidgetItem *item);

/**
 * @brief Performs the on_btnBackToRooms_clicked operation.
 */
    void on_btnBackToRooms_clicked();
};

#endif // MAINWINDOW_H
