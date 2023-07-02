#include "register.h"
#include "ui_register.h"
#include<QSqlQueryModel>
#include<QMessageBox>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_ok_clicked()
{
    QString usname,usrn,ps,rps;
    usname = ui->lineEdit_usname->text();
    usrn = ui->lineEdit_usrn->text();
    ps = ui->lineEdit_ps->text();
    rps = ui->lineEdit_rps->text();
    if(ps!=rps){
        QMessageBox::about(NULL,"警告","两次输入的密码不一致，请重新输入");
    }else{
        QString sqlstring="select count (*) from Userimt where Username='"+usname+"'";
        QSqlQueryModel *model=new QSqlQueryModel;
        model->setQuery(sqlstring);
        QModelIndex index=model->index(0,0);
        if(index.data()!=0){
            QMessageBox::about(NULL,"警告","此用户名已被占用，请重新输入");
        }else{
            QSqlQueryModel *model2=new QSqlQueryModel;
            sqlstring="insert into Userimt values ('"+usname+"','"+usrn+"','"+ps+"','0','0')";
            model2->setQuery(sqlstring);
            QMessageBox::about(NULL,"提示","注册成功！");
        }
    }
}
