#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    w.firstConnectWs(); //Conncettion
    w.device_uuid = QSysInfo::machineUniqueId();
    w.listentoWs(); // for listen ws

    return a.exec();
}
