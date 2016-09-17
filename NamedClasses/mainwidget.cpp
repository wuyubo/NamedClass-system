#include "mainwidget.h"
#include <QFileDialog>
#include "ui_mainwidget.h"
#include <excel/qexcel.h>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    m_excel = new QExcelObject(this);
}

MainWidget::~MainWidget()
{
    //delete m_excel;
    delete ui;
}

void MainWidget::on_read_btn_clicked()
{
    QString strFile = QFileDialog::getOpenFileName(this,QStringLiteral("选择Excel文件"),"",tr("Exel file(*.xls *.xlsx)"));

    if (strFile.isEmpty())
    {
     return;
    }
    QExcel excel(strFile, this);
    excel.selectSheet(1);
//    excel.setCellString("A2", "EEE");
//    m_excel->open(strFile);
    ui->name_lb->setText(excel.getCellValue(2, 1).toString());
}

void MainWidget::on_begin_btn_clicked()
{
    nameWidget = new Naming();
    nameWidget->show();
}
