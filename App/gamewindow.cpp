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
    ui->boardWidget->resize(labelwidth*15, labelheight*15);
    ui->boardGrid->setParent(ui->boardWidget);
    makeLabelBoard(15);
    QWidget::setMouseTracking(true);

    tileWrapper = new TileWrapper;
    tileWrapper->setParent(this);
    tileWrapper->makeTile();
    tileWrapper->setImage(":/Img/configIcon.png");
    tileWrapper->setGeometry(20, 20, labelwidth, labelheight);

}
GameWindow::~GameWindow()
{
    delete ui;

}

void GameWindow::makeLabelBoard(int size)
{
    for(int i = 0; i < size; i++){

        for(int j = 0; j < size; j++){

            label = new LabelWrapper();
            label->makeLabel();
            label->setCoords(i, j);

            label->qLabel->setText(QString::number(label->get_i()) + " " + QString::number(label->get_j()));

            ui->boardGrid->addWidget(label->qLabel, i,j);
            label->setGeometry(ui->boardWidget->x() + i*labelwidth, ui->boardWidget->y() + j*labelheight, labelwidth, labelheight);

            ui->gridLayoutWidget->setMouseTracking(true);
            ui->boardWidget->setMouseTracking(true);

            labelList->pushTail(label);
        }
    }
}

void GameWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    QWidget::mouseDoubleClickEvent(event);
        int mouseX = event->x();
        int mouseY = event->y();
        int labelX = tileWrapper->x();
        int labelY = tileWrapper->y();
        int labelWidth = tileWrapper->width();
        int labelHeight = tileWrapper->height();

        // Verifies that the mouse double click is within the label's limits.
    if (mouseX > labelX and mouseX < labelX + labelWidth and
            mouseY > labelY and mouseY < labelY + labelHeight){

        moving_label = tileWrapper;
    }
}

void GameWindow::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    movingX = event->x();
    movingY = event->y();
    if (moving_label != nullptr){
        tileWrapper->move(movingX - labelwidth/2, movingY - labelheight/2);
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
    tileWrapper->repaint(x - labelwidth/2, y - labelheight/2, labelwidth, labelheight);
}



bool GameWindow::collision(QWidget *lb1, int x, int y)
{
    bool xlimits = false;
    bool ylimits = false;
    if ((lb1->x() >= x and lb1->x() < x + labelwidth) or (lb1->x() <= x and  lb1->x() > x - labelwidth)){

        xlimits = true;
    }

    if ((lb1->y() >= y and lb1->y() < y + labelheight) or (lb1->y() <= y and  lb1->y() > y - labelheight)){

        ylimits = true;
    }

    qInfo() << "Collision: " + QString::number(xlimits == true && ylimits == true);
    return xlimits == true && ylimits == true;
}


void GameWindow::setLabelOnBoard()
{

    for(int i = 0; i < labelList->getSize(); i++){

        LabelWrapper * labelwrapper = labelList->getNode(i)->getValue();

        if(collision(labelwrapper, movingX, movingY)){

            tileWrapper->setGeometry(labelwrapper->x(), labelwrapper->y(), labelwidth, labelheight);
            tileWrapper->setCoords(labelwrapper->get_i(), labelwrapper->get_j());

            qInfo() << "movingX " << movingX << " movingY " << movingY;

            break;

        }

    }

}




