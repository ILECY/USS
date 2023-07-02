#include "admin_orders.h"
#include "ui_admin_orders.h"
#include<QSqlQueryModel>
#include<QSqlTableModel>

Admin_Orders::Admin_Orders(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_Orders)
{
    ui->setupUi(this);
    init();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Admin_Orders::~Admin_Orders()
{
    delete ui;
}

void Admin_Orders::init()
{
    QSqlQueryModel *model=new QSqlQueryModel;
    QString sql;
    sql="SELECT Borrow.Borrow_id as 租借编号,Borrow.Username as 用户名,Borrow.Umbrella_id as 雨伞编号,Borrow.Place_id as 借出地点编号,Borrow.Borrow_time as 借出时间,Borrow.Is_return as 是否归还,Return.Place_id as 归还地点编号,Return.Return_time as 归还时间 FROM Borrow LEFT OUTER JOIN Return ON Borrow.Borrow_id = Return.Borrow_id";
    model->setQuery(sql);
    ui->tableView->setModel(model);
}

void Admin_Orders::on_pushButton_add_clicked()
{
    add = new Admin_Orders_Add;
    add -> show();
}

void Admin_Orders::on_pushButton_refresh_clicked()
{
    init();
}

void Admin_Orders::on_pushButton_dele_clicked()
{
    dele =new Admin_Orders_Dele;
    dele -> show();
}

void Admin_Orders::on_pushButton_ok_clicked()
{
    QString find=ui->lineEdit_find->text(),sqlstring;
    sqlstring="SELECT Borrow.Borrow_id as 租借编号,Borrow.Username as 用户名,Borrow.Umbrella_id as 雨伞编号,Borrow.Place_id as 借出地点编号,Borrow.Borrow_time as 借出时间,Borrow.Is_return as 是否归还,Return.Place_id as 归还地点编号,Return.Return_time as 归还时间 FROM Borrow LEFT OUTER JOIN Return ON Borrow.Borrow_id = Return.Borrow_id WHERE Borrow.Borrow_id LIKE '%"+find+"%' OR Borrow.Username LIKE '%"+find+"%' OR Borrow.Umbrella_id LIKE '%"+find+"%' OR Borrow.Place_id LIKE '%"+find+"%' OR Return.Place_id LIKE '%"+find+"%'";
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(sqlstring);
    ui->tableView->setModel(model);
}
