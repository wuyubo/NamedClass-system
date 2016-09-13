#ifndef NAMING_H
#define NAMING_H

#include <QWidget>

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

private:
    Ui::Naming *ui;
};

#endif // NAMING_H
