#include "classnames.h"

ClassNames::ClassNames(QObject *parent) :
    QObject(parent)
{
    reset();
}
void ClassNames::reset()
{
    index = 0;
    count = 0;
    flag = 0;
    names_map.clear();
}

void ClassNames::map_push_back(QString name)
{
    names_map[++count] = name;
    flag = 1;
}

QString ClassNames::nextOne()
{
    if(flag  == 0) return "";
    if(++index > count){
        return "";
    }
    return names_map[index];
}

QString ClassNames::prevOne()
{
    if(flag  == 0) return "";
    if(++index < 1 || index > count){
        return "";
    }
    return names_map[index];
}

QString ClassNames::getName(int index)
{
    if(flag  == 0) return "";
    if(index < 1){
        return "";
    }
    return names_map[index];
}

int ClassNames::Index()
{
    return index;
}

int ClassNames::Count()
{
    return count;
}

QString ClassNames::ClassName()
{
    return className;
}
