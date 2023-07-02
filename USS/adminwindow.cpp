#include "adminwindow.h"
#include "ui_adminwindow.h"

#pragma execution_character_set("utf-8")

Adminwindow::Adminwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Adminwindow)
{
    ui->setupUi(this);
}

Adminwindow::~Adminwindow()
{
    delete ui;
}

void Adminwindow::on_pushButton_umbrella_clicked()
{
    aub = new Admin_Umbrella;
    aub -> show();
}

void Adminwindow::on_pushButton_user_clicked()
{
    aus = new Admin_User;
    aus -> show();
}

void Adminwindow::on_pushButton_place_clicked()
{
    ap =new Admin_Place;
    ap -> show();
}

void Adminwindow::on_pushButton_orders_clicked()
{
    ao =new Admin_Orders;
    ao -> show();
}

void Adminwindow::on_pushButton_return_clicked(){};
