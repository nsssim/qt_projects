#ifndef TODOMAIN_H
#define TODOMAIN_H

#include <QMainWindow>
#include <QString>
#include <iostream>
//!!!!!
#include "todoadd.h"
#include "todoedit.h"



using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class TodoMain; }
QT_END_NAMESPACE

class TodoMain : public QMainWindow
{
    Q_OBJECT

public:

    TodoMain(QWidget *parent = nullptr);
    ~TodoMain();


private slots:
    void on_add_btn_clicked();
    void addItemMain();

    void on_del_btn_clicked();
    void on_edit_btn_clicked();

    void changeTodoList();

private:
    Ui::TodoMain *ui;

    TodoAdd *todoAdd;
    TodoEdit *todoEdit;
};
#endif // TODOMAIN_H
