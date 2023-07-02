#ifndef ADMIN_ORDERS_ADD_H
#define ADMIN_ORDERS_ADD_H

#include <QWidget>

namespace Ui {
class Admin_Orders_Add;
}

class Admin_Orders_Add : public QWidget
{
    Q_OBJECT

public:
    explicit Admin_Orders_Add(QWidget *parent = 0);
    ~Admin_Orders_Add();

private slots:
    void on_pushButton_ok_clicked();

    void on_radioButton_clicked();

private:
    Ui::Admin_Orders_Add *ui;
};

#endif // ADMIN_ORDERS_ADD_H
