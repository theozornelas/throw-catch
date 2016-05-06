#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QWidget>
#include <list>
#include <iterator>
#include "souvenir.h"

namespace Ui {
class shoppingcart;
}

class shoppingcart : public QWidget
{
    Q_OBJECT

public:
    explicit shoppingcart(QWidget *parent = 0);
    ~shoppingcart();
    void setList(list<Souvenir*> shoppingCart);


private:
    Ui::shoppingcart *ui;
};

#endif // SHOPPINGCART_H
