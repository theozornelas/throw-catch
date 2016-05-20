#include "../header/mainwindow.h"
#include "ui_mainwindow.h"

#include <QMovie>

/**
 * @brief MainWindow::MainWindow Displays the window of the program.
 *                               Retrieves all needed information from
 *                               the database for this program, such as
 *                               stadiums and a universal global graph of
 *                               all the connecting edges and vertex. The
 *                               constructor also intializes the search bar.
 *
 * @param parent
 */
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

/**
 * @brief MainWindow::~MainWindow Properly closes the window and exits program.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::isBlank A helper method to check if a QString is blank or not.
 * @param text
 * @return T/F if the QString is blank
 */
bool MainWindow::isBlank(QString text) {
    return text.trimmed() == "";
}

/**
 * @brief MainWindow::tripProcess A method that helps initialize every time the user clicks
 *        the button 'next' on their trip. Such as initializing the current stadium their
 *        visiting souvenir's list, along with updating the mileage (how much they have
 *        traveled) and how far they are into the trip (ex. 1/5 stadiums have been visisted).
 * @param trip
 */
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

/**
 * @brief MainWindow::tripProcess2 This method exactly similar to the original trip
 *        process, however their trip process is meant for custom trips only. As it
 *        recursively calls the Dijkstra formula to find the next stadium to visit.
 * @param trip
 */
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

/**
 * @brief MainWindow::on_homePageButton_clicked Trigger for if a user clicks the home button.
 */
void MainWindow::on_homePageButton_clicked()
{
    ui->display->setCurrentIndex(HOME);
}

/**
 * @brief MainWindow::on_viewStadiumByComboBox_currentIndexChanged Checks if a user has selected
 *        to view the list of stadiums based off a view set (ex: Viewing only AMERICAN stadiums).
 * @param arg1
 */
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

/**
 * @brief MainWindow::on_viewStadiumsPageButton_clicked Trigger for if user clicks the
 *        view stadiums button.
 */
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

/**
 * @brief MainWindow::viewStadiumBy A method to help resort the list and excludes
 *        what is requested by the user. Such as only viewing American stadiums.
 * @param sortByType
 * @param stadiumList
 */
void MainWindow::viewStadiumBy(QString sortByType, QVector<Stadium*> stadiumList) {

    ui->viewStadiumsList->clear();

    ui->viewStadiumsList->setColumnWidth(0, 200);
    ui->viewStadiumsList->setColumnWidth(1, 210);
    ui->viewStadiumsList->setColumnWidth(2, 80);
    ui->viewStadiumsList->setColumnWidth(3, 200);
    ui->viewStadiumsList->setColumnWidth(4, 100);
    ui->viewStadiumsList->setColumnWidth(5, 120);
    ui->viewStadiumsList->setColumnWidth(6, 170);

    // Sets the list if user requested stadium to be viewed by a specific view type.
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
        // Sets the list for if the list of stadium is going to be viewed by all.
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

/**
 * @brief MainWindow::on_planATripButton_clicked User has clicked on plan a trip button.
 */
void MainWindow::on_planATripButton_clicked()
{
    ui->display->setCurrentIndex(PLAN_A_TRIP);
}

/**
 * @brief MainWindow::on_customTripButton_clicked User has clicked on the custom trip button.
 */
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

/**
 * @brief MainWindow::on_startingStadiumComboBox_currentIndexChanged Checks if a user has
 *        requested a new stadium to start at, if so the program checked if
 *        the stadium is not already in their trips to visit if so it will swap them.
 * @param arg1
 */
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

/**
 * @brief MainWindow::on_stadiumsToSelectFromList_itemDoubleClicked Allows a user to
 *        double click on a stadium to add to their iternary list.
 * @param item
 * @param column
 */
void MainWindow::on_stadiumsToSelectFromList_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    QString selectedStadiumName = item->text(0);
    QTreeWidgetItem *type = new QTreeWidgetItem(ui->selectedStadiumsList);
    type->setText(0, selectedStadiumName);
    ui->selectedStadiumsList->addTopLevelItem(type);

    delete item;
}

/**
 * @brief MainWindow::on_selectedStadiumsList_itemDoubleClicked Allows a user to double
 *        click on stadiums they have changed their mind on visiting.
 * @param item
 * @param column
 */
void MainWindow::on_selectedStadiumsList_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    QString selectedStadiumName = item->text(0);
    QTreeWidgetItem *type = new QTreeWidgetItem(ui->stadiumsToSelectFromList);
    type->setText(0, selectedStadiumName);
    ui->stadiumsToSelectFromList->addTopLevelItem(type);

    delete item;
}


