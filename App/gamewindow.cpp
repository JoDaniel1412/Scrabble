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
    createGraphicDock();
    QWidget::setMouseTracking(true);



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
            label->setAlignment(Qt::AlignCenter);
            label->setStyleSheet("QLabel { background-color : white; }");

            ui->boardGrid->addWidget(label, i,j);

            label->setMouseTracking(true);
            ui->gridLayoutWidget->setMouseTracking(true);
            ui->boardWidget->setMouseTracking(true);
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
        tileWrapper->setImage(":/Img/configIcon.png");
        tileWrapper->setLetter(dock->getLetters()->getNode(i)->getValue());
        tileWrapper->setInitialX(20);
        tileWrapper->setInitialY(65*i);
        tileWrapper->setGeometry(tileWrapper->getInitialX(), tileWrapper->getInitialY(), labelwidth, labelheight);
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
                break;
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

    gridLabelX = event->x() - ui->boardWidget->x();
    gridLabelY = event->y() - ui->boardWidget->y();

    if (moving_label != nullptr){
        if (collision(ui->boardWidget, movingX, movingY)){

            setLabelOnBoard();
            qInfo() << "Label on board";

        } else{
            moving_label->setGeometry(moving_label->getInitialX(), moving_label->getInitialY(), labelwidth, labelheight);
            qInfo() << "Label not on board";
        }

    }

    moving_label = nullptr;

}

void GameWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);

}



bool GameWindow::collision(QWidget *lb1, int x, int y)
{
    bool limits = false;
    if (((x > lb1->x() and x < lb1->x() + lb1->width())) and (y > lb1->y() and y < lb1->y() + lb1->height()))
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
    qInfo() << "Collision: " + QString::number(limits == true);
    return limits == true;

}


void GameWindow::setLabelOnBoard()
{
    try {
        QWidget * widgetChild = ui->boardWidget->childAt(gridLabelX, gridLabelY);

        if(widgetChild != ui->gridLayoutWidget){

            LabelWrapper *labelwrapper = (LabelWrapper*) widgetChild;

            moving_label->move(labelwrapper->x() + ui->boardWidget->x(), labelwrapper->y() + ui->boardWidget->y());
            moving_label->setCoords(labelwrapper->get_i(), labelwrapper->get_j());

        } else {
            moving_label->move(moving_label->getInitialX(), moving_label->getInitialY());
        }

    } catch (std::exception & e) {
        qInfo() << e.what();
    }

}




void GameWindow::hover()
{
    LabelWrapper *test = (LabelWrapper*) ui->boardWidget->childAt(gridLabelX, gridLabelY);

    test->setStyleSheet("QLabel { background-color : #e1c699; }");

}




