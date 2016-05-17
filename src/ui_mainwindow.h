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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
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
    QPushButton *adminModifyStadiumsButton;
    QStackedWidget *display;
    QWidget *homePage;
    QLabel *viewStadiumHeading_2;
    QFrame *frame_3;
    QLabel *label_2;
    QLabel *viewStadiumHeading_3;
    QLabel *label;
    QLabel *viewStadiumHeading_4;
    QLabel *viewStadiumHeading_5;
    QWidget *viewStadiumsPage;
    QLabel *viewStadiumHeading;
    QLabel *label_3;
    QComboBox *viewStadiumByComboBox;
    QTreeWidget *viewStadiumsList;
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
    QLabel *totalRevenueLabel;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *singleStadiumLayoutInfo;
    QLabel *singleStadiumTeamName;
    QLabel *singleStadiumType;
    QLabel *singleStadiumAddress;
    QLabel *singleStadiumBoxOfficeNum;
    QLabel *singleStadiumDateOpened;
    QLabel *singleStadiumSeatingCapacity;
    QLabel *singleStadiumSurface;
    QLabel *singleStadiumTotalRevenue;
    QWidget *planATripPage;
    QPushButton *shortestTripToAllButton;
    QPushButton *customTripButton;
    QPushButton *minimumSpanningTreeButton;
    QLabel *planATripLabel;
    QLabel *label_4;
    QWidget *quickTripToAllPage;
    QLabel *quickTripLabel;
    QTreeWidget *quickTripList;
    QLabel *quickTripStartingStadiumLabel;
    QLabel *quickTripStartingStadium;
    QLabel *quickTripDescription;
    QPushButton *quickTripTakeTripButton;
    QWidget *customTripPage;
    QLabel *customTripLabel;
    QTreeWidget *stadiumsToSelectFromList;
    QTreeWidget *selectedStadiumsList;
    QPushButton *confirmCustomTripButton;
    QLabel *startingStadiumLabel;
    QComboBox *startingStadiumComboBox;
    QPushButton *removeFromItineraryButton;
    QPushButton *addToItineraryButton;
    QWidget *minimumSpanningTreePage;
    QLabel *planATripLabel_2;
    QTreeWidget *MSTList;
    QLabel *planATripLabel_3;
    QLabel *mstTotalWeight;
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
    QLCDNumber *totalDistanceTraveled;
    QLabel *currentTripStadiumCount_2;
    QFrame *travel;
    QLabel *travelGif;
    QLabel *travelToName;
    QLabel *travelFromName;
    QWidget *confrimPurchasesPage;
    QLabel *confirmPurchasesLabel;
    QLabel *grandTotalLabel;
    QLabel *grandTotalAmount;
    QTreeWidget *shoppingCart;
    QLabel *shoppingCartLabel;
    QPushButton *confirmPurchasesButton;
    QLabel *shoppingCartEmpty;
    QLCDNumber *finalTotalDistance;
    QLabel *grandTotalLabel_2;
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
    QPushButton *viewMoreInfoAboutStadiumButton;
    QLabel *label_7;
    QLabel *stadiumTotalRevenue;
    QLabel *stadiumTotalRevenueLabel;
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
    QLabel *adminAddSouvenirErrorMessage;
    QLabel *modifyStadiumsDescr_2;
    QWidget *adminModifyStadiums;
    QPushButton *addStadiumFromFileButton;
    QPushButton *updateAStadiumButton;
    QLabel *modifyStadiumLabel;
    QTreeWidget *stadiumsToModifyList;
    QFrame *line;
    QFrame *line_2;
    QLabel *modifyStadiumOrLabel;
    QLabel *modifyStadiumsDescr;
    QLabel *modifyStadiumSelectDescr;
    QWidget *updateStadiumPage;
    QLabel *modifySouvenirsListLabel_2;
    QFrame *updateLeague;
    QHBoxLayout *horizontalLayout_5;
    QLabel *updateLeagueLabel;
    QRadioButton *updateAmericanLeague;
    QRadioButton *updateNationalLeague;
    QSpacerItem *horizontalSpacer_11;
    QFrame *frame;
    QFrame *updateStadiumName;
    QHBoxLayout *horizontalLayout_6;
    QLabel *updateStadiumLabel;
    QLineEdit *updateStadium;
    QSpacerItem *horizontalSpacer_12;
    QFrame *updateTeam;
    QHBoxLayout *horizontalLayout_7;
    QLabel *updateStadiumTeamNameLabel;
    QLineEdit *updateTeamName;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *confirmStadiumUpdateButton;
    QPushButton *cancelStadiumUpdatesButton;
    QFrame *updateInformation;
    QGridLayout *gridLayout_4;
    QFrame *frame_2;
    QLineEdit *updateStreetAddress;
    QLineEdit *updateZipcode;
    QLineEdit *updateCity;
    QLineEdit *updateState;
    QLabel *updateAddress_2;
    QLabel *updateAddress_3;
    QLabel *updateAddress_4;
    QLabel *updateAddress_5;
    QSpacerItem *horizontalSpacer_16;
    QComboBox *updateMonth;
    QLineEdit *updateYear;
    QSpinBox *updateSeatingCapacity;
    QLineEdit *updatePhoneNumber;
    QLineEdit *updateTypology;
    QLabel *label_20;
    QLabel *label_22;
    QLabel *label_21;
    QLabel *label_19;
    QLineEdit *updateDay;
    QLabel *updateStadiumTeamNameLabel_2;
    QLabel *updateStadiumInvalidErrorMessage;
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
        homePageButton->setStyleSheet(QStringLiteral("font: 25 20pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        planATripButton = new QPushButton(sidebarFrame);
        planATripButton->setObjectName(QStringLiteral("planATripButton"));
        planATripButton->setGeometry(QRect(0, 340, 201, 61));
        planATripButton->setStyleSheet(QStringLiteral("font: 25 20pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        viewStadiumsPageButton = new QPushButton(sidebarFrame);
        viewStadiumsPageButton->setObjectName(QStringLiteral("viewStadiumsPageButton"));
        viewStadiumsPageButton->setGeometry(QRect(0, 277, 201, 61));
        viewStadiumsPageButton->setStyleSheet(QStringLiteral("font: 25 20pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
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
        adminHomeButton->setStyleSheet(QStringLiteral("font: 25 20pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        adminModifyButton = new QPushButton(adminSidebarFrame);
        adminModifyButton->setObjectName(QStringLiteral("adminModifyButton"));
        adminModifyButton->setGeometry(QRect(0, 340, 201, 61));
        adminModifyButton->setStyleSheet(QStringLiteral("font: 25 20pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        viewAdminStadiumsButton = new QPushButton(adminSidebarFrame);
        viewAdminStadiumsButton->setObjectName(QStringLiteral("viewAdminStadiumsButton"));
        viewAdminStadiumsButton->setGeometry(QRect(0, 277, 201, 61));
        viewAdminStadiumsButton->setStyleSheet(QStringLiteral("font: 25 20pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        adminModifyStadiumsButton = new QPushButton(adminSidebarFrame);
        adminModifyStadiumsButton->setObjectName(QStringLiteral("adminModifyStadiumsButton"));
        adminModifyStadiumsButton->setGeometry(QRect(0, 400, 201, 61));
        adminModifyStadiumsButton->setStyleSheet(QStringLiteral("font: 25 20pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        options->addWidget(adminOptions);
        display = new QStackedWidget(centralWidget);
        display->setObjectName(QStringLiteral("display"));
        display->setGeometry(QRect(203, 40, 801, 596));
        display->setStyleSheet(QLatin1String("background-color: #EAEAE9\n"
""));
        homePage = new QWidget();
        homePage->setObjectName(QStringLiteral("homePage"));
        viewStadiumHeading_2 = new QLabel(homePage);
        viewStadiumHeading_2->setObjectName(QStringLiteral("viewStadiumHeading_2"));
        viewStadiumHeading_2->setGeometry(QRect(20, 10, 301, 41));
        viewStadiumHeading_2->setStyleSheet(QLatin1String("font: 25 30pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
""));
        frame_3 = new QFrame(homePage);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(330, 0, 421, 611));
        frame_3->setStyleSheet(QLatin1String("background-color: rgb(223, 223, 223);\n"
"border: none;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 10, 341, 71));
        label_2->setStyleSheet(QLatin1String("border-image:url(:/icon/icons/welcome-sign.png);\n"
"background-color: none;"));
        viewStadiumHeading_3 = new QLabel(frame_3);
        viewStadiumHeading_3->setObjectName(QStringLiteral("viewStadiumHeading_3"));
        viewStadiumHeading_3->setGeometry(QRect(30, 80, 351, 61));
        QFont font;
        font.setFamily(QStringLiteral("Futura"));
        font.setPointSize(14);
        viewStadiumHeading_3->setFont(font);
        viewStadiumHeading_3->setStyleSheet(QStringLiteral("background none;"));
        viewStadiumHeading_3->setWordWrap(true);
        label = new QLabel(homePage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 100, 401, 391));
        label->setStyleSheet(QLatin1String("border-image:url(:/icon/icons/program-throw-catch.png);\n"
"background-color: none;"));
        viewStadiumHeading_4 = new QLabel(homePage);
        viewStadiumHeading_4->setObjectName(QStringLiteral("viewStadiumHeading_4"));
        viewStadiumHeading_4->setGeometry(QRect(490, 110, 351, 61));
        viewStadiumHeading_4->setFont(font);
        viewStadiumHeading_4->setStyleSheet(QStringLiteral("background-color: none;"));
        viewStadiumHeading_4->setWordWrap(true);
        viewStadiumHeading_5 = new QLabel(homePage);
        viewStadiumHeading_5->setObjectName(QStringLiteral("viewStadiumHeading_5"));
        viewStadiumHeading_5->setGeometry(QRect(490, 140, 251, 221));
        viewStadiumHeading_5->setFont(font);
        viewStadiumHeading_5->setStyleSheet(QStringLiteral("background-color: none;"));
        viewStadiumHeading_5->setWordWrap(true);
        display->addWidget(homePage);
        frame_3->raise();
        viewStadiumHeading_2->raise();
        label->raise();
        viewStadiumHeading_4->raise();
        viewStadiumHeading_5->raise();
        viewStadiumsPage = new QWidget();
        viewStadiumsPage->setObjectName(QStringLiteral("viewStadiumsPage"));
        viewStadiumHeading = new QLabel(viewStadiumsPage);
        viewStadiumHeading->setObjectName(QStringLiteral("viewStadiumHeading"));
        viewStadiumHeading->setGeometry(QRect(20, 10, 311, 41));
        viewStadiumHeading->setStyleSheet(QStringLiteral("font: 25 30pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        label_3 = new QLabel(viewStadiumsPage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 60, 59, 16));
        viewStadiumByComboBox = new QComboBox(viewStadiumsPage);
        viewStadiumByComboBox->setObjectName(QStringLiteral("viewStadiumByComboBox"));
        viewStadiumByComboBox->setGeometry(QRect(80, 56, 171, 21));
        viewStadiumByComboBox->setStyleSheet(QLatin1String("QComboBox::down-arrow {\n"
"		image:url(:/icon/icons/down_arrow.png);\n"
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
        viewStadiumsList = new QTreeWidget(viewStadiumsPage);
        viewStadiumsList->setObjectName(QStringLiteral("viewStadiumsList"));
        viewStadiumsList->setGeometry(QRect(20, 100, 711, 481));
        viewStadiumsList->setSortingEnabled(true);
        viewStadiumsList->header()->setDefaultSectionSize(100);
        display->addWidget(viewStadiumsPage);
        viewSingleStadiumPage = new QWidget();
        viewSingleStadiumPage->setObjectName(QStringLiteral("viewSingleStadiumPage"));
        singleStadiumNameLabel = new QLabel(viewSingleStadiumPage);
        singleStadiumNameLabel->setObjectName(QStringLiteral("singleStadiumNameLabel"));
        singleStadiumNameLabel->setGeometry(QRect(20, 10, 661, 41));
        singleStadiumNameLabel->setStyleSheet(QStringLiteral("font: 25 30pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        singleStadiumInfo = new QFrame(viewSingleStadiumPage);
        singleStadiumInfo->setObjectName(QStringLiteral("singleStadiumInfo"));
        singleStadiumInfo->setGeometry(QRect(20, 70, 451, 431));
        singleStadiumInfo->setStyleSheet(QStringLiteral("border: none;"));
        singleStadiumInfo->setFrameShape(QFrame::StyledPanel);
        singleStadiumInfo->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(singleStadiumInfo);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 131, 401));
        singleStadiumLayoutLabels = new QVBoxLayout(verticalLayoutWidget);
        singleStadiumLayoutLabels->setSpacing(6);
        singleStadiumLayoutLabels->setContentsMargins(11, 11, 11, 11);
        singleStadiumLayoutLabels->setObjectName(QStringLiteral("singleStadiumLayoutLabels"));
        singleStadiumLayoutLabels->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        QFont font1;
        font1.setFamily(QStringLiteral("Futura"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label_9->setFont(font1);

        singleStadiumLayoutLabels->addWidget(label_9);

        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        QFont font2;
        font2.setFamily(QStringLiteral("Futura"));
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        label_12->setFont(font2);

        singleStadiumLayoutLabels->addWidget(label_12);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font2);

        singleStadiumLayoutLabels->addWidget(label_8);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);

        singleStadiumLayoutLabels->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font2);

        singleStadiumLayoutLabels->addWidget(label_6);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font2);

        singleStadiumLayoutLabels->addWidget(label_10);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font2);

        singleStadiumLayoutLabels->addWidget(label_11);

        totalRevenueLabel = new QLabel(verticalLayoutWidget);
        totalRevenueLabel->setObjectName(QStringLiteral("totalRevenueLabel"));
        totalRevenueLabel->setFont(font2);

        singleStadiumLayoutLabels->addWidget(totalRevenueLabel);

        verticalLayoutWidget_2 = new QWidget(singleStadiumInfo);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(160, 10, 271, 401));
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
        QFont font3;
        font3.setPointSize(13);
        font3.setKerning(true);
        singleStadiumAddress->setFont(font3);
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

        singleStadiumTotalRevenue = new QLabel(verticalLayoutWidget_2);
        singleStadiumTotalRevenue->setObjectName(QStringLiteral("singleStadiumTotalRevenue"));

        singleStadiumLayoutInfo->addWidget(singleStadiumTotalRevenue);

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
        shortestTripToAllButton->setGeometry(QRect(180, 320, 411, 61));
        shortestTripToAllButton->setStyleSheet(QStringLiteral("font: 25 20pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        customTripButton = new QPushButton(planATripPage);
        customTripButton->setObjectName(QStringLiteral("customTripButton"));
        customTripButton->setGeometry(QRect(180, 390, 411, 61));
        customTripButton->setStyleSheet(QStringLiteral("font: 25 20pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        minimumSpanningTreeButton = new QPushButton(planATripPage);
        minimumSpanningTreeButton->setObjectName(QStringLiteral("minimumSpanningTreeButton"));
        minimumSpanningTreeButton->setGeometry(QRect(180, 460, 411, 61));
        minimumSpanningTreeButton->setStyleSheet(QStringLiteral("font: 25 20pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        planATripLabel = new QLabel(planATripPage);
        planATripLabel->setObjectName(QStringLiteral("planATripLabel"));
        planATripLabel->setGeometry(QRect(20, 10, 311, 41));
        planATripLabel->setStyleSheet(QStringLiteral("font: 25 30pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        label_4 = new QLabel(planATripPage);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(120, 50, 561, 271));
        label_4->setStyleSheet(QStringLiteral("border-image:url(:/icon/icons/program-baseball-field.png);"));
        display->addWidget(planATripPage);
        customTripButton->raise();
        minimumSpanningTreeButton->raise();
        planATripLabel->raise();
        label_4->raise();
        shortestTripToAllButton->raise();
        quickTripToAllPage = new QWidget();
        quickTripToAllPage->setObjectName(QStringLiteral("quickTripToAllPage"));
        quickTripLabel = new QLabel(quickTripToAllPage);
        quickTripLabel->setObjectName(QStringLiteral("quickTripLabel"));
        quickTripLabel->setGeometry(QRect(20, 10, 371, 51));
        quickTripLabel->setStyleSheet(QLatin1String("font: 25 30pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
""));
        quickTripList = new QTreeWidget(quickTripToAllPage);
        quickTripList->setObjectName(QStringLiteral("quickTripList"));
        quickTripList->setGeometry(QRect(130, 150, 431, 341));
        quickTripList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        quickTripList->setAlternatingRowColors(true);
        quickTripList->header()->setCascadingSectionResizes(false);
        quickTripList->header()->setDefaultSectionSize(150);
        quickTripList->header()->setHighlightSections(false);
        quickTripList->header()->setStretchLastSection(true);
        quickTripStartingStadiumLabel = new QLabel(quickTripToAllPage);
        quickTripStartingStadiumLabel->setObjectName(QStringLiteral("quickTripStartingStadiumLabel"));
        quickTripStartingStadiumLabel->setGeometry(QRect(130, 110, 141, 31));
        quickTripStartingStadiumLabel->setStyleSheet(QLatin1String("font: 25 20pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
""));
        quickTripStartingStadium = new QLabel(quickTripToAllPage);
        quickTripStartingStadium->setObjectName(QStringLiteral("quickTripStartingStadium"));
        quickTripStartingStadium->setGeometry(QRect(280, 116, 211, 16));
        QFont font4;
        font4.setBold(true);
        font4.setWeight(75);
        quickTripStartingStadium->setFont(font4);
        quickTripDescription = new QLabel(quickTripToAllPage);
        quickTripDescription->setObjectName(QStringLiteral("quickTripDescription"));
        quickTripDescription->setGeometry(QRect(40, 50, 611, 43));
        quickTripDescription->setWordWrap(true);
        quickTripTakeTripButton = new QPushButton(quickTripToAllPage);
        quickTripTakeTripButton->setObjectName(QStringLiteral("quickTripTakeTripButton"));
        quickTripTakeTripButton->setGeometry(QRect(400, 500, 161, 41));
        quickTripTakeTripButton->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #01CDE6;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
"}"));
        display->addWidget(quickTripToAllPage);
        customTripPage = new QWidget();
        customTripPage->setObjectName(QStringLiteral("customTripPage"));
        customTripLabel = new QLabel(customTripPage);
        customTripLabel->setObjectName(QStringLiteral("customTripLabel"));
        customTripLabel->setGeometry(QRect(20, 10, 311, 41));
        customTripLabel->setStyleSheet(QStringLiteral("font: 25 30pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        stadiumsToSelectFromList = new QTreeWidget(customTripPage);
        stadiumsToSelectFromList->setObjectName(QStringLiteral("stadiumsToSelectFromList"));
        stadiumsToSelectFromList->setGeometry(QRect(80, 160, 256, 261));
        selectedStadiumsList = new QTreeWidget(customTripPage);
        selectedStadiumsList->setObjectName(QStringLiteral("selectedStadiumsList"));
        selectedStadiumsList->setGeometry(QRect(420, 160, 256, 261));
        confirmCustomTripButton = new QPushButton(customTripPage);
        confirmCustomTripButton->setObjectName(QStringLiteral("confirmCustomTripButton"));
        confirmCustomTripButton->setGeometry(QRect(580, 510, 121, 31));
        confirmCustomTripButton->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #01CDE6;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
"}"));
        startingStadiumLabel = new QLabel(customTripPage);
        startingStadiumLabel->setObjectName(QStringLiteral("startingStadiumLabel"));
        startingStadiumLabel->setGeometry(QRect(80, 100, 221, 16));
        startingStadiumComboBox = new QComboBox(customTripPage);
        startingStadiumComboBox->setObjectName(QStringLiteral("startingStadiumComboBox"));
        startingStadiumComboBox->setGeometry(QRect(310, 95, 201, 26));
        startingStadiumComboBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        startingStadiumComboBox->setLayoutDirection(Qt::LeftToRight);
        startingStadiumComboBox->setStyleSheet(QLatin1String("QComboBox::down-arrow {\n"
"		image: url(:/icon/icons/down_arrow.png);\n"
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
        removeFromItineraryButton = new QPushButton(customTripPage);
        removeFromItineraryButton->setObjectName(QStringLiteral("removeFromItineraryButton"));
        removeFromItineraryButton->setGeometry(QRect(340, 290, 71, 41));
        removeFromItineraryButton->setStyleSheet(QLatin1String("image:url(:/icon/icons/left-arrow.png);\n"
"border: none;"));
        addToItineraryButton = new QPushButton(customTripPage);
        addToItineraryButton->setObjectName(QStringLiteral("addToItineraryButton"));
        addToItineraryButton->setGeometry(QRect(340, 240, 71, 41));
        addToItineraryButton->setStyleSheet(QLatin1String("image:url(:/icon/icons/right-arrow.png);\n"
"border: none;"));
        display->addWidget(customTripPage);
        minimumSpanningTreePage = new QWidget();
        minimumSpanningTreePage->setObjectName(QStringLiteral("minimumSpanningTreePage"));
        planATripLabel_2 = new QLabel(minimumSpanningTreePage);
        planATripLabel_2->setObjectName(QStringLiteral("planATripLabel_2"));
        planATripLabel_2->setGeometry(QRect(20, 20, 411, 41));
        planATripLabel_2->setStyleSheet(QStringLiteral("font: 25 30pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        MSTList = new QTreeWidget(minimumSpanningTreePage);
        MSTList->setObjectName(QStringLiteral("MSTList"));
        MSTList->setGeometry(QRect(50, 80, 621, 291));
        MSTList->header()->setDefaultSectionSize(120);
        planATripLabel_3 = new QLabel(minimumSpanningTreePage);
        planATripLabel_3->setObjectName(QStringLiteral("planATripLabel_3"));
        planATripLabel_3->setGeometry(QRect(130, 380, 141, 41));
        planATripLabel_3->setStyleSheet(QStringLiteral("font: 25 25pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        mstTotalWeight = new QLabel(minimumSpanningTreePage);
        mstTotalWeight->setObjectName(QStringLiteral("mstTotalWeight"));
        mstTotalWeight->setGeometry(QRect(280, 390, 211, 21));
        QFont font5;
        font5.setPointSize(20);
        mstTotalWeight->setFont(font5);
        display->addWidget(minimumSpanningTreePage);
        tripProcessPage = new QWidget();
        tripProcessPage->setObjectName(QStringLiteral("tripProcessPage"));
        currentTripStadiumNameLabel = new QLabel(tripProcessPage);
        currentTripStadiumNameLabel->setObjectName(QStringLiteral("currentTripStadiumNameLabel"));
        currentTripStadiumNameLabel->setGeometry(QRect(20, 10, 431, 61));
        currentTripStadiumNameLabel->setStyleSheet(QStringLiteral("font: 25 30pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        addSouvenirToShoppingCart = new QPushButton(tripProcessPage);
        addSouvenirToShoppingCart->setObjectName(QStringLiteral("addSouvenirToShoppingCart"));
        addSouvenirToShoppingCart->setGeometry(QRect(280, 360, 121, 31));
        addSouvenirToShoppingCart->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #293539;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
"}"));
        currentTripWelcomeDescription = new QLabel(tripProcessPage);
        currentTripWelcomeDescription->setObjectName(QStringLiteral("currentTripWelcomeDescription"));
        currentTripWelcomeDescription->setGeometry(QRect(60, 60, 331, 20));
        QFont font6;
        font6.setPointSize(14);
        currentTripWelcomeDescription->setFont(font6);
        currentTripWelcomeDescription->setWordWrap(true);
        listOfCurrentStadiumSouvenirs = new QTreeWidget(tripProcessPage);
        listOfCurrentStadiumSouvenirs->setObjectName(QStringLiteral("listOfCurrentStadiumSouvenirs"));
        listOfCurrentStadiumSouvenirs->setGeometry(QRect(40, 130, 361, 221));
        listOfCurrentStadiumSouvenirs->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listOfCurrentStadiumSouvenirs->header()->setDefaultSectionSize(133);
        currentTripNextButtonLabel = new QLabel(tripProcessPage);
        currentTripNextButtonLabel->setObjectName(QStringLiteral("currentTripNextButtonLabel"));
        currentTripNextButtonLabel->setGeometry(QRect(430, 520, 141, 41));
        currentTripNextButtonLabel->setWordWrap(true);
        currentTripSouvenirLabel = new QLabel(tripProcessPage);
        currentTripSouvenirLabel->setObjectName(QStringLiteral("currentTripSouvenirLabel"));
        currentTripSouvenirLabel->setGeometry(QRect(40, 100, 121, 21));
        QFont font7;
        font7.setFamily(QStringLiteral("Gill Sans,Gill Sans MT Condensed"));
        font7.setPointSize(20);
        font7.setBold(false);
        font7.setItalic(false);
        font7.setWeight(3);
        currentTripSouvenirLabel->setFont(font7);
        currentTripSouvenirLabel->setStyleSheet(QStringLiteral("font: 25 20pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        currentTripNextStadium = new QPushButton(tripProcessPage);
        currentTripNextStadium->setObjectName(QStringLiteral("currentTripNextStadium"));
        currentTripNextStadium->setGeometry(QRect(580, 530, 121, 31));
        currentTripNextStadium->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #01CDE6;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
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
        currentTripProgressBar->setGeometry(QRect(30, 460, 371, 21));
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
        currentTripProgressLabel->setGeometry(QRect(30, 430, 161, 21));
        currentTripProgressLabel->setFont(font7);
        currentTripProgressLabel->setStyleSheet(QStringLiteral("font: 25 20pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        currentTripStadiumCount = new QLabel(tripProcessPage);
        currentTripStadiumCount->setObjectName(QStringLiteral("currentTripStadiumCount"));
        currentTripStadiumCount->setGeometry(QRect(30, 491, 421, 20));
        currentTripStadiumCount->setFont(font6);
        currentTripStadiumCount->setWordWrap(true);
        totalDistanceTraveled = new QLCDNumber(tripProcessPage);
        totalDistanceTraveled->setObjectName(QStringLiteral("totalDistanceTraveled"));
        totalDistanceTraveled->setGeometry(QRect(150, 530, 131, 41));
        totalDistanceTraveled->setDigitCount(6);
        currentTripStadiumCount_2 = new QLabel(tripProcessPage);
        currentTripStadiumCount_2->setObjectName(QStringLiteral("currentTripStadiumCount_2"));
        currentTripStadiumCount_2->setGeometry(QRect(30, 540, 341, 31));
        currentTripStadiumCount_2->setFont(font6);
        currentTripStadiumCount_2->setWordWrap(true);
        travel = new QFrame(tripProcessPage);
        travel->setObjectName(QStringLiteral("travel"));
        travel->setGeometry(QRect(440, 100, 261, 391));
        travel->setStyleSheet(QLatin1String("background-color: rgb(223, 223, 223);\n"
"border: none;"));
        travel->setFrameShape(QFrame::StyledPanel);
        travel->setFrameShadow(QFrame::Raised);
        travelGif = new QLabel(travel);
        travelGif->setObjectName(QStringLiteral("travelGif"));
        travelGif->setGeometry(QRect(20, 0, 231, 391));
        travelToName = new QLabel(travel);
        travelToName->setObjectName(QStringLiteral("travelToName"));
        travelToName->setGeometry(QRect(40, 30, 111, 101));
        QFont font8;
        font8.setFamily(QStringLiteral("Futura"));
        font8.setPointSize(18);
        font8.setBold(false);
        font8.setItalic(false);
        font8.setWeight(50);
        travelToName->setFont(font8);
        travelToName->setStyleSheet(QLatin1String("background-color: none;\n"
"color: white;\n"
"font: 18pt \"Futura\";"));
        travelToName->setWordWrap(true);
        travelFromName = new QLabel(travel);
        travelFromName->setObjectName(QStringLiteral("travelFromName"));
        travelFromName->setGeometry(QRect(120, 290, 131, 91));
        travelFromName->setStyleSheet(QLatin1String("font: 18pt \"Futura\";background-color: none;\n"
"color: white;"));
        travelFromName->setWordWrap(true);
        display->addWidget(tripProcessPage);
        currentTripStadiumNameLabel->raise();
        addSouvenirToShoppingCart->raise();
        currentTripWelcomeDescription->raise();
        listOfCurrentStadiumSouvenirs->raise();
        currentTripNextButtonLabel->raise();
        currentTripSouvenirLabel->raise();
        currentTripNextStadium->raise();
        shoppingCartButton->raise();
        currentTripProgressBar->raise();
        currentTripProgressLabel->raise();
        currentTripStadiumCount->raise();
        currentTripStadiumCount_2->raise();
        totalDistanceTraveled->raise();
        travel->raise();
        confrimPurchasesPage = new QWidget();
        confrimPurchasesPage->setObjectName(QStringLiteral("confrimPurchasesPage"));
        confirmPurchasesLabel = new QLabel(confrimPurchasesPage);
        confirmPurchasesLabel->setObjectName(QStringLiteral("confirmPurchasesLabel"));
        confirmPurchasesLabel->setGeometry(QRect(20, 0, 431, 61));
        confirmPurchasesLabel->setStyleSheet(QStringLiteral("font: 25 30pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        grandTotalLabel = new QLabel(confrimPurchasesPage);
        grandTotalLabel->setObjectName(QStringLiteral("grandTotalLabel"));
        grandTotalLabel->setGeometry(QRect(450, 446, 151, 31));
        grandTotalLabel->setStyleSheet(QLatin1String("font: 75 20pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
"color: rgb(32, 32, 32)\n"
""));
        grandTotalAmount = new QLabel(confrimPurchasesPage);
        grandTotalAmount->setObjectName(QStringLiteral("grandTotalAmount"));
        grandTotalAmount->setGeometry(QRect(590, 450, 121, 21));
        grandTotalAmount->setFont(font5);
        shoppingCart = new QTreeWidget(confrimPurchasesPage);
        shoppingCart->setObjectName(QStringLiteral("shoppingCart"));
        shoppingCart->setGeometry(QRect(50, 110, 611, 311));
        shoppingCart->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        shoppingCart->header()->setDefaultSectionSize(133);
        shoppingCartLabel = new QLabel(confrimPurchasesPage);
        shoppingCartLabel->setObjectName(QStringLiteral("shoppingCartLabel"));
        shoppingCartLabel->setGeometry(QRect(230, 70, 221, 31));
        shoppingCartLabel->setStyleSheet(QLatin1String("font: 25 25pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
"color: rgb(68, 68, 68);\n"
""));
        confirmPurchasesButton = new QPushButton(confrimPurchasesPage);
        confirmPurchasesButton->setObjectName(QStringLiteral("confirmPurchasesButton"));
        confirmPurchasesButton->setGeometry(QRect(540, 530, 121, 31));
        confirmPurchasesButton->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #01CDE6;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
"}"));
        shoppingCartEmpty = new QLabel(confrimPurchasesPage);
        shoppingCartEmpty->setObjectName(QStringLiteral("shoppingCartEmpty"));
        shoppingCartEmpty->setGeometry(QRect(60, 130, 261, 16));
        finalTotalDistance = new QLCDNumber(confrimPurchasesPage);
        finalTotalDistance->setObjectName(QStringLiteral("finalTotalDistance"));
        finalTotalDistance->setGeometry(QRect(220, 520, 131, 41));
        finalTotalDistance->setDigitCount(6);
        grandTotalLabel_2 = new QLabel(confrimPurchasesPage);
        grandTotalLabel_2->setObjectName(QStringLiteral("grandTotalLabel_2"));
        grandTotalLabel_2->setGeometry(QRect(50, 529, 161, 31));
        grandTotalLabel_2->setStyleSheet(QLatin1String("font: 75 20pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
"color: rgb(32, 32, 32)\n"
""));
        display->addWidget(confrimPurchasesPage);
        shoppingCartEmpty->raise();
        confirmPurchasesLabel->raise();
        grandTotalLabel->raise();
        grandTotalAmount->raise();
        shoppingCart->raise();
        shoppingCartLabel->raise();
        confirmPurchasesButton->raise();
        finalTotalDistance->raise();
        grandTotalLabel_2->raise();
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
        loginButton->setGeometry(QRect(320, 310, 113, 32));
        loginButton->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #293539;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
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
        adminLoginLabel->setStyleSheet(QStringLiteral("font: 25 30pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        display->addWidget(adminLoginPage);
        adminHomePage = new QWidget();
        adminHomePage->setObjectName(QStringLiteral("adminHomePage"));
        adminHomePageLabel = new QLabel(adminHomePage);
        adminHomePageLabel->setObjectName(QStringLiteral("adminHomePageLabel"));
        adminHomePageLabel->setGeometry(QRect(20, 10, 311, 41));
        adminHomePageLabel->setStyleSheet(QStringLiteral("font: 25 30pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        display->addWidget(adminHomePage);
        viewAdminStadiumsPage = new QWidget();
        viewAdminStadiumsPage->setObjectName(QStringLiteral("viewAdminStadiumsPage"));
        adminStadiumList = new QTreeWidget(viewAdminStadiumsPage);
        adminStadiumList->setObjectName(QStringLiteral("adminStadiumList"));
        adminStadiumList->setGeometry(QRect(220, 140, 371, 361));
        adminStadiumList->header()->setCascadingSectionResizes(false);
        adminStadiumList->header()->setDefaultSectionSize(200);
        adminHomePageLabel_2 = new QLabel(viewAdminStadiumsPage);
        adminHomePageLabel_2->setObjectName(QStringLiteral("adminHomePageLabel_2"));
        adminHomePageLabel_2->setGeometry(QRect(40, 20, 311, 41));
        QFont font9;
        font9.setFamily(QStringLiteral("Gill Sans,Gill Sans MT Condensed"));
        font9.setPointSize(30);
        font9.setBold(false);
        font9.setItalic(false);
        font9.setWeight(3);
        adminHomePageLabel_2->setFont(font9);
        adminHomePageLabel_2->setStyleSheet(QStringLiteral("font: 25 30pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        viewMoreInfoAboutStadiumButton = new QPushButton(viewAdminStadiumsPage);
        viewMoreInfoAboutStadiumButton->setObjectName(QStringLiteral("viewMoreInfoAboutStadiumButton"));
        viewMoreInfoAboutStadiumButton->setGeometry(QRect(430, 110, 161, 21));
        viewMoreInfoAboutStadiumButton->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #01CDE6;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
"}"));
        label_7 = new QLabel(viewAdminStadiumsPage);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 60, 451, 31));
        label_7->setWordWrap(true);
        stadiumTotalRevenue = new QLabel(viewAdminStadiumsPage);
        stadiumTotalRevenue->setObjectName(QStringLiteral("stadiumTotalRevenue"));
        stadiumTotalRevenue->setGeometry(QRect(470, 520, 131, 31));
        QFont font10;
        font10.setPointSize(23);
        stadiumTotalRevenue->setFont(font10);
        stadiumTotalRevenueLabel = new QLabel(viewAdminStadiumsPage);
        stadiumTotalRevenueLabel->setObjectName(QStringLiteral("stadiumTotalRevenueLabel"));
        stadiumTotalRevenueLabel->setGeometry(QRect(220, 520, 241, 31));
        stadiumTotalRevenueLabel->setStyleSheet(QLatin1String("font: 25 20pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
"color: rgb(32, 32, 32)\n"
""));
        display->addWidget(viewAdminStadiumsPage);
        adminModifyPage = new QWidget();
        adminModifyPage->setObjectName(QStringLiteral("adminModifyPage"));
        modifyInformationLabel = new QLabel(adminModifyPage);
        modifyInformationLabel->setObjectName(QStringLiteral("modifyInformationLabel"));
        modifyInformationLabel->setGeometry(QRect(10, 10, 391, 41));
        modifyInformationLabel->setStyleSheet(QStringLiteral("font: 25 30pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
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
"	font: 75 15pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
"}"));
        display->addWidget(adminModifyPage);
        modifySouvenirItemPage = new QWidget();
        modifySouvenirItemPage->setObjectName(QStringLiteral("modifySouvenirItemPage"));
        modifySouvenirsListLabel = new QLabel(modifySouvenirItemPage);
        modifySouvenirsListLabel->setObjectName(QStringLiteral("modifySouvenirsListLabel"));
        modifySouvenirsListLabel->setGeometry(QRect(20, 10, 311, 41));
        modifySouvenirsListLabel->setStyleSheet(QStringLiteral("font: 25 30pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        listOfModifyStadiumsSouvenirs = new QTreeWidget(modifySouvenirItemPage);
        listOfModifyStadiumsSouvenirs->setObjectName(QStringLiteral("listOfModifyStadiumsSouvenirs"));
        listOfModifyStadiumsSouvenirs->setGeometry(QRect(30, 170, 521, 311));
        listOfModifyStadiumsSouvenirs->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listOfModifyStadiumsSouvenirs->setEditTriggers(QAbstractItemView::DoubleClicked);
        listOfModifyStadiumsSouvenirs->setAlternatingRowColors(true);
        listOfModifyStadiumsSouvenirs->setSelectionBehavior(QAbstractItemView::SelectRows);
        listOfModifyStadiumsSouvenirs->header()->setDefaultSectionSize(150);
        removeSelectedSouvenir = new QPushButton(modifySouvenirItemPage);
        removeSelectedSouvenir->setObjectName(QStringLiteral("removeSelectedSouvenir"));
        removeSelectedSouvenir->setGeometry(QRect(460, 140, 91, 20));
        removeSelectedSouvenir->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #293539;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
"}"));
        addSelectedSouvenir = new QPushButton(modifySouvenirItemPage);
        addSelectedSouvenir->setObjectName(QStringLiteral("addSelectedSouvenir"));
        addSelectedSouvenir->setGeometry(QRect(470, 490, 81, 21));
        addSelectedSouvenir->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #293539;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
"}"));
        newSouvenirNameLabel = new QLabel(modifySouvenirItemPage);
        newSouvenirNameLabel->setObjectName(QStringLiteral("newSouvenirNameLabel"));
        newSouvenirNameLabel->setGeometry(QRect(30, 490, 59, 16));
        newSouvenirName = new QLineEdit(modifySouvenirItemPage);
        newSouvenirName->setObjectName(QStringLiteral("newSouvenirName"));
        newSouvenirName->setGeometry(QRect(80, 490, 151, 21));
        newSouvenirPriceLabel = new QLabel(modifySouvenirItemPage);
        newSouvenirPriceLabel->setObjectName(QStringLiteral("newSouvenirPriceLabel"));
        newSouvenirPriceLabel->setGeometry(QRect(260, 490, 59, 16));
        newSouvenirPrice = new QLineEdit(modifySouvenirItemPage);
        newSouvenirPrice->setObjectName(QStringLiteral("newSouvenirPrice"));
        newSouvenirPrice->setGeometry(QRect(300, 490, 151, 21));
        adminAddSouvenirErrorMessage = new QLabel(modifySouvenirItemPage);
        adminAddSouvenirErrorMessage->setObjectName(QStringLiteral("adminAddSouvenirErrorMessage"));
        adminAddSouvenirErrorMessage->setGeometry(QRect(30, 520, 241, 20));
        adminAddSouvenirErrorMessage->setStyleSheet(QStringLiteral("color: #01CDE6"));
        modifyStadiumsDescr_2 = new QLabel(modifySouvenirItemPage);
        modifyStadiumsDescr_2->setObjectName(QStringLiteral("modifyStadiumsDescr_2"));
        modifyStadiumsDescr_2->setGeometry(QRect(30, 50, 671, 81));
        display->addWidget(modifySouvenirItemPage);
        adminModifyStadiums = new QWidget();
        adminModifyStadiums->setObjectName(QStringLiteral("adminModifyStadiums"));
        addStadiumFromFileButton = new QPushButton(adminModifyStadiums);
        addStadiumFromFileButton->setObjectName(QStringLiteral("addStadiumFromFileButton"));
        addStadiumFromFileButton->setGeometry(QRect(480, 270, 231, 41));
        addStadiumFromFileButton->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #293539;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
"}"));
        updateAStadiumButton = new QPushButton(adminModifyStadiums);
        updateAStadiumButton->setObjectName(QStringLiteral("updateAStadiumButton"));
        updateAStadiumButton->setGeometry(QRect(60, 500, 231, 41));
        updateAStadiumButton->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #293539;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
"}"));
        modifyStadiumLabel = new QLabel(adminModifyStadiums);
        modifyStadiumLabel->setObjectName(QStringLiteral("modifyStadiumLabel"));
        modifyStadiumLabel->setGeometry(QRect(30, 10, 311, 41));
        modifyStadiumLabel->setStyleSheet(QStringLiteral("font: 25 30pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        stadiumsToModifyList = new QTreeWidget(adminModifyStadiums);
        stadiumsToModifyList->setObjectName(QStringLiteral("stadiumsToModifyList"));
        stadiumsToModifyList->setGeometry(QRect(50, 160, 256, 321));
        line = new QFrame(adminModifyStadiums);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(410, 90, 20, 191));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(adminModifyStadiums);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(410, 330, 16, 221));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        modifyStadiumOrLabel = new QLabel(adminModifyStadiums);
        modifyStadiumOrLabel->setObjectName(QStringLiteral("modifyStadiumOrLabel"));
        modifyStadiumOrLabel->setGeometry(QRect(403, 290, 41, 41));
        modifyStadiumOrLabel->setStyleSheet(QStringLiteral("font: 25 20pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        modifyStadiumsDescr = new QLabel(adminModifyStadiums);
        modifyStadiumsDescr->setObjectName(QStringLiteral("modifyStadiumsDescr"));
        modifyStadiumsDescr->setGeometry(QRect(60, 50, 511, 21));
        modifyStadiumSelectDescr = new QLabel(adminModifyStadiums);
        modifyStadiumSelectDescr->setObjectName(QStringLiteral("modifyStadiumSelectDescr"));
        modifyStadiumSelectDescr->setGeometry(QRect(50, 130, 281, 21));
        display->addWidget(adminModifyStadiums);
        updateStadiumPage = new QWidget();
        updateStadiumPage->setObjectName(QStringLiteral("updateStadiumPage"));
        updateStadiumPage->setStyleSheet(QLatin1String("QLineEdit { \n"
"                        border:1px outset; \n"
"                        border-radius: 1px; \n"
"                        border-color: rgb(114, 114, 114);\n"
"                        color:rgb(0, 0, 0); \n"
"}"));
        modifySouvenirsListLabel_2 = new QLabel(updateStadiumPage);
        modifySouvenirsListLabel_2->setObjectName(QStringLiteral("modifySouvenirsListLabel_2"));
        modifySouvenirsListLabel_2->setGeometry(QRect(40, 10, 311, 41));
        modifySouvenirsListLabel_2->setStyleSheet(QStringLiteral("font: 25 30pt \"Gill Sans\", \"Gill Sans MT Condensed\";"));
        updateLeague = new QFrame(updateStadiumPage);
        updateLeague->setObjectName(QStringLiteral("updateLeague"));
        updateLeague->setGeometry(QRect(40, 170, 621, 46));
        updateLeague->setStyleSheet(QStringLiteral(""));
        updateLeague->setFrameShape(QFrame::StyledPanel);
        updateLeague->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(updateLeague);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        updateLeagueLabel = new QLabel(updateLeague);
        updateLeagueLabel->setObjectName(QStringLiteral("updateLeagueLabel"));
        QFont font11;
        font11.setFamily(QStringLiteral("Futura"));
        font11.setPointSize(14);
        font11.setBold(true);
        font11.setWeight(75);
        updateLeagueLabel->setFont(font11);

        horizontalLayout_5->addWidget(updateLeagueLabel);

        updateAmericanLeague = new QRadioButton(updateLeague);
        updateAmericanLeague->setObjectName(QStringLiteral("updateAmericanLeague"));

        horizontalLayout_5->addWidget(updateAmericanLeague);

        updateNationalLeague = new QRadioButton(updateLeague);
        updateNationalLeague->setObjectName(QStringLiteral("updateNationalLeague"));

        horizontalLayout_5->addWidget(updateNationalLeague);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        frame = new QFrame(updateStadiumPage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(40, 70, 621, 81));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        updateStadiumName = new QFrame(frame);
        updateStadiumName->setObjectName(QStringLiteral("updateStadiumName"));
        updateStadiumName->setGeometry(QRect(10, 3, 601, 41));
        updateStadiumName->setStyleSheet(QLatin1String("border: none;\n"
""));
        updateStadiumName->setFrameShape(QFrame::StyledPanel);
        updateStadiumName->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(updateStadiumName);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        updateStadiumLabel = new QLabel(updateStadiumName);
        updateStadiumLabel->setObjectName(QStringLiteral("updateStadiumLabel"));
        updateStadiumLabel->setFont(font11);

        horizontalLayout_6->addWidget(updateStadiumLabel);

        updateStadium = new QLineEdit(updateStadiumName);
        updateStadium->setObjectName(QStringLiteral("updateStadium"));
        updateStadium->setStyleSheet(QLatin1String("QLineEdit { \n"
"                        border:1px outset; \n"
"                        border-radius: 1px; \n"
"                        border-color: rgb(114, 114, 114);\n"
"                        color:rgb(0, 0, 0); \n"
"}"));
        updateStadium->setCursorPosition(0);

        horizontalLayout_6->addWidget(updateStadium);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);

        updateTeam = new QFrame(frame);
        updateTeam->setObjectName(QStringLiteral("updateTeam"));
        updateTeam->setGeometry(QRect(10, 37, 601, 41));
        updateTeam->setStyleSheet(QLatin1String("border: none;\n"
""));
        updateTeam->setFrameShape(QFrame::StyledPanel);
        updateTeam->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(updateTeam);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        updateStadiumTeamNameLabel = new QLabel(updateTeam);
        updateStadiumTeamNameLabel->setObjectName(QStringLiteral("updateStadiumTeamNameLabel"));
        updateStadiumTeamNameLabel->setFont(font11);

        horizontalLayout_7->addWidget(updateStadiumTeamNameLabel);

        updateTeamName = new QLineEdit(updateTeam);
        updateTeamName->setObjectName(QStringLiteral("updateTeamName"));
        updateTeamName->setStyleSheet(QLatin1String("QLineEdit { \n"
"                        border:1px outset; \n"
"                        border-radius: 1px; \n"
"                        border-color: rgb(114, 114, 114);\n"
"                        color:rgb(0, 0, 0); \n"
"}"));
        updateTeamName->setCursorPosition(0);

        horizontalLayout_7->addWidget(updateTeamName);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_13);

        confirmStadiumUpdateButton = new QPushButton(updateStadiumPage);
        confirmStadiumUpdateButton->setObjectName(QStringLiteral("confirmStadiumUpdateButton"));
        confirmStadiumUpdateButton->setGeometry(QRect(540, 540, 121, 41));
        confirmStadiumUpdateButton->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #01CDE6;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
"}"));
        cancelStadiumUpdatesButton = new QPushButton(updateStadiumPage);
        cancelStadiumUpdatesButton->setObjectName(QStringLiteral("cancelStadiumUpdatesButton"));
        cancelStadiumUpdatesButton->setGeometry(QRect(450, 540, 81, 41));
        cancelStadiumUpdatesButton->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: #293539;\n"
"color: white;\n"
"border:none;\n"
"	font: 75 15pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
"}"));
        updateInformation = new QFrame(updateStadiumPage);
        updateInformation->setObjectName(QStringLiteral("updateInformation"));
        updateInformation->setGeometry(QRect(40, 260, 621, 251));
        updateInformation->setFrameShape(QFrame::StyledPanel);
        updateInformation->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(updateInformation);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        frame_2 = new QFrame(updateInformation);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setStyleSheet(QStringLiteral("border: none;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        updateStreetAddress = new QLineEdit(frame_2);
        updateStreetAddress->setObjectName(QStringLiteral("updateStreetAddress"));
        updateStreetAddress->setGeometry(QRect(100, 30, 191, 20));
        updateStreetAddress->setStyleSheet(QLatin1String("QLineEdit { \n"
"                        border:1px outset; \n"
"                        border-radius: 1px; \n"
"                        border-color: rgb(114, 114, 114);\n"
"}"));
        updateZipcode = new QLineEdit(frame_2);
        updateZipcode->setObjectName(QStringLiteral("updateZipcode"));
        updateZipcode->setGeometry(QRect(420, 60, 171, 20));
        updateZipcode->setStyleSheet(QLatin1String("QLineEdit { \n"
"                        border:1px outset; \n"
"                        border-radius: 1px; \n"
"                        border-color: rgb(114, 114, 114);\n"
"                        color:rgb(0, 0, 0); \n"
"}"));
        updateZipcode->setFrame(true);
        updateCity = new QLineEdit(frame_2);
        updateCity->setObjectName(QStringLiteral("updateCity"));
        updateCity->setGeometry(QRect(100, 60, 191, 20));
        updateCity->setStyleSheet(QLatin1String("QLineEdit { \n"
"                        border:1px outset; \n"
"                        border-radius: 1px; \n"
"                        border-color: rgb(114, 114, 114);\n"
"                        color:rgb(0, 0, 0); \n"
"}"));
        updateState = new QLineEdit(frame_2);
        updateState->setObjectName(QStringLiteral("updateState"));
        updateState->setGeometry(QRect(420, 30, 171, 20));
        updateState->setStyleSheet(QLatin1String("QLineEdit { \n"
"                        border:1px outset; \n"
"                        border-radius: 1px; \n"
"                        border-color: rgb(114, 114, 114);\n"
"                        color:rgb(0, 0, 0); \n"
"}"));
        updateAddress_2 = new QLabel(frame_2);
        updateAddress_2->setObjectName(QStringLiteral("updateAddress_2"));
        updateAddress_2->setGeometry(QRect(20, 30, 55, 20));
        updateAddress_2->setFont(font11);
        updateAddress_3 = new QLabel(frame_2);
        updateAddress_3->setObjectName(QStringLiteral("updateAddress_3"));
        updateAddress_3->setGeometry(QRect(30, 60, 55, 20));
        updateAddress_3->setFont(font11);
        updateAddress_4 = new QLabel(frame_2);
        updateAddress_4->setObjectName(QStringLiteral("updateAddress_4"));
        updateAddress_4->setGeometry(QRect(310, 30, 101, 20));
        updateAddress_4->setFont(font11);
        updateAddress_5 = new QLabel(frame_2);
        updateAddress_5->setObjectName(QStringLiteral("updateAddress_5"));
        updateAddress_5->setGeometry(QRect(310, 60, 101, 20));
        updateAddress_5->setFont(font11);

        gridLayout_4->addWidget(frame_2, 0, 0, 1, 7);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_16, 2, 2, 1, 1);

        updateMonth = new QComboBox(updateInformation);
        updateMonth->setObjectName(QStringLiteral("updateMonth"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(updateMonth->sizePolicy().hasHeightForWidth());
        updateMonth->setSizePolicy(sizePolicy);
        updateMonth->setStyleSheet(QLatin1String("QComboBox::down-arrow {\n"
"		image: url(:/icon/icons/down_arrow.png);\n"
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
        updateMonth->setMaxVisibleItems(12);

        gridLayout_4->addWidget(updateMonth, 3, 4, 1, 1);

        updateYear = new QLineEdit(updateInformation);
        updateYear->setObjectName(QStringLiteral("updateYear"));
        updateYear->setMaximumSize(QSize(100, 16777215));
        updateYear->setInputMethodHints(Qt::ImhNone);
        updateYear->setMaxLength(4);

        gridLayout_4->addWidget(updateYear, 3, 6, 1, 1);

        updateSeatingCapacity = new QSpinBox(updateInformation);
        updateSeatingCapacity->setObjectName(QStringLiteral("updateSeatingCapacity"));
        updateSeatingCapacity->setMaximum(999999999);

        gridLayout_4->addWidget(updateSeatingCapacity, 2, 3, 1, 4);

        updatePhoneNumber = new QLineEdit(updateInformation);
        updatePhoneNumber->setObjectName(QStringLiteral("updatePhoneNumber"));
        updatePhoneNumber->setStyleSheet(QLatin1String("QLineEdit { \n"
"                        border:1px outset; \n"
"                        border-radius: 1px; \n"
"                        border-color: rgb(114, 114, 114);\n"
"                        color:rgb(0, 0, 0); \n"
"}"));
        updatePhoneNumber->setMaxLength(20);

        gridLayout_4->addWidget(updatePhoneNumber, 1, 2, 1, 5);

        updateTypology = new QLineEdit(updateInformation);
        updateTypology->setObjectName(QStringLiteral("updateTypology"));
        updateTypology->setCursorPosition(0);

        gridLayout_4->addWidget(updateTypology, 4, 1, 1, 6);

        label_20 = new QLabel(updateInformation);
        label_20->setObjectName(QStringLiteral("label_20"));
        QFont font12;
        font12.setFamily(QStringLiteral("Futura"));
        label_20->setFont(font12);
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_20, 3, 0, 1, 1);

        label_22 = new QLabel(updateInformation);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setFont(font12);
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_22, 4, 0, 1, 1);

        label_21 = new QLabel(updateInformation);
        label_21->setObjectName(QStringLiteral("label_21"));
        QFont font13;
        font13.setFamily(QStringLiteral("Futura"));
        font13.setPointSize(13);
        label_21->setFont(font13);

        gridLayout_4->addWidget(label_21, 1, 0, 1, 2);

        label_19 = new QLabel(updateInformation);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font12);
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_19, 2, 0, 1, 1);

        updateDay = new QLineEdit(updateInformation);
        updateDay->setObjectName(QStringLiteral("updateDay"));
        updateDay->setMaximumSize(QSize(50, 16777215));
        updateDay->setMaxLength(2);

        gridLayout_4->addWidget(updateDay, 3, 5, 1, 1);

        updateStadiumTeamNameLabel_2 = new QLabel(updateStadiumPage);
        updateStadiumTeamNameLabel_2->setObjectName(QStringLiteral("updateStadiumTeamNameLabel_2"));
        updateStadiumTeamNameLabel_2->setGeometry(QRect(40, 234, 181, 17));
        QFont font14;
        font14.setFamily(QStringLiteral("Futura"));
        font14.setPointSize(20);
        font14.setBold(true);
        font14.setWeight(75);
        updateStadiumTeamNameLabel_2->setFont(font14);
        updateStadiumInvalidErrorMessage = new QLabel(updateStadiumPage);
        updateStadiumInvalidErrorMessage->setObjectName(QStringLiteral("updateStadiumInvalidErrorMessage"));
        updateStadiumInvalidErrorMessage->setGeometry(QRect(40, 520, 371, 16));
        updateStadiumInvalidErrorMessage->setStyleSheet(QStringLiteral("color: red;"));
        display->addWidget(updateStadiumPage);
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
        teamNameLabel->setGeometry(QRect(10, 0, 151, 41));
        teamNameLabel->setStyleSheet(QLatin1String("#teamNameLabel {\n"
"color: white;\n"
"font: 25 30pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
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
"border-image:url(:/icon/icons/magnifying-glass.png);"));
        secretAdminLoginButton = new QToolButton(headerFrame);
        secretAdminLoginButton->setObjectName(QStringLiteral("secretAdminLoginButton"));
        secretAdminLoginButton->setGeometry(QRect(44, 15, 16, 16));
        secretAdminLoginButton->setStyleSheet(QLatin1String("background-color: none;\n"
"color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-image:url(:/icon/icons/baseball.png);"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        adminLoginButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "throw-catch", 0));
        homePageButton->setText(QApplication::translate("MainWindow", "HOME", 0));
        planATripButton->setText(QApplication::translate("MainWindow", "DREAM TRIP", 0));
        viewStadiumsPageButton->setText(QApplication::translate("MainWindow", "VIEW STADIUMS", 0));
        adminHomeButton->setText(QApplication::translate("MainWindow", "HOME", 0));
        adminModifyButton->setText(QApplication::translate("MainWindow", "MODIFY SOUVENIRS", 0));
        viewAdminStadiumsButton->setText(QApplication::translate("MainWindow", "VIEW STADIUMS", 0));
        adminModifyStadiumsButton->setText(QApplication::translate("MainWindow", "MODIFY STADIUMS", 0));
        viewStadiumHeading_2->setText(QApplication::translate("MainWindow", "HOME", 0));
        label_2->setText(QString());
        viewStadiumHeading_3->setText(QApplication::translate("MainWindow", "Hi there! The basebal vacaction planner was created so you can experience your dream vacation to all  ", 0));
        label->setText(QString());
        viewStadiumHeading_4->setText(QApplication::translate("MainWindow", "your favorite baseball stadiums.", 0));
        viewStadiumHeading_5->setText(QApplication::translate("MainWindow", "You can view stadiums, and can even view only American or National stadiums, along with sorting the stadiums by their attributes. Next, you can plan your dream trip and virtually take the trip. On each trip you take, you can purchase souvenirs as a memory!\n"
"\n"
"            Happy traveling!", 0));
        viewStadiumHeading->setText(QApplication::translate("MainWindow", "VIEW STADIUMS", 0));
        label_3->setText(QApplication::translate("MainWindow", "View by:", 0));
        viewStadiumByComboBox->clear();
        viewStadiumByComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "All", 0)
         << QApplication::translate("MainWindow", "American", 0)
         << QApplication::translate("MainWindow", "National", 0)
        );
        QTreeWidgetItem *___qtreewidgetitem = viewStadiumsList->headerItem();
        ___qtreewidgetitem->setText(6, QApplication::translate("MainWindow", "Typology", 0));
        ___qtreewidgetitem->setText(5, QApplication::translate("MainWindow", "Date Opened", 0));
        ___qtreewidgetitem->setText(4, QApplication::translate("MainWindow", "Surface", 0));
        ___qtreewidgetitem->setText(3, QApplication::translate("MainWindow", "Location", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindow", "Capacity", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Team", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Stadium", 0));
        singleStadiumNameLabel->setText(QApplication::translate("MainWindow", "STADIUM_NAME", 0));
        label_9->setText(QApplication::translate("MainWindow", "Team name:", 0));
        label_12->setText(QApplication::translate("MainWindow", "Type of League:", 0));
        label_8->setText(QApplication::translate("MainWindow", "Address:", 0));
        label_5->setText(QApplication::translate("MainWindow", "Box office number:", 0));
        label_6->setText(QApplication::translate("MainWindow", "Date opened:", 0));
        label_10->setText(QApplication::translate("MainWindow", "Seating capacity:", 0));
        label_11->setText(QApplication::translate("MainWindow", "Surface:", 0));
        totalRevenueLabel->setText(QApplication::translate("MainWindow", "Total revenue:", 0));
        singleStadiumTeamName->setText(QApplication::translate("MainWindow", "team_name", 0));
        singleStadiumType->setText(QApplication::translate("MainWindow", "type_of_league", 0));
        singleStadiumAddress->setText(QApplication::translate("MainWindow", "address", 0));
        singleStadiumBoxOfficeNum->setText(QApplication::translate("MainWindow", "box_office_number", 0));
        singleStadiumDateOpened->setText(QApplication::translate("MainWindow", "date_opened", 0));
        singleStadiumSeatingCapacity->setText(QApplication::translate("MainWindow", "seating_capacity", 0));
        singleStadiumSurface->setText(QApplication::translate("MainWindow", "surface", 0));
        singleStadiumTotalRevenue->setText(QApplication::translate("MainWindow", "total_revenue", 0));
        shortestTripToAllButton->setText(QApplication::translate("MainWindow", "QUICK TRIP", 0));
        customTripButton->setText(QApplication::translate("MainWindow", "CUSTOM TRIP", 0));
        minimumSpanningTreeButton->setText(QApplication::translate("MainWindow", "GENERATE MINIMUM SPANNING TREE", 0));
        planATripLabel->setText(QApplication::translate("MainWindow", "PLAN A TRIP", 0));
        label_4->setText(QString());
        quickTripLabel->setText(QApplication::translate("MainWindow", "QUICK TRIP", 0));
        QTreeWidgetItem *___qtreewidgetitem1 = quickTripList->headerItem();
        ___qtreewidgetitem1->setText(1, QApplication::translate("MainWindow", "Distance from Starting Stadium", 0));
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Stadium", 0));
        quickTripStartingStadiumLabel->setText(QApplication::translate("MainWindow", "Starting stadium:", 0));
        quickTripStartingStadium->setText(QApplication::translate("MainWindow", "starting_stadium", 0));
        quickTripDescription->setText(QApplication::translate("MainWindow", "Please select a stadium you would like to quickly visit to from the starting stadium, Dodger Stadium. Once the stadium is selected, press the button 'Take Trip'. Happy traveling!", 0));
        quickTripTakeTripButton->setText(QApplication::translate("MainWindow", "TAKE TRIP", 0));
        customTripLabel->setText(QApplication::translate("MainWindow", "PLAN CUSTOM TRIP", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = stadiumsToSelectFromList->headerItem();
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "Stadiums to Select From", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = selectedStadiumsList->headerItem();
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "Itinerary", 0));
        confirmCustomTripButton->setText(QApplication::translate("MainWindow", "TAKE TRIP", 0));
        startingStadiumLabel->setText(QApplication::translate("MainWindow", "Please select your starting stadium:", 0));
        removeFromItineraryButton->setText(QString());
        addToItineraryButton->setText(QString());
        planATripLabel_2->setText(QApplication::translate("MainWindow", "MINIMUM SPANNING TREE", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = MSTList->headerItem();
        ___qtreewidgetitem4->setText(2, QApplication::translate("MainWindow", "weight", 0));
        ___qtreewidgetitem4->setText(1, QApplication::translate("MainWindow", "destination", 0));
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "origin", 0));
        planATripLabel_3->setText(QApplication::translate("MainWindow", "total weight:", 0));
        mstTotalWeight->setText(QApplication::translate("MainWindow", "---- miles", 0));
        currentTripStadiumNameLabel->setText(QApplication::translate("MainWindow", "STADIUM_NAME", 0));
        addSouvenirToShoppingCart->setText(QApplication::translate("MainWindow", "+ Add to cart", 0));
        currentTripWelcomeDescription->setText(QApplication::translate("MainWindow", "Welcome, you have arrived at your destination. ", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = listOfCurrentStadiumSouvenirs->headerItem();
        ___qtreewidgetitem5->setText(2, QApplication::translate("MainWindow", "Quantity", 0));
        ___qtreewidgetitem5->setText(1, QApplication::translate("MainWindow", "Price", 0));
        ___qtreewidgetitem5->setText(0, QApplication::translate("MainWindow", "Name", 0));
        currentTripNextButtonLabel->setText(QApplication::translate("MainWindow", "Click 'NEXT' to travel to your next stadium.", 0));
        currentTripSouvenirLabel->setText(QApplication::translate("MainWindow", "SOUVENIRS", 0));
        currentTripNextStadium->setText(QApplication::translate("MainWindow", "NEXT", 0));
        shoppingCartButton->setText(QString());
        currentTripProgressBar->setFormat(QString());
        currentTripProgressLabel->setText(QApplication::translate("MainWindow", "TRIP PROGRESS", 0));
        currentTripStadiumCount->setText(QApplication::translate("MainWindow", "_/_ stadiums have been visited.", 0));
        currentTripStadiumCount_2->setText(QApplication::translate("MainWindow", "You have traveled                                       miles", 0));
        travelGif->setText(QString());
        travelToName->setText(QApplication::translate("MainWindow", "travel_to_name", 0));
        travelFromName->setText(QApplication::translate("MainWindow", "travel_from_name", 0));
        confirmPurchasesLabel->setText(QApplication::translate("MainWindow", "CONFIRM YOUR PURCHASES", 0));
        grandTotalLabel->setText(QApplication::translate("MainWindow", "GRAND TOTAL:", 0));
        grandTotalAmount->setText(QApplication::translate("MainWindow", "$0.00", 0));
        QTreeWidgetItem *___qtreewidgetitem6 = shoppingCart->headerItem();
        ___qtreewidgetitem6->setText(4, QApplication::translate("MainWindow", "Total", 0));
        ___qtreewidgetitem6->setText(3, QApplication::translate("MainWindow", "Quantity", 0));
        ___qtreewidgetitem6->setText(2, QApplication::translate("MainWindow", "Subtotal", 0));
        ___qtreewidgetitem6->setText(1, QApplication::translate("MainWindow", "Name", 0));
        ___qtreewidgetitem6->setText(0, QApplication::translate("MainWindow", "Remove", 0));
        shoppingCartLabel->setText(QApplication::translate("MainWindow", "SHOPPING CART", 0));
        confirmPurchasesButton->setText(QApplication::translate("MainWindow", "CONFIRM", 0));
        shoppingCartEmpty->setText(QApplication::translate("MainWindow", "Your shopping cart is currently empty!", 0));
        grandTotalLabel_2->setText(QApplication::translate("MainWindow", "TOTAL DISTANCE:", 0));
        usernameLabel->setText(QApplication::translate("MainWindow", "Username", 0));
        passwordLabel->setText(QApplication::translate("MainWindow", "Password", 0));
        loginButton->setText(QApplication::translate("MainWindow", "LOGIN", 0));
        adminLoginErrorMessage->setText(QApplication::translate("MainWindow", "Invalid username or password.", 0));
        adminLoginLabel->setText(QApplication::translate("MainWindow", "ADMIN LOGIN", 0));
        adminHomePageLabel->setText(QApplication::translate("MainWindow", "ADMIN HOME PAGE", 0));
        QTreeWidgetItem *___qtreewidgetitem7 = adminStadiumList->headerItem();
        ___qtreewidgetitem7->setText(1, QApplication::translate("MainWindow", "Total Revenue", 0));
        ___qtreewidgetitem7->setText(0, QApplication::translate("MainWindow", "Stadium", 0));
        adminHomePageLabel_2->setText(QApplication::translate("MainWindow", "STADIUMS", 0));
        viewMoreInfoAboutStadiumButton->setText(QApplication::translate("MainWindow", "VIEW MORE INFO", 0));
        label_7->setText(QApplication::translate("MainWindow", "If you would like to view more information about the stadium, please select one of the following stadiums and click the 'VIEW MORE INFO' button.", 0));
        stadiumTotalRevenue->setText(QApplication::translate("MainWindow", "$0.00", 0));
        stadiumTotalRevenueLabel->setText(QApplication::translate("MainWindow", "GRAND TOTAL REVENUE:", 0));
        modifyInformationLabel->setText(QApplication::translate("MainWindow", "MODIFY INFORMATION", 0));
        modifyDescription->setText(QApplication::translate("MainWindow", "Select a stadium you would like to modify one or more of its souvenirs.", 0));
        QTreeWidgetItem *___qtreewidgetitem8 = listOfModifyStadiums->headerItem();
        ___qtreewidgetitem8->setText(0, QApplication::translate("MainWindow", "Stadium", 0));
        modifyInformationNextButton->setText(QApplication::translate("MainWindow", "NEXT", 0));
        modifySouvenirsListLabel->setText(QApplication::translate("MainWindow", "SOUVENIRS", 0));
        QTreeWidgetItem *___qtreewidgetitem9 = listOfModifyStadiumsSouvenirs->headerItem();
        ___qtreewidgetitem9->setText(1, QApplication::translate("MainWindow", "Price", 0));
        ___qtreewidgetitem9->setText(0, QApplication::translate("MainWindow", "Name", 0));
        removeSelectedSouvenir->setText(QApplication::translate("MainWindow", "DELETE", 0));
        addSelectedSouvenir->setText(QApplication::translate("MainWindow", "ADD", 0));
        newSouvenirNameLabel->setText(QApplication::translate("MainWindow", "Name:", 0));
        newSouvenirPriceLabel->setText(QApplication::translate("MainWindow", "Price", 0));
        adminAddSouvenirErrorMessage->setText(QApplication::translate("MainWindow", "*** Invalid name or price.", 0));
        modifyStadiumsDescr_2->setText(QApplication::translate("MainWindow", "To modify a souvenir you can do any of the following:\n"
"     1. ADD:        Input a name and a price for the new souvenir, then press the 'ADD' button.\n"
"     2. DELETE:  Select a souvenir and press the 'DELETE' button.\n"
"     3. UPDATE:  Double click on the souvenir that you would like to update, then press 'enter' on your keyboard.\n"
"", 0));
        addStadiumFromFileButton->setText(QApplication::translate("MainWindow", "ADD STADIUMS FROM FILE", 0));
        updateAStadiumButton->setText(QApplication::translate("MainWindow", "UPDATE A STADIUM", 0));
        modifyStadiumLabel->setText(QApplication::translate("MainWindow", "MODIFY STADIUMS", 0));
        QTreeWidgetItem *___qtreewidgetitem10 = stadiumsToModifyList->headerItem();
        ___qtreewidgetitem10->setText(0, QApplication::translate("MainWindow", "Stadium", 0));
        modifyStadiumOrLabel->setText(QApplication::translate("MainWindow", "OR", 0));
        modifyStadiumsDescr->setText(QApplication::translate("MainWindow", "You can either update a stadium's information or add new stadiums from a file.", 0));
        modifyStadiumSelectDescr->setText(QApplication::translate("MainWindow", "Select a stadium you would like to update.", 0));
        modifySouvenirsListLabel_2->setText(QApplication::translate("MainWindow", "UPDATE A STADIUM", 0));
        updateLeagueLabel->setText(QApplication::translate("MainWindow", "League: ", 0));
        updateAmericanLeague->setText(QApplication::translate("MainWindow", "American", 0));
        updateNationalLeague->setText(QApplication::translate("MainWindow", "National", 0));
        updateStadiumLabel->setText(QApplication::translate("MainWindow", "Stadium:", 0));
        updateStadium->setText(QString());
        updateStadium->setPlaceholderText(QApplication::translate("MainWindow", "Stadium name", 0));
        updateStadiumTeamNameLabel->setText(QApplication::translate("MainWindow", "Team name:", 0));
        updateTeamName->setText(QString());
        updateTeamName->setPlaceholderText(QApplication::translate("MainWindow", "Team name", 0));
        confirmStadiumUpdateButton->setText(QApplication::translate("MainWindow", "CONFIRM", 0));
        cancelStadiumUpdatesButton->setText(QApplication::translate("MainWindow", "CANCEL", 0));
        updateStreetAddress->setPlaceholderText(QApplication::translate("MainWindow", "Street Address", 0));
        updateZipcode->setPlaceholderText(QApplication::translate("MainWindow", "Zipcode", 0));
        updateCity->setPlaceholderText(QApplication::translate("MainWindow", "City", 0));
        updateState->setPlaceholderText(QApplication::translate("MainWindow", "State or Country", 0));
        updateAddress_2->setText(QApplication::translate("MainWindow", "Street:", 0));
        updateAddress_3->setText(QApplication::translate("MainWindow", "City:", 0));
        updateAddress_4->setText(QApplication::translate("MainWindow", "State/Country:", 0));
        updateAddress_5->setText(QApplication::translate("MainWindow", "Zipcode:", 0));
        updateMonth->clear();
        updateMonth->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Month", 0)
         << QApplication::translate("MainWindow", "January", 0)
         << QApplication::translate("MainWindow", "February", 0)
         << QApplication::translate("MainWindow", "March", 0)
         << QApplication::translate("MainWindow", "April", 0)
         << QApplication::translate("MainWindow", "May", 0)
         << QApplication::translate("MainWindow", "June", 0)
         << QApplication::translate("MainWindow", "July", 0)
         << QApplication::translate("MainWindow", "August", 0)
         << QApplication::translate("MainWindow", "September", 0)
         << QApplication::translate("MainWindow", "October", 0)
         << QApplication::translate("MainWindow", "November", 0)
         << QApplication::translate("MainWindow", "December", 0)
        );
        updateMonth->setCurrentText(QApplication::translate("MainWindow", "Month", 0));
        updateYear->setPlaceholderText(QApplication::translate("MainWindow", "Year", 0));
        updateSeatingCapacity->setSpecialValueText(QString());
        updatePhoneNumber->setPlaceholderText(QApplication::translate("MainWindow", "Box office number", 0));
        updateTypology->setText(QString());
        updateTypology->setPlaceholderText(QApplication::translate("MainWindow", "Typology", 0));
        label_20->setText(QApplication::translate("MainWindow", "Opening date:", 0));
        label_22->setText(QApplication::translate("MainWindow", "Typology:", 0));
        label_21->setText(QApplication::translate("MainWindow", "Box office number:", 0));
        label_19->setText(QApplication::translate("MainWindow", "Seating capacity:", 0));
        updateDay->setPlaceholderText(QApplication::translate("MainWindow", "Day", 0));
        updateStadiumTeamNameLabel_2->setText(QApplication::translate("MainWindow", "Information", 0));
        updateStadiumInvalidErrorMessage->setText(QApplication::translate("MainWindow", "* All invalid text inputs are highlighted in red.", 0));
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
