#include "mainwindow.h"
#include "login.h"
#include "client.h"
#include <QApplication>
//need no modification
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
	Login l(w.cl);
	
	//Login Window
	l.window_to_call = &w;
	l.show();

    return a.exec();
}
