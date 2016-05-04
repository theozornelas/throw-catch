/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *options;
    QWidget *customerOptions;
    QFrame *sidebarFrame;
    QPushButton *homePageButton;
    QPushButton *planATripButton;
    QPushButton *viewStadiumsPageButton;
    QWidget *adminOptions;
    QFrame *adminSidebarFrame;
    QPushButton *adminHomeButton;
    QPushButton *adminModifyButton;
    QPushButton *viewAdminStadiumsButton;
    QStackedWidget *display;
    QWidget *homePage;
    QLabel *homeHeading;
    QWidget *viewStadiumsPage;
    QLabel *viewStadiumHeading;
    QTableWidget *viewStadiumsList;
    QWidget *planATripPage;
    QPushButton *shortestTripToAllButton;
    QPushButton *customTripButton;
    QPushButton *minimumSpanningTreeButton;
    QLabel *planATripLabel;
    QWidget *shortestTripToAllPage;
    QLabel *shortestTripToAllLabel;
    QTreeWidget *shortestTripList;
    QLabel *planATripLabel_4;
    QLabel *label_2;
    QWidget *customTripPage;
    QLabel *customTripLabel;
    QTreeWidget *treeWidget_2;
    QTreeWidget *treeWidget_3;
    QPushButton *adminLoginButton_2;
    QLabel *customTripLabel_2;
    QWidget *minimumSpanningTreePage;
    QLabel *planATripLabel_2;
    QTreeWidget *treeWidget;
    QLabel *planATripLabel_3;
    QLabel *label;
    QWidget *adminLoginPage;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QPushButton *loginButton;
    QLineEdit *username;
    QLineEdit *password;
    QLabel *adminLoginErrorMessage;
    QLabel *adminLoginLabel;
    QWidget *adminHomePage;
    QLabel *adminHomePageLabel;
    QWidget *viewAdminStadiumsPage;
    QWidget *adminModifyPage;
    QLabel *modifyInformationLabel;
    QLabel *modifyDescription;
    QTreeWidget *listOfModifyStadiums;
    QPushButton *modifyInformationNextButton;
    QWidget *modifySouvenirItemPage;
    QLabel *modifySouvenirsListLabel;
    QTreeWidget *listOfModifyStadiumsSouvenirs;
    QPushButton *removeSelectedSouvenir;
    QPushButton *addSelectedSouvenir;
    QLabel *newSouvenirNameLabel;
    QLineEdit *newSouvenirName;
    QLabel *newSouvenirPriceLabel;
    QLineEdit *newSouvenirPrice;
    QFrame *headerFrame;
    QLabel *teamNameLabel;
    QPushButton *adminLoginButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(947, 638);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("#centralWidget {\n"
"background-color: #EAEAE9;\n"
"}\n"
"\n"
"#headerFrame {\n"
"background: #8af;\n"
"border: none;\n"
"border-bottom: 1px solid black; }\n"
"\n"
""));
        options = new QStackedWidget(centralWidget);
        options->setObjectName(QStringLiteral("options"));
        options->setGeometry(QRect(0, 20, 201, 621));
        options->setStyleSheet(QLatin1String("QPushButton:hover {\n"
"background-color: #EAEAE9;\n"
"color: #293539;\n"
"}\n"
"\n"
"QPushButton {\n"
"background-color: #293539;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Helvetica\";\n"
"}\n"
""));
        customerOptions = new QWidget();
        customerOptions->setObjectName(QStringLiteral("customerOptions"));
        sidebarFrame = new QFrame(customerOptions);
        sidebarFrame->setObjectName(QStringLiteral("sidebarFrame"));
        sidebarFrame->setGeometry(QRect(0, 12, 201, 613));
        sidebarFrame->setStyleSheet(QLatin1String("#sidebarFrame {\n"
"background: #293539;\n"
"border: none;\n"
"}"));
        sidebarFrame->setFrameShape(QFrame::StyledPanel);
        sidebarFrame->setFrameShadow(QFrame::Raised);
        homePageButton = new QPushButton(sidebarFrame);
        homePageButton->setObjectName(QStringLiteral("homePageButton"));
        homePageButton->setGeometry(QRect(0, 214, 201, 61));
        planATripButton = new QPushButton(sidebarFrame);
        planATripButton->setObjectName(QStringLiteral("planATripButton"));
        planATripButton->setGeometry(QRect(0, 340, 201, 61));
        viewStadiumsPageButton = new QPushButton(sidebarFrame);
        viewStadiumsPageButton->setObjectName(QStringLiteral("viewStadiumsPageButton"));
        viewStadiumsPageButton->setGeometry(QRect(0, 277, 201, 61));
        options->addWidget(customerOptions);
        adminOptions = new QWidget();
        adminOptions->setObjectName(QStringLiteral("adminOptions"));
        adminSidebarFrame = new QFrame(adminOptions);
        adminSidebarFrame->setObjectName(QStringLiteral("adminSidebarFrame"));
        adminSidebarFrame->setGeometry(QRect(0, 10, 201, 613));
        adminSidebarFrame->setStyleSheet(QLatin1String("#adminSidebarFrame {\n"
"background: #293539;\n"
"border: none;\n"
"}"));
        adminSidebarFrame->setFrameShape(QFrame::StyledPanel);
        adminSidebarFrame->setFrameShadow(QFrame::Raised);
        adminHomeButton = new QPushButton(adminSidebarFrame);
        adminHomeButton->setObjectName(QStringLiteral("adminHomeButton"));
        adminHomeButton->setGeometry(QRect(0, 214, 201, 61));
        adminModifyButton = new QPushButton(adminSidebarFrame);
        adminModifyButton->setObjectName(QStringLiteral("adminModifyButton"));
        adminModifyButton->setGeometry(QRect(0, 340, 201, 61));
        viewAdminStadiumsButton = new QPushButton(adminSidebarFrame);
        viewAdminStadiumsButton->setObjectName(QStringLiteral("viewAdminStadiumsButton"));
        viewAdminStadiumsButton->setGeometry(QRect(0, 277, 201, 61));
        options->addWidget(adminOptions);
        display = new QStackedWidget(centralWidget);
        display->setObjectName(QStringLiteral("display"));
        display->setGeometry(QRect(203, 40, 801, 596));
        display->setStyleSheet(QLatin1String("\n"
"background-color: #EAEAE9\n"
""));
        homePage = new QWidget();
        homePage->setObjectName(QStringLiteral("homePage"));
        homeHeading = new QLabel(homePage);
        homeHeading->setObjectName(QStringLiteral("homeHeading"));
        homeHeading->setGeometry(QRect(20, 20, 201, 31));
        homeHeading->setStyleSheet(QLatin1String("font: 75 30pt \"Gill Sans\";\n"
""));
        display->addWidget(homePage);
        viewStadiumsPage = new QWidget();
        viewStadiumsPage->setObjectName(QStringLiteral("viewStadiumsPage"));
        viewStadiumHeading = new QLabel(viewStadiumsPage);
        viewStadiumHeading->setObjectName(QStringLiteral("viewStadiumHeading"));
        viewStadiumHeading->setGeometry(QRect(20, 10, 311, 41));
        viewStadiumHeading->setStyleSheet(QLatin1String("	font: 75 30pt \"Gill Sans\";\n"
""));
        viewStadiumsList = new QTableWidget(viewStadiumsPage);
        if (viewStadiumsList->columnCount() < 7)
            viewStadiumsList->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        viewStadiumsList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        viewStadiumsList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        viewStadiumsList->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        viewStadiumsList->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        viewStadiumsList->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        viewStadiumsList->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        viewStadiumsList->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        viewStadiumsList->setObjectName(QStringLiteral("viewStadiumsList"));
        viewStadiumsList->setGeometry(QRect(20, 160, 702, 421));
        viewStadiumsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        viewStadiumsList->setSortingEnabled(true);
        display->addWidget(viewStadiumsPage);
        planATripPage = new QWidget();
        planATripPage->setObjectName(QStringLiteral("planATripPage"));
        planATripPage->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #90A4AE;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Helvetica\";\n"
