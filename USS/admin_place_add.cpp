#include "admin_place_add.h"
#include "ui_admin_place_add.h"
#include<QSqlQueryModel>
#include<QMessageBox>

#pragma execution_character_set("utf-8")

Admin_Place_Add::Admin_Place_Add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_Place_Add)
{
    ui->setupUi(this);
}

Admin_Place_Add::~Admin_Place_Add()
{
    delete ui;
}

void Admin_Place_Add::on_pushButton_ok_clicked()
{
    QString pid,pname;
    pid = ui->lineEdit_pid->text();
    pname = ui->lineEdit_pname->text();


    QString sqlstring="select count (*) from Place where Place_id='"+pid+"'";
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(sqlstring);
    QModelIndex index=model->index(0,0);
    if(index.data()!=0){
        QSqlQueryModel *model2=new QSqlQueryModel;
        sqlstring="update Place set Place_id ='"+pid+"',Place_name='"+pname+"' where Place_id='"+pid+"'";
        model2->setQuery(sqlstring);
        QMessageBox::about(NULL,"提示","地点信息修改成功");
    }else{
        QSqlQueryModel *model2=new QSqlQueryModel;
        sqlstring="insert into Place values ('"+pid+"','"+pname+"')";
        model2->setQuery(sqlstring);
        QMessageBox::about(NULL,"提示","地点信息添加成功");
    }
}
