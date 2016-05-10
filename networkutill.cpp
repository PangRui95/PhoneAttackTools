#include "mainwindow.h"
#include "networkutill.h"

NetWorkUtill::NetWorkUtill(QUrl url)
{
    manager = new QNetworkAccessManager();
    request.setUrl(QUrl(url));
    reply = manager -> get(request);
}

NetWorkUtill::~NetWorkUtill()
{
    delete manager;
}

void NetWorkUtill::SendAttackForGet(QUrl url)
{
    request.setUrl(QUrl(url));
    delete reply;
    reply = manager -> get(request);
}
