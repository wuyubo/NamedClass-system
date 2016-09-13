#include "qexcelobject.h"

QExcelObject::QExcelObject(QObject *parent) :
    QObject(parent)
{
    excel = new QAxObject("Excel.Application");
    excel->setProperty("Visible", false);
    work_books = excel->querySubObject("WorkBooks");
}

QExcelObject::~QExcelObject()
{
    excel->setProperty("DisplayAlerts", 0);
    work_book->dynamicCall("SaveAs(const QString&)", QString(excel_name));
    excel->setProperty("DisplayAlerts", 1);
    work_book->dynamicCall("Close(Boolean)", false);
    excel->dynamicCall("Quit(void)");
}

bool QExcelObject::open(QString excel_path)
{
   excel_name = excel_path;

   work_books->dynamicCall("Open (const QString&)", excel_name);
   work_book = work_books->querySubObject("ActiveWorkBook");
//   work_book =  work_books->querySubObject("Open(QString, QVariant)", excel_name);
   work_sheets = work_book->querySubObject("WorkSheets");
   setWorkSheet(1);

   return true;
}

QVariant QExcelObject::getTitle()
{
    return excel->property("Caption");
}

int QExcelObject::sheetCount()
{
    return work_sheets->property("Count").toInt();
}

QString QExcelObject::setWorkSheet(int index)
{
    if(index > 0 && index <= sheetCount())
    {
        work_sheet = work_book->querySubObject("Sheets(int)", index);
        used_range = work_sheet->querySubObject("UsedRange");
        rows = used_range->querySubObject("Rows");
        columns = used_range->querySubObject("Columns");
        row_count = rows->property("Count").toInt();
        column_count = columns->property("Count").toInt();
        row_start = used_range->property("Row").toInt();
        column_start = used_range->property("Column").toInt();
    }
    return workSheetName();
}

QString QExcelObject::workSheetName()
{
    return work_sheet->property("Name").toString();
}

QVariant QExcelObject::getCellValue(int row, int col)
{
    if(row < row_start || row >= row_count
            || col < column_start || col >= column_count) return QVariant("");
    QAxObject *cell = work_sheet->querySubObject("Cells(int,int)", row, col);
    QVariant cell_value = cell->property("Value");
    return cell_value;
}

int QExcelObject::rowCount()
{
    return row_count;
}

int QExcelObject::colCount()
{
    return column_count;
}

int QExcelObject::rowStart()
{
    return row_start;
}

int QExcelObject::colStart()
{
    return column_start;
}

