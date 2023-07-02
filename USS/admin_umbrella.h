#ifndef ADMIN_UMBRELLA_H
#define ADMIN_UMBRELLA_H

#include <QWidget>
#include "admin_umbrella_add.h"
#include "admin_umbrella_dele.h"

namespace Ui {
class Admin_Umbrella;
}

class Admin_Umbrella : public QWidget
{
    Q_OBJECT

public:
    explicit Admin_Umbrella(QWidget *parent = 0);
    ~Admin_Umbrella();
    void init();

private slots:
    void on_pushButton_ubadd_clicked();

    void on_pushButton_ubrf_clicked();

    void on_pushButton_ubdelete_clicked();

    void on_pushButton_ubfind_clicked();

private:
    Ui::Admin_Umbrella *ui;
    Admin_Umbrella_Add *add;
    Admin_Umbrella_Dele *dele;
};

#endif // ADMIN_UMBRELLA_H
