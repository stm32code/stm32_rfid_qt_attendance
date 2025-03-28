#include "maindialog.h"
#include <QApplication>
#include "login.h"“

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    LOGIN w;
    w.show();

    return a.exec();
}
