#include "../header/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include <QTableWidgetItem>
#include <QMessageBox>
#include <QRegExp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stadiums = db.getStadiums();
    stadiumsGraph = db.createGraph(stadiums);

    keys = db.getAllStadiumsKeys();

    ui->viewStadiumsList->setRowCount(keys.length() + 1);

    for(int row = 0; row < keys.length(); row++) {
        Stadium *s = *stadiums.get(keys[row]);

        ui->viewStadiumsList->setRowHeight(row, 45);
        ui->viewStadiumsList->setItem(row, 0, new QTableWidgetItem(s->getStadiumName()));
        ui->viewStadiumsList->setItem(row, 1, new QTableWidgetItem(s->getTeamName()));
        ui->viewStadiumsList->setItem(row, 2, new QTableWidgetItem(QString::number(s->getSeatingCapacity())));
        ui->viewStadiumsList->setItem(row, 3, new QTableWidgetItem(s->getAddress()));
        ui->viewStadiumsList->setItem(row, 4, new QTableWidgetItem(s->getSurface()));
        ui->viewStadiumsList->setItem(row, 5, new QTableWidgetItem(s->getDateOpened()));
        ui->viewStadiumsList->setItem(row, 6, new QTableWidgetItem(s->getTypology()));
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isBlank(QString text) {
    return text.trimmed() == "";
}

void MainWindow::on_homePageButton_clicked()
{
    ui->display->setCurrentIndex(HOME);
}

void MainWindow::on_viewStadiumsPageButton_clicked()
{
    ui->display->setCurrentIndex(VIEW_STADIUMS);
}

void MainWindow::on_planATripButton_clicked()
{
    ui->display->setCurrentIndex(PLAN_A_TRIP);
}

void MainWindow::on_customTripButton_clicked()
{
    ui->display->setCurrentIndex(CUSTOM_TRIP);
}

void MainWindow::on_minimumSpanningTreeButton_clicked()
{
    ui->display->setCurrentIndex(MST_TRIP);


    Graph<Stadium>::EdgeList edges = stadiumsGraph->MSTPrim();

    for(Graph<Stadium>::EdgeItr i = edges.begin(); i != edges.end(); i++) {
        QTreeWidgetItem *currentItem = new QTreeWidgetItem(ui->MSTList);
        currentItem->setText(0, i->print());
        currentItem->setText(2, QString::number(i->weight()));
    }

    ui->MSTList->resizeColumnToContents(0);
    ui->MSTList->resizeColumnToContents(1);
    ui->MSTList->resizeColumnToContents(2);




}

void MainWindow::on_shortestTripToAllButton_clicked()
{
    ui->display->setCurrentIndex(SHORTEST_TO_ALL);
}

void MainWindow::on_adminLoginButton_clicked()
{
    if(!adminPrivilege) {
        ui->adminLoginErrorMessage->setVisible(false);
        ui->password->clear();
        ui->username->clear();

        ui->display->setCurrentIndex(ADMIN_LOGIN);
    }
    else {
        ui->adminLoginButton->setText("SIGN IN");
        adminPrivilege = false;
        ui->display->setCurrentIndex(HOME);
        ui->options->setCurrentIndex(CUSTOMER);
    }
}

void MainWindow::on_loginButton_clicked()
{
    ui->adminLoginErrorMessage->setVisible(false);

    bool valid = true;
    QString username = ui->username->text();
    QString password = ui->password->text();

    if(isBlank(username) || isBlank(password)) {
        valid = false;
    }
    else if(username != "admin" || password != "password") {
        valid = false;
    }

    if(valid) {
        adminPrivilege = true;
        ui->options->setCurrentIndex(ADMIN);
        ui->display->setCurrentIndex(ADMIN_HOME);
        ui->adminLoginButton->setText("SIGN OUT");
        ui->password->clear();
        ui->username->clear();
    }
    else {
        ui->adminLoginErrorMessage->setVisible(true);
    }


}

void MainWindow::on_adminModifyButton_clicked()
{

    ui->listOfModifyStadiums->clear();

    for(int i = 0; i < keys.size(); i++) {
        Stadium *s = *stadiums.get(keys[i]);
        QTreeWidgetItem *currentItem = new QTreeWidgetItem(ui->listOfModifyStadiums);
        currentItem->setText(0, s->getStadiumName());
    }

    ui->display->setCurrentIndex(MODIFY_INFO);
}

void MainWindow::on_modifyInformationNextButton_clicked()
{
        QTreeWidgetItem* selectedStadium = ui->listOfModifyStadiums->currentItem();

       if(selectedStadium != NULL) {

           QString stadiumName = selectedStadium->data(0, 0).toString();
           currentStadium = *stadiums.get(db.getStadiumID(stadiumName));

           if(currentStadium != NULL) {

               ui->listOfModifyStadiumsSouvenirs->clear();

               QVector<Souvenir> stadiumsSouvenirs = currentStadium->getSouvenirs();

               for(int i = 0; i < stadiumsSouvenirs.size(); i++) {
                   Souvenir *s = &stadiumsSouvenirs[i];
                   QTreeWidgetItem *currentItem = new QTreeWidgetItem(ui->listOfModifyStadiumsSouvenirs);
                   currentItem->setText(0, s->getName());
                   currentItem->setText(1, "$" + QString::number(s->getPrice()));
               }

               ui->display->setCurrentIndex(MODIFY_SOUVENIRS);
           }

        }
        else {
               QMessageBox::warning(this, "Warning!", "Uh-oh, please select a stadium to modify.");

           }

}


void MainWindow::on_removeSelectedSouvenir_clicked()
{
    QTreeWidgetItem* currentSouvenir = ui->listOfModifyStadiumsSouvenirs->currentItem();

    if(currentSouvenir != NULL) {

        QString removeSouvenirName = currentSouvenir->data(0, 0).toString();
        currentStadium->removeSouvenir(removeSouvenirName);
    }
    else {
        QMessageBox::warning(this, "Warning!", "Uh-oh, please select a souvenir to delete.");

    }

    on_modifyInformationNextButton_clicked();
}

void MainWindow::on_addSelectedSouvenir_clicked()
{
    bool valid = true;

    QString souvenirName = ui->newSouvenirName->text();
    QString souvenirPrice = ui->newSouvenirPrice->text();

    QRegExp re("(\\d+)");

    if(isBlank(souvenirName) || isBlank(souvenirPrice)) {
        valid = false;
    }
    else if(!re.exactMatch(souvenirPrice)) {
        valid = false;
    }

    if(valid) {
        currentStadium->addSouvenir(new Souvenir(currentStadium->getStadiumID(), souvenirName, souvenirPrice.toDouble(), 0));
    }
    else {

    }


}

void MainWindow::on_confirmCustomTripButton_clicked()
{
    ui->display->setCurrentIndex(TRIP_PROCESS);
}

void MainWindow::on_shoppingCartButton_clicked()
{
//    ShoppingCart *currentShoppingCart = new ShoppingCart();

//    currentShoppingCart->SetList(currentCustomer->getShoppingCart());
//    currentShoppingCart->show();
//    currentShoppingCart->setVisible(true);
}


//Quick Sort
template <typename E>
void MainWindow::QuickSort(QVector<E> &vecToSort, int left, int right)
{
    int i = left;
    int j = right;
    E temp;

    //Chooses the pivot
    E pivot = vecToSort[(left + right) / 2];

    //Sorts the vector
    while(i <= j)
    {
        while(vecToSort[i] < pivot)
        {
            ++i;
        }
        while(vecToSort[j] > pivot)
        {
            --j;
        }
        if(i <= j)
        {
            temp = vecToSort[i];
            vecToSort[i] = vecToSort[j];
            vecToSort[j] = temp;
            ++i;
            --j;
        }
    }

    if(left < j)
        QuickSort(vecToSort, left, j);
    if(i < right)
        QuickSort(vecToSort, i, right);
}

