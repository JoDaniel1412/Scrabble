#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1900, 965);

    // Sets the menu image on a label.
    QPixmap pix("/home/jessica/Scrabble/App/Scrabble.png");
    ui->scrabbleImg->setPixmap(pix);

    // Positions the buttons
    ui->btnsWidget->setGeometry(ui->scrabbleImg->width()/2 - (ui->btnsWidget->width()/2 + 30), 400, 500, 400);

    ui->line->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_joinBtn_pressed()
{
    ui->line->setVisible(true);
}

