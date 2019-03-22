#include "hostwindow.h"
#include "ui_hostwindow.h"
#include "mainwindow.h"

HostWindow::HostWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HostWindow)
{
    ui->setupUi(this);
    this->resize(960, 730);

    // Sets the menu image on a label.
    QPixmap pix("/home/jessica/Scrabble/App/background.png");
    ui->hostBg->setPixmap(pix);
}

HostWindow::~HostWindow()
{
    delete ui;

}
