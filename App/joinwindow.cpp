#include "joinwindow.h"
#include "ui_joinwindow.h"
#include "mainwindow.h"
#include "gamewindow.h"

JoinWindow::JoinWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JoinWindow)
{
    ui->setupUi(this);
    this->resize(1024, 768);
}

JoinWindow::~JoinWindow()
{
    delete ui;
}

void JoinWindow::on_returnBtn_clicked()
{
    this->hide();

    // Show the MainWindow (i.e. the parent window)
    QWidget *parent = this->parentWidget();
    parent->show();
}

void JoinWindow::on_joinGameBtn_clicked()
{
    this -> hide();
    gameWindow = new GameWindow(this);
    //gameWindow->showFullScreen();
    gameWindow -> show();
}
