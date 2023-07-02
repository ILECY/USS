#include "admin_orders_add.h"
#include "ui_admin_orders_add.h"
#include<QSqlQueryModel>
#include<QMessageBox>

Admin_Orders_Add::Admin_Orders_Add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_Orders_Add)
{
    ui->setupUi(this);
    ui->lineEdit_pid_r->setEnabled(0);
    ui->lineEdit_rt->setEnabled(0);
}

Admin_Orders_Add::~Admin_Orders_Add()
{
    delete ui;
}

void Admin_Orders_Add::on_radioButton_clicked()
{
    bool checked=ui->radioButton->isChecked();
    if (checked){
        ui->lineEdit_pid_r->setEnabled(1);
        ui->lineEdit_rt->setEnabled(1);
    }else{
        ui->lineEdit_pid_r->setEnabled(0);
        ui->lineEdit_rt->setEnabled(0);
    }
}

void Admin_Orders_Add::on_pushButton_ok_clicked()
{
    QString bid,usname,uid,pid_b,bt,pid_r,rt;
    bool f1=0,f2=0;
    bid=ui->lineEdit_bid->text();
    usname=ui->lineEdit_usname->text();
    uid=ui->lineEdit_uid->text();
    pid_b=ui->lineEdit_pid_b->text();
    bt=ui->lineEdit_bt->text();

    if(ui->radioButton->isChecked()){
        pid_r=ui->lineEdit_pid_r->text();
        rt=ui->lineEdit_rt->text();
        QString sqlstring="select count (*) from Return where Borrow_id='"+bid+"'";
        QSqlQueryModel *model=new QSqlQueryModel;
        model->setQuery(sqlstring);
        QModelIndex index=model->index(0,0);
        if(index.data()!=0){
            QSqlQueryModel *model2=new QSqlQueryModel;
            sqlstring="update Return set Borrow_id ='"+bid+"',Place_id='"+pid_r+"',Return_time='"+rt+"' where Borrow_id='"+bid+"'";
            model2->setQuery(sqlstring);
        }else{
            QSqlQueryModel *model2=new QSqlQueryModel;
            sqlstring="insert into Return values ('"+bid+"','"+pid_r+"','"+rt+"')";
            model2->setQuery(sqlstring);
            f2=1;
        }
    }

    QString isr=QString::number(ui->radioButton->isChecked());
    QString sqlstring="select count (*) from Borrow where Borrow_id='"+bid+"'";
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(sqlstring);
    QModelIndex index=model->index(0,0);
    if(index.data()!=0){
        QSqlQueryModel *model2=new QSqlQueryModel;
        sqlstring="update Return set Borrow_id ='"+bid+"',Username='"+usname+"',Umbrella_id='"+uid+"',Place_id='"+pid_b+"',Borrow_time='"+bt+"',Is_return='"+isr+"' where Borrow_id='"+bid+"'";
        model2->setQuery(sqlstring);
    }else{
        QSqlQueryModel *model2=new QSqlQueryModel;
        sqlstring="insert into Borrow values ('"+bid+"','"+usname+"','"+uid+"','"+pid_b+"','"+bt+"','"+isr+"')";
        model2->setQuery(sqlstring);
        f1=1;
    }
    QString ms;
    if(f1) ms+="租借记录添加成功，";
    else ms+="租借记录修改成功，";
    if(f2) ms+="归还记录添加成功";
    else ms+="归还记录修改成功";
    QMessageBox::about(NULL,"提示",ms);
}
