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

// Players label shows slider value.
void HostWindow::on_horizontalSlider_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->playersLb->setText("Players " + s);
    QFont font = ui->playersLb->font();
    font.setPointSize(28);
    ui->playersLb->setFont(font);
    ui->playersLb->setAlignment(Qt::AlignCenter);
}
