#ifndef ADMIN_USER_ADD_H
#define ADMIN_USER_ADD_H

#include <QWidget>

namespace Ui {
class Admin_User_Add;
}

class Admin_User_Add : public QWidget
{
    Q_OBJECT

public:
    explicit Admin_User_Add(QWidget *parent = 0);
    ~Admin_User_Add();

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::Admin_User_Add *ui;
};

#endif // ADMIN_USER_ADD_H
