#include "mainwindow.h"
#include "authwindow.h"
#include <QTextCodec>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    AuthWindow w;
    w.show();
    return a.exec();
}
