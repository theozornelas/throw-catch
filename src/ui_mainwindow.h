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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
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
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QWidget *viewSingleStadiumPage;
    QLabel *singleStadiumNameLabel;
    QFrame *singleStadiumInfo;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *singleStadiumLayoutLabels;
    QLabel *label_9;
    QLabel *label_12;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *singleStadiumLayoutInfo;
    QLabel *singleStadiumTeamName;
    QLabel *singleStadiumType;
    QLabel *singleStadiumAddress;
    QLabel *singleStadiumBoxOfficeNum;
    QLabel *singleStadiumDateOpened;
    QLabel *singleStadiumSeatingCapacity;
    QLabel *singleStadiumSurface;
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
    QTreeWidget *stadiumsToSelectFromList;
    QTreeWidget *selectedStadiumsList;
    QPushButton *confirmCustomTripButton;
    QLabel *arrows;
    QLabel *startingStadiumLabel;
    QComboBox *startingStadiumComboBox;
    QWidget *minimumSpanningTreePage;
    QLabel *planATripLabel_2;
    QTreeWidget *MSTList;
    QLabel *planATripLabel_3;
    QLabel *label;
    QWidget *tripProcessPage;
    QLabel *currentTripStadiumNameLabel;
    QPushButton *addSouvenirToShoppingCart;
    QLabel *currentTripWelcomeDescription;
    QTreeWidget *listOfCurrentStadiumSouvenirs;
    QLabel *currentTripNextButtonLabel;
    QLabel *currentTripSouvenirLabel;
    QPushButton *currentTripNextStadium;
    QPushButton *shoppingCartButton;
    QProgressBar *currentTripProgressBar;
    QLabel *currentTripProgressLabel;
    QLabel *currentTripStadiumCount;
    QWidget *confrimPurchasesPage;
    QLabel *confirmPurchasesLabel;
    QLabel *grandTotalLabel;
    QLabel *grandTotalAmount;
    QTreeWidget *shoppingCart;
    QLabel *shoppingCartLabel;
    QPushButton *confirmPurchasesButton;
    QPushButton *updateShoppingCart;
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
    QTreeWidget *adminStadiumList;
    QLabel *adminHomePageLabel_2;
    QPushButton *confirmPurchasesButton_2;
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
    QWidget *adminViewStadiumsPage;
    QFrame *headerFrame;
    QLabel *teamNameLabel;
    QPushButton *adminLoginButton;
    QLineEdit *searchBar;
    QToolButton *searchButton;
    QToolButton *secretAdminLoginButton;

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
        label_3 = new QLabel(viewStadiumsPage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 60, 59, 16));
        label_4 = new QLabel(viewStadiumsPage);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 100, 59, 16));
        comboBox = new QComboBox(viewStadiumsPage);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(80, 56, 171, 26));
        display->addWidget(viewStadiumsPage);
        viewSingleStadiumPage = new QWidget();
        viewSingleStadiumPage->setObjectName(QStringLiteral("viewSingleStadiumPage"));
        singleStadiumNameLabel = new QLabel(viewSingleStadiumPage);
        singleStadiumNameLabel->setObjectName(QStringLiteral("singleStadiumNameLabel"));
        singleStadiumNameLabel->setGeometry(QRect(20, 10, 661, 41));
        singleStadiumNameLabel->setStyleSheet(QLatin1String("	font: 75 30pt \"Gill Sans\";\n"
""));
        singleStadiumInfo = new QFrame(viewSingleStadiumPage);
        singleStadiumInfo->setObjectName(QStringLiteral("singleStadiumInfo"));
        singleStadiumInfo->setGeometry(QRect(20, 70, 451, 381));
        singleStadiumInfo->setStyleSheet(QStringLiteral("border: none;"));
        singleStadiumInfo->setFrameShape(QFrame::StyledPanel);
        singleStadiumInfo->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(singleStadiumInfo);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 131, 351));
        singleStadiumLayoutLabels = new QVBoxLayout(verticalLayoutWidget);
        singleStadiumLayoutLabels->setSpacing(6);
        singleStadiumLayoutLabels->setContentsMargins(11, 11, 11, 11);
        singleStadiumLayoutLabels->setObjectName(QStringLiteral("singleStadiumLayoutLabels"));
        singleStadiumLayoutLabels->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_9->setFont(font);

        singleStadiumLayoutLabels->addWidget(label_9);

        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);

        singleStadiumLayoutLabels->addWidget(label_12);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        singleStadiumLayoutLabels->addWidget(label_8);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        singleStadiumLayoutLabels->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        singleStadiumLayoutLabels->addWidget(label_6);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        singleStadiumLayoutLabels->addWidget(label_10);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        singleStadiumLayoutLabels->addWidget(label_11);

        verticalLayoutWidget_2 = new QWidget(singleStadiumInfo);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(160, 10, 271, 351));
        singleStadiumLayoutInfo = new QVBoxLayout(verticalLayoutWidget_2);
        singleStadiumLayoutInfo->setSpacing(6);
        singleStadiumLayoutInfo->setContentsMargins(11, 11, 11, 11);
        singleStadiumLayoutInfo->setObjectName(QStringLiteral("singleStadiumLayoutInfo"));
        singleStadiumLayoutInfo->setContentsMargins(0, 0, 0, 0);
        singleStadiumTeamName = new QLabel(verticalLayoutWidget_2);
        singleStadiumTeamName->setObjectName(QStringLiteral("singleStadiumTeamName"));

        singleStadiumLayoutInfo->addWidget(singleStadiumTeamName);

        singleStadiumType = new QLabel(verticalLayoutWidget_2);
        singleStadiumType->setObjectName(QStringLiteral("singleStadiumType"));

        singleStadiumLayoutInfo->addWidget(singleStadiumType);

        singleStadiumAddress = new QLabel(verticalLayoutWidget_2);
        singleStadiumAddress->setObjectName(QStringLiteral("singleStadiumAddress"));
        QFont font1;
        font1.setPointSize(13);
        font1.setKerning(true);
        singleStadiumAddress->setFont(font1);
        singleStadiumAddress->setStyleSheet(QStringLiteral(""));
        singleStadiumAddress->setWordWrap(false);

        singleStadiumLayoutInfo->addWidget(singleStadiumAddress);

        singleStadiumBoxOfficeNum = new QLabel(verticalLayoutWidget_2);
        singleStadiumBoxOfficeNum->setObjectName(QStringLiteral("singleStadiumBoxOfficeNum"));

        singleStadiumLayoutInfo->addWidget(singleStadiumBoxOfficeNum);

        singleStadiumDateOpened = new QLabel(verticalLayoutWidget_2);
        singleStadiumDateOpened->setObjectName(QStringLiteral("singleStadiumDateOpened"));

        singleStadiumLayoutInfo->addWidget(singleStadiumDateOpened);

        singleStadiumSeatingCapacity = new QLabel(verticalLayoutWidget_2);
        singleStadiumSeatingCapacity->setObjectName(QStringLiteral("singleStadiumSeatingCapacity"));

        singleStadiumLayoutInfo->addWidget(singleStadiumSeatingCapacity);

        singleStadiumSurface = new QLabel(verticalLayoutWidget_2);
        singleStadiumSurface->setObjectName(QStringLiteral("singleStadiumSurface"));

        singleStadiumLayoutInfo->addWidget(singleStadiumSurface);

        display->addWidget(viewSingleStadiumPage);
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
        shortestTripList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        shortestTripList->setAlternatingRowColors(true);
        shortestTripList->header()->setCascadingSectionResizes(false);
        shortestTripList->header()->setDefaultSectionSize(150);
        shortestTripList->header()->setStretchLastSection(false);
        planATripLabel_4 = new QLabel(shortestTripToAllPage);
        planATripLabel_4->setObjectName(QStringLiteral("planATripLabel_4"));
        planATripLabel_4->setGeometry(QRect(230, 360, 111, 41));
        planATripLabel_4->setStyleSheet(QLatin1String("	font: 75 20pt \"Gill Sans\";\n"
""));
        label_2 = new QLabel(shortestTripToAllPage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(350, 372, 81, 20));
        QFont font2;
        font2.setPointSize(14);
        label_2->setFont(font2);
        display->addWidget(shortestTripToAllPage);
        customTripPage = new QWidget();
        customTripPage->setObjectName(QStringLiteral("customTripPage"));
        customTripLabel = new QLabel(customTripPage);
        customTripLabel->setObjectName(QStringLiteral("customTripLabel"));
        customTripLabel->setGeometry(QRect(20, 10, 311, 41));
        customTripLabel->setStyleSheet(QLatin1String("	font: 75 30pt \"Gill Sans\";\n"
""));
        stadiumsToSelectFromList = new QTreeWidget(customTripPage);
        stadiumsToSelectFromList->setObjectName(QStringLiteral("stadiumsToSelectFromList"));
        stadiumsToSelectFromList->setGeometry(QRect(80, 160, 256, 261));
        selectedStadiumsList = new QTreeWidget(customTripPage);
        selectedStadiumsList->setObjectName(QStringLiteral("selectedStadiumsList"));
        selectedStadiumsList->setGeometry(QRect(410, 160, 256, 251));
        confirmCustomTripButton = new QPushButton(customTripPage);
        confirmCustomTripButton->setObjectName(QStringLiteral("confirmCustomTripButton"));
        confirmCustomTripButton->setGeometry(QRect(580, 510, 121, 31));
        confirmCustomTripButton->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #293539;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Helvetica\";\n"
