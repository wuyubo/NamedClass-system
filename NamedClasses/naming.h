#ifndef NAMING_H
#define NAMING_H

#include <QWidget>
#include "classnames.h"
#include <Students/qstudentlist.h>

namespace Ui {
class Naming;
}

class Naming : public QWidget
{
    Q_OBJECT

public:
    explicit Naming(QStudentList *stulist, QWidget *parent = 0);
    ~Naming();
    void showInfo();

private slots:
    void on_back_btn_clicked();

    void on_last_btn_clicked();

    void on_next_btn_clicked();

    void on_absence_btn_clicked();

    void on_late_btn_clicked();

    void on_leave_btn_clicked();


private:
    Ui::Naming *ui;
    ClassNames *names;
    QStudentList *m_stu_list;
};

#endif // NAMING_H
