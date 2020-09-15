#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    if(!db.isValid())
    {
       qDebug()<<"create db error"<<endl;
       return -1;
    }

    db.setDatabaseName("Test3.db");

    if(!db.open())
    {
       qDebug()<<"open db error"<<endl;
       return -1;
    }

    QSqlQuery que;
    if(!que.exec("create table if not exists user"
                 "(id int,password text)"))
    {
       qDebug()<<"EXEC  error"<<endl;
       db.close();
       return -1;
    }


    Widget w;
    w.show();

    return a.exec();
}
