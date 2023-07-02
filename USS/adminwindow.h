#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QWidget>
#include "admin_umbrella.h"
#include "admin_user.h"
#include "admin_place.h"
#include "admin_orders.h"

namespace Ui {
class Adminwindow;
}

class Adminwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Adminwindow(QWidget *parent = 0);
    ~Adminwindow();

private slots:
    void on_pushButton_umbrella_clicked();

    void on_pushButton_user_clicked();

    void on_pushButton_place_clicked();

    void on_pushButton_return_clicked();

    void on_pushButton_orders_clicked();

private:
    Ui::Adminwindow *ui;
    Admin_Umbrella *aub;
    Admin_User *aus;
    Admin_Place *ap;
    Admin_Orders *ao;
};

#endif // ADMINWINDOW_H
