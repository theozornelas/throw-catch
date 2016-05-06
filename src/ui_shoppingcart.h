/********************************************************************************
** Form generated from reading UI file 'shoppingcart.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
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

class Ui_Form
{
public:
    QTreeWidget *shoppingCartList;
    QFrame *header;
    QLabel *teamNameLabel;
    QLabel *shoppingCartLabel;
    QLabel *grandTotalLabel;
    QLabel *grandTotalAmountLabel;
    QLabel *emptyShoppingCartLabel;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(593, 492);
        shoppingCartList = new QTreeWidget(Form);
        shoppingCartList->setObjectName(QStringLiteral("shoppingCartList"));
        shoppingCartList->setGeometry(QRect(40, 100, 511, 291));
        shoppingCartList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        shoppingCartList->setAlternatingRowColors(true);
        shoppingCartList->header()->setDefaultSectionSize(130);
        header = new QFrame(Form);
        header->setObjectName(QStringLiteral("header"));
        header->setGeometry(QRect(0, 0, 601, 41));
        header->setStyleSheet(QLatin1String("#headerFrame {\n"
"background: #01CDE6;\n"
"border: none;\n"
"}"));
        header->setFrameShape(QFrame::StyledPanel);
        header->setFrameShadow(QFrame::Raised);
        teamNameLabel = new QLabel(header);
        teamNameLabel->setObjectName(QStringLiteral("teamNameLabel"));
        teamNameLabel->setGeometry(QRect(10, 10, 161, 21));
        teamNameLabel->setStyleSheet(QLatin1String("#teamNameLabel {\n"
"color: white;\n"
"	font: 75 20pt \"Gill Sans\";\n"
"}"));
        shoppingCartLabel = new QLabel(Form);
        shoppingCartLabel->setObjectName(QStringLiteral("shoppingCartLabel"));
        shoppingCartLabel->setGeometry(QRect(40, 60, 241, 31));
        shoppingCartLabel->setStyleSheet(QLatin1String("font: 75 30pt \"Gill Sans\";\n"
"color: rgb(61, 61, 61);\n"
""));
        grandTotalLabel = new QLabel(Form);
        grandTotalLabel->setObjectName(QStringLiteral("grandTotalLabel"));
        grandTotalLabel->setGeometry(QRect(290, 400, 141, 31));
        grandTotalLabel->setStyleSheet(QLatin1String("font: 75 30pt \"Gill Sans\";\n"
"color: rgb(61, 61, 61);\n"
""));
        grandTotalAmountLabel = new QLabel(Form);
        grandTotalAmountLabel->setObjectName(QStringLiteral("grandTotalAmountLabel"));
        grandTotalAmountLabel->setGeometry(QRect(440, 408, 91, 21));
        QFont font;
        font.setPointSize(22);
        grandTotalAmountLabel->setFont(font);
        emptyShoppingCartLabel = new QLabel(Form);
        emptyShoppingCartLabel->setObjectName(QStringLiteral("emptyShoppingCartLabel"));
        emptyShoppingCartLabel->setGeometry(QRect(60, 100, 391, 16));
        header->raise();
        shoppingCartLabel->raise();
        grandTotalLabel->raise();
        grandTotalAmountLabel->raise();
        emptyShoppingCartLabel->raise();
        shoppingCartList->raise();

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        QTreeWidgetItem *___qtreewidgetitem = shoppingCartList->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("Form", "Total", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("Form", "Qty", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("Form", "Sub-total", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("Form", "Stadium", 0));
        teamNameLabel->setText(QApplication::translate("Form", "throw-catch", 0));
        shoppingCartLabel->setText(QApplication::translate("Form", "SHOPPING CART", 0));
        grandTotalLabel->setText(QApplication::translate("Form", "Grand total:", 0));
        grandTotalAmountLabel->setText(QApplication::translate("Form", "$0.00", 0));
        emptyShoppingCartLabel->setText(QApplication::translate("Form", "Your shopping cart is currently empty! ", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPINGCART_H
