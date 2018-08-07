#ifndef CONNECTCLIENT_H
#define CONNECTCLIENT_H

#include <QTcpSocket>   //socket的头文件
#include <QObject>
#include <QString>
#include <QList>

#include "datapacket.h"
#include "normalprotocol.h"
#include "execnormalprotocol.h"

class ConnectClient: public QThread     //继承线程
{
    Q_OBJECT
public:
    ConnectClient(QTcpSocket *nect, QObject *parent = 0);//构造函数
    ~ConnectClient();   //析构函数

    static QueueNormalProtocol q_queueNormalProtocol; //正常协议队列

public slots:
    void slotSendDataToClient(QByteArray buffer);//槽-发送数据到客户端
    void slotReadyRead();

signals:
    void signalUserLoginSuccess(User info);//信号-用户登陆成功

protected:
    void run();

private:
    QTcpSocket *m_socket;
    bool  m_isThread;

    DataPacket m_recvDataPacket;

    NormalProtocol m_normalProtocol;
    ExecNormalProtocol *m_execNormalProtocol;

};

typedef QList<ConnectClient *> ListConnectClient;

#endif // CONNECTCLIENT_H
