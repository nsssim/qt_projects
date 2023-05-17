#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QWebSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include <QNetworkConfigurationManager>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isAdmin = false;
    teamOneCounter = 0;
    teamTwoCounter = 0;
    ui->team_one_btn->setText(QString::number(teamOneCounter));
    ui->team_two_btn->setText(QString::number(teamOneCounter));
    QNetworkConfigurationManager manager;

    connect(socket, SIGNAL(connected()), this, SLOT(sendDeviceIdtoWs()));
    connect(&manager, &QNetworkConfigurationManager::onlineStateChanged,
            this, &MainWindow::denemeFun);
    connect( socket, &QWebSocket::disconnected, this, [=]() {
        QString err = ((QWebSocket*)sender())->errorString();
        qDebug() << "disconnected" << err;
    });
    whatAreYou();


    qDebug() << manager.isOnline();

}

MainWindow::~MainWindow()
{
    delete ui;
}

/* Type of device (Referee or spectator) */
void MainWindow::denemeFun(bool isOnline){
    if (!isOnline) {
            QMessageBox::warning(this, tr("Warning"), tr("Wi-Fi is offline"));
        }
}


void MainWindow::whatAreYou(){
    if (isAdmin == false) {
        qDebug()  << "isadmin" << isAdmin;
        ui->team_one_btn->setEnabled(false);
        ui->team_two_btn->setEnabled(false);
        //ui->admin_btn->setEnabled(false);
        ui->score_reset_btn->setEnabled(false);
    }else{
        ui->team_one_btn->setEnabled(true);
        ui->team_two_btn->setEnabled(true);
        ui->score_reset_btn->setEnabled(true);
    }
}


/* SCORE INCREASE DECREASE */
void MainWindow::on_score_reset_btn_clicked()
{
    teamOneCounter = 0;
    teamTwoCounter = 0;
    ui->team_one_btn->setText(QString::number(0));
    ui->team_two_btn->setText(QString::number(0));
    sendScoretoWs();
}

void MainWindow::on_team_one_btn_pressed()
{
    QPoint p = mapFromGlobal(QCursor::pos());
    teamOneFirstPointY = p.y();
    //qDebug() << "first" << p.y();
}

void MainWindow::on_team_one_btn_released()
{
    QPoint p = mapFromGlobal(QCursor::pos());
    teamOneLastPointY = p.y();
    //qDebug() << "last" << p.y();
    increaseOrDecrease(0);
    sendScoretoWs();
}

void MainWindow::on_team_two_btn_pressed()
{
    QPoint p = mapFromGlobal(QCursor::pos());
    teamTwoFirstPointY = p.y();
    //qDebug() << "first" << p.y();
}

void MainWindow::on_team_two_btn_released()
{
    QPoint p = mapFromGlobal(QCursor::pos());
    teamTwoLastPointY = p.y();
    //qDebug() << "last" << p.y();
    increaseOrDecrease(1);
    sendScoretoWs();
}

void MainWindow::increaseOrDecrease(int team){
    if (team == 0) { // for team one
        if (teamOneFirstPointY < teamOneLastPointY) {
            if (teamOneCounter > 0) {
                teamOneCounter = (ui->team_one_btn->text()).toInt();
                teamOneCounter--;
                ui->team_one_btn->setText(QString::number(teamOneCounter));
                //qDebug() << "if" << teamOneCounter;
            }
        }else{
            teamOneCounter = (ui->team_one_btn->text()).toInt();
            teamOneCounter++;
            ui->team_one_btn->setText(QString::number(teamOneCounter));
            //qDebug() << "else" << teamOneCounter;
        }
    }else{ // for team two
        if (teamTwoFirstPointY < teamTwoLastPointY) {
            if (teamTwoCounter > 0 ) {
                teamTwoCounter = (ui->team_two_btn->text()).toInt();
                teamTwoCounter--;
                ui->team_two_btn->setText(QString::number(teamTwoCounter));
                //qDebug() << "if" << teamOneCounter;
            }
        }else{
            teamTwoCounter = (ui->team_two_btn->text()).toInt();
            teamTwoCounter++;
            ui->team_two_btn->setText(QString::number(teamTwoCounter));
            //qDebug() << "else" << teamOneCounter;
        }
    }
}
/* SCORE INCREASE DECREASE */


/* WEBSOCKET */
void MainWindow::firstConnectWs(){
    socket->open(QUrl("ws://51.89.254.13:8080/"));
}

void MainWindow::listentoWs(){

    QObject::connect(socket, &QWebSocket::textMessageReceived,this, [=](const QString &message){
        qDebug() << "Received message:" << message;

        if (message.contains("NEW USER JOINED", Qt::CaseInsensitive)) {
            qDebug() << "new user";
        }else if(message.contains("you become admin now!", Qt::CaseInsensitive)){
            qDebug() << "you are admin";
            this->ui->admin_btn->setEnabled(false);
        }else if(message.contains("you registered! uuid:", Qt::CaseInsensitive)){
            qDebug() << "register and admin";
        }else if(message.contains("Team", Qt::CaseInsensitive)){
            QJsonObject obj;
            QJsonDocument doc = QJsonDocument::fromJson(message.toUtf8());
            obj = doc.object();
            qDebug() << "listen ws";
            qDebug() << "Team-A:" << obj.value("Team-A").toString();
            qDebug() << "Team-B:" << obj.value("Team-B").toString();
            ui->team_one_btn->setText(obj.value("Team-A").toString());
            ui->team_two_btn->setText(obj.value("Team-B").toString());

        }else if(message.contains("admin already exists", Qt::CaseInsensitive)){
            qDebug() << "EXISTS";
            this->isAdmin = false;
            this->whatAreYou();
            QMessageBox::warning(this, "Information", "Admin already exists       ");
        }else if(message.contains("uuid already registered")){
            QMessageBox::critical(this, "Error", "Only one application can be opened on the device.   z");
            this->close();
        }
    });
}

void MainWindow::becomeAdmin()
{
    QJsonObject jsonObject;
    jsonObject["type"] = "admin";
    QJsonDocument jsonDoc(jsonObject);
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    qDebug() << jsonString;
    socket->sendTextMessage(jsonString);
    isAdmin = true;
}

void MainWindow::sendDeviceIdtoWs(){
    QJsonObject jsonObject;
    jsonObject["uuid"] = device_uuid;
    QJsonDocument jsonDoc(jsonObject);
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    qDebug() << socket->sendTextMessage(jsonString);
}

void MainWindow::sendScoretoWs(){
    QString teamOne = QString::number(teamOneCounter);
    QString teamTwo = QString::number(teamTwoCounter);
    QJsonObject jsonObject;
    jsonObject["Team-A"] = teamOne;
    jsonObject["Team-B"] = teamTwo;
    QJsonDocument jsonDoc(jsonObject);
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    socket->sendTextMessage(jsonString);
}
/* WEBSOCKET */


void MainWindow::on_admin_btn_clicked() // for become admin
{
    becomeAdmin();
    whatAreYou();
}
