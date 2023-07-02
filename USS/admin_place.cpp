#include "admin_place.h"
#include "ui_admin_place.h"
#include<QSqlQueryModel>

#pragma execution_character_set("utf-8")

Admin_Place::Admin_Place(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_Place)
{
    ui->setupUi(this);
    init();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Admin_Place::~Admin_Place()
{
    delete ui;
}

void Admin_Place::init()
{
    QSqlQueryModel *model=new QSqlQueryModel;
    QString sql;
    sql="select Place_id as 地点编号 ,Place_name as 地点名称 from Place order by Place_id asc";
    model->setQuery(sql);
    ui->tableView->setModel(model);
}

void Admin_Place::on_pushButton_3_clicked()
{
    init();
}

void Admin_Place::on_pushButton_add_clicked()
{
    add = new Admin_Place_Add;
    add -> show();
}

void Admin_Place::on_pushButton_dele_clicked()
{
    dele = new Admin_Place_Dele;
    dele -> show();
}
