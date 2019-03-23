#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hostwindow.h"
#include "joinwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

             private:
                HostWindow * hostWindow;
                JoinWindow * joinWindow;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_hostBtn_clicked();

    void on_joinBtn_clicked();

    void on_configBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
