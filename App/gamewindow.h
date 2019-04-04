#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QDialog>
#include <QMouseEvent>
#include <QLabel>
#include "labelwrapper.h"
#include "list/List.h"
#include "tilewrapper.h"

namespace Ui {
class GameWindow;
}
class GameWindow : public QDialog
{
    Q_OBJECT

public:

    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow() override;

    int movingX, movingY;

    TileWrapper * tileWrapper = nullptr;

    TileWrapper * moving_label = nullptr;

    LabelWrapper * label = nullptr;

    QLabel * qlabel1 = nullptr;

    List<LabelWrapper*> * labelList = new List<LabelWrapper*>();

    void setLabelOnBoard();


    int labelwidth = 50;
    int labelheight = 50;

protected:

    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:

    Ui::GameWindow *ui;
    void makeLabelBoard(int size);
    bool collision(QWidget * lb1, QWidget * lb2);
};

#endif // GAMEWINDOW_H
