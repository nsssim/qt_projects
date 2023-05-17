#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( QWidget *parent = nullptr);
    ~MainWindow();
    QString device_uuid;
    QString score;
    bool isAdmin;

    void firstConnectWs();
    void listentoWs();
    void becomeAdmin();
    void sendScoretoWs();

private slots:

    void on_score_reset_btn_clicked(); // for reset

    void on_team_one_btn_pressed(); // to get the value of the first click for team one

    void on_team_one_btn_released(); // to get the value of the last click for team one

    void on_team_two_btn_pressed(); // to get the value of the first click for team two

    void on_team_two_btn_released(); // to get the value of the last click for team two

    void on_admin_btn_clicked();

    void sendDeviceIdtoWs();

    void denemeFun(bool);

private:
    Ui::MainWindow *ui;
    int teamOneCounter;
    int teamTwoCounter;
    int teamOneFirstPointY;
    int teamOneLastPointY;
    int teamTwoFirstPointY;
    int teamTwoLastPointY;

    void increaseOrDecrease(int); // this parameter is for which team (0 -> team one)

    QWebSocket *socket = new QWebSocket();
    void whatAreYou();
    bool scanofResponseMessage(QString, QString);
};
#endif // MAINWINDOW_H
