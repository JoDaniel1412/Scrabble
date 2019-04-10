#include "propertieswindow.h"
#include "ui_propertieswindow.h"

PropertiesWindow * PropertiesWindow::instance = nullptr;
QString PropertiesWindow::ip = "127.0.0.1";
int PropertiesWindow::port = 12345;
int PropertiesWindow::number = 84682074;

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
    QString ip = ui->ipEntry->text();
    int port = ui->portEntry->text().toInt();
    int number = ui->numberEntry->text().toInt();

    if (ip != "") this->setIP(ip);
    if (port != 0) this->setPort(port);
    if (number != 0) this->setNumber(number);

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
void PropertiesWindow::setNumber(int number)
{
    this->number = number;
}
