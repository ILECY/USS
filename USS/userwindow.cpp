#include "userwindow.h"
#include "ui_userwindow.h"
#include<QSqlQueryModel>

#pragma execution_character_set("utf-8")

Userwindow::Userwindow(QString un,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Userwindow)
{
    ui->setupUi(this);
    username=un;
    init();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->label->setText("当前登录用户："+username);

}

Userwindow::~Userwindow()
{
    delete ui;
}

void Userwindow::init()
{
    QSqlQueryModel *model=new QSqlQueryModel;
    QString sql;
    sql="SELECT Umbrella.Umbrella_id as 雨伞编号,Umbrella.Umbrella_type as 雨伞类型,Place.Place_name as 存放地点 FROM Umbrella LEFT OUTER JOIN Place ON Umbrella.Place_id = Place.Place_id WHERE Umbrella.Is_borrowed=0";
    model->setQuery(sql);
    ui->tableView->setModel(model);
}

void Userwindow::on_pushButton_clicked()
{
    QString finds=ui->lineEdit_find->text();
    QSqlQueryModel *model=new QSqlQueryModel;
    QString sqlstring;
    sqlstring="SELECT Umbrella.Umbrella_id as 雨伞编号,Umbrella.Umbrella_type as 雨伞类型,Place.Place_name as 存放地点 FROM Umbrella LEFT OUTER JOIN Place ON Umbrella.Place_id = Place.Place_id WHERE Umbrella.Is_borrowed=0 AND (Umbrella_id LIKE '%"
        +finds+"%' OR Place_name LIKE '%"+finds+"%' OR Umbrella_type LIKE '%"+finds+"%')";
    model->setQuery(sqlstring);
    ui->tableView->setModel(model);
}

void Userwindow::on_pushButton_borrow_clicked()
{
     QSqlQueryModel *model=new QSqlQueryModel;
     QString sqlstring="select Is_borrow from Userimt where Username ='"+username+"'";
     model->setQuery(sqlstring);
     QModelIndex index=model->index(0,0);
     if(index.data()==0){
         ub = new User_Borrow(username);
         ub -> show();
     }else{
         ur = new User_Return(username);
         ur -> show();
     }
}
