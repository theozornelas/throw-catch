/********************************************************************************
** Form generated from reading UI file 'shoppingcart.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPINGCART_H
#define UI_SHOPPINGCART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShoppingCart
{
public:
    QFrame *headerFrame;
    QLabel *teamNameLabel;
    QTreeWidget *shoppingCart;
    QLabel *shoppingCartLabel;
    QLabel *grandTotalLabel;
    QLabel *grandTotalAmount;
    QLabel *label;

    void setupUi(QWidget *ShoppingCart)
    {
        if (ShoppingCart->objectName().isEmpty())
            ShoppingCart->setObjectName(QStringLiteral("ShoppingCart"));
        ShoppingCart->resize(570, 470);
        headerFrame = new QFrame(ShoppingCart);
        headerFrame->setObjectName(QStringLiteral("headerFrame"));
        headerFrame->setGeometry(QRect(0, 0, 571, 41));
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
"font: 25 20pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
"}"));
        shoppingCart = new QTreeWidget(ShoppingCart);
        shoppingCart->setObjectName(QStringLiteral("shoppingCart"));
        shoppingCart->setGeometry(QRect(40, 100, 471, 311));
        shoppingCart->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        shoppingCart->header()->setDefaultSectionSize(133);
        shoppingCartLabel = new QLabel(ShoppingCart);
        shoppingCartLabel->setObjectName(QStringLiteral("shoppingCartLabel"));
        shoppingCartLabel->setGeometry(QRect(170, 60, 201, 31));
        shoppingCartLabel->setStyleSheet(QLatin1String("font: 25 25pt \"Gill Sans\", \"Gill Sans MT Condensed\";\n"
"color: rgb(68, 68, 68);\n"
""));
        grandTotalLabel = new QLabel(ShoppingCart);
        grandTotalLabel->setObjectName(QStringLiteral("grandTotalLabel"));
        grandTotalLabel->setGeometry(QRect(200, 420, 151, 31));
        grandTotalLabel->setStyleSheet(QLatin1String("font: 75 20pt \"Helvetica\";\n"
"color: rgb(32, 32, 32)\n"
""));
        grandTotalAmount = new QLabel(ShoppingCart);
        grandTotalAmount->setObjectName(QStringLiteral("grandTotalAmount"));
        grandTotalAmount->setGeometry(QRect(350, 424, 121, 21));
        QFont font;
        font.setPointSize(23);
        grandTotalAmount->setFont(font);
        label = new QLabel(ShoppingCart);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 110, 261, 16));
        label->raise();
        headerFrame->raise();
        shoppingCart->raise();
        shoppingCartLabel->raise();
        grandTotalLabel->raise();
        grandTotalAmount->raise();

        retranslateUi(ShoppingCart);

        QMetaObject::connectSlotsByName(ShoppingCart);
    } // setupUi

    void retranslateUi(QWidget *ShoppingCart)
    {
        ShoppingCart->setWindowTitle(QApplication::translate("ShoppingCart", "Form", 0));
        teamNameLabel->setText(QApplication::translate("ShoppingCart", "throw-catch", 0));
        QTreeWidgetItem *___qtreewidgetitem = shoppingCart->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("ShoppingCart", "Total", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("ShoppingCart", "Quantity", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("ShoppingCart", "Subtotal", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("ShoppingCart", "Name", 0));
        shoppingCartLabel->setText(QApplication::translate("ShoppingCart", "SHOPPING CART", 0));
        grandTotalLabel->setText(QApplication::translate("ShoppingCart", "GRAND TOTAL:", 0));
        grandTotalAmount->setText(QApplication::translate("ShoppingCart", "$0.00", 0));
        label->setText(QApplication::translate("ShoppingCart", "Your shopping cart is currently empty!", 0));
    } // retranslateUi

};

namespace Ui {
    class ShoppingCart: public Ui_ShoppingCart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPINGCART_H