"}"));
        arrows = new QLabel(customTripPage);
        arrows->setObjectName(QStringLiteral("arrows"));
        arrows->setGeometry(QRect(350, 230, 51, 71));
        QFont font3;
        font3.setFamily(QStringLiteral("Geneva"));
        font3.setPointSize(30);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        arrows->setFont(font3);
        arrows->setStyleSheet(QStringLiteral(""));
        startingStadiumLabel = new QLabel(customTripPage);
        startingStadiumLabel->setObjectName(QStringLiteral("startingStadiumLabel"));
        startingStadiumLabel->setGeometry(QRect(80, 100, 221, 16));
        startingStadiumComboBox = new QComboBox(customTripPage);
        startingStadiumComboBox->setObjectName(QStringLiteral("startingStadiumComboBox"));
        startingStadiumComboBox->setGeometry(QRect(310, 95, 201, 26));
        startingStadiumComboBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        startingStadiumComboBox->setLayoutDirection(Qt::LeftToRight);
        startingStadiumComboBox->setStyleSheet(QLatin1String("QComboBox::down-arrow {\n"
"		image: url(\"/Users/sarahsingletary/Documents/throw-catch/src/icons/down_arrow.png\");\n"
"}\n"
"\n"
"QComboBox{\n"
" border: 0px solid   rgb(53, 53, 53);\n"
" background-color: rgb(255, 255, 255);\n"
" color:                      rgb(53, 53, 53); \n"
" padding:                    5px \n"
"\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"        border: 1px solid #5A5A5A;\n"
"        background: #353535;\n"
"    color:                      white;\n"
"    font-weight:            bold;\n"
"    padding:                    0px;\n"
"}\n"
"\n"
"\n"
""));
        startingStadiumComboBox->setMaxVisibleItems(5);
        startingStadiumComboBox->setInsertPolicy(QComboBox::InsertAtBottom);
        startingStadiumComboBox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);
        startingStadiumComboBox->setFrame(true);
        display->addWidget(customTripPage);
        minimumSpanningTreePage = new QWidget();
        minimumSpanningTreePage->setObjectName(QStringLiteral("minimumSpanningTreePage"));
        planATripLabel_2 = new QLabel(minimumSpanningTreePage);
        planATripLabel_2->setObjectName(QStringLiteral("planATripLabel_2"));
        planATripLabel_2->setGeometry(QRect(20, 20, 371, 41));
        planATripLabel_2->setStyleSheet(QLatin1String("	font: 75 30pt \"Gill Sans\";\n"
""));
        MSTList = new QTreeWidget(minimumSpanningTreePage);
        MSTList->setObjectName(QStringLiteral("MSTList"));
        MSTList->setGeometry(QRect(50, 80, 621, 291));
        MSTList->header()->setDefaultSectionSize(120);
        planATripLabel_3 = new QLabel(minimumSpanningTreePage);
        planATripLabel_3->setObjectName(QStringLiteral("planATripLabel_3"));
        planATripLabel_3->setGeometry(QRect(200, 370, 101, 41));
        planATripLabel_3->setStyleSheet(QLatin1String("	font: 75 20pt \"Gill Sans\";\n"
""));
        label = new QLabel(minimumSpanningTreePage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 381, 81, 20));
        label->setFont(font2);
        display->addWidget(minimumSpanningTreePage);
        tripProcessPage = new QWidget();
        tripProcessPage->setObjectName(QStringLiteral("tripProcessPage"));
        currentTripStadiumNameLabel = new QLabel(tripProcessPage);
        currentTripStadiumNameLabel->setObjectName(QStringLiteral("currentTripStadiumNameLabel"));
        currentTripStadiumNameLabel->setGeometry(QRect(20, 10, 431, 61));
        currentTripStadiumNameLabel->setStyleSheet(QLatin1String("font: 75 30pt \"Gill Sans\";\n"
""));
        addSouvenirToShoppingCart = new QPushButton(tripProcessPage);
        addSouvenirToShoppingCart->setObjectName(QStringLiteral("addSouvenirToShoppingCart"));
        addSouvenirToShoppingCart->setGeometry(QRect(280, 390, 121, 31));
        addSouvenirToShoppingCart->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #293539;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Helvetica\";\n"
