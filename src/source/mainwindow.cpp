#include "../header/mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // get the stadiums and greate a graph of them
    stadiums = db.getStadiums();
    stadiumsGraph = db.createGraph(stadiums);

    keys = db.getAllStadiumsKeys();

    for(skiplist<int, Stadium*>::Iterator itr = stadiums.begin(); itr != stadiums.end(); itr++) {
        Stadium *s = *stadiums.get(db.getStadiumID((*itr)->getStadiumName()));
        searchNames << s->getStadiumName();
    }

    stadiumSearch = new QCompleter(searchNames,this);
    stadiumSearch->setCaseSensitivity(Qt::CaseInsensitive);
    ui->searchBar->setCompleter(stadiumSearch);

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isBlank(QString text) {
    return text.trimmed() == "";
}

void MainWindow::tripProcess(QVector<Stadium*> trip) {

    ui->display->setCurrentIndex(TRIP_PROCESS);
    ui->currentTripNextStadium->setText("NEXT");
    shoppingCart.clear();


    QEventLoop pause;

    if(!trip.empty()) {

        double totalDistanceTraveled = 0;        // accumulator for trip distance
        const int NUM_OF_STADIUMS = trip.size(); // number of stadiums to visit

        // Loop once for every stadium on the trip list
        for(int i = 0; i < trip.size(); i++) {

            ui->currentTripProgressBar->setValue(((i+1)/(double)NUM_OF_STADIUMS)*100);

            ui->currentTripStadiumCount->setText(QString::number((i+1))
                                                 + " out of " + QString::number(NUM_OF_STADIUMS)
                                                 + " stadiums have been visited");

            /** Clears the current stadium sovenirs table,
             * to prepare for new stadium's souvenir list */
            ui->listOfCurrentStadiumSouvenirs->clear();

            if(i >= trip.size() - 1) {
                ui->currentTripNextStadium->setText("FINISH");
            }


            currentStadium = trip.pop;
            ui->currentTripStadiumNameLabel->setText(currentStadium->getStadiumName());

            QVector<Souvenir> souvenirs = currentStadium->getSouvenirs();

            for(int j = 0; j < souvenirs.size(); j++) {
                Souvenir souvenir = souvenirs[j];
                QTreeWidgetItem *currentItem = new QTreeWidgetItem(ui->listOfCurrentStadiumSouvenirs);
                currentItem->setText(0, souvenir.getName());
                currentItem->setText(1, "$" + QString::number(souvenir.getPrice()));

                QSpinBox *qtyBox = new QSpinBox();
                qtyBox->setRange(0, 99);

                ui->listOfCurrentStadiumSouvenirs->setItemWidget(currentItem, 2, qtyBox);
            }

            ui->listOfCurrentStadiumSouvenirs->resizeColumnToContents(0);
            ui->listOfCurrentStadiumSouvenirs->resizeColumnToContents(1);
            ui->listOfCurrentStadiumSouvenirs->resizeColumnToContents(2);


            totalDistanceTraveled += stadiumsGraph->GetDistanceTo(*currentStadium);
            ui->totalDistanceTraveled->display(totalDistanceTraveled);

            stadiumsGraph->Dijkstra(*currentStadium);


            /** Waits until user clicks 'next' button */
            QObject::connect(ui->currentTripNextStadium, SIGNAL(clicked()), &pause, SLOT(quit()));
            pause.exec();

        }

        ui->finalTotalDistance->display(totalDistanceTraveled);

        currentStadium = NULL;
        trip.clear();

    }
}

void MainWindow::on_homePageButton_clicked()
{
    ui->display->setCurrentIndex(HOME);
}

void MainWindow::on_viewStadiumByComboBox_currentIndexChanged(const QString &arg1)
{
    viewStadiumBy(arg1);
}


void MainWindow::on_viewStadiumsPageButton_clicked()
{
    ui->display->setCurrentIndex(VIEW_STADIUMS);
    viewStadiumBy(ui->viewStadiumByComboBox->currentText());
}


