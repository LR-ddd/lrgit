#include "interface.h"
#include "ui_interface.h"

interface::interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::interface)
{
    ui->setupUi(this);
    _socket2=new QTcpSocket;
    _socket2->connectToHost("127.0.0.1",9988);

    connect(_socket2,SIGNAL(readyRead()),this,SLOT(recv2_info()));
}

interface::~interface()
{
    delete ui;
}

void interface::on_pushButton_clicked()
{
    this->close();
}

void interface::on_pushButton_2_clicked()
{
    QString str;
    str=ui->textEdit->toPlainText();

    ui->textBrowser->append("lr");
    ui->textBrowser->append(" "+str);

    QByteArray buff=str.toUtf8();
    _socket2->write(buff);

    ui->textEdit->clear();
}

void interface::recv2_info()
{
    QString buf=_socket2->readAll();

    ui->textBrowser->append("server:");
    ui->textBrowser->append(" "+buf);
}
