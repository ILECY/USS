#include "admin_user.h"
#include "ui_admin_user.h"
#include<QSqlQueryModel>

Admin_User::Admin_User(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_User)
{
    ui->setupUi(this);
    init();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
void Admin_User::init()
{
    QSqlQueryModel *model=new QSqlQueryModel;
    QString sql;
    sql="select Username as 用户名 ,Realname as 真实姓名,Password as 密码 ,Is_borrow as 是否租借,Is_admin as 是否管理员  from Userimt";
    model->setQuery(sql);
    ui->tableView->setModel(model);
}
Admin_User::~Admin_User()
{
    delete ui;
}

void Admin_User::on_pushButton_usadd_clicked()
{
    add =new Admin_User_Add;
    add -> show();
}

void Admin_User::on_pushButton_usrf_clicked()
{
    init();
}

void Admin_User::on_pushButton_usdelete_clicked()
{
    dele = new Admin_User_dele;
    dele -> show();
}

void Admin_User::on_pushButton_usfind_clicked()
{
    QString finds=ui->lineEdit_usfind->text(),sqlstring;
    sqlstring="select Username as 用户名 ,Realname as 真实姓名,Password as 密码 ,Is_borrow as 是否租借,Is_admin as 是否管理员  from Userimt where (Username LIKE '%"+finds+"%')";
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(sqlstring);
    ui->tableView->setModel(model);
}
