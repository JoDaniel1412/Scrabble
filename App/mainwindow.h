#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hostwindow.h"
#include "joinwindow.h"
#include <QVariant>
#include <QString>
#include "propertieswindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

             private:
                HostWindow * hostWindow;
                JoinWindow * joinWindow;
                GameWindow * gameWindow;
                PropertiesWindow * propertiesWindow;

public:
    QString getIP();

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void closeEvent(QCloseEvent *e);

    QString ip;


private slots:
    void on_hostBtn_clicked();

    void on_joinBtn_clicked();

    void on_propertiesBtn_clicked();

    void on_exitBtn_clicked();

    void on_testBtn_clicked();

private:
    Ui::MainWindow *ui;
};


void saveSettings(const QString &key, const QVariant &valor);
QVariant loadSettings(const QString &llave);

#endif // MAINWINDOW_H
