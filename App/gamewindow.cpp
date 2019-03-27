#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QPushButton>
#include <qlabel.h>
#include <QDebug>
#include <QMouseEvent>
#include "list/List.h"
#include "labelwrapper.h"


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
        int mouseX = event->x();
        int mouseY = event->y();
        int labelX = ui->label->x();
        int labelY = ui->label->y();
        int labelWidth = ui->label->width();
        int labelHeight = ui->label->height();

        // Verifies that the mouse double click is within the label's limits.
    if (mouseX > labelX and mouseX < labelX + labelWidth and
            mouseY > labelY and mouseY < labelY + labelHeight){
        moving_label = ui->label;
    }
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
    QString x = QString::number(event->x());
    QString y = QString::number(event->y());

    qInfo() << "X: " + x + " " + "Y: " + y;

}

void GameWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    int x = event->x();
    int y = event->y();
    ui->label->repaint(x - 25, y - 25, 20, 20);
}

// Fills the grid(size x size) with labels.
void GameWindow::makeLabelBoard(int size)
{
    for(int i = 0; i < size; i++){

        for(int j = 0; j < size; j++){

            LabelWrapper *label = new LabelWrapper();
            label->makeLabel();
            label->setCoords(i, j);

            label->qLabel->setText(QString::number(label->get_i()) + " " + QString::number(label->get_j()));

            ui->boardGrid->setParent(ui->boardWidget);
            ui->boardGrid->addWidget(label->qLabel, i,j);

            // Enables getting mouse positions.
            ui->gridLayoutWidget->setMouseTracking(true);
            ui->boardWidget->setMouseTracking(true);
        }
    }
}

void GameWindow::collision(LabelWrapper lb1, QLabel lb2)
{

}




