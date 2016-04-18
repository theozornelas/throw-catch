#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "dbmanager.h"
#include "stadium.h"
#include "skiplist.h"

enum display {
    HOME,
    VIEW_STADIUMS,
};

enum options {
    CUSTOMER,
    ADMIN
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_homePageButton_clicked();
    void on_viewStadiumsPageButton_clicked();

private:
    Ui::MainWindow *ui;
    DBManager db;

    QVector<Stadium> stadiums;
};

#endif // MAINWINDOW_H
