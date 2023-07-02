#include "admin_user_add.h"
#include "ui_admin_user_add.h"
#include<QSqlQueryModel>
#include<QMessageBox>

#pragma execution_character_set("utf-8")

Admin_User_Add::Admin_User_Add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_User_Add)
{
    ui->setupUi(this);
}

Admin_User_Add::~Admin_User_Add()
{
    delete ui;
}

void Admin_User_Add::on_pushButton_ok_clicked()
{
    QString usname,usrn,ps,isa;
    usname = ui->lineEdit_usname->text();
    usrn = ui->lineEdit_usrn->text();
    ps = ui->lineEdit_ps->text();
    isa = ui->lineEdit_isa->text();

    QString sqlstring="select count (*) from Userimt where Username='"+usname+"'";
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(sqlstring);
    QModelIndex index=model->index(0,0);
    if(index.data()!=0){
        QSqlQueryModel *model2=new QSqlQueryModel;
        sqlstring="update Userimt set Username ='"+usname+"',Realname='"+usrn+"',Password='"+ps+"',Is_borrow='0',Is_admin='"+isa+"' where Username='"+usname+"'";
        model2->setQuery(sqlstring);
        QMessageBox::about(NULL,"提示","用户信息修改成功");
    }else{
        QSqlQueryModel *model2=new QSqlQueryModel;
        sqlstring="insert into Userimt values ('"+usname+"','"+usrn+"','"+ps+"','0','"+isa+"')";
        model2->setQuery(sqlstring);
        QMessageBox::about(NULL,"提示","用户信息添加成功");
    }
}
