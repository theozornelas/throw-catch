#include "../header/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stadiums = db.getStadiums();

    for(int i = 0; i < stadiums.length(); i++) {
        qDebug() << stadiums[i].getStadiumName();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_homePageButton_clicked()
{
    ui->display->setCurrentIndex(HOME);
}

void MainWindow::on_viewStadiumsPageButton_clicked()
{
    ui->display->setCurrentIndex(VIEW_STADIUMS);
}
