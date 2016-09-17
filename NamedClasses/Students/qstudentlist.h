#ifndef QSTUDENTLIST_H
#define QSTUDENTLIST_H

#include <QObject>
#include <QVector>
#include <Students/qstudent.h>

class QStudentList : public QObject
{
    Q_OBJECT
public:
    explicit QStudentList(QObject *parent = 0);

private:
    QVector<QStudent> m_stu_list;

};

#endif // QSTUDENTLIST_H
