#include "mainwidget.h"
#include <QFileDialog>
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    m_excel = new QExcelObject(this);
}

MainWidget::~MainWidget()
{
    delete m_excel;
    delete ui;
}

void MainWidget::on_read_btn_clicked()
{
    QString strFile = QFileDialog::getOpenFileName(this,QStringLiteral("选择Excel文件"),"",tr("Exel file(*.xls *.xlsx)"));

    if (strFile.isEmpty())
    {
     return;
    }

    m_excel->open(strFile);
    ui->name_lb->setText(m_excel->getCellValue(3, 4).toString());
}

void MainWidget::on_begin_btn_clicked()
{
    nameWidget = new Naming();
    nameWidget->show();
}