"}"));
        currentTripWelcomeDescription = new QLabel(tripProcessPage);
        currentTripWelcomeDescription->setObjectName(QStringLiteral("currentTripWelcomeDescription"));
        currentTripWelcomeDescription->setGeometry(QRect(60, 60, 331, 31));
        currentTripWelcomeDescription->setFont(font2);
        currentTripWelcomeDescription->setWordWrap(true);
        listOfCurrentStadiumSouvenirs = new QTreeWidget(tripProcessPage);
        listOfCurrentStadiumSouvenirs->setObjectName(QStringLiteral("listOfCurrentStadiumSouvenirs"));
        listOfCurrentStadiumSouvenirs->setGeometry(QRect(40, 160, 361, 221));
        listOfCurrentStadiumSouvenirs->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listOfCurrentStadiumSouvenirs->header()->setDefaultSectionSize(133);
        currentTripNextButtonLabel = new QLabel(tripProcessPage);
        currentTripNextButtonLabel->setObjectName(QStringLiteral("currentTripNextButtonLabel"));
        currentTripNextButtonLabel->setGeometry(QRect(430, 520, 141, 41));
        currentTripNextButtonLabel->setWordWrap(true);
        currentTripSouvenirLabel = new QLabel(tripProcessPage);
        currentTripSouvenirLabel->setObjectName(QStringLiteral("currentTripSouvenirLabel"));
        currentTripSouvenirLabel->setGeometry(QRect(40, 130, 111, 21));
        QFont font4;
        font4.setFamily(QStringLiteral("Gill Sans"));
        font4.setPointSize(20);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(9);
        currentTripSouvenirLabel->setFont(font4);
        currentTripSouvenirLabel->setStyleSheet(QLatin1String("font: 75 20pt \"Gill Sans\";\n"
""));
        currentTripNextStadium = new QPushButton(tripProcessPage);
        currentTripNextStadium->setObjectName(QStringLiteral("currentTripNextStadium"));
        currentTripNextStadium->setGeometry(QRect(580, 530, 121, 31));
        currentTripNextStadium->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #01CDE6;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Helvetica\";\n"
