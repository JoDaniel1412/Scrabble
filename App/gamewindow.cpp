#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QPushButton>
#include <qlabel.h>
#include <QDebug>
#include <QMouseEvent>
#include "list/List.h"
#include <QPainter>


GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    int boardX = this->x() + ui->boardWidget->width()/2;
    int boardY = this->y() + this->height()/2 - ui->boardWidget->height()/2 - 50;

    ui->boardWidget->setGeometry(boardX, boardY, labelwidth*15, labelheight*15);
    ui->boardGrid->setParent(ui->boardWidget);

    makeLabelBoard(15, 15);
    createGraphicDock();

    QWidget::setMouseTracking(true);


    loadPlayers();

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

            QString color = "#b2967d";
            if (board->getTile(i, j)->getBonus() == 2) color = "#92d5e6";
            if (board->getTile(i, j)->getBonus() == 4) color = "#c78283";

            LabelWrapper * label = new LabelWrapper();
            label->makeLabel();
            label->setCoords(i, j);
            label->setAlignment(Qt::AlignCenter);
            label->setStyleSheet("QLabel { background-color : " + color + "; }");


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
        tileWrapper->setLetter(dock->getLetters()->getNode(i)->getValue());
        tileWrapper->setImage(":/Img/background2.jpg");
        tileWrapper->setInitialX(30);
        tileWrapper->setInitialY(65*(1+i));
        tileWrapper->setGeometry(tileWrapper->getInitialX(), tileWrapper->getInitialY(), labelwidth, labelheight);
        tileWrapper->setMouseTracking(true);

        tileList->pushTail(tileWrapper);

    }
}

void GameWindow::deleteFromDock(TileWrapper * tilewrapper)
{
    for(int i = 0; i < dock->getLetters()->getSize(); i++){
        if (tilewrapper == tileList->getNode(i)->getValue()){
            dock->remove(i);
            delete moving_label;
            int index = tileList->index(tilewrapper);
            tileList->deleteValue(index);
            break;
        }
    }
}

void GameWindow::loadPlayers()
{
    MockGame::makePlayers();
    unordered_map<string, int> * map = game->getPlayers();

    ui->tableWidget->setRowCount(map->size());
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->verticalHeader()->setVisible(false);
    QStringList header;
    header<<"name " << "points";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setStyleSheet("::section { background-color: #b2967d; }" );
    int i = 0;

    for (pair<string, int> entry : *map) {
        QString name = QString::fromStdString(entry.first).toLower();
        QString points = QString::number(entry.second);

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(points));

        i++;
    }

    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}


void GameWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    QWidget::mouseDoubleClickEvent(event);
    int mouseX = event->x();
    int mouseY = event->y();

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

    gridLabelX = event->x() - ui->boardWidget->x();
    gridLabelY = event->y() - ui->boardWidget->y();

    if (moving_label != nullptr){
        moving_label->move(movingX - 25, movingY - 25);

    }
}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);

    if (moving_label != nullptr){
        if (collision(ui->boardWidget, movingX, movingY)){
            setLabelOnBoard();

        } else{
            moving_label->move(moving_label->getInitialX(), moving_label->getInitialY());
            moving_label = nullptr;
        }
    }
}


bool GameWindow::collision(QWidget *lb1, int x, int y)
{
    bool limits = false;
    if (((x > lb1->x() and x < lb1->x() + lb1->width())) and (y > lb1->y() and y < lb1->y() + lb1->height()))
    {
        limits = true;
    }
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
            moving_label->setCoords(labelwrapper->get_i(), labelwrapper->get_j());

            if(board->putLetter(moving_label->get_i(), moving_label->get_j(), moving_label->getLetter())){
                labelwrapper->setImage(":/Img/background2.jpg", moving_label->getLetter());
                deleteFromDock(moving_label);
                moving_label = nullptr;

            } else moving_label->move(moving_label->getInitialX(), moving_label->getInitialY());
        }

    } catch (std::exception & e) {
    qInfo() << e.what();
    }

}

