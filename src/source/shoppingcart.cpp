#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include "../header/shoppingcart.h"


ShoppingCart::ShoppingCart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShoppingCart)
{
    ui->setupUi(this);
}

ShoppingCart::~ShoppingCart()
{
    delete ui;
}

void ShoppingCart::setList(QVector<Souvenir*> shoppingCart, skiplist<int, Stadium*> stadiums) {

    if(shoppingCart.empty()) {
        ui->shoppingCart->hide();
    }
    else {
        ui->shoppingCart->clear();

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

            QTreeWidgetItem *itm = new QTreeWidgetItem();

            itm->setText(0, souvenirName);
            itm->setText(1, "$" + QString::number(subtotal, 'f', 2));
            itm->setTextAlignment(1, Qt::AlignCenter);
            itm->setText(2, QString::number(qty));
            itm->setTextAlignment(2, Qt::AlignCenter);
            itm->setText(3, "$" + QString::number(souvenirTotal, 'f', 2));
            itm->setTextAlignment(3, Qt::AlignCenter);

            stadiumTotal += souvenirTotal;
            grandTotal += stadiumTotal;


            parent->addChild(itm);
            // Iterator increments to the next node
            it++;
        }

        parent->setText(3, QString::number(stadiumTotal, 'f', 2));
        stadiumTotal = 0;

        grandTotal += stadiumTotal;
        ui->grandTotalAmount->setText("$" + QString::number(grandTotal, 'f', 2));



    }
}
