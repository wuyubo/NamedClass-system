#include "naming.h"
#include "ui_naming.h"

Naming::Naming(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Naming)
{
    ui->setupUi(this);
}

Naming::~Naming()
{
    delete ui;
}

void Naming::on_back_btn_clicked()
{
    delete this;
}
