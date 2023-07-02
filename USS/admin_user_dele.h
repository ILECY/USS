#ifndef ADMIN_USER_DELE_H
#define ADMIN_USER_DELE_H

#include <QWidget>

namespace Ui {
class Admin_User_dele;
}

class Admin_User_dele : public QWidget
{
    Q_OBJECT

public:
    explicit Admin_User_dele(QWidget *parent = 0);
    ~Admin_User_dele();

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButto_ok_clicked();

private:
    Ui::Admin_User_dele *ui;
};

#endif // ADMIN_USER_DELE_H
