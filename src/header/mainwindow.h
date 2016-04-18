#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "dbmanager.h"
#include "skiplist.h"
#include "stadium.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    DBManager db;

    //skiplist<int, Stadium> stadiums;
};

#endif // MAINWINDOW_H
