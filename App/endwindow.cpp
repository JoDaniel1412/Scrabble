#include "endwindow.h"
#include "ui_endwindow.h"

EndWindow::EndWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndWindow)
{
    ui->setupUi(this);
    this->resize(1024, 768);

    GameWindow gamewindow;
    gamewindow.loadPlayers(this->ui->tableWidget);

    int windowX = this->x() + this->width()/2 - ui->tableWidget->width()/2;
    int windowY = this->y() + ui->tableWidget->height();

    ui->tableWidget->move(windowX, windowY);

}

EndWindow::~EndWindow()
{
    delete ui;
}

void EndWindow::on_BackMenuBtn_clicked()
{
    this->hide();

    // Show the MainWindow (i.e. the parent window)
    MainWindow *parent = new MainWindow();
    parent->show();
}
