#include "client.h"
#include "qfile.h"
#include <qdatastream.h>
//You may explain how QSocket works if you use these codes.
chatClient::chatClient(QObject *parent) : QObject(parent)
{
    this->sock = new QTcpSocket(this);
    connect(sock, SIGNAL(readyRead()), this, SLOT(readMsg()));
}

void chatClient::connectToServer(QString ip, uint16_t port){
    sock->connectToHost(ip, port);
	sock->waitForConnected();
}

void chatClient::sendMessage(QString msg){
	sock->write(msg.toUtf8());
    sock->waitForBytesWritten();
    return;
}

void chatClient::sendImg(const QByteArray& tmp) {
	sock->write(tmp);
	sock->waitForBytesWritten();
}

void chatClient::readMsg(){
	raw_data += sock->readAll();
	process_raw_data();
}

void chatClient::process_content(const QByteArray& tmp) {
	auto msg = QString::fromUtf8(tmp);
	int pos = msg.indexOf("!");
	auto content = tmp.mid(pos + 1);

	if (msg.startsWith("msg")) {
		emit newMessageRead(QString::fromUtf8(content));
	}
	else if (msg.startsWith("status")) {
		emit newStatus(QString::fromUtf8(content));
	}
	else if (msg.startsWith("img")) {
		//parse FileName
		int end_p = msg.indexOf("|");
		auto filename = msg.mid(pos + 1, end_p - pos - 1);
		//Save img file
		QFile qf("./" + filename);
		qf.open(QIODevice::WriteOnly);
		qf.write(content.mid(end_p - pos));
		qf.close();
		emit newImgRead("./" + filename);
	}
	else if (msg.startsWith("~@login_success")) {
		emit loginSuccess();
	}
	else if (msg.startsWith("~@login_pwd_error")) {
		emit loginPwdError();
	}
	else if (msg.startsWith("~@login_no_such_user")) {
		emit loginNoSuchUser();
	}
	else if (msg.startsWith("~@create_success")) {
		emit createSuccess();
	}
	else if (msg.startsWith("~@create_username_used")) {
		emit createNameExisted();
	}
	else if (msg.startsWith("msgbox")) {
		emit sendMsgBox(QString::fromUtf8(content));
	}
	else {
		emit newMessageRead(msg);
	}
}

void chatClient::process_raw_data() {
	auto raw_str = QString::fromUtf8(raw_data);
	if (raw_str.startsWith("@")) {
		int pos = raw_str.indexOf(":");
		if (pos < 0) {
			return;
		}
		auto total_size = raw_str.mid(1, pos - 1).toInt(),
			real_size = raw_data.size() - pos - 1;

		if (total_size > real_size) {
			return;
		}
		else if (total_size == real_size) {
			process_content(raw_data.mid(pos+1));
			raw_data.clear();
		}
		else {
			process_content(raw_data.mid(pos + 1, total_size));
			raw_data = raw_data.mid(pos + total_size + 1);
			process_raw_data();
		}
	}
	else {
		//Something Wrong
		raw_data.clear();
		return;
	}
}

/*
void chatClient::save_img() {
	file_tmp.resize(img_total_size);
	QFile qf("./" + receive_file_name);
	qf.open(QIODevice::WriteOnly);
	qf.write(file_tmp);
	qf.close();
	file_tmp.clear();
	img_finished = true;
	img_received_size = img_total_size = 0;
}

void chatClient::parseMsg(const QString& msg) {
	if (!img_finished) {
		img_received_size += receive_tmp.size();
		file_tmp += receive_tmp;
		if (img_received_size >= img_total_size) {
			save_img();
		}
	}
	if (msg.isEmpty()) {
		return;
	}
	if (msg.startsWith("msg:")) {
		int type_len = 4, comma_pos = msg.indexOf(":", type_len);
		auto length = msg.mid(type_len, comma_pos - type_len).toInt();
		emit newMessageRead(msg.mid(comma_pos + 1, length));
		parseMsg(msg.mid(comma_pos + length + 1));
	}
	else if (msg.startsWith("status:")) {
		int type_len = 7, comma_pos = msg.indexOf(":", type_len);
		auto length = msg.mid(type_len, comma_pos - type_len).toInt();
		emit newStatus(msg.mid(comma_pos + 1, length));
		parseMsg(msg.mid(comma_pos + length + 1));
	}
	else if (msg.startsWith("img:")) {
		int type_len = 4, comma_pos = msg.indexOf(":", type_len), end_pos = msg.indexOf("|", type_len);
		auto length = msg.mid(type_len, comma_pos - type_len).toInt();
		receive_file_name = msg.mid(comma_pos + 1, end_pos - comma_pos - 1);
		img_total_size = length;
		file_tmp += receive_tmp.mid(end_pos + 1);
		img_received_size += file_tmp.size();
		if (img_received_size >= img_total_size) {
			save_img();
		}
		else {
			img_finished = false;
		}
	}
	else if (msg.startsWith("~@login_success")) {
		emit loginSuccess();
	}
	else if (msg.startsWith("~@login_pwd_error")) {
		emit loginPwdError();
	}
	else if (msg.startsWith("~@login_no_such_user")) {
		emit loginNoSuchUser();
	}
	else if (msg.startsWith("~@create_success")) {
		emit createSuccess();
	}
	else if (msg.startsWith("~@create_username_used")) {
		emit createNameExisted();
	}
	else if (msg.startsWith("msgbox:")) {
		int type_len = 7, comma_pos = msg.indexOf(":", type_len);
		auto length = msg.mid(type_len, comma_pos - type_len).toInt();
		emit sendMsgBox(msg.mid(comma_pos + 1, length));
		parseMsg(msg.mid(comma_pos + length + 1));
	}
	else {
		emit newMessageRead(msg);
	}
}*/

chatClient::~chatClient(){
    if(sock != nullptr) delete sock;
}

void chatClient::disconnectServer() {
	sock->disconnectFromHost();
}