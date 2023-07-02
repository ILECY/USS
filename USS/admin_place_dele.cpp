#include "admin_place_dele.h"
#include "ui_admin_place_dele.h"
#include<QMessageBox>
#include<QSqlQueryModel>

Admin_Place_Dele::Admin_Place_Dele(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_Place_Dele)
{
    ui->setupUi(this);
}

Admin_Place_Dele::~Admin_Place_Dele()
{
    delete ui;
}

void Admin_Place_Dele::on_pushButton_cancel_clicked()
{
    close();
}

void Admin_Place_Dele::on_pushButto_ok_clicked()
{
    QString id=ui->lineEdit_dele->text(),sqlstring;
    sqlstring="select count (*) from Place where Place_id='"+id+"'";
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(sqlstring);
    QModelIndex index=model->index(0,0);
    if(index.data()==0){
        QMessageBox::about(NULL,"警告","系统中不存在此编号");
    }else{
        sqlstring="delete from Place where Place_id='"+id+"'";
        model->setQuery(sqlstring);
        QMessageBox::about(NULL,"提示","删除成功");
    }
}
