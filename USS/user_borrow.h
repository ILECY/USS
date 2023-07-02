#ifndef USER_BORROW_H
#define USER_BORROW_H

#include <QWidget>

namespace Ui {
class User_Borrow;
}

class User_Borrow : public QWidget
{
    Q_OBJECT

public:
    explicit User_Borrow(QString un,QWidget *parent = 0);
    ~User_Borrow();
    QString username;

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::User_Borrow *ui;
};

#endif // USER_BORROW_H
