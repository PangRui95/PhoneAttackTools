#ifndef ATTACKTHREAD_H
#define ATTACKTHREAD_H
#include <QThread>
#include <QString>
#include <QVector>
#include "networkutill.h"
#include "loadinterface.h"

class AttackThread : public QThread
{
    Q_OBJECT

public:
    QString PhoneNum;
    AttackThread();
    AttackThread(QString pn);
    ~AttackThread();
    void run();

private:
    LoadInterface *readFile;
    QVector<QString> readUrl;
    QUrl url;
};

#endif // ATTACKTHREAD_H
