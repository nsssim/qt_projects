#ifndef BROADCAST_H
#define BROADCAST_H

#include <QMainWindow>
#include <QtCore>

QT_BEGIN_NAMESPACE
namespace Ui { class broadcast; }
QT_END_NAMESPACE

class QUdpSocket;

class broadcast : public QMainWindow
{
    Q_OBJECT

public:
    broadcast(QWidget *parent = nullptr);
    ~broadcast();

private slots:
    void on_scanButton_clicked();
    void clearForm();

    void on_clearButton_clicked();

private:
    Ui::broadcast *ui;
    QUdpSocket *mSocket;
};

class MyThread : public QThread
{
public:
    MyThread();
    void run(int, int, QString, QUdpSocket*);
};
#endif // BROADCAST_H
