#include "joinwindow.h"
#include "hostwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDebug>

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

// Changes from mainWindow to hostWindow.
void MainWindow::on_hostBtn_clicked()
{
    this -> hide( );
    hostWindow = new HostWindow( );
    hostWindow -> show();

}

// Changes from mainWindow to joinWindow.


void MainWindow::on_joinBtn_clicked()
{
    this -> hide( );
    joinWindow = new JoinWindow( );
    joinWindow -> show();

}