"}"));
        shortestTripToAllButton = new QPushButton(planATripPage);
        shortestTripToAllButton->setObjectName(QStringLiteral("shortestTripToAllButton"));
        shortestTripToAllButton->setGeometry(QRect(180, 160, 411, 61));
        customTripButton = new QPushButton(planATripPage);
        customTripButton->setObjectName(QStringLiteral("customTripButton"));
        customTripButton->setGeometry(QRect(180, 230, 411, 61));
        minimumSpanningTreeButton = new QPushButton(planATripPage);
        minimumSpanningTreeButton->setObjectName(QStringLiteral("minimumSpanningTreeButton"));
        minimumSpanningTreeButton->setGeometry(QRect(180, 300, 411, 61));
        planATripLabel = new QLabel(planATripPage);
        planATripLabel->setObjectName(QStringLiteral("planATripLabel"));
        planATripLabel->setGeometry(QRect(20, 10, 311, 41));
        planATripLabel->setStyleSheet(QLatin1String("	font: 75 30pt \"Gill Sans\";\n"
""));
        display->addWidget(planATripPage);
        shortestTripToAllPage = new QWidget();
        shortestTripToAllPage->setObjectName(QStringLiteral("shortestTripToAllPage"));
        shortestTripToAllLabel = new QLabel(shortestTripToAllPage);
        shortestTripToAllLabel->setObjectName(QStringLiteral("shortestTripToAllLabel"));
        shortestTripToAllLabel->setGeometry(QRect(20, 10, 311, 41));
        shortestTripToAllLabel->setStyleSheet(QLatin1String("	font: 75 30pt \"Gill Sans\";\n"
""));
        shortestTripList = new QTreeWidget(shortestTripToAllPage);
        shortestTripList->setObjectName(QStringLiteral("shortestTripList"));
        shortestTripList->setGeometry(QRect(230, 100, 261, 251));
        shortestTripList->setAlternatingRowColors(true);
        shortestTripList->header()->setCascadingSectionResizes(true);
        shortestTripList->header()->setDefaultSectionSize(150);
        shortestTripList->header()->setStretchLastSection(true);
        planATripLabel_4 = new QLabel(shortestTripToAllPage);
        planATripLabel_4->setObjectName(QStringLiteral("planATripLabel_4"));
        planATripLabel_4->setGeometry(QRect(230, 360, 111, 41));
        planATripLabel_4->setStyleSheet(QLatin1String("	font: 75 20pt \"Gill Sans\";\n"
""));
        label_2 = new QLabel(shortestTripToAllPage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(350, 372, 81, 20));
        QFont font;
        font.setPointSize(14);
        label_2->setFont(font);
        display->addWidget(shortestTripToAllPage);
        customTripPage = new QWidget();
        customTripPage->setObjectName(QStringLiteral("customTripPage"));
        customTripLabel = new QLabel(customTripPage);
        customTripLabel->setObjectName(QStringLiteral("customTripLabel"));
        customTripLabel->setGeometry(QRect(20, 10, 311, 41));
        customTripLabel->setStyleSheet(QLatin1String("	font: 75 30pt \"Gill Sans\";\n"
""));
        treeWidget_2 = new QTreeWidget(customTripPage);
        treeWidget_2->setObjectName(QStringLiteral("treeWidget_2"));
        treeWidget_2->setGeometry(QRect(80, 120, 256, 261));
        treeWidget_3 = new QTreeWidget(customTripPage);
        treeWidget_3->setObjectName(QStringLiteral("treeWidget_3"));
        treeWidget_3->setGeometry(QRect(410, 120, 256, 251));
        adminLoginButton_2 = new QPushButton(customTripPage);
        adminLoginButton_2->setObjectName(QStringLiteral("adminLoginButton_2"));
        adminLoginButton_2->setGeometry(QRect(580, 510, 121, 31));
        adminLoginButton_2->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #293539;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Helvetica\";\n"
