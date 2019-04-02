#include "joinwindow.h"
#include "ui_joinwindow.h"
#include "mainwindow.h"
#include <QJsonObject>

JoinWindow::JoinWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JoinWindow)
{
    ui->setupUi(this);
    this->resize(1024, 768);
}

JoinWindow::~JoinWindow()
{
    delete ui;
}

void JoinWindow::on_returnBtn_clicked()
{
    this->hide();

    // Show the MainWindow (i.e. the parent window)
    QWidget *parent = this->parentWidget();
    parent->show();
}

void JoinWindow::on_joinGameBtn_clicked()
{
    Client *client = new Client();
    client->connectToHost();

    QString code = ui->codeEntry->text();
    QByteArray codeData = code.toUtf8();

    QString name = ui->nameEntry->text();
    QByteArray nameCode = name.toUtf8();

    client->writeData(codeData);
    client->writeData(nameCode);
}
