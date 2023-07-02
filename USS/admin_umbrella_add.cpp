#include "admin_umbrella_add.h"
#include "ui_admin_umbrella_add.h"
#include<QSqlQueryModel>
#include<QMessageBox>

#pragma execution_character_set("utf-8")

Admin_Umbrella_Add::Admin_Umbrella_Add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_Umbrella_Add)
{
    ui->setupUi(this);
}

Admin_Umbrella_Add::~Admin_Umbrella_Add()
{
    delete ui;
}

void Admin_Umbrella_Add::on_pushButton_ok_clicked()
{
    QString ubid,ubtype,placeid,isb;
    ubid = ui->lineEdit_ubid->text();
    ubtype = ui->lineEdit_ubtype->text();
    placeid = ui->lineEdit_placeid->text();
    isb = ui->lineEdit_isb->text();

    QString sqlstring="select count (*) from Umbrella where Umbrella_id='"+ubid+"'";
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(sqlstring);
    QModelIndex index=model->index(0,0);
    if(index.data()!=0){
        QSqlQueryModel *model2=new QSqlQueryModel;
        sqlstring="update Umbrella set Umbrella_id ='"+ubid+"',Umbrella_type='"+ubtype+"',Place_id='"+placeid+"',Is_borrowed='"+isb+"' where Umbrella_id='"+ubid+"'";
        model2->setQuery(sqlstring);
        QMessageBox::about(NULL,"提示","雨伞信息修改成功");
    }else{
        QSqlQueryModel *model2=new QSqlQueryModel;
        sqlstring="insert into Umbrella values ('"+ubid+"','"+ubtype+"','"+placeid+"','"+isb+"')";
        model2->setQuery(sqlstring);
        QMessageBox::about(NULL,"提示","雨伞信息添加成功");
    }
}
