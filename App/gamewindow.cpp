#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QPushButton>
#include <qlabel.h>
#include <QDebug>
#include <QMouseEvent>


GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    fillGrid(15);
    QWidget::setMouseTracking(true);

}
GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    QWidget::mouseDoubleClickEvent(event);
    QString x = QString::number(event->x());
    QString y = QString::number(event->y());
    qInfo() << "Double Click: " + x + " " + y;
}

void GameWindow::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    movingX = event->x();
    movingY = event->y();
    if (moving_label != nullptr){
        ui->label->move(movingX - 25, movingY - 25);
    }
}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    moving_label = ui->label;
    mouseMoveEvent(event);
    ui->label->move(movingX - 25, movingY - 25);

}

void GameWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    ui->label->repaint(movingX - 25, movingY - 25, 20, 20);
}

// Fills the grid(size x size) with labels.
void GameWindow::fillGrid(int size)
{
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            ui->boardGrid->addWidget(new QLabel("B"), i,j);
        }
    }
}

