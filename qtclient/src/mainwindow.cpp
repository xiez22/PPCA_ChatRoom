#pragma execution_character_set("utf-8")  


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qinputdialog.h"
#include "qmessagebox.h"
#include "login.h"
#include <qfiledialog.h>
#include <qimage.h>
#include <qbuffer.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cl = new chatClient(this);

    //ui->status_label->setText("正在连接到服务器......");
	cl->connectToServer("127.0.0.1", 6666);
    //ui->status_label->setText("已经连接到服务器，请从左上角开始选项选择登录或注册。");
	//add_new_msg("已经连接到服务器，请从左上角“开始”选项选择登录或注册。");

    //you may explain what's the function of these two connect.
    connect(cl, SIGNAL(newMessageRead(const QString&)), this, SLOT(add_new_msg(const QString&)));
    connect(this, SIGNAL(newMessageSent(const QString &)), this, SLOT(add_new_msg(const QString &)));
    connect(cl, SIGNAL(newStatus(const QString&)), this, SLOT(updata_status(const QString&)));
	connect(cl, SIGNAL(sendMsgBox(const QString&)), this, SLOT(send_msg_box(const QString&)));
	connect(cl, SIGNAL(newImgRead(const QString&)), this, SLOT(add_new_img(const QString&)));
}

//destroy
MainWindow::~MainWindow()
{
    delete ui;
    if(cl != nullptr)
        delete cl;
}


//send button clicked
void MainWindow::on_send_button_clicked(){
    QString toSend = ui->input_text->toPlainText();

	//Check if empty
	if (toSend.isEmpty()) {
		send_msg_box("发送的消息不能为空！");
		return;
	}

	toSend = "msg:" + QString::number(toSend.length()) + ":" + toSend;
    cl->sendMessage(toSend);
    ui->input_text->clear();
    ui->input_text->setFocus();
}

void MainWindow::on_actionConnect_To_Server_triggered(){
    cl->sendMessage("~@Client:Login");
}

void MainWindow::on_actionVIP_triggered(){
    cl->sendMessage("~@Client:VIP");
    add_new_msg("VIP");
}

void MainWindow::on_actionCreate_User_triggered(){
    cl->sendMessage("~@Client:Create");
    add_new_msg("Create");
}

void stringToHtmlFilter(QString& str)
{
	str.replace("&", "&amp;");
	str.replace(">", "&gt;");
	str.replace("<", "&lt;");
	str.replace("\"", "&quot;");
	str.replace("\'", "&#39;");
	str.replace(" ", "&nbsp;");
	str.replace("\n", "<br>");
	str.replace("\r", "<br>");
}

auto stringToHtml(const QString& str, QColor crl)
{
	QByteArray array;
	array.append(crl.red());
	array.append(crl.green());
	array.append(crl.blue());
	QString strC(array.toHex());
	return QString("<span style=\" color:#%1;\">%2</span>").arg(strC).arg(str);
}

auto imgPathToHtml(const QString& path)
{
	return QString("<img src=\"%1\" width=\"300\" height=\"300\"/>").arg(path);
}


void MainWindow::add_new_msg(const QString& newMsg) {
	//QString old = ui->info_text->toPlainText();
	//Analyze color
	int pos = newMsg.indexOf("|");
	auto color_list = newMsg.mid(0, pos).split(",");
	
	QColor clr(color_list[0].toInt(),color_list[1].toInt(),color_list[2].toInt());
	auto to_print = newMsg.mid(pos + 1) + "\n";
	stringToHtmlFilter(to_print);
	to_print = stringToHtml(to_print, clr);
	ui->info_text->insertHtml(to_print);
	ui->info_text->moveCursor(QTextCursor::End);
}

//show message in status bar
void MainWindow::updata_status(const QString &newSta){
    ui->status_label->setText(newSta);
}

//change name
void MainWindow::on_Change_Name_Button_triggered() {
	QInputDialog dia(this);
	dia.setWindowTitle("修改昵称");
	dia.setLabelText("您确认需要修改您的昵称吗？\n此操作将会消耗您10个金币，且完成后不可撤销。\n请在下方输入您的新昵称：");
	dia.setInputMode(QInputDialog::TextInput);
	if (dia.exec() == QInputDialog::Accepted) {
		auto msg = "name:" + QString::number(dia.textValue().length()) + ":" + dia.textValue();
		cl->sendMessage(msg);
	}
}

//Send Msg Box
void MainWindow::send_msg_box(const QString& msg) {
	QMessageBox qmb;
	qmb.setWindowTitle("提示");
	qmb.setText(msg);
	qmb.setIcon(QMessageBox::Information);
	qmb.setStandardButtons(QMessageBox::Ok);
	qmb.exec();
}

//Quit
void MainWindow::on_Exit_Login_triggered() {
	cl->disconnectServer();
	this->close();
}

//Image
void MainWindow::on_Image_Button_released() {
	//QFileDialog qfd;
	auto filename = QFileDialog::getOpenFileName(this, "请您选择图片", "",
		"图片文件(*png *jpg)");
	if (filename.isEmpty())
		return;

	QFile file(filename);
	file.open(QIODevice::ReadOnly);
	auto dataStr = file.readAll();

	if (dataStr.size() > 2000000) {
		ui->status_label->setText("您发送的图片太大了，开通会员，以发送2M以上大小的文件！");
		return;
		file.close();
	}

	cl->sendMessage("img:" + QString::number(dataStr.size()));
	QThread::msleep(100);
	cl->sendImg(dataStr);
	file.close();
}

//Show Img
void MainWindow::add_new_img(const QString& img_dir) {
	auto html = imgPathToHtml(img_dir);
	QString tmp = "\n\n";
	stringToHtmlFilter(tmp);
	html += stringToHtml(tmp,QColor(0,0,0));
	ui->info_text->insertHtml(html);
	ui->info_text->moveCursor(QTextCursor::End);
}