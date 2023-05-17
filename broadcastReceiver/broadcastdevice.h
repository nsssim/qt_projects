#ifndef BROADCASTDEVICE_H
#define BROADCASTDEVICE_H

#include <QMainWindow>
#include <QtCore>
#include <QUdpSocket>
#include <QNetworkDatagram>

QT_BEGIN_NAMESPACE
namespace Ui { class broadcastDevice; }
QT_END_NAMESPACE

class QUdpSocket;

class broadcastDevice : public QMainWindow
{
    Q_OBJECT

public:
    broadcastDevice(QWidget *parent = nullptr);
    ~broadcastDevice();

private slots:
    void on_openPortButton_clicked();
    int rondomPortNumber();

    void on_disconnectButton_clicked();
    void sendResponse(quint16 senderPort);

private:
    Ui::broadcastDevice *ui;
    QUdpSocket *mSocket;
};
#endif // BROADCASTDEVICE_H
