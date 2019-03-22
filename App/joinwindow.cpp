#include "joinwindow.h"
#include "ui_joinwindow.h"
#include "mainwindow.h"

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
