#ifndef ADMIN_UMBRELLA_DELE_H
#define ADMIN_UMBRELLA_DELE_H

#include <QWidget>

namespace Ui {
class Admin_Umbrella_Dele;
}

class Admin_Umbrella_Dele : public QWidget
{
    Q_OBJECT

public:
    explicit Admin_Umbrella_Dele(QWidget *parent = 0);
    ~Admin_Umbrella_Dele();

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButto_ok_clicked();

private:
    Ui::Admin_Umbrella_Dele *ui;
};

#endif // ADMIN_UMBRELLA_DELE_H