"}"));
        customTripLabel_2 = new QLabel(customTripPage);
        customTripLabel_2->setObjectName(QStringLiteral("customTripLabel_2"));
        customTripLabel_2->setGeometry(QRect(350, 190, 51, 71));
        QFont font1;
        font1.setFamily(QStringLiteral("Geneva"));
        font1.setPointSize(30);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        customTripLabel_2->setFont(font1);
        customTripLabel_2->setStyleSheet(QStringLiteral(""));
        display->addWidget(customTripPage);
        minimumSpanningTreePage = new QWidget();
        minimumSpanningTreePage->setObjectName(QStringLiteral("minimumSpanningTreePage"));
        planATripLabel_2 = new QLabel(minimumSpanningTreePage);
        planATripLabel_2->setObjectName(QStringLiteral("planATripLabel_2"));
        planATripLabel_2->setGeometry(QRect(20, 20, 371, 41));
        planATripLabel_2->setStyleSheet(QLatin1String("	font: 75 30pt \"Gill Sans\";\n"
""));
        treeWidget = new QTreeWidget(minimumSpanningTreePage);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(200, 80, 391, 291));
        treeWidget->header()->setDefaultSectionSize(120);
        planATripLabel_3 = new QLabel(minimumSpanningTreePage);
        planATripLabel_3->setObjectName(QStringLiteral("planATripLabel_3"));
        planATripLabel_3->setGeometry(QRect(200, 370, 101, 41));
        planATripLabel_3->setStyleSheet(QLatin1String("	font: 75 20pt \"Gill Sans\";\n"
""));
        label = new QLabel(minimumSpanningTreePage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 381, 81, 20));
        label->setFont(font);
        display->addWidget(minimumSpanningTreePage);
        adminLoginPage = new QWidget();
        adminLoginPage->setObjectName(QStringLiteral("adminLoginPage"));
        usernameLabel = new QLabel(adminLoginPage);
        usernameLabel->setObjectName(QStringLiteral("usernameLabel"));
        usernameLabel->setGeometry(QRect(200, 180, 81, 16));
        passwordLabel = new QLabel(adminLoginPage);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setGeometry(QRect(200, 240, 59, 16));
        loginButton = new QPushButton(adminLoginPage);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(320, 330, 113, 32));
        loginButton->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #293539;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Helvetica\";\n"
