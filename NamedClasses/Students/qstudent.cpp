#include <QAxObject>
#include <QFile>
#include <QStringList>
#include <QDebug>

#include "qstudent.h"

QStudent::QStudent(QObject *parent):
    QObject(parent)
{
    m_status = NORMAL;
}
QStudent::QStudent(const QStudent &stu)
{
     m_grade = stu.m_grade;
     m_stu_ID = stu.m_stu_ID;
     m_name = stu.m_name;
     m_index = stu.m_index;
     m_status = stu.m_status;
}

QStudent::~QStudent()
{
}

QString & QStudent::grade()
{
    return m_grade;
}

QString & QStudent::stuId()
{
    return m_stu_ID;
}

QString & QStudent::name()
{
    return m_name;
}

int & QStudent::index()
{
    return m_index;
}


STATUS & QStudent::status()
{
    return m_status;
}
void QStudent::setgrade(QString g)
{
    m_grade = g;
}

void QStudent::setstuId(QString id)
{
    m_stu_ID = id;
}

void QStudent::setname(QString n)
{
    m_name = n;
}

void QStudent::setindex(int idx)
{
    m_index = idx;
}

void QStudent::setstatus(STATUS state)
{
    m_status = state;
}

