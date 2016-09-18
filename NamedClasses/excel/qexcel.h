#ifndef QEXCEL_H
#define QEXCEL_H

#include <QString>
#include <QVariant>

class QAxObject;

class QExcel : public QObject
{
public:
    QExcel(QString xlsFilePath, QObject *parent = 0);
    ~QExcel();


public:

    void selectSheet(const QString& sheetName);
    //sheetIndex 起始于 1
    void selectSheet(int sheetIndex);

    void setCellString(int row, int column, const QString& value);
    //cell 例如 "A7"
    void setCellString(const QString& cell, const QString& value);
    //range 例如 "A5:C7"
    QVariant getCellValue(int row, int column);
    QVariant getCellValue(const QString& cell);
    int rowCounts();
    void save();
    void close();


private:
    QAxObject * excel;
    QAxObject * workBooks;
    QAxObject * workBook;
    QAxObject * sheets;
    QAxObject * sheet;
    bool open_flag;
};


#endif // QEXCEL_H
