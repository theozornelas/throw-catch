#include "shoppingcart.h"
#include "ui_shoppingcart.h"

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
