#include "naming.h"
#include "ui_naming.h"

Naming::Naming(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Naming)
{
    ui->setupUi(this);
    names = new ClassNames(this);
    for(int i=0; i<10; i++)
    {
        names->map_push_back("吴玉波"+QString::number(i));
    }
    ui->name_lb->setText(names->nextOne());
}

Naming::~Naming()
{
    delete ui;
}

void Naming::on_back_btn_clicked()
{
    delete this;
}

void Naming::on_last_btn_clicked()
{
    ui->name_lb->setText(names->prevOne());
}

void Naming::on_next_btn_clicked()
{
    ui->name_lb->setText(names->nextOne());
}