/**
 * @brief MainWindow::on_minimumSpanningTreeButton_clicked Displays all the distances
 *        from starting stadium Dodger Stadium. User is then allowed to decide which
 *        'quick trip' they would like to take.
 */
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

/**
 * @brief MainWindow::on_shortestTripToAllButton_clicked Also known as the 'quick trip' button.
 *        User clicks on planning a 'quick trip' button.
 */
void MainWindow::on_shortestTripToAllButton_clicked()
{
    ui->display->setCurrentIndex(QUICK_TRIP);

    const QString startingStadiumName = "Dodger Stadium";
    Stadium s = **stadiums.get(db.getStadiumID(startingStadiumName));
    stadiumsGraph->Dijkstra(s);

    ui->quickTripStartingStadium->setText(startingStadiumName);

    ui->quickTripList->clear();

     for(skiplist<int, Stadium*>::Iterator itr = stadiums.begin(); itr != stadiums.end(); itr++) {
        Stadium *s = *stadiums.get(db.getStadiumID((*itr)->getStadiumName()));
        QTreeWidgetItem *currentItem = new QTreeWidgetItem(ui->quickTripList);
        currentItem->setText(0, s->getStadiumName());
        currentItem->setText(1, QString::number(stadiumsGraph->GetDistanceTo(*s)));
    }

     ui->quickTripList->setColumnWidth(0, 250);


}

/**
 * @brief MainWindow::on_adminLoginButton_clicked User has clicked on the log-in button on homepage.
 */
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

/**
 * @brief MainWindow::on_loginButton_clicked User has confirmed their input for username and
 *        password and wants to to log in. This method verifies that the username and password
 *        is correct. For now, program only allows adminstrations to have accounts.
 */
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

/**
 * @brief MainWindow::on_password_returnPressed User has pressed enter after typing
 *        in their password, which then triggers the loginButton_clicked().
 */
void MainWindow::on_password_returnPressed()
{
    on_loginButton_clicked();
}

/**
 * @brief MainWindow::on_adminModifyButton_clicked Modifying souvenirs. Admin clicked on the
 *        button 'modifying souvenirs'. Redirected to a page of a list of stadiums, where they
 *        chould to select a stadium that they would like to modifies it's souvenirs list.
 */
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

/**
 * @brief MainWindow::on_removeSelectedSouvenir_clicked Checks if an admin has selected
 *        their desire souvenir to remove from a stadium's souvenir list.
 */
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

/**
 * @brief MainWindow::on_addSelectedSouvenir_clicked Verifys if admin has put in the
 *        right/proper input fields to create a new souvenir for the current stadium.
 */
