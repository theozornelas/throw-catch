#include "../header/mainwindow.h"
#include "ui_mainwindow.h"

#include <QMovie>

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

        double totalDistanceTraveled = 0;
        QString previousStadium = "Home";

        const int NUM_OF_STADIUMS = trip.size();

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


            currentStadium = trip[i];

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

            ui->travelFromName->setText(previousStadium);
            ui->travelToName->setText(currentStadium->getStadiumName());
            QMovie *animation = new QMovie(":/icon/icons/baseball-travel.gif");
            ui->travelGif->setMovie(animation);
            animation->start();



            ui->listOfCurrentStadiumSouvenirs->resizeColumnToContents(0);
            ui->listOfCurrentStadiumSouvenirs->resizeColumnToContents(1);
            ui->listOfCurrentStadiumSouvenirs->resizeColumnToContents(2);


            totalDistanceTraveled += stadiumsGraph->GetDistanceTo(*currentStadium);
            ui->totalDistanceTraveled->display(totalDistanceTraveled);

            stadiumsGraph->Dijkstra(*currentStadium);

            /** Waits until user clicks 'next' button */
            QObject::connect(ui->currentTripNextStadium, SIGNAL(clicked()), &pause, SLOT(quit()));
            pause.exec();

            delete animation;
            previousStadium = currentStadium->getStadiumName();

        }

        ui->finalTotalDistance->display(totalDistanceTraveled);

        currentStadium = NULL;
        trip.clear();

    }
}

