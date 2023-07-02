#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QSqlQueryModel>
#include<QDebug>
#include<QMessageBox>

#pragma execution_character_set("utf-8")

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit_username,SIGNAL(returnPressed()),ui->lineEdit_password,SLOT(setFocus()));
    connect(ui->lineEdit_password,SIGNAL(returnPressed()),this,SLOT(on_pushButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString inputName=ui->lineEdit_username->text();
    QString inputPassword=ui->lineEdit_password->text();

    QString sqlstring="select password from Userimt where Username ='"+inputName+"'";
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(sqlstring);
    QModelIndex index=model->index(0,0);
    if(index.data() == 0){
        QMessageBox::about(NULL,"提示","不存在此用户");
    }else{
        if(index.data() == inputPassword){
            sqlstring="select Is_admin from Userimt where Username ='"+inputName+"'";
            model->setQuery(sqlstring);
            QModelIndex index2=model->index(0,0);
            if(index2.data()==1){
                QMessageBox::about(NULL,"提示","管理员登陆成功");
                adm = new Adminwindow;
                adm -> show();
                close();
            }else{
                QMessageBox::about(NULL,"提示","用户登陆成功");
                user = new Userwindow(inputName);
                //user ->username=inputName;
                user -> show();
                close();
            }
        }else{
            QMessageBox::about(NULL,"提示","用户名或密码错误");
        }
    }

}

void MainWindow::on_pushButton_reg_clicked()
{
    reg = new Register;
    reg -> show();
}
