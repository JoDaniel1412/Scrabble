#ifndef HOSTWINDOW_H
#define HOSTWINDOW_H

#include <QDialog>
#include <random>
#include "stringtojson.h"
#include <QMessageBox>

namespace Ui {
class HostWindow;
}

class HostWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HostWindow(QWidget *parent = nullptr);
    ~HostWindow();

private slots:
    void on_horizontalSlider_sliderMoved(int position);

    void on_returnBtn_clicked();

    void on_hostGameBtn_clicked();

private:
    Ui::HostWindow *ui;
};

#endif // HOSTWINDOW_H
