#include "joinwindow.h"
#include "ui_joinwindow.h"
#include "mainwindow.h"
#include <QJsonObject>
#include "stringtojson.h"
using namespace std;
#include <iostream>

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
    QString name = ui->nameEntry->text();


    QByteArray data = StringToJson::joinWindowObject(code, name);


    client->writeData(data);
    QByteArray response = client->getSocket()->readAll();
    cout <<response.toStdString()<<endl;
}
