#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Login;
}

class CreateUser;

class Login : public QDialog
{
    Q_OBJECT

public:
	MainWindow* window_to_call = nullptr;
	CreateUser* create_window = nullptr;
	chatClient* cl = nullptr;
    explicit Login(chatClient* cl, QWidget *parent = 0);
    ~Login();

public slots:
	void on_Login_Button_pressed();
	void show_next_window();
	void no_such_user();
	void pwd_error();
	void on_CreateUser_released();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
