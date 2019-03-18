#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_hostBtn_toggled(bool checked);

    void on_joinBtn_toggled(bool checked);

    void on_joinBtn_pressed();

    void on_joinBtn_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
