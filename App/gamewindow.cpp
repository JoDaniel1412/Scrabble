#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QPushButton>
#include <qlabel.h>


GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    fillGrid(15);
}
GameWindow::~GameWindow()
{
    delete ui;
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
