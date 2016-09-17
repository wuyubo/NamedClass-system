#include "qstudentlist.h"

QMap<int, int> QStudentList::stc_index_map;

QStudentList::QStudentList(QObject *parent) :
    QObject(parent)
{
    excel_begin_row = 3;
    setIndexMap(1, 2, 3, 5);
    index = 0;
    excel_max_row = 5;
    student_count = 0;
}
QStudentList::~QStudentList()
{
    relaseList();
}

void QStudentList::relaseList()
{
    QStudent *tmp;
    for(QVector<QStudent*>::iterator iter = m_stu_list.begin();
        iter != m_stu_list.end(); )
    {
        tmp = *iter;
        m_stu_list.erase(iter);
        delete tmp;
    }
}

void QStudentList::inportFromExcel(QString &filepath)
{
    QExcel excel(filepath);
    excel.selectSheet(1);
    relaseList();
    for(int i = excel_begin_row; i <= excel_max_row; i++)
    {
        QStudent *stu = new QStudent(this);
        stu->setindex(i);
        stu->setgrade(excel.getCellValue(i,getMapIndex(M_GRADE)).toString());
        stu->setstuId(excel.getCellValue(i,getMapIndex(M_NUMBER)).toString());
        stu->setname(excel.getCellValue(i,getMapIndex(M_NAME)).toString());
        m_stu_list.push_back(stu);
    }
    student_count = m_stu_list.size();
}

QStudent * QStudentList::getStudent()
{
    return m_stu_list[index];
}

void QStudentList::nextStudent()
{
    if(index < student_count-1) index++;
    else index = 0;
}

void QStudentList::prevStudent()
{
    if(index > 0) index++;
    else index = student_count-1;
}

void QStudentList::setIndexMap(int g_idx, int id_idx, int n_idx, int c_idx)
{
    stc_index_map[M_GRADE] = g_idx;
    stc_index_map[M_NUMBER] = id_idx;
    stc_index_map[M_NAME] = n_idx;
    stc_index_map[M_CLASS] = c_idx;
}

int QStudentList::getMapIndex(MAP_NAME name)
{
    return stc_index_map[name];
}
