#include "../header/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stadiums = db.getStadiums();

    ui->viewStadiumsList->setRowCount(stadiums.length() + 1);

    for(int row = 0; row < stadiums.length(); row++) {
        Stadium s = stadiums[row];

        ui->viewStadiumsList->setRowHeight(row, 45);
        ui->viewStadiumsList->setItem(row, 0, new QTableWidgetItem(s.getStadiumName()));
        ui->viewStadiumsList->setItem(row, 1, new QTableWidgetItem(s.getTeamName()));
        ui->viewStadiumsList->setItem(row, 2, new QTableWidgetItem(QString::number(s.getSeatingCapacity())));
        ui->viewStadiumsList->setItem(row, 3, new QTableWidgetItem(s.getAddress()));
        ui->viewStadiumsList->setItem(row, 4, new QTableWidgetItem(s.getSurface()));
        ui->viewStadiumsList->setItem(row, 5, new QTableWidgetItem(s.getDateOpened()));
        ui->viewStadiumsList->setItem(row, 6, new QTableWidgetItem(s.getTypology()));
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
