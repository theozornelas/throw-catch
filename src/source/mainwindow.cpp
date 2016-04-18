#include "../header/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //stadiums = db.getStadiums();

}

MainWindow::~MainWindow()
{
    delete ui;
}
