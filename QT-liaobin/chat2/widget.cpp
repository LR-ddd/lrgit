#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    _server=new QTcpServer;
    _server->listen(QHostAddress::Any,8888);

    connect(_server,SIGNAL(newConnection()),this,SLOT(slotConnect()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString str1;
    str1=ui->textEdit->toPlainText();

    ui->textBrowser->append("server:");
    ui->textBrowser->append(" "+str1);

    QByteArray buf=str1.toUtf8();
    _socket->write(buf);

    ui->textEdit->clear();
}


void Widget::on_pushButton_2_clicked()
{
    this->close();
}

void Widget::recv_info()
{
    QString str=_socket->readAll();

    ui->textBrowser->append("user:");
    ui->textBrowser->append(" "+str);
}

void Widget::slotConnect()
{

    while(_server->hasPendingConnections())
    {

        _socket=_server->nextPendingConnection();
        connect(_socket,SIGNAL(readyRead()),this,SLOT(recv_info()));
    }
}
