/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_interface
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QMenu *menuSet;
    QMenu *menuLianxiren;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *interface)
    {
        if (interface->objectName().isEmpty())
            interface->setObjectName(QStringLiteral("interface"));
        interface->resize(800, 600);
        centralwidget = new QWidget(interface);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 731, 211));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 240, 731, 87));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 480, 93, 28));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(670, 480, 93, 28));
        interface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(interface);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuSet = new QMenu(menubar);
        menuSet->setObjectName(QStringLiteral("menuSet"));
        menuLianxiren = new QMenu(menubar);
        menuLianxiren->setObjectName(QStringLiteral("menuLianxiren"));
        interface->setMenuBar(menubar);
        statusbar = new QStatusBar(interface);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        interface->setStatusBar(statusbar);

        menubar->addAction(menuSet->menuAction());
        menubar->addAction(menuLianxiren->menuAction());

        retranslateUi(interface);

        QMetaObject::connectSlotsByName(interface);
    } // setupUi

    void retranslateUi(QMainWindow *interface)
    {
        interface->setWindowTitle(QApplication::translate("interface", "MainWindow", 0));
        pushButton->setText(QApplication::translate("interface", "exit", 0));
        pushButton_2->setText(QApplication::translate("interface", "send", 0));
        menuSet->setTitle(QApplication::translate("interface", "\350\256\276\347\275\256", 0));
        menuLianxiren->setTitle(QApplication::translate("interface", "\350\201\224\347\263\273\344\272\272", 0));
    } // retranslateUi

};

namespace Ui {
    class interface: public Ui_interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
