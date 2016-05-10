#ifndef LOADINTERFACE_H
#define LOADINTERFACE_H
#include <QString>
#include <QFile>
#include <QVector>

class LoadInterface
{
public:
    LoadInterface(QString filename,QString phone_number);
    ~LoadInterface();
    QVector<QString> ReadInterfaceContent();
private:
    QFile file;
    QString phone_number;
};

#endif // LOADINTERFACE_H
