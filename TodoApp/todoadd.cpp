#include "todoadd.h"
#include "ui_todoadd.h"
#include "todomain.h"

#include <QDebug>
#include <QString>


TodoAdd::TodoAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TodoAdd)
{
    ui->setupUi(this);

    connect(ui->add_button, SIGNAL(clicked(bool)), this, SIGNAL(todo_add()));
}

TodoAdd::~TodoAdd()
{
    delete ui;
}

QString TodoAdd::getItem()
{
    return ui->add_text->text();
}

void TodoAdd::clearForm()
{
    ui->add_text->clear();
}