void MainWindow::tripProcess2(QVector<VertexItr> trip) {

    // Comparitor class for vertexItr, pushes smallest weights to the bottom
    struct {
        bool operator()(const VertexItr &lhs, const VertexItr &rhs) {
            return (lhs->getDistance() < rhs->getDistance());
        }
    } compStadium;

    ui->display->setCurrentIndex(TRIP_PROCESS);
    ui->currentTripNextStadium->setText("NEXT");
    shoppingCart.clear();


    QEventLoop pause;

    if(!trip.empty()) {

        double totalDistanceTraveled = 0;        // accumulator for trip distance
        const int NUM_OF_STADIUMS = trip.size(); // number of stadiums to visit
        QString previousStadium = "Home";

        qDebug() << "NUMBER OF STADIUMS TO VISIT: " << NUM_OF_STADIUMS;

        // Loop once for every stadium on the trip list
        for(int i = 0; i < NUM_OF_STADIUMS; i++) {

            ui->currentTripProgressBar->setValue(((i+1)/(double)NUM_OF_STADIUMS)*100);

            ui->currentTripStadiumCount->setText(QString::number((i+1))
                                                 + " out of " + QString::number(NUM_OF_STADIUMS)
                                                 + " stadiums have been visited");


            /** Clears the current stadium sovenirs table,
             * to prepare for new stadium's souvenir list */
            ui->listOfCurrentStadiumSouvenirs->clear();

            if(i >= NUM_OF_STADIUMS - 1) {
                ui->currentTripNextStadium->setText("FINISH");
            }

            // pop the next stadium to visit and store in the class variable
            currentStadium = *stadiums.get(db.getStadiumID((**trip.front()).getStadiumName())); // GROSS! :P
            //currentStadiumItr = trip.front();
            trip.pop_front();
            ui->currentTripStadiumNameLabel->setText(currentStadium->getStadiumName());
            ui->travelFromName->setText(previousStadium);
            previousStadium = currentStadium->getStadiumName();
            ui->travelToName->setText(currentStadium->getStadiumName());

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


            QMovie *animation = new QMovie(":/icon/icons/baseball-travel.gif");
            ui->travelGif->setMovie(animation);
            animation->start();


            ui->listOfCurrentStadiumSouvenirs->resizeColumnToContents(0);
            ui->listOfCurrentStadiumSouvenirs->resizeColumnToContents(1);
            ui->listOfCurrentStadiumSouvenirs->resizeColumnToContents(2);

            // add distance from last stop to this stop to the total distance
            if(i != 0){
                totalDistanceTraveled += stadiumsGraph->GetDistanceTo(*currentStadium);
            }
            ui->totalDistanceTraveled->display(totalDistanceTraveled);

            stadiumsGraph->Dijkstra(*currentStadium);
            std::sort(trip.begin(), trip.end(), compStadium);




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
    QTreeWidgetItemIterator it(ui->viewStadiumsList);
    QVector<Stadium*> list;
    QString stadiumName;

    while(*it) {
        stadiumName = (*it)->text(0);
        Stadium *s = *stadiums.get(db.getStadiumID(stadiumName));
        list.push_back(s);
        it++;
    }

    viewStadiumBy(arg1, list);
}


void MainWindow::on_viewStadiumsPageButton_clicked()
{
    ui->display->setCurrentIndex(VIEW_STADIUMS);
    QVector<Stadium*> list;

    for(skiplist<int, Stadium*>::Iterator itr = stadiums.begin(); itr != stadiums.end(); itr++) {
           Stadium *s = *stadiums.get(db.getStadiumID((*itr)->getStadiumName()));
           list.push_back(s);
    }

    viewStadiumBy(ui->viewStadiumByComboBox->currentText(), list);
}


void MainWindow::viewStadiumBy(QString sortByType, QVector<Stadium*> stadiumList) {

    ui->viewStadiumsList->clear();

    ui->viewStadiumsList->setColumnWidth(0, 200);
    ui->viewStadiumsList->setColumnWidth(1, 210);
    ui->viewStadiumsList->setColumnWidth(2, 80);
    ui->viewStadiumsList->setColumnWidth(3, 200);
    ui->viewStadiumsList->setColumnWidth(4, 100);
    ui->viewStadiumsList->setColumnWidth(5, 120);
    ui->viewStadiumsList->setColumnWidth(6, 170);


    if(sortByType != "All") {
        for(skiplist<int, Stadium*>::Iterator itr = stadiums.begin(); itr != stadiums.end(); itr++) {
            Stadium *s = *stadiums.get(db.getStadiumID((*itr)->getStadiumName()));

            if(s->getLeagueType() == sortByType) {
                QTreeWidgetItem *currentItem = new QTreeWidgetItem(ui->viewStadiumsList);
                currentItem->setText(0, s->getStadiumName());
                currentItem->setText(1, s->getTeamName());
                currentItem->setText(2, QString::number(s->getSeatingCapacity()));
                currentItem->setText(3, s->getAddress().streetAddress.trimmed() + ",\n" + s->getAddress().city
                                     + ", " + s->getAddress().state + " " + s->getAddress().zipCode);
                currentItem->setText(4, s->getSurface());
                QDate currentDate = QDate::fromString(s->getDateOpened(), "MMMM d, yyyy");
                currentItem->setData(5, 0, currentDate);
                currentItem->setText(6, s->getTypology());
            }

        }
    }
    else {

        for(skiplist<int, Stadium*>::Iterator itr = stadiums.begin(); itr != stadiums.end(); itr++) {
            Stadium *s = *stadiums.get(db.getStadiumID((*itr)->getStadiumName()));
            QTreeWidgetItem *currentItem = new QTreeWidgetItem(ui->viewStadiumsList);
            currentItem->setText(0, s->getStadiumName());
            currentItem->setText(1, s->getTeamName());
            currentItem->setText(2, QString::number(s->getSeatingCapacity()));
            currentItem->setText(3, s->getAddress().streetAddress.trimmed() + ",\n" + s->getAddress().city
                                 + ", " + s->getAddress().state + " " + s->getAddress().zipCode);
            currentItem->setText(4, s->getSurface());
            QDate currentDate = QDate::fromString(s->getDateOpened(), "MMMM d, yyyy");
            currentItem->setData(5, 0, currentDate);
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

    Graph<Stadium>::EdgeList edges = stadiumsGraph->PrimJarnek();

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

void MainWindow::on_password_returnPressed()
{
    on_loginButton_clicked();
}

void MainWindow::on_adminModifyButton_clicked()
{

    ui->listOfModifyStadiums->clear();

    for(skiplist<int, Stadium*>::Iterator itr = stadiums.begin(); itr != stadiums.end(); itr++) {
        Stadium *s = *stadiums.get(db.getStadiumID((*itr)->getStadiumName()));
        QTreeWidgetItem *currentItem = new QTreeWidgetItem(ui->listOfModifyStadiums);

        if(s != NULL) {
            currentItem->setText(0, s->getStadiumName());
        }
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
        qDebug() << "Removing a souvenir: " << db.RemoveSouvenir(currentStadium->getStadiumID(), removeSouvenirName);
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

        Souvenir *s = new Souvenir(currentStadium->getStadiumID(), souvenirName, souvenirPrice.toDouble(), 0);
        currentStadium->addSouvenir(s);
        qDebug() << "Adding a souvenir: " << db.AddNewSouvenir(currentStadium->getStadiumID(), souvenirName, souvenirPrice.toDouble(), 0);

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
        QVector<VertexItr> trip;

        // add starting point to front of vector
        trip.push_back( stadiumsGraph->findVertex(*s) );

        QTreeWidgetItemIterator it(ui->selectedStadiumsList);
        QString stadiumName;

        // add the rest to the vector
        while(*it) {
            stadiumName = (*it)->text(0);
            s = *stadiums.get(db.getStadiumID(stadiumName));
            trip.push_back( stadiumsGraph->findVertex(*s) );
            it++;
        }
        // Send the list to the trip processing method
        tripProcess2(trip);
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


            ui->grandTotalAmount->setText("$0.00");

        }
        else {
            ui->shoppingCart->clear();
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

            ui->shoppingCart->setColumnWidth(0, 200);
            ui->shoppingCart->setColumnWidth(1, 70);
            ui->shoppingCart->setColumnWidth(2, 70);
            ui->shoppingCart->setColumnWidth(3, 70);

            while(it != shoppingCart.end())
            {
                nextStadium = (*stadiums.get((*it)->getStadiumID()))->getStadiumName();

                if(currentStadium != nextStadium) {

                    parent->setText(3, QString::number(stadiumTotal, 'f', 2));
                    grandTotal += stadiumTotal;
                    stadiumTotal = 0;
                    parent = new QTreeWidgetItem(ui->shoppingCart);
                    ui->shoppingCart->addTopLevelItem(parent);
                    parent->setText(0, nextStadium);
                    ui->shoppingCart->addTopLevelItem(parent);

                    currentStadium = nextStadium;

                }

                souvenirName = (*it)->getName();
                subtotal = (*it)->getPrice();
                qty   = (*it)->getQuantity();
                souvenirTotal = (*it)->getPrice() * (*it)->getQuantity();

                QTreeWidgetItem *itm = new QTreeWidgetItem(parent);


                itm->setText(0, souvenirName);
                itm->setText(1, "$" + QString::number(subtotal, 'f', 2));
                itm->setTextAlignment(1, Qt::AlignCenter);
                itm->setText(2, QString::number(qty));
                itm->setTextAlignment(2, Qt::AlignCenter);
                itm->setText(3, "$" + QString::number(souvenirTotal, 'f', 2));
                itm->setTextAlignment(3, Qt::AlignCenter);

                stadiumTotal += souvenirTotal;

                parent->addChild(itm);
                // Iterator increments to the next node
                it++;
            }

            parent->setText(3, QString::number(stadiumTotal, 'f', 2));
            grandTotal += stadiumTotal;
            stadiumTotal = 0;

            ui->grandTotalAmount->setText("$" + QString::number(grandTotal, 'f', 2));
        }

        ui->shoppingCart->expandAll();

    }
}

/****************************
 *  VIEWING RANDOM STADIUM
 ****************************/
void MainWindow::on_searchButton_clicked()
{
    viewSingleStadium(ui->searchBar->text());

    ui->searchBar->clear();
}

void MainWindow::on_searchBar_returnPressed()
{
    on_searchButton_clicked();
}


void MainWindow::viewSingleStadium(QString stadiumName) {
    int stadiumID = db.getStadiumID(stadiumName);

    /** If stadium id is -1, the stadium does not exist */
    if(stadiumID != -1) {
        Stadium *s = *stadiums.get(stadiumID);
        ui->singleStadiumNameLabel->setText(s->getStadiumName());
        ui->singleStadiumInfo->setVisible(true);


        ui->singleStadiumAddress->setText(s->getAddress().streetAddress.trimmed() + ",\n" + s->getAddress().city
                                          + ", " + s->getAddress().state + " " + s->getAddress().zipCode);
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


void MainWindow::on_addStadiumFromFileButton_clicked()
{
        QString filename = QFileDialog::getOpenFileName(
                                       this,                                    // The parent of this popup
                                       "Select New Stadium JSON",               // The caption on the file picker
                                       QDir::currentPath(),                     // The default directory to show
                                       "JSON File (*.json);;Text File (*.txt);;All Files (*.*)");

        qDebug() << "FILE SELECTED: " << filename;

        // Create the input file object
        QFile inFile(filename);

        // Open the input file object
        if (!inFile.open(QIODevice::ReadOnly)) {
                qWarning("Couldn't open file.");
            }

        // read the file into a string
        QString stringFile = inFile.readAll();
        inFile.close();

        // open data into a JSON Object
        QJsonDocument jsonFile = QJsonDocument::fromJson(stringFile.toUtf8());

        // check to make sure file contains JSON object
        if(jsonFile.isObject()){
            // extract object and make sure it's a stadium
            QJsonObject JsonStadium = jsonFile.object();
            if(JsonStadium["ObjType"].toString() == "stadium"){
                int newStadiumID = stadiums.size()+1;
                Stadium* newStadium = new Stadium(newStadiumID, // ID should be 1 more than size
                                                   JsonStadium["stadiumName"].toString(),
                                                   JsonStadium["teamName"].toString(),
                                                   JsonStadium["streetAddress"].toString().trimmed(),
                                                   JsonStadium["city"].toString(),
                                                   JsonStadium["state"].toString(),
                                                   JsonStadium["zipCode"].toString(),
                                                   JsonStadium["boxOfficeNumber"].toString(),
                                                   JsonStadium["dateOpened"].toString(),
                                                   JsonStadium["seatingCapacity"].toInt(),
                                                   JsonStadium["surface"].toString(),
                                                   JsonStadium["leagueType"].toString(),
                                                   JsonStadium["typology"].toString(),
                                                   0);  // initial revenue is 0

                qDebug() << JsonStadium["stadiumName"].toString();
                qDebug() << JsonStadium["streetAddress"].toString();
                qDebug() << JsonStadium["city"].toString() << ", "
                         << JsonStadium["state"].toString() << JsonStadium["zipCode"].toString();
                qDebug() << "PHONE NUM: " << JsonStadium["boxOfficeNumber"].toString();
                qDebug() << "Team: " << JsonStadium["teamName"].toString();
                qDebug() << "League: " << JsonStadium["leagueType"].toString();
                qDebug() << "Date opened: " << JsonStadium["dateOpened"].toString();
                qDebug() << "Seating Capactiy: " << JsonStadium["seatingCapacity"].toInt();
                qDebug() << "Surface Type: " << JsonStadium["surface"].toString();
                qDebug() << "Stadium Type: " << JsonStadium["typology"].toString();

                // insert stadium to skiplist
                stadiums.insert(newStadiumID, newStadium);
                // Add stadium to Database
                db.AddNewStadium(newStadium);
                // Add stadium ID to lookup list
                keys.push_back(newStadiumID);

                //Inserts and sets the autocomplete search
                searchNames << newStadium->getStadiumName();

                stadiumSearch = new QCompleter(searchNames,this);
                stadiumSearch->setCaseSensitivity(Qt::CaseInsensitive);
                ui->searchBar->setCompleter(stadiumSearch);


                // insert stadium and edges into graph
                QJsonArray adjAR = JsonStadium["adjacent"].toArray();
                for(int i = 0; i < adjAR.size(); i++){
                    QJsonObject edge = adjAR.at(i).toObject();
                    int destID   = db.getStadiumID(edge["stadium"].toString());
                    Stadium destination = **stadiums.get(destID);
                    int distance = edge["distance"].toInt();

                    stadiumsGraph->insertEdge(*newStadium, destination, distance);
                    qDebug() << "Successfully added edges to database? " << db.addEdges(newStadium, &destination, distance);
                    qDebug() << "DISTANCE TO NEW STADIUM: " << stadiumsGraph->GetDistance(destination, *newStadium);
                }
            }
            else{ qDebug() << "File contains no valid Stadium Object";}
        }
        else{ qDebug() << "File contains no valid JSON object!";}

}

void MainWindow::on_adminModifyStadiumsButton_clicked()
{
    ui->display->setCurrentIndex(MODIFY_STADIUMS);

    ui->stadiumsToModifyList->clear();

    for(skiplist<int, Stadium*>::Iterator itr = stadiums.begin(); itr != stadiums.end(); itr++) {
        Stadium *s = *stadiums.get(db.getStadiumID((*itr)->getStadiumName()));

        QTreeWidgetItem *currentItem = new QTreeWidgetItem(ui->stadiumsToModifyList);
        currentItem->setText(0, s->getStadiumName());
    }

}

void MainWindow::on_updateAStadiumButton_clicked()
{
    QTreeWidgetItem* selectedStadium = ui->stadiumsToModifyList->currentItem();

    if(selectedStadium != NULL) {

        ui->updateStadiumInvalidErrorMessage->hide();


       currentStadium = *stadiums.get(db.getStadiumID(selectedStadium->data(0, 0).toString()));
       ui->updateStadium->setText(currentStadium->getStadiumName());
       ui->updateTeamName->setText(currentStadium->getTeamName());
       ui->updateStreetAddress->setText(currentStadium->getAddress().streetAddress);
       ui->updateCity->setText(currentStadium->getAddress().city);
       ui->updateZipcode->setText(currentStadium->getAddress().zipCode);
       ui->updateState->setText(currentStadium->getAddress().state);
       ui->updateSeatingCapacity->setValue(currentStadium->getSeatingCapacity());
       ui->updatePhoneNumber->setText(currentStadium->getBoxOfficeNumber());
       ui->updateTypology->setText(currentStadium->getTypology());
       
       QDate stadiumDate = QDate::fromString(currentStadium->getDateOpened(), "MMMM d, yyyy");

       ui->updateYear->setText(QString::number(stadiumDate.year()));
       ui->updateMonth->setCurrentIndex(stadiumDate.month());
       ui->updateDay->setText(QString::number(stadiumDate.day()));

       if(currentStadium->getLeagueType() == "American") {
           ui->updateAmericanLeague->setChecked(true);
       }
       else {
           ui->updateNationalLeague->setChecked(true);
       }

       ui->display->setCurrentIndex(UPDATE_STADIUM);

    }
    else {
        QMessageBox::warning(this, "Warning!", "Uh-oh, please select a stadium to update.");

    }
}



void MainWindow::on_cancelStadiumUpdatesButton_clicked()
{
    ui->display->setCurrentIndex(MODIFY_STADIUMS);
}

/**
 * @brief MainWindow::on_confirmStadiumUpdateButton_clicked
 *        Error checks all input, and if all input is valid,
 *        program will update the current stadium as well
 *        as update it within the database.
 */
void MainWindow::on_confirmStadiumUpdateButton_clicked()
{
    /** Let the error checking begin */

    const QString validStyleSheet = "QLineEdit { "
                                      "border:1px outset; border-radius: 1px; "
                                      "border-color: rgb(114, 114, 114); }";

    const QString invalidStyleSheet = "QLineEdit { "
                                      "border:1px outset; border-radius: 1px; "
                                      "border-color: red; }";

    ui->updateStadium->setStyleSheet(validStyleSheet);
    ui->updateTeamName->setStyleSheet(validStyleSheet);
    ui->updatePhoneNumber->setStyleSheet(validStyleSheet);
    ui->updateTypology->setStyleSheet(validStyleSheet);
    ui->updateStreetAddress->setStyleSheet(validStyleSheet);
    ui->updateCity->setStyleSheet(validStyleSheet);
    ui->updateState->setStyleSheet(validStyleSheet);
    ui->updateZipcode->setStyleSheet(validStyleSheet);
    ui->updateDay->setStyleSheet(validStyleSheet);
    ui->updateYear->setStyleSheet(validStyleSheet);

    ui->updateStadiumInvalidErrorMessage->hide();

    bool valid = true;
    QString newStadiumName = ui->updateStadium->text();
    QString newTeamName = ui->updateTeamName->text();
    QString newBoxOfficeNumber = ui->updatePhoneNumber->text();
    int     newSeatingCapacity = ui->updateSeatingCapacity->value();
    QString newTypology = ui->updateTypology->text();

    Address newAddress;
    newAddress.streetAddress = ui->updateStreetAddress->text();
    newAddress.city = ui->updateCity->text();
    newAddress.state = ui->updateState->text();
    newAddress.zipCode = ui->updateZipcode->text();


    QString newLeagueType = (ui->updateAmericanLeague->isChecked() ? "American" : "National");

    int month = ui->updateMonth->currentIndex();
    int day = ui->updateDay->text().toInt();
    int year = ui->updateYear->text().toInt();

    /** Checks if date is a valid date */
    QDate verifyDate(year, month, day);
    QString newDateOpened;

    if(verifyDate.isValid()) {
        newDateOpened = verifyDate.toString("MMMM d, yyyy");
        qDebug() << newDateOpened;
    }
    else {
        valid = false;
        ui->updateDay->setStyleSheet(invalidStyleSheet);
        ui->updateYear->setStyleSheet(invalidStyleSheet);
    }

    /** Verifys if anything was left blank */
    if(isBlank(newStadiumName)) { valid = false; ui->updateStadium->setStyleSheet(invalidStyleSheet); }
    if(isBlank(newTeamName)) { valid = false; ui->updateTeamName->setStyleSheet(invalidStyleSheet); }
    if(isBlank(newBoxOfficeNumber)) { valid = false; ui->updatePhoneNumber->setStyleSheet(invalidStyleSheet); }
    if(isBlank(newTypology)) { valid = false; ui->updateTypology->setStyleSheet(invalidStyleSheet); }
    if(isBlank(newAddress.streetAddress)) { valid = false; ui->updateStreetAddress->setStyleSheet(invalidStyleSheet); }
    if(isBlank(newAddress.city)) { valid = false; ui->updateCity->setStyleSheet(invalidStyleSheet); }
    if(isBlank(newAddress.state)) { valid = false; ui->updateState->setStyleSheet(invalidStyleSheet); }
    if(isBlank(newAddress.zipCode)) { valid = false; ui->updateZipcode->setStyleSheet(invalidStyleSheet); }

    /** Checks if box office number follows the format of (nnn)nnn-nnnn or +1 nnn-nnn-nnnn*/
    QRegExp verifyAmericanBoxOfficeNumber("\\([0-9]{3}\\)[0-9]{3}-{1}[0-9]{4}");
    QRegExp verifyCanadianBoxOfficeNumber("\\+1{1} [0-9]{3}-{1}[0-9]{3}-{1}[0-9]{4}");


    if(!verifyAmericanBoxOfficeNumber.exactMatch(newBoxOfficeNumber)
      && !verifyCanadianBoxOfficeNumber.exactMatch(newBoxOfficeNumber)) {
        valid = false;
        ui->updatePhoneNumber->setStyleSheet(invalidStyleSheet);
    }

    /** If valid, it will update the stadium */
    if(valid) {
        currentStadium->setStadiumName(newStadiumName);
        currentStadium->setTeamName(newTeamName);
        currentStadium->setBoxOfficeNumber(newBoxOfficeNumber);
        currentStadium->setTypology(newTypology);
        currentStadium->setAddress(newAddress);
        currentStadium->setLeagueType(newLeagueType);
        currentStadium->setDateOpened(newDateOpened);
        currentStadium->setSeatingCapacity(newSeatingCapacity);

        /** Updates it in the database */
        db.UpdateStadium(currentStadium);

        currentStadium = NULL;
        on_adminModifyStadiumsButton_clicked();
    }
    else {
        ui->updateStadiumInvalidErrorMessage->show();
    }





}


void MainWindow::on_listOfModifyStadiumsSouvenirs_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    item->setFlags (item->flags () | Qt::ItemIsEditable);
    if(currentStadium != NULL) {
        QString itemName = item->data(0,0).toString();
        currentSouvenir = currentStadium->findSouvenir(itemName);
    }
}


void MainWindow::on_listOfModifyStadiumsSouvenirs_itemChanged(QTreeWidgetItem *item, int column)
{

    if(currentSouvenir != NULL) {
    if(column == 0) {
        QString newName = item->data(0,0).toString();
        QString oldName = currentSouvenir->getName();
        currentSouvenir->setName(newName);

        qDebug() << "Successfully updated souvenir name: " <<
                    db.updateSouvenirName(currentStadium->getStadiumID(), oldName, newName);

    }
    else if(column == 1) {
        QString price = item->data(1, 0).toString();
        QRegExp re("\\$?[0-9]+\\.?[0-9]*");

        if(re.exactMatch(price)) {
            if(price.at(0) == '$') {
                price = price.mid(1,price.size());
        }

            currentSouvenir->setPrice(price.toDouble());

            qDebug() << "Successfully updated souvenir price: " <<
                        db.updateSouvenirPrice(currentStadium->getStadiumID(), currentSouvenir->getName(), price.toDouble());
        }


        item->setText(1, "$" + QString::number(currentSouvenir->getPrice(), 'f', 2));


    }

    currentSouvenir = NULL;
}

}


