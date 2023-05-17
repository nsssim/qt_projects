#ifndef SCANQR_H
#define SCANQR_H

#include <QObject>
#include <QMutex>
#include <iostream>
#include <QThread>
#include <QCamera>

class scanQr : public QObject
{
    Q_OBJECT
public:
    explicit scanQr(QObject *parent = nullptr);
    std::string qrMessage;

    Q_INVOKABLE void createThread(QString filePath);
    //Q_INVOKABLE void captureToBuffer(QString filePath);    
signals:

public slots:
    //void createThread(QString filePath);
};

class scanThread : public QThread
{
    Q_OBJECT
public:
    scanThread();
    void run(QImage fileImage);

};


#endif // SCANQR_H
