#ifndef HOSTWINDOW_H
#define HOSTWINDOW_H

#include <QDialog>

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

private:
    Ui::HostWindow *ui;
};

#endif // HOSTWINDOW_H
