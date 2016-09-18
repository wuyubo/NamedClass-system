#ifndef QSTUDENTLIST_H
#define QSTUDENTLIST_H

#include <QObject>
#include <QVector>
#include <Students/qstudent.h>
#include <excel/qexcel.h>
#include <QMap>
#include <Datatype/types.h>

class QStudentList : public QObject
{
    Q_OBJECT
public:
    explicit QStudentList(QObject *parent = 0);
    ~QStudentList();
    void relaseList();
    void import();
    void save();
    void inportFromExcel(QString &filepath);
    void saveToExcel();
    QStudent * getStudent();
    void nextStudent();
    void prevStudent();

public:
    static void setIndexMap(int g_idx, int id_idx, int n_idx, int c_idx);
    static int getMapIndex(MAP_NAME name);
    void initStatusMap();
    QString & getStatusString(STATUS status);

private:
    static QMap<int, int> stc_index_map;
    QMap<STATUS, QString> status_map;
    QVector<QStudent *> m_stu_list;
    int excel_begin_row;
    int index;
    int excel_max_row;
    int student_count;
    QString excel_path;
};

#endif // QSTUDENTLIST_H
