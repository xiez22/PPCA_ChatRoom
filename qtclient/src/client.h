#pragma execution_character_set("utf-8")  


#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QThread>

class chatClient : public QObject
{
    Q_OBJECT

public:
    explicit chatClient(QObject *parent = nullptr);
    ~chatClient();

private:
    QTcpSocket *sock = nullptr;
	void parseMsg(const QString&);
	void process_raw_data();
	void process_content(const QByteArray&);

	//FILE receive
	QByteArray raw_data;
	int PREFIX_LEN = 100;


signals:
    void newMessageRead(const QString&);
    void newStatus(const QString&);
	void loginSuccess();
	void loginNoSuchUser();
	void loginPwdError();
	void createNameExisted();
	void createSuccess();
	void sendMsgBox(const QString&);
	void newImgRead(const QString&);
public slots:
    void readMsg();
public:
    void connectToServer(QString ip, uint16_t port);
    void sendMessage(QString msg);
	void disconnectServer();
	void sendImg(const QByteArray& tmp);
};

#endif // CLIENT_H
