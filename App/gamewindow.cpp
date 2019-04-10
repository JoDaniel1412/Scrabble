#include "endwindow.h"
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

    int boardX = this->x() + ui->boardTable->width()/2;
    int boardY = this->y() + this->height()/2 - ui->boardTable->height()/2 - 100;

    ui->boardTable->setGeometry(boardX, boardY, labelwidth*15 + 32, labelheight*15 + 2);

    makeLabelBoard(15, 15);
    createGraphicDock();

    QWidget::setMouseTracking(true);
    ui->boardTable->setMouseTracking(true);

    loadPlayers(this->ui->tableWidget);

}

GameWindow::~GameWindow()
{
    delete ui;

}

void GameWindow::makeLabelBoard(int rows, int columns)
{
    ui->boardTable->setRowCount(rows);
    ui->boardTable->setColumnCount(columns);
    ui->boardTable->verticalHeader()->setVisible(false);
    ui->boardTable->horizontalHeader()->setVisible(false);

    for(int i = 0; i < rows; i++){

        for(int j = 0; j < columns; j++){

            QString color = "#b2967d";
            if (board->getTile(i, j)->getBonus() == 2) color = "#92d5e6";
            if (board->getTile(i, j)->getBonus() == 4) color = "#c78283";

            LabelWrapper * labelWrapper = new LabelWrapper();
            labelWrapper->makeLabel();
            labelWrapper->setCoords(i, j);
            labelWrapper->setAlignment(Qt::AlignCenter);
            labelWrapper->setStyleSheet("QLabel { background-color : " + color + "; }");

            QChar letter = board->getLetter(i, j);
            if(letter != '0') labelWrapper->setImage(":/Img/background2.jpg", letter);

            ui->boardTable->setColumnWidth(j, labelwidth);
            ui->boardTable->setRowHeight(i, labelheight);
            ui->boardTable->setCellWidget(i, j, labelWrapper);
            ui->boardTable->resize(labelwidth * 15 + 34, labelheight * 15 + 4);

            labelWrapper->show();
            labelWrapper->update();


            labelvector->pushTail(labelWrapper);
        }
    }
}


void GameWindow::createGraphicDock()
{
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
        tileWrapper->show();

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

void GameWindow::loadPlayers(QTableWidget *table)
{
    unordered_map<string, int> * map = game->getPlayers();

    table->setRowCount(map->size());
    table->setColumnCount(2);
    table->verticalHeader()->setVisible(false);
    table->resize(370, 310);
    QStringList header;
    header<<"name " << "points";
    table->setHorizontalHeaderLabels(header);
    table->horizontalHeader()->setStyleSheet("::section { background-color: #b2967d; }" );
    int i = 0;

    for (pair<string, int> entry : *map) {
        QString name = QString::fromStdString(entry.first).toLower();
        QString points = QString::number(entry.second);

        table->setItem(i, 0, new QTableWidgetItem(name));
        table->setItem(i, 1, new QTableWidgetItem(points));

        i++;
    }

    table->resizeRowsToContents();
    table->setColumnWidth(0, 180);
    table->setColumnWidth(1, 180);
}

void GameWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    QWidget::mouseDoubleClickEvent(event);

}

void GameWindow::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    movingX = event->x();
    movingY = event->y();

    gridLabelX = event->x() - ui->boardTable->x();
    gridLabelY = event->y() - ui->boardTable->y();

    if (moving_label != nullptr){
        moving_label->move(movingX - 25, movingY - 25);

    }
}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);

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

void GameWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);

    if (moving_label != nullptr){
        if (collision(ui->boardTable, movingX, movingY)){
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
    if (((x > lb1->x() and x < lb1->x() + lb1->width()))
            and (y > lb1->y() and y < lb1->y() + lb1->height()))
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
        QWidget * widgetChild = ui->boardTable->childAt(gridLabelX, gridLabelY);

        LabelWrapper *labelwrapper = (LabelWrapper*) widgetChild;
        moving_label->setCoords(labelwrapper->get_i(), labelwrapper->get_j());

        if(board->putLetter(moving_label->get_i(), moving_label->get_j(), moving_label->getLetter())){
            labelwrapper->setImage(":/Img/background2.jpg", moving_label->getLetter());
            deleteFromDock(moving_label);
            moving_label = nullptr;

        } else moving_label->move(moving_label->getInitialX(), moving_label->getInitialY());


    } catch (std::exception & e) {
    qInfo() << e.what();
    }

}

void GameWindow::on_closeButton_clicked()
{
    this -> hide();
    EndWindow *endwindow = new EndWindow(this);
    endwindow -> show();

    updateGame();
}

void GameWindow::updateGame()
{
    updateDock();
    updateTable();
    updateBoard();
}

void GameWindow::updateDock()
{
    for(int i = 0; i < tileList->getSize(); i++){
        tileList->getNode(i)->getValue()->deleteTile();
    }

    delete tileList;
    tileList = new List<TileWrapper*>();
    createGraphicDock();
}

void GameWindow::updateBoard()
{
    makeLabelBoard(15, 15);
}

void GameWindow::updateTable()
{
    loadPlayers(ui->tableWidget);
}

void GameWindow::on_playBtn_clicked()
{
    board->getHorizontalWord(1,3);
}
