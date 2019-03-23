#include "hostwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QtNetwork/QHostAddress>
#include <QNetworkInterface>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1024, 768);

}

MainWindow::~MainWindow()
{
    delete ui;

}

//Changes from mainWindow to hostWindow.
void MainWindow::on_hostBtn_clicked()
{
    this -> hide( );
    hostWindow = new HostWindow(this);
    hostWindow -> show();

}

void MainWindow::on_joinBtn_clicked()
{
    this -> hide( );
    joinWindow = new JoinWindow(this);
    joinWindow -> show();
}

void MainWindow::on_configBtn_clicked()
{
    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost)
             qDebug() << address.toString();
    }
}
