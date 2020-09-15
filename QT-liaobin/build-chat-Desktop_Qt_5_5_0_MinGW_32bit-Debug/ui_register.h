/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_register
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *register)
    {
        if (register->objectName().isEmpty())
            register->setObjectName(QStringLiteral("register"));
        register->resize(400, 300);
        lineEdit = new QLineEdit(register);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(130, 100, 221, 31));
        lineEdit_2 = new QLineEdit(register);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 150, 221, 31));
        lineEdit_3 = new QLineEdit(register);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 200, 221, 31));
        label = new QLabel(register);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 110, 72, 15));
        label_2 = new QLabel(register);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 160, 72, 15));
        label_3 = new QLabel(register);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 210, 72, 15));
        pushButton = new QPushButton(register);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 260, 93, 28));
        pushButton_2 = new QPushButton(register);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 260, 93, 28));

        retranslateUi(register);

        QMetaObject::connectSlotsByName(register);
    } // setupUi

    void retranslateUi(QWidget *register)
    {
        register->setWindowTitle(QApplication::translate("register", "Form", 0));
        label->setText(QApplication::translate("register", "user", 0));
        label_2->setText(QApplication::translate("register", "password", 0));
        label_3->setText(QApplication::translate("register", "repassword", 0));
        pushButton->setText(QApplication::translate("register", "register", 0));
        pushButton_2->setText(QApplication::translate("register", "exit", 0));
    } // retranslateUi

};

namespace Ui {
    class register: public Ui_register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
