#include "broadcast.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    broadcast w;
    w.show();
    return a.exec();
}
