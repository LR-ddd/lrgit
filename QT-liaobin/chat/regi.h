#ifndef REGI_H
#define REGI_H

#include <QWidget>
#include "widget.h"

#define IP "127.0.0.1"
#define port 8888


namespace Ui {
class regi;
}

class regi : public QWidget
{
    Q_OBJECT

public:
    explicit regi(QWidget *parent = 0);
    ~regi();
public slots:
    void recv_info();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::regi *ui;
    QTcpSocket *_socket;
};

#endif // REGI_H
