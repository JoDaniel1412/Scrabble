#include "hostwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork/QHostAddress>
#include <QNetworkInterface>
#include <QSettings>


// Saves changes that have been made to Settings
void saveSettings(const QString &key,
                  const QVariant &valor,
                  const QString &group){

    QSettings S;
    S.beginGroup(group);
    S.setValue(key, valor);
    S.endGroup();
}

// Loads the last saved changes on Settings.
QVariant loadSettings(const QString &key,
                      const QVariant defaultValue,
                      const QString &group){

    QVariant v;
    QSettings S;
    S.beginGroup(group);
    v = S.value(key, defaultValue);
    S.endGroup();

    return v;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1024, 768);

    QSize size1;

    size1 = loadSettings("Size", size(), "Window").value<QSize>();
    resize(size1);

    loadFromPropertiesWindow();
    qInfo() << "IP2: " << ip << " Port2: " << port;

}

MainWindow::~MainWindow()
{
    delete ui;

}

// Changes from mainWindow to hostWindow.
void MainWindow::on_hostBtn_clicked()
{
    this -> hide();
    hostWindow = new HostWindow(this);
    hostWindow -> show();

}

// Changes from mainWindow to joinWindow.
void MainWindow::on_joinBtn_clicked()
{
    loadFromPropertiesWindow();
    qInfo() << "IP3: " << ip << " Port3: " << port;
    this -> hide( );
    joinWindow = new JoinWindow(this);
    joinWindow -> show();
}

// Displays properites Window.
void MainWindow::on_propertiesBtn_clicked()
{
    propertiesWindow = new PropertiesWindow(this);
    propertiesWindow -> show();
}

// Saves settings changes when MainWindow is closed.
void MainWindow::closeEvent(QCloseEvent *e){
    saveSettings("IP", ip, "Server");
    saveSettings("PORT", port, "Server");
    saveSettings("Size", size(), "Window");

    QWidget::closeEvent(e);
}

void MainWindow::on_exitBtn_clicked()
{
    QApplication::quit();
}

void MainWindow::on_testBtn_clicked()
{
    MockDock::makeLetters();
    MockGame::makePlayers();

    this->hide();
    gameWindow = new GameWindow();
    gameWindow->show();
}

void MainWindow::loadFromPropertiesWindow()
{
    ip = PropertiesWindow::getInstance()->getIP();
    port = PropertiesWindow::getInstance()->getPort();

    loadSettings("IP", ip, "Server");
    loadSettings("PORT", port, "Server");
    loadSettings("NUMBER", number, "Server");

}
