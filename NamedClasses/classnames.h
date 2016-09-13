#ifndef CLASSNAMES_H
#define CLASSNAMES_H

#include <QObject>
#include <QMap>

class ClassNames : public QObject
{
    Q_OBJECT
public:
    explicit ClassNames(QObject *parent = 0);
    void reset();
    void map_push_back(QString name);
    QString nextOne();
    QString prevOne();
    QString getName(int index);
    int Index();
    int Count();
    QString ClassName();

signals:

public slots:

private:
    QMap<int, QString> names_map;
    int index;
    int count;
    QString className;
    int flag;

};

#endif // CLASSNAMES_H
