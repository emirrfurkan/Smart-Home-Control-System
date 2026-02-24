/**
 * @file mainwindow.cpp
 * @brief Main window UI controller for the Qt application.
 *
 * This file is part of the SmartHomeProject application.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

// --- CLASSES ---
#include "Admin.h"
#include "User.h"
#include "Home.h"
#include "Room.h"
#include "Device.h"

// --- DEVICES ---
#include "Light.h"
#include "Curtain.h"
#include "Plug.h"
#include "TV.h"
#include "Thermostat.h"

// --- UI LIBRARIES ---
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myHome = new Home("Smart Home");
    currentUser = nullptr;
    selectedRoom = nullptr;

    setupDummyData();

    setupRoomListPage();

    ui->stackedWidget->setCurrentIndex(0);
    this->setStyleSheet("background-color: #BDE0FE;");

    QString buttonStyle =
        "QPushButton { background-color: white; border-radius: 25px; color: black; font: bold 16px; padding: 15px; border: 1px solid #E0E0E0; }"
        "QPushButton:hover { background-color: #F0F8FF; }"
        "QPushButton:pressed { background-color: #E0E0E0; }";

    ui->btnAdmin->setStyleSheet(buttonStyle);
    ui->btnUser->setStyleSheet(buttonStyle);
    ui->lblTitle->setStyleSheet("font: bold 28px; color: #333333; background: transparent;");
}

MainWindow::~MainWindow()
{
    delete myHome;
    delete ui;
}

// --- HELPER BUTTON CREATION FUNCTION ---
void MainWindow::clearLayout(QLayout* layout) {
    if (!layout) return;
    QLayoutItem* item;
    while ((item = layout->takeAt(0))) {
        if (item->widget()) {
            delete item->widget();
        }
        if (item->layout()) {
            clearLayout(item->layout());
        }
        delete item;
    }
}

QWidget* createCustomButton(QString labelText, QString insideText, QWidget* parent) {
    QWidget* container = new QWidget(parent);
    QVBoxLayout* layout = new QVBoxLayout(container);

    QPushButton* btn = new QPushButton(insideText, parent);
    btn->setFixedSize(100, 100);
    btn->setStyleSheet(
        "QPushButton { background-color: white; color: #333; border: 3px solid #333; border-radius: 50px; font-weight: bold; font-size: 18px; }"
        "QPushButton:pressed { background-color: #ddd; }"
        "QPushButton:hover { border-color: #007bff; color: #007bff; }"
        );

    QLabel* lbl = new QLabel(labelText, parent);
    lbl->setAlignment(Qt::AlignCenter);
    lbl->setWordWrap(true);
    lbl->setStyleSheet("font-size: 14px; font-weight: bold; color: #333; margin-top: 5px;");

    layout->addWidget(btn);
    layout->addWidget(lbl);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(0,0,0,0);

    return container;
}

// --- MAIN WINDOW CONSTRUCTOR ---


// --- DUMMY DATA ---
void MainWindow::setupDummyData() {
    Admin* admin = new Admin("admin", "1234", "System Administrator");
    User* normalUser = new User("ali", "1234", "Ali Veli");

    myHome->getUsers().push_back(admin);
    myHome->getUsers().push_back(normalUser);

    Room* livingRoom = new Room("Living Room");
    Room* kitchen = new Room("Kitchen");
    Room* bathroom = new Room("Bathroom");

    myHome->addRoom(livingRoom);
    myHome->addRoom(kitchen);
    myHome->addRoom(bathroom);

    Light* lightLivingRoom = new Light(101, "Chandelier");
    TV* livinRoomTV = new TV(102, "Main TV");
    Curtain* livingRoomCurtain = new Curtain(103, "Curtain");
    Thermostat* thermostat = new Thermostat(104, "Thermostat");

    admin->addDevice(livingRoom, lightLivingRoom);
    admin->addDevice(livingRoom, livinRoomTV);
    admin->addDevice(livingRoom, livingRoomCurtain);
    admin->addDevice(livingRoom, thermostat);

    Plug* coffePlug = new Plug(201, "Coffee Machine");
    Light* kittchenLight = new Light(202, "Kitchen LED");

    Light* bathroomLight = new Light(301,"Light");

    admin->addDevice(kitchen, coffePlug);
    admin->addDevice(kitchen, kittchenLight);
    admin->addDevice(bathroom, bathroomLight);
}

// --- USER LOGIN (DIRECT / NO PASSWORD) ---
void MainWindow::on_btnUser_clicked()
{
    User* user = myHome->authenticateUser("ali", "1234");

    if (user != nullptr) {
        currentUser = user;

        ui->txtUserName->clear();
        ui->txtPassword->clear();

        setupHomePage();
        setupRoomListPage();

        ui->stackedWidget->setCurrentIndex(1);
        qDebug() << "User (Ali) logged in automatically.";
    } else {
        QMessageBox::critical(this, "Error", "Automatic login failed! (User Ali not found)");
    }
}

// --- ADMIN LOGIN (PASSWORD REQUIRED) ---
void MainWindow::on_btnAdmin_clicked()
{
    QString username = ui->txtUserName->text();
    QString password = ui->txtPassword->text();

    if(username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Error", "Username and password are required for admin login!");
        return;
    }

    User* foundUser = myHome->authenticateUser(username.toStdString(), password.toStdString());

    if (foundUser != nullptr && foundUser->getUsername() == "admin") {
        currentUser = foundUser;

        ui->txtPassword->clear();

        setupHomePage();
        setupRoomListPage();

        ui->stackedWidget->setCurrentIndex(1);
        qDebug() << "Admin logged in securely.";
    } else {
        QMessageBox::critical(this, "Error", "Login failed! Check your credentials.");
    }
}

// --- PAGE 2: HOME SCREEN ---
void MainWindow::setupHomePage() {
    QWidget* homePageWidget = ui->stackedWidget->widget(1);

    QGridLayout* gridLayout = homePageWidget->findChild<QGridLayout*>();
    if (gridLayout) {
        QLayoutItem* item;
        while ((item = gridLayout->takeAt(0))) {
            if (item->widget()) delete item->widget();
            delete item;
        }
    } else {
        gridLayout = new QGridLayout(homePageWidget);
        gridLayout->setSpacing(20);
        gridLayout->setContentsMargins(40, 40, 40, 40);
    }



    QPushButton* btnBackHome = new QPushButton("< Back", homePageWidget);
    btnBackHome->setFixedSize(100, 40);
    btnBackHome->setStyleSheet("background-color: #444; color: white; font-weight: bold; border-radius: 10px;");
    connect(btnBackHome, &QPushButton::clicked, this, [=](){
        currentUser = nullptr;
        selectedRoom = nullptr;
        ui->stackedWidget->setCurrentIndex(0);
    });
    gridLayout->addWidget(btnBackHome, 0, 0, 1, 2, Qt::AlignLeft);

    QWidget* wLight = createCustomButton("Turn off all\ndevices", "OFF", this);
    connect(wLight->findChild<QPushButton*>(), &QPushButton::clicked, this, &MainWindow::on_btnGlobalLightOff_clicked);
    gridLayout->addWidget(wLight, 1, 0);

    QWidget* wCurtain = createCustomButton("Close all\ncurtains", "CLOSE", this);
    connect(wCurtain->findChild<QPushButton*>(), &QPushButton::clicked, this, &MainWindow::on_btnGlobalCurtains_clicked);
    gridLayout->addWidget(wCurtain, 1, 1);

    QWidget* wWater = createCustomButton("Turn off\nthe water", "H2O", this);
    connect(wWater->findChild<QPushButton*>(), &QPushButton::clicked, this, &MainWindow::on_btnGlobalWaterOff_clicked);
    gridLayout->addWidget(wWater, 2, 0);

    QWidget* wDoor = createCustomButton("Lock off\nall doors", "LOCK", this);
    connect(wDoor->findChild<QPushButton*>(), &QPushButton::clicked, this, &MainWindow::on_btnGlobalDoorLock_clicked);
    gridLayout->addWidget(wDoor, 2, 1);

    QWidget* wTempUp = createCustomButton("Increase\nTemperature", "TEMP +", this);
    connect(wTempUp->findChild<QPushButton*>(), &QPushButton::clicked, this, &MainWindow::on_btnGlobalTempUp_clicked);
    gridLayout->addWidget(wTempUp, 3, 0);

    QWidget* wTempDown = createCustomButton("Decrease\nTemperature", "TEMP -", this);
    connect(wTempDown->findChild<QPushButton*>(), &QPushButton::clicked, this, &MainWindow::on_btnGlobalTempDown_clicked);
    gridLayout->addWidget(wTempDown, 3, 1);

    QPushButton* btnGoToRooms = new QPushButton("Room List >", homePageWidget);
    btnGoToRooms->setStyleSheet("background-color: #2980b9; color: white; font-weight: bold; padding: 15px; border-radius: 10px;");
    gridLayout->addWidget(btnGoToRooms, 4, 0, 1, 2);

    connect(btnGoToRooms, &QPushButton::clicked, this, [=](){
        setupRoomListPage();
        ui->stackedWidget->setCurrentIndex(2);
    });
}

// --- GLOBAL BUTTON FUNCTIONS ---
void MainWindow::on_btnGlobalLightOff_clicked() {
    for (Room* r : myHome->getRooms()) {
        for (Device* d : r->getDevices()) {
            if (dynamic_cast<Light*>(d) || dynamic_cast<TV*>(d)) {
                d->turnOff();
            }
        }
    }
    QMessageBox::information(this, "System", "All lights and TVs turned off.");
}

void MainWindow::on_btnGlobalCurtains_clicked() {
    for (Room* r : myHome->getRooms()) {
        for (Device* d : r->getDevices()) {
            Curtain* c = dynamic_cast<Curtain*>(d);
            if (c) c->closeCurtain();
        }
    }
    QMessageBox::information(this, "System", "All curtains closed.");
}

void MainWindow::on_btnGlobalWaterOff_clicked() {
    QMessageBox::information(this, "System", "Main water valve turned off.");
}

void MainWindow::on_btnGlobalDoorLock_clicked() {
    QMessageBox::information(this, "System", "All doors locked.");
}

void MainWindow::on_btnGlobalTempUp_clicked() {
    for (Room* r : myHome->getRooms()) {
        for (Device* d : r->getDevices()) {
            Thermostat* t = dynamic_cast<Thermostat*>(d);
            if (t) t->setTemperature(26);
        }
    }
    QMessageBox::information(this, "Temperature", "Temperature increased (26°C)");
}

void MainWindow::on_btnGlobalTempDown_clicked() {
    for (Room* r : myHome->getRooms()) {
        for (Device* d : r->getDevices()) {
            Thermostat* t = dynamic_cast<Thermostat*>(d);
            if (t) t->setTemperature(18);
        }
    }
    QMessageBox::information(this, "Temperature", "Temperature decreased (18°C)");
}

// --- PAGE 3: ROOM LIST ---
void MainWindow::setupRoomListPage() {
    QWidget* listPage = ui->stackedWidget->widget(2);

    QVBoxLayout* layout = listPage->findChild<QVBoxLayout*>();
    if (!layout) {
        layout = new QVBoxLayout(listPage);
    }


    QPushButton* oldBack = listPage->findChild<QPushButton*>("btnBackToHome");
    if (oldBack) delete oldBack;

    QPushButton* btnBackToHome = new QPushButton("< Back", listPage);
    btnBackToHome->setObjectName("btnBackToHome");
    btnBackToHome->setFixedSize(100, 40);
    btnBackToHome->setStyleSheet("background-color: #444; color: white; font-weight: bold; border-radius: 10px; margin-bottom: 10px;");
    connect(btnBackToHome, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(1); // Home
    });
    layout->insertWidget(0, btnBackToHome);

    QPushButton* oldBtn = listPage->findChild<QPushButton*>("btnDynamicAddRoom");
    if (oldBtn) {
        delete oldBtn;
    }

    if (ui->listWidgetRooms) {
        ui->listWidgetRooms->clear();

        ui->listWidgetRooms->setStyleSheet(
            "QListWidget { background-color: transparent; border: none; }"
            "QListWidget::item { background-color: white; border: 2px solid #ce5cff; border-radius: 15px; color: black; font-size: 18px; font-weight: bold; padding: 15px; margin-bottom: 10px; }"
            "QListWidget::item:hover { background-color: #f0e6ff; }"
            "QListWidget::item:selected { background-color: #ce5cff; color: white; }"
            );

        for (Room* r : myHome->getRooms()) {
            QString roomName = QString::fromStdString(r->getName());
            QListWidgetItem* item = new QListWidgetItem(roomName);
            item->setTextAlignment(Qt::AlignCenter);
            ui->listWidgetRooms->addItem(item);
        }
    }

    if (currentUser && currentUser->getUsername() == "admin") {
        QPushButton* btnAddRoom = new QPushButton("+ ADD NEW ROOM", listPage);
        btnAddRoom->setObjectName("btnDynamicAddRoom");
        btnAddRoom->setStyleSheet("background-color: #8e44ad; color: white; font-weight: bold; padding: 15px; border-radius: 10px; margin-top: 10px;");

        layout->addWidget(btnAddRoom);

        connect(btnAddRoom, &QPushButton::clicked, this, &MainWindow::on_btnAddRoom_clicked);
    }
}

// --- ROOM SELECTION (CLICK) ---
void MainWindow::on_listWidgetRooms_itemClicked(QListWidgetItem *item)
{
    QString clickedRoomName = item->text();
    selectedRoom = nullptr;

    for (Room* r : myHome->getRooms()) {
        if (QString::fromStdString(r->getName()) == clickedRoomName) {
            selectedRoom = r;
            break;
        }
    }

    if (selectedRoom != nullptr) {
        setupRoomDetailPage();
        ui->stackedWidget->setCurrentIndex(3);
    }
}

// --- PAGE 4: ROOM DETAIL (DYNAMIC)
void MainWindow::setupRoomDetailPage() {
    qDebug() << "STEP 1: setupRoomDetailPage started.";

    if (selectedRoom == nullptr) {
        qDebug() << "WARNING: No room selected (nullptr). Operation cancelled.";
        return;
    }

    QWidget* detailPage = ui->stackedWidget->widget(3);
    if (!detailPage) {
        QMessageBox::critical(this, "Error", "Page 4 is missing in design!");
        return;
    }

    //qDebug() << "STEP 2: Cleaning started...";
    qDeleteAll(detailPage->findChildren<QWidget*>());
    if (detailPage->layout()) {
        delete detailPage->layout();
    }

    QVBoxLayout* mainLayout = new QVBoxLayout(detailPage);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(20,20,20,20);

    QPushButton* btnBack = new QPushButton("< BACK", detailPage);
    btnBack->setFixedSize(100, 50);
    btnBack->setStyleSheet("background-color: #333; color: white; font-weight: bold; border-radius: 10px;");
    connect(btnBack, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    QString roomName = "Unknown Room";
    if (selectedRoom) {
        roomName = QString::fromStdString(selectedRoom->getName());
    }

    QLabel* lblTitle = new QLabel(roomName, detailPage);
    lblTitle->setStyleSheet("font-size: 32px; font-weight: bold; color: #2c3e50; margin-left: 20px;");

    QHBoxLayout* topBar = new QHBoxLayout();
    topBar->addWidget(btnBack);
    topBar->addWidget(lblTitle);
    topBar->addStretch();
    mainLayout->addLayout(topBar);

    qDebug() << "STEP 3: Adding devices...";

    std::vector<Device*> devices = selectedRoom->getDevices();

    if (devices.empty()) {
        QLabel* lbl = new QLabel("No Devices", detailPage);
        lbl->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(lbl);
    } else {
        QGridLayout* grid = new QGridLayout();
        int r=0, c=0;
        for(Device* d : devices) {
            if(!d) continue;

            QString status = d->getIsOn() ? "ON" : "OFF";
            QString color = d->getIsOn() ? "background-color: #2ecc71;" : "background-color: #e74c3c;";

            QPushButton* btn = new QPushButton(QString::fromStdString(d->getName()) + "\n" + status);
            btn->setFixedSize(120, 100);
            btn->setStyleSheet(color + "color: white; font-weight: bold; border-radius: 15px;");

            connect(btn, &QPushButton::clicked, this, [=](){
                if(d->getIsOn()) d->turnOff(); else d->turnOn();
                setupRoomDetailPage();
            });

            grid->addWidget(btn, r, c);
            c++; if(c>1) {c=0; r++;}
        }
        mainLayout->addLayout(grid);
    }
    mainLayout->addStretch();
    qDebug() << "STEP 4: Completed successfully.";
}

// --- BACK BUTTON SLOT ---
void MainWindow::on_btnBackToRooms_clicked() {
    ui->stackedWidget->setCurrentIndex(2);
}

// --- ADD NEW ROOM ---
void MainWindow::on_btnAddRoom_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, "Add Room",
                                         "New Room Name:", QLineEdit::Normal,
                                         "", &ok);
    if (ok && !text.isEmpty()) {
        Room* newRoom = new Room(text.toStdString());

        // Default light
        Light* l = new Light(999, "Ceiling Light");
        newRoom->addDevice(l);

        myHome->addRoom(newRoom);

        QMessageBox::information(this, "Success", text + " added successfully.");

        setupRoomListPage();
    }
}

// --- ADD NEW USER ---
void MainWindow::on_btnAddUser_clicked()
{
    bool ok;
    QString name = QInputDialog::getText(this, "Add User",
                                         "New Username:", QLineEdit::Normal,
                                         "", &ok);
    if (ok && !name.isEmpty()) {
        User* newUser = new User(name.toStdString(), "1234", name.toStdString());
        myHome->getUsers().push_back(newUser);

        QMessageBox::information(this, "Success", "User " + name + " added (Password: 1234).");
    }
}
