/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect_To_Server;
    QAction *actionasdfadsf;
    QAction *actionCreate_User;
    QAction *actionVIP;
    QAction *actionasdfadsf_2;
    QAction *Change_Name_Button;
    QAction *Exit_Login;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *status_label;
    QPushButton *Image_Button;
    QTextEdit *input_text;
    QPushButton *send_button;
    QTextBrowser *info_text;
    QMenuBar *menuBar;
    QMenu *menuServer;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(590, 623);
        actionConnect_To_Server = new QAction(MainWindow);
        actionConnect_To_Server->setObjectName(QString::fromUtf8("actionConnect_To_Server"));
        actionasdfadsf = new QAction(MainWindow);
        actionasdfadsf->setObjectName(QString::fromUtf8("actionasdfadsf"));
        actionCreate_User = new QAction(MainWindow);
        actionCreate_User->setObjectName(QString::fromUtf8("actionCreate_User"));
        actionVIP = new QAction(MainWindow);
        actionVIP->setObjectName(QString::fromUtf8("actionVIP"));
        actionasdfadsf_2 = new QAction(MainWindow);
        actionasdfadsf_2->setObjectName(QString::fromUtf8("actionasdfadsf_2"));
        Change_Name_Button = new QAction(MainWindow);
        Change_Name_Button->setObjectName(QString::fromUtf8("Change_Name_Button"));
        Exit_Login = new QAction(MainWindow);
        Exit_Login->setObjectName(QString::fromUtf8("Exit_Login"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        status_label = new QLabel(centralWidget);
        status_label->setObjectName(QString::fromUtf8("status_label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        status_label->setFont(font);

        gridLayout->addWidget(status_label, 8, 0, 1, 2);

        Image_Button = new QPushButton(centralWidget);
        Image_Button->setObjectName(QString::fromUtf8("Image_Button"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(3);
        sizePolicy.setHeightForWidth(Image_Button->sizePolicy().hasHeightForWidth());
        Image_Button->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        Image_Button->setFont(font1);
        Image_Button->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"border-radius: 10px;\n"
"background-color: rgb(79, 132, 255);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(Image_Button, 6, 0, 1, 1);

        input_text = new QTextEdit(centralWidget);
        input_text->setObjectName(QString::fromUtf8("input_text"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(8);
        sizePolicy1.setHeightForWidth(input_text->sizePolicy().hasHeightForWidth());
        input_text->setSizePolicy(sizePolicy1);
        input_text->setFont(font);

        gridLayout->addWidget(input_text, 5, 0, 1, 2);

        send_button = new QPushButton(centralWidget);
        send_button->setObjectName(QString::fromUtf8("send_button"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(10);
        sizePolicy2.setVerticalStretch(3);
        sizePolicy2.setHeightForWidth(send_button->sizePolicy().hasHeightForWidth());
        send_button->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        send_button->setFont(font2);
        send_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(68, 44, 255);\n"
"border: 0px;\n"
"border-radius: 10px;"));

        gridLayout->addWidget(send_button, 6, 1, 1, 1);

        info_text = new QTextBrowser(centralWidget);
        info_text->setObjectName(QString::fromUtf8("info_text"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(20);
        sizePolicy3.setHeightForWidth(info_text->sizePolicy().hasHeightForWidth());
        info_text->setSizePolicy(sizePolicy3);
        info_text->setFont(font);

        gridLayout->addWidget(info_text, 4, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 590, 29));
        menuServer = new QMenu(menuBar);
        menuServer->setObjectName(QString::fromUtf8("menuServer"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuServer->menuAction());
        menuBar->addAction(menu->menuAction());
        menuServer->addAction(actionVIP);
        menu->addAction(Change_Name_Button);
        menu->addAction(Exit_Login);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\275\221\347\273\234\350\201\212\345\244\251\345\256\244", nullptr));
        actionConnect_To_Server->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
#if QT_CONFIG(shortcut)
        actionConnect_To_Server->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionasdfadsf->setText(QCoreApplication::translate("MainWindow", "asdfadsf", nullptr));
        actionCreate_User->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214\346\226\260\347\224\250\346\210\267", nullptr));
        actionVIP->setText(QCoreApplication::translate("MainWindow", "\345\205\205\345\200\274VIP\344\274\232\345\221\230", nullptr));
        actionasdfadsf_2->setText(QCoreApplication::translate("MainWindow", "asdfadsf", nullptr));
        Change_Name_Button->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\346\230\265\347\247\260", nullptr));
        Exit_Login->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        status_label->setText(QCoreApplication::translate("MainWindow", "\346\202\250\350\277\233\345\205\245\344\272\206\350\201\212\345\244\251\345\256\244", nullptr));
        Image_Button->setText(QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207", nullptr));
        send_button->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
#if QT_CONFIG(shortcut)
        send_button->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Return", nullptr));
#endif // QT_CONFIG(shortcut)
        menuServer->setTitle(QCoreApplication::translate("MainWindow", "\344\274\232\345\221\230\346\234\215\345\212\241", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\350\264\246\346\210\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
