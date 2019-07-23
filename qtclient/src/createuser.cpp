#include "createuser.h"
#include "ui_createuser.h"
#include <qthread.h>
#include <qmessagebox.h>
#include <regex>
#include <string>
#include "login.h"

CreateUser::CreateUser(chatClient* cl, Login* lo, QWidget *parent):
    QWidget(parent),
    ui(new Ui::CreateUser),
	window_to_call(lo),
	cl(cl)
{
	setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
	setFixedSize(664, 369);
    ui->setupUi(this);

	connect(cl, SIGNAL(createSuccess()), this, SLOT(create_success()));
	connect(cl, SIGNAL(createNameExisted()), this, SLOT(create_name_existed()));
}

CreateUser::~CreateUser()
{
    delete ui;
}

void CreateUser::on_Create_Button_released() {
	auto username = ui->Username->text(),
		password = ui->Password->text(),
		name = ui->Name->text();

	if (username.isEmpty() || password.isEmpty() || name.isEmpty()) {
		ui->Create_Label->setText("用户名、密码或昵称不能为空！");
		return;
	}

	std::regex r("^[0-9a-zA-Z_]{3,15}$");
	std::string pwd = password.toStdString();
	if (!std::regex_match(pwd, r)) {
		ui->Create_Label->setText("密码应当由数字、英文字母或下划线组成，且长度应为3-15之间。");
		return;
	}

	cl->sendMessage("~@Client:Create");
	cl->sendMessage(username);
	QThread::msleep(100);
	cl->sendMessage(password);
	QThread::msleep(100);
	cl->sendMessage(name);
}

void CreateUser::create_success() {
	//登录


	QMessageBox msg(this);
	msg.setWindowTitle("完成注册");
	msg.setText("恭喜您完成注册，现在您将进入登录界面，请您输入账号和密码后进入聊天室。");
	msg.setIcon(QMessageBox::Information);
	msg.setStandardButtons(QMessageBox::Ok);
	msg.exec();

	window_to_call->show();
	this->close();
}

void CreateUser::create_name_existed() {
	ui->Create_Label->setText("用户名已经被使用，请更换一个");
}