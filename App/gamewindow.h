#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QDialog>
namespace Ui {
class GameWindow;
}
class GameWindow : public QDialog
{
    Q_OBJECT

public:

    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private:

    Ui::GameWindow *ui;
    void fillGrid(int size);
};

#endif // GAMEWINDOW_H