"}"));
        shoppingCartButton = new QPushButton(tripProcessPage);
        shoppingCartButton->setObjectName(QStringLiteral("shoppingCartButton"));
        shoppingCartButton->setGeometry(QRect(660, 20, 51, 51));
        shoppingCartButton->setStyleSheet(QLatin1String("background-color: none;\n"
"color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-image:url(\"/Users/sarahsingletary/Documents/throw-catch/src/icons/shopping-cart-full-sign.png\");"));
        shoppingCartButton->setAutoDefault(false);
        currentTripProgressBar = new QProgressBar(tripProcessPage);
        currentTripProgressBar->setObjectName(QStringLiteral("currentTripProgressBar"));
        currentTripProgressBar->setGeometry(QRect(30, 480, 371, 21));
        currentTripProgressBar->setStyleSheet(QLatin1String("QProgressBar {\n"
"    border: 2px solid grey;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #01CDE6;\n"
"    width: 20px;\n"
"}"));
        currentTripProgressBar->setValue(24);
        currentTripProgressBar->setTextDirection(QProgressBar::TopToBottom);
        currentTripProgressLabel = new QLabel(tripProcessPage);
        currentTripProgressLabel->setObjectName(QStringLiteral("currentTripProgressLabel"));
        currentTripProgressLabel->setGeometry(QRect(30, 450, 161, 21));
        currentTripProgressLabel->setFont(font4);
        currentTripProgressLabel->setStyleSheet(QLatin1String("font: 75 20pt \"Gill Sans\";\n"
""));
        currentTripStadiumCount = new QLabel(tripProcessPage);
        currentTripStadiumCount->setObjectName(QStringLiteral("currentTripStadiumCount"));
        currentTripStadiumCount->setGeometry(QRect(30, 503, 331, 31));
        currentTripStadiumCount->setFont(font2);
        currentTripStadiumCount->setWordWrap(true);
        display->addWidget(tripProcessPage);
        confrimPurchasesPage = new QWidget();
        confrimPurchasesPage->setObjectName(QStringLiteral("confrimPurchasesPage"));
        confirmPurchasesLabel = new QLabel(confrimPurchasesPage);
        confirmPurchasesLabel->setObjectName(QStringLiteral("confirmPurchasesLabel"));
        confirmPurchasesLabel->setGeometry(QRect(20, 0, 431, 61));
        confirmPurchasesLabel->setStyleSheet(QLatin1String("font: 75 30pt \"Gill Sans\";\n"
""));
        grandTotalLabel = new QLabel(confrimPurchasesPage);
        grandTotalLabel->setObjectName(QStringLiteral("grandTotalLabel"));
        grandTotalLabel->setGeometry(QRect(450, 446, 151, 31));
        grandTotalLabel->setStyleSheet(QLatin1String("font: 75 20pt \"Gill Sans\";\n"
"color: rgb(32, 32, 32)\n"
""));
        grandTotalAmount = new QLabel(confrimPurchasesPage);
        grandTotalAmount->setObjectName(QStringLiteral("grandTotalAmount"));
        grandTotalAmount->setGeometry(QRect(590, 450, 121, 21));
        QFont font5;
        font5.setPointSize(23);
        grandTotalAmount->setFont(font5);
        shoppingCart = new QTreeWidget(confrimPurchasesPage);
        shoppingCart->setObjectName(QStringLiteral("shoppingCart"));
        shoppingCart->setGeometry(QRect(50, 110, 611, 311));
        shoppingCart->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        shoppingCart->header()->setDefaultSectionSize(133);
        shoppingCartLabel = new QLabel(confrimPurchasesPage);
        shoppingCartLabel->setObjectName(QStringLiteral("shoppingCartLabel"));
        shoppingCartLabel->setGeometry(QRect(230, 70, 191, 31));
        shoppingCartLabel->setStyleSheet(QLatin1String("font: 75 25pt \"Gill Sans\";\n"
"color: rgb(68, 68, 68);\n"
""));
        confirmPurchasesButton = new QPushButton(confrimPurchasesPage);
        confirmPurchasesButton->setObjectName(QStringLiteral("confirmPurchasesButton"));
        confirmPurchasesButton->setGeometry(QRect(540, 530, 121, 31));
        confirmPurchasesButton->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #01CDE6;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Helvetica\";\n"
