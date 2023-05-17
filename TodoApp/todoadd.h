#ifndef TODOADD_H
#define TODOADD_H

#include <QDialog>
#include <QString>
#include <iostream>
using namespace std;

namespace Ui {
class TodoAdd;
}

class TodoAdd : public QDialog
{
    Q_OBJECT

public:
    explicit TodoAdd(QWidget *parent = nullptr);
    ~TodoAdd();
    QString getItem();
    void clearForm();

signals:
    void todo_add();

private slots:

private:
    Ui::TodoAdd *ui;
};

#endif // TODOADD_H
