#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QDialog>
#include <QMouseEvent>
#include <QLabel>
#include "wrappers/labelwrapper.h"
#include "list/List.h"
#include "wrappers/tilewrapper.h"
#include "game/dock.h"
#include "game/board.h"
#include "mocks/mockdock.h"
#include "game/game.h"
#include "mocks/mockgame.h"
#include "QTableWidget"
#include <QList>

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
    Game * game = Game::getInstance();

    void loadPlayers(QTableWidget * table);
    void updateDock();
    void updateBoard();
    void updateTable();

    int labelwidth = 55;
    int labelheight =55;

protected:

    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void on_closeButton_clicked();

    void askUpdate();

    void on_smsButton_clicked();

public slots:
    void updateGame();

private:

    Ui::GameWindow *ui;
    List<LabelWrapper*> * labelvector = new List<LabelWrapper*>();
    void makeLabelBoard(int rows, int columns);
    void createGraphicDock();
    bool collision(QWidget * lb1, int x, int y);
    bool collision(int x, int y, int x2, int y2);
    void setLabelOnBoard();
    void deleteFromDock(TileWrapper * tilewrapper);

};

#endif // GAMEWINDOW_H
