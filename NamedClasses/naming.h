#ifndef NAMING_H
#define NAMING_H

#include <QWidget>
#include "classnames.h"

namespace Ui {
class Naming;
}

class Naming : public QWidget
{
    Q_OBJECT

public:
    explicit Naming(QWidget *parent = 0);
    ~Naming();


private slots:
    void on_back_btn_clicked();

    void on_last_btn_clicked();

    void on_next_btn_clicked();

private:
    Ui::Naming *ui;
    ClassNames *names;
};

#endif // NAMING_H
