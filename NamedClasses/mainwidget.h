#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "naming.h"
#include <Students/qstudentlist.h>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private slots:
    void on_read_btn_clicked();

    void on_begin_btn_clicked();

private:
    Ui::MainWidget *ui;
    Naming *nameWidget;
    QStudentList *stu_list;
};

#endif // MAINWIDGET_H