"}"));
        username = new QLineEdit(adminLoginPage);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(280, 180, 211, 31));
        password = new QLineEdit(adminLoginPage);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(280, 230, 211, 31));
        password->setEchoMode(QLineEdit::Password);
        adminLoginErrorMessage = new QLabel(adminLoginPage);
        adminLoginErrorMessage->setObjectName(QStringLiteral("adminLoginErrorMessage"));
        adminLoginErrorMessage->setGeometry(QRect(280, 280, 241, 20));
        adminLoginErrorMessage->setStyleSheet(QStringLiteral("color: #01CDE6"));
        adminLoginLabel = new QLabel(adminLoginPage);
        adminLoginLabel->setObjectName(QStringLiteral("adminLoginLabel"));
        adminLoginLabel->setGeometry(QRect(20, 20, 311, 41));
        adminLoginLabel->setStyleSheet(QLatin1String("	font: 75 30pt \"Gill Sans\";\n"
""));
        display->addWidget(adminLoginPage);
        adminHomePage = new QWidget();
        adminHomePage->setObjectName(QStringLiteral("adminHomePage"));
        adminHomePageLabel = new QLabel(adminHomePage);
        adminHomePageLabel->setObjectName(QStringLiteral("adminHomePageLabel"));
        adminHomePageLabel->setGeometry(QRect(20, 10, 311, 41));
        adminHomePageLabel->setStyleSheet(QLatin1String("	font: 75 30pt \"Gill Sans\";\n"
""));
        display->addWidget(adminHomePage);
        viewAdminStadiumsPage = new QWidget();
        viewAdminStadiumsPage->setObjectName(QStringLiteral("viewAdminStadiumsPage"));
        display->addWidget(viewAdminStadiumsPage);
        adminModifyPage = new QWidget();
        adminModifyPage->setObjectName(QStringLiteral("adminModifyPage"));
        modifyInformationLabel = new QLabel(adminModifyPage);
        modifyInformationLabel->setObjectName(QStringLiteral("modifyInformationLabel"));
        modifyInformationLabel->setGeometry(QRect(10, 10, 311, 41));
        modifyInformationLabel->setStyleSheet(QLatin1String("	font: 75 30pt \"Gill Sans\";\n"
""));
        modifyDescription = new QLabel(adminModifyPage);
        modifyDescription->setObjectName(QStringLiteral("modifyDescription"));
        modifyDescription->setGeometry(QRect(70, 50, 441, 21));
        listOfModifyStadiums = new QTreeWidget(adminModifyPage);
        listOfModifyStadiums->setObjectName(QStringLiteral("listOfModifyStadiums"));
        listOfModifyStadiums->setGeometry(QRect(70, 100, 431, 241));
        listOfModifyStadiums->setAlternatingRowColors(true);
        modifyInformationNextButton = new QPushButton(adminModifyPage);
        modifyInformationNextButton->setObjectName(QStringLiteral("modifyInformationNextButton"));
        modifyInformationNextButton->setGeometry(QRect(390, 360, 113, 32));
        modifyInformationNextButton->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #293539;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Helvetica\";\n"
