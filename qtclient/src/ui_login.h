/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *Username_Text;
    QLineEdit *Password_Text;
    QLabel *label_4;
    QLabel *login_label;
    QPushButton *Login_Button;
    QCommandLinkButton *CreateUser;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(541, 300);
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 161, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(13);
        label->setFont(font);
        label_2 = new QLabel(Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 100, 141, 19));
        label_3 = new QLabel(Login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 160, 141, 19));
        Username_Text = new QLineEdit(Login);
        Username_Text->setObjectName(QString::fromUtf8("Username_Text"));
        Username_Text->setGeometry(QRect(120, 100, 331, 27));
        Password_Text = new QLineEdit(Login);
        Password_Text->setObjectName(QString::fromUtf8("Password_Text"));
        Password_Text->setGeometry(QRect(120, 160, 331, 27));
        Password_Text->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(Login);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(170, 50, 191, 201));
        label_4->setStyleSheet(QString::fromUtf8(""));
        label_4->setPixmap(QPixmap(QString::fromUtf8("E:/Project/Go/PPCA/qtclient/src/logo.png")));
        label_4->setScaledContents(true);
        login_label = new QLabel(Login);
        login_label->setObjectName(QString::fromUtf8("login_label"));
        login_label->setGeometry(QRect(10, 280, 501, 17));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        login_label->setFont(font1);
        login_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 4);"));
        Login_Button = new QPushButton(Login);
        Login_Button->setObjectName(QString::fromUtf8("Login_Button"));
        Login_Button->setGeometry(QRect(350, 250, 104, 32));
        CreateUser = new QCommandLinkButton(Login);
        CreateUser->setObjectName(QString::fromUtf8("CreateUser"));
        CreateUser->setGeometry(QRect(280, 20, 240, 50));
        label_4->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        Username_Text->raise();
        Password_Text->raise();
        login_label->raise();
        Login_Button->raise();
        CreateUser->raise();

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225\345\210\260\350\201\212\345\244\251\345\256\244\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_4->setText(QString());
        login_label->setText(QCoreApplication::translate("Login", "\345\260\232\346\234\252\347\231\273\345\275\225", nullptr));
        Login_Button->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
#if QT_CONFIG(shortcut)
        Login_Button->setShortcut(QCoreApplication::translate("Login", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        CreateUser->setText(QCoreApplication::translate("Login", "\346\262\241\346\234\211\350\264\246\346\210\267\357\274\237\346\263\250\345\206\214\344\270\200\344\270\252\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
