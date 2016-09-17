#include "naming.h"
#include "ui_naming.h"

Naming::Naming(QStudentList *stulist, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Naming)
{
    ui->setupUi(this);
    m_stu_list = stulist;
    ui->name_lb->setText(m_stu_list->getStudent()->name());
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
    m_stu_list->nextStudent();
    ui->name_lb->setText(m_stu_list->getStudent()->name());
}

void Naming::on_next_btn_clicked()
{
    m_stu_list->nextStudent();
    ui->name_lb->setText(m_stu_list->getStudent()->name());
}
