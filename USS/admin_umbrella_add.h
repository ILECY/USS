#ifndef ADMIN_UMBRELLA_ADD_H
#define ADMIN_UMBRELLA_ADD_H

#include <QWidget>

namespace Ui {
class Admin_Umbrella_Add;
}

class Admin_Umbrella_Add : public QWidget
{
    Q_OBJECT

public:
    explicit Admin_Umbrella_Add(QWidget *parent = 0);
    ~Admin_Umbrella_Add();

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::Admin_Umbrella_Add *ui;
};

#endif // ADMIN_UMBRELLA_ADD_H