"}"));
        display->addWidget(adminModifyPage);
        modifySouvenirItemPage = new QWidget();
        modifySouvenirItemPage->setObjectName(QStringLiteral("modifySouvenirItemPage"));
        modifySouvenirsListLabel = new QLabel(modifySouvenirItemPage);
        modifySouvenirsListLabel->setObjectName(QStringLiteral("modifySouvenirsListLabel"));
        modifySouvenirsListLabel->setGeometry(QRect(20, 10, 311, 41));
        modifySouvenirsListLabel->setStyleSheet(QLatin1String("	font: 75 30pt \"Gill Sans\";\n"
""));
        listOfModifyStadiumsSouvenirs = new QTreeWidget(modifySouvenirItemPage);
        listOfModifyStadiumsSouvenirs->setObjectName(QStringLiteral("listOfModifyStadiumsSouvenirs"));
        listOfModifyStadiumsSouvenirs->setGeometry(QRect(30, 60, 521, 311));
        listOfModifyStadiumsSouvenirs->setAlternatingRowColors(true);
        listOfModifyStadiumsSouvenirs->header()->setDefaultSectionSize(150);
        removeSelectedSouvenir = new QPushButton(modifySouvenirItemPage);
        removeSelectedSouvenir->setObjectName(QStringLiteral("removeSelectedSouvenir"));
        removeSelectedSouvenir->setGeometry(QRect(460, 30, 91, 20));
        removeSelectedSouvenir->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #293539;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Helvetica\";\n"
"}"));
        addSelectedSouvenir = new QPushButton(modifySouvenirItemPage);
        addSelectedSouvenir->setObjectName(QStringLiteral("addSelectedSouvenir"));
        addSelectedSouvenir->setGeometry(QRect(470, 380, 81, 21));
        addSelectedSouvenir->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #293539;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Helvetica\";\n"
"}"));
        newSouvenirNameLabel = new QLabel(modifySouvenirItemPage);
        newSouvenirNameLabel->setObjectName(QStringLiteral("newSouvenirNameLabel"));
        newSouvenirNameLabel->setGeometry(QRect(30, 380, 59, 16));
        newSouvenirName = new QLineEdit(modifySouvenirItemPage);
        newSouvenirName->setObjectName(QStringLiteral("newSouvenirName"));
        newSouvenirName->setGeometry(QRect(80, 380, 151, 21));
        newSouvenirPriceLabel = new QLabel(modifySouvenirItemPage);
        newSouvenirPriceLabel->setObjectName(QStringLiteral("newSouvenirPriceLabel"));
        newSouvenirPriceLabel->setGeometry(QRect(260, 380, 59, 16));
        newSouvenirPrice = new QLineEdit(modifySouvenirItemPage);
        newSouvenirPrice->setObjectName(QStringLiteral("newSouvenirPrice"));
        newSouvenirPrice->setGeometry(QRect(300, 380, 151, 21));
        display->addWidget(modifySouvenirItemPage);
        headerFrame = new QFrame(centralWidget);
        headerFrame->setObjectName(QStringLiteral("headerFrame"));
        headerFrame->setGeometry(QRect(0, 0, 951, 41));
        headerFrame->setStyleSheet(QLatin1String("#headerFrame {\n"
"background: #01CDE6;\n"
"border: none;\n"
"}"));
        headerFrame->setFrameShape(QFrame::StyledPanel);
        headerFrame->setFrameShadow(QFrame::Raised);
        teamNameLabel = new QLabel(headerFrame);
        teamNameLabel->setObjectName(QStringLiteral("teamNameLabel"));
        teamNameLabel->setGeometry(QRect(10, 10, 161, 21));
        teamNameLabel->setStyleSheet(QLatin1String("#teamNameLabel {\n"
"color: white;\n"
"	font: 75 30pt \"Gill Sans\";\n"
"}"));
        adminLoginButton = new QPushButton(headerFrame);
        adminLoginButton->setObjectName(QStringLiteral("adminLoginButton"));
        adminLoginButton->setGeometry(QRect(840, 10, 91, 21));
        adminLoginButton->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #293539;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Helvetica\";\n"
