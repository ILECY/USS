#include "user_return.h"
#include "ui_user_return.h"
#include<QSqlQueryModel>
#include<QMessageBox>
#include<QDateTime>

User_Return::User_Return(QString un,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::User_Return)
{
    ui->setupUi(this);
    username=un;
    init();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QString sqlstring="select Umbrella_id from Borrow where Is_return='0' AND Username='"+username+"'";
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(sqlstring);
    QModelIndex index=model->index(0,0);
    uid=index.data().toInt();
    ui->label->setText("借出的雨伞编号："+QString::number(uid));
}

void User_Return::init(){
    QSqlQueryModel *model=new QSqlQueryModel;
    QString sql;
    sql="select Place_id as 地点编号 ,Place_name as 地点名称 from Place order by Place_id asc";
    model->setQuery(sql);
    ui->tableView->setModel(model);
}

User_Return::~User_Return()
{
    delete ui;
}

void User_Return::on_pushButton_clicked()
{
    QString pid=ui->lineEdit_return->text(),sqlstring;
    QSqlQueryModel *model1=new QSqlQueryModel,*model2=new QSqlQueryModel,*model3=new QSqlQueryModel;
    QSqlQueryModel *model4=new QSqlQueryModel,*model5=new QSqlQueryModel,*model6=new QSqlQueryModel;
    QSqlQueryModel *model7=new QSqlQueryModel;
    sqlstring="update Userimt set Is_borrow='0' where Username='"+username+"'";
    model1->setQuery(sqlstring);
    sqlstring="update Umbrella set Is_borrowed='0' where Umbrella_id='"+QString::number(uid)+"'";
    model2->setQuery(sqlstring);
    sqlstring="update Umbrella set Place_id='"+pid+"' where Umbrella_id='"+QString::number(uid)+"'";
    model3->setQuery(sqlstring);

    sqlstring="select Borrow_id from Borrow where Is_return='0' AND Username='"+username+"'";
    model4->setQuery(sqlstring);
    QModelIndex index=model4->index(0,0);
    QString bid=QString::number(index.data().toInt());
    sqlstring="update Borrow set Is_return='1' where Borrow_id='"+bid+"'";
    model5->setQuery(sqlstring);

    int time1=QDateTime::currentDateTime().toTime_t();
    sqlstring="insert into Return values ('"+bid+"','"+pid+"','"+QString::number(time1)+"')";
    model6->setQuery(sqlstring);

    sqlstring="select Borrow_time from Borrow where Borrow_id='"+bid+"'";
    model7->setQuery(sqlstring);
    index=model7->index(0,0);
    int time2=index.data().toInt();
    int money=(time1-time2)/3600;
    QMessageBox::about(NULL,"提示","租借时间(秒)："+QString::number(time1-time2)+"\n请支付(元)："+QString::number(money));
    close();
}
