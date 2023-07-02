#ifndef ADMIN_PLACE_H
#define ADMIN_PLACE_H

#include <QWidget>
#include "admin_place_add.h"
#include "admin_place_dele.h"

namespace Ui {
class Admin_Place;
}

class Admin_Place : public QWidget
{
    Q_OBJECT

public:
    explicit Admin_Place(QWidget *parent = 0);
    ~Admin_Place();
    void init();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_dele_clicked();

private:
    Ui::Admin_Place *ui;
    Admin_Place_Add *add;
    Admin_Place_Dele *dele;
};

#endif // ADMIN_PLACE_H
