#include "admin_user_dele.h"
#include "ui_admin_user_dele.h"
#include<QMessageBox>
#include<QSqlQueryModel>

#pragma execution_character_set("utf-8")

Admin_User_dele::Admin_User_dele(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_User_dele)
{
    ui->setupUi(this);
}

Admin_User_dele::~Admin_User_dele()
{
    delete ui;
}

void Admin_User_dele::on_pushButton_cancel_clicked()
{
    close();
}

void Admin_User_dele::on_pushButto_ok_clicked()
{
    QString id=ui->lineEdit_dele->text(),sqlstring;
    sqlstring="select count (*) from Userimt where Username='"+id+"'";
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(sqlstring);
    QModelIndex index=model->index(0,0);
    if(index.data()==0){
        QMessageBox::about(NULL,"警告","系统中不存在此编号");
    }else{
        sqlstring="delete from Userimt where Username='"+id+"'";
        model->setQuery(sqlstring);
        QMessageBox::about(NULL,"提示","删除成功");
    }
}
