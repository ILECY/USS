#ifndef USER_RETURN_H
#define USER_RETURN_H

#include <QWidget>

namespace Ui {
class User_Return;
}

class User_Return : public QWidget
{
    Q_OBJECT

public:
    explicit User_Return(QString un,QWidget *parent = 0);
    ~User_Return();
    QString username;
    void init();

private slots:
    void on_pushButton_clicked();

private:
    Ui::User_Return *ui;
    int uid;
};

#endif // USER_RETURN_H