"}"));
        updateShoppingCart = new QPushButton(confrimPurchasesPage);
        updateShoppingCart->setObjectName(QStringLiteral("updateShoppingCart"));
        updateShoppingCart->setGeometry(QRect(50, 80, 91, 20));
        updateShoppingCart->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #01CDE6;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Helvetica\";\n"
"}"));
        display->addWidget(confrimPurchasesPage);
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
        adminStadiumList = new QTreeWidget(viewAdminStadiumsPage);
        adminStadiumList->setObjectName(QStringLiteral("adminStadiumList"));
        adminStadiumList->setGeometry(QRect(60, 90, 371, 361));
        adminStadiumList->header()->setCascadingSectionResizes(false);
        adminStadiumList->header()->setDefaultSectionSize(200);
        adminHomePageLabel_2 = new QLabel(viewAdminStadiumsPage);
        adminHomePageLabel_2->setObjectName(QStringLiteral("adminHomePageLabel_2"));
        adminHomePageLabel_2->setGeometry(QRect(60, 20, 311, 41));
        adminHomePageLabel_2->setStyleSheet(QLatin1String("	font: 75 30pt \"Gill Sans\";\n"
""));
        confirmPurchasesButton_2 = new QPushButton(viewAdminStadiumsPage);
        confirmPurchasesButton_2->setObjectName(QStringLiteral("confirmPurchasesButton_2"));
        confirmPurchasesButton_2->setGeometry(QRect(270, 60, 161, 21));
        confirmPurchasesButton_2->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #01CDE6;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Helvetica\";\n"
