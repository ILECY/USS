#include "admin_orders_dele.h"
#include "ui_admin_orders_dele.h"
#include<QMessageBox>
#include<QSqlQueryModel>

Admin_Orders_Dele::Admin_Orders_Dele(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_Orders_Dele)
{
    ui->setupUi(this);
}

Admin_Orders_Dele::~Admin_Orders_Dele()
{
    delete ui;
}

void Admin_Orders_Dele::on_pushButton_clicked()
{
    QString id=ui->lineEdit_dele->text(),sqlstring;
    sqlstring="select count (*) from Borrow where Borrow_id='"+id+"'";
    QSqlQueryModel *model=new QSqlQueryModel,*model2=new QSqlQueryModel;
    model->setQuery(sqlstring);
    QModelIndex index=model->index(0,0);
    if(index.data()==0){
        QMessageBox::about(NULL,"警告","系统中不存在此编号");
    }else{
        sqlstring="delete from Borrow where Borrow_id='"+id+"'";
        model->setQuery(sqlstring);
        QMessageBox::about(NULL,"提示","删除成功");
    }
     sqlstring="select count (*) from Return where Borrow_id='"+id+"'";
     model2->setQuery(sqlstring);
     index=model2->index(0,0);
     if(index.data()!=0){
         sqlstring="delete from Return where Borrow_id='"+id+"'";
         model2->setQuery(sqlstring);
     }
}
