#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>
#include "user_borrow.h"
#include "user_return.h"

namespace Ui {
class Userwindow;
}

class Userwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Userwindow(QString un,QWidget *parent = 0);
    ~Userwindow();
    void init();
    QString username;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_borrow_clicked();

private:
    Ui::Userwindow *ui;
    User_Borrow *ub;
    User_Return *ur;
};

#endif // USERWINDOW_H
