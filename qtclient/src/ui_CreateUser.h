/********************************************************************************
** Form generated from reading UI file 'CreateUser.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEUSER_H
#define UI_CREATEUSER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateUser
{
public:
    QLabel *label;
    QLabel *Create_Label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *Username;
    QLineEdit *Password;
    QLineEdit *Name;
    QPushButton *Create_Button;

    void setupUi(QWidget *CreateUser)
    {
        if (CreateUser->objectName().isEmpty())
            CreateUser->setObjectName(QString::fromUtf8("CreateUser"));
        CreateUser->resize(664, 369);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateUser->sizePolicy().hasHeightForWidth());
        CreateUser->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        CreateUser->setWindowIcon(icon);
        label = new QLabel(CreateUser);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 231, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(13);
        label->setFont(font);
        Create_Label = new QLabel(CreateUser);
        Create_Label->setObjectName(QString::fromUtf8("Create_Label"));
        Create_Label->setGeometry(QRect(40, 60, 571, 17));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        Create_Label->setFont(font1);
        Create_Label->setStyleSheet(QString::fromUtf8("color: rgb(187, 0, 34);"));
        label_2 = new QLabel(CreateUser);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 100, 81, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        label_2->setFont(font2);
        label_3 = new QLabel(CreateUser);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 170, 81, 21));
        label_3->setFont(font2);
        label_4 = new QLabel(CreateUser);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 240, 81, 21));
        label_4->setFont(font2);
        Username = new QLineEdit(CreateUser);
        Username->setObjectName(QString::fromUtf8("Username"));
        Username->setGeometry(QRect(140, 100, 451, 23));
        Password = new QLineEdit(CreateUser);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setGeometry(QRect(140, 170, 451, 23));
        Password->setEchoMode(QLineEdit::Password);
        Name = new QLineEdit(CreateUser);
        Name->setObjectName(QString::fromUtf8("Name"));
        Name->setGeometry(QRect(140, 240, 451, 23));
        Create_Button = new QPushButton(CreateUser);
        Create_Button->setObjectName(QString::fromUtf8("Create_Button"));
        Create_Button->setGeometry(QRect(40, 290, 561, 61));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(12);
        Create_Button->setFont(font3);

        retranslateUi(CreateUser);

        QMetaObject::connectSlotsByName(CreateUser);
    } // setupUi

    void retranslateUi(QWidget *CreateUser)
    {
        CreateUser->setWindowTitle(QCoreApplication::translate("CreateUser", "\345\210\233\345\273\272\346\226\260\347\224\250\346\210\267", nullptr));
        label->setText(QCoreApplication::translate("CreateUser", "+ \345\210\233\345\273\272\344\270\200\344\270\252\346\226\260\347\224\250\346\210\267", nullptr));
        Create_Label->setText(QCoreApplication::translate("CreateUser", "\350\276\223\345\205\245\346\202\250\347\232\204\350\264\246\346\210\267\344\277\241\346\201\257", nullptr));
        label_2->setText(QCoreApplication::translate("CreateUser", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("CreateUser", "\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("CreateUser", "\346\230\265\347\247\260", nullptr));
        Create_Button->setText(QCoreApplication::translate("CreateUser", "\345\210\233\345\273\272\344\270\200\344\270\252\346\226\260\347\224\250\346\210\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateUser: public Ui_CreateUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEUSER_H
