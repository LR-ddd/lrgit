#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include "widget.h"

namespace Ui {
class interface;
}

class interface : public QMainWindow
{
    Q_OBJECT

public:
    explicit interface(QWidget *parent = 0);
    ~interface();

public slots:
    void recv2_info();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::interface *ui;
    QTcpSocket *_socket2;
};

#endif // INTERFACE_H
