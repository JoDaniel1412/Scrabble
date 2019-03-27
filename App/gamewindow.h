#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QDialog>
#include <QMouseEvent>
#include <QLabel>
#include "labelwrapper.h"
#include "list/List.h"

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

    LabelWrapper *label = nullptr;

    List<LabelWrapper*> * labelList = new List<LabelWrapper*>();

protected:

    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:

    Ui::GameWindow *ui;
    void makeLabelBoard(int size);
    bool collision(QLabel * lb1, QLabel * lb2);
};

#endif // GAMEWINDOW_H
