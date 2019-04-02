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
    ui->boardWidget->resize(ui->label->width()*15, ui->label->height()*15);
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
    if(moving_label != nullptr){
        setLabelOnBoard();
    }
    moving_label = nullptr;

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

            label = new LabelWrapper();
            label->makeLabel();
            label->setCoords(i, j);

            label->qLabel->setText(QString::number(label->get_i()) + " " + QString::number(label->get_j()));

            ui->boardGrid->setParent(ui->boardWidget);
            ui->boardGrid->addWidget(label->qLabel, i,j);

            // Enables getting mouse positions.
            ui->gridLayoutWidget->setMouseTracking(true);
            ui->boardWidget->setMouseTracking(true);

            // Adds labels to a list.
            labelList->pushTail(label);
        }
    }
}

bool GameWindow::collision(QLabel *lb1, QLabel *lb2)
{
    bool result = false;
    if (lb1->x() > lb2->x() and lb1->x() < lb2->x() + lb2->width()
            and lb1->y() > lb2->y()
            and lb1->y() < lb2->y() + lb2->height()){

        qInfo() << "Collision";
        result = true;
    }
    return result;
}

void GameWindow::setLabelOnBoard()
{

    LabelWrapper * label2 = labelList->getNode(0)->getValue();
    if(collision(moving_label, label2)){
        qInfo() << labelList->getNode(0)->getValue();
        moving_label->setParent(labelList->getNode(0)->getValue());
        ui->boardGrid->addWidget(moving_label, label2->get_i(), label2->get_j());
        moving_label->setGeometry(label2->x(), label2->y(), moving_label->width(), moving_label->height());
    }
}




