#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include "../header/shoppingcart.h"

#include <QDebug>
#include "souvenir.h"
#include <list>

shoppingcart::shoppingcart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shoppingcart)
{
    ui->setupUi(this);

}

shoppingcart::~shoppingcart()
{
    delete ui;
}
void shoppingcart:: setList(list<Souvenir*> shoppingCart)
{
  if(shoppingCart.empty()) {

  }
}


