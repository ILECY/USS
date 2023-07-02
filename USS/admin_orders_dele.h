#ifndef ADMIN_ORDERS_DELE_H
#define ADMIN_ORDERS_DELE_H

#include <QWidget>

namespace Ui {
class Admin_Orders_Dele;
}

class Admin_Orders_Dele : public QWidget
{
    Q_OBJECT

public:
    explicit Admin_Orders_Dele(QWidget *parent = 0);
    ~Admin_Orders_Dele();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Admin_Orders_Dele *ui;
};

#endif // ADMIN_ORDERS_DELE_H
