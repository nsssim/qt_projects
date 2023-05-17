#include "broadcastdevice.h"
#include "ui_broadcastdevice.h"
#include "QMessageBox"
#include <QUdpSocket>
#include <QRandomGenerator>
#include <iostream>
#include <QNetworkDatagram>

using namespace std;

broadcastDevice::broadcastDevice(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::broadcastDevice)
{
    ui->setupUi(this);
    mSocket = new QUdpSocket(this);
    connect(mSocket, &QUdpSocket::readyRead, this, [&]() {
        if(mSocket->hasPendingDatagrams())
        {
            QByteArray dataGram;
            QHostAddress sender;
            quint16 senderPort;
            dataGram.resize(mSocket->pendingDatagramSize());
            mSocket->readDatagram(dataGram.data(), dataGram.size(), &sender, &senderPort);
            ui->messageHistories->addItem(QString(dataGram));

            //QNetworkDatagram a = mSocket->receiveDatagram();
            //cout << a.senderPort() << endl;
            sendResponse(senderPort);
            //auto datagramRes = ui->portValue->text().toLatin1();
            //mSocket->writeDatagram(datagramRes, QHostAddress::LocalHost , &senderPort);
            //mSocket->receiveDatagram();
        }
    });
}

broadcastDevice::~broadcastDevice()
{
    delete ui;
}

int broadcastDevice::rondomPortNumber()
{
    int portNumber;
    portNumber = QRandomGenerator::global()->bounded(0, 65537);
    return (portNumber);
}

void broadcastDevice::on_openPortButton_clicked()
{
    int portValue;

    portValue = rondomPortNumber();
    mSocket->bind(portValue, QUdpSocket::ShareAddress);
    ui->portValue->setText(QString::number(portValue));
}

void broadcastDevice::on_disconnectButton_clicked()
{
    mSocket->disconnect();
    ui->portValue->setText("");
}

void broadcastDevice::sendResponse(quint16 senderPort)
{
    auto datagramRes = ui->portValue->text().toLatin1();
    //cout << sender << endl;
    cout << senderPort << endl;
    mSocket->writeDatagram(datagramRes, QHostAddress::LocalHost, senderPort);
    //mSocket->receiveDatagram();
}
