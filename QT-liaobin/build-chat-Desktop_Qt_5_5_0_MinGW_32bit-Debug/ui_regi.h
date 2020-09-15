/********************************************************************************
** Form generated from reading UI file 'regi.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGI_H
#define UI_REGI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_regi
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *regi)
    {
        if (regi->objectName().isEmpty())
            regi->setObjectName(QStringLiteral("regi"));
        regi->resize(712, 615);
        lineEdit = new QLineEdit(regi);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(220, 210, 221, 31));
        lineEdit_2 = new QLineEdit(regi);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(220, 280, 221, 31));
        lineEdit_3 = new QLineEdit(regi);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(220, 360, 221, 31));
        pushButton = new QPushButton(regi);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 20, 93, 28));
        pushButton_2 = new QPushButton(regi);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(590, 20, 93, 28));
        label = new QLabel(regi);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 220, 81, 16));
        label_2 = new QLabel(regi);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 280, 81, 16));
        label_3 = new QLabel(regi);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 370, 81, 21));
        label_4 = new QLabel(regi);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 530, 72, 15));
        textBrowser = new QTextBrowser(regi);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(220, 510, 221, 41));

        retranslateUi(regi);

        QMetaObject::connectSlotsByName(regi);
    } // setupUi

    void retranslateUi(QWidget *regi)
    {
        regi->setWindowTitle(QApplication::translate("regi", "Form", 0));
        pushButton->setText(QApplication::translate("regi", "back", 0));
        pushButton_2->setText(QApplication::translate("regi", "register", 0));
        label->setText(QApplication::translate("regi", "user name", 0));
        label_2->setText(QApplication::translate("regi", "password", 0));
        label_3->setText(QApplication::translate("regi", "repassword", 0));
        label_4->setText(QApplication::translate("regi", "\346\217\220\347\244\272", 0));
    } // retranslateUi

};

namespace Ui {
    class regi: public Ui_regi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGI_H
