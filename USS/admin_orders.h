#ifndef ADMIN_ORDERS_H
#define ADMIN_ORDERS_H

#include <QWidget>
#include "admin_orders_add.h"
#include "admin_orders_dele.h"

namespace Ui {
class Admin_Orders;
}

class Admin_Orders : public QWidget
{
    Q_OBJECT

public:
    explicit Admin_Orders(QWidget *parent = 0);
    ~Admin_Orders();
    void init();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_refresh_clicked();

    void on_pushButton_dele_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::Admin_Orders *ui;
    Admin_Orders_Add *add;
    Admin_Orders_Dele *dele;
};

#endif // ADMIN_ORDERS_H
