#include "naming.h"
#include "ui_naming.h"

Naming::Naming(QStudentList *stulist, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Naming)
{
    ui->setupUi(this);
    m_stu_list = stulist;
    showInfo();
}

Naming::~Naming()
{
    delete ui;
}

void Naming::showInfo()
{
    QStudent *stu = m_stu_list->getStudent();
    ui->class_lb->setText(stu->grade());
    ui->name_lb->setText(stu->name());
    ui->number_le->setText(stu->stuId());
}

void Naming::on_back_btn_clicked()
{
    m_stu_list->save();
    delete this;
}

void Naming::on_last_btn_clicked()
{
    m_stu_list->nextStudent();
    showInfo();

}
void Naming::on_next_btn_clicked()
{
    m_stu_list->getStudent()->status() = S_ARRIVE;
    m_stu_list->nextStudent();
    showInfo();
}

void Naming::on_absence_btn_clicked()
{
    m_stu_list->getStudent()->status() = S_ABSENCE;
    m_stu_list->nextStudent();
    showInfo();
}

void Naming::on_late_btn_clicked()
{
    m_stu_list->getStudent()->status() = S_LATE;
    m_stu_list->nextStudent();
    showInfo();
}

void Naming::on_leave_btn_clicked()
{
    m_stu_list->getStudent()->status() = S_REQUEST;
    m_stu_list->nextStudent();
    showInfo();
}
