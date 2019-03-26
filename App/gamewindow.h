#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QDialog>
#include <QMouseEvent>
#include <QLabel>

namespace Ui {
class GameWindow;
}
class GameWindow : public QDialog
{
    Q_OBJECT

public:

    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

    int movingX, movingY;

    QLabel * moving_label = nullptr;

protected:

    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void on_pushButton_pressed();

    void on_pushButton_released();

private:

    Ui::GameWindow *ui;
    void fillGrid(int size);
};

#endif // GAMEWINDOW_H
