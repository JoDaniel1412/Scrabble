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

    static QString ip;

    static int port;

    static int number;

    void setIP(QString ip);

    void setPort(int port);

    void setNumber(int number);
};

#endif // PROPERTIESWINDOW_H
