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
    QStudent(const QStudent &stu);
public:
    QString & grade();
    QString & stuId();
    QString & name();
    int & index();
    STATUS & status();

private:
    QString m_grade;
    QString m_stu_ID;
    QString m_name;
    int m_index;
    STATUS m_status;
};


#endif // QStudent_H
