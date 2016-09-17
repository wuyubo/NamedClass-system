#include <QAxObject>
#include <QFile>
#include <QStringList>
#include <QDebug>

#include "qexcel.h"

QExcel::QExcel(QString xlsFilePath, QObject *parent)
{
    excel = 0;
    workBooks = 0;
    workBook = 0;
    sheets = 0;
    sheet = 0;

    excel = new QAxObject("Excel.Application", parent);
    workBooks = excel->querySubObject("Workbooks");
    QFile file(xlsFilePath);
    if (file.exists())
    {
        workBooks->dynamicCall("Open(const QString&)", xlsFilePath);
        workBook = excel->querySubObject("ActiveWorkBook");
        sheets = workBook->querySubObject("WorkSheets");
    }
}

QExcel::~QExcel()
{
    close();
}

void QExcel::close()//have
{
    excel->dynamicCall("Quit()");

    delete sheet;
    delete sheets;
    delete workBook;
    delete workBooks;
    delete excel;

    excel = 0;
    workBooks = 0;
    workBook = 0;
    sheets = 0;
    sheet = 0;
}


void QExcel::selectSheet(int sheetIndex)
{
    sheet = sheets->querySubObject("Item(int)", sheetIndex);
}
void QExcel::selectSheet(const QString& sheetName)
{
    sheet = sheets->querySubObject("Item(const QString&)", sheetName);
}

void QExcel::setCellString(int row, int column, const QString& value)//have
{
    QAxObject *range = sheet->querySubObject("Cells(int,int)", row, column);
    range->dynamicCall("SetValue(const QString&)", value);
}


void QExcel::save()//have
{
    workBook->dynamicCall("Save()");
}

void QExcel::setCellString(const QString& cell, const QString& value)//have
{
    QAxObject *range = sheet->querySubObject("Range(const QString&)", cell);
    range->dynamicCall("SetValue(const QString&)", value);
}

QVariant QExcel::getCellValue(int row, int column)
{
    QAxObject *cell = sheet->querySubObject("Cells(int,int)", row, column);
    return cell->property("Value");
}

QVariant QExcel::getCellValue(const QString& cell)
{
    QAxObject *range = sheet->querySubObject("Range(const QString&)", cell);
    return range->property("Value");
}
