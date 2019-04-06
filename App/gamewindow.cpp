#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QPushButton>
#include <qlabel.h>
#include <QDebug>
#include <QMouseEvent>
#include "list/List.h"
#include "labelwrapper.h"
#include "mockdock.h"


GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->boardWidget->resize(labelwidth*15, labelheight*15);
    ui->boardGrid->setParent(ui->boardWidget);
    makeLabelBoard(15, 15);
    //createGraphicDock();
    QWidget::setMouseTracking(true);

    /*
    LabelWrapper * labelx = new LabelWrapper();
    labelx->setParent(this);
    labelx->setPixmap(QPixmap(":/Img/configIcon.png"));
    labelx->setGeometry(0,0, 20, 20);
    */


}
GameWindow::~GameWindow()
{
    delete ui;

}

void GameWindow::makeLabelBoard(int rows, int columns)
{

    for(int i = 0; i < rows; i++){

        List<LabelWrapper*> *row = new List<LabelWrapper*>();

        labelmatrix->pushTail(row);

        for(int j = 0; j < columns; j++){

            LabelWrapper * label = new LabelWrapper();
            label->makeLabel();
            label->setCoords(i, j);

            label->setText(QString::number(label->get_i()) + " " + QString::number(label->get_j()));

            ui->boardGrid->addWidget(label, i,j);
            label->setGeometry(ui->boardWidget->x() + i*labelwidth, ui->boardWidget->y() + j*labelheight, labelwidth, labelheight);

            label->setMouseTracking(true);
            ui->gridLayoutWidget->setMouseTracking(true);
            ui->boardWidget->setMouseTracking(true);
            labelList->pushTail(label);

            row->pushTail(label);
        }
    }
}


void GameWindow::createGraphicDock()
{
    MockDock::makeLetters();

    for (int i = 0; i < dock->getLetters()->getSize(); i++){

        TileWrapper * tileWrapper = new TileWrapper;
        tileWrapper->setParent(this);
        tileWrapper->makeTile();
        QString letter = QChar(dock->getLetters()->value(i));
        QString url = letter + ".png";
        tileWrapper->setImage(url);
        tileWrapper->setGeometry(20, 20*i, labelwidth, labelheight);
        tileWrapper->setMouseTracking(true);

        tileList->pushTail(tileWrapper);

    }
}



void GameWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    QWidget::mouseDoubleClickEvent(event);
        int mouseX = event->x();
        int mouseY = event->y();

        // Verifies that the mouse double click is within the label's limits.

        for(int i = 0; i < tileList->getSize(); i++){

            TileWrapper * tile  = tileList->getNode(i)->getValue();

            if (collision(tile, mouseX, mouseY)){
                moving_label = tile;
        }

    }
}

void GameWindow::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    movingX = event->x();
    movingY = event->y();


    if (moving_label != nullptr){
        moving_label->move(movingX - 25, movingY - 25);

    }
}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    if(moving_label != nullptr and collision(ui->boardWidget, movingX, movingY)){

        setLabelOnBoard();

    } else{

        moving_label->setGeometry(movingX - labelwidth/2, movingY - labelheight/2, labelwidth, labelheight);
    }

    moving_label = nullptr;

}

void GameWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    moving_label->setGeometry(movingX - labelwidth/2, movingY - labelheight/2, labelwidth, labelheight);
}



bool GameWindow::collision(QWidget *lb1, int x, int y)
{
    bool limits = false;
    if (((x > lb1->x() and x < lb1->x() + labelwidth)) and (y > lb1->y() and y < lb1->y() + labelheight))
    {
        limits = true;
    }

    //qInfo() << "Collision: " + QString::number(limits == true);
    return limits == true;
}

bool GameWindow::collision(int x, int y, int x2, int y2)
{
    bool limits = false;
    if (((x > x2 and x < x2 + labelwidth)) and (y > y2 and y < y2 + labelheight))
    {
        limits = true;
    }

    //qInfo() << "Collision: " + QString::number(limits == true);
    return limits == true;
}


void GameWindow::setLabelOnBoard()
{

    for(int i = 0; i < labelList->getSize(); i++){

        LabelWrapper * labelwrapper = labelList->getNode(i)->getValue();

        if(collision(labelwrapper->x(), labelwrapper->y(), movingX, movingY)){

            moving_label->setGeometry(labelwrapper->x(), labelwrapper->y(), labelwidth, labelheight);
            moving_label->setCoords(labelwrapper->get_i(), labelwrapper->get_j());

        }

    }

}




void GameWindow::hover()
{
    for(int i = 0; i < labelList->getSize(); i++){

        LabelWrapper * labelwrapper = labelList->getNode(i)->getValue();
        qInfo() << "I: " << labelwrapper->x() << " J" << labelwrapper->y();
        qInfo() << "x: " << movingX << " y" << movingY;

        if(collision(labelwrapper->x(), labelwrapper->y(), movingX, movingY)){
            //qInfo() << "I: " << labelwrapper->get_i() << " J" << labelwrapper->get_j();

            labelwrapper->setStyleSheet("QLabel { background-color : red; }");


        } else{

            labelwrapper->setStyleSheet("QLabel { background-color : white; }");
        }

    }

}