"}"));
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
        listOfModifyStadiums->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listOfModifyStadiums->setAlternatingRowColors(true);
        listOfModifyStadiums->header()->setCascadingSectionResizes(false);
        listOfModifyStadiums->header()->setHighlightSections(false);
        listOfModifyStadiums->header()->setStretchLastSection(true);
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
        listOfModifyStadiumsSouvenirs->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
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
        adminViewStadiumsPage = new QWidget();
        adminViewStadiumsPage->setObjectName(QStringLiteral("adminViewStadiumsPage"));
        display->addWidget(adminViewStadiumsPage);
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
        adminLoginButton->setGeometry(QRect(638, 11, 91, 21));
        adminLoginButton->setStyleSheet(QLatin1String("QPushButton {\n"
"color: white;\n"
"background-color: none;\n"
"border: none;\n"
"font: 75 15pt \"Helvetica\";\n"
"}"));
        adminLoginButton->setFlat(false);
        searchBar = new QLineEdit(headerFrame);
        searchBar->setObjectName(QStringLiteral("searchBar"));
        searchBar->setGeometry(QRect(730, 10, 181, 21));
        searchBar->setMaxLength(40);
        searchBar->setClearButtonEnabled(true);
        searchButton = new QToolButton(headerFrame);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(920, 12, 16, 16));
        searchButton->setStyleSheet(QLatin1String("background-color: none;\n"
"color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-image:url(\"/Users/sarahsingletary/Documents/throw-catch/src/icons/magnifying-glass.png\");"));
        secretAdminLoginButton = new QToolButton(headerFrame);
        secretAdminLoginButton->setObjectName(QStringLiteral("secretAdminLoginButton"));
        secretAdminLoginButton->setGeometry(QRect(44, 15, 16, 16));
        secretAdminLoginButton->setStyleSheet(QLatin1String("background-color: none;\n"
"color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-image:url(\"/Users/sarahsingletary/Documents/throw-catch/src/icons/baseball.png\");"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        adminLoginButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        homePageButton->setText(QApplication::translate("MainWindow", "HOME", 0));
        planATripButton->setText(QApplication::translate("MainWindow", "TRIP", 0));
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
        label_3->setText(QApplication::translate("MainWindow", "View by:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Sort by:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "All", 0)
         << QApplication::translate("MainWindow", "American", 0)
         << QApplication::translate("MainWindow", "National", 0)
        );
        singleStadiumNameLabel->setText(QApplication::translate("MainWindow", "STADIUM_NAME", 0));
        label_9->setText(QApplication::translate("MainWindow", "Team name:", 0));
        label_12->setText(QApplication::translate("MainWindow", "Type of League:", 0));
        label_8->setText(QApplication::translate("MainWindow", "Address:", 0));
        label_5->setText(QApplication::translate("MainWindow", "Box office number:", 0));
        label_6->setText(QApplication::translate("MainWindow", "Date opened:", 0));
        label_10->setText(QApplication::translate("MainWindow", "Seating capacity:", 0));
        label_11->setText(QApplication::translate("MainWindow", "Surface:", 0));
        singleStadiumTeamName->setText(QApplication::translate("MainWindow", "team_name", 0));
        singleStadiumType->setText(QApplication::translate("MainWindow", "type_of_league", 0));
        singleStadiumAddress->setText(QApplication::translate("MainWindow", "address", 0));
        singleStadiumBoxOfficeNum->setText(QApplication::translate("MainWindow", "box_office_number", 0));
        singleStadiumDateOpened->setText(QApplication::translate("MainWindow", "date_opened", 0));
        singleStadiumSeatingCapacity->setText(QApplication::translate("MainWindow", "seating_capacity", 0));
        singleStadiumSurface->setText(QApplication::translate("MainWindow", "surface", 0));
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
        QTreeWidgetItem *___qtreewidgetitem1 = stadiumsToSelectFromList->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Stadiums", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = selectedStadiumsList->headerItem();
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "Stadiums to travel to", 0));
        confirmCustomTripButton->setText(QApplication::translate("MainWindow", "TAKE TRIP", 0));
        arrows->setText(QApplication::translate("MainWindow", "-->\n"
"<--", 0));
        startingStadiumLabel->setText(QApplication::translate("MainWindow", "Please select your starting stadium:", 0));
        planATripLabel_2->setText(QApplication::translate("MainWindow", "MINIMUM SPANNING TREE", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = MSTList->headerItem();
        ___qtreewidgetitem3->setText(2, QApplication::translate("MainWindow", "weight", 0));
        ___qtreewidgetitem3->setText(1, QApplication::translate("MainWindow", "destination", 0));
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "origin", 0));
        planATripLabel_3->setText(QApplication::translate("MainWindow", "total weight:", 0));
        label->setText(QApplication::translate("MainWindow", "---- miles", 0));
        currentTripStadiumNameLabel->setText(QApplication::translate("MainWindow", "STADIUM_NAME", 0));
        addSouvenirToShoppingCart->setText(QApplication::translate("MainWindow", "+ Add to cart", 0));
        currentTripWelcomeDescription->setText(QApplication::translate("MainWindow", "Welcome, you have arrived at your destination. ", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = listOfCurrentStadiumSouvenirs->headerItem();
        ___qtreewidgetitem4->setText(2, QApplication::translate("MainWindow", "Quantity", 0));
        ___qtreewidgetitem4->setText(1, QApplication::translate("MainWindow", "Price", 0));
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "Name", 0));
        currentTripNextButtonLabel->setText(QApplication::translate("MainWindow", "Click 'NEXT' to travel to your next stadium.", 0));
        currentTripSouvenirLabel->setText(QApplication::translate("MainWindow", "SOUVENIRS", 0));
        currentTripNextStadium->setText(QApplication::translate("MainWindow", "NEXT", 0));
        shoppingCartButton->setText(QString());
        currentTripProgressBar->setFormat(QString());
        currentTripProgressLabel->setText(QApplication::translate("MainWindow", "TRIP PROGRESS", 0));
        currentTripStadiumCount->setText(QApplication::translate("MainWindow", "_/_ stadiums have been visited.", 0));
        confirmPurchasesLabel->setText(QApplication::translate("MainWindow", "CONFIRM YOUR PURCHASES", 0));
        grandTotalLabel->setText(QApplication::translate("MainWindow", "GRAND TOTAL:", 0));
        grandTotalAmount->setText(QApplication::translate("MainWindow", "$0.00", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = shoppingCart->headerItem();
        ___qtreewidgetitem5->setText(4, QApplication::translate("MainWindow", "Total", 0));
        ___qtreewidgetitem5->setText(3, QApplication::translate("MainWindow", "Quantity", 0));
        ___qtreewidgetitem5->setText(2, QApplication::translate("MainWindow", "Subtotal", 0));
        ___qtreewidgetitem5->setText(1, QApplication::translate("MainWindow", "Name", 0));
        ___qtreewidgetitem5->setText(0, QApplication::translate("MainWindow", "Remove", 0));
        shoppingCartLabel->setText(QApplication::translate("MainWindow", "SHOPPING CART", 0));
        confirmPurchasesButton->setText(QApplication::translate("MainWindow", "CONFIRM", 0));
        updateShoppingCart->setText(QApplication::translate("MainWindow", "update", 0));
        usernameLabel->setText(QApplication::translate("MainWindow", "Username", 0));
        passwordLabel->setText(QApplication::translate("MainWindow", "Password", 0));
        loginButton->setText(QApplication::translate("MainWindow", "LOGIN", 0));
        adminLoginErrorMessage->setText(QApplication::translate("MainWindow", "Invalid username or password.", 0));
        adminLoginLabel->setText(QApplication::translate("MainWindow", "ADMIN LOGIN", 0));
        adminHomePageLabel->setText(QApplication::translate("MainWindow", "ADMIN HOME PAGE", 0));
        QTreeWidgetItem *___qtreewidgetitem6 = adminStadiumList->headerItem();
        ___qtreewidgetitem6->setText(1, QApplication::translate("MainWindow", "Total Revenue", 0));
        ___qtreewidgetitem6->setText(0, QApplication::translate("MainWindow", "Stadium", 0));
        adminHomePageLabel_2->setText(QApplication::translate("MainWindow", "STADIUMS", 0));
        confirmPurchasesButton_2->setText(QApplication::translate("MainWindow", "VIEW MORE INFO", 0));
        modifyInformationLabel->setText(QApplication::translate("MainWindow", "MODIFY INFORMATION", 0));
        modifyDescription->setText(QApplication::translate("MainWindow", "Select a stadium you would like to modify it's list of souvenirs", 0));
        QTreeWidgetItem *___qtreewidgetitem7 = listOfModifyStadiums->headerItem();
        ___qtreewidgetitem7->setText(0, QApplication::translate("MainWindow", "Stadium", 0));
        modifyInformationNextButton->setText(QApplication::translate("MainWindow", "NEXT", 0));
        modifySouvenirsListLabel->setText(QApplication::translate("MainWindow", "SOUVENIRS", 0));
        QTreeWidgetItem *___qtreewidgetitem8 = listOfModifyStadiumsSouvenirs->headerItem();
        ___qtreewidgetitem8->setText(1, QApplication::translate("MainWindow", "Price", 0));
        ___qtreewidgetitem8->setText(0, QApplication::translate("MainWindow", "Name", 0));
        removeSelectedSouvenir->setText(QApplication::translate("MainWindow", "DELETE", 0));
        addSelectedSouvenir->setText(QApplication::translate("MainWindow", "ADD", 0));
        newSouvenirNameLabel->setText(QApplication::translate("MainWindow", "Name:", 0));
        newSouvenirPriceLabel->setText(QApplication::translate("MainWindow", "Price", 0));
        teamNameLabel->setText(QApplication::translate("MainWindow", "thr  w-catch", 0));
        adminLoginButton->setText(QApplication::translate("MainWindow", "SIGN IN", 0));
        searchBar->setInputMask(QString());
        searchBar->setText(QString());
        searchBar->setPlaceholderText(QApplication::translate("MainWindow", "Search for a stadium...", 0));
        searchButton->setText(QString());
        secretAdminLoginButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
