#ifndef JOINWINDOW_H
#define JOINWINDOW_H

#include <QDialog>
#include "gamewindow.h"

namespace Ui {
class JoinWindow;
}

class JoinWindow : public QDialog
{
    Q_OBJECT

            GameWindow * gameWindow;

public:
    explicit JoinWindow(QWidget *parent = nullptr);
    ~JoinWindow();

private slots:
    void on_returnBtn_clicked();

    void on_joinGameBtn_clicked();

private:
    Ui::JoinWindow *ui;
};

#endif // JOINWINDOW_H
