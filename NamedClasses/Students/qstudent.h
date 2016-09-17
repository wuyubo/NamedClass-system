#ifndef QStudent_H
#define QStudent_H

#include <QString>
#include <QMap>
#include <Datatype/types.h>

class QStudent : public QObject
{
public:
    QStudent(QObject *parent = 0);
    ~QStudent();
public:
    QString & grade();
    QString & stuId();
    QString & name();
    int & index();
    STATUS & status();
    static void setIndexMap(int g_idx, int id_idx, int n_idx, int c_idx);
    static int getMapIndex(MAP_NAME name);

private:
    static QMap<int, int> stc_index_map;
    QString m_grade;
    QString m_stu_ID;
    QString m_name;
    int m_index;
    STATUS m_status;
};


#endif // QStudent_H
