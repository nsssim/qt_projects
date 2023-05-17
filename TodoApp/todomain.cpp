#include "todomain.h"
#include "ui_todomain.h"


//!!!!

#include <QDebug>
#include <QString>
#include <QMessageBox>


TodoMain::TodoMain(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::TodoMain)
{
    ui->setupUi(this);

    todoAdd = new TodoAdd();
    todoEdit = new TodoEdit();

    connect(todoAdd, SIGNAL(todo_add()), this, SLOT(addItemMain()));
    connect(todoEdit, SIGNAL(valueChanged()), this, SLOT(changeTodoList()));
}

TodoMain::~TodoMain(){
    delete ui;
}

void TodoMain::on_add_btn_clicked(){
    todoAdd->show(); //
}

void TodoMain::addItemMain()
{
    QString item = todoAdd->getItem();
    if(item == NULL){
        QMessageBox::critical(this, "Error", "Must not be empty");
        todoAdd->close();
        todoAdd->show();
    }else{
        todoAdd->close();
        ui->todoList->addItem(item);
        todoAdd->clearForm();
    }
}


void TodoMain::on_del_btn_clicked()
{
    ui->todoList->takeItem(ui->todoList->currentRow());
}


void TodoMain::on_edit_btn_clicked()
{
    if(ui->todoList->currentItem() == NULL){
        cout << "Bos" << endl;
        QMessageBox::warning(this, "Warning", "Please select the item you want to edit.");
    }else{
        todoEdit->show();
    }
}

void TodoMain::changeTodoList(){
    QString new_text = todoEdit->get_text();
    ui->todoList->item(ui->todoList->currentRow())->setData(0, new_text);
    todoEdit->clear_text();
    todoEdit->close();
}

