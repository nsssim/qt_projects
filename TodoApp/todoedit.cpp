#include "todoedit.h"
#include "ui_todoedit.h"

TodoEdit::TodoEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TodoEdit)
{
    ui->setupUi(this);

    connect(ui->ok_btn, SIGNAL(clicked(bool)), SIGNAL(valueChanged()));
}

TodoEdit::~TodoEdit()
{
    delete ui;
}

QString TodoEdit::get_text()
{
    return ui->text->text();
}

void TodoEdit::clear_text(){
    ui->text->clear();
}
