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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
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
    QStackedWidget *display;
    QWidget *homePage;
    QLabel *homeHeading;
    QWidget *viewStadiumsPage;
    QLabel *viewStadiumHeading;
    QFrame *headerFrame;
    QLabel *teamNameLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(867, 591);
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
        options->setGeometry(QRect(0, 20, 241, 581));
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
        sidebarFrame->setGeometry(QRect(0, -10, 251, 631));
        sidebarFrame->setStyleSheet(QLatin1String("#sidebarFrame {\n"
"background: #293539;\n"
"border: none;\n"
"}"));
        sidebarFrame->setFrameShape(QFrame::StyledPanel);
        sidebarFrame->setFrameShadow(QFrame::Raised);
        homePageButton = new QPushButton(sidebarFrame);
        homePageButton->setObjectName(QStringLiteral("homePageButton"));
        homePageButton->setGeometry(QRect(0, 214, 241, 61));
        planATripButton = new QPushButton(sidebarFrame);
        planATripButton->setObjectName(QStringLiteral("planATripButton"));
        planATripButton->setGeometry(QRect(0, 340, 241, 61));
        viewStadiumsPageButton = new QPushButton(sidebarFrame);
        viewStadiumsPageButton->setObjectName(QStringLiteral("viewStadiumsPageButton"));
        viewStadiumsPageButton->setGeometry(QRect(0, 277, 241, 61));
        options->addWidget(customerOptions);
        adminOptions = new QWidget();
        adminOptions->setObjectName(QStringLiteral("adminOptions"));
        options->addWidget(adminOptions);
        display = new QStackedWidget(centralWidget);
        display->setObjectName(QStringLiteral("display"));
        display->setGeometry(QRect(240, 20, 631, 571));
        display->setStyleSheet(QLatin1String("\n"
"background-color: #EAEAE9\n"
""));
        homePage = new QWidget();
        homePage->setObjectName(QStringLiteral("homePage"));
        homeHeading = new QLabel(homePage);
        homeHeading->setObjectName(QStringLiteral("homeHeading"));
        homeHeading->setGeometry(QRect(20, 30, 201, 31));
        display->addWidget(homePage);
        viewStadiumsPage = new QWidget();
        viewStadiumsPage->setObjectName(QStringLiteral("viewStadiumsPage"));
        viewStadiumHeading = new QLabel(viewStadiumsPage);
        viewStadiumHeading->setObjectName(QStringLiteral("viewStadiumHeading"));
        viewStadiumHeading->setGeometry(QRect(20, 30, 181, 16));
        display->addWidget(viewStadiumsPage);
        headerFrame = new QFrame(centralWidget);
        headerFrame->setObjectName(QStringLiteral("headerFrame"));
        headerFrame->setGeometry(QRect(0, 0, 871, 41));
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
        homeHeading->setText(QApplication::translate("MainWindow", "HOME", 0));
        viewStadiumHeading->setText(QApplication::translate("MainWindow", "VIEW STADIUMS", 0));
        teamNameLabel->setText(QApplication::translate("MainWindow", "throw-catch", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
