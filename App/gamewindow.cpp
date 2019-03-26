#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QPushButton>
#include <qlabel.h>
#include <QDebug>
#include <QMouseEvent>
#include "list/List.h"


GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    makeLabelBoard(15);
    QWidget::setMouseTracking(true);

}
GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    QWidget::mouseDoubleClickEvent(event);
    moving_label = ui->label;
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
    moving_label = nullptr;

}

void GameWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    int x = event->x();
    int y = event->y();
    ui->label->repaint(x - 25, x - 25, 20, 20);
}

// Fills the grid(size x size) with labels.
void GameWindow::makeLabelBoard(int size)
{
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            ui->label->setParent(ui->frame);
        }
    }
}

