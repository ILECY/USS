#ifndef ADMIN_USER_H
#define ADMIN_USER_H

#include <QWidget>
#include "admin_user_add.h"
#include "admin_user_dele.h"

namespace Ui {
class Admin_User;
}

class Admin_User : public QWidget
{
    Q_OBJECT

public:
    explicit Admin_User(QWidget *parent = 0);
    ~Admin_User();
    void init();

private slots:
    void on_pushButton_usadd_clicked();

    void on_pushButton_usrf_clicked();

    void on_pushButton_usdelete_clicked();

    void on_pushButton_usfind_clicked();

private:
    Ui::Admin_User *ui;
    Admin_User_Add *add;
    Admin_User_dele *dele;
};

#endif // ADMIN_USER_H
