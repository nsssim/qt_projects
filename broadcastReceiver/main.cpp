#include "broadcastdevice.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    broadcastDevice w;
    w.show();
    return a.exec();
}
