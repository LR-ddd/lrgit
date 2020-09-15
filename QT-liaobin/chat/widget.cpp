#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QImage img;
    img.load(":/1.jpg");
    QPixmap map=QPixmap::fromImage(img);
    ui->label_3->setPixmap(map);
    ui->label_3->setScaledContents(true);

    QPalette palette=this->palette();
    QImage img2(":/2.jpg");
    QImage fitimgpic=img2.scaled(this->width(),this->height(),Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Window,QBrush(fitimgpic));
    this->setPalette(palette);

    this->setWindowTitle("Login page");

    ui->lineEdit->installEventFilter(this);
    _socket1=new QTcpSocket;
    _socket1->connectToHost(IP,port);

    connect(_socket1,SIGNAL(readyRead()),this,SLOT(recv2_info()));

}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    switch(event->type())
    {
        case QEvent::KeyPress:
            if(watched==ui->lineEdit)
            {
                QKeyEvent *tkey=static_cast<QKeyEvent *>(event);
                int val=tkey->key();
                if(Qt::Key_0<=val&&val<=Qt::Key_9||val==Qt::Key_Backspace)
                {

                     return false;
                }
                else
                {
                    return true;
                }
            }
            else if(watched==ui->lineEdit_2)
            {
                return false;
            }
            break;
       default:
                break;
    }
    return false;
}

void Widget::on_pushButton_2_clicked()
{
   QString user1;
   QString pwd1;
   QString buf;
   user1=ui->lineEdit->text();
   pwd1=ui->lineEdit_2->text();
   if(user1== "")
   {
       QMessageBox::warning(this,"","user names cannot be left blank");
   }
   else if(pwd1== "")
   {
       QMessageBox::warning(this,"","password cannot be left blank");
   }
   else
   {
       buf="login"+'*'+user1+'*'+pwd1+"*";
   }

   QByteArray buff=buf.toUtf8();
   _socket1->write(buff);
}


void Widget::on_pushButton_clicked()
{
    this->close();
}

void Widget::on_pushButton_3_clicked()
{
        regi *win=new regi;
        win->show();
        this->close();

}

void Widget::recv2_info()
{
    QString buf=_socket1->readAll();

    if(buf=="ok")
    {
        interface *win1=new interface;
        win1->show();
        this->close();

    }

}

