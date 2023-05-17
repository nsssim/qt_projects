#include "broadcast.h"
#include "ui_broadcast.h"
#include "QMessageBox"
#include <QUdpSocket>
#include <iostream>
#include <QNetworkDatagram>
#include <QDebug>
#include <QMutex>

using namespace std;

MyThread::MyThread()
{

}

void MyThread::run(int f_nb, int l_nb, QString message, QUdpSocket *mSocket)
{
    int firstPort = f_nb;
    int lastPort = l_nb;
    auto datagram = message.toLatin1();
    qDebug() << "bbbbbbb";
    while(firstPort <= lastPort )
    {
        //QMutex mutex;
        //mutex.lock();
        mSocket->writeDatagram(datagram, QHostAddress::LocalHost, firstPort);

        firstPort++;

        //mutex.unlock();
    }
}

broadcast::broadcast(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::broadcast)
{
    ui->setupUi(this);
    mSocket = new QUdpSocket(this);
    connect(mSocket, &QUdpSocket::readyRead, this, [&]() {
        if (mSocket->hasPendingDatagrams())
        {
            QByteArray resdataGram;
            QHostAddress sender;
            quint16 senderPort;
            resdataGram.resize(mSocket->pendingDatagramSize());
            mSocket->readDatagram(resdataGram.data(), resdataGram.size(), &sender, &senderPort);

            QString data = QString::fromLatin1(resdataGram.data());
            cout << "asda" << endl;
            cout << senderPort << endl;


            if(data != NULL)
            {
                ui->portList->addItem(data);
                ui->portValue->setText(data);
            }
            //cout << data << endl;

        } else
        {
            mSocket->disconnect();
        }
    });
}

broadcast::~broadcast()
{
    delete ui;
}

void broadcast::clearForm()
{
    ui->startVariable->setValue(0);
    ui->endVariable->setValue(65536);
    ui->messageText->setText("");
}

void broadcast::on_scanButton_clicked()
{
    mSocket->bind(44556, QUdpSocket::ShareAddress);

    if(ui->startVariable->value() >= ui->endVariable->value())
    {
        QMessageBox::information(this, "error", "Lütfen geçerli bir aralık girin");
        return;
    }
    ui->scanButton->setDisabled(true);
    //int firstPort = ui->startVariable->value();
    //int lastPort = ui->endVariable->value();
    QString message = ui->messageText->text();
    /*int tmpPort = firstPort + 10000;

    while(firstPort <= lastPort)
    {
        qDebug() << "aaaa";
        MyThread sender;
        if(tmpPort <= lastPort)
            sender.run(firstPort, tmpPort, message, mSocket);
        else
            sender.run(firstPort, lastPort, message, mSocket);
        sender.start();
        firstPort = firstPort + 10000;
        tmpPort = tmpPort + 10000;
    }*/
    MyThread sender1, sender2, sender3, sender4, sender5, sender6, sender7;

    sender1.run(0, 10000, message, mSocket);
    sender2.run(10000, 20000, message, mSocket);
    sender3.run(20000, 30000, message, mSocket);
    sender4.run(30000, 40000, message, mSocket);
    sender5.run(40000, 50000, message, mSocket);
    sender6.run(50000, 60000, message, mSocket);
    sender7.run(60000, 65536, message, mSocket);

    /*sender1.start();
    sender2.start();
    sender3.start();
    sender4.start();
    sender5.start();
    sender6.start();
    sender7.start();*/
    ui->scanButton->setDisabled(false);
    return;
}


void broadcast::on_clearButton_clicked()
{
    clearForm();
}

