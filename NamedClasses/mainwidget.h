#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "qexcelobject.h"
#include "naming.h"


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
    QExcelObject *m_excel;
    Naming *nameWidget;
};

#endif // MAINWIDGET_H