void MainWindow::viewStadiumBy(QString sortByType) {

    ui->viewStadiumsList->clear();

    ui->viewStadiumsList->setColumnWidth(0, 200);
    ui->viewStadiumsList->setColumnWidth(1, 90);
    ui->viewStadiumsList->setColumnWidth(2, 70);
    ui->viewStadiumsList->setColumnWidth(3, 100);
    ui->viewStadiumsList->setColumnWidth(4, 100);
    ui->viewStadiumsList->setColumnWidth(5, 90);
    ui->viewStadiumsList->setColumnWidth(6, 90);


    if(sortByType != "All") {
        for(int row = 0; row < keys.length(); row++) {
            Stadium *s = *stadiums.get(keys[row]);

            if(s->getLeagueType() == sortByType) {
                QTreeWidgetItem *currentItem = new QTreeWidgetItem(ui->viewStadiumsList);
                currentItem->setText(0, s->getStadiumName());
                currentItem->setText(1, s->getTeamName());
                currentItem->setText(2, QString::number(s->getSeatingCapacity()));
                currentItem->setText(3, s->getAddress().streetAddress + " " + s->getAddress().city
                                     + "\n" + s->getAddress().state + " " + s->getAddress().zipCode);
                currentItem->setText(4, s->getSurface());
                currentItem->setText(5, s->getDateOpened());
                currentItem->setText(6, s->getTypology());
            }

        }
    }
    else {


        for(int row = 0; row < keys.length(); row++) {
            Stadium *s = *stadiums.get(keys[row]);
            QTreeWidgetItem *currentItem = new QTreeWidgetItem(ui->viewStadiumsList);
            currentItem->setText(0, s->getStadiumName());
            currentItem->setText(1, s->getTeamName());
            currentItem->setText(2, QString::number(s->getSeatingCapacity()));
            currentItem->setText(3, s->getAddress().streetAddress + " " + s->getAddress().city
                                 + "\n" + s->getAddress().state + " " + s->getAddress().zipCode);
            currentItem->setText(4, s->getSurface());
            currentItem->setText(5, s->getDateOpened());
            currentItem->setText(6, s->getTypology());

        }
    }
}


void MainWindow::on_planATripButton_clicked()
{
    ui->display->setCurrentIndex(PLAN_A_TRIP);
}

void MainWindow::on_customTripButton_clicked()
{
    ui->display->setCurrentIndex(CUSTOM_TRIP);

    ui->stadiumsToSelectFromList->clear();
    ui->selectedStadiumsList->clear();
    ui->startingStadiumComboBox->clear();

 for(skiplist<int, Stadium*>::Iterator itr = stadiums.begin(); itr != stadiums.end(); itr++) {
        Stadium *s = *stadiums.get(db.getStadiumID((*itr)->getStadiumName()));
        ui->startingStadiumComboBox->addItem(s->getStadiumName());
    }
}

void MainWindow::on_startingStadiumComboBox_currentIndexChanged(const QString &arg1)
{
    ui->stadiumsToSelectFromList->clear();

    for(skiplist<int, Stadium*>::Iterator itr = stadiums.begin(); itr != stadiums.end(); itr++) {
        Stadium *s = *stadiums.get(db.getStadiumID((*itr)->getStadiumName()));
        if(s->getStadiumName() != arg1) {
            QTreeWidgetItem *currentItem = new QTreeWidgetItem(ui->stadiumsToSelectFromList);
            currentItem->setText(0, s->getStadiumName());
        }
    }

    QTreeWidgetItemIterator it(ui->selectedStadiumsList);
    bool found = false;
    while (*it && !found) {

        QString currentStadiumName = (*it)->text(0);


        if(currentStadiumName == arg1) {
            found = true;
            delete *it;
        }
        else {
            it++;
        }
    }


}


void MainWindow::on_stadiumsToSelectFromList_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    QString selectedStadiumName = item->text(0);
    QTreeWidgetItem *type = new QTreeWidgetItem(ui->selectedStadiumsList);
    type->setText(0, selectedStadiumName);
    ui->selectedStadiumsList->addTopLevelItem(type);

    delete item;
}

