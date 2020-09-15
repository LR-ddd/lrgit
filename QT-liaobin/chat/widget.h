#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <QObject>
#include <QEvent>
#include <QKeyEvent>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QTcpServer>
#include <QMessageBox>
#include <QTcpSocket>
#include <QtNetwork>
#include <QPalette>
#include <QBrush>
#include "regi.h"
#include "interface.h"

#define IP "127.0.0.1"
#define port 8888

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    bool eventFilter(QObject *watched, QEvent *event);
public slots:
    void recv2_info();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *_socket1;
};

#endif // WIDGET_H
