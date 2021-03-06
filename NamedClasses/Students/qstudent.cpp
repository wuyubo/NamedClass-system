#include <QAxObject>
#include <QFile>
#include <QStringList>
#include <QDebug>

#include "qstudent.h"

QStudent::QStudent(QObject *parent):
    QObject(parent)
{
    m_status = S_NORMAL;
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
