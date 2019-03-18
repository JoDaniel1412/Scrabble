#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1900, 965);
    ui->menuWidget->setStyleSheet("background-color:black;");
}

MainWindow::~MainWindow()
{
    delete ui;
}
