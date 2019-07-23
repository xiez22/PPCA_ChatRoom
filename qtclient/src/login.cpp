#include "login.h"
#include "ui_login.h"
#include <qmessagebox.h>
#include <qthread.h>
#include "createuser.h"

Login::Login(chatClient* cl, QWidget *parent) :
    QDialog(parent),
	cl(cl),
    ui(new Ui::Login){
	setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
	setFixedSize(541, 300);
    ui->setupUi(this);

	auto a = connect(cl, SIGNAL(loginSuccess()), this, SLOT(show_next_window()));
	connect(cl, SIGNAL(loginNoSuchUser()), this, SLOT(no_such_user()));
	connect(cl, SIGNAL(loginPwdError()), this, SLOT(pwd_error()));
}

Login::~Login(){
    delete ui;
}

void Login::on_Login_Button_pressed(){
	auto username = ui->Username_Text->text();
	auto password = ui->Password_Text->text();

	if (username.isEmpty() || password.isEmpty()) {
		ui->login_label->setText("用户名或密码不能为空！");
		return;
	}

	cl->sendMessage("~@Client:Login");
	cl->sendMessage(username);
	QThread::msleep(100);
	cl->sendMessage(password);
	ui->login_label->setText("网络异常，请重新登录！");
}

void Login::show_next_window() {
	window_to_call->show();
	this->close();
}

void Login::no_such_user(){
	ui->login_label->setText("无此用户！");
}

void Login::pwd_error(){
	ui->login_label->setText("密码错误！");
	ui->Password_Text->setText("");
	ui->Password_Text->setFocus();
}

void Login::on_CreateUser_released() {
	create_window = new CreateUser(cl, this);
	create_window->show();
	this->close();
}