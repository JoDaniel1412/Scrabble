#ifndef PROPERTIESWINDOW_H
#define PROPERTIESWINDOW_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class PropertiesWindow;
}

class PropertiesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PropertiesWindow(QWidget *parent = nullptr);
    ~PropertiesWindow();

public:

    static PropertiesWindow *getInstance();

    QString getIP();

    int getPort();

private slots:
    void on_saveChangesBtn_clicked();

private:
    Ui::PropertiesWindow *ui;

    static PropertiesWindow *instance;

    QString ip = "127.0.0.1";

    int port = 12345;

    int number = 84682074;

    void setIP(QString ip);

    void setPort(int port);

    void setNumber(int number);
};

#endif // PROPERTIESWINDOW_H
