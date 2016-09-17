#include <QAxObject>
#include <QFile>
#include <QStringList>
#include <QDebug>

#include "qstudent.h"

QMap<QString, int> QStudent::stc_index_map;

QStudent::QStudent(QObject *parent)
{
    m_status = NORMAL;
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

void QStudent::setIndexMap(int g_idx, int id_idx, int n_idx, int c_idx)
{
    stc_index_map[M_GRADE] = g_idx;
    stc_index_map[M_NUMBER] = id_idx;
    stc_index_map[M_NAME] = n_idx;
    stc_index_map[M_CLASS] = c_idx;
}

int QStudent::getMapIndex(MAP_NAME name)
{
    return stc_index_map[name];
}
