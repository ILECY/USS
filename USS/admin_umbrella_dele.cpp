#include "admin_umbrella_dele.h"
#include "ui_admin_umbrella_dele.h"
#include<QMessageBox>
#include<QSqlQueryModel>

#pragma execution_character_set("utf-8")

Admin_Umbrella_Dele::Admin_Umbrella_Dele(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_Umbrella_Dele)
{
    ui->setupUi(this);
}

Admin_Umbrella_Dele::~Admin_Umbrella_Dele()
{
    delete ui;
}

void Admin_Umbrella_Dele::on_pushButton_cancel_clicked()
{
    close();
}

void Admin_Umbrella_Dele::on_pushButto_ok_clicked()
{
    QString id=ui->lineEdit_dele->text(),sqlstring;
    sqlstring="select count (*) from Umbrella where Umbrella_id='"+id+"'";
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(sqlstring);
    QModelIndex index=model->index(0,0);
    if(index.data()==0){
        QMessageBox::about(NULL,"警告","系统中不存在此编号");
    }else{
        sqlstring="delete from Umbrella where Umbrella_id='"+id+"'";
        model->setQuery(sqlstring);
        QMessageBox::about(NULL,"提示","删除成功");
    }
}
