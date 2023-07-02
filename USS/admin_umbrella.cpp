#include "admin_umbrella.h"
#include "ui_admin_umbrella.h"
#include<QSqlQueryModel>

#pragma execution_character_set("utf-8")

Admin_Umbrella::Admin_Umbrella(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_Umbrella)
{
    ui->setupUi(this);
    init();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
void Admin_Umbrella::init()
{
    QSqlQueryModel *model=new QSqlQueryModel;
    QString sql;
    sql="select Umbrella_id as 雨伞编号 ,Umbrella_type as 雨伞类型,Place_id as 地点编号 ,Is_borrowed as 是否借出  from Umbrella";
    model->setQuery(sql);
    ui->tableView->setModel(model);
}
Admin_Umbrella::~Admin_Umbrella()
{
    delete ui;
}

void Admin_Umbrella::on_pushButton_ubadd_clicked()
{
    add = new Admin_Umbrella_Add;
    add -> show();
}

void Admin_Umbrella::on_pushButton_ubrf_clicked()
{
    init();
}

void Admin_Umbrella::on_pushButton_ubdelete_clicked()
{
    dele = new Admin_Umbrella_Dele;
    dele -> show();
}

void Admin_Umbrella::on_pushButton_ubfind_clicked()
{
    QString finds=ui->lineEdit_ubfind->text(),sqlstring;
    sqlstring="select Umbrella_id as 雨伞编号 ,Umbrella_type as 雨伞类型,Place_id as 地点编号 ,Is_borrowed as 是否借出  from Umbrella where (Umbrella_id LIKE '%"+finds+"%') or (Umbrella_type LIKE '%"+finds+"%') or (Place_id LIKE '%"+finds+"%')";
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(sqlstring);
    ui->tableView->setModel(model);
}
