#ifndef ENDWINDOW_H
#define ENDWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class EndWindow;
}

class EndWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EndWindow(QWidget *parent = nullptr);
    ~EndWindow();

private slots:
    void on_BackMenuBtn_clicked();

private:
    Ui::EndWindow *ui;
};

#endif // ENDWINDOW_H
