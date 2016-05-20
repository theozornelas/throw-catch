#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QWidget>
#include <list>
#include <iterator>
#include "souvenir.h"
#include "stadium.h"
#include "skiplist.h"

namespace Ui {
class ShoppingCart;
}

class ShoppingCart : public QWidget
{
    Q_OBJECT

public:
    explicit ShoppingCart(QWidget *parent = 0);
    ~ShoppingCart();

    /** ACCESSORS **/
    // Initializes the list, and set the QTreeWidget within the ui.
    void setList(QVector<Souvenir*> shoppingCart, skiplist<int, Stadium*> stadiums);


private:
    Ui::ShoppingCart *ui;
};

#endif // SHOPPINGCART_H
