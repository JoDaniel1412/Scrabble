#include "hostwindow.h"
#include "ui_hostwindow.h"
#include "mainwindow.h"

HostWindow::HostWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HostWindow)
{
    ui->setupUi(this);
    this->resize(1024, 768);

}

HostWindow::~HostWindow()
{
    delete ui;

}
