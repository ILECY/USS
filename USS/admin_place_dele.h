#ifndef ADMIN_PLACE_DELE_H
#define ADMIN_PLACE_DELE_H

#include <QWidget>

namespace Ui {
class Admin_Place_Dele;
}

class Admin_Place_Dele : public QWidget
{
    Q_OBJECT

public:
    explicit Admin_Place_Dele(QWidget *parent = 0);
    ~Admin_Place_Dele();

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButto_ok_clicked();

private:
    Ui::Admin_Place_Dele *ui;
};

#endif // ADMIN_PLACE_DELE_H
