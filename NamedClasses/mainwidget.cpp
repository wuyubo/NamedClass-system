#include "mainwidget.h"
#include <QFileDialog>
#include "ui_mainwidget.h"
#include <excel/qexcel.h>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    stu_list = new QStudentList(this);
}

MainWidget::~MainWidget()
{
    delete stu_list;
    delete ui;
}

void MainWidget::on_read_btn_clicked()
{
    QString strFile = QFileDialog::getOpenFileName(this,QStringLiteral("选择Excel文件"),"",tr("Exel file(*.xls *.xlsx)"));

    if (strFile.isEmpty())
    {
     return;
    }
    stu_list->inportFromExcel(strFile);

//    excel.setCellString("A2", "EEE");
    ui->name_lb->setText(stu_list->getStudent()->name());
}

void MainWidget::on_begin_btn_clicked()
{
    nameWidget = new Naming(stu_list);
    nameWidget->show();
}
