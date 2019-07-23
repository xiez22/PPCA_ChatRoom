#pragma execution_character_set("utf-8")  


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "client.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
	chatClient *cl;
	

private slots:
    void on_send_button_clicked();
    void on_actionConnect_To_Server_triggered();
    void on_actionCreate_User_triggered();
    void on_actionVIP_triggered();
    void add_new_msg(const QString&);
    void updata_status(const QString&);
	void on_Change_Name_Button_triggered();
	void send_msg_box(const QString&);
	void on_Exit_Login_triggered();
	void on_Image_Button_released();
	void add_new_img(const QString&);

private:
    Ui::MainWindow *ui;
    bool login_status = false;

signals:
    void newMessageSent(const QString &);
};

#endif // MAINWINDOW_H
