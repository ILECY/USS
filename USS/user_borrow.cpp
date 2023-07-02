#include "user_borrow.h"
#include "ui_user_borrow.h"
#include<QSqlQueryModel>
#include<QMessageBox>
#include<QDateTime>
User_Borrow::User_Borrow(QString un,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::User_Borrow)
{
    ui->setupUi(this);
    username=un;
}

User_Borrow::~User_Borrow()
{
    delete ui;
}

void User_Borrow::on_pushButton_ok_clicked()
{
    QString uid=ui->lineEdit_borrow->text();
    QSqlQueryModel *model1=new QSqlQueryModel,*model2=new QSqlQueryModel;
    QString sqlstring1,sqlstring2;
    sqlstring1="select Is_borrowed from Umbrella where Umbrella_id ='"+uid+"'";
    sqlstring2="select count (*) from Umbrella where Umbrella_id ='"+uid+"'";
    model1->setQuery(sqlstring1);
    QModelIndex index1=model1->index(0,0);
    model2->setQuery(sqlstring2);
    QModelIndex index2=model2->index(0,0);
    if(index1.data()==1){
        QMessageBox::about(NULL,"警告","此雨伞已被借出");
    }else if(index2.data()==0){
        QMessageBox::about(NULL,"警告","不存在此编号的雨伞");
    }else{
        QSqlQueryModel *model3=new QSqlQueryModel,*model4=new QSqlQueryModel;
        QSqlQueryModel *model5=new QSqlQueryModel,*model6=new QSqlQueryModel;
        QSqlQueryModel *model7=new QSqlQueryModel;
        QString sqlstring;

        sqlstring="select max(Borrow_id) from Borrow";
        model3->setQuery(sqlstring);
        QModelIndex index=model3->index(0,0);
        int bid=index.data().toInt();
        bid++;
        int time=QDateTime::currentDateTime().toTime_t();
        sqlstring="select Place_id from Umbrella where Umbrella_id ='"+uid+"'";
        model7->setQuery(sqlstring);
        index=model7->index(0,0);
        QString pid=index.data().toString();
        sqlstring="insert into Borrow values ('"+QString::number(bid)+"','"+username+"','"+uid+"','"+pid+"','"+QString::number(time)+"','0')";
        model4->setQuery(sqlstring);
        QMessageBox::about(NULL,"提示","租借成功");

        sqlstring="update Userimt set Is_borrow='1' where Username='"+username+"'";
        model5->setQuery(sqlstring);
        sqlstring="update Umbrella set Is_borrowed='1' where Umbrella_id='"+uid+"'";
        model6->setQuery(sqlstring);
        close();
    }

}
