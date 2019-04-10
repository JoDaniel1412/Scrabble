#include "propertieswindow.h"
#include "ui_propertieswindow.h"

PropertiesWindow * PropertiesWindow::instance = nullptr;

PropertiesWindow::PropertiesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PropertiesWindow)
{
    ui->setupUi(this);
}

PropertiesWindow::~PropertiesWindow()
{
    delete ui;
}

PropertiesWindow *PropertiesWindow::getInstance()
{
    if (instance == nullptr) instance = new PropertiesWindow();
    return instance;
}

QString PropertiesWindow::getIP()
{
    return ip;
}

int PropertiesWindow::getPort()
{
    return port;
}

void PropertiesWindow::on_saveChangesBtn_clicked()
{
    this->setIP(ui->ipEntry->text());
    this->setPort(ui->portEntry->text().toInt());

    qInfo() << "IP1: " << ip << " Port1: " << port;
}

void PropertiesWindow::setIP(QString ip)
{
    this->ip = ip;
}

void PropertiesWindow::setPort(int port)
{
    this->port = port;
}
