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
    void setgrade(QString g);
    void setstuId(QString id);
    void setname(QString n);
    void setindex(int idx);
    void setstatus(STATUS state);


private:

    QString m_grade;
    QString m_stu_ID;
    QString m_name;
    int m_index;
    STATUS m_status;
};


#endif // QStudent_H
