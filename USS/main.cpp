#include "mainwindow.h"
#include <QApplication>
#include<QDebug>
#include<QSqlDatabase>

#pragma execution_character_set("utf-8")

bool opendatebase(){
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    //mydb.setDatabaseName("D:\\Myworks\\qtfile\\USS\\USSDB.db");
    mydb.setDatabaseName("USSDB.db");
    if(mydb.open()){
        qDebug()<<"open success";
        return true;
    }
    else{
        qDebug()<<"open failed";
        return false;
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    opendatebase();
    MainWindow w;
    w.show();

    return a.exec();
}
