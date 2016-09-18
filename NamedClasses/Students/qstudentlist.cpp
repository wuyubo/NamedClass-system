#include "qstudentlist.h"

QMap<int, int> QStudentList::stc_index_map;

QStudentList::QStudentList(QObject *parent) :
    QObject(parent)
{
    excel_begin_row = 4;
    setIndexMap(3, 4, 5, 8);
    index = 0;
    excel_max_row = 5;
    student_count = 0;
    initStatusMap();
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
void QStudentList::import()
{

}

void QStudentList::save()
{
    saveToExcel();
}

void QStudentList::inportFromExcel(QString &filepath)
{
    QExcel excel(filepath);
    excel.selectSheet(1);
    relaseList();
    excel_max_row = excel.rowCounts();
    for(int i = excel_begin_row; i <= excel_max_row; i++)
    {
        QStudent *stu = new QStudent(this);
        stu->index()= i;
        stu->grade() = excel.getCellValue(i,getMapIndex(M_GRADE)).toString();
        stu->stuId() = excel.getCellValue(i,getMapIndex(M_NUMBER)).toString();
        stu->name() = excel.getCellValue(i,getMapIndex(M_NAME)).toString();
        m_stu_list.push_back(stu);
    }
    student_count = m_stu_list.size();
    excel_path = filepath;
    excel.close();
}

void QStudentList::saveToExcel()
{
    QStudent *tmp;
    QExcel excel(excel_path);
    excel.selectSheet(1);
    for(QVector<QStudent*>::iterator iter = m_stu_list.begin();
        iter != m_stu_list.end(); iter++)
    {
        tmp = *iter;
        excel.setCellString(tmp->index(), getMapIndex(M_CLASS),
                            getStatusString(tmp->status()));
    }
    excel.save();
    excel.close();
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

void QStudentList::initStatusMap()
{
    status_map[S_NORMAL] = " ";
    status_map[S_ARRIVE] = "A";
    status_map[S_LATE] = "L";
    status_map[S_ABSENCE] = "x";
    status_map[S_REQUEST] = "R";
}

QString & QStudentList::getStatusString(STATUS status)
{
    return status_map[status];
}