void MainWindow::on_addSelectedSouvenir_clicked()
{
    bool valid = true;

    ui->adminAddSouvenirErrorMessage->setVisible(false);

    QString souvenirName = ui->newSouvenirName->text();
    QString souvenirPrice = ui->newSouvenirPrice->text();

    // regular expression ensures that the price matches
    // either $4.00, $4, 4.00, or 4.
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

/**
 * @brief MainWindow::on_confirmCustomTripButton_clicked The user has finish selecting their
 *        desire stadiums to visit, and has requested to take their trip.
 */
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

/**
 * @brief MainWindow::on_quickTripTakeTripButton_clicked User has requested to confirm and take
 *        their quick trip, that starts at Dodger Stadium and visit only ONE other stadium.
 */
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

/**
 * @brief MainWindow::on_shoppingCartButton_clicked During the trip, the user is allowed to
 *        view their shopping cart at any given moment by just clicking the shopping cart icon.
 */
void MainWindow::on_shoppingCartButton_clicked()
{
    ShoppingCart *currentShoppingCart = new ShoppingCart();
    currentShoppingCart->setList(shoppingCart, stadiums);
    currentShoppingCart->show();
    currentShoppingCart->setVisible(true);
    currentShoppingCart->setFocus();
}

/**
 * @brief MainWindow::on_secretAdminLoginButton_clicked If any user on the program
 *        clicks the baseball within throw-catch. It will take them to their login.
 *        Awesome secret login.
 */
void MainWindow::on_secretAdminLoginButton_clicked()
{
    on_adminLoginButton_clicked();
}

/**
 * @brief MainWindow::on_addSouvenirToShoppingCart_clicked During the trip, the user is
 *        allowed to purchase souvenirs, if a user clicks the button 'add to cart' the
 *        item will be added.
 */
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

/**
 * @brief MainWindow::addToCart A helper method to ensure the reqeusted souvenir to be
 *        potentially bought is added to the shopping cart.
 * @param s
 */
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


/**
 * @brief MainWindow::on_currentTripNextStadium_clicked User has reqeusted to travel to the
 *        next Stdaium during their trip proccess.
 */
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

            parent->setText(0, currentStadium);

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
/**
 * @brief MainWindow::on_searchButton_clicked Trigger for if a user clicks the magnifying glass icon
 *        to search for a desired stadium. Calls helper method viewSingleStdaium(...).
 */
void MainWindow::on_searchButton_clicked()
{
    viewSingleStadium(ui->searchBar->text());

    ui->searchBar->clear();
}

/**
 * @brief MainWindow::on_searchBar_returnPressed Also another trigger for searching a stadium, user has
 *        pressed enter instead of clicking the magnifying glass icon.
 */
void MainWindow::on_searchBar_returnPressed()
{
    on_searchButton_clicked();
}

/**
 * @brief MainWindow::viewSingleStadium Helper function to display the page of viewing
 *        a single stadium information. If an admin is currently logged in they have the
 *        capability of viewing a stadium's total revenue. The function also ensures
 *        if a specified stadium is not found, they it will alert the user it wasn't found.
 * @param stadiumName
 */
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

/**
 * @brief MainWindow::on_confirmPurchasesButton_clicked Trigger if user confirms that they
 *        do indeed want to purchase all items in their shopping cart. This method
 *        adds up the total revenue from each stadium and adds it to stadium's total
 *        revenue attribute. This method also verifys the user's purchase and displays
 *        the overall grand total.
 */
void MainWindow::on_confirmPurchasesButton_clicked()
{
    QString stadiumName;
    double totalSpentAtStadium;

    QTreeWidgetItemIterator it(ui->shoppingCart);
    while (*it) {

        stadiumName = (*it)->text(1);
        totalSpentAtStadium = (*it)->text(3).toDouble();
        Stadium *s = *stadiums.get(db.getStadiumID(stadiumName));

        if(s != NULL) {
            qDebug() << totalSpentAtStadium;
            s->addToTotalRevenue(totalSpentAtStadium);
            db.updateTotalRevenue(s->getStadiumID(), s->getTotalRevenue());
        }

      it++;
    }

    /** Clears shopping cart once purchases are confirmed */
    shoppingCart.clear();

    ui->display->setCurrentIndex(HOME);
}

/**
 * @brief MainWindow::on_viewAdminStadiumsButton_clicked Admin has requested to
 *        view a list of stadiums. List of stadiums provide it's name along with
 *        the total revenue.
 */
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

/**
 * @brief MainWindow::on_adminHomeButton_clicked Trigger for if admin home button is clicked.
 */
void MainWindow::on_adminHomeButton_clicked()
{
    ui->display->setCurrentIndex(ADMIN_HOME);
}

/**
 * @brief MainWindow::on_viewMoreInfoAboutStadiumButton_clicked If admin wants to view more
 *        about a stadium, they can select a stadium and view more. Calls helper method
 *        view single stadium, which has all admin functionality of viewing total revenue, etc.
 */
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

/**
 * @brief MainWindow::on_addStadiumFromFileButton_clicked Allow admin to select a json file
 *        and add new stadiums to the list. When a stadium or stadiums is added, it connecting
 *        edges and attributes are not only added to the current global list, but added to
 *        the database for persistent data.
 */
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

/**
 * @brief MainWindow::on_adminModifyStadiumsButton_clicked Trigger for if an admin request to modify a stadium.
 */
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

/**
 * @brief MainWindow::on_updateAStadiumButton_clicked Once button is clicked on,
 *        it redirects the admin to a page of a list of stadiums, where they can
 *        select a stadium to alter it's info.
 */
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


/**
 * @brief MainWindow::on_cancelStadiumUpdatesButton_clicked Admin clicks on 'cancel' when
 *        modifying a stadium, therefore all changes made on that page are ignored.
 */
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

/**
 * @brief MainWindow::on_listOfModifyStadiumsSouvenirs_itemDoubleClicked Allows the user to modify an item
 *        within the current stadium's souvenir list just by clicking then editing the text.
 * @param item
 * @param column
 */
void MainWindow::on_listOfModifyStadiumsSouvenirs_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    item->setFlags (item->flags () | Qt::ItemIsEditable);
    if(currentStadium != NULL) {
        QString itemName = item->data(0,0).toString();
        currentSouvenir = currentStadium->findSouvenir(itemName);
    }
}

/**
 * @brief MainWindow::on_listOfModifyStadiumsSouvenirs_itemChanged A trigger that confirms that a user
 *        has modify a souvenir within a stadium's list and double checks if it is valid input before
 *        confirming that desired change.
 * @param item
 * @param column
 */
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


