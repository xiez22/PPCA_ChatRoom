#ifndef CREATEUSER_H
#define CREATEUSER_H

#include <QWidget>
#include "mainwindow.h"
#include "login.h"

namespace Ui {
class CreateUser;
}

class CreateUser : public QWidget
{
    Q_OBJECT

public:
	explicit CreateUser(chatClient*, Login*, QWidget* parent = nullptr);
    ~CreateUser();

private:
    Ui::CreateUser *ui;
	Login* window_to_call = nullptr;
	chatClient* cl = nullptr;

public slots:
	void on_Create_Button_released();
	void create_success();
	void create_name_existed();
};

#endif // CREATEUSER_H
