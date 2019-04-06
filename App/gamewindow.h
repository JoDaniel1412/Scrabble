#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QDialog>
#include <QMouseEvent>
#include <QLabel>
#include "labelwrapper.h"
#include "list/List.h"
#include "tilewrapper.h"
#include "game/dock.h"
#include "mockdock.h"

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


    TileWrapper * moving_label = nullptr;

    List<TileWrapper*> * tileList = new List<TileWrapper*>();

    LabelWrapper * label = nullptr;

    QLabel * qlabel1 = nullptr;

    List<LabelWrapper*> * labelList = new List<LabelWrapper*>();

    Dock * dock = Dock::getInstance();

    void setLabelOnBoard();

    void createGraphicDock();

    void hover();


    int labelwidth = 65;
    int labelheight = 65;

protected:

    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:

    Ui::GameWindow *ui;
    List<List<LabelWrapper*>*> * labelmatrix = new List<List<LabelWrapper*>*>();
    void makeLabelBoard(int rows, int columns);
    bool collision(QWidget * lb1, int x, int y);
    bool collision(int x, int y, int x2, int y2);

};

#endif // GAMEWINDOW_H