void MainWindow::on_selectedStadiumsList_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    QString selectedStadiumName = item->text(0);
    QTreeWidgetItem *type = new QTreeWidgetItem(ui->stadiumsToSelectFromList);
    type->setText(0, selectedStadiumName);
    ui->stadiumsToSelectFromList->addTopLevelItem(type);

    delete item;
}



void MainWindow::on_minimumSpanningTreeButton_clicked()
{
    ui->display->setCurrentIndex(MST_TRIP);

    double totalWeight = 0;

    Graph<Stadium>::EdgeList edges = stadiumsGraph->MSTPrim();

    for(Graph<Stadium>::EdgeItr i = edges.begin(); i != edges.end(); i++) {
        QTreeWidgetItem *currentItem = new QTreeWidgetItem(ui->MSTList);
        currentItem->setText(0, i->start().print());
        currentItem->setText(1, i->end().print());
        currentItem->setText(2, QString::number(i->weight()));
        currentItem->setTextAlignment(2, Qt::AlignHCenter);
        totalWeight += i->weight();
    }

    ui->mstTotalWeight->setText(QString::number(totalWeight) + " miles");

    ui->MSTList->setColumnWidth(0, 230);
    ui->MSTList->setColumnWidth(1, 230);
    ui->MSTList->resizeColumnToContents(2);




}

void MainWindow::on_shortestTripToAllButton_clicked()
{
    ui->display->setCurrentIndex(QUICK_TRIP);

    const QString startingStadiumName = "Dodger Stadium";
    Stadium s = **stadiums.get(db.getStadiumID(startingStadiumName));
    stadiumsGraph->Dijkstra(s);

    ui->quickTripStartingStadium->setText(startingStadiumName);


//    Graph<Stadium>::VertexList path = stadiumsGraph->shortestPathTo(**stadiums.get(db.getStadiumID("Wrigley Field")));
//    Graph<Stadium>::VertexItr itr = path.begin();
//    while(itr != path.end()){
//        QTreeWidgetItem *currentItem = new QTreeWidgetItem(ui->shortestTripList);
//        Stadium s = **itr;
//        currentItem->setText(0, s.getStadiumName());
//        currentItem->setText(1, QString::number((itr)->getDistance(), 'f', 2));
//        totalWeight += (itr)->getDistance();

//        itr++;

//    }

    ui->quickTripList->clear();

     for(skiplist<int, Stadium*>::Iterator itr = stadiums.begin(); itr != stadiums.end(); itr++) {
        Stadium *s = *stadiums.get(db.getStadiumID((*itr)->getStadiumName()));
        QTreeWidgetItem *currentItem = new QTreeWidgetItem(ui->quickTripList);
        currentItem->setText(0, s->getStadiumName());
        currentItem->setText(1, QString::number(stadiumsGraph->GetDistanceTo(*s)));
    }

     ui->quickTripList->setColumnWidth(0, 250);


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

    for(skiplist<int, Stadium*>::Iterator itr = stadiums.begin(); itr != stadiums.end(); itr++) {
        Stadium *s = *stadiums.get(db.getStadiumID((*itr)->getStadiumName()));
        QTreeWidgetItem *currentItem = new QTreeWidgetItem(ui->listOfModifyStadiums);
        currentItem->setText(0, s->getStadiumName());
    }

    ui->display->setCurrentIndex(MODIFY_INFO);
}

