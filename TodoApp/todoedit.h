#ifndef TODOEDIT_H
#define TODOEDIT_H

#include <QWidget>

namespace Ui {
class TodoEdit;
}

class TodoEdit : public QWidget
{
    Q_OBJECT

public:
    explicit TodoEdit(QWidget *parent = nullptr);
    ~TodoEdit();
    QString get_text();
    void clear_text();

signals:
    void valueChanged();

private:
    Ui::TodoEdit *ui;
};

#endif // TODOEDIT_H
