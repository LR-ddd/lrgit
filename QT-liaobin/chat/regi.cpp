#include "regi.h"
#include "ui_regi.h"

#include <string.h>

regi::regi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regi)
{
    ui->setupUi(this);
    _socket=new QTcpSocket;
    _socket->connectToHost(IP,port);

    connect(_socket,SIGNAL(readyRead()),this,SLOT(recv_info()));


}

regi::~regi()
{
    delete ui;
}

void regi::on_pushButton_2_clicked()
{
    QString user;
    QString pwd;
    QString rpwd;
    QString buf;

    user=ui->lineEdit->text();
    pwd=ui->lineEdit_2->text();
    rpwd=ui->lineEdit_3->text();

    if(user== "")
    {
        QMessageBox::warning(this,"","user names cannot be left blank");
    }
    else if(pwd== "")
    {
        QMessageBox::warning(this,"","password cannot be left blank");
    }
    else if(rpwd== ""||rpwd!=pwd)
    {
        QMessageBox::warning(this,"","the two inputs are not equal");
    }
    else
    {
        buf="register"+'*'+user+'*'+pwd+"*";
    }
    ui->textBrowser->append(buf);

    QByteArray buff=buf.toUtf8();
    _socket->write(buff);

    ui->textBrowser->clear();
}

void regi::on_pushButton_clicked()
{
    Widget *win3=new Widget;
    win3->show();
    this->close();
}

void regi::recv_info()
{
    QString buf1=_socket->readAll();

    ui->textBrowser->append("server");
    ui->textBrowser->append(buf1);
}