void MainWindow::on_modifyInformationNextButton_clicked()
{
   ui->newSouvenirName->clear();
   ui->newSouvenirPrice->clear();
   ui->adminAddSouvenirErrorMessage->setVisible(false);


   QTreeWidgetItem* selectedStadium = ui->listOfModifyStadiums->currentItem();

       if(selectedStadium != NULL) {

           QString stadiumName = selectedStadium->data(0, 0).toString();
           currentStadium = *stadiums.get(db.getStadiumID(stadiumName));

           if(currentStadium != NULL) {

               ui->listOfModifyStadiumsSouvenirs->clear();

               QVector<Souvenir> stadiumsSouvenirs = currentStadium->getSouvenirs();

               ui->listOfModifyStadiumsSouvenirs->setColumnWidth(0, 300);
               for(int i = 0; i < stadiumsSouvenirs.size(); i++) {
                   Souvenir *s = &stadiumsSouvenirs[i];
                   QTreeWidgetItem *currentItem = new QTreeWidgetItem(ui->listOfModifyStadiumsSouvenirs);
                   currentItem->setText(0, s->getName());
                   currentItem->setText(1, "$" + QString::number(s->getPrice(), 'f', 2));
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

    ui->adminAddSouvenirErrorMessage->setVisible(false);

    QString souvenirName = ui->newSouvenirName->text();
    QString souvenirPrice = ui->newSouvenirPrice->text();

    QRegExp re("\\$?[0-9]+\\.?[0-9]*");

    if(isBlank(souvenirName) || isBlank(souvenirPrice)) {
        valid = false;
    }
    else if(!re.exactMatch(souvenirPrice)) {
        valid = false;
    }


    if(valid) {
        if(souvenirPrice.at(0) == '$') {
            souvenirPrice = souvenirPrice.mid(1,souvenirPrice.size());
        }

        currentStadium->addSouvenir(new Souvenir(currentStadium->getStadiumID(), souvenirName, souvenirPrice.toDouble(), 0));
        on_modifyInformationNextButton_clicked();
    }
    else {
        ui->adminAddSouvenirErrorMessage->setVisible(true);
    }


}

void MainWindow::on_confirmCustomTripButton_clicked()
{
    // Get starting point from the UI
    Stadium *s = *stadiums.get(db.getStadiumID(ui->startingStadiumComboBox->currentText()));

    if(s != NULL) {
        QVector<Stadium *> trip;

        // add starting point to front of vector
        trip.push_back(s);

        QTreeWidgetItemIterator it(ui->selectedStadiumsList);
        QString stadiumName;

        // add the rest to the vector
        while(*it) {
            stadiumName = (*it)->text(0);
            s = *stadiums.get(db.getStadiumID(stadiumName));
            trip.push_back(s);
            it++;
        }
        // Send the list to the trip processing method
        tripProcess(trip);
    }

}

void MainWindow::on_quickTripTakeTripButton_clicked()
{
    QTreeWidgetItem* selectedStadium = ui->quickTripList->currentItem();

    if(selectedStadium != NULL) {

        Stadium *startingStadium = *stadiums.get(db.getStadiumID(ui->quickTripStartingStadium->text()));
        Stadium *stadiumToVisit = *stadiums.get(db.getStadiumID(selectedStadium->data(0, 0).toString()));

        if(startingStadium != NULL && stadiumToVisit != NULL) {
            QVector<Stadium*> trip;
            trip.push_back(startingStadium);
            trip.push_back(stadiumToVisit);
            tripProcess(trip);
        }
    }
    else {
        QMessageBox::warning(this, "Warning!", "Uh-oh, please select a stadium to visit.");

    }


}

void MainWindow::on_shoppingCartButton_clicked()
{
    ShoppingCart *currentShoppingCart = new ShoppingCart();
    currentShoppingCart->setList(shoppingCart, stadiums);
    currentShoppingCart->show();
    currentShoppingCart->setVisible(true);
    currentShoppingCart->setFocus();
}

void MainWindow::on_secretAdminLoginButton_clicked()
{
    on_adminLoginButton_clicked();
}

void MainWindow::on_addSouvenirToShoppingCart_clicked()
{
    QString name;
    double price;
    unsigned int qty;
    
    if(currentStadium != NULL) {
        
        QTreeWidgetItemIterator it(ui->listOfCurrentStadiumSouvenirs);
        while (*it) {

            name = (*it)->text(0);
            price = (*it)->text(1).right((*it)->text(1).size() - 1).toDouble();

            QSpinBox* box = qobject_cast<QSpinBox*>(ui->listOfCurrentStadiumSouvenirs->itemWidget((*it), 2));
            qty = box->text().toInt();

            if(qty != 0) {
                Souvenir *s = new Souvenir(currentStadium->getStadiumID(), name, price, qty);
                addToCart(s);
                box->setValue(0);

            }



          it++;
        }
    }


    
}

void MainWindow::addToCart(Souvenir *s) {

    /** First checks if the item already exists within
     * the shopping cart, if so it will add to its quantity */
    Souvenir *foundSouvenir = NULL;
    bool found = false;

    int i = 0;
    while(!found && i < shoppingCart.size()) {
        if((shoppingCart[i]->getStadiumID() == s->getStadiumID()) &&
            (shoppingCart[i]->getName() == s->getName())) {
            found = true;
            foundSouvenir = shoppingCart[i];
        }

       i++;
    }

    /** Checks if an existing souvenir was found or not */
    if(foundSouvenir != NULL) {
        foundSouvenir->addToQuantity(s->getQuantity());
    }
    /** If not found, pushes the new souvenir to the
     * end of the shoppingCart list */
    else {
        shoppingCart.push_back(s);
    }
}




void MainWindow::on_currentTripNextStadium_clicked()
{
    if(ui->currentTripNextStadium->text() == "FINISH") {
        ui->display->setCurrentIndex(CONFIRM_SHOPPING_CART);

        if(shoppingCart.empty()) {
            ui->shoppingCart->hide();
            ui->updateShoppingCart->setVisible(false);
            ui->grandTotalAmount->setText("$0.00");

        }
        else {
            ui->shoppingCart->clear();
            ui->updateShoppingCart->setVisible(true);
            ui->shoppingCart->setVisible(true);

            QString currentStadium = "";
            QString nextStadium = "";
            double stadiumTotal = 0;
            double grandTotal = 0;

            QString souvenirName;
            double subtotal;
            unsigned int qty;
            double souvenirTotal;


            // Sets the iterator to begin at the start of the list
            QVector<Souvenir*>::iterator it = shoppingCart.begin();

            QTreeWidgetItem *parent = new QTreeWidgetItem(ui->shoppingCart);
            ui->shoppingCart->addTopLevelItem(parent);
            currentStadium = (*stadiums.get((*it)->getStadiumID()))->getStadiumName();

            parent->setText(1, currentStadium);

            ui->shoppingCart->setColumnWidth(0, 70);
            ui->shoppingCart->setColumnWidth(1, 200);
            ui->shoppingCart->setColumnWidth(2, 70);
            ui->shoppingCart->setColumnWidth(3, 70);
            ui->shoppingCart->setColumnWidth(4, 70);

            while(it != shoppingCart.end())
            {
                nextStadium = (*stadiums.get((*it)->getStadiumID()))->getStadiumName();

                if(currentStadium != nextStadium) {

                    parent->setText(4, QString::number(stadiumTotal, 'f', 2));
                    stadiumTotal = 0;
                    parent = new QTreeWidgetItem(ui->shoppingCart);
                    ui->shoppingCart->addTopLevelItem(parent);
                    parent->setText(1, nextStadium);
                    ui->shoppingCart->addTopLevelItem(parent);

                    currentStadium = nextStadium;

                }

                souvenirName = (*it)->getName();
                subtotal = (*it)->getPrice();
                qty   = (*it)->getQuantity();
                souvenirTotal = (*it)->getPrice() * (*it)->getQuantity();

                QTreeWidgetItem *itm = new QTreeWidgetItem(parent);
                QCheckBox *removeCheckBox = new QCheckBox();

                ui->shoppingCart->setItemWidget(itm, 0, removeCheckBox);

                itm->setText(1, souvenirName);
                itm->setText(2, "$" + QString::number(subtotal, 'f', 2));
                itm->setTextAlignment(1, Qt::AlignCenter);
                itm->setText(3, QString::number(qty));
                itm->setTextAlignment(2, Qt::AlignCenter);
                itm->setText(4, "$" + QString::number(souvenirTotal, 'f', 2));
                itm->setTextAlignment(3, Qt::AlignCenter);

                stadiumTotal += souvenirTotal;
                grandTotal += stadiumTotal;


                parent->addChild(itm);
                // Iterator increments to the next node
                it++;
            }

            parent->setText(4, QString::number(stadiumTotal, 'f', 2));
            stadiumTotal = 0;

            grandTotal += stadiumTotal;
            ui->grandTotalAmount->setText("$" + QString::number(grandTotal, 'f', 2));
        }
    }
}

void MainWindow::on_searchButton_clicked()
{
    viewSingleStadium(ui->searchBar->text());

    ui->searchBar->clear();


}

void MainWindow::viewSingleStadium(QString stadiumName) {
    int stadiumID = db.getStadiumID(stadiumName);

    /** If stadium id is -1, the stadium does not exist */
    if(stadiumID != -1) {
        Stadium *s = *stadiums.get(stadiumID);
        ui->singleStadiumNameLabel->setText(s->getStadiumName());
        ui->singleStadiumInfo->setVisible(true);

        ui->singleStadiumAddress->setText(s->getAddress().streetAddress + " " + s->getAddress().city
                                          + "\n" + s->getAddress().state + " " + s->getAddress().zipCode);
        ui->singleStadiumBoxOfficeNum->setText(s->getBoxOfficeNumber());
        ui->singleStadiumSeatingCapacity->setText(QString::number(s->getSeatingCapacity()));
        ui->singleStadiumSurface->setText(s->getSurface());
        ui->singleStadiumTeamName->setText(s->getTeamName());
        ui->singleStadiumDateOpened->setText(s->getDateOpened());
        ui->singleStadiumType->setText(s->getLeagueType());

        if(adminPrivilege) {
            ui->singleStadiumTotalRevenue->setVisible(true);
            ui->totalRevenueLabel->setVisible(true);
            ui->singleStadiumTotalRevenue->setText("$" + QString::number(s->getTotalRevenue(),'f',2));
        }
        else {
            ui->singleStadiumTotalRevenue->setVisible(false);
            ui->totalRevenueLabel->setVisible(false);
        }

    }
    else if(!isBlank(ui->searchBar->text())) {
        ui->singleStadiumNameLabel->setText(stadiumName + " was not found.");
        ui->singleStadiumInfo->hide();
    }

    ui->display->setCurrentIndex(VIEW_SINGLE_STADIUM);

}


void MainWindow::on_confirmPurchasesButton_clicked()
{
    QString stadiumName;
    double totalSpentAtStadium;

    QTreeWidgetItemIterator it(ui->shoppingCart);
    while (*it) {

        stadiumName = (*it)->text(1);
        totalSpentAtStadium = (*it)->text(4).toDouble();
        Stadium *s = *stadiums.get(db.getStadiumID(stadiumName));

        if(s != NULL) {
            s->addToTotalRevenue(totalSpentAtStadium);
            db.updateTotalRevenue(s->getStadiumID(), s->getTotalRevenue());
        }

      it++;
    }

    /** Clears shopping cart once purchases are confirmed */
    shoppingCart.clear();

    ui->display->setCurrentIndex(HOME);
}

void MainWindow::on_viewAdminStadiumsButton_clicked()
{
    ui->display->setCurrentIndex(ADMIN_STADIUMS);

    ui->adminStadiumList->clear();

    ui->adminStadiumList->setColumnWidth(0, 200);
    ui->adminStadiumList->setColumnWidth(1, 70);

    double grandTotalRevenue = 0;

    for(skiplist<int, Stadium*>::Iterator itr = stadiums.begin(); itr != stadiums.end(); itr++) {
        Stadium *s = *stadiums.get(db.getStadiumID((*itr)->getStadiumName()));

        QTreeWidgetItem *currentItem = new QTreeWidgetItem(ui->adminStadiumList);
        currentItem->setText(0, s->getStadiumName());
        currentItem->setText(1, "$" + QString::number(s->getTotalRevenue(), 'f', 2));
        grandTotalRevenue += s->getTotalRevenue();
    }

    ui->stadiumTotalRevenue->setText("$" + QString::number(grandTotalRevenue, 'f', 2));

}

void MainWindow::on_adminHomeButton_clicked()
{
    ui->display->setCurrentIndex(ADMIN_HOME);
}


void MainWindow::on_viewMoreInfoAboutStadiumButton_clicked()
{
    QTreeWidgetItem* selectedStadium = ui->adminStadiumList->currentItem();

    if(selectedStadium != NULL) {

        viewSingleStadium(selectedStadium->data(0, 0).toString());
    }
    else {
        QMessageBox::warning(this, "Warning!", "Uh-oh, please select a stadium to view.");

    }

}





