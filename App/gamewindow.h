#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QDialog>
#include <QMouseEvent>
#include <QLabel>
#include "labelwrapper.h"
#include "list/List.h"
#include "tilewrapper.h"
#include "game/dock.h"
#include "game/board.h"

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
    int gridLabelX, gridLabelY;

    TileWrapper * moving_label = nullptr;
    List<TileWrapper*> * tileList = new List<TileWrapper*>();
    LabelWrapper * label = nullptr;
    Dock * dock = Dock::getInstance();
    Board * board = Board::getInstance();


    void hover();


    int labelwidth = 55;
    int labelheight =55;

protected:

    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:

    Ui::GameWindow *ui;
    List<List<LabelWrapper*>*> * labelmatrix = new List<List<LabelWrapper*>*>();
    void makeLabelBoard(int rows, int columns);
    void createGraphicDock();
    bool collision(QWidget * lb1, int x, int y);
    bool collision(int x, int y, int x2, int y2);
    void setLabelOnBoard();
    void deleteFromDock(TileWrapper * tilewrapper);

};

#endif // GAMEWINDOW_H
