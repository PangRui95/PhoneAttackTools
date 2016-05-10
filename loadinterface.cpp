#include <QTextStream>
#include <QDebug>
#include "loadinterface.h"

LoadInterface::LoadInterface(QString filename,QString phone_number)
{
    file.setFileName(filename);
    this->phone_number = phone_number;
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug()<<"无法打开文件"<<endl;
    }
}

LoadInterface::~LoadInterface()
{
    file.close();
}

QVector<QString> LoadInterface::ReadInterfaceContent()
{
    QVector<QString> interface;
    if(file.exists())
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString temp = in.readLine();
            if(temp.indexOf("%phone_number%")>0)
            {
                temp.replace(temp.indexOf("%phone_number%"),14,phone_number);
                interface.append(temp);
            }
            else
                interface.append(temp+phone_number);
        }
    }

    return interface;
}
