#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "adminwindow.h"
#include "userwindow.h"
#include "register.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_reg_clicked();

private:
    Ui::MainWindow *ui;
    Adminwindow *adm;
    Userwindow *user;
    Register *reg;
};

#endif // MAINWINDOW_H