"}"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        homePageButton->setText(QApplication::translate("MainWindow", "HOME", 0));
        planATripButton->setText(QApplication::translate("MainWindow", "PLAN A TRIP", 0));
        viewStadiumsPageButton->setText(QApplication::translate("MainWindow", "VIEW STADIUMS", 0));
        adminHomeButton->setText(QApplication::translate("MainWindow", "HOME", 0));
        adminModifyButton->setText(QApplication::translate("MainWindow", "MODIFY SOUVENIRS", 0));
        viewAdminStadiumsButton->setText(QApplication::translate("MainWindow", "VIEW STADIUMS", 0));
        homeHeading->setText(QApplication::translate("MainWindow", "HOME", 0));
        viewStadiumHeading->setText(QApplication::translate("MainWindow", "VIEW STADIUMS", 0));
        QTableWidgetItem *___qtablewidgetitem = viewStadiumsList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Stadium", 0));
        QTableWidgetItem *___qtablewidgetitem1 = viewStadiumsList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem2 = viewStadiumsList->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Seating Capacity", 0));
        QTableWidgetItem *___qtablewidgetitem3 = viewStadiumsList->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Location", 0));
        QTableWidgetItem *___qtablewidgetitem4 = viewStadiumsList->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Surface", 0));
        QTableWidgetItem *___qtablewidgetitem5 = viewStadiumsList->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Date Opened", 0));
        QTableWidgetItem *___qtablewidgetitem6 = viewStadiumsList->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Typology", 0));
        shortestTripToAllButton->setText(QApplication::translate("MainWindow", "SHORTEST TRIP TO ALL", 0));
        customTripButton->setText(QApplication::translate("MainWindow", "CUSTOM TRIP", 0));
        minimumSpanningTreeButton->setText(QApplication::translate("MainWindow", "GENERATE MINIMUM SPANNING TREE", 0));
        planATripLabel->setText(QApplication::translate("MainWindow", "PLAN A TRIP", 0));
        shortestTripToAllLabel->setText(QApplication::translate("MainWindow", "SHORTEST TRIP TO ALL", 0));
        QTreeWidgetItem *___qtreewidgetitem = shortestTripList->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Distance to next", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Stadium", 0));
        planATripLabel_4->setText(QApplication::translate("MainWindow", "total distance:", 0));
        label_2->setText(QApplication::translate("MainWindow", "--- miles", 0));
        customTripLabel->setText(QApplication::translate("MainWindow", "PLAN CUSTOM TRIP", 0));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget_2->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Stadiums", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget_3->headerItem();
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "Stadiums to travel to", 0));
        adminLoginButton_2->setText(QApplication::translate("MainWindow", "TAKE TRIP", 0));
        customTripLabel_2->setText(QApplication::translate("MainWindow", "-->\n"
"<--", 0));
        planATripLabel_2->setText(QApplication::translate("MainWindow", "MINIMUM SPANNING TREE", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget->headerItem();
        ___qtreewidgetitem3->setText(2, QApplication::translate("MainWindow", "weight", 0));
        ___qtreewidgetitem3->setText(1, QApplication::translate("MainWindow", "destination", 0));
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "origin", 0));
        planATripLabel_3->setText(QApplication::translate("MainWindow", "total weight:", 0));
        label->setText(QApplication::translate("MainWindow", "---- miles", 0));
        usernameLabel->setText(QApplication::translate("MainWindow", "Username", 0));
        passwordLabel->setText(QApplication::translate("MainWindow", "Password", 0));
        loginButton->setText(QApplication::translate("MainWindow", "LOGIN", 0));
        adminLoginErrorMessage->setText(QApplication::translate("MainWindow", "Invalid username or password.", 0));
        adminLoginLabel->setText(QApplication::translate("MainWindow", "ADMIN LOGIN", 0));
        adminHomePageLabel->setText(QApplication::translate("MainWindow", "ADMIN HOME PAGE", 0));
        modifyInformationLabel->setText(QApplication::translate("MainWindow", "MODIFY INFORMATION", 0));
        modifyDescription->setText(QApplication::translate("MainWindow", "Select a stadium you would like to modify t's list of souvenirs", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = listOfModifyStadiums->headerItem();
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "Stadium", 0));
        modifyInformationNextButton->setText(QApplication::translate("MainWindow", "NEXT", 0));
        modifySouvenirsListLabel->setText(QApplication::translate("MainWindow", "SOUVENIRS", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = listOfModifyStadiumsSouvenirs->headerItem();
        ___qtreewidgetitem5->setText(1, QApplication::translate("MainWindow", "Price", 0));
        ___qtreewidgetitem5->setText(0, QApplication::translate("MainWindow", "Name", 0));
        removeSelectedSouvenir->setText(QApplication::translate("MainWindow", "DELETE", 0));
        addSelectedSouvenir->setText(QApplication::translate("MainWindow", "ADD", 0));
        newSouvenirNameLabel->setText(QApplication::translate("MainWindow", "Name:", 0));
        newSouvenirPriceLabel->setText(QApplication::translate("MainWindow", "Price", 0));
        teamNameLabel->setText(QApplication::translate("MainWindow", "throw-catch", 0));
        adminLoginButton->setText(QApplication::translate("MainWindow", "SIGN IN", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
