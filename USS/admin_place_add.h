#ifndef ADMIN_PLACE_ADD_H
#define ADMIN_PLACE_ADD_H

#include <QWidget>

namespace Ui {
class Admin_Place_Add;
}

class Admin_Place_Add : public QWidget
{
    Q_OBJECT

public:
    explicit Admin_Place_Add(QWidget *parent = 0);
    ~Admin_Place_Add();

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::Admin_Place_Add *ui;
};

#endif // ADMIN_PLACE_ADD_H
