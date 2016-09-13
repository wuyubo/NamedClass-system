#ifndef QEXCELOBJECT_H
#define QEXCELOBJECT_H

#include <QAxObject>
#include <QVariant>

class QExcelObject : public QObject
{
    Q_OBJECT
public:
    explicit QExcelObject(QObject *parent = 0);
    ~QExcelObject();
    bool open(QString excel_path);
    QVariant getTitle();
    int sheetCount();
    QString setWorkSheet(int index);
    QString workSheetName();
    QVariant getCellValue(int row, int col);
    int rowCount();
    int colCount();
    int rowStart();
    int colStart();

private:
    QAxObject *excel;
    QAxObject *work_books;
    QAxObject *work_book;
    QAxObject *work_sheets;
    QAxObject *work_sheet;
    QAxObject *used_range;
    QAxObject *rows;
    QAxObject *columns;
    int row_start;
    int column_start;
    int row_count;
    int column_count;
    QAxObject *cell;
    QVariant cell_value;
    QString  excel_name;
};

#endif // QEXCELOBJECT_H
