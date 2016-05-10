#ifndef NETWORKUTILL_H
#define NETWORKUTILL_H
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

class NetWorkUtill:public QObject
{
    Q_OBJECT

public:
    NetWorkUtill(QUrl url);
    ~NetWorkUtill();
    void SendAttackForGet(QUrl url);

public slots:

private:
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QNetworkReply *reply;
};

#endif // NETWORKUTILL_H
